#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/static.h>
#include <xtd/types.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class system_fonts;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains system fonts native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ system_fonts final static_ {
        friend xtd::drawing::system_fonts;
      protected:
        /// @name Protected static methods
        
        /// @{
        /// @brief Gets a font that is used to display text in the title bars of windows.
        /// @return A font handle that is used to display text in the title bars of windows.
        /// @warning Internal use only
        static intptr caption_font();
        
        /// @brief Gets the default font that applications can use for dialog boxes and forms.
        /// @return The default font handle of the system. The value returned will vary depending on the user's operating system and the local culture setting of their system.
        /// @warning Internal use only
        static intptr default_font();
        
        /// @brief Gets a font that applications can use for dialog boxes and forms.
        /// @return A font handle that can be used for dialog boxes and forms, depending on the operating system and local culture setting of the system.
        /// @warning Internal use only
        static intptr dialog_font();
        
        /// @brief Gets a font that is used for icon titles.
        /// @return A font handle that is used for icon titles.
        /// @warning Internal use only
        static intptr icon_title_font();
        
        /// @brief Gets a font that is used for menus.
        /// @return A font handle that is used for menus.
        /// @warning Internal use only
        static intptr menu_font();
        
        /// @brief Gets a font that is used for message boxes.
        /// @return A font handle that is used for message boxes.
        /// @warning Internal use only
        static intptr message_box_font();
        
        /// @brief Gets a font that is used to display text in the title bars of small windows, such as tool windows.
        /// @return A font handle that is used to display text in the title bars of small windows, such as tool windows.
        /// @warning Internal use only
        static intptr small_caption_font();
        
        /// @brief Gets a font that is used to display text in the status bar.
        /// @return A font handle that is used to display text in the status bar.
        /// @warning Internal use only
        static intptr status_font();
        
        /// @brief Gets a font that is used to display text in the tool bar.
        /// @return A font handle that is used to display text in the tool bar.
        /// @warning Internal use only
        static intptr tool_font();
        /// @}
      };
    }
  }
}
