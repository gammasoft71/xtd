/// @file
/// @brief Contains xtd::drawing::xtd_system_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::xtd_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ xtd_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::xtd_system_images
    /// @par Header
    /// @code #include <xtd/drawing/xtd_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ xtd_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the xtd system image "gammasoft".
      /// @return The xtd::drawing::image "gammasoft".
      static xtd::drawing::image gammasoft() noexcept;
      /// @brief Gets the xtd system image "gammasoft" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "gammasoft".
      static xtd::drawing::image gammasoft(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd".
      /// @return The xtd::drawing::image "xtd".
      static xtd::drawing::image xtd() noexcept;
      /// @brief Gets the xtd system image "xtd" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd".
      static xtd::drawing::image xtd(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-console".
      /// @return The xtd::drawing::image "xtd-console".
      static xtd::drawing::image xtd_console() noexcept;
      /// @brief Gets the xtd system image "xtd-console" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-console".
      static xtd::drawing::image xtd_console(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-forms".
      /// @return The xtd::drawing::image "xtd-forms".
      static xtd::drawing::image xtd_forms() noexcept;
      /// @brief Gets the xtd system image "xtd-forms" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-forms".
      static xtd::drawing::image xtd_forms(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-tunit".
      /// @return The xtd::drawing::image "xtd-tunit".
      static xtd::drawing::image xtd_tunit() noexcept;
      /// @brief Gets the xtd system image "xtd-tunit" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-tunit".
      static xtd::drawing::image xtd_tunit(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-core".
      /// @return The xtd::drawing::image "xtd-core".
      static xtd::drawing::image xtd_core() noexcept;
      /// @brief Gets the xtd system image "xtd-core" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-core".
      static xtd::drawing::image xtd_core(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-delegates".
      /// @return The xtd::drawing::image "xtd-delegates".
      static xtd::drawing::image xtd_delegates() noexcept;
      /// @brief Gets the xtd system image "xtd-delegates" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-delegates".
      static xtd::drawing::image xtd_delegates(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-diagnostics".
      /// @return The xtd::drawing::image "xtd-diagnostics".
      static xtd::drawing::image xtd_diagnostics() noexcept;
      /// @brief Gets the xtd system image "xtd-diagnostics" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-diagnostics".
      static xtd::drawing::image xtd_diagnostics(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-drawing".
      /// @return The xtd::drawing::image "xtd-drawing".
      static xtd::drawing::image xtd_drawing() noexcept;
      /// @brief Gets the xtd system image "xtd-drawing" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-drawing".
      static xtd::drawing::image xtd_drawing(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-io".
      /// @return The xtd::drawing::image "xtd-io".
      static xtd::drawing::image xtd_io() noexcept;
      /// @brief Gets the xtd system image "xtd-io" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-io".
      static xtd::drawing::image xtd_io(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-strings".
      /// @return The xtd::drawing::image "xtd-strings".
      static xtd::drawing::image xtd_strings() noexcept;
      /// @brief Gets the xtd system image "xtd-strings" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-strings".
      static xtd::drawing::image xtd_strings(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the xtd system image "xtd-cmake".
      /// @return The xtd::drawing::image "xtd-cmake".
      static xtd::drawing::image xtd_cmake() noexcept;
      /// @brief Gets the xtd system image "xtd-cmake" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-cmake".
      static xtd::drawing::image xtd_cmake(const xtd::drawing::size& size) noexcept;

      /// @}

      /// @name Methods

      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      static const std::vector<xtd::drawing::image>& get_images() noexcept;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      static std::vector<xtd::drawing::image> get_images(const xtd::drawing::size& size) noexcept;

      /// @brief Gets an array of image names.
      /// @return The array of image names.
      static const std::vector<xtd::ustring>& get_image_names() noexcept;
      /// @}
    };
  }
}
