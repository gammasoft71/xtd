/// @file
/// @brief Contains xtd::drawing::system_fonts factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "font.h"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the fonts used to display text in Windows display elements.
    /// @code
    /// class drawing_export_ system_fonts final static_
    /// @endcode
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
      /// @name Static properties
      
      /// @{
      /// @brief Gets a xtd::drawing::font that is used to display text in the title bars of windows.
      /// @return A xtd::drawing::font that is used to display text in the title bars of windows.
      static xtd::drawing::font caption_font();
      
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
      static xtd::drawing::font default_font();
      
      /// @brief Gets a xtd::drawing::font that applications can use for dialog boxes and forms.
      /// @return A xtd::drawing::font that can be used for dialog boxes and forms, depending on the operating system and local culture setting of the system.
      /// @remarks If the operating system is Windows 2000 or Windows XP, the xtd::drawing::system_fonts::dialog_font property returns Tahoma, 8 point. Otherwise, xtd::drawing::system_fonts::dialog_font returns the value of the xtd::drawing::system_fonts::default_font property. The xtd::drawing::font returned by xtd::drawing::system_fonts::dialog_font does not change when the user is in High Contrast mode. For a font that changes when the user is in High Contrast mode use another system font such as xtd::drawing::system_fonts::icon_title_font.
      static xtd::drawing::font dialog_font();
      
      /// @brief Gets a xtd::drawing::font that is used for icon titles.
      /// @return A xtd::drawing::font that is used for icon titles.
      static xtd::drawing::font icon_title_font();
      
      /// @brief Gets a xtd::drawing::font that is used for menus.
      /// @return A xtd::drawing::font that is used for menus.
      static xtd::drawing::font menu_font();
      
      /// @brief Gets a xtd::drawing::font that is used for message boxes.
      /// @return A xtd::drawing::font that is used for message boxes.
      static xtd::drawing::font message_box_font();
      
      /// @brief Gets a xtd::drawing::font that is used to display text in the title bars of small windows, such as tool windows.
      /// @return A xtd::drawing::font that is used to display text in the title bars of small windows, such as tool windows.
      static xtd::drawing::font small_caption_font();
      
      /// @brief Gets a xtd::drawing::font that is used to display text in the status bar.
      /// @return A xtd::drawing::font that is used to display text in the status bar.
      static xtd::drawing::font status_font();
      
      /// @brief Gets a xtd::drawing::font that is used to display text in the tool bar.
      /// @return A xtd::drawing::font that is used to display text in the tool bar.
      static xtd::drawing::font tool_font();
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief Gets an array of system fonts.
      static const std::vector<xtd::drawing::font>& get_fonts();
      
      /// @brief Gets an array of system font names.
      static const std::vector<xtd::ustring>& get_font_names();
      /// @}
    };
  }
}
