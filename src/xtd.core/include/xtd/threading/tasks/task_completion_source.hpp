/// @file
/// @brief Contains xtd::threading::tasks::task <result_t> class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "task_result.hpp"
#include "../cancellation_token_source.hpp"
#include "../../new_ptr.hpp"
#include "../../ptr.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      template<class result_t>
      class task_completion_source : public xtd::object {
      public:
        /// @name Public Constructors

        /// @{
        task_completion_source() : data_ {xtd::new_ptr<data>([this] {
          //if (data_->task.token().is_cancellation_requested()) throw task_canceled_exception {};
          if (data_->exception != null) throw *data_->exception;
          return data_->result;
        })} {}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        auto task() const noexcept -> const xtd::threading::tasks::task<result_t>& {return data_->task;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        auto set_canceled() -> void {
          data_->cancellation.cancel();
          data_->task.start();
        }

        template<class exception_t>
        auto set_exception(const exception_t& exception) -> void {
          data_->exception = xtd::ptr<xtd::exception> {exception.template memberwise_clone<exception_t>().release()};
          *data_->exception = exception;
          data_->task.start();
        }

        auto set_result(result_t&& result) -> void {
          data_->result = std::forward<result_t>(result);
          data_->task.start();
        }
        /// @}
        
      private:
        struct data {
          template<typename func_t>
          data(func_t func) {task = {func, cancellation.token()};}
          xtd::threading::cancellation_token_source cancellation;
          result_t result;
          xtd::ptr<xtd::exception> exception;
          xtd::threading::tasks::task<result_t> task;
        };
        xtd::ptr<data> data_;
      };
    }
  }
}
