/// @file
/// @brief Contains xtd::drawing::rotate_flip_type enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies how much an image is rotated and the axis used to flip the image.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    /// @remarks The xtd::drawing::image::rotate_flip method rotates the image clockwise.
    /// @remarks If you wish to draw on an image once it has been rotated, you should always retrieve a new graphics object from the image, otherwise an exception could occur.
    enum class rotate_flip_type {
      /// @brief Specifies no clockwise rotation and no flipping.
      rotate_none_flip_none = 0,
      /// @brief Specifies a 270-degree clockwise rotation followed by a horizontal and vertical flip.
      rotate_90_flip_none = 1,
      /// @brief Specifies a 180-degree clockwise rotation without flipping.
      rotate_180_flip_none = 2,
      /// @brief Specifies a 270-degree clockwise rotation without flipping.
      rotate_270_flip_none = 3,
      
      /// @brief Specifies no clockwise rotation followed by a horizontal flip.
      rotate_none_flip_x = 4,
      /// @brief Specifies a 90-degree clockwise rotation followed by a horizontal flip.
      rotate_90_flip_x = 5,
      /// @brief Specifies a 180-degree clockwise rotation followed by a horizontal flip.
      rotate_180_flip_x = 6,
      /// @brief Specifies a 270-degree clockwise rotation followed by a horizontal flip.
      rotate_270_flip_x = 7,
      
      /// @brief Specifies no clockwise rotation followed by a vertical flip.
      rotate_none_flip_y = rotate_180_flip_x,
      /// @brief Specifies a 90-degree clockwise rotation followed by a vertical flip.
      rotate_90_flip_y = rotate_270_flip_x,
      /// @brief Specifies a 180-degree clockwise rotation followed by a vertical flip.
      rotate_180_flip_y = rotate_none_flip_x,
      /// @brief Specifies a 270-degree clockwise rotation followed by a vertical flip.
      rotate_270_flip_y = rotate_90_flip_x,
      
      /// @brief Specifies no clockwise rotation followed by a horizontal and vertical flip.
      rotate_none_flip_xy = rotate_180_flip_none,
      /// @brief Specifies a 90-degree clockwise rotation followed by a horizontal and vertical flip.
      rotate_90_flip_xy = rotate_270_flip_none,
      /// @brief Specifies a 180-degree clockwise rotation followed by a horizontal and vertical flip.
      rotate_180_flip_xy = rotate_none_flip_none,
      /// @brief Specifies a 90-degree clockwise rotation without flipping.
      rotate_270_flip_xy = rotate_90_flip_none,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::rotate_flip_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::rotate_flip_type> {{xtd::drawing::rotate_flip_type::rotate_none_flip_none, "rotate_none_flip_none"}, {xtd::drawing::rotate_flip_type::rotate_90_flip_none, "rotate_90_flip_none"}, {xtd::drawing::rotate_flip_type::rotate_180_flip_none, "rotate_180_flip_none"}, {xtd::drawing::rotate_flip_type::rotate_270_flip_none, "rotate_270_flip_none"}, {xtd::drawing::rotate_flip_type::rotate_none_flip_x, "rotate_none_flip_x"}, {xtd::drawing::rotate_flip_type::rotate_90_flip_x, "rotate_90_flip_x"}, {xtd::drawing::rotate_flip_type::rotate_180_flip_x, "rotate_180_flip_x"}, {xtd::drawing::rotate_flip_type::rotate_270_flip_x, "rotate_270_flip_x"}};}
};
/// @endcond
