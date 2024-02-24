/// @file
/// @brief Contains xtd::drawing::drawing_2d::compositing_mode enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Specifies how the source colors are combined with the background colors.
      /// @par Namespace
      /// xtd::drawing::drawing_2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class compositing_mode {
        /// @brief Specifies that when a color is rendered, it is blended with the background color. The blend is determined by the alpha component of the color being rendered.
        source_over = 0,
        /// @brief Specifies that when a color is rendered, it overwrites the background color.
        source_copy = 1,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::drawing_2d::compositing_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::drawing_2d::compositing_mode> {{xtd::drawing::drawing_2d::compositing_mode::source_over, "source_over"}, {xtd::drawing::drawing_2d::compositing_mode::source_copy, "source_copy"}};}
};
/// @endcond
