/// @file
/// @brief Contains xtd::drawing::places_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::places_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ places_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::places_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/places_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ places_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the places system image "folder".
      /// @return The xtd::drawing::image "folder".
      [[nodiscard]] static auto folder() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder".
      [[nodiscard]] static auto folder(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-activities".
      /// @return The xtd::drawing::image "folder-activities".
      [[nodiscard]] static auto folder_activities() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-activities" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-activities".
      [[nodiscard]] static auto folder_activities(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-applications".
      /// @return The xtd::drawing::image "folder-applications".
      [[nodiscard]] static auto folder_applications() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-applications" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-applications".
      [[nodiscard]] static auto folder_applications(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-bookmark".
      /// @return The xtd::drawing::image "folder-bookmark".
      [[nodiscard]] static auto folder_bookmark() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-bookmark" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-bookmark".
      [[nodiscard]] static auto folder_bookmark(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-cloud".
      /// @return The xtd::drawing::image "folder-cloud".
      [[nodiscard]] static auto folder_cloud() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-cloud" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-cloud".
      [[nodiscard]] static auto folder_cloud(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-desktop".
      /// @return The xtd::drawing::image "folder-desktop".
      [[nodiscard]] static auto folder_desktop() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-desktop" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-desktop".
      [[nodiscard]] static auto folder_desktop(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-development".
      /// @return The xtd::drawing::image "folder-development".
      [[nodiscard]] static auto folder_development() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-development" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-development".
      [[nodiscard]] static auto folder_development(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-documents".
      /// @return The xtd::drawing::image "folder-documents".
      [[nodiscard]] static auto folder_documents() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-documents" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-documents".
      [[nodiscard]] static auto folder_documents(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-download".
      /// @return The xtd::drawing::image "folder-download".
      [[nodiscard]] static auto folder_download() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-download" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-download".
      [[nodiscard]] static auto folder_download(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-favorites".
      /// @return The xtd::drawing::image "folder-favorites".
      [[nodiscard]] static auto folder_favorites() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-favorites" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-favorites".
      [[nodiscard]] static auto folder_favorites(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-games".
      /// @return The xtd::drawing::image "folder-games".
      [[nodiscard]] static auto folder_games() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-games" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-games".
      [[nodiscard]] static auto folder_games(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-github".
      /// @return The xtd::drawing::image "folder-github".
      [[nodiscard]] static auto folder_github() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-github" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-github".
      [[nodiscard]] static auto folder_github(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-home".
      /// @return The xtd::drawing::image "folder-home".
      [[nodiscard]] static auto folder_home() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-home" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-home".
      [[nodiscard]] static auto folder_home(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-html".
      /// @return The xtd::drawing::image "folder-html".
      [[nodiscard]] static auto folder_html() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-html" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-html".
      [[nodiscard]] static auto folder_html(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-images".
      /// @return The xtd::drawing::image "folder-images".
      [[nodiscard]] static auto folder_images() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-images" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-images".
      [[nodiscard]] static auto folder_images(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-important".
      /// @return The xtd::drawing::image "folder-important".
      [[nodiscard]] static auto folder_important() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-important" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-important".
      [[nodiscard]] static auto folder_important(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-locked".
      /// @return The xtd::drawing::image "folder-locked".
      [[nodiscard]] static auto folder_locked() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-locked" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-locked".
      [[nodiscard]] static auto folder_locked(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-music".
      /// @return The xtd::drawing::image "folder-music".
      [[nodiscard]] static auto folder_music() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-music" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-music".
      [[nodiscard]] static auto folder_music(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-network".
      /// @return The xtd::drawing::image "folder-network".
      [[nodiscard]] static auto folder_network() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-network" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-network".
      [[nodiscard]] static auto folder_network(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-print".
      /// @return The xtd::drawing::image "folder-print".
      [[nodiscard]] static auto folder_print() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-print" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-print".
      [[nodiscard]] static auto folder_print(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-public".
      /// @return The xtd::drawing::image "folder-public".
      [[nodiscard]] static auto folder_public() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-public" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-public".
      [[nodiscard]] static auto folder_public(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-remote".
      /// @return The xtd::drawing::image "folder-remote".
      [[nodiscard]] static auto folder_remote() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-remote" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-remote".
      [[nodiscard]] static auto folder_remote(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-system".
      /// @return The xtd::drawing::image "folder-system".
      [[nodiscard]] static auto folder_system() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-system" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-system".
      [[nodiscard]] static auto folder_system(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-tar".
      /// @return The xtd::drawing::image "folder-tar".
      [[nodiscard]] static auto folder_tar() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-tar" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-tar".
      [[nodiscard]] static auto folder_tar(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-temp".
      /// @return The xtd::drawing::image "folder-temp".
      [[nodiscard]] static auto folder_temp() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-temp" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-temp".
      [[nodiscard]] static auto folder_temp(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-templates".
      /// @return The xtd::drawing::image "folder-templates".
      [[nodiscard]] static auto folder_templates() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-templates" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-templates".
      [[nodiscard]] static auto folder_templates(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-text".
      /// @return The xtd::drawing::image "folder-text".
      [[nodiscard]] static auto folder_text() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-text" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-text".
      [[nodiscard]] static auto folder_text(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "folder-videos".
      /// @return The xtd::drawing::image "folder-videos".
      [[nodiscard]] static auto folder_videos() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "folder-videos" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "folder-videos".
      [[nodiscard]] static auto folder_videos(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "network-server".
      /// @return The xtd::drawing::image "network-server".
      [[nodiscard]] static auto network_server() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "network-server" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "network-server".
      [[nodiscard]] static auto network_server(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "network-workgroup".
      /// @return The xtd::drawing::image "network-workgroup".
      [[nodiscard]] static auto network_workgroup() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "network-workgroup" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "network-workgroup".
      [[nodiscard]] static auto network_workgroup(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "start-here".
      /// @return The xtd::drawing::image "start-here".
      [[nodiscard]] static auto start_here() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "start-here" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "start-here".
      [[nodiscard]] static auto start_here(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "user-bookmarks".
      /// @return The xtd::drawing::image "user-bookmarks".
      [[nodiscard]] static auto user_bookmarks() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "user-bookmarks" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-bookmarks".
      [[nodiscard]] static auto user_bookmarks(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "user-desktop".
      /// @return The xtd::drawing::image "user-desktop".
      [[nodiscard]] static auto user_desktop() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "user-desktop" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-desktop".
      [[nodiscard]] static auto user_desktop(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "user-home".
      /// @return The xtd::drawing::image "user-home".
      [[nodiscard]] static auto user_home() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "user-home" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-home".
      [[nodiscard]] static auto user_home(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the places system image "user-trash".
      /// @return The xtd::drawing::image "user-trash".
      [[nodiscard]] static auto user_trash() noexcept -> xtd::drawing::image;
      /// @brief Gets the places system image "user-trash" with specified size.
      /// @param size The places system image size in pixels.
      /// @return The xtd::drawing::image "user-trash".
      [[nodiscard]] static auto user_trash(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
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
