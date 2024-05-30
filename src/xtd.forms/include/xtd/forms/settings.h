/// @file
/// @brief Contains xtd::forms::settings component.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/configuration/settings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent settings associate to the application.
    /// @deprecated Replaced by xtd::settings - Will be removed in version 0.4.0
    using settings [[deprecated("Replaced by xtd::configuration::settings - Will be removed in version 0.4.0")]] = xtd::configuration::settings;
  }
}
