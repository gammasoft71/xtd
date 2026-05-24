/// @file
/// @brief Contains xtd::drawing::system_pens factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "pen.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_pens class is a xtd::drawing::xtd::drawing::pen that is the color of a Windows display element and that has a width of 1 pixel.
    /// ```cpp
    /// class drawing_export_ system_pens final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_pens
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing pens
    class drawing_export_ system_pens final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a pen that is the color of the accent.
      /// @return A xtd::drawing::pen that is the color of the accent.
      [[nodiscard]] static auto accent() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the accent text.
      /// @return A xtd::drawing::pen that is the color of the accent ext.
      [[nodiscard]] static auto accent_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the active border.
      /// @return A xtd::drawing::pen that is the color of the active window's border.
      [[nodiscard]] static auto active_border() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the active caption.
      /// @return A xtd::drawing::pen that is the color of the active caption.
      [[nodiscard]] static auto active_caption() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the active caption text.
      /// @return A xtd::drawing::pen that is the color of the active caption text.
      [[nodiscard]] static auto active_caption_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the active text.
      /// @return A xtd::drawing::pen that is the color of the active text.
      [[nodiscard]] static auto active_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the app workspace.
      /// @return A xtd::drawing::pen that is the color of the app workspace.
      [[nodiscard]] static auto app_workspace() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the button face.
      /// @return A xtd::drawing::pen that is the color of the button face.
      [[nodiscard]] static auto button_face() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the button highlight.
      /// @return A xtd::drawing::pen that is the color of the button highlight.
      [[nodiscard]] static auto button_highlight() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the button shadow.
      /// @return A xtd::drawing::pen that is the color of the button shadow.
      [[nodiscard]] static auto button_shadow() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the control.
      /// @return A xtd::drawing::pen that is the color of the control.
      [[nodiscard]] static auto control() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the control dark.
      /// @return A xtd::drawing::pen that is the color of the control dark.
      [[nodiscard]] static auto control_dark() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the control dark dark.
      /// @return A xtd::drawing::pen that is the color of the control dark dark.
      [[nodiscard]] static auto control_dark_dark() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the control light.
      /// @return A xtd::drawing::pen that is the color of the control light.
      [[nodiscard]] static auto control_light() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the control light light.
      /// @return A xtd::drawing::pen that is the color of the control light kight.
      [[nodiscard]] static auto control_light_light() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the control text.
      /// @return A xtd::drawing::pen that is the color of the control text.
      [[nodiscard]] static auto control_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the desktop.
      /// @return A xtd::drawing::pen that is the color of the desktop.
      [[nodiscard]] static auto desktop() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the gradient active caption.
      /// @return A xtd::drawing::pen that is the color of the gradient active caption.
      [[nodiscard]] static auto gradient_active_caption() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the gradient inactive caption.
      /// @return A xtd::drawing::pen that is the color of the gradient inactive caption.
      [[nodiscard]] static auto gradient_inactive_caption() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the gray text.
      /// @return A xtd::drawing::pen that is the color of the gray text.
      [[nodiscard]] static auto gray_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the highlight.
      /// @return A xtd::drawing::pen that is the color of the highlight.
      [[nodiscard]] static auto highlight() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the highlight text.
      /// @return A xtd::drawing::pen that is the color of the highlight text.
      [[nodiscard]] static auto highlight_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the hot track.
      /// @return A xtd::drawing::pen that is the color of the hot track.
      [[nodiscard]] static auto hot_track() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the inactive border.
      /// @return A xtd::drawing::pen that is the color of the inactive border.
      [[nodiscard]] static auto inactive_border() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the inactive caption.
      /// @return A xtd::drawing::pen that is the color of the inactive caption.
      [[nodiscard]] static auto inactive_caption() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the inactive caption text.
      /// @return A xtd::drawing::pen that is the color of the inactive caption text.
      [[nodiscard]] static auto inactive_caption_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the info.
      /// @return A xtd::drawing::pen that is the color of the info.
      [[nodiscard]] static auto info() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the info text.
      /// @return A xtd::drawing::pen that is the color of the info text.
      [[nodiscard]] static auto info_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the link text.
      /// @return A xtd::drawing::pen that is the color of the link text.
      [[nodiscard]] static auto link_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the menu.
      /// @return A xtd::drawing::pen that is the color of the menu.
      [[nodiscard]] static auto menu() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the menu bar.
      /// @return A xtd::drawing::pen that is the color of the menu bar.
      [[nodiscard]] static auto menu_bar() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the menu highlight.
      /// @return A xtd::drawing::pen that is the color of the menu highlight.
      [[nodiscard]] static auto menu_highlight() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the menu text.
      /// @return A xtd::drawing::pen that is the color of the menu text.
      [[nodiscard]] static auto menu_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the scroll bar.
      /// @return A xtd::drawing::pen that is the color of the scroll bar.
      [[nodiscard]] static auto scroll_bar() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the text box.
      /// @return A xtd::drawing::pen that is the color of the text box.
      [[nodiscard]] static auto text_box() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the text box text.
      /// @return A xtd::drawing::pen that is the color of the text box text.
      [[nodiscard]] static auto text_box_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the visited text.
      /// @return A xtd::drawing::pen that is the color of the visited text.
      [[nodiscard]] static auto visited_text() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the window.
      /// @return A xtd::drawing::pen that is the color of the window.
      [[nodiscard]] static auto window() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the window frame.
      /// @return A xtd::drawing::pen that is the color of the window frame.
      [[nodiscard]] static auto window_frame() -> xtd::drawing::pen;
      
      /// @brief Gets a pen that is the color of the window text.
      /// @return A xtd::drawing::pen that is the color of the window text.
      [[nodiscard]] static auto window_text() -> xtd::drawing::pen;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of system colors.
      [[nodiscard]] static auto get_pens() -> const xtd::array<xtd::drawing::pen>&;
      /// @}
    };
  }
}
