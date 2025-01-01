/// @file
/// @brief Contains xtd::forms::key_event_handler event handler.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "animation_update_event_args.hpp"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the update of xtd::forms::animation.
    /// @param sender The source of the event.
    /// @param e A xtd::forms::animation_updated_event_args that contains the event data.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/animation_event_handler>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    using animation_updated_event_handler = xtd::delegate<void(xtd::object&, const xtd::forms::animation_updated_event_args&)>;
  }
}
