#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <istream>
#include <vector>
#include <xtd/static>
#include <xtd/string>
#include <xtd/drawing_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class icon;
    class image;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains icon native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ icon final static_ {
        friend xtd::drawing::icon;
        friend xtd::drawing::image;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates an icon from specified filename.
        /// @param filename The filename of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        [[nodiscard]] static auto create(const xtd::string& filename) -> xtd::intptr;
        /// @brief Creates an icon from specified filename, and size.
        /// @param filename The filename of the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        [[nodiscard]] static auto create(const xtd::string& filename, xtd::int32 width, xtd::int32 height) -> xtd::intptr;
        /// @brief Creates an icon from specified std::stream.
        /// @param stream The stream containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        [[nodiscard]] static auto create(std::istream& stream) -> xtd::intptr;
        /// @brief Creates an icon from specified std::stream, and size.
        /// @param stream The stream containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        [[nodiscard]] static auto create(std::istream& stream, xtd::int32 width, xtd::int32 height) -> xtd::intptr;
        /// @brief Creates an icon from bits.
        /// @param bits The bits containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        /// @remarks This method is used for creating an icon from an XPM (or XBM) image.
        [[nodiscard]] static auto create(const char* const* bits) -> xtd::intptr;
        /// @brief Creates an icon from specified bits, and size.
        /// @param stream The bits containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @remarks This method is used for creating an icons from an XPM (or XBM) image.
        /// @warning Internal use only
        [[nodiscard]] static auto create(const char* const* bits, xtd::int32 width, xtd::int32 height) -> xtd::intptr;
        /// @brief Creates an icon from image.
        /// @param image The image handle containing the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        [[nodiscard]] static auto create(xtd::intptr image) -> xtd::intptr;
        /// @brief Creates an icon from specified icon, and size.
        /// @param icon The icon handle containing the icon.
        /// @param width The desired width of the icon.
        /// @param height The desired height of the icon.
        /// @return A new icon handle.
        /// @warning Internal use only
        [[nodiscard]] static auto create(xtd::intptr icon, xtd::int32 width, xtd::int32 height) -> xtd::intptr;
        
        /// @brief Destroys the icon.
        /// @param icon The icon handle to destroy.
        /// @warning Internal use only
        static auto destroy(xtd::intptr icon) -> void;
        
        /// @brief Creates an icon from handle.
        /// @param handle The icon handle .
        /// @return A new icon handle.
        /// @warning Internal use only
        [[nodiscard]] static auto from_handle(xtd::intptr handle) -> xtd::intptr;
        
        /// @brief Gets the height of icon.
        /// @param icon The icon handle .
        /// @return The height of icon.
        /// @warning Internal use only
        [[nodiscard]] static auto get_height(xtd::intptr icon) -> xtd::int32;
        
        /// @brief Gets the width of icon.
        /// @param icon The icon handle .
        /// @return The width of icon.
        /// @warning Internal use only
        [[nodiscard]] static auto get_width(xtd::intptr icon) -> xtd::int32;
        
        /// @brief Saves icon to the specified output filename.
        /// @param icon The icon handle .
        /// @param filename The file to save to.
        /// @warning Internal use only
        static auto save(xtd::intptr icon, const xtd::string& filename) -> void;
        /// @brief Saves icon to the specified output std::ostream.
        /// @param icon The icon handle .
        /// @param stream The std::ostream to save to.
        /// @warning Internal use only
        static auto save(xtd::intptr icon, std::ostream& stream, xtd::usize raw_format) -> void;
        
        /// @brief Converts icon to an image.
        /// @param icon The icon handle .
        /// @return A image handle that represents the converted icon.
        /// @warning Internal use only
        [[nodiscard]] static auto to_image(xtd::intptr icon) -> xtd::intptr;
        /// @}
      };
    }
  }
}
