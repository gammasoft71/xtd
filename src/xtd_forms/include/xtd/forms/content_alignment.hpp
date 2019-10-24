#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies alignment of content on the drawing surface.
    enum class content_alignment {
      /// @brief Content is vertically aligned at the top, and horizontally aligned on the left.
      top_left = 1,
      /// @brief Content is vertically aligned at the top, and horizontally aligned at the center.
      top_center = 2,
      /// @brief Content is vertically aligned at the top, and horizontally aligned on the right.
      top_right = 4,
      /// @brief Content is vertically aligned in the middle, and horizontally aligned on the left.
      middle_left = 16,
      /// @brief Content is vertically aligned at the middle, and horizontally aligned at the center.
      middle_center = 32,
      /// @brief Content is vertically aligned at the middle, and horizontally aligned on the right.
      middle_right = 64,
      /// @brief Content is vertically aligned in the bottom, and horizontally aligned on the left.
      bottom_left = 256,
      /// @brief Content is vertically aligned at the bottom, and horizontally aligned at the center.
      bottom_center = 512,
      /// @brief Content is vertically aligned at the bottom, and horizontally aligned on the right.
      bottom_right = 1024,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, content_alignment value) {return os << to_string(value, {{content_alignment::top_left, "top_left"}, {content_alignment::top_center, "top_center"}, {content_alignment::top_right, "top_right"}, {content_alignment::middle_left, "middle_left"}, {content_alignment::middle_center, "middle_center"}, {content_alignment::middle_right, "middle_right"}, {content_alignment::bottom_left, "bottom_left"}, {content_alignment::bottom_center, "bottom_center"}, {content_alignment::bottom_right, "bottom_right"}});}
    inline std::wostream& operator<<(std::wostream& os, content_alignment value) {return os << to_string(value, {{content_alignment::top_left, L"top_left"}, {content_alignment::top_center, L"top_center"}, {content_alignment::top_right, L"top_right"}, {content_alignment::middle_left, L"middle_left"}, {content_alignment::middle_center, L"middle_center"}, {content_alignment::middle_right, L"middle_right"}, {content_alignment::bottom_left, L"bottom_left"}, {content_alignment::bottom_center, L"bottom_center"}, {content_alignment::bottom_right, L"bottom_right"}});}
    /// @endcond
  }
}
