/// @file
/// @brief Contains xtd::drawing::copy_pixel_operation enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Determines how the source color in a copy pixel operation is combined with the destination color to result in a final color.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    /// @remarks The xtd::drawing::copy_pixel_operation enumeration is used by the xtd::drawing::graphics::copy_from_screen method of the xtd::drawing::graphics class.
    enum class copy_pixel_operation {
      /// @brief The destination area is filled by using the color associated with index 0 in the physical palette. (This color is black for the default physical palette.)
      blackness = 66,
      /// @brief Windows that are layered on top of your window are included in the resulting image. By default, the image contains only your window. Note that this generally cannot be used for printing device contexts.
      capture_blt = 1073741824,
      /// @brief The destination area is inverted.
      destination_invert = 5570569,
      /// @brief The colors of the source area are merged with the colors of the selected brush of the destination device context using the Boolean AND operator.
      merge_copy = 12583114,
      /// @brief The colors of the inverted source area are merged with the colors of the destination area by using the Boolean OR operator.
      merge_paint = 12255782,
      /// @brief The bitmap is not mirrored.
      no_mirror_bitmap = -2147483648,
      /// @brief The inverted source area is copied to the destination.
      not_source_copy = 3342344,
      /// @brief The source and destination colors are combined using the Boolean OR operator, and then resultant color is then inverted.
      not_source_erase = 1114278,
      /// @brief The brush currently selected in the destination device context is copied to the destination bitmap.
      pat_copy = 15728673,
      /// @brief The colors of the brush currently selected in the destination device context are combined with the colors of the destination are using the Boolean XOR operator.
      pat_invert = 5898313,
      /// @brief The colors of the brush currently selected in the destination device context are combined with the colors of the inverted source area using the Boolean OR operator. The result of this operation is combined with the colors of the destination area using the Boolean OR operator.
      pat_paint = 16452105,
      /// @brief The colors of the source and destination areas are combined using the Boolean AND operator.
      source_and = 8913094,
      /// @brief The source area is copied directly to the destination area.
      source_copy = 13369376,
      /// @brief The inverted colors of the destination area are combined with the colors of the source area using the Boolean AND operator.
      source_erase = 4457256,
      /// @brief The colors of the source and destination areas are combined using the Boolean XOR operator.
      source_invert = 6684742,
      /// @brief The colors of the source and destination areas are combined using the Boolean OR operator.
      source_paint = 15597702,
      /// @brief The destination area is filled by using the color associated with index 1 in the physical palette. (This color is white for the default physical palette.)
      whiteness = 16711778,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::copy_pixel_operation> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::copy_pixel_operation> {{xtd::drawing::copy_pixel_operation::blackness, "blackness"}, {xtd::drawing::copy_pixel_operation::capture_blt, "capture_blt"}, {xtd::drawing::copy_pixel_operation::destination_invert, "destination_invert"}, {xtd::drawing::copy_pixel_operation::merge_copy, "merge_copy"}, {xtd::drawing::copy_pixel_operation::merge_paint, "merge_paint"}, {xtd::drawing::copy_pixel_operation::no_mirror_bitmap, "no_mirror_bitmap"}, {xtd::drawing::copy_pixel_operation::not_source_copy, "not_source_copy"}, {xtd::drawing::copy_pixel_operation::not_source_erase, "not_source_erase"}, {xtd::drawing::copy_pixel_operation::pat_copy, "pat_copy"}, {xtd::drawing::copy_pixel_operation::pat_invert, "pat_invert"}, {xtd::drawing::copy_pixel_operation::pat_paint, "pat_paint"}, {xtd::drawing::copy_pixel_operation::source_and, "source_and"}, {xtd::drawing::copy_pixel_operation::source_copy, "source_copy"}, {xtd::drawing::copy_pixel_operation::source_erase, "source_erase"}, {xtd::drawing::copy_pixel_operation::source_invert, "source_invert"}, {xtd::drawing::copy_pixel_operation::source_paint, "source_paint"}, {xtd::drawing::copy_pixel_operation::whiteness, "whiteness"}};}
};
/// @endcond
