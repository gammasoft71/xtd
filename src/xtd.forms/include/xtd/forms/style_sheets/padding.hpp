/// @file
/// @brief Contains xtd::forms::style_sheets::padding alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "lengths.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Padding is used to create space around an element's content, inside of any defined borders.
      /// ```cpp
      /// using padding = xtd::forms::style_sheets::lengths
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/padding>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      using padding = xtd::forms::style_sheets::lengths;
    }
  }
}
