/// @file
/// @brief Contains xtd::forms::mouse_event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <xtd/event_handler.h>
#include "mouse_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the MouseDown, MouseUp, or MouseMove event of a form, control, or other component.
    /// @param sender The source of the event.
    /// @param e A xtd::forms::mouse_event_args that contains the event data.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    using mouse_event_handler = delegate<void(object& sender, const mouse_event_args& e)>;
  }
}
