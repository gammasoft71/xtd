#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/static>
#include <xtd/types>
#include <xtd/drawing_native_export.hpp>

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
        [[nodiscard]] static auto to_argb(xtd::intptr color) -> xtd::uint32;
        
        /// @brief Gets a color that is the color used to accent a control.
        /// @return A color handle that is the color used to accent a control.
        /// @warning Internal use only
        [[nodiscard]] static auto accent() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the text used to accent a control.
        /// @return A color handle that is the color of the text used to accent a control.
        /// @warning Internal use only
        [[nodiscard]] static auto accent_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the active window's border.
        /// @return A color handle that is the color of the active window's border.
        /// @warning Internal use only
        [[nodiscard]] static auto active_border() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background of the active window's title bar.
        /// @return A color handle that is the color of the active window's title bar.
        /// @warning Internal use only
        [[nodiscard]] static auto active_caption() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the text in the active window's title bar.
        /// @return A color handle that is the color of the text in the active window's title bar.
        /// @warning Internal use only
        [[nodiscard]] static auto active_caption_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of an html link text when mouse down.
        /// @return A color handle that is the color of an html link text when mouse down.
        /// @warning Internal use only
        [[nodiscard]] static auto active_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the application workspace.
        /// @return A color handle that is the color of the application workspace.
        /// @warning Internal use only
        [[nodiscard]] static auto app_workspace() -> xtd::intptr;
        
        /// @brief Gets a color that is the face color of a 3-D element.
        /// @return A color handle that is the face color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto button_face() -> xtd::intptr;
        
        /// @brief Gets a color that is the highlight color of a 3-D element.
        /// @return A color handle that is the highlight color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto button_highlight() -> xtd::intptr;
        
        /// @brief Gets a color that is the shadow color of a 3-D element.
        /// @return A color handle that is the shadow color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto button_shadow() -> xtd::intptr;
        
        /// @brief Gets a color that is the face color of a 3-D element.
        /// @return A color handle that is the face color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto control() -> xtd::intptr;
        
        /// @brief Gets a color that is the shadow color of a 3-D element.
        /// @return A color handle that is the shadow color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto control_dark() -> xtd::intptr;
        
        /// @brief Gets a color that is the dark shadow color of a 3-D element.
        /// @return A color handle that is the dark shadow color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto control_dark_dark() -> xtd::intptr;
        
        /// @brief Gets a color that is the light color of a 3-D element.
        /// @return A color handle that is the light color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto control_light() -> xtd::intptr;
        
        /// @brief Gets a color that is the highlight color of a 3-D element.
        /// @return A color handle that is the highlight color of a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto control_light_light() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of text in a 3-D element.
        /// @return A color handle that is the color of text in a 3-D element.
        /// @warning Internal use only
        [[nodiscard]] static auto control_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the desktop.
        /// @return A color handle that is the color of the desktop.
        /// @warning Internal use only
        [[nodiscard]] static auto desktop() -> xtd::intptr;
        
        /// @brief Gets a color that is the lightest color in the color gradient of an active window's title bar.
        /// @return A color handle that is the lightest color in the color gradient of an active window's title bar.
        /// @warning Internal use only
        [[nodiscard]] static auto gradient_active_caption() -> xtd::intptr;
        
        /// @brief Gets a color that is the lightest color in the color gradient of an inactive window's title bar.
        /// @return A color handle that is the lightest color in the color gradient of an inactive window's title bar.
        /// @warning Internal use only
        [[nodiscard]] static auto gradient_inactive_caption() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of dimmed text.
        /// @return A color handle that is the color of dimmed text.
        /// @warning Internal use only
        [[nodiscard]] static auto gray_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background of selected items.
        /// @return A color handle that is the color of the background of selected items.
        /// @warning Internal use only
        [[nodiscard]] static auto highlight() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the text of selected items.
        /// @return A color handle that is the color of the text of selected items.
        /// @warning Internal use only
        [[nodiscard]] static auto highlight_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color used to designate a hot-tracked item.
        /// @return A color handle that is the color used to designate a hot-tracked item.
        /// @warning Internal use only
        [[nodiscard]] static auto hot_track() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of an inactive window's border.
        /// @return A color handle that is the color of an inactive window's border.
        /// @warning Internal use only
        [[nodiscard]] static auto inactive_border() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background of an inactive window's title bar.
        /// @return A color handle that is the color of the background of an inactive window's title bar.
        /// @warning Internal use only
        [[nodiscard]] static auto inactive_caption() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the text in an inactive window's title bar.
        /// @return A color handle that is the color of the text in an inactive window's title bar.
        /// @warning Internal use only
        [[nodiscard]] static auto inactive_caption_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background of a xtd::forms::tool_tip.
        /// @return A color handle that is the color of the background of a xtd::forms::tool_tip.
        /// @warning Internal use only
        [[nodiscard]] static auto info() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the text of a xtd::forms::tool_tip.
        /// @return A color handle that is the color of the text of a xtd::forms::tool_tip.
        /// @warning Internal use only
        [[nodiscard]] static auto info_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of an html link text.
        /// @return A color handle that is the color of an html link text.
        /// @warning Internal use only
        [[nodiscard]] static auto link_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of a menu's background.
        /// @return A color handle that is the color of a menu's background.
        /// @warning Internal use only
        [[nodiscard]] static auto menu() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background of a menu bar.
        /// @return A color handle that is the color of the background of a menu bar.
        /// @warning Internal use only
        [[nodiscard]] static auto menu_bar() -> xtd::intptr;
        
        /// @brief Gets a color that is the color used to highlight menu items when the menu appears as a flat menu.
        /// @return A color handle that is the color used to highlight menu items when the menu appears as a flat menu.
        /// @warning Internal use only
        [[nodiscard]] static auto menu_highlight() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of a menu's text.
        /// @return A color handle that is the color of a menu's text.
        /// @warning Internal use only
        [[nodiscard]] static auto menu_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background of a scroll bar.
        /// @return A color handle that is the color of the background of a scroll bar.
        /// @warning Internal use only
        [[nodiscard]] static auto scroll_bar() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the shadow text.
        /// @return A color handle that is the color of the shadow text.
        /// @warning Internal use only
        [[nodiscard]] static auto shadow_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background of a text box.
        /// @return A color handle that is the color of the background of a textt box.
        /// @warning Internal use only
        [[nodiscard]] static auto text_box() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the text of a text box.
        /// @return A color handle that is the color of the text of a text tbox.
        /// @warning Internal use only
        [[nodiscard]] static auto text_box_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of an html visited link text.
        /// @return A color handle that is the color of an html visited link text.
        /// @warning Internal use only
        [[nodiscard]] static auto visited_text() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the background in the client area of a window.
        /// @return A color handle that is the color of the background in the client area of a window.
        /// @warning Internal use only
        [[nodiscard]] static auto window() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of a window frame.
        /// @return A color handle that is the color of a window frame.
        /// @warning Internal use only
        [[nodiscard]] static auto window_frame() -> xtd::intptr;
        
        /// @brief Gets a color that is the color of the text in the client area of a window.
        /// @return A color handle that is the color of the text in the client area of a window.
        /// @warning Internal use only
        [[nodiscard]] static auto window_text() -> xtd::intptr;
        /// @}
      };
    }
  }
}
