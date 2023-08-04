/// @file
/// @brief Contains xtd::auto_reset_event exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "event_wait_handle.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::auto_reset_event, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents a thread synchronization event that, when signaled, resets automatically after releasing a single waiting thread. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/threading/auto_reset_event> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks You use xtd::threading::auto_reset_event, xtd::threading::manual_reset_event, and xtd::threading::event_wait_handle for thread interaction (or thread signaling).
    /// @remarks A thread waits for a signal by calling xtd::threading::auto_reset_event::wWait_one. If the xtd::threading::auto_reset_event is in the non-signaled state, the thread blocks until xtd::threading::auto_reset_event::set is called.
    /// @remarks Calling xtd::threading::auto_reset_event::set signals xtd::threading::auto_reset_event to release a waiting thread. xtd::threading::auto_reset_event remains signaled until a single waiting thread is released, and then automatically returns to the non-signaled state. If no threads are waiting, the state remains signaled indefinitely.
    /// @remarks If a thread calls xtd::threading::wait_handle::wait_one while the xtd::threading::auto_reset_event is in the signaled state, the thread does not block. The xtd::threading::auto_reset_event releases the thread immediately and returns to the non-signaled state.
    /// @warning There is no guarantee that every call to the xtd::threading::auto_reset_event::set method will release a thread. If two calls are too close together, so that the second call occurs before a thread has been released, only one thread is released. It's as if the second call did not happen. Also, if xtd::threading::auto_reset_event::set is called when there are no threads waiting and the xtd::threading::auto_reset_event is already signaled, the call has no effect.
    /// @remarks You can xtd::threading::auto_reset_event the initial state of an xtd::threading::auto_reset_event by passing a bool value to the constructor: true if the initial state is signaled and false otherwise.
    /// @remarks AutoResetEvent can also be used with the static xtd::threading::wait_handle::wait_all and xtd::threading::wait_handle::wait_any methods.
    /// @note Unlike the xtd::threading::auto_reset_event class, the xtd::threading::event_wait_handle class provides access to named system synchronization events.
    class auto_reset_event : public event_wait_handle {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::auto_reset_event class.
      /// @remarks The initial state is false.
      auto_reset_event() = default;
      /// @brief Initializes a new instance of the xtd::threading::auto_reset_event class with a bool value indicating whether to set the initial state to signaled.
      /// @param initial_state true to set the initial state to signaled; false to set the initial state to non-signaled.
      explicit auto_reset_event(bool initial_state) : event_wait_handle(initial_state, event_reset_mode::auto_reset) {}
      /// @}
    };
  }
}
