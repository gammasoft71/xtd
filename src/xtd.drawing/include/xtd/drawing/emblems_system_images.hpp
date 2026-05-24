/// @file
/// @brief Contains xtd::drawing::emblems_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::emblems_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ emblems_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::emblems_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/emblems_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ emblems_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the emblems system image "emblem-default".
      /// @return The xtd::drawing::image "emblem-default".
      [[nodiscard]] static auto emblem_default() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-default" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-default".
      [[nodiscard]] static auto emblem_default(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-documents".
      /// @return The xtd::drawing::image "emblem-documents".
      [[nodiscard]] static auto emblem_documents() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-documents" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-documents".
      [[nodiscard]] static auto emblem_documents(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-downloads".
      /// @return The xtd::drawing::image "emblem-downloads".
      [[nodiscard]] static auto emblem_downloads() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-downloads" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-downloads".
      [[nodiscard]] static auto emblem_downloads(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-favorite".
      /// @return The xtd::drawing::image "emblem-favorite".
      [[nodiscard]] static auto emblem_favorite() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-favorite" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-favorite".
      [[nodiscard]] static auto emblem_favorite(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-important".
      /// @return The xtd::drawing::image "emblem-important".
      [[nodiscard]] static auto emblem_important() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-important" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-important".
      [[nodiscard]] static auto emblem_important(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-locked".
      /// @return The xtd::drawing::image "emblem-locked".
      [[nodiscard]] static auto emblem_locked() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-locked" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-locked".
      [[nodiscard]] static auto emblem_locked(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-mail".
      /// @return The xtd::drawing::image "emblem-mail".
      [[nodiscard]] static auto emblem_mail() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-mail" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-mail".
      [[nodiscard]] static auto emblem_mail(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-new".
      /// @return The xtd::drawing::image "emblem-new".
      [[nodiscard]] static auto emblem_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-new" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-new".
      [[nodiscard]] static auto emblem_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-photos".
      /// @return The xtd::drawing::image "emblem-photos".
      [[nodiscard]] static auto emblem_photos() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-photos" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-photos".
      [[nodiscard]] static auto emblem_photos(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-readonly".
      /// @return The xtd::drawing::image "emblem-readonly".
      [[nodiscard]] static auto emblem_readonly() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-readonly" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-readonly".
      [[nodiscard]] static auto emblem_readonly(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-shared".
      /// @return The xtd::drawing::image "emblem-shared".
      [[nodiscard]] static auto emblem_shared() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-shared" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-shared".
      [[nodiscard]] static auto emblem_shared(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-symbolic-link".
      /// @return The xtd::drawing::image "emblem-symbolic-link".
      [[nodiscard]] static auto emblem_symbolic_link() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-symbolic-link" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-symbolic-link".
      [[nodiscard]] static auto emblem_symbolic_link(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-synchronizing".
      /// @return The xtd::drawing::image "emblem-synchronizing".
      [[nodiscard]] static auto emblem_synchronizing() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-synchronizing" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-synchronizing".
      [[nodiscard]] static auto emblem_synchronizing(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-system".
      /// @return The xtd::drawing::image "emblem-system".
      [[nodiscard]] static auto emblem_system() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-system" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-system".
      [[nodiscard]] static auto emblem_system(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-unlocked".
      /// @return The xtd::drawing::image "emblem-unlocked".
      [[nodiscard]] static auto emblem_unlocked() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-unlocked" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-unlocked".
      [[nodiscard]] static auto emblem_unlocked(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the emblems system image "emblem-unreadable".
      /// @return The xtd::drawing::image "emblem-unreadable".
      [[nodiscard]] static auto emblem_unreadable() noexcept -> xtd::drawing::image;
      /// @brief Gets the emblems system image "emblem-unreadable" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-unreadable".
      [[nodiscard]] static auto emblem_unreadable(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
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
