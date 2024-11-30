/// @file
/// @brief Contains xtd::forms::run_worker_completed_event_handler event handler.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "run_worker_completed_event_args.hpp"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the xtd::forms::background_worker::run_worker_completed event. This class cannot be inherited.
    /// @param sender The source of the event.
    /// @param e A do_work_event_args that contains the event data.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/run_worker_completed_event_handler>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks When you create a run_worker_completed_event_handler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event-handler method is called whenever the event occurs, unless you remove the delegate
    using run_worker_completed_event_handler = delegate<void(object& sender, const run_worker_completed_event_args& e)>;
  }
}
