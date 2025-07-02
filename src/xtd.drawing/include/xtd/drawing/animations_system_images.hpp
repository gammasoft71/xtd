/// @file
/// @brief Contains xtd::drawing::animations_system_images factory.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::animations_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ animations_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::animations_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/animations_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ animations_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;
      
      /// @brief Gets the animations system image "process-working".
      /// @return The xtd::drawing::image "process-working".
      static xtd::drawing::image process_working() noexcept;
      /// @brief Gets the animations system image "process-working" with specified size.
      /// @param size The animations system image size in pixels.
      /// @return The xtd::drawing::image "process-working".
      static xtd::drawing::image process_working(const xtd::drawing::size& size) noexcept;
      
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      static const xtd::array<xtd::drawing::image>& get_images() noexcept;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      static xtd::array<xtd::drawing::image> get_images(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an array of image names.
      /// @return The array of image names.
      static const xtd::array<xtd::string>& get_image_names() noexcept;
      /// @}
    };
  }
}
