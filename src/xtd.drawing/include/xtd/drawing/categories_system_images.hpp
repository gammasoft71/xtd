/// @file
/// @brief Contains xtd::drawing::categories_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::categories_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ categories_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::categories_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/categories_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ categories_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the categories system image "applications-accessories".
      /// @return The xtd::drawing::image "applications-accessories".
      [[nodiscard]] static auto applications_accessories() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-accessories" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-accessories".
      [[nodiscard]] static auto applications_accessories(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-development".
      /// @return The xtd::drawing::image "applications-development".
      [[nodiscard]] static auto applications_development() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-development" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-development".
      [[nodiscard]] static auto applications_development(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-engineering".
      /// @return The xtd::drawing::image "applications-engineering".
      [[nodiscard]] static auto applications_engineering() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-engineering" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-engineering".
      [[nodiscard]] static auto applications_engineering(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-games".
      /// @return The xtd::drawing::image "applications-games".
      [[nodiscard]] static auto applications_games() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-games" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-games".
      [[nodiscard]] static auto applications_games(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-graphics".
      /// @return The xtd::drawing::image "applications-graphics".
      [[nodiscard]] static auto applications_graphics() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-graphics" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-graphics".
      [[nodiscard]] static auto applications_graphics(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-internet".
      /// @return The xtd::drawing::image "applications-internet".
      [[nodiscard]] static auto applications_internet() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-internet" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-internet".
      [[nodiscard]] static auto applications_internet(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-multimedia".
      /// @return The xtd::drawing::image "applications-multimedia".
      [[nodiscard]] static auto applications_multimedia() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-multimedia" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-multimedia".
      [[nodiscard]] static auto applications_multimedia(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-office".
      /// @return The xtd::drawing::image "applications-office".
      [[nodiscard]] static auto applications_office() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-office" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-office".
      [[nodiscard]] static auto applications_office(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-other".
      /// @return The xtd::drawing::image "applications-other".
      [[nodiscard]] static auto applications_other() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-other" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-other".
      [[nodiscard]] static auto applications_other(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-science".
      /// @return The xtd::drawing::image "applications-science".
      [[nodiscard]] static auto applications_science() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-science" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-science".
      [[nodiscard]] static auto applications_science(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-system".
      /// @return The xtd::drawing::image "applications-system".
      [[nodiscard]] static auto applications_system() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-system" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-system".
      [[nodiscard]] static auto applications_system(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "applications-utilities".
      /// @return The xtd::drawing::image "applications-utilities".
      [[nodiscard]] static auto applications_utilities() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "applications-utilities" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-utilities".
      [[nodiscard]] static auto applications_utilities(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "preferences-desktop".
      /// @return The xtd::drawing::image "preferences-desktop".
      [[nodiscard]] static auto preferences_desktop() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "preferences-desktop" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop".
      [[nodiscard]] static auto preferences_desktop(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "preferences-desktop-peripherals".
      /// @return The xtd::drawing::image "preferences-desktop-peripherals".
      [[nodiscard]] static auto preferences_desktop_peripherals() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "preferences-desktop-peripherals" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-peripherals".
      [[nodiscard]] static auto preferences_desktop_peripherals(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "preferences-desktop-personal".
      /// @return The xtd::drawing::image "preferences-desktop-personal".
      [[nodiscard]] static auto preferences_desktop_personal() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "preferences-desktop-personal" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-personal".
      [[nodiscard]] static auto preferences_desktop_personal(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "preferences-other".
      /// @return The xtd::drawing::image "preferences-other".
      [[nodiscard]] static auto preferences_other() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "preferences-other" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-other".
      [[nodiscard]] static auto preferences_other(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "preferences-system".
      /// @return The xtd::drawing::image "preferences-system".
      [[nodiscard]] static auto preferences_system() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "preferences-system" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-system".
      [[nodiscard]] static auto preferences_system(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "preferences-system-network".
      /// @return The xtd::drawing::image "preferences-system-network".
      [[nodiscard]] static auto preferences_system_network() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "preferences-system-network" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-system-network".
      [[nodiscard]] static auto preferences_system_network(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the categories system image "system-help".
      /// @return The xtd::drawing::image "system-help".
      [[nodiscard]] static auto system_help() noexcept -> xtd::drawing::image;
      /// @brief Gets the categories system image "system-help" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "system-help".
      [[nodiscard]] static auto system_help(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
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
