/// @file
/// @brief Contains xtd::forms::message_box_options enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/forms/message_dialog_options.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies options on a message_box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
    /// @remarks This enumeration is used by the MessageBox class.
    /// @remarks If you do not want to specify this parameter when calling methods on MessageBox, you can pass in 0 instead.
    using message_box_options = message_dialog_options;
  }
}
