/// @file
/// @brief Contains xtd::threading::tasks::basic_task <> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "task_canceled_exception.hpp"
#include "task_creation_options.hpp"
#include "task_status.hpp"
#include "../cancellation_token.hpp"
#include "../../helpers/throw_helper.hpp"
#include "../../runtime/exception_services/exception_dispatch_info.hpp"
#include "../../action.hpp"
#include "../../aggregate_exception.hpp"
#include "../../iasync_result.hpp"
#include "../../new_sptr.hpp"
#include "../../object.hpp"
#include "../../optional.hpp"
#include "../../ref.hpp"
#include "../../scope_exit.hpp"
#include "../../sptr.hpp"
#include "../auto_reset_event.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @cond
      template<class result_t = void>
      class task;
      
      template<class result_t>
      struct task_awaiter;

      class abstract_task : public xtd::object {
      public:
        virtual auto start() -> void = 0;
        virtual auto wait() -> void = 0;
        virtual auto wait(xtd::int32 milliseconds_timeout) -> bool = 0;
        virtual auto wait(const xtd::time_span& timeout) -> bool = 0;
      protected:
        /// @cond
        static auto generate_id() noexcept -> xtd::size {
          static auto id = xtd::size {0};
          return ++id;
        }
        /// @endcond
        
        inline static thread_local xtd::optional<xtd::size> current_id_ = 0;
      };
      
      /// @endcond
      
      /// @brief Represents an asynchronous operation.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      template<class result_t = void>
      class basic_task : public abstract_task, public xtd::iasync_result {
      public:
        /// @name Public Fields
        
        /// @{
        /// @brief Indicates that a xtd::threading::wait_handle::wait_any operation timed out before any of the wait handles were signaled. This field is constant.
        /// @remarks This field is one of the possible return values of xtd::threading::wait_handle::wait_any.
        static constexpr xtd::size wait_timeout = xtd::size_object::max_value;
        /// @}
        /// @name Public Constructors
        
        /// @{
        /// @}

        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto async_state() const noexcept -> xtd::any_object override {return data_->async_state;}
        [[nodiscard]] auto creation_options() const noexcept -> xtd::threading::tasks::task_creation_options {return data_->creation_options;}
        [[nodiscard]] auto exception() const noexcept -> xtd::ref<xtd::exception> {
          if (data_->exception.exception_captured()) return  *data_->exception.source_exception();
          return xtd::null;
        }
        [[nodiscard]] auto id() const noexcept -> xtd::size {return data_->id;}
        [[nodiscard]] auto is_canceled() const noexcept -> bool {return data_->status == xtd::threading::tasks::task_status::canceled;}
        [[nodiscard]] auto is_completed() const noexcept -> bool override {return is_faulted() || is_canceled() || data_->status == xtd::threading::tasks::task_status::ran_to_completion;}
        [[nodiscard]] auto is_faulted() const noexcept -> bool {return data_->status == xtd::threading::tasks::task_status::faulted;}
        [[nodiscard]] auto status() const noexcept -> xtd::threading::tasks::task_status {return data_->status;}
        /// @}
        
        /// @name Public Static Properties
        
        /// @{
        [[nodiscard]] static auto completed_task() -> task<result_t>;
        [[nodiscard]] static auto current_id() noexcept -> xtd::optional<xtd::size> {return current_id_;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        auto continue_with(std::function<void()> continuation) -> void {continue_with(xtd::action<> {continuation});}
        auto continue_with(xtd::action<> continuation) -> void {
          auto call_now = false;
          
          lock_(data_->sync_root) {
            if (is_completed()) call_now = true;
            else data_->continuation = continuation;
          }
          
          if (call_now) continuation();
        }
        
        [[noreturn]] auto rethrow_exception() -> void {
          if (is_faulted () && data_->exception) throw *data_->exception.source_exception();
          xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "This task is not faulted.");
        }
        
        auto run_synchronously() -> void {
          data_->status = xtd::threading::tasks::task_status::waiting_for_activation;
          task_proc(data_->state, false);
          data_->status = xtd::threading::tasks::task_status::waiting_to_run;
        }
        
        auto start() -> void override {
          if (is_completed()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Start may not be called on a task that has completed.");
          data_->status = xtd::threading::tasks::task_status::waiting_for_activation;
          thread_pool::register_wait_for_single_object(data_->start_event, task_proc, *data_->state, xtd::threading::timeout::infinite, true);
          data_->status = xtd::threading::tasks::task_status::waiting_to_run;
          data_->start_event.set();
        }
        
        auto wait() -> void override {wait(xtd::threading::timeout::infinite);}
        
        auto wait(xtd::int32 milliseconds_timeout) -> bool override {
          bool result = data_->end_event.wait_one(milliseconds_timeout);
          if (data_->status == xtd::threading::tasks::task_status::faulted)
            rethrow_exception();
          return result;
        }
        
        auto wait(const xtd::time_span& timeout) -> bool override {return wait(xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}

        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        [[nodiscard]] static auto from_cancelation(const xtd::threading::cancellation_token& cancellation_token) -> task<result_t>;
        
        template<class from_exception_t>
        [[nodiscard]] static auto from_exception(from_exception_t exception) -> task<result_t>;
        
        [[nodiscard]] static auto delay(const xtd::time_span& delay) -> task<>;
        [[nodiscard]] static auto delay(const xtd::time_span& delay, const xtd::threading::cancellation_token& cancellation_token) -> task<>;
        [[nodiscard]] static auto delay(xtd::int32 milliseconds_delay) -> task<>;
        [[nodiscard]] static auto delay(xtd::int32 milliseconds_delay, const xtd::threading::cancellation_token& cancellation_token) -> task<>;

        template<class collection_t>
        static auto wait_all(const collection_t& tasks) -> bool {return wait_all(tasks, xtd::threading::timeout::infinite);}

        template<class collection_t>
        static auto wait_all(const collection_t& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : task_pointers)
            task_pointers.push_back(const_cast<abstract_task*>(xtd::as<abstract_task>(&task)));
          return wait_all(array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }

        template<class collection_t>
        static auto wait_all(const collection_t& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}

        template<class collection_t>
        static size_t wait_any(const collection_t& tasks) {return wait_any(tasks, timeout::infinite);}
        
        template<class collection_t>
        static size_t wait_any(const collection_t& tasks, int32 milliseconds_timeout) {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(const_cast<abstract_task*>(as<abstract_task>(&task)));
          return wait_any(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        
        template<class collection_t>
        static size_t wait_any(const collection_t& tasks, const time_span& timeout) {return wait_any(tasks, as<int32>(timeout.total_milliseconds_duration().count()));}
        /// @}
        
        /// @cond
        template<class ...items_t>
        static auto wait_all(items_t... items) -> bool {return wait_all(xtd::threading::timeout::infinite, items...);}
        template<class ...items_t>
        static auto wait_all(const xtd::time_span& timeout, items_t... items) -> bool {return wait_all(xtd::as<xtd::int32>(timeout.total_milliseconds()), items...);}
        template<class ...items_t>
        static auto wait_all(xtd::int32 milliseconds_timeout, items_t... items) -> bool {
          auto task_pointers = std::vector<abstract_task*> {};
          fill_task_pointers(task_pointers, items...);
          return wait_all(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        template<class item_t>
        static auto wait_all(const std::initializer_list<item_t>& tasks) -> bool {return wait_all(tasks, timeout::infinite);}
        template<class item_t>
        static auto wait_all(const std::initializer_list<item_t>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(const_cast<abstract_task*>(as<abstract_task>(&task)));
          return wait_all(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        template<class item_t>
        static auto wait_all(const std::initializer_list<item_t>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, as<int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const std::initializer_list<xtd::sptr<abstract_task>>& tasks) -> bool {return wait_all(tasks, xtd::threading::timeout::infinite);}
        static auto wait_all(const std::initializer_list<xtd::sptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const std::initializer_list<xtd::sptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const std::initializer_list<xtd::uptr<abstract_task>>& tasks) -> bool {return wait_all(tasks, xtd::threading::timeout::infinite);}
        static auto wait_all(const std::initializer_list<xtd::uptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const std::initializer_list<xtd::uptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const xtd::array<xtd::sptr<abstract_task>>& tasks) -> bool {return wait_all(tasks, timeout::infinite);}
        static auto wait_all(const xtd::array<xtd::sptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const xtd::array<xtd::sptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const xtd::array<xtd::uptr<abstract_task>>& tasks) -> bool {return wait_all(tasks, timeout::infinite);}
        static auto wait_all(const xtd::array<xtd::uptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const xtd::array<xtd::uptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const xtd::array<abstract_task*>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          if (milliseconds_timeout < timeout::infinite) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          
          if (milliseconds_timeout == timeout::infinite) {
            for (auto task : tasks)
              task->wait();
            return true;
          }
          
          auto sw = xtd::diagnostics::stopwatch::start_new();
          for (auto& task : tasks)
            if (sw.elapsed_milliseconds() > milliseconds_timeout || task->wait(milliseconds_timeout - xtd::as<xtd::int32>(sw.elapsed_milliseconds()))) return false;
          return true;
        }

        template<class ...items_t>
        static auto wait_any(items_t... items) -> xtd::size {return wait_any(xtd::threading::timeout::infinite, items...);}
        template<class ...items_t>
        static auto wait_any(const xtd::time_span& timeout, items_t... items) -> xtd::size {return wait_any(xtd::as<xtd::int32>(timeout.total_milliseconds()), items...);}
        template<class ...items_t>
        static auto wait_any(xtd::int32 milliseconds_timeout, items_t... items) -> xtd::size {
          auto task_pointers = std::vector<abstract_task*> {};
          fill_task_pointers(task_pointers, items...);
          return wait_any(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        template<class item_t>
        static auto wait_any(const std::initializer_list<item_t>& tasks) -> xtd::size {return wait_any(tasks, timeout::infinite);}
        template<class item_t>
        static auto wait_any(const std::initializer_list<item_t>& tasks, xtd::int32 milliseconds_timeout) -> xtd::size {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(const_cast<abstract_task*>(as<abstract_task>(&task)));
          return wait_any(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        template<class item_t>
        static auto wait_any(const std::initializer_list<item_t>& tasks, const xtd::time_span& timeout) -> xtd::size {return wait_any(tasks, as<int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const std::initializer_list<xtd::sptr<abstract_task>>& tasks) -> xtd::size {return wait_any(tasks, xtd::threading::timeout::infinite);}
        static auto wait_any(const std::initializer_list<xtd::sptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::size {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const std::initializer_list<xtd::sptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> xtd::size {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const std::initializer_list<xtd::uptr<abstract_task>>& tasks) -> xtd::size {return wait_any(tasks, xtd::threading::timeout::infinite);}
        static auto wait_any(const std::initializer_list<xtd::uptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::size {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const std::initializer_list<xtd::uptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> xtd::size {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const xtd::array<xtd::sptr<abstract_task>>& tasks) -> xtd::size {return wait_any(tasks, timeout::infinite);}
        static auto wait_any(const xtd::array<xtd::sptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::size {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const xtd::array<xtd::sptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> xtd::size {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const xtd::array<xtd::uptr<abstract_task>>& tasks) -> xtd::size {return wait_any(tasks, timeout::infinite);}
        static auto wait_any(const xtd::array<xtd::uptr<abstract_task>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::size {
          auto task_pointers = std::vector<abstract_task*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<abstract_task*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const xtd::array<xtd::uptr<abstract_task>>& tasks, const xtd::time_span& timeout) -> xtd::size {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const xtd::array<abstract_task*>& tasks, xtd::int32 milliseconds_timeout) -> xtd::size {
          if (milliseconds_timeout < xtd::threading::timeout::infinite) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          
          auto sleep_duration = 1;
          const auto max_sleep = 10;
          auto sw = xtd::diagnostics::stopwatch::start_new();
          
          while (milliseconds_timeout == xtd::threading::timeout::infinite || sw.elapsed_milliseconds() <= milliseconds_timeout) {
            for (auto index = xtd::size {0}; index < tasks.length(); ++index)
              if (tasks[index]->wait(0)) return index;

            xtd::threading::thread::sleep(sleep_duration);
            sleep_duration = std::min(sleep_duration + 1, max_sleep);
          }
          
          return wait_timeout;
        }
        /// @endcond
        
        /// @name Public Operators
        
        /// @{
        auto operator co_await() noexcept;
        /// @}
        
      private:
        template<class task_result_t>
        friend class task;
        template<class batic_task_result_t>
        friend class batic_task;
        
        basic_task() = default;
        basic_task(basic_task&&) = default;
        basic_task(const basic_task&) = default;
        auto operator=(basic_task&&) -> basic_task& = default;
        auto operator=(const basic_task&) -> basic_task& = default;
        
        [[nodiscard]] auto async_wait_handle() noexcept -> xtd::threading::wait_handle& override {return data_->async_event;}
        [[nodiscard]] auto completed_synchronously() const noexcept -> bool override {return false;}

        template<class item_t, class ...items_t>
        static auto fill_task_pointers(std::vector<abstract_task*>& abstract_task_pointer, item_t& first, items_t& ... rest) -> void {
          abstract_task_pointer.push_back(const_cast<abstract_task*>(as<abstract_task>(&first)));
          fill_task_pointers(abstract_task_pointer, rest...);
        }
        template<class item_t>
        static auto fill_task_pointers(std::vector<abstract_task*>& abstract_task_pointer, item_t& item) -> void {
          abstract_task_pointer.push_back(const_cast<abstract_task*>(as<abstract_task>(&item)));
        }

        struct data {
          xtd::async_callback async_callback;
          xtd::threading::manual_reset_event async_event;
          xtd::any_object async_state;
          xtd::optional<xtd::threading::cancellation_token> cancellation_token;
          xtd::action<> continuation;
          xtd::threading::tasks::task_creation_options creation_options = xtd::threading::tasks::task_creation_options::none;
          const xtd::any_object empty_state;
          xtd::threading::auto_reset_event end_event;
          xtd::runtime::exception_services::exception_dispatch_info exception;
          xtd::size id = generate_id();
          xtd::threading::auto_reset_event start_event;
          const xtd::any_object* state = &empty_state;
          xtd::threading::tasks::task_status status = xtd::threading::tasks::task_status::created;
          xtd::object sync_root;
          xtd::action<> task_run;
        };
        
        xtd::sptr<data> data_ = xtd::new_sptr<data>();
        
        xtd::threading::wait_or_timer_callback task_proc {delegate_(const xtd::any_object& state, bool timed_out) {
          auto previous_current_id = current_id_;
          current_id_ = data_->id;
          
          scope_exit_ {
            current_id_ = previous_current_id;
            data_->end_event.set();
            if (!data_->continuation.is_empty()) data_->continuation();
          };
          
          data_->status = xtd::threading::tasks::task_status::running;
          try {
            if (data_->cancellation_token && data_->cancellation_token->wait_handle().wait_one(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::task_canceled);
            data_->task_run();
            if (data_->cancellation_token && data_->cancellation_token->wait_handle().wait_one(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::task_canceled);
            data_->status = xtd::threading::tasks::task_status::ran_to_completion;
          } catch (const xtd::threading::tasks::task_canceled_exception& exception) {
            data_->exception = xtd::runtime::exception_services::exception_dispatch_info::capture(exception);
            data_->status = xtd::threading::tasks::task_status::canceled;
          } catch (const xtd::exception& exception) {
            data_->exception = xtd::runtime::exception_services::exception_dispatch_info::capture(exception);
            data_->status = xtd::threading::tasks::task_status::faulted;
          } catch (const std::exception& exception) {
            data_->exception = xtd::runtime::exception_services::exception_dispatch_info::capture(xtd::exception {exception.what()});
            data_->status = xtd::threading::tasks::task_status::faulted;
          } catch (...) {
            data_->exception = xtd::runtime::exception_services::exception_dispatch_info::capture(xtd::exception {"Unknown exception"});
            data_->status = xtd::threading::tasks::task_status::faulted;
          }
        }};

      };
    }
  }
}
