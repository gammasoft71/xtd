/// @file
/// @brief Contains xtd::drawing::categories_system_images factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::categories_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ categories_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::categories_system_images
    /// @par Header
    /// @code #include <xtd/drawing/categories_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ categories_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the categories system image "applications-accessories".
      /// @return The xtd::drawing::image "applications-accessories".
      static xtd::drawing::image applications_accessories() noexcept;
      /// @brief Gets the categories system image "applications-accessories" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-accessories".
      static xtd::drawing::image applications_accessories(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-development".
      /// @return The xtd::drawing::image "applications-development".
      static xtd::drawing::image applications_development() noexcept;
      /// @brief Gets the categories system image "applications-development" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-development".
      static xtd::drawing::image applications_development(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-engineering".
      /// @return The xtd::drawing::image "applications-engineering".
      static xtd::drawing::image applications_engineering() noexcept;
      /// @brief Gets the categories system image "applications-engineering" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-engineering".
      static xtd::drawing::image applications_engineering(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-games".
      /// @return The xtd::drawing::image "applications-games".
      static xtd::drawing::image applications_games() noexcept;
      /// @brief Gets the categories system image "applications-games" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-games".
      static xtd::drawing::image applications_games(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-graphics".
      /// @return The xtd::drawing::image "applications-graphics".
      static xtd::drawing::image applications_graphics() noexcept;
      /// @brief Gets the categories system image "applications-graphics" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-graphics".
      static xtd::drawing::image applications_graphics(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-internet".
      /// @return The xtd::drawing::image "applications-internet".
      static xtd::drawing::image applications_internet() noexcept;
      /// @brief Gets the categories system image "applications-internet" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-internet".
      static xtd::drawing::image applications_internet(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-multimedia".
      /// @return The xtd::drawing::image "applications-multimedia".
      static xtd::drawing::image applications_multimedia() noexcept;
      /// @brief Gets the categories system image "applications-multimedia" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-multimedia".
      static xtd::drawing::image applications_multimedia(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-office".
      /// @return The xtd::drawing::image "applications-office".
      static xtd::drawing::image applications_office() noexcept;
      /// @brief Gets the categories system image "applications-office" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-office".
      static xtd::drawing::image applications_office(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-other".
      /// @return The xtd::drawing::image "applications-other".
      static xtd::drawing::image applications_other() noexcept;
      /// @brief Gets the categories system image "applications-other" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-other".
      static xtd::drawing::image applications_other(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-science".
      /// @return The xtd::drawing::image "applications-science".
      static xtd::drawing::image applications_science() noexcept;
      /// @brief Gets the categories system image "applications-science" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-science".
      static xtd::drawing::image applications_science(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-system".
      /// @return The xtd::drawing::image "applications-system".
      static xtd::drawing::image applications_system() noexcept;
      /// @brief Gets the categories system image "applications-system" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-system".
      static xtd::drawing::image applications_system(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "applications-utilities".
      /// @return The xtd::drawing::image "applications-utilities".
      static xtd::drawing::image applications_utilities() noexcept;
      /// @brief Gets the categories system image "applications-utilities" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "applications-utilities".
      static xtd::drawing::image applications_utilities(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "preferences-desktop".
      /// @return The xtd::drawing::image "preferences-desktop".
      static xtd::drawing::image preferences_desktop() noexcept;
      /// @brief Gets the categories system image "preferences-desktop" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop".
      static xtd::drawing::image preferences_desktop(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "preferences-desktop-peripherals".
      /// @return The xtd::drawing::image "preferences-desktop-peripherals".
      static xtd::drawing::image preferences_desktop_peripherals() noexcept;
      /// @brief Gets the categories system image "preferences-desktop-peripherals" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-peripherals".
      static xtd::drawing::image preferences_desktop_peripherals(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "preferences-desktop-personal".
      /// @return The xtd::drawing::image "preferences-desktop-personal".
      static xtd::drawing::image preferences_desktop_personal() noexcept;
      /// @brief Gets the categories system image "preferences-desktop-personal" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-desktop-personal".
      static xtd::drawing::image preferences_desktop_personal(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "preferences-other".
      /// @return The xtd::drawing::image "preferences-other".
      static xtd::drawing::image preferences_other() noexcept;
      /// @brief Gets the categories system image "preferences-other" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-other".
      static xtd::drawing::image preferences_other(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "preferences-system".
      /// @return The xtd::drawing::image "preferences-system".
      static xtd::drawing::image preferences_system() noexcept;
      /// @brief Gets the categories system image "preferences-system" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-system".
      static xtd::drawing::image preferences_system(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "preferences-system-network".
      /// @return The xtd::drawing::image "preferences-system-network".
      static xtd::drawing::image preferences_system_network() noexcept;
      /// @brief Gets the categories system image "preferences-system-network" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "preferences-system-network".
      static xtd::drawing::image preferences_system_network(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the categories system image "system-help".
      /// @return The xtd::drawing::image "system-help".
      static xtd::drawing::image system_help() noexcept;
      /// @brief Gets the categories system image "system-help" with specified size.
      /// @param size The categories system image size in pixels.
      /// @return The xtd::drawing::image "system-help".
      static xtd::drawing::image system_help(const xtd::drawing::size& size) noexcept;

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
