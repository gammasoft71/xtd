/// @file
/// @brief Contains xtd::forms::style_sheets::toggle_button alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The buttton data allows you to specify the box of a toggle_button control.
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/togle_button>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks You need to know how the box model works.
      /// @remarks For more information, see [Box Model](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.forms/Style%20sheets/style_sheets_box_model).
      using toggle_button = xtd::forms::style_sheets::control;
    }
  }
}
