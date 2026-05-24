/// @file
/// @brief Contains xtd::drawing::system_colors factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "color.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_colors class is a xtd::drawing::color structure that is the color of a Windows display element.
    /// ```cpp
    /// class drawing_export_ system_colors final static_
    /// ```
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
      [[nodiscard]] static auto accent() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text used to accent a control.
      /// @return A xtd::drawing::color that is the color of the text used to accent a control.
      [[nodiscard]] static auto accent_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the active window's border.
      /// @return A xtd::drawing::color that is the color of the active window's border.
      [[nodiscard]] static auto active_border() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of the active window's title bar.
      /// @return A xtd::drawing::color that is the color of the active window's title bar.
      [[nodiscard]] static auto active_caption() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text in the active window's title bar.
      /// @return A xtd::drawing::color that is the color of the text in the active window's title bar.
      [[nodiscard]] static auto active_caption_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a active text.
      /// @return A xtd::drawing::color that is the color of a active text.
      /// @remarks The active text color is the text color of an html link text when mouse down.
      [[nodiscard]] static auto active_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the application workspace.
      /// @return A xtd::drawing::color that is the color of the application workspace.
      /// @remarks The application workspace is the area in a multiple-document view that is not being occupied by documents.
      [[nodiscard]] static auto app_workspace() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the face color of a 3-D element.
      /// @return A xtd::drawing::color that is the face color of a 3-D element.
      [[nodiscard]] static auto button_face() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the highlight color of a 3-D element.
      /// @return A xtd::drawing::color that is the highlight color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face the light source.
      [[nodiscard]] static auto button_highlight() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the shadow color of a 3-D element.
      /// @return A xtd::drawing::color that is the shadow color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face away from the light source.
      [[nodiscard]] static auto button_shadow() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the face color of a 3-D element.
      /// @return A xtd::drawing::color that is the face color of a 3-D element.
      [[nodiscard]] static auto control() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the shadow color of a 3-D element.
      /// @return A xtd::drawing::color that is the shadow color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face away from the light source.
      [[nodiscard]] static auto control_dark() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the dark shadow color of a 3-D element.
      /// @return A xtd::drawing::color that is the dark shadow color of a 3-D element.
      /// @remarks This color is applied to the parts of a 3-D element that are the darkest color.
      [[nodiscard]] static auto control_dark_dark() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the light color of a 3-D element.
      /// @return A xtd::drawing::color that is the light color of a 3-D element.
      /// @remarks This color is applied to parts of a 3-D element that face the light source.
      [[nodiscard]] static auto control_light() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the highlight color of a 3-D element.
      /// @return A xtd::drawing::color that is the highlight color of a 3-D element.
      /// @remarks This color is applied to the parts of a 3-D element that are the lightest color.
      [[nodiscard]] static auto control_light_light() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of text in a 3-D element.
      /// @return A xtd::drawing::color that is the color of text in a 3-D element.
      [[nodiscard]] static auto control_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the desktop.
      /// @return A xtd::drawing::color that is the color of the desktop.
      [[nodiscard]] static auto desktop() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the lightest color in the color gradient of an active window's title bar.
      /// @return A xtd::drawing::color that is the lightest color in the color gradient of an active window's title bar.
      [[nodiscard]] static auto gradient_active_caption() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the lightest color in the color gradient of an inactive window's title bar.
      /// @return A xtd::drawing::color that is the lightest color in the color gradient of an inactive window's title bar.
      [[nodiscard]] static auto gradient_inactive_caption() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of dimmed text.
      /// @return A xtd::drawing::color that is the color of dimmed text.
      /// @remarks Items in a list that are disabled are displayed in dimmed text.
      [[nodiscard]] static auto gray_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of selected items.
      /// @return A xtd::drawing::color that is the color of the background of selected items.
      /// @remarks Selected items may include menu items as well as selected text. For example, the xtd::drawing::color structure may be the color used for the background of selected items in a list box.
      [[nodiscard]] static auto highlight() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text of selected items.
      /// @return A xtd::drawing::color that is the color of the text of selected items.
      /// @remarks For example, this color is used for the text of selected items in a list box.
      [[nodiscard]] static auto highlight_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color used to designate a hot-tracked item.
      /// @return A xtd::drawing::color that is the color used to designate a hot-tracked item.
      /// @remarks Single-clicking a hot-tracked item executes the item.
      [[nodiscard]] static auto hot_track() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of an inactive window's border.
      /// @return A xtd::drawing::color that is the color of an inactive window's border.
      [[nodiscard]] static auto inactive_border() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of an inactive window's title bar.
      /// @return A xtd::drawing::color that is the color of the background of an inactive window's title bar.
      [[nodiscard]] static auto inactive_caption() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text in an inactive window's title bar.
      /// @return A xtd::drawing::color that is the color of the text in an inactive window's title bar.
      [[nodiscard]] static auto inactive_caption_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a xtd::forms::tool_tip.
      /// @return A xtd::drawing::color that is the color of the background of a xtd::forms::tool_tip.
      [[nodiscard]] static auto info() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text of a xtd::forms::tool_tip.
      /// @return A xtd::drawing::color that is the color of the text of a xtd::forms::tool_tip.
      [[nodiscard]] static auto info_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a link text.
      /// @return A xtd::drawing::color that is the color of a link text.
      /// @remarks The link text color is the text color of an html link text.
      [[nodiscard]] static auto link_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a menu's background.
      /// @return A xtd::drawing::color that is the color of a menu's background.
      [[nodiscard]] static auto menu() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a menu bar.
      /// @return A xtd::drawing::color that is the color of the background of a menu bar.
      [[nodiscard]] static auto menu_bar() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color used to highlight menu items when the menu appears as a flat menu.
      /// @return A xtd::drawing::color that is the color used to highlight menu items when the menu appears as a flat menu.
      [[nodiscard]] static auto menu_highlight() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a menu's text.
      /// @return A xtd::drawing::color that is the color of a menu's text.
      [[nodiscard]] static auto menu_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a scroll bar.
      /// @return A xtd::drawing::color that is the color of the background of a scroll bar.
      [[nodiscard]] static auto scroll_bar() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the shadow text.
      /// @return A xtd::drawing::color that is the color of the shadow text.
      [[nodiscard]] static auto shadow_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background of a text box.
      /// @return A xtd::drawing::color that is the color of the background of a textt box.
      [[nodiscard]] static auto text_box() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text of a text box.
      /// @return A xtd::drawing::color that is the color of the text of a text tbox.
      [[nodiscard]] static auto text_box_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a visited text.
      /// @return A xtd::drawing::color that is the color of a link text.
      /// @remarks The visited text color is the text color of an html visited link text.
      [[nodiscard]] static auto visited_text() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the background in the client area of a window.
      /// @return A xtd::drawing::color that is the color of the background in the client area of a window.
      [[nodiscard]] static auto window() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of a window frame.
      /// @return A xtd::drawing::color that is the color of a window frame.
      [[nodiscard]] static auto window_frame() -> xtd::drawing::color;
      
      /// @brief Gets a xtd::drawing::color structure that is the color of the text in the client area of a window.
      /// @return A xtd::drawing::color that is the color of the text in the client area of a window.
      [[nodiscard]] static auto window_text() -> xtd::drawing::color;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of system colors.
      [[nodiscard]] static auto get_colors() noexcept -> const xtd::array<xtd::drawing::color>&;
      
      /// @brief Gets an array of system color names.
      [[nodiscard]] static auto get_color_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
