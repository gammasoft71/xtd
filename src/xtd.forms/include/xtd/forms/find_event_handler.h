/// @file
/// @brief Contains xtd::forms::find_event_handler event handler.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "find_event_args.h"
#include <xtd/event_handler>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents the method that will handle the xtd::forms::find_dialog::find_next event of the xtd::forms::find_dialog and the xtd::forms::replace_dialog::find_next event of the xtd::forms::replace_dialog.
    /// @param sender The source of the event.
    /// @param e A xtd::forms::find_event_args that contains the event data.
    /// @par Header
    /// @code #include <xtd/forms/find_event_handler> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    using find_event_handler = delegate<void(object& sender, const find_event_args& e)>;
  }
}
