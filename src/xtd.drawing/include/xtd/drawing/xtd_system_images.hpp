/// @file
/// @brief Contains xtd::drawing::xtd_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::xtd_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ xtd_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::xtd_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/xtd_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ xtd_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the xtd system image "gammasoft".
      /// @return The xtd::drawing::image "gammasoft".
      [[nodiscard]] static auto gammasoft() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "gammasoft" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "gammasoft".
      [[nodiscard]] static auto gammasoft(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd".
      /// @return The xtd::drawing::image "xtd".
      [[nodiscard]] static auto xtd() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd".
      [[nodiscard]] static auto xtd(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-console".
      /// @return The xtd::drawing::image "xtd-console".
      [[nodiscard]] static auto xtd_console() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-console" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-console".
      [[nodiscard]] static auto xtd_console(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-forms".
      /// @return The xtd::drawing::image "xtd-forms".
      [[nodiscard]] static auto xtd_forms() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-forms" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-forms".
      [[nodiscard]] static auto xtd_forms(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-tunit".
      /// @return The xtd::drawing::image "xtd-tunit".
      [[nodiscard]] static auto xtd_tunit() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-tunit" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-tunit".
      [[nodiscard]] static auto xtd_tunit(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-core".
      /// @return The xtd::drawing::image "xtd-core".
      [[nodiscard]] static auto xtd_core() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-core" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-core".
      [[nodiscard]] static auto xtd_core(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-delegates".
      /// @return The xtd::drawing::image "xtd-delegates".
      [[nodiscard]] static auto xtd_delegates() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-delegates" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-delegates".
      [[nodiscard]] static auto xtd_delegates(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-diagnostics".
      /// @return The xtd::drawing::image "xtd-diagnostics".
      [[nodiscard]] static auto xtd_diagnostics() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-diagnostics" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-diagnostics".
      [[nodiscard]] static auto xtd_diagnostics(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-drawing".
      /// @return The xtd::drawing::image "xtd-drawing".
      [[nodiscard]] static auto xtd_drawing() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-drawing" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-drawing".
      [[nodiscard]] static auto xtd_drawing(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-io".
      /// @return The xtd::drawing::image "xtd-io".
      [[nodiscard]] static auto xtd_io() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-io" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-io".
      [[nodiscard]] static auto xtd_io(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-strings".
      /// @return The xtd::drawing::image "xtd-strings".
      [[nodiscard]] static auto xtd_strings() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-strings" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-strings".
      [[nodiscard]] static auto xtd_strings(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the xtd system image "xtd-cmake".
      /// @return The xtd::drawing::image "xtd-cmake".
      [[nodiscard]] static auto xtd_cmake() noexcept -> xtd::drawing::image;
      /// @brief Gets the xtd system image "xtd-cmake" with specified size.
      /// @param size The xtd system image size in pixels.
      /// @return The xtd::drawing::image "xtd-cmake".
      [[nodiscard]] static auto xtd_cmake(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      [[nodiscard]] static auto get_images() noexcept -> const xtd::array<xtd::drawing::image>&;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      [[nodiscard]] static auto get_images(const xtd::drawing::size& size) noexcept -> xtd::array<xtd::drawing::image>;
      
      /// @brief Gets an array of image names.
      /// @return The array of image names.
      [[nodiscard]] static auto get_image_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
