/// @file
/// @brief Contains xtd::forms::thread_exception_event_handler event handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "thread_exception_event_args.hpp"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Represents the method that will handle the xtd::forms::application::thread_exception event of an xtd::forms::application.
    /// ```cpp
    /// using thread_exception_event_handler = xtd::delegate<void(object& sender, paint_event_args& e)>;
    /// ```
    /// @param sender The source of the event.
    /// @param e A paint_event_args that contains the event data.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/thread_exception_event_handler>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    using thread_exception_event_handler = xtd::delegate<void(object& sender, const thread_exception_event_args& e)>;
  }
}
