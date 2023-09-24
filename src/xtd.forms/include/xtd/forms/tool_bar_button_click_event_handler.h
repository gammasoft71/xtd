/// @file
/// @brief Contains xtd::forms::tool_bar_button_click_event_handler event handler.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event_handler.h>
#include "tool_bar_button_click_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the xtd::forms::tool_bar::button_click event of a xtd::forms::tool_bar.
    /// @param sender The source of the event.
    /// @param e A xtd::forms::tool_bar_button_click_event_args that contains the event data.
    /// @par Header
    /// @code #include <xtd/forms/tool_bar_button_click_event_handler> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks When you create a xtd::forms::tool_bar_button_click_even_handler delegate, you identify the method that will handle the event. To associate the event with your event handler, add an instance of the delegate to the event. The event handler is called whenever the event occurs, unless you remove the delegate.
    /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
    using tool_bar_button_click_event_handler = delegate<void(object& sender, const tool_bar_button_click_event_args& e)>;
  }
}
