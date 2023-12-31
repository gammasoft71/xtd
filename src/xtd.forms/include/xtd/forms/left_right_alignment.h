/// @file
/// @brief Contains xtd::forms::left_right_alignment enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies whether an object or text is aligned to the left or right of a reference point.
    /// @par Header
    /// @code #include <xtd/forms/left_right_alignment> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class left_right_alignment {
      /// @brief The object or text is aligned to the left of the reference point.
      left = 0,
      /// @brief The object or text is aligned to the right of the reference point.
      right = 1,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::left_right_alignment> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::left_right_alignment> {{xtd::forms::left_right_alignment::left, "left"}, {xtd::forms::left_right_alignment::right, "right"}};}
};
/// @endcond
