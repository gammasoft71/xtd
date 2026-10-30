/// @file
/// @brief Contains xtd::forms::application_appearance enum class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the appearance of a application.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/application_appearance>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class application_appearance {
      /// @brief The appearance of the applicaiotn is determined by the user's operating system.
      system = 0,
      /// @brief The appearance of the applicaiotn is forced to light.
      light,
      /// @brief The appearance of the applicaiotn is forced to dark.
      dark,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::application_appearance> {
  static auto values() noexcept {return xtd::enum_collection<xtd::forms::application_appearance> {{xtd::forms::application_appearance::system, "system"}, {xtd::forms::application_appearance::light, "light"}, {xtd::forms::application_appearance::dark, "dark"}};}
};
/// @endcond
