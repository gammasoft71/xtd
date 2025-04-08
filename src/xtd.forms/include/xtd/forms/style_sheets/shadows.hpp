/// @file
/// @brief Contains xtd::forms::style_sheets::shadows typedef.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "shadow.hpp"
#include <xtd/collections/generic/list>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief Represents an xtd::forms::style_sheets::shadow array.
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/shadows>
      /// ```
      /// @par Namespace
      /// xtd::forms
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      using shadows = xtd::collections::generic::list<xtd::forms::style_sheets::shadow>;
    }
  }
}

