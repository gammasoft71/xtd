/// @file
/// @brief Contains xtd::diagnostics::process_priority_class enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Indicates the priority that the system associates with a process. This value, together with the priority value of each thread of the process, determines each thread's base priority level.
    /// @code
    /// enum class process_priority_class
    /// @endcode
    /// @par Header
    /// @code #include <xtd/diagnostics/process_priority_class> @endcode
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks A process priority class encompasses a range of thread priority levels. Threads with different priorities running in the process run relative to the process's priority class. The operating system uses the base-priority level of all executable threads to determine which thread gets the next slice of processor time.
    /// @remarks Win32 uses four priority classes with seven base priority levels per class. Based on time elapsed or other boosts, the operating system can change the base priority level when a process needs to be put ahead of others for access to the processor. In addition, you can set PriorityBoostEnabled to temporarily boost the priority level of threads that have been taken out of the wait state. The priority is reset when the process returns to the wait state.
    enum class process_priority_class {
      /// @brief Specifies that the process has no special scheduling needs.
      normal = 0x20,
      /// @brief Specifies that the threads of this process run only when the system is idle, such as a screen saver. The threads of the process are preempted by the threads of any process running in a higher priority class. This priority class is inherited by child processes.
      idle = 0x40,
      /// @brief Specifies that the process performs time-critical tasks that must be executed immediately, such as the Task List dialog, which must respond quickly when called by the user, regardless of the load on the operating system. The threads of the process preempt the threads of normal or idle priority class processes. Use extreme care when specifying High for the process's priority class, because a high priority class application can use nearly all available processor time.
      high = 0x80,
      /// @brief Specifies that the process has the highest possible priority. The threads of a process with RealTime priority preempt the threads of all other processes, including operating system processes performing important tasks. Thus, a RealTime priority process that executes for more than a very brief interval can cause disk caches not to flush or cause the mouse to be unresponsive.
      real_time = 0x100,
      /// @brief Specifies that the process has priority above Idle but below Normal.
      below_normal = 0x4000,
      /// @brief Specifies that the process has priority higher than Normal but lower than High.
      above_normal = 0x8000,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::diagnostics::process_priority_class> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::diagnostics::process_priority_class> {{xtd::diagnostics::process_priority_class::normal, "normal"}, {xtd::diagnostics::process_priority_class::idle, "idle"}, {xtd::diagnostics::process_priority_class::high, "high"}, {xtd::diagnostics::process_priority_class::real_time, "real_time"}, {xtd::diagnostics::process_priority_class::below_normal, "below_normal"}, {xtd::diagnostics::process_priority_class::above_normal, "above_normal"}};}
};
/// @endcond
