/// @file
/// @brief Contains xtd::threading::tasks::task_creation_options enum class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../enum.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more. This enumeration supports a bitwise combination of its member values.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Specifies flags that control optional behavior for the creation and execution of tasks. This enumeration supports a bitwise combination of its member values.
      /// @par Namespace
      /// xtd::threading::tasks
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/tasks/task_creation_options>
      /// ```
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core threading tasks
      enum class task_creation_options {
        /// @brief Specifies that the default behavior should be used.
        none = 0b0,
        /// @brief A hint to a xtd::threading::tasks::task_scheduler to schedule a task in as fair a manner as possible, meaning that tasks scheduled sooner will be more likely to be run sooner, and tasks scheduled later will be more likely to be run later.
        prefer_fairness = 0b1,
        /// @brief Specifies that a task will be a long-running, coarse-grained operation involving fewer, larger components than fine-grained systems. It provides a hint to the xtd::threading::tasks::task_scheduler that oversubscription may be warranted. Oversubscription lets you create more threads than the available number of hardware threads. It also provides a hint to the task scheduler that an additional thread might be required for the task so that it does not block the forward progress of other threads or work items on the local thread-pool queue.
        long_running = 0b10,
        /// @brief Specifies that a task is attached to a parent in the task hierarchy. By default, a child task (that is, an inner task created by an outer task) executes independently of its parent. You can use the AttachedToParent option so that the parent and child tasks are synchronized.<br>Note that if a parent task is configured with the DenyChildAttach option, the AttachedToParent option in the child task has no effect, and the child task will execute as a detached child task.
        attached_to_parent = 0b100,
        /// @brief Specifies that any child task that attempts to execute as an attached child task (that is, it is created with the AttachedToParent option) will not be able to attach to the parent task and will execute instead as a detached child task. For more information, see Attached and Detached Child Tasks.
        deny_child_attach = 0b1000,
        /// @brief Prevents the ambient scheduler from being seen as the current scheduler in the created task. This means that operations like StartNew or ContinueWith that are performed in the created task will see Default as the current scheduler.
        hide_scheduler = 0b10000,
        /// @brief Forces continuations added to the current task to be executed asynchronously.
        run_continuations_asynchronously = 0b1000000,
      };

      /// @cond
      [[maybe_unused]] inline task_creation_options& operator ^=(task_creation_options& lhs, task_creation_options rhs) {lhs = static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) ^ static_cast<std::underlying_type<task_creation_options>::type>(rhs)); return lhs;}
      [[maybe_unused]] inline task_creation_options& operator &=(task_creation_options& lhs, task_creation_options rhs) {lhs = static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) & static_cast<std::underlying_type<task_creation_options>::type>(rhs)); return lhs;}
      [[maybe_unused]] inline task_creation_options& operator |=(task_creation_options& lhs, task_creation_options rhs) {lhs = static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) | static_cast<std::underlying_type<task_creation_options>::type>(rhs)); return lhs;}
      [[maybe_unused]] inline task_creation_options& operator +=(task_creation_options& lhs, task_creation_options rhs) {lhs = static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) + static_cast<std::underlying_type<task_creation_options>::type>(rhs)); return lhs;}
      [[maybe_unused]] inline task_creation_options& operator -=(task_creation_options& lhs, task_creation_options rhs) {lhs = static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) - static_cast<std::underlying_type<task_creation_options>::type>(rhs)); return lhs;}
      [[maybe_unused]] inline task_creation_options operator ^(task_creation_options lhs, task_creation_options rhs) {return static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) ^ static_cast<std::underlying_type<task_creation_options>::type>(rhs));}
      [[maybe_unused]] inline task_creation_options operator &(task_creation_options lhs, task_creation_options rhs) {return static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) & static_cast<std::underlying_type<task_creation_options>::type>(rhs));}
      [[maybe_unused]] inline task_creation_options operator |(task_creation_options lhs, task_creation_options rhs) {return static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) | static_cast<std::underlying_type<task_creation_options>::type>(rhs));}
      [[maybe_unused]] inline task_creation_options operator +(task_creation_options lhs, task_creation_options rhs) {return static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) + static_cast<std::underlying_type<task_creation_options>::type>(rhs));}
      [[maybe_unused]] inline task_creation_options operator -(task_creation_options lhs, task_creation_options rhs) {return static_cast<task_creation_options>(static_cast<std::underlying_type<task_creation_options>::type>(lhs) - static_cast<std::underlying_type<task_creation_options>::type>(rhs));}
      [[maybe_unused]] inline task_creation_options operator ~(task_creation_options lhs) {return static_cast<task_creation_options>(~static_cast<std::underlying_type<task_creation_options>::type>(lhs));} \
      /// @endcond
    }
  }
}

/// @cond
template<> struct xtd::enum_set_attribute<xtd::threading::tasks::task_creation_options> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};

template<> struct xtd::enum_register<xtd::threading::tasks::task_creation_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::threading::tasks::task_creation_options> {{xtd::threading::tasks::task_creation_options::none, "none"}, {xtd::threading::tasks::task_creation_options::prefer_fairness, "prefer_fairness"}, {xtd::threading::tasks::task_creation_options::long_running, "long_running"}, {xtd::threading::tasks::task_creation_options::attached_to_parent, "attached_to_parent"}, {xtd::threading::tasks::task_creation_options::deny_child_attach, "deny_child_attach"}, {xtd::threading::tasks::task_creation_options::hide_scheduler, "hide_scheduler"}, {xtd::threading::tasks::task_creation_options::run_continuations_asynchronously, "run_continuations_asynchronously"}};}
};
/// @endcond
