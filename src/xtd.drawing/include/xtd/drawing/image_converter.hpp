/// @file
/// @brief Contains xtd::drawing::image_converter class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "image.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class bitmap;
    /// @endcond
    
    /// @brief Converts images to and from xtd::drawing::image class. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ image_converter final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::image_converter
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    class drawing_export_ image_converter final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Convert specified base64 string to image.
      /// @param value A base64 string that contains the image.
      /// @return The converted image from base64 string.
      /// @remarks The first eight bytes contain the width followed by the height of the image. The following bytes contain the ARGB components of the image pixels.
      static xtd::drawing::image from_base64_string(const xtd::string& value);

      /// @brief Convert specified image to byte array.
      /// @param value The image to convert into byte array.
      /// @return A byte array that contains the image.
      /// @remarks The first eight bytes contain the width followed by the height of the image. The following bytes contain the ARGB components of the image pixels.
      static xtd::array<xtd::byte> to_array(const xtd::drawing::image& value);
      
      /// @brief Convert specified image to base64 string.
      /// @param value The image to convert into base64 string.
      /// @return A base64 string that contains the image.
      /// @remarks The first eight bytes contain the width followed by the height of the image. The following bytes contain the ARGB components of the image pixels.
      static xtd::string to_base64_string(const xtd::drawing::image& value);
      
      /// @brief Convert specified image to file.
      /// @param value The image to convert into base64 string.
      /// @param filename A string that contains the name of the file to which to save this xtd::drawing::image.
      /// @remarks If no encoder exists for the file format of the image, the Portable Network Graphics (PNG) encoder is used. When you use the xtd::drawing::image::save method to save a graphic image as a Windows Metafile Format (WMF) or Enhanced Metafile Format (EMF) file, the resulting file is saved as a Portable Network Graphics (PNG) file. This behavior occurs because the GDI+ component of the .NET Framework does not have an encoder that you can use to save files as .wmf or .emf files.
      /// @remarks Saving the image to the same file it was constructed from is not allowed and throws an exception.
      static void to_file(const xtd::drawing::image& value, const xtd::string& filename);
      /// @brief Convert specified image to file.
      /// @param value The image to convert into base64 string.
      /// @param filename A string that contains the name of the file to which to save this xtd::drawing::image.
      /// @param format The xtd::drawing::imaging::image_format for this xtd::drawing::image.
      static void to_file(const xtd::drawing::image& value, const xtd::string& filename, const xtd::drawing::imaging::image_format& format);
      
      /// @brief Convert specified byte array to image.
      /// @param value A byte array that contains the image.
      /// @return The converted image from byte array.
      /// @remarks The first eight bytes contain the width followed by the height of the image. The following bytes contain the ARGB components of the image pixels.
      static xtd::drawing::image to_image(const xtd::array<xtd::byte>& value);
      /// @brief Convert specified bytes span to image.
      /// @param value A bytes span that contains the image.
      /// @return The converted image from byte array.
      /// @remarks The first eight bytes contain the width followed by the height of the image. The following bytes contain the ARGB components of the image pixels.
      static xtd::drawing::image to_image(const xtd::read_only_span<xtd::byte>& value);
      /// @brief Convert specified file name string.
      /// @param filename A file name string that contains the image.
      /// @return The converted image from file name string.
      static xtd::drawing::image to_image(const xtd::string& filename);
      /// @brief Convert specified stream to image.
      /// @param stream The input stream that contains the image.
      /// @return The converted image from stream.
      static xtd::drawing::image to_image(std::istream& stream);

      /// @brief Convert specified image to stream.
      /// @param value The image to convert.
      /// @param stream The output stream where to write the image.
      /// @param format The xtd::drawing::imaging::image_format for this xtd::drawing::image.
      /// @remarks You should avoid saving an image to the same stream that was used to construct it. Doing so might damage the stream.
      /// @remarks The image must be saved to the stream at an offset of zero. If any additional data has been written to the stream before saving the image, the image data in the stream will be corrupted.
      static void to_stream(const xtd::drawing::image& value, std::ostream& stream, const xtd::drawing::imaging::image_format& format);
      /// @}
    };
  }
}
