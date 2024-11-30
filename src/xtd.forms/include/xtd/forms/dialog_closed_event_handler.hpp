/// @file
/// @brief Contains xtd::forms::dialog_closed_event_handler dialog.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "dialog_closed_event_args.hpp"
#include <xtd/delegate>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides handler for a dialog closed event.
    /// @param sender The source of the event.
    /// @param e An dialog_closed_event_args that contains event data.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/dialog_closed_event_handler>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    using dialog_closed_event_handler = delegate<void(object& sender, const dialog_closed_event_args& e)>;
  }
}
