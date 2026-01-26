/// @file
/// @brief Contains xtd::threading::tasks::task <result_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "task_result.hpp"
#include "../../func.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      template<class result_t = void>
      class wtask : public xtd::threading::tasks::task<result_t> {
      public:
        /// @cond
        wtask() = default;
        wtask(wtask&&) = default;
        wtask(const wtask&) = default;
        auto operator=(wtask&&) -> wtask& = default;
        auto operator=(const wtask&) -> wtask& = default;
        /// @endcond
        
        /// @name Public Constructors
        
        /// @{
        wtask(const xtd::func<result_t>& func) : task<result_t>(func) {}
        wtask(const xtd::func<result_t>& func, const xtd::threading::cancellation_token& cancellation_token) : task<result_t>(func, cancellation_token) {}
        wtask(const xtd::func<result_t, const xtd::any_object&>& func, const xtd::any_object& state) : task<result_t>(func, state) {}
        /// @}
        
        /// @cond
        wtask(const std::function<result_t()>& func) : task<result_t>(func) {}
        wtask(const std::function<result_t()>& func, const xtd::threading::cancellation_token& cancellation_token) : task<result_t>(func, cancellation_token) {}
        wtask(const std::function<result_t(const xtd::any_object&)>& func, const xtd::any_object& state) : task<result_t>(func, state) {}
        
        ~wtask() {task<result_t>::wait();}
        /// @endcond
      };
    }
  }
}
