/// @file
/// @brief Contains xtd::drawing::imaging::color_palette class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../color.hpp"
#include <xtd/collections/generic/list>
#include <xtd/iequatable>
#include <xtd/object>
#include <cstdint>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class image;
    /// @endcond
    
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Defines an array of colors that make up a color palette. The colors are 32-bit ARGB colors. Not inheritable.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks You are not allowed to construct a color_palette object directly. If you created a color_palette object, you could then manipulate the palette size for a particular image, which is not allowed. Use the image.palette property to obtain a color_palette object.
      /// @remarks The colors in the palette are limited to 32-bit ARGB colors. A 32-bit ARGB color has 8 bits each for alpha, red, green, and blue values. The lowest 8 bits make up the blue bit, the next 8 bits are green, the next 8 bits are red, and the most significant 8 bits are alpha. This means each component can vary from 0 to 255. Fully on is 255 and fully off is 0. Alpha is used to make the color value transparent (alpha = 0) or opaque (alpha = 255). The number of intensity levels in the image can be increased without increasing the number of colors used. This process creates what is called a halftone, and it offers increased contrast at a cost of decreased resolution.
      class color_palette final : public object, public xtd::iequatable<color_palette> {
      public:
        /// @cond
        color_palette(color_palette&&) = default;
        color_palette(const color_palette&) = default;
        color_palette& operator =(color_palette&&) = default;
        color_palette& operator =(const color_palette&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets an array of color structures.
        /// @return The array of color structure that make up this color_palette.
        xtd::array<color> entries() const noexcept;
        
        /// @brief Gets a value that specifies how to interpret the color information in the array of colors.
        /// @remarks The following flag values are valid:
        /// * 0x00000001 The color values in the array contain alpha information.
        /// * 0x00000002 The colors in the array are grayscale values.
        /// * 0x00000004 The colors in the array are halftone values.
        int32 flags() const noexcept;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const object& obj) const noexcept override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        bool equals(const color_palette& other) const noexcept override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        xtd::size get_hash_code() const noexcept override;
        /// @}
        
      private:
        friend class xtd::drawing::image;
        color_palette() = default;
        xtd::collections::generic::list<color> entries_;
        int32 flags_ = 0;
      };
    }
  }
}
