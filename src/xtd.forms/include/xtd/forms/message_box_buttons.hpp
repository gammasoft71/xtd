/// @file
/// @brief Contains xtd::forms::message_box_buttons enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "message_dialog_buttons.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which buttons to display on a message_box.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/message_box_buttons>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the message_box class.
    using message_box_buttons = message_dialog_buttons;
  }
}
