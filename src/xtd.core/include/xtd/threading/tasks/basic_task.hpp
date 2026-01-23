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
      /// @endcond
      
      /// @brief Represents an asynchronous operation.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      template<class result_t>
      class basic_task : public xtd::object, public xtd::iasync_result {
      public:
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
        auto start() -> void {
          data_->status = xtd::threading::tasks::task_status::waiting_for_activation;
          thread_pool::register_wait_for_single_object(data_->start_event, task_proc, *data_->state, xtd::threading::timeout::infinite, true);
          data_->status = xtd::threading::tasks::task_status::waiting_to_run;
          data_->start_event.set();
        }
        
        auto wait() -> void {wait(xtd::threading::timeout::infinite);}
        
        auto wait(xtd::int32 milliseconds_timeout) -> bool {
          bool result = data_->end_event.wait_one(milliseconds_timeout);
          if (data_->status == xtd::threading::tasks::task_status::faulted)
            throw *data_->exception.source_exception();
          data_->status = xtd::threading::tasks::task_status::ran_to_completion;
          return result;
        }
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        template<class from_result_t>
        [[nodiscard]] static auto from_result(from_result_t result) -> task<from_result_t>;
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @}
        
      private:
        template<class task_result_t>
        friend class task;
        
        basic_task() = default;
        basic_task(basic_task&&) = default;
        basic_task(const basic_task&) = default;
        auto operator=(basic_task&&) -> basic_task& = default;
        auto operator=(const basic_task&) -> basic_task& = default;
        
        [[nodiscard]] auto async_wait_handle() noexcept -> xtd::threading::wait_handle& override {return data_->async_event;}
        [[nodiscard]] auto completed_synchronously() const noexcept -> bool override {return false;}

        static auto generate_id() -> xtd::size {
          static auto id = xtd::size {0};
          return ++id;
        }
        
        struct data {
          xtd::async_callback async_callback;
          xtd::threading::manual_reset_event async_event;
          xtd::any_object async_state;
          xtd::threading::cancellation_token cancellation_token;
          xtd::threading::tasks::task_creation_options creation_options = xtd::threading::tasks::task_creation_options::none;
          const xtd::any_object empty_state;
          xtd::threading::auto_reset_event end_event;
          xtd::runtime::exception_services::exception_dispatch_info exception;
          xtd::size id = generate_id();
          xtd::int32 milliseconds_delay = timeout_none;
          xtd::threading::auto_reset_event start_event;
          const xtd::any_object* state = &empty_state;
          xtd::threading::tasks::task_status status = xtd::threading::tasks::task_status::created;
          xtd::action<> task_run;
        };
        
        xtd::sptr<data> data_ = xtd::new_sptr<data>();
        
        xtd::threading::wait_or_timer_callback task_proc {delegate_(const xtd::any_object& state, bool timed_out) {
          auto previous_current_id = current_id_;
          current_id_ = data_->id;
          
          scope_exit_ {
            current_id_ = previous_current_id;
            data_->end_event.set();
          };
          
          data_->status = xtd::threading::tasks::task_status::running;
          try {
            if (data_->cancellation_token.is_cancellation_requested()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::task_canceled);
            if (data_->milliseconds_delay != timeout_none) thread::sleep(data_->milliseconds_delay);
            if (data_->cancellation_token.is_cancellation_requested()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::task_canceled);
            data_->task_run();
            data_->status = xtd::threading::tasks::task_status::waiting_for_children_to_complete;
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

        inline static thread_local xtd::optional<xtd::size> current_id_;
        inline static constexpr xtd::int32 timeout_none = -2;
      };
    }
  }
}
