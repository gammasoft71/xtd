/// @file
/// @brief Contains xtd::threading::tasks::parallel <result_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "task_factory.hpp"
#include "../../collections/generic/list.hpp"
#include "../../array.hpp"
#include "../../static.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::parallel which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::parallel <result_t>, which is a parallel that can return a value. The xtd::threading::tasks::parallel class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Provides support for creating and scheduling Task objects.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      class parallel static_ {
      public:
        /// @brief Executes each of the provided actions, possibly in parallel.
        /// @par Library
        /// Switch.Core
        /// @ingroup SwitchCore
        /// @param An array of Action to execute.
        /// @remarks This method can be used to execute a set of operations, potentially in parallel.
        /// @remarks No guarantees are made about the order in which the operations execute or whether they execute in parallel. This method does not return until each of the provided operations has completed, regardless of whether completion occurs due to normal or exceptional termination.
        /// @par Examples
        /// This example demonstrates how to use the Invokemethod with other methods, anonymous delegates, and lambda expressions.
        /// @include ParallelInvoke.cpp
        static auto invoke(const xtd::array<xtd::action<>>& actions) -> void {
          xtd::collections::generic::list<xtd::threading::tasks::task<>> tasks;
          for (const auto& action : actions)
            tasks.add(xtd::threading::tasks::task<>::factory().start_new(action));
          task<>::wait_all(tasks);
        }
        
        template<class collection_t>
        static auto invoke(const collection_t& actions) -> void {
          xtd::collections::generic::list<xtd::threading::tasks::task<>> tasks;
          for (const auto& action : actions)
            tasks.add(xtd::threading::tasks::task<>::factory().start_new(action));
          task<>::wait_all(tasks);
        }

        template<typename ...args_t>
        static auto invoke(args_t... args) -> void {invoke(xtd::array<xtd::action<>> {std::forward<args_t>(args)...});}

        /// @cond
        static auto invoke(const xtd::array<std::function<void()>>& actions) -> void {
          xtd::collections::generic::list<xtd::threading::tasks::task<>> tasks;
          for (const auto& action : actions)
            tasks.add(xtd::threading::tasks::task<>::factory().start_new(action));
          task<>::wait_all(tasks);
        }
        /// @endcond
      };
    }
  }
}
