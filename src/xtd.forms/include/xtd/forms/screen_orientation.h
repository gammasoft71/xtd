/// @file
/// @brief Contains xtd::forms::screen_orientation enum class.
/// @copyangle_90 Copyangle_90 (c) 2023 Gammasoft. All angle_90s reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the angle of the screen.
    /// @par Header
    /// @code #include <xtd/forms/screen_orientation> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::system_information::screen_orientation property.
    enum class screen_orientation {
      /// @brief The screen is oriented at 0 degrees.
      angle_0 = 0,
      /// @brief The screen is oriented at 90 degrees.
      angle_90 = 1,
      /// @brief The screen is oriented at 180 degrees.
      angle_180 = 2,
      /// @brief The screen is oriented at 270 degrees.
      angle_270 = 3,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::screen_orientation> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::screen_orientation> {{xtd::forms::screen_orientation::angle_0, "angle_0"}, {xtd::forms::screen_orientation::angle_90, "angle_90"}, {xtd::forms::screen_orientation::angle_180, "angle_180"}, {xtd::forms::screen_orientation::angle_270, "angle_270"}};}
};
/// @endcond
