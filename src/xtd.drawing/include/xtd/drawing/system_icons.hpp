/// @file
/// @brief Contains xtd::drawing::system_icons factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "icon.hpp"
#include "size.hpp"
#include "system_images.hpp"
#include <xtd/static>
#include <map>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_icons class is an xtd::drawing::icon object for Windows system-wide icons. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ system_icons final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_icons
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the system_fonts class returns a Font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
    class system_icons final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets an xtd::drawing::icon object that contains the default application icon (WIN32: IDI_APPLICATION).
      /// @return An xtd::drawing::icon object that contains the default application icon.
      [[nodiscard]] static auto application() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the default application icon (WIN32: IDI_APPLICATION) with specified size.
      /// @param size An xtd::drawing::size structure that define the default size of icon.
      /// @return An xtd::drawing::icon object that contains the default application the icon.
      [[nodiscard]] static auto application(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system asterisk icon (WIN32: IDI_ASTERISK).
      /// @return An xtd::drawing::icon object that contains the system asterisk icon.
      [[nodiscard]] static auto asterisk() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the system asterisk icon (WIN32: IDI_ASTERISK) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system asterisk icon.
      [[nodiscard]] static auto asterisk(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system error icon (WIN32: IDI_ERROR).
      /// @return An xtd::drawing::icon object that contains the system error icon.
      [[nodiscard]] static auto error() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the system error icon (WIN32: IDI_ERROR) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system error icon.
      [[nodiscard]] static auto error(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system exclamation icon (WIN32: IDI_EXCLAMATION).
      /// @return An xtd::drawing::icon object that contains the system exclamation icon.
      [[nodiscard]] static auto exclamation() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the system exclamation icon (WIN32: IDI_EXCLAMATION) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system exclamation icon.
      [[nodiscard]] static auto exclamation(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system hand icon (WIN32: IDI_HAND).
      /// @return An xtd::drawing::icon object that contains the system hand icon.
      [[nodiscard]] static auto hand() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the system hand icon (WIN32: IDI_HAND) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system hand icon.
      [[nodiscard]] static auto hand(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system information icon (WIN32: IDI_INFORMATION).
      /// @return An xtd::drawing::icon object that contains the system information icon.
      [[nodiscard]] static auto information() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the system information icon (WIN32: IDI_INFORMATION) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system information icon.
      [[nodiscard]] static auto information(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system question icon (WIN32: IDI_QUESTION).
      /// @return An xtd::drawing::icon object that contains the system question icon.
      [[nodiscard]] static auto question() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the system question icon (WIN32: IDI_QUESTION) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system question icon.
      [[nodiscard]] static auto question(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the shield icon.
      /// @return An xtd::drawing::icon object that contains the shield icon.
      [[nodiscard]] static auto shield() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the shield icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the shield icon.
      [[nodiscard]] static auto shield(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system warning icon (WIN32: IDI_WARNING).
      /// @return An xtd::drawing::icon object that contains the system warning icon.
      [[nodiscard]] static auto warning() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the system warning icon (WIN32: IDI_WARNING) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system warning icon.
      [[nodiscard]] static auto warning(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO).
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      [[nodiscard]] static auto win_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      [[nodiscard]] static auto win_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets the default size of the icon.
      /// @return An xtd::drawing::size structure that define the default size of the icon in pixels.
      /// @remarks The default size is 32 x 32 pixels.
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets an xtd::drawing::icon object that contains the KDE logo icon.
      /// @return An xtd::drawing::icon object that contains the KDE logo icon.
      [[nodiscard]] static auto kde_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the KDE logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the KDE logo icon.
      [[nodiscard]] static auto kde_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the macOS logo icon.
      /// @return An xtd::drawing::icon object that contains the macOS logo icon.
      [[nodiscard]] static auto macos_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the macOS logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the macOS logo icon.
      [[nodiscard]] static auto macos_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the GNOME logo icon.
      /// @return An xtd::drawing::icon object that contains the GNOME logo icon.
      [[nodiscard]] static auto gnome_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the GNOME logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the GNOME logo icon.
      [[nodiscard]] static auto gnome_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Symbolic logo icon.
      /// @return An xtd::drawing::icon object that contains the Symbolic logo icon.
      [[nodiscard]] static auto symbolic_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the Symbolic logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Symbolic logo icon.
      [[nodiscard]] static auto symbolic_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO).
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      [[nodiscard]] static auto windows_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      [[nodiscard]] static auto windows_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Gammasoft logo icon.
      /// @return An xtd::drawing::icon object that contains the Gammasoft logo icon.
      [[nodiscard]] static auto gammasoft() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the Gammasoft logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Gammasoft logo icon.
      [[nodiscard]] static auto gammasoft(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the xtd logo icon.
      /// @return An xtd::drawing::icon object that contains the xtd logo icon.
      [[nodiscard]] static auto xtd_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the xtd logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the xtd logo icon.
      [[nodiscard]] static auto xtd_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      
      /// @brief Gets an xtd::drawing::icon object that contains the xtd.forms logo icon.
      /// @return An xtd::drawing::icon object that contains the xtd.forms logo icon.
      [[nodiscard]] static auto xtd_forms_logo() noexcept -> xtd::drawing::icon;
      /// @brief Gets an xtd::drawing::icon object that contains the xtd.forms logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the xtd.forms logo icon.
      [[nodiscard]] static auto xtd_forms_logo(const xtd::drawing::size& size) noexcept -> xtd::drawing::icon;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets system icon from specified name.
      /// @param name The system icon name.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      /// @remarks The theme is the default system theme.
      /// @remarks The size is the default size (32 x 32).
      [[nodiscard]] static auto from_name(const xtd::string& name) -> xtd::drawing::icon;
      /// @brief Gets system icon from specified name and size.
      /// @param name The system icon name.
      /// @param size The system icon size in pixels.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      /// @remarks The theme is the default system theme.
      [[nodiscard]] static auto from_name(const xtd::string& name, const xtd::drawing::size& size) -> xtd::drawing::icon;
      /// @brief Gets system icon from specified them and name.
      /// @param theme The system icon theme.
      /// @param name The system icon name.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      /// @remarks The size is the default size in pixels (32 x 32).
      [[nodiscard]] static auto from_name(const xtd::string& theme, const xtd::string& name) -> xtd::drawing::icon;
      /// @brief Gets system icon from specified theme, name and size.
      /// @param theme The system icon theme.
      /// @param name The system icon name.
      /// @param size The system icon size in pixels.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      [[nodiscard]] static auto from_name(const xtd::string& theme, const xtd::string& name, const xtd::drawing::size& size) -> xtd::drawing::icon;
      /// @}
    };
  }
}

