/// @file
/// @brief Contains xtd::forms::key_event_handler event handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "key_event_args.hpp"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the xtd::forms::control::key_up or xtd::forms::control::key_down event of a control.
    /// ```cpp
    /// using key_event_handler = xtd::delegate<void(object& sender, key_event_args& e)>;
    /// ```
    /// @param sender The source of the event.
    /// @param e A key_event_args that contains the event data.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/key_event_handler>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    using key_event_handler = xtd::delegate<void(object& sender, key_event_args& e)>;
  }
}
