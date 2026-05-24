/// @file
/// @brief Contains xtd::drawing::system_fonts factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "font.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the fonts used to display text in Windows display elements.
    /// ```cpp
    /// class drawing_export_ system_fonts final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_fonts
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing fonts
    /// @remarks Each property of the system_fonts class returns a xtd::drawing::font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
    class drawing_export_ system_fonts final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a xtd::drawing::font that is used to display text in the title bars of windows.
      /// @return A xtd::drawing::font that is used to display text in the title bars of windows.
      [[nodiscard]] static auto caption_font() -> xtd::drawing::font;
      
      /// @brief Gets the default font that applications can use for dialog boxes and forms.
      /// @return The default xtd::drawing::font of the system. The value returned will vary depending on the user's operating system and the local culture setting of their system.
      /// @remarks The following table describes the value returned by the xtd::drawing::system_fonts::default_font property depending on the operating system and local culture.
      /// | System and/or culture           | Font                                                               |
      /// | ------------------------------- | ------------------------------------------------------------------ |
      /// | Windows NT 4x, Japanese version | MS UI Gothic, 9 point                                              |
      /// | Arabic Windows                  | Tahoma, 8 point                                                    |
      /// | Other operating system/culture  | MS Shell Dlg logical font, typically Microsoft Sans Serif, 8 point |
      /// @remarks MS Shell Dlg maps to a font set in the system registry.
      /// @remarks If the above fonts are not installed, the default font is Tahoma, 8 point. If Tahoma, 8 point, is not installed, xtd::drawing::system_fonts::default_font returns the value of the GenericSansSerif property.
      /// @remarks The xtd::drawing::font returned by xtd::drawing::system_fonts::default_font does not change when the user is in High Contrast mode. For a font that changes when the user is in High Contrast mode use another system font such as xtd::drawing::system_fonts::icon_title_font.
      [[nodiscard]] static auto default_font() -> xtd::drawing::font;
      
      /// @brief Gets a xtd::drawing::font that applications can use for dialog boxes and forms.
      /// @return A xtd::drawing::font that can be used for dialog boxes and forms, depending on the operating system and local culture setting of the system.
      /// @remarks If the operating system is Windows 2000 or Windows XP, the xtd::drawing::system_fonts::dialog_font property returns Tahoma, 8 point. Otherwise, xtd::drawing::system_fonts::dialog_font returns the value of the xtd::drawing::system_fonts::default_font property. The xtd::drawing::font returned by xtd::drawing::system_fonts::dialog_font does not change when the user is in High Contrast mode. For a font that changes when the user is in High Contrast mode use another system font such as xtd::drawing::system_fonts::icon_title_font.
      [[nodiscard]] static auto dialog_font() -> xtd::drawing::font;
      
      /// @brief Gets a xtd::drawing::font that is used for icon titles.
      /// @return A xtd::drawing::font that is used for icon titles.
      [[nodiscard]] static auto icon_title_font() -> xtd::drawing::font;
      
      /// @brief Gets a xtd::drawing::font that is used for menus.
      /// @return A xtd::drawing::font that is used for menus.
      [[nodiscard]] static auto menu_font() -> xtd::drawing::font;
      
      /// @brief Gets a xtd::drawing::font that is used for message boxes.
      /// @return A xtd::drawing::font that is used for message boxes.
      [[nodiscard]] static auto message_box_font() -> xtd::drawing::font;
      
      /// @brief Gets a xtd::drawing::font that is used to display text in the title bars of small windows, such as tool windows.
      /// @return A xtd::drawing::font that is used to display text in the title bars of small windows, such as tool windows.
      [[nodiscard]] static auto small_caption_font() -> xtd::drawing::font;
      
      /// @brief Gets a xtd::drawing::font that is used to display text in the status bar.
      /// @return A xtd::drawing::font that is used to display text in the status bar.
      [[nodiscard]] static auto status_font() -> xtd::drawing::font;
      
      /// @brief Gets a xtd::drawing::font that is used to display text in the tool bar.
      /// @return A xtd::drawing::font that is used to display text in the tool bar.
      [[nodiscard]] static auto tool_font() -> xtd::drawing::font;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of system fonts.
      [[nodiscard]] static auto get_fonts() -> const xtd::array<xtd::drawing::font>&;
      
      /// @brief Gets an array of system font names.
      [[nodiscard]] static auto get_font_names() -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
