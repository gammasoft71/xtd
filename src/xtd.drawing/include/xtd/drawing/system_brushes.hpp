/// @file
/// @brief Contains xtd::drawing::system_brushes factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "solid_brush.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_brushes class is a xtd::drawing::solid_brush that is the color of a Windows display element.
    /// ```cpp
    /// class drawing_export_ system_brushes final static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_brushes
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing brushes
    class drawing_export_ system_brushes final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets a solid_brush that is the color of the accent.
      [[nodiscard]] static auto accent() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the accent text.
      [[nodiscard]] static auto accent_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the active border.
      [[nodiscard]] static auto active_border() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the active caption.
      [[nodiscard]] static auto active_caption() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the active caption text.
      [[nodiscard]] static auto active_caption_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the active text.
      [[nodiscard]] static auto active_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the app workspace.
      [[nodiscard]] static auto app_workspace() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the button face.
      [[nodiscard]] static auto button_face() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the button highlight.
      [[nodiscard]] static auto button_highlight() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the button shadow.
      [[nodiscard]] static auto button_shadow() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the control.
      [[nodiscard]] static auto control() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the control dark.
      [[nodiscard]] static auto control_dark() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the control dark dark.
      [[nodiscard]] static auto control_dark_dark() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the control light.
      [[nodiscard]] static auto control_light() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the control light light.
      [[nodiscard]] static auto control_light_light() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the control text.
      [[nodiscard]] static auto control_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the desktop.
      [[nodiscard]] static auto desktop() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the gradient active caption.
      [[nodiscard]] static auto gradient_active_caption() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the gradient inactive caption.
      [[nodiscard]] static auto gradient_inactive_caption() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the gray text.
      [[nodiscard]] static auto gray_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the highlight.
      [[nodiscard]] static auto highlight() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the highlight text.
      [[nodiscard]] static auto highlight_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the hot track.
      [[nodiscard]] static auto hot_track() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the inactive border.
      [[nodiscard]] static auto inactive_border() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the inactive caption.
      [[nodiscard]] static auto inactive_caption() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the inactive caption text.
      [[nodiscard]] static auto inactive_caption_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the info.
      [[nodiscard]] static auto info() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the info text.
      [[nodiscard]] static auto info_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the link text.
      [[nodiscard]] static auto link_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the menu.
      [[nodiscard]] static auto menu() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the menu bar.
      [[nodiscard]] static auto menu_bar() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the menu highlight.
      [[nodiscard]] static auto menu_highlight() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the menu text.
      [[nodiscard]] static auto menu_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the scroll bar.
      [[nodiscard]] static auto scroll_bar() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the shadow text.
      [[nodiscard]] static auto shadow_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the text box.
      [[nodiscard]] static auto text_box() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the text box text.
      [[nodiscard]] static auto text_box_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the visited text.
      [[nodiscard]] static auto visited_text() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the window.
      [[nodiscard]] static auto window() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the window frame.
      [[nodiscard]] static auto window_frame() -> xtd::drawing::solid_brush;
      
      /// @brief Gets a solid_brush that is the color of the window text.
      [[nodiscard]] static auto window_text() -> xtd::drawing::solid_brush;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of system colors.
      static auto get_brushes() -> const xtd::array<xtd::drawing::solid_brush>&;
      /// @}
    };
  }
}
