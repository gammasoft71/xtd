/// @file
/// @brief Contains xtd::drawing::applications_system_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::applications_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ applications_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::applications_system_images
    /// @par Header
    /// @code #include <xtd/drawing/applications_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ applications_system_images final : private system_images_base {
    public:
      /// @name Static properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the applications system image "accessories-calculator".
      /// @return The xtd::drawing::image "accessories-calculator".
      static xtd::drawing::image accessories_calculator() noexcept;
      /// @brief Gets the applications system image "accessories-calculator" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-calculator".
      static xtd::drawing::image accessories_calculator(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "accessories-character-map".
      /// @return The xtd::drawing::image "accessories-character-map".
      static xtd::drawing::image accessories_character_map() noexcept;
      /// @brief Gets the applications system image "accessories-character-map" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-character-map".
      static xtd::drawing::image accessories_character_map(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "accessories-dictionary".
      /// @return The xtd::drawing::image "accessories-dictionary".
      static xtd::drawing::image accessories_dictionary() noexcept;
      /// @brief Gets the applications system image "accessories-dictionary" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-dictionary".
      static xtd::drawing::image accessories_dictionary(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "accessories-text-editor".
      /// @return The xtd::drawing::image "accessories-text-editor".
      static xtd::drawing::image accessories_text_editor() noexcept;
      /// @brief Gets the applications system image "accessories-text-editor" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "accessories-text-editor".
      static xtd::drawing::image accessories_text_editor(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "help-browser".
      /// @return The xtd::drawing::image "help-browser".
      static xtd::drawing::image help_browser() noexcept;
      /// @brief Gets the applications system image "help-browser" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "help-browser".
      static xtd::drawing::image help_browser(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "help".
      /// @return The xtd::drawing::image "help".
      static xtd::drawing::image help() noexcept;
      /// @brief Gets the applications system image "help" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "help".
      static xtd::drawing::image help(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "multimedia-volume-control".
      /// @return The xtd::drawing::image "multimedia-volume-control".
      static xtd::drawing::image multimedia_volume_control() noexcept;
      /// @brief Gets the applications system image "multimedia-volume-control" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "multimedia-volume-control".
      static xtd::drawing::image multimedia_volume_control(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "preferences-desktop-accessibility".
      /// @return The xtd::drawing::image "preferences-desktop-accessibility".
      static xtd::drawing::image preferences_desktop_accessibility() noexcept;
      /// @brief Gets the applications system image "preferences-desktop-accessibility" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-accessibility".
      static xtd::drawing::image preferences_desktop_accessibility(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "preferences-desktop-font".
      /// @return The xtd::drawing::image "preferences-desktop-font".
      static xtd::drawing::image preferences_desktop_font() noexcept;
      /// @brief Gets the applications system image "preferences-desktop-font" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-font".
      static xtd::drawing::image preferences_desktop_font(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "preferences-desktop-keyboard".
      /// @return The xtd::drawing::image "preferences-desktop-keyboard".
      static xtd::drawing::image preferences_desktop_keyboard() noexcept;
      /// @brief Gets the applications system image "preferences-desktop-keyboard" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-keyboard".
      static xtd::drawing::image preferences_desktop_keyboard(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "preferences-desktop-locale".
      /// @return The xtd::drawing::image "preferences-desktop-locale".
      static xtd::drawing::image preferences_desktop_locale() noexcept;
      /// @brief Gets the applications system image "preferences-desktop-locale" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-locale".
      static xtd::drawing::image preferences_desktop_locale(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "preferences-desktop-screensaver".
      /// @return The xtd::drawing::image "preferences-desktop-screensaver".
      static xtd::drawing::image preferences_desktop_screensaver() noexcept;
      /// @brief Gets the applications system image "preferences-desktop-screensaver" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-screensaver".
      static xtd::drawing::image preferences_desktop_screensaver(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "preferences-desktop-theme".
      /// @return The xtd::drawing::image "preferences-desktop-theme".
      static xtd::drawing::image preferences_desktop_theme() noexcept;
      /// @brief Gets the applications system image "preferences-desktop-theme" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-theme".
      static xtd::drawing::image preferences_desktop_theme(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "preferences-desktop-wallpaper".
      /// @return The xtd::drawing::image "preferences-desktop-wallpaper".
      static xtd::drawing::image preferences_desktop_wallpaper() noexcept;
      /// @brief Gets the applications system image "preferences-desktop-wallpaper" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-wallpaper".
      static xtd::drawing::image preferences_desktop_wallpaper(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "system-file-manager".
      /// @return The xtd::drawing::image "system-file-manager".
      static xtd::drawing::image system_file_manager() noexcept;
      /// @brief Gets the applications system image "system-file-manager" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "system-file-manager".
      static xtd::drawing::image system_file_manager(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "system-software-install".
      /// @return The xtd::drawing::image "system-software-install".
      static xtd::drawing::image system_software_install() noexcept;
      /// @brief Gets the applications system image "system-software-install" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "system-software-install".
      static xtd::drawing::image system_software_install(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "system-software-update".
      /// @return The xtd::drawing::image "system-software-update".
      static xtd::drawing::image system_software_update() noexcept;
      /// @brief Gets the applications system image "system-software-update" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "system-software-update".
      static xtd::drawing::image system_software_update(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "utilities-system-monitor".
      /// @return The xtd::drawing::image "utilities-system-monitor".
      static xtd::drawing::image utilities_system_monitor() noexcept;
      /// @brief Gets the applications system image "utilities-system-monitor" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "utilities-system-monitor".
      static xtd::drawing::image utilities_system_monitor(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the applications system image "utilities-terminal".
      /// @return The xtd::drawing::image "utilities-terminal".
      static xtd::drawing::image utilities_terminal() noexcept;
      /// @brief Gets the applications system image "utilities-terminal" with specified size.
      /// @param size The applications system image size in pixels.
      /// @return The xtd::drawing::image "utilities-terminal".
      static xtd::drawing::image utilities_terminal(const xtd::drawing::size& size) noexcept;

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
