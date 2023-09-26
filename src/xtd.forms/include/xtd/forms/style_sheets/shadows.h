/// @file
/// @brief Contains xtd::forms::style_sheets::shadows typedef.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "shadow"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Represents an xtd::forms::style_sheets::shadow array.
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/shadows> @endcode
      /// @par Namespace
      /// xtd::forms
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      using shadows = std::vector<xtd::forms::style_sheets::shadow>;
    }
  }
}

