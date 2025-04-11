/// @file
/// @brief Contains xtd::forms::shadows typedef.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "shadow.hpp"
#include <xtd/array>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents an xtd::forms::shadow array.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/shadows>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    using shadows = xtd::array<xtd::forms::shadow>;
  }
}

