/// @file
/// @brief Contains xtd::drawing::applications_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::applications_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ applications_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::applications_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/applications_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ applications_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the applications system image "accessories-calculator".
      /// @return The xtd::drawing::image "accessories-calculator".
      [[nodiscard]] static auto accessories_calculator() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "accessories-calculator" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-calculator".
      [[nodiscard]] static auto accessories_calculator(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "accessories-character-map".
      /// @return The xtd::drawing::image "accessories-character-map".
      [[nodiscard]] static auto accessories_character_map() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "accessories-character-map" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-character-map".
      [[nodiscard]] static auto accessories_character_map(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "accessories-dictionary".
      /// @return The xtd::drawing::image "accessories-dictionary".
      [[nodiscard]] static auto accessories_dictionary() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "accessories-dictionary" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-dictionary".
      [[nodiscard]] static auto accessories_dictionary(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "accessories-text-editor".
      /// @return The xtd::drawing::image "accessories-text-editor".
      [[nodiscard]] static auto accessories_text_editor() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "accessories-text-editor" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-text-editor".
      [[nodiscard]] static auto accessories_text_editor(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "help-browser".
      /// @return The xtd::drawing::image "help-browser".
      [[nodiscard]] static auto help_browser() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "help-browser" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "help-browser".
      [[nodiscard]] static auto help_browser(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "help".
      /// @return The xtd::drawing::image "help".
      [[nodiscard]] static auto help() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "help" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "help".
      [[nodiscard]] static auto help(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "multimedia-volume-control".
      /// @return The xtd::drawing::image "multimedia-volume-control".
      [[nodiscard]] static auto multimedia_volume_control() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "multimedia-volume-control" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "multimedia-volume-control".
      [[nodiscard]] static auto multimedia_volume_control(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "preferences-desktop-accessibility".
      /// @return The xtd::drawing::image "preferences-desktop-accessibility".
      [[nodiscard]] static auto preferences_desktop_accessibility() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "preferences-desktop-accessibility" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-accessibility".
      [[nodiscard]] static auto preferences_desktop_accessibility(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "preferences-desktop-font".
      /// @return The xtd::drawing::image "preferences-desktop-font".
      [[nodiscard]] static auto preferences_desktop_font() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "preferences-desktop-font" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-font".
      [[nodiscard]] static auto preferences_desktop_font(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "preferences-desktop-keyboard".
      /// @return The xtd::drawing::image "preferences-desktop-keyboard".
      [[nodiscard]] static auto preferences_desktop_keyboard() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "preferences-desktop-keyboard" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-keyboard".
      [[nodiscard]] static auto preferences_desktop_keyboard(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "preferences-desktop-locale".
      /// @return The xtd::drawing::image "preferences-desktop-locale".
      [[nodiscard]] static auto preferences_desktop_locale() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "preferences-desktop-locale" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-locale".
      [[nodiscard]] static auto preferences_desktop_locale(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "preferences-desktop-screensaver".
      /// @return The xtd::drawing::image "preferences-desktop-screensaver".
      [[nodiscard]] static auto preferences_desktop_screensaver() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "preferences-desktop-screensaver" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-screensaver".
      [[nodiscard]] static auto preferences_desktop_screensaver(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "preferences-desktop-theme".
      /// @return The xtd::drawing::image "preferences-desktop-theme".
      [[nodiscard]] static auto preferences_desktop_theme() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "preferences-desktop-theme" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-theme".
      [[nodiscard]] static auto preferences_desktop_theme(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "preferences-desktop-wallpaper".
      /// @return The xtd::drawing::image "preferences-desktop-wallpaper".
      [[nodiscard]] static auto preferences_desktop_wallpaper() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "preferences-desktop-wallpaper" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-wallpaper".
      [[nodiscard]] static auto preferences_desktop_wallpaper(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "system-file-manager".
      /// @return The xtd::drawing::image "system-file-manager".
      [[nodiscard]] static auto system_file_manager() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "system-file-manager" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "system-file-manager".
      [[nodiscard]] static auto system_file_manager(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "system-software-install".
      /// @return The xtd::drawing::image "system-software-install".
      [[nodiscard]] static auto system_software_install() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "system-software-install" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "system-software-install".
      [[nodiscard]] static auto system_software_install(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "system-software-update".
      /// @return The xtd::drawing::image "system-software-update".
      [[nodiscard]] static auto system_software_update() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "system-software-update" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "system-software-update".
      [[nodiscard]] static auto system_software_update(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "utilities-system-monitor".
      /// @return The xtd::drawing::image "utilities-system-monitor".
      [[nodiscard]] static auto utilities_system_monitor() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "utilities-system-monitor" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "utilities-system-monitor".
      [[nodiscard]] static auto utilities_system_monitor(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the applications system image "utilities-terminal".
      /// @return The xtd::drawing::image "utilities-terminal".
      [[nodiscard]] static auto utilities_terminal() noexcept -> xtd::drawing::image;
      /// @brief Gets the applications system image "utilities-terminal" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "utilities-terminal".
      [[nodiscard]] static auto utilities_terminal(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
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
