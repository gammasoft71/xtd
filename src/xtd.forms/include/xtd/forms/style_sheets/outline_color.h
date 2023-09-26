/// @file
/// @brief Contains xtd::forms::style_sheets::outline_color alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "border_color"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::outline_color is used to set the color of the outlines.
      /// @code
      /// using outline_color = xtd::forms::style_sheets::border_color
      /// @endcode
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/outline_color> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      using outline_color = xtd::forms::style_sheets::border_color;
    }
  }
}
