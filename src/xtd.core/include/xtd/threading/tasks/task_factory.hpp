/// @file
/// @brief Contains xtd::threading::tasks::task_factory <result_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "task.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task_factory which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task_factory <result_t>, which is a task_factory that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Provides support for creating and scheduling Task objects.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      class task_factory : public xtd::object {
      public:
        /// @cond
        task_factory() = default;
        task_factory(task_factory&&) = default;
        auto operator=(task_factory&&) -> task_factory& = default;
        task_factory(const task_factory&) = default;
        auto operator=(const task_factory&) -> task_factory& = default;
        /// @endcond
        
        /// @name Public Methods
        
        /// @{
        /// @brief Creates and starts a task.
        /// @param action The action delegate to execute asynchronously.
        /// @return The started task.
        /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
        template<class result_t>
        auto start_new(const xtd::func<result_t>& action) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action};
          t.start();
          return t;
        }
        /// @brief Creates and starts a task.
        /// @param action The action delegate to execute asynchronously.
        /// @return The started task.
        /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
        template<class result_t>
        auto start_new(const xtd::func<result_t>& action, const xtd::threading::cancellation_token& cancellation_token) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action, cancellation_token};
          t.start();
          return t;
        }
        /// @brief Creates and starts a task.
        /// @param action The action delegate to execute asynchronously.
        /// @return The started task.
        /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
        template<class result_t>
        auto start_new(const xtd::func<result_t, const xtd::any_object&>& action, const xtd::any_object& state) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action, state};
          t.start();
          return t;
        }
        /// @brief Creates and starts a task.
        /// @param action The action delegate to execute asynchronously.
        /// @return The started task.
        /// @remarks Calling StartNew is functionally equivalent to creating a task by using one of its constructors, and then calling the Task.Start method to schedule the task for execution.
        template<class result_t>
        auto start_new(const xtd::func<result_t, const xtd::any_object&>& action, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action, state, cancellation_token};
          t.start();
          return t;
        }

        /// @}

        /// @cond
        auto start_new(const std::function<void()>& action) const -> xtd::threading::tasks::task<> {
          auto t = xtd::threading::tasks::task<> {action};
          t.start();
          return t;
        }
        auto start_new(const std::function<void()>& action, const xtd::threading::cancellation_token& cancellation_token) const -> xtd::threading::tasks::task<> {
          auto t = xtd::threading::tasks::task<> {action, cancellation_token};
          t.start();
          return t;
        }
        auto start_new(const std::function<void(const xtd::any_object&)>& action, const xtd::any_object& state) const -> xtd::threading::tasks::task<> {
          auto t = xtd::threading::tasks::task<> {action, state};
          t.start();
          return t;
        }
        auto start_new(const std::function<void(const xtd::any_object&)>& action, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) const -> xtd::threading::tasks::task<> {
          auto t = xtd::threading::tasks::task<> {action, state, cancellation_token};
          t.start();
          return t;
        }

        template<class result_t>
        auto start_new(const std::function<result_t()>& action) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action};
          t.start();
          return t;
        }
        template<class result_t>
        auto start_new(const std::function<result_t()>& action, const xtd::threading::cancellation_token& cancellation_token) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action, cancellation_token};
          t.start();
          return t;
        }
        template<class result_t>
        auto start_new(const std::function<result_t(const xtd::any_object&)>& action, const xtd::any_object& state) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action, state};
          t.start();
          return t;
        }
        template<class result_t>
        auto start_new(const std::function<result_t(const xtd::any_object&)>& action, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) const -> xtd::threading::tasks::task<result_t> {
          auto t = xtd::threading::tasks::task<result_t> {action, state, cancellation_token};
          t.start();
          return t;
        }
        /// @endcond
      };
      
      /// @cond
      template<class result_t>
      auto basic_task<result_t>::completed_task() -> xtd::threading::tasks::task<result_t> {
        auto task = xtd::threading::tasks::task<result_t> {};
        task.basic_task<result_t>::data_->status = xtd::threading::tasks::task_status::ran_to_completion;
        task.basic_task<result_t>::data_->end_event.set();
        return task;
      }

      template<class result_t>
      auto basic_task<result_t>::factory() noexcept -> const xtd::threading::tasks::task_factory& {
        static auto factory = xtd::threading::tasks::task_factory {};
        return factory;
      }

      template<class result_t>
      auto basic_task<result_t>::delay(const xtd::time_span& delay) -> xtd::threading::tasks::task<> {return basic_task<result_t>::delay(xtd::as<xtd::int32>(delay.total_milliseconds()));}
      
      template<class result_t>
      auto basic_task<result_t>::delay(const xtd::time_span& delay, const xtd::threading::cancellation_token& cancellation_token) -> task<> {return basic_task<result_t>::delay(xtd::as<xtd::int32>(delay.total_milliseconds()), cancellation_token);}
      
      template<class result_t>
      auto basic_task<result_t>::delay(xtd::int32 milliseconds_delay) -> xtd::threading::tasks::task<> {return xtd::threading::tasks::task<>::run([milliseconds_delay]{xtd::threading::cancellation_token {}.wait_handle().wait_one(milliseconds_delay);});}
      
      template<class result_t>
      auto basic_task<result_t>::delay(xtd::int32 milliseconds_delay, const xtd::threading::cancellation_token& cancellation_token) -> task<> {
        return xtd::threading::tasks::task<>::run([cancellation_token, milliseconds_delay]{xtd::threading::cancellation_token {cancellation_token}.wait_handle().wait_one(milliseconds_delay);}, cancellation_token);
      }
      
      template<class result_t>
      auto basic_task<result_t>::from_cancelation(const xtd::threading::cancellation_token& cancellation_token) -> task<result_t> {
        if (!cancellation_token.is_cancellation_requested()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
        auto task = xtd::threading::tasks::task<result_t> {};
        task.basic_task<>::data_->cancellation_token = cancellation_token;
        task.basic_task<>::data_->status = xtd::threading::tasks::task_status::canceled;
        task.basic_task<>::data_->end_event.set();
        return task;
      }
      
      template<class result_t>
      template<class from_exception_t>
      auto basic_task<result_t>::from_exception(from_exception_t exception) -> xtd::threading::tasks::task<result_t> {
        auto task = xtd::threading::tasks::task<result_t> {};
        task.basic_task<>::data_->exception = xtd::runtime::exception_services::exception_dispatch_info::capture(exception);
        task.basic_task<>::data_->status = xtd::threading::tasks::task_status::faulted;
        task.basic_task<>::data_->end_event.set();
        return task;
      }
      
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const xtd::func<result_t>& func) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func);}
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const xtd::func<result_t>& func, const xtd::threading::cancellation_token& cancellation_token) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func, cancellation_token);}
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func, state);}
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func, state, cancellation_token);}
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const std::function<result_t()>& func) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func);}
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const std::function<result_t()>& func, const xtd::threading::cancellation_token& cancellation_token) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func, cancellation_token);}
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const std::function<result_t(const xtd::any_object&)>& func, const xtd::any_object& state) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func, state);}
      template<class result_t>
      auto xtd::threading::tasks::basic_task<result_t>::run(const std::function<result_t(const xtd::any_object&)>& func, const xtd::any_object& state, const xtd::threading::cancellation_token& cancellation_token) -> xtd::threading::tasks::task<result_t> {return factory().start_new(func, state, cancellation_token);}
      
      template<class result_t>
      struct task_awaiter {
        xtd::threading::tasks::task<result_t>& task;
        
        auto await_ready() const noexcept -> bool {return task.is_completed();}
        
        auto await_suspend(std::coroutine_handle<> handle) -> void {task.continue_with([handle] {handle.resume();});}
        
        auto await_resume() -> result_t {
          if (task.is_faulted()) task.rethrow_exception();
          if constexpr (!std::is_void_v<result_t>) return task.result();
        }
      };
      
      template<class result_t>
      inline auto basic_task<result_t>::operator co_await() noexcept {
        return xtd::threading::tasks::task_awaiter<result_t> {xtd::as<xtd::threading::tasks::task<result_t>>(*this)};
      }
      /// @endcond
    }
  }
}
