/// @file
/// @brief Contains xtd::drawing::system_icons factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "icon.h"
#include "size.h"
#include "system_images.h"
#include <xtd/static>
#include <map>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_icons class is an xtd::drawing::icon object for Windows system-wide icons. This class cannot be inherited.
    /// @code
    /// class drawing_export_ system_icons final static_
    /// @endcode
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
      /// @name Static properties
      
      /// @{
      /// @brief Gets an xtd::drawing::icon object that contains the default application icon (WIN32: IDI_APPLICATION).
      /// @return An xtd::drawing::icon object that contains the default application icon.
      static xtd::drawing::icon application() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the default application icon (WIN32: IDI_APPLICATION) with specified size.
      /// @param size An xtd::drawing::size structure that define the default size of icon.
      /// @return An xtd::drawing::icon object that contains the default application the icon.
      static xtd::drawing::icon application(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system asterisk icon (WIN32: IDI_ASTERISK).
      /// @return An xtd::drawing::icon object that contains the system asterisk icon.
      static xtd::drawing::icon asterisk() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the system asterisk icon (WIN32: IDI_ASTERISK) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system asterisk icon.
      static xtd::drawing::icon asterisk(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system error icon (WIN32: IDI_ERROR).
      /// @return An xtd::drawing::icon object that contains the system error icon.
      static xtd::drawing::icon error() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the system error icon (WIN32: IDI_ERROR) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system error icon.
      static xtd::drawing::icon error(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system exclamation icon (WIN32: IDI_EXCLAMATION).
      /// @return An xtd::drawing::icon object that contains the system exclamation icon.
      static xtd::drawing::icon exclamation() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the system exclamation icon (WIN32: IDI_EXCLAMATION) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system exclamation icon.
      static xtd::drawing::icon exclamation(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system hand icon (WIN32: IDI_HAND).
      /// @return An xtd::drawing::icon object that contains the system hand icon.
      static xtd::drawing::icon hand() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the system hand icon (WIN32: IDI_HAND) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system hand icon.
      static xtd::drawing::icon hand(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system information icon (WIN32: IDI_INFORMATION).
      /// @return An xtd::drawing::icon object that contains the system information icon.
      static xtd::drawing::icon information() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the system information icon (WIN32: IDI_INFORMATION) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system information icon.
      static xtd::drawing::icon information(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system question icon (WIN32: IDI_QUESTION).
      /// @return An xtd::drawing::icon object that contains the system question icon.
      static xtd::drawing::icon question() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the system question icon (WIN32: IDI_QUESTION) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system question icon.
      static xtd::drawing::icon question(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the shield icon.
      /// @return An xtd::drawing::icon object that contains the shield icon.
      static xtd::drawing::icon shield() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the shield icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the shield icon.
      static xtd::drawing::icon shield(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the system warning icon (WIN32: IDI_WARNING).
      /// @return An xtd::drawing::icon object that contains the system warning icon.
      static xtd::drawing::icon warning() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the system warning icon (WIN32: IDI_WARNING) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the system warning icon.
      static xtd::drawing::icon warning(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO).
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      static xtd::drawing::icon win_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      static xtd::drawing::icon win_logo(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets the default size of the icon.
      /// @return An xtd::drawing::size structure that define the default size of the icon in pixels.
      /// @remarks The default size is 32 x 32 pixels.
      static xtd::drawing::size default_size() noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the KDE logo icon.
      /// @return An xtd::drawing::icon object that contains the KDE logo icon.
      static xtd::drawing::icon kde_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the KDE logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the KDE logo icon.
      static xtd::drawing::icon kde_logo(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the macOS logo icon.
      /// @return An xtd::drawing::icon object that contains the macOS logo icon.
      static xtd::drawing::icon macos_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the macOS logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the macOS logo icon.
      static xtd::drawing::icon macos_logo(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the GNOME logo icon.
      /// @return An xtd::drawing::icon object that contains the GNOME logo icon.
      static xtd::drawing::icon gnome_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the GNOME logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the GNOME logo icon.
      static xtd::drawing::icon gnome_logo(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Symbolic logo icon.
      /// @return An xtd::drawing::icon object that contains the Symbolic logo icon.
      static xtd::drawing::icon symbolic_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the Symbolic logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Symbolic logo icon.
      static xtd::drawing::icon symbolic_logo(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO).
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      static xtd::drawing::icon windows_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the Windows logo icon (WIN32: IDI_WINLOGO) with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Windows logo icon.
      static xtd::drawing::icon windows_logo(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the Gammasoft logo icon.
      /// @return An xtd::drawing::icon object that contains the Gammasoft logo icon.
      static xtd::drawing::icon gammasoft() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the Gammasoft logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the Gammasoft logo icon.
      static xtd::drawing::icon gammasoft(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the xtd logo icon.
      /// @return An xtd::drawing::icon object that contains the xtd logo icon.
      static xtd::drawing::icon xtd_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the xtd logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the xtd logo icon.
      static xtd::drawing::icon xtd_logo(const xtd::drawing::size& size) noexcept;
      
      /// @brief Gets an xtd::drawing::icon object that contains the xtd.forms logo icon.
      /// @return An xtd::drawing::icon object that contains the xtd.forms logo icon.
      static xtd::drawing::icon xtd_forms_logo() noexcept;
      /// @brief Gets an xtd::drawing::icon object that contains the xtd.forms logo icon with specified size.
      /// @param size An xtd::drawing::size structure that define the size of the icon in pixels.
      /// @return An xtd::drawing::icon object that contains the xtd.forms logo icon.
      static xtd::drawing::icon xtd_forms_logo(const xtd::drawing::size& size) noexcept;
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief Gets system icon from specified name.
      /// @param name The system icon name.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      /// @remarks The theme is the default system theme.
      /// @remarks The size is the default size (32 x 32).
      static xtd::drawing::icon from_name(const xtd::ustring& name);
      /// @brief Gets system icon from specified name and size.
      /// @param name The system icon name.
      /// @param size The system icon size in pixels.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      /// @remarks The theme is the default system theme.
      static xtd::drawing::icon from_name(const xtd::ustring& name, const xtd::drawing::size& size);
      /// @brief Gets system icon from specified them and name.
      /// @param theme The system icon theme.
      /// @param name The system icon name.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      /// @remarks The size is the default size in pixels (32 x 32).
      static xtd::drawing::icon from_name(const xtd::ustring& theme, const xtd::ustring& name);
      /// @brief Gets system icon from specified theme, name and size.
      /// @param theme The system icon theme.
      /// @param name The system icon name.
      /// @param size The system icon size in pixels.
      /// @return An xtd::drawing::icon object that contains the system icon from specified name.
      static xtd::drawing::icon from_name(const xtd::ustring& theme, const xtd::ustring& name, const xtd::drawing::size& size);
      /// @}
    };
  }
}

