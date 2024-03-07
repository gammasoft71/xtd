/// @file
/// @brief Contains xtd::drawing::places_system_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::places_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ places_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::places_system_images
    /// @par Header
    /// @code #include <xtd/drawing/places_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ places_system_images final : private system_images_base {
    public:
      /// @name Static properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the places system image "folder".
      /// @return The xtd::drawing::image "folder".
      static xtd::drawing::image folder() noexcept;
      /// @brief Gets the places system image "folder" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder".
      static xtd::drawing::image folder(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-activities".
      /// @return The xtd::drawing::image "folder-activities".
      static xtd::drawing::image folder_activities() noexcept;
      /// @brief Gets the places system image "folder-activities" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-activities".
      static xtd::drawing::image folder_activities(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-applications".
      /// @return The xtd::drawing::image "folder-applications".
      static xtd::drawing::image folder_applications() noexcept;
      /// @brief Gets the places system image "folder-applications" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-applications".
      static xtd::drawing::image folder_applications(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-bookmark".
      /// @return The xtd::drawing::image "folder-bookmark".
      static xtd::drawing::image folder_bookmark() noexcept;
      /// @brief Gets the places system image "folder-bookmark" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-bookmark".
      static xtd::drawing::image folder_bookmark(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-cloud".
      /// @return The xtd::drawing::image "folder-cloud".
      static xtd::drawing::image folder_cloud() noexcept;
      /// @brief Gets the places system image "folder-cloud" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-cloud".
      static xtd::drawing::image folder_cloud(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-desktop".
      /// @return The xtd::drawing::image "folder-desktop".
      static xtd::drawing::image folder_desktop() noexcept;
      /// @brief Gets the places system image "folder-desktop" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-desktop".
      static xtd::drawing::image folder_desktop(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-development".
      /// @return The xtd::drawing::image "folder-development".
      static xtd::drawing::image folder_development() noexcept;
      /// @brief Gets the places system image "folder-development" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-development".
      static xtd::drawing::image folder_development(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-documents".
      /// @return The xtd::drawing::image "folder-documents".
      static xtd::drawing::image folder_documents() noexcept;
      /// @brief Gets the places system image "folder-documents" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-documents".
      static xtd::drawing::image folder_documents(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-download".
      /// @return The xtd::drawing::image "folder-download".
      static xtd::drawing::image folder_download() noexcept;
      /// @brief Gets the places system image "folder-download" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-download".
      static xtd::drawing::image folder_download(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-favorites".
      /// @return The xtd::drawing::image "folder-favorites".
      static xtd::drawing::image folder_favorites() noexcept;
      /// @brief Gets the places system image "folder-favorites" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-favorites".
      static xtd::drawing::image folder_favorites(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-games".
      /// @return The xtd::drawing::image "folder-games".
      static xtd::drawing::image folder_games() noexcept;
      /// @brief Gets the places system image "folder-games" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-games".
      static xtd::drawing::image folder_games(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-github".
      /// @return The xtd::drawing::image "folder-github".
      static xtd::drawing::image folder_github() noexcept;
      /// @brief Gets the places system image "folder-github" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-github".
      static xtd::drawing::image folder_github(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-home".
      /// @return The xtd::drawing::image "folder-home".
      static xtd::drawing::image folder_home() noexcept;
      /// @brief Gets the places system image "folder-home" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-home".
      static xtd::drawing::image folder_home(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-html".
      /// @return The xtd::drawing::image "folder-html".
      static xtd::drawing::image folder_html() noexcept;
      /// @brief Gets the places system image "folder-html" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-html".
      static xtd::drawing::image folder_html(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-images".
      /// @return The xtd::drawing::image "folder-images".
      static xtd::drawing::image folder_images() noexcept;
      /// @brief Gets the places system image "folder-images" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-images".
      static xtd::drawing::image folder_images(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-important".
      /// @return The xtd::drawing::image "folder-important".
      static xtd::drawing::image folder_important() noexcept;
      /// @brief Gets the places system image "folder-important" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-important".
      static xtd::drawing::image folder_important(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-locked".
      /// @return The xtd::drawing::image "folder-locked".
      static xtd::drawing::image folder_locked() noexcept;
      /// @brief Gets the places system image "folder-locked" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-locked".
      static xtd::drawing::image folder_locked(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-music".
      /// @return The xtd::drawing::image "folder-music".
      static xtd::drawing::image folder_music() noexcept;
      /// @brief Gets the places system image "folder-music" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-music".
      static xtd::drawing::image folder_music(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-network".
      /// @return The xtd::drawing::image "folder-network".
      static xtd::drawing::image folder_network() noexcept;
      /// @brief Gets the places system image "folder-network" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-network".
      static xtd::drawing::image folder_network(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-print".
      /// @return The xtd::drawing::image "folder-print".
      static xtd::drawing::image folder_print() noexcept;
      /// @brief Gets the places system image "folder-print" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-print".
      static xtd::drawing::image folder_print(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-public".
      /// @return The xtd::drawing::image "folder-public".
      static xtd::drawing::image folder_public() noexcept;
      /// @brief Gets the places system image "folder-public" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-public".
      static xtd::drawing::image folder_public(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-remote".
      /// @return The xtd::drawing::image "folder-remote".
      static xtd::drawing::image folder_remote() noexcept;
      /// @brief Gets the places system image "folder-remote" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-remote".
      static xtd::drawing::image folder_remote(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-system".
      /// @return The xtd::drawing::image "folder-system".
      static xtd::drawing::image folder_system() noexcept;
      /// @brief Gets the places system image "folder-system" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-system".
      static xtd::drawing::image folder_system(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-tar".
      /// @return The xtd::drawing::image "folder-tar".
      static xtd::drawing::image folder_tar() noexcept;
      /// @brief Gets the places system image "folder-tar" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-tar".
      static xtd::drawing::image folder_tar(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-temp".
      /// @return The xtd::drawing::image "folder-temp".
      static xtd::drawing::image folder_temp() noexcept;
      /// @brief Gets the places system image "folder-temp" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-temp".
      static xtd::drawing::image folder_temp(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-templates".
      /// @return The xtd::drawing::image "folder-templates".
      static xtd::drawing::image folder_templates() noexcept;
      /// @brief Gets the places system image "folder-templates" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-templates".
      static xtd::drawing::image folder_templates(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-text".
      /// @return The xtd::drawing::image "folder-text".
      static xtd::drawing::image folder_text() noexcept;
      /// @brief Gets the places system image "folder-text" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-text".
      static xtd::drawing::image folder_text(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "folder-videos".
      /// @return The xtd::drawing::image "folder-videos".
      static xtd::drawing::image folder_videos() noexcept;
      /// @brief Gets the places system image "folder-videos" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-videos".
      static xtd::drawing::image folder_videos(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "network-server".
      /// @return The xtd::drawing::image "network-server".
      static xtd::drawing::image network_server() noexcept;
      /// @brief Gets the places system image "network-server" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "network-server".
      static xtd::drawing::image network_server(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "network-workgroup".
      /// @return The xtd::drawing::image "network-workgroup".
      static xtd::drawing::image network_workgroup() noexcept;
      /// @brief Gets the places system image "network-workgroup" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "network-workgroup".
      static xtd::drawing::image network_workgroup(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "start-here".
      /// @return The xtd::drawing::image "start-here".
      static xtd::drawing::image start_here() noexcept;
      /// @brief Gets the places system image "start-here" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "start-here".
      static xtd::drawing::image start_here(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "user-bookmarks".
      /// @return The xtd::drawing::image "user-bookmarks".
      static xtd::drawing::image user_bookmarks() noexcept;
      /// @brief Gets the places system image "user-bookmarks" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-bookmarks".
      static xtd::drawing::image user_bookmarks(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "user-desktop".
      /// @return The xtd::drawing::image "user-desktop".
      static xtd::drawing::image user_desktop() noexcept;
      /// @brief Gets the places system image "user-desktop" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-desktop".
      static xtd::drawing::image user_desktop(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "user-home".
      /// @return The xtd::drawing::image "user-home".
      static xtd::drawing::image user_home() noexcept;
      /// @brief Gets the places system image "user-home" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-home".
      static xtd::drawing::image user_home(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the places system image "user-trash".
      /// @return The xtd::drawing::image "user-trash".
      static xtd::drawing::image user_trash() noexcept;
      /// @brief Gets the places system image "user-trash" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-trash".
      static xtd::drawing::image user_trash(const xtd::drawing::size& size) noexcept;

      /// @}

      /// @name Static methods

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
