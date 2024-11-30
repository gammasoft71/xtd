/// @file
/// @brief Contains xtd::drawing::imaging::image_lock_mode  class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd.drawing.imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief Specifies flags that are passed to the flags parameter of the xtd::drawing::bitmap::lock_bits method. The xtd::drawing::bitmap::lock_bits method locks a portion of an image so that you can read or write the pixel data.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class image_lock_mode {
        /// @brief Specifies that a portion of the image is locked for reading.
        read_only = 1,
        /// @brief Specifies that a portion of the image is locked for writing.
        write_only = 2,
        /// @brief Specifies that a portion of the image is locked for reading or writing.
        read_write = 3,
        /// @brief Specifies that the buffer used for reading or writing pixel data is allocated by the user. If this flag is set, the flags parameter of the xtd::drawing::bitmap::lock_bits method serves as an input parameter (and possibly as an output parameter). If this flag is cleared, then the flags parameter serves only as an output parameter.
        user_input_buffer = 4,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::imaging::image_lock_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::imaging::image_lock_mode> {{xtd::drawing::imaging::image_lock_mode::read_only, "read_only"}, {xtd::drawing::imaging::image_lock_mode::write_only, "write_only"}, {xtd::drawing::imaging::image_lock_mode::read_write, "read_write"}, {xtd::drawing::imaging::image_lock_mode::user_input_buffer, "user_input_buffer"}};}
};
/// @endcond
