/// @file
/// @brief Contains xtd::forms::cancel_event_handler event handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "cancel_event_args.hpp"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that handles a cancelable event.
    /// ```cpp
    /// usingusing cancel_event_handler = xtd::delegate<void(object& sender, cancel_event_args& e)>;
    /// ```
    /// @param sender The source of the event.
    /// @param e A cancel_event_args that contains the event data.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/cancel_event_handler>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks When you create a cancel_event_handler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event-handler method is called whenever the event occurs, unless you remove the delegate.
    using cancel_event_handler = xtd::delegate<void(object& sender, cancel_event_args& e)>;
  }
}
