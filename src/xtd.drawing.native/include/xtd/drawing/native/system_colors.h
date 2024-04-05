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
    class color;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains system colors native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ system_colors final static_ {
        friend xtd::drawing::color;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Convert system color to argb.
        /// @param color The color handle.
        /// @return The 32-bit ARGB value of system color.
        /// @warning Internal use only
        static uint32 to_argb(xtd::intptr color);
        
        /// @brief Gets a color that is the color used to accent a control.
        /// @return A color handle that is the color used to accent a control.
        /// @warning Internal use only
        static xtd::intptr accent();
        
        /// @brief Gets a color that is the color of the text used to accent a control.
        /// @return A color handle that is the color of the text used to accent a control.
        /// @warning Internal use only
        static xtd::intptr accent_text();
        
        /// @brief Gets a color that is the color of the active window's border.
        /// @return A color handle that is the color of the active window's border.
        /// @warning Internal use only
        static xtd::intptr active_border();
        
        /// @brief Gets a color that is the color of the background of the active window's title bar.
        /// @return A color handle that is the color of the active window's title bar.
        /// @warning Internal use only
        static xtd::intptr active_caption();
        
        /// @brief Gets a color that is the color of the text in the active window's title bar.
        /// @return A color handle that is the color of the text in the active window's title bar.
        /// @warning Internal use only
        static xtd::intptr active_caption_text();
        
        /// @brief Gets a color that is the color of an html link text when mouse down.
        /// @return A color handle that is the color of an html link text when mouse down.
        /// @warning Internal use only
        static xtd::intptr active_text();
        
        /// @brief Gets a color that is the color of the application workspace.
        /// @return A color handle that is the color of the application workspace.
        /// @warning Internal use only
        static xtd::intptr app_workspace();
        
        /// @brief Gets a color that is the face color of a 3-D element.
        /// @return A color handle that is the face color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr button_face();
        
        /// @brief Gets a color that is the highlight color of a 3-D element.
        /// @return A color handle that is the highlight color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr button_highlight();
        
        /// @brief Gets a color that is the shadow color of a 3-D element.
        /// @return A color handle that is the shadow color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr button_shadow();
        
        /// @brief Gets a color that is the face color of a 3-D element.
        /// @return A color handle that is the face color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr control();
        
        /// @brief Gets a color that is the shadow color of a 3-D element.
        /// @return A color handle that is the shadow color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr control_dark();
        
        /// @brief Gets a color that is the dark shadow color of a 3-D element.
        /// @return A color handle that is the dark shadow color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr control_dark_dark();
        
        /// @brief Gets a color that is the light color of a 3-D element.
        /// @return A color handle that is the light color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr control_light();
        
        /// @brief Gets a color that is the highlight color of a 3-D element.
        /// @return A color handle that is the highlight color of a 3-D element.
        /// @warning Internal use only
        static xtd::intptr control_light_light();
        
        /// @brief Gets a color that is the color of text in a 3-D element.
        /// @return A color handle that is the color of text in a 3-D element.
        /// @warning Internal use only
        static xtd::intptr control_text();
        
        /// @brief Gets a color that is the color of the desktop.
        /// @return A color handle that is the color of the desktop.
        /// @warning Internal use only
        static xtd::intptr desktop();
        
        /// @brief Gets a color that is the lightest color in the color gradient of an active window's title bar.
        /// @return A color handle that is the lightest color in the color gradient of an active window's title bar.
        /// @warning Internal use only
        static xtd::intptr gradient_active_caption();
        
        /// @brief Gets a color that is the lightest color in the color gradient of an inactive window's title bar.
        /// @return A color handle that is the lightest color in the color gradient of an inactive window's title bar.
        /// @warning Internal use only
        static xtd::intptr gradient_inactive_caption();
        
        /// @brief Gets a color that is the color of dimmed text.
        /// @return A color handle that is the color of dimmed text.
        /// @warning Internal use only
        static xtd::intptr gray_text();
        
        /// @brief Gets a color that is the color of the background of selected items.
        /// @return A color handle that is the color of the background of selected items.
        /// @warning Internal use only
        static xtd::intptr highlight();
        
        /// @brief Gets a color that is the color of the text of selected items.
        /// @return A color handle that is the color of the text of selected items.
        /// @warning Internal use only
        static xtd::intptr highlight_text();
        
        /// @brief Gets a color that is the color used to designate a hot-tracked item.
        /// @return A color handle that is the color used to designate a hot-tracked item.
        /// @warning Internal use only
        static xtd::intptr hot_track();
        
        /// @brief Gets a color that is the color of an inactive window's border.
        /// @return A color handle that is the color of an inactive window's border.
        /// @warning Internal use only
        static xtd::intptr inactive_border();
        
        /// @brief Gets a color that is the color of the background of an inactive window's title bar.
        /// @return A color handle that is the color of the background of an inactive window's title bar.
        /// @warning Internal use only
        static xtd::intptr inactive_caption();
        
        /// @brief Gets a color that is the color of the text in an inactive window's title bar.
        /// @return A color handle that is the color of the text in an inactive window's title bar.
        /// @warning Internal use only
        static xtd::intptr inactive_caption_text();
        
        /// @brief Gets a color that is the color of the background of a xtd::forms::tool_tip.
        /// @return A color handle that is the color of the background of a xtd::forms::tool_tip.
        /// @warning Internal use only
        static xtd::intptr info();
        
        /// @brief Gets a color that is the color of the text of a xtd::forms::tool_tip.
        /// @return A color handle that is the color of the text of a xtd::forms::tool_tip.
        /// @warning Internal use only
        static xtd::intptr info_text();
        
        /// @brief Gets a color that is the color of an html link text.
        /// @return A color handle that is the color of an html link text.
        /// @warning Internal use only
        static xtd::intptr link_text();
        
        /// @brief Gets a color that is the color of a menu's background.
        /// @return A color handle that is the color of a menu's background.
        /// @warning Internal use only
        static xtd::intptr menu();
        
        /// @brief Gets a color that is the color of the background of a menu bar.
        /// @return A color handle that is the color of the background of a menu bar.
        /// @warning Internal use only
        static xtd::intptr menu_bar();
        
        /// @brief Gets a color that is the color used to highlight menu items when the menu appears as a flat menu.
        /// @return A color handle that is the color used to highlight menu items when the menu appears as a flat menu.
        /// @warning Internal use only
        static xtd::intptr menu_highlight();
        
        /// @brief Gets a color that is the color of a menu's text.
        /// @return A color handle that is the color of a menu's text.
        /// @warning Internal use only
        static xtd::intptr menu_text();
        
        /// @brief Gets a color that is the color of the background of a scroll bar.
        /// @return A color handle that is the color of the background of a scroll bar.
        /// @warning Internal use only
        static xtd::intptr scroll_bar();
        
        /// @brief Gets a color that is the color of the shadow text.
        /// @return A color handle that is the color of the shadow text.
        /// @warning Internal use only
        static xtd::intptr shadow_text();
        
        /// @brief Gets a color that is the color of the background of a text box.
        /// @return A color handle that is the color of the background of a textt box.
        /// @warning Internal use only
        static xtd::intptr text_box();
        
        /// @brief Gets a color that is the color of the text of a text box.
        /// @return A color handle that is the color of the text of a text tbox.
        /// @warning Internal use only
        static xtd::intptr text_box_text();
        
        /// @brief Gets a color that is the color of an html visited link text.
        /// @return A color handle that is the color of an html visited link text.
        /// @warning Internal use only
        static xtd::intptr visited_text();
        
        /// @brief Gets a color that is the color of the background in the client area of a window.
        /// @return A color handle that is the color of the background in the client area of a window.
        /// @warning Internal use only
        static xtd::intptr window();
        
        /// @brief Gets a color that is the color of a window frame.
        /// @return A color handle that is the color of a window frame.
        /// @warning Internal use only
        static xtd::intptr window_frame();
        
        /// @brief Gets a color that is the color of the text in the client area of a window.
        /// @return A color handle that is the color of the text in the client area of a window.
        /// @warning Internal use only
        static xtd::intptr window_text();
        /// @}
      };
    }
  }
}
