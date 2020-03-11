#pragma once
#include "font.hpp"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the fonts used to display text in Windows display elements.
    /// @remarks Each property of the system_fonts class returns a Font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
    class system_fonts static_ {
    public:
      /// @brief Gets a font that is used to display text in the title bars of windows.
      static xtd::drawing::font caption_font();
      
      /// @brief Gets the default font that applications can use for dialog boxes and forms.
      /// @remarks The following table describes the value returned by the DefaultFont property depending on the operating system and local culture.
      /// | System and/or culture           | Font                                                               |
      /// |---------------------------------|--------------------------------------------------------------------|
      /// | Windows NT 4x, Japanese version | MS UI Gothic, 9 point                                              |
      /// | Arabic Windows                  | Tahoma, 8 point                                                    |
      /// | Other operating system/culture  | MS Shell Dlg logical font, typically Microsoft Sans Serif, 8 point |
      /// @remarks MS Shell Dlg maps to a font set in the system registry.
      /// @remarks If the above fonts are not installed, the default font is Tahoma, 8 point. If Tahoma, 8 point, is not installed, DefaultFont returns the value of the GenericSansSerif property.
      /// @remarks The Font returned by DefaultFont does not change when the user is in High Contrast mode. For a font that changes when the user is in High Contrast mode use another system font such as IconTitleFont.
      static xtd::drawing::font default_font();
      
      /// @brief Gets a font that applications can use for dialog boxes and forms.
      /// @remarks If the operating system is Windows 2000 or Windows XP, the DialogFont property returns Tahoma, 8 point. Otherwise, DialogFont returns the value of the DefaultFont property. The Font returned by DialogFont does not change when the user is in High Contrast mode. For a font that changes when the user is in High Contrast mode use another system font such as IconTitleFont.
      static xtd::drawing::font dialog_font();
      
      /// @brief Gets a font that is used for icon titles.
      static xtd::drawing::font icon_title_font();
      
      /// @brief Gets a font that is used for menus.
      static xtd::drawing::font menu_font();
      
      /// @brief Gets a font that is used for message boxes.
      static xtd::drawing::font message_box_font();
      
      /// @brief Gets a font that is used to display text in the title bars of small windows, such as tool windows.
      static xtd::drawing::font small_caption_font();
      
      /// @brief Gets a font that is used to display text in the status bar.
      static xtd::drawing::font status_font();
    };
  }
}
