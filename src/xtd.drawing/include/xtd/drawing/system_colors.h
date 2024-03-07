/// @file
/// @brief Contains xtd::drawing::system_colors factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "color.h"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_colors class is a xtd::drawing::color structure that is the color of a Windows display element.
    /// @code
    /// class drawing_export_ system_colors final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_colors
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing colors
    /// @remarks Better performance is achieved by using the properties of the xtd::drawing::SystemPens or xtd::drawing::SystemBrushes classes rather than creating a new pen or brush based on a value from xtd::drawing::system_colors. For example, if you wanted to get a brush for the face color of a 3-D element, use the SystemBrushes.Control property because it gets a brush that already exists, whereas calling the SolidBrush.#ctor(xtd::drawing::color) constructor with a parameter value of system_colors::Control will create a new brush.
    class drawing_export_ system_colors final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a xtd::drawing::color structure that is the color used to accent a control.
      /// @return A xtd::drawing::color that is the color used to accent a control.
      static xtd::drawing::color accent();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text used to accent a control.
      /// @return A xtd::drawing::color that is the color of the text used to accent a control.
      static xtd::drawing::color accent_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the active window's border.
      /// @return A xtd::drawing::color that is the color of the active window's border.
      static xtd::drawing::color active_border();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of the active window's title bar.
      /// @return A xtd::drawing::color that is the color of the active window's title bar.
      static xtd::drawing::color active_caption();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text in the active window's title bar.
      /// @return A xtd::drawing::color that is the color of the text in the active window's title bar.
      static xtd::drawing::color active_caption_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a active text.
      /// @return A xtd::drawing::color that is the color of a active text.
      /// @remarks The active text color is the text color of an html link text when mouse down.
      static xtd::drawing::color active_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the application workspace.
      /// @return A xtd::drawing::color that is the color of the application workspace.
      /// @remarks The application workspace is the area in a multiple-document view that is not being occupied by documents.
      static xtd::drawing::color app_workspace();
      
      /// @brief Gets a xtd::drawing::color structure that is the face color of a 3-D element.
      /// @return A xtd::drawing::color that is the face color of a 3-D element.
      static xtd::drawing::color button_face();
      
      /// @brief Gets a xtd::drawing::color structure that is the highlight color of a 3-D element.
      /// @return A xtd::drawing::color that is the highlight color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face the light source.
      static xtd::drawing::color button_highlight();
      
      /// @brief Gets a xtd::drawing::color structure that is the shadow color of a 3-D element.
      /// @return A xtd::drawing::color that is the shadow color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face away from the light source.
      static xtd::drawing::color button_shadow();
      
      /// @brief Gets a xtd::drawing::color structure that is the face color of a 3-D element.
      /// @return A xtd::drawing::color that is the face color of a 3-D element.
      static xtd::drawing::color control();
      
      /// @brief Gets a xtd::drawing::color structure that is the shadow color of a 3-D element.
      /// @return A xtd::drawing::color that is the shadow color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face away from the light source.
      static xtd::drawing::color control_dark();
      
      /// @brief Gets a xtd::drawing::color structure that is the dark shadow color of a 3-D element.
      /// @return A xtd::drawing::color that is the dark shadow color of a 3-D element.
      /// @remarks This color is applied to the parts of a 3-D element that are the darkest color.
      static xtd::drawing::color control_dark_dark();
      
      /// @brief Gets a xtd::drawing::color structure that is the light color of a 3-D element.
      /// @return A xtd::drawing::color that is the light color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face the light source.
      static xtd::drawing::color control_light();
      
      /// @brief Gets a xtd::drawing::color structure that is the highlight color of a 3-D element.
      /// @return A xtd::drawing::color that is the highlight color of a 3-D element.
      /// @remarks This color is applied to the parts of a 3-D element that are the lightest color.
      static xtd::drawing::color control_light_light();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of text in a 3-D element.
      /// @return A xtd::drawing::color that is the color of text in a 3-D element.
      static xtd::drawing::color control_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the desktop.
      /// @return A xtd::drawing::color that is the color of the desktop.
      static xtd::drawing::color desktop();
      
      /// @brief Gets a xtd::drawing::color structure that is the lightest color in the color gradient of an active window's title bar.
      /// @return A xtd::drawing::color that is the lightest color in the color gradient of an active window's title bar.
      static xtd::drawing::color gradient_active_caption();
      
      /// @brief Gets a xtd::drawing::color structure that is the lightest color in the color gradient of an inactive window's title bar.
      /// @return A xtd::drawing::color that is the lightest color in the color gradient of an inactive window's title bar.
      static xtd::drawing::color gradient_inactive_caption();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of dimmed text.
      /// @return A xtd::drawing::color that is the color of dimmed text.
      /// @remarks Items in a list that are disabled are displayed in dimmed text.
      static xtd::drawing::color gray_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of selected items.
      /// @return A xtd::drawing::color that is the color of the background of selected items.
      /// @remarks Selected items may include menu items as well as selected text. For example, the xtd::drawing::color structure may be the color used for the background of selected items in a list box.
      static xtd::drawing::color highlight();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text of selected items.
      /// @return A xtd::drawing::color that is the color of the text of selected items.
      /// @remarks For example, this color is used for the text of selected items in a list box.
      static xtd::drawing::color highlight_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color used to designate a hot-tracked item.
      /// @return A xtd::drawing::color that is the color used to designate a hot-tracked item.
      /// @remarks Single-clicking a hot-tracked item executes the item.
      static xtd::drawing::color hot_track();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of an inactive window's border.
      /// @return A xtd::drawing::color that is the color of an inactive window's border.
      static xtd::drawing::color inactive_border();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of an inactive window's title bar.
      /// @return A xtd::drawing::color that is the color of the background of an inactive window's title bar.
      static xtd::drawing::color inactive_caption();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text in an inactive window's title bar.
      /// @return A xtd::drawing::color that is the color of the text in an inactive window's title bar.
      static xtd::drawing::color inactive_caption_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a xtd::forms::tool_tip.
      /// @return A xtd::drawing::color that is the color of the background of a xtd::forms::tool_tip.
      static xtd::drawing::color info();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text of a xtd::forms::tool_tip.
      /// @return A xtd::drawing::color that is the color of the text of a xtd::forms::tool_tip.
      static xtd::drawing::color info_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a link text.
      /// @return A xtd::drawing::color that is the color of a link text.
      /// @remarks The link text color is the text color of an html link text.
      static xtd::drawing::color link_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a menu's background.
      /// @return A xtd::drawing::color that is the color of a menu's background.
      static xtd::drawing::color menu();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a menu bar.
      /// @return A xtd::drawing::color that is the color of the background of a menu bar.
      static xtd::drawing::color menu_bar();
      
      /// @brief Gets a xtd::drawing::color structure that is the color used to highlight menu items when the menu appears as a flat menu.
      /// @return A xtd::drawing::color that is the color used to highlight menu items when the menu appears as a flat menu.
      static xtd::drawing::color menu_highlight();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a menu's text.
      /// @return A xtd::drawing::color that is the color of a menu's text.
      static xtd::drawing::color menu_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a scroll bar.
      /// @return A xtd::drawing::color that is the color of the background of a scroll bar.
      static xtd::drawing::color scroll_bar();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the shadow text.
      /// @return A xtd::drawing::color that is the color of the shadow text.
      static xtd::drawing::color shadow_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a text box.
      /// @return A xtd::drawing::color that is the color of the background of a textt box.
      static xtd::drawing::color text_box();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text of a text box.
      /// @return A xtd::drawing::color that is the color of the text of a text tbox.
      static xtd::drawing::color text_box_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a visited text.
      /// @return A xtd::drawing::color that is the color of a link text.
      /// @remarks The visited text color is the text color of an html visited link text.
      static xtd::drawing::color visited_text();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background in the client area of a window.
      /// @return A xtd::drawing::color that is the color of the background in the client area of a window.
      static xtd::drawing::color window();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a window frame.
      /// @return A xtd::drawing::color that is the color of a window frame.
      static xtd::drawing::color window_frame();
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text in the client area of a window.
      /// @return A xtd::drawing::color that is the color of the text in the client area of a window.
      static xtd::drawing::color window_text();
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of system colors.
      static const std::vector<xtd::drawing::color>& get_colors() noexcept;
      
      /// @brief Gets an array of system color names.
      static const std::vector<xtd::ustring>& get_color_names() noexcept;
      /// @}
    };
  }
}
