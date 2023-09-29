/// @file
/// @brief Contains xtd::threading::wait_or_timer_callback exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../delegate.h"
#include <any>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents a method to be called when a xtd::threading::wait_handle is signaled or times out.
    /// @code
    /// using wait_or_timer_callback = xtd::action<std::any, bool>
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/wait_or_timer_callback> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @param state An object containing information to be used by the callback method each time it executes.
    /// @param timed_out true if the xtd::threading::wait_handle timed out; false if it was signaled.
    /// @remarks xtd::threading::wait_or_timer_callback represents a callback method that you want to execute when a registered wait handle times out or is signaled. Create the delegate by passing your callback method to the xtd::threading::wait_or_timer_callback constructor. Your method must have the signature shown here.
    /// @remarks Create the registered wait handle by passing the xtd::threading::wait_or_timer_callback delegate and a xtd::threading::wait_handle to xtd::threading::thread_pool::register_wait_for_single_object. Your callback method executes each time the xtd::threading::wait_handle times out or is signaled.
    /// @remarks If you want to pass information to your callback method, create an object that contains the necessary information and pass it to xtd::threading::thread_pool::register_wait_for_single_object when you create the registered wait handle. Each time your callback method executes, the state parameter contains this object.
    using wait_or_timer_callback = delegate<void(std::any, bool)>;
  }
}
