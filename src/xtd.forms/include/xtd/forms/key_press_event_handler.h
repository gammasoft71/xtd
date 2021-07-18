/// @file
/// @brief Contains xtd::forms::key_press_event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <xtd/event_handler.h>
#include "key_press_event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    
    /// @brief Represents the method that will handle the key_press event of a control.
    /// @param sender The source of the event.
    /// @param e A key_press_event_args that contains the event data.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    using key_press_event_handler = delegate<void(object& sender, key_press_event_args& e)>;
  }
}
