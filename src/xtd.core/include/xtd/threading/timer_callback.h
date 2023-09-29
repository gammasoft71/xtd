/// @file
/// @brief Contains xtd::threading::timer_callback exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../action.h"
#include <any>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents the method that handles calls from a xtd::threading::timer.
    /// @code
    /// using timer_callback = xtd::action<std::any>
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/timer_callback> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @param state An object containing application-specific information relevant to the method invoked by this delegate.
    /// @remarks Use a xtd::threading::timer_callback delegate to specify the method that is called by a xtd::threading::timer. This method does not execute in the thread that created the timer; it executes in a separate thread pool thread that is provided by the system. The xtd::threading::timer_callback delegate invokes the method once after the start time elapses, and continues to invoke it once per timer interval until the xtd::threading::timer is destroy, or until the xtd::threading::timer::change method is called with the interval value Infinite.
    /// @note The timer delegate is specified when the timer is constructed, and cannot be changed. The start time for a xtd::threading::timer is passed in the due_time parameter of the xtd::threading::timer constructors, and the period is passed in the period parameter. For an example that demonstrates creating and using a xtd::threading::timer_callback delegate, see xtd::threading::timer.
    using timer_callback = action<std::any>;
  }
}
