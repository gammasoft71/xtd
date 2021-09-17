/// @file
/// @brief Contains xtd::forms::message_box_icon enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/forms/message_dialog_icon.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies constants defining which information to display.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the message_box class. The description of each member of this enumeration contains a typical representation of the symbol. The actual graphic displayed is a function of the operating system constants. In current implementations there are four unique symbols with multiple values assigned to them.
    using message_box_icon = message_dialog_icon;
  }
}
