/// @file
/// @brief Contains xtd::forms::style_sheets::description_property alias.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "string_value.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The description property allows you to specify the description string of a theme selector.
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      using description_property = xtd::forms::style_sheets::string_value;
    }
  }
}
