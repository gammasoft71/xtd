/// @file
/// @brief Contains xtd::forms::content_alignment enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies alignment of content on the drawing surface.
    /// @par Header
    /// @code #include <xtd/forms/content_alignment> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class content_alignment {
      /// @brief Content is vertically aligned at the top, and horizontally aligned on the left.
      top_left = 0b1,
      /// @brief Content is vertically aligned at the top, and horizontally aligned at the center.
      top_center = 0b10,
      /// @brief Content is vertically aligned at the top, and horizontally aligned on the right.
      top_right = 0b100,
      /// @brief Content is vertically aligned in the middle, and horizontally aligned on the left.
      middle_left = 0b10000,
      /// @brief Content is vertically aligned at the middle, and horizontally aligned at the center.
      middle_center = 0b100000,
      /// @brief Content is vertically aligned at the middle, and horizontally aligned on the right.
      middle_right = 0b1000000,
      /// @brief Content is vertically aligned in the bottom, and horizontally aligned on the left.
      bottom_left = 0b100000000,
      /// @brief Content is vertically aligned at the bottom, and horizontally aligned at the center.
      bottom_center = 0b1000000000,
      /// @brief Content is vertically aligned at the bottom, and horizontally aligned on the right.
      bottom_right = 0b10000000000,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::content_alignment> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::content_alignment> {{xtd::forms::content_alignment::top_left, "top_left"}, {xtd::forms::content_alignment::top_center, "top_center"}, {xtd::forms::content_alignment::top_right, "top_right"}, {xtd::forms::content_alignment::middle_left, "middle_left"}, {xtd::forms::content_alignment::middle_center, "middle_center"}, {xtd::forms::content_alignment::middle_right, "middle_right"}, {xtd::forms::content_alignment::bottom_left, "bottom_left"}, {xtd::forms::content_alignment::bottom_center, "bottom_center"}, {xtd::forms::content_alignment::bottom_right, "bottom_right"}};}
};
/// @endcond
