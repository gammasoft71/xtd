/// @file
/// @brief Contains xtd::threading::tasks::task_object class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../object.hpp"
#include "../../usize.hpp"
#include <atomic>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and canceled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Represents an asynchronous operation object.
      /// ```cpp
      /// class task_object : public xtd::object
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/tasks/task_object>
      /// ```
      /// @par Namespace
      /// xtd::threading
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core tasks
      class task_object : public object {
        /// @cond
      protected:
        inline static thread_local xtd::usize current_id_ = 0;
        inline static std::atomic<xtd::usize> last_id_ = 0;

        task_object() = default;

        static auto generate_id() noexcept -> xtd::usize {return last_id_++;}
        /// @endcond
      };
    }
  }
}
