/// @file
/// @brief Contains xtd::forms::system_texts factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/texts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of string objects for use by a Windows Forms application.
    /// @deprecated Replaced by xtd::drawing::texts - Will be removed in version 0.4.0
    using system_texts [[deprecated("Replaced by xtd::drawing::texts - Will be removed in version 0.4.0")]] = xtd::drawing::texts;
  }
}
