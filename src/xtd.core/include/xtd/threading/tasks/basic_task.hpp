/// @file
/// @brief Contains xtd::threading::tasks::basic_task <> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "itask.hpp"
#include "task_canceled_exception.hpp"
#include "task_creation_options.hpp"
#include "task_status.hpp"
#include "../auto_reset_event.hpp"
#include "../lock.hpp"
#include "../thread_pool.hpp"
#include "../../diagnostics/stopwatch.hpp"
#include "../../helpers/throw_helper.hpp"
#include "../../exception_services/exception_dispatch_info.hpp"
#include "../../action.hpp"
#include "../../aggregate_exception.hpp"
#include "../../func.hpp"
#include "../../iasync_result.hpp"
#include "../../new_sptr.hpp"
#include "../../optional.hpp"
#include "../../ref.hpp"
#include "../../scope_exit.hpp"
#include "../../sptr.hpp"
#include "../../usize.hpp"
#include <coroutine>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @cond
      template<typename result_t = void>
      class task;
      
      template<typename result_t>
      struct task_awaiter;

      class task_factory;
      /// @endcond
      
      /// @brief Represents an asynchronous operation.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      template<typename result_t = void>
      class basic_task : public itask, public xtd::iasync_result {
      public:
        struct yield_awaiter;
        
        /// @name Public Fields
        
        /// @{
        /// @brief Indicates that a xtd::threading::wait_handle::wait_any operation timed out before any of the wait handles were signaled. This field is constant.
        /// @remarks This field is one of the possible return values of xtd::threading::wait_handle::wait_any.
        static constexpr xtd::usize wait_timeout = xtd::usize_object::max_value;
        /// @}
        /// @name Public Constructors
        
        /// @{
        basic_task(const xtd::func<result_t>& func) {
          data_->func = func;
        }
        basic_task(const xtd::func<result_t>& func, const xtd::threading::cancellation_token& cancellation_token) {
          data_->func = func;
          data_->cancellation_token = cancellation_token;
        }
        basic_task(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state) {
          data_->parameterized_func = func;
          data_->state = &state;
        }
        basic_task(const xtd::func<result_t>& func, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) {
          data_->func = func;
          data_->state = &state;
          data_->cancellation_token = cancellation_token;
        }
        /// @}
        
        /// @cond
        template<typename create_result_t>
        basic_task(const xtd::func<create_result_t>& func) {
          data_->func = func;
        }
        template<typename create_result_t>
        basic_task(const xtd::func<create_result_t>& func, const xtd::threading::cancellation_token& cancellation_token) {
          data_->func = func;
          data_->cancellation_token = cancellation_token;
        }
        template<typename create_result_t>
        basic_task(const xtd::func<create_result_t, const xtd::any_object&>& func, const xtd::any_object& state) {
          data_->parameterized_func = func;
          data_->state = &state;
        }
        template<typename create_result_t>
        basic_task(const xtd::func<create_result_t, const xtd::any_object&>& func, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) {
          data_->parameterized_func = func;
          data_->state = &state;
          data_->cancellation_token = cancellation_token;
        }
        /// @}

        
        /// @name Public Properties
        
        /// @{
        [[nodiscard]] auto async_state() const noexcept -> xtd::any_object override {return data_->async_state;}
        [[nodiscard]] auto creation_options() const noexcept -> xtd::threading::tasks::task_creation_options {return data_->creation_options;}
        [[nodiscard]] auto exception() const noexcept -> xtd::ref<xtd::exception> {return data_->exception.exception_captured() ? xtd::ref<xtd::exception> {*data_->exception.source_exception()} : xtd::ref<xtd::exception> {xtd::null};}
        /// @brief Gets an ID for this xtd::threading::tasks::task instance.
        /// @return The identifier that is assigned by the system to this xtd::threading::tasks::task instance.
        /// @remarks Task IDs are assigned on-demand and do not necessarily represent the order in which task instances are created. Note that although collisions are very rare, task identifiers are not guaranteed to be unique.
        /// @remarks To get the task ID of the currently executing task from within code that task is executing, use the xtd::threading::tasks::task::current_id property.
        [[nodiscard]] auto id() const noexcept -> xtd::usize override {return data_->id;}
        [[nodiscard]] auto is_canceled() const noexcept -> bool {return data_->status == xtd::threading::tasks::task_status::canceled;}
        [[nodiscard]] auto is_completed() const noexcept -> bool override {return is_faulted() || is_canceled() || data_->status == xtd::threading::tasks::task_status::ran_to_completion;}
        [[nodiscard]] auto is_faulted() const noexcept -> bool {return data_->status == xtd::threading::tasks::task_status::faulted;}
        [[nodiscard]] auto status() const noexcept -> xtd::threading::tasks::task_status {return data_->status;}
        /// @}
        
        /// @name Public Static Properties
        
        /// @{
        [[nodiscard]] static auto completed_task() -> task<result_t>;
        [[nodiscard]] static auto current_id() noexcept -> xtd::usize {return current_id_;}
        [[nodiscard]] static auto factory() noexcept -> const xtd::threading::tasks::task_factory&;
        /// @}
        
        /// @name Public Methods
        
        /// @{
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
          data_->task_proc(data_->state, false);
          data_->status = xtd::threading::tasks::task_status::waiting_to_run;
        }
        
        /// @brief Starts the xtd::threading::tasks::task, scheduling it for execution to the current xtd::threading::tasks::task_scheduler.
        auto start() -> void override {
          if (is_completed()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Start may not be called on a task that has completed.");
          data_->status = xtd::threading::tasks::task_status::waiting_for_activation;
          thread_pool::register_wait_for_single_object(data_->start_event, data_->task_proc, *data_->state, xtd::threading::timeout::infinite, true);
          data_->status = xtd::threading::tasks::task_status::waiting_to_run;
          data_->start_event.set();
        }
        
        /// @brief Waits for the xtd::threading::tasks::task to complete execution.
        auto wait() -> void override {wait(xtd::threading::timeout::infinite);}
        /// @brief Waits for the xtd::threading::tasks::task to complete execution with specified milliseconds timout.
        /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
        /// @return `true` if the xtd::threading::tasks::task completed execution within the allotted time; otherwise, `false`.
        auto wait(xtd::int32 milliseconds_timeout) -> bool override {
          auto cancellation_token = xtd::threading::cancellation_token {};
          return wait(milliseconds_timeout, cancellation_token);
        }
        /// @brief Waits for the xtd::threading::tasks::task to complete execution with specified milliseconds timout and cancellation token.
        /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
        /// @return `true` if the xtd::threading::tasks::task completed execution within the allotted time; otherwise, `false`.
        auto wait(xtd::int32 milliseconds_timeout, xtd::threading::cancellation_token& cancellation_token) -> bool override {
          auto& cancellation_token_wait_handle = cancellation_token.wait_handle();
          auto result = xtd::threading::wait_handle::wait_any(milliseconds_timeout, &data_->end_event, &cancellation_token_wait_handle);
          if (data_->status == xtd::threading::tasks::task_status::faulted) rethrow_exception();
          return result;
        }
        /// @brief Waits for the xtd::threading::tasks::task to complete execution with specified timout.
        /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::threading::timeout::infinite_time_span that represents -1 milliseconds to wait indefinitely.
        /// @return `true` if the xtd::threading::tasks::task completed execution within the allotted time; otherwise, `false`.
        auto wait(const xtd::time_span& timeout) -> bool override {return wait(xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        /// @brief Waits for the xtd::threading::tasks::task to complete execution with specified timout and cancellation token.
        /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::threading::timeout::infinite_time_span that represents -1 milliseconds to wait indefinitely.
        /// @return `true` if the xtd::threading::tasks::task completed execution within the allotted time; otherwise, `false`.
        auto wait(const xtd::time_span& timeout, xtd::threading::cancellation_token& cancellation_token) -> bool override {return wait(xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()), cancellation_token);}
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        [[nodiscard]] static auto from_cancelation(const xtd::threading::cancellation_token& cancellation_token) -> task<result_t>;
        
        template<typename from_exception_t>
        [[nodiscard]] static auto from_exception(from_exception_t exception) -> task<result_t>;
        
        [[nodiscard]] static auto delay(const xtd::time_span& delay) -> task<>;
        [[nodiscard]] static auto delay(const xtd::time_span& delay, const xtd::threading::cancellation_token& cancellation_token) -> task<>;
        [[nodiscard]] static auto delay(xtd::int32 milliseconds_delay) -> task<>;
        [[nodiscard]] static auto delay(xtd::int32 milliseconds_delay, const xtd::threading::cancellation_token& cancellation_token) -> task<>;

        [[nodiscard]] static auto run(const xtd::func<result_t>& func) -> task<result_t>;
        [[nodiscard]] static auto run(const xtd::func<result_t>& func, const xtd::threading::cancellation_token& cancellation_token) -> task<result_t>;
        [[nodiscard]] static auto run(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state) -> task<result_t>;
        [[nodiscard]] static auto run(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) -> task<result_t>;
        
        template<typename collection_t>
        static auto wait_all(const collection_t& tasks) -> bool {return wait_all(tasks, xtd::threading::timeout::infinite);}

        template<typename collection_t>
        static auto wait_all(const collection_t& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(const_cast<decltype(&task)>(&task));
          return wait_all(array<itask*> {task_pointers}, milliseconds_timeout);
        }

        template<typename collection_t>
        static auto wait_all(const collection_t& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}

        template<typename collection_t>
        static xtd::usize wait_any(const collection_t& tasks) {return wait_any(tasks, timeout::infinite);}
        
        template<typename collection_t>
        static xtd::usize wait_any(const collection_t& tasks, int32 milliseconds_timeout) {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(const_cast<decltype(&task)>(&task));
          return wait_any(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        
        template<typename collection_t>
        static xtd::usize wait_any(const collection_t& tasks, const time_span& timeout) {return wait_any(tasks, as<int32>(timeout.total_milliseconds_duration().count()));}
        /// @}
        
        /// @cond
        template<typename ...items_t>
        static auto wait_all(items_t... items) -> bool {return wait_all(xtd::threading::timeout::infinite, items...);}
        template<typename ...items_t>
        static auto wait_all(const xtd::time_span& timeout, items_t... items) -> bool {return wait_all(xtd::as<xtd::int32>(timeout.total_milliseconds()), items...);}
        template<typename ...items_t>
        static auto wait_all(xtd::int32 milliseconds_timeout, items_t... items) -> bool {
          auto task_pointers = std::vector<itask*> {};
          fill_task_pointers(task_pointers, items...);
          return wait_all(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        template<typename item_t>
        static auto wait_all(const std::initializer_list<item_t>& tasks) -> bool {return wait_all(tasks, timeout::infinite);}
        template<typename item_t>
        static auto wait_all(const std::initializer_list<item_t>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(const_cast<item_t*>(&task));
          return wait_all(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        template<typename item_t>
        static auto wait_all(const std::initializer_list<item_t>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, as<int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const std::initializer_list<xtd::sptr<itask>>& tasks) -> bool {return wait_all(tasks, xtd::threading::timeout::infinite);}
        static auto wait_all(const std::initializer_list<xtd::sptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const std::initializer_list<xtd::sptr<itask>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const std::initializer_list<xtd::uptr<itask>>& tasks) -> bool {return wait_all(tasks, xtd::threading::timeout::infinite);}
        static auto wait_all(const std::initializer_list<xtd::uptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const std::initializer_list<xtd::uptr<itask>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const xtd::array<xtd::sptr<itask>>& tasks) -> bool {return wait_all(tasks, timeout::infinite);}
        static auto wait_all(const xtd::array<xtd::sptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const xtd::array<xtd::sptr<itask>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const xtd::array<xtd::uptr<itask>>& tasks) -> bool {return wait_all(tasks, timeout::infinite);}
        static auto wait_all(const xtd::array<xtd::uptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> bool {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_all(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_all(const xtd::array<xtd::uptr<itask>>& tasks, const xtd::time_span& timeout) -> bool {return wait_all(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_all(const xtd::array<itask*>& tasks, xtd::int32 milliseconds_timeout) -> bool {
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

        template<typename ...items_t>
        static auto wait_any(items_t... items) -> xtd::usize {return wait_any(xtd::threading::timeout::infinite, items...);}
        template<typename ...items_t>
        static auto wait_any(const xtd::time_span& timeout, items_t... items) -> xtd::usize {return wait_any(xtd::as<xtd::int32>(timeout.total_milliseconds()), items...);}
        template<typename ...items_t>
        static auto wait_any(xtd::int32 milliseconds_timeout, items_t... items) -> xtd::usize {
          auto task_pointers = std::vector<itask*> {};
          fill_task_pointers(task_pointers, items...);
          return wait_any(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        template<typename item_t>
        static auto wait_any(const std::initializer_list<item_t>& tasks) -> xtd::usize {return wait_any(tasks, timeout::infinite);}
        template<typename item_t>
        static auto wait_any(const std::initializer_list<item_t>& tasks, xtd::int32 milliseconds_timeout) -> xtd::usize {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(const_cast<item_t*>(&task));
          return wait_any(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        template<typename item_t>
        static auto wait_any(const std::initializer_list<item_t>& tasks, const xtd::time_span& timeout) -> xtd::usize {return wait_any(tasks, as<int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const std::initializer_list<xtd::sptr<itask>>& tasks) -> xtd::usize {return wait_any(tasks, xtd::threading::timeout::infinite);}
        static auto wait_any(const std::initializer_list<xtd::sptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::usize {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const std::initializer_list<xtd::sptr<itask>>& tasks, const xtd::time_span& timeout) -> xtd::usize {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const std::initializer_list<xtd::uptr<itask>>& tasks) -> xtd::usize {return wait_any(tasks, xtd::threading::timeout::infinite);}
        static auto wait_any(const std::initializer_list<xtd::uptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::usize {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const std::initializer_list<xtd::uptr<itask>>& tasks, const xtd::time_span& timeout) -> xtd::usize {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const xtd::array<xtd::sptr<itask>>& tasks) -> xtd::usize {return wait_any(tasks, timeout::infinite);}
        static auto wait_any(const xtd::array<xtd::sptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::usize {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const xtd::array<xtd::sptr<itask>>& tasks, const xtd::time_span& timeout) -> xtd::usize {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const xtd::array<xtd::uptr<itask>>& tasks) -> xtd::usize {return wait_any(tasks, timeout::infinite);}
        static auto wait_any(const xtd::array<xtd::uptr<itask>>& tasks, xtd::int32 milliseconds_timeout) -> xtd::usize {
          auto task_pointers = std::vector<itask*> {};
          for (auto& task : tasks)
            task_pointers.push_back(task.get());
          return wait_any(xtd::array<itask*> {task_pointers}, milliseconds_timeout);
        }
        static auto wait_any(const xtd::array<xtd::uptr<itask>>& tasks, const xtd::time_span& timeout) -> xtd::usize {return wait_any(tasks, xtd::as<xtd::int32>(timeout.total_milliseconds_duration().count()));}
        static auto wait_any(const xtd::array<itask*>& tasks, xtd::int32 milliseconds_timeout) -> xtd::usize {
          if (milliseconds_timeout < xtd::threading::timeout::infinite) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          
          auto sleep_duration = 1;
          const auto max_sleep = 10;
          auto sw = xtd::diagnostics::stopwatch::start_new();
          
          while (milliseconds_timeout == xtd::threading::timeout::infinite || sw.elapsed_milliseconds() <= milliseconds_timeout) {
            for (auto index = xtd::usize {0}; index < tasks.length(); ++index)
              if (tasks[index]->wait(0)) return index;

            xtd::threading::thread::sleep(sleep_duration);
            sleep_duration = std::min(sleep_duration + 1, max_sleep);
          }
          
          return wait_timeout;
        }

        static auto yield() -> task<result_t>;
        /// @endcond
        
      private:
        template<typename task_result_t>
        friend class task;
        template<typename batic_task_result_t>
        friend class batic_task;
        
        basic_task() = default;
        basic_task(basic_task&&) = default;
        basic_task(const basic_task&) = default;
        auto operator=(basic_task&&) -> basic_task& = default;
        auto operator=(const basic_task&) -> basic_task& = default;
        
        [[nodiscard]] auto async_wait_handle() noexcept -> xtd::threading::wait_handle& override {return data_->async_event;}
        [[nodiscard]] auto completed_synchronously() const noexcept -> bool override {return false;}

        template<typename item_t, typename ...items_t>
        static auto fill_task_pointers(std::vector<itask*>& itask_pointer, item_t& first, items_t& ... rest) -> void {
          itask_pointer.push_back(&first);
          fill_task_pointers(itask_pointer, rest...);
        }
        template<typename item_t>
        static auto fill_task_pointers(std::vector<itask*>& itask_pointer, item_t& item) -> void {
          itask_pointer.push_back(&item);
        }

        static auto generate_id() noexcept -> xtd::usize {
          static auto id = xtd::usize {0};
          return ++id;
        }

        struct data {
          using result_type = std::conditional_t<std::is_same_v<result_t, void>, std::uint8_t, result_t>;
          
          xtd::async_callback async_callback;
          xtd::threading::manual_reset_event async_event;
          xtd::any_object async_state;
          xtd::optional<xtd::threading::cancellation_token> cancellation_token;
          xtd::action<> continuation;
          xtd::threading::tasks::task_creation_options creation_options = xtd::threading::tasks::task_creation_options::none;
          const xtd::any_object empty_state;
          xtd::threading::auto_reset_event end_event;
          xtd::exception_services::exception_dispatch_info exception;
          xtd::func<result_t> func;
          xtd::usize id = generate_id();
          xtd::func<result_t, const xtd::any_object&> parameterized_func;
          result_type result;
          const xtd::any_object* state = &empty_state;
          xtd::threading::auto_reset_event start_event;
          xtd::threading::tasks::task_status status = xtd::threading::tasks::task_status::created;
          xtd::object sync_root;
          
          xtd::threading::wait_or_timer_callback task_proc {delegate_(const xtd::any_object& state, bool timed_out) {
            auto previous_current_id = current_id_;
            current_id_ = id;
            
            scope_exit_ {
              current_id_ = previous_current_id;
              end_event.set();
              if (!continuation.is_empty()) continuation();
            };
            
            status = xtd::threading::tasks::task_status::running;
            try {
              if (cancellation_token && cancellation_token->wait_handle().wait_one(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::task_canceled);
              if constexpr(std::is_same_v<result_t, void>) {
                if (!func.is_empty()) func();
                else if (!parameterized_func.is_empty()) parameterized_func(state);
              } else {
                if (!func.is_empty()) result = func();
                else if (!parameterized_func.is_empty()) result = parameterized_func(state);
              }
              if (cancellation_token && cancellation_token->wait_handle().wait_one(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::task_canceled);
              status = xtd::threading::tasks::task_status::ran_to_completion;
            } catch (const xtd::threading::tasks::task_canceled_exception& e) {
              exception = xtd::exception_services::exception_dispatch_info::capture(e);
              status = xtd::threading::tasks::task_status::canceled;
            } catch (const xtd::exception& e) {
              exception = xtd::exception_services::exception_dispatch_info::capture(e);
              status = xtd::threading::tasks::task_status::faulted;
            } catch (const std::exception& e) {
              exception = xtd::exception_services::exception_dispatch_info::capture(xtd::exception {e.what()});
              status = xtd::threading::tasks::task_status::faulted;
            } catch (...) {
              exception = xtd::exception_services::exception_dispatch_info::capture(xtd::exception {"Unknown exception"});
              status = xtd::threading::tasks::task_status::faulted;
            }
          }};
        };
        
        xtd::sptr<data> data_ = xtd::new_sptr<data>();
        inline static thread_local xtd::usize current_id_ = 0;
      };
    }
  }
}
