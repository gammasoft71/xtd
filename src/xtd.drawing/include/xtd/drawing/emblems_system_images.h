/// @file
/// @brief Contains xtd::drawing::emblems_system_images factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::emblems_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ emblems_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::emblems_system_images
    /// @par Header
    /// @code #include <xtd/drawing/emblems_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ emblems_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the emblems system image "emblem-default".
      /// @return The xtd::drawing::image "emblem-default".
      static xtd::drawing::image emblem_default() noexcept;
      /// @brief Gets the emblems system image "emblem-default" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-default".
      static xtd::drawing::image emblem_default(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-documents".
      /// @return The xtd::drawing::image "emblem-documents".
      static xtd::drawing::image emblem_documents() noexcept;
      /// @brief Gets the emblems system image "emblem-documents" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-documents".
      static xtd::drawing::image emblem_documents(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-downloads".
      /// @return The xtd::drawing::image "emblem-downloads".
      static xtd::drawing::image emblem_downloads() noexcept;
      /// @brief Gets the emblems system image "emblem-downloads" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-downloads".
      static xtd::drawing::image emblem_downloads(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-favorite".
      /// @return The xtd::drawing::image "emblem-favorite".
      static xtd::drawing::image emblem_favorite() noexcept;
      /// @brief Gets the emblems system image "emblem-favorite" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-favorite".
      static xtd::drawing::image emblem_favorite(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-important".
      /// @return The xtd::drawing::image "emblem-important".
      static xtd::drawing::image emblem_important() noexcept;
      /// @brief Gets the emblems system image "emblem-important" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-important".
      static xtd::drawing::image emblem_important(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-locked".
      /// @return The xtd::drawing::image "emblem-locked".
      static xtd::drawing::image emblem_locked() noexcept;
      /// @brief Gets the emblems system image "emblem-locked" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-locked".
      static xtd::drawing::image emblem_locked(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-mail".
      /// @return The xtd::drawing::image "emblem-mail".
      static xtd::drawing::image emblem_mail() noexcept;
      /// @brief Gets the emblems system image "emblem-mail" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-mail".
      static xtd::drawing::image emblem_mail(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-new".
      /// @return The xtd::drawing::image "emblem-new".
      static xtd::drawing::image emblem_new() noexcept;
      /// @brief Gets the emblems system image "emblem-new" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-new".
      static xtd::drawing::image emblem_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-photos".
      /// @return The xtd::drawing::image "emblem-photos".
      static xtd::drawing::image emblem_photos() noexcept;
      /// @brief Gets the emblems system image "emblem-photos" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-photos".
      static xtd::drawing::image emblem_photos(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-readonly".
      /// @return The xtd::drawing::image "emblem-readonly".
      static xtd::drawing::image emblem_readonly() noexcept;
      /// @brief Gets the emblems system image "emblem-readonly" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-readonly".
      static xtd::drawing::image emblem_readonly(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-shared".
      /// @return The xtd::drawing::image "emblem-shared".
      static xtd::drawing::image emblem_shared() noexcept;
      /// @brief Gets the emblems system image "emblem-shared" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-shared".
      static xtd::drawing::image emblem_shared(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-symbolic-link".
      /// @return The xtd::drawing::image "emblem-symbolic-link".
      static xtd::drawing::image emblem_symbolic_link() noexcept;
      /// @brief Gets the emblems system image "emblem-symbolic-link" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-symbolic-link".
      static xtd::drawing::image emblem_symbolic_link(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-synchronizing".
      /// @return The xtd::drawing::image "emblem-synchronizing".
      static xtd::drawing::image emblem_synchronizing() noexcept;
      /// @brief Gets the emblems system image "emblem-synchronizing" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-synchronizing".
      static xtd::drawing::image emblem_synchronizing(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-system".
      /// @return The xtd::drawing::image "emblem-system".
      static xtd::drawing::image emblem_system() noexcept;
      /// @brief Gets the emblems system image "emblem-system" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-system".
      static xtd::drawing::image emblem_system(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-unlocked".
      /// @return The xtd::drawing::image "emblem-unlocked".
      static xtd::drawing::image emblem_unlocked() noexcept;
      /// @brief Gets the emblems system image "emblem-unlocked" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-unlocked".
      static xtd::drawing::image emblem_unlocked(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the emblems system image "emblem-unreadable".
      /// @return The xtd::drawing::image "emblem-unreadable".
      static xtd::drawing::image emblem_unreadable() noexcept;
      /// @brief Gets the emblems system image "emblem-unreadable" with specified size.
      /// @param size The emblems system image size in pixels.
      /// @return The xtd::drawing::image "emblem-unreadable".
      static xtd::drawing::image emblem_unreadable(const xtd::drawing::size& size) noexcept;

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
