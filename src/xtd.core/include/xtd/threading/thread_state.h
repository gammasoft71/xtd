/// @file
/// @brief Contains xtd::threading::thread_state enumeration.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Specifies the execution states of a System::Threading::Thread.
    /// @code
    /// enum class thread_state
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/thread_state> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    enum class thread_state {
      /// @brief The thread_state has been started, it is not blocked, and there is no pending System::Threading::ThreadAbortException.
      running = 0x0000,
      /// @brief The thread_state is being requested to stop. This is for internal use only.
      stop_requested = 0x0001,
      /// @brief The thread_state is being requested to suspend.
      suspend_requested = 0x0002,
      /// @brief The thread_state is being executed as a background thread_state, as opposed to a foreground thread_state. This state is controlled by setting the System::Threading::Thread.Isbackground property.
      background = 0x0004,
      /// @brief The System::Threading::Thread.Start() method has not been invoked on the thread_state.
      unstarted = 0x0008,
      /// @brief The thread_state has stopped.
      stopped = 0x0010,
      /// @brief The thread_state is blocked. This could be the result of calling System::Threading::Thread.Sleep(System::Int32) or System::Threading::Thread.Join(), of requesting a lock � for example, by calling System::Threading::Monitor.Enter(System::object) or System::Threading::Monitor.Wait(System::object,System::Int32,System::Boolean) or of waiting on a thread_state synchronization object such as System::Threading::ManualResetEvent.
      wait_sleep_join = 0x0020,
      /// @brief The thread_state has been suspended.
      suspended = 0x0040,
      /// @brief The System::Threading::Thread.Abort(System::object) method has been invoked on the thread_state, but the thread_state has not yet received the pending System::Threading::ThreadAbortException that will attempt to terminate it.
      abort_requested = 0x0080,
      /// @brief The thread_state state includes System::Threading::ThreadState.abort_requested and the thread_state is now dead, but its state has not yet changed to System::Threading::ThreadState.stopped.
      aborted = 0x0100
    };
  }
}

/// @cond
flags_attribute_(xtd::threading, thread_state);

template<> struct xtd::enum_register<xtd::threading::thread_state> {
  explicit operator auto() const noexcept {
    return xtd::enum_collection<xtd::threading::thread_state> {{xtd::threading::thread_state::running, "running"}, {xtd::threading::thread_state::stop_requested, "stop_requested"}, {xtd::threading::thread_state::suspend_requested, "suspend_requested"}, {xtd::threading::thread_state::background, "background"}, {xtd::threading::thread_state::unstarted, "unstarted"}, {xtd::threading::thread_state::stopped, "stopped"}, {xtd::threading::thread_state::wait_sleep_join, "wait_sleep_join"}, {xtd::threading::thread_state::suspended, "suspended"}, {xtd::threading::thread_state::abort_requested, "abort_requested"}, {xtd::threading::thread_state::aborted, "aborted"}};}
};
/// @endcond
