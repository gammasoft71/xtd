/// @file
/// @brief Contains xtd::manual_reset_event exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "event_wait_handle.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::manual_reset_event, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::manual_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents a thread synchronization event that, when signaled, must be reset manually. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/threading/manual_reset_event> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks You use xtd::threading::auto_reset_event, xtd::threading::manual_reset_event, and xtd::threading::event_wait_handle for thread interaction (or thread signaling).
    /// @remarks When a thread begins an activity that must complete before other threads proceed, it calls xtd::threading::event_wait_handle::reset to put xtd::threading::manual_reset_event in the non-signaled state. This thread can be thought of as controlling the xtd::threading::manual_reset_event. Threads that call xtd::threading::wait_handle::wait_one block, awaiting the signal. When the controlling thread completes the activity, it calls xtd::threading::event_wait_handle::set to signal that the waiting threads can proceed. All waiting threads are released.
    /// @remarks Once it has been signaled, xtd::threading::manual_reset_event remains signaled until it is manually reset by calling the xtd::threading::event_wait_handle::reset() method. That is, calls to xtd::threading::wait_handle:wait_one return immediately.
    /// @remarks You can control the initial state of a xtd::threading::manual_reset_event by passing a bool value to the constructor: true if the initial state is signaled, and false otherwise.
    /// @remarks xtd::threading::manual_reset_event can also be used with the static xtd::threading::wait_handle::wait_all and xtd::threading::wait_handle::wait_any methods.
    /// @warning Unlike the xtd::threading::manual_reset_event class, the xtd::threading::event_wait_handle class provides access to named system synchronization events.
    class manual_reset_event : public event_wait_handle {
    public:
      /// @name Constructors
      
      /// @{
      manual_reset_event() = default;
      /// @brief Initializes a new instance of the xtd::threading::manual_reset_event class with a bool value indicating whether to set the initial state to signaled.
      /// @param initial_state true to set the initial state signaled; false to set the initial state to nonsignaled.
      /// @remarks If the initial state of a xtd::threading::manual_reset_event is signaled (that is, if it is created by passing true for initialState), threads that wait on the xtd::threading::manual_reset_event do not block. If the initial state is nonsignaled, threads block until the xtd::threading::event_wait_handle::set method is called.
      explicit manual_reset_event(bool initial_state) : event_wait_handle(initial_state, event_reset_mode::manual_reset) {}
      /// @}
    };
  }
}
