/// @file
/// @brief Contains xtd::forms::dialog_style enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the style of a dialog.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class dialog_style {
      /// @brief Standard style dialog.
      standard = 0,
      /// @brief System style dialog.
      system = 1,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::dialog_style> {
  void operator()(xtd::enum_collection<xtd::forms::dialog_style>& values, xtd::enum_type& type) {values =  {{xtd::forms::dialog_style::standard, "standard"}, {xtd::forms::dialog_style::system, "system"}};}
};
/// @endcond
