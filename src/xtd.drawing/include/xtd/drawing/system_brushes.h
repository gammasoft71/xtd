/// @file
/// @brief Contains xtd::drawing::system_brushes factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include "../drawing_export.h"
#include "solid_brush.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_brushes class is a xtd::drawing::solid_brush that is the color of a Windows display element.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ system_brushes final static_ {
    public:
      /// @brief Gets a solid_brush that is the color of the active border.
      static xtd::drawing::solid_brush active_border();
      
      /// @brief Gets a solid_brush that is the color of the active caption.
      static xtd::drawing::solid_brush active_caption();
      
      /// @brief Gets a solid_brush that is the color of the active caption text.
      static xtd::drawing::solid_brush active_caption_text();
      
      /// @brief Gets a solid_brush that is the color of the app workspace.
      static xtd::drawing::solid_brush app_workspace();
      
      /// @brief Gets a solid_brush that is the color of the control.
      static xtd::drawing::solid_brush control();
      
      /// @brief Gets a solid_brush that is the color of the control dark.
      static xtd::drawing::solid_brush control_dark();
      
      /// @brief Gets a solid_brush that is the color of the control dark dark.
      static xtd::drawing::solid_brush control_dark_dark();
      
      /// @brief Gets a solid_brush that is the color of the control light.
      static xtd::drawing::solid_brush control_light();
      
      /// @brief Gets a solid_brush that is the color of the control light light.
      static xtd::drawing::solid_brush control_light_light();
      
      /// @brief Gets a solid_brush that is the color of the control text.
      static xtd::drawing::solid_brush control_text();
      
      /// @brief Gets a solid_brush that is the color of the desktop.
      static xtd::drawing::solid_brush desktop();
      
      /// @brief Gets a solid_brush that is the color of the gray text.
      static xtd::drawing::solid_brush gray_text();
      
      /// @brief Gets a solid_brush that is the color of the highlight.
      static xtd::drawing::solid_brush highlight();
      
      /// @brief Gets a solid_brush that is the color of the highlight text.
      static xtd::drawing::solid_brush highlight_text();
      
      /// @brief Gets a solid_brush that is the color of the hot track.
      static xtd::drawing::solid_brush hot_track();
      
      /// @brief Gets a solid_brush that is the color of the inactive border.
      static xtd::drawing::solid_brush inactive_border();
      
      /// @brief Gets a solid_brush that is the color of the inactive caption.
      static xtd::drawing::solid_brush inactive_caption();
      
      /// @brief Gets a solid_brush that is the color of the inactive caption text.
      static xtd::drawing::solid_brush inactive_caption_text();
      
      /// @brief Gets a solid_brush that is the color of the info.
      static xtd::drawing::solid_brush info();
      
      /// @brief Gets a solid_brush that is the color of the info text.
      static xtd::drawing::solid_brush info_text();
      
      /// @brief Gets a solid_brush that is the color of the menu.
      static xtd::drawing::solid_brush menu();
      
      /// @brief Gets a solid_brush that is the color of the menu text.
      static xtd::drawing::solid_brush menu_text();
      
      /// @brief Gets a solid_brush that is the color of the scroll bar.
      static xtd::drawing::solid_brush scroll_bar();
      
      /// @brief Gets a solid_brush that is the color of the window.
      static xtd::drawing::solid_brush window();
      
      /// @brief Gets a solid_brush that is the color of the window frame.
      static xtd::drawing::solid_brush window_frame();
      
      /// @brief Gets a solid_brush that is the color of the window text.
      static xtd::drawing::solid_brush window_text();
      
      /// @brief Gets a solid_brush that is the color of the button face.
      static xtd::drawing::solid_brush button_face();
      
      /// @brief Gets a solid_brush that is the color of the button highlight.
      static xtd::drawing::solid_brush button_highlight();
      
      /// @brief Gets a solid_brush that is the color of the button shadow.
      static xtd::drawing::solid_brush button_shadow();
      
      /// @brief Gets a solid_brush that is the color of the gradient active caption.
      static xtd::drawing::solid_brush gradient_active_caption();
      
      /// @brief Gets a solid_brush that is the color of the gradient inactive caption.
      static xtd::drawing::solid_brush gradient_inactive_caption();
      
      /// @brief Gets a solid_brush that is the color of the menu bar.
      static xtd::drawing::solid_brush menu_bar();
      
      /// @brief Gets a solid_brush that is the color of the menu highlight.
      static xtd::drawing::solid_brush menu_highlight();
      
      /// @brief Gets a solid_brush that is the color of the accent.
      static xtd::drawing::solid_brush accent();
    };
  }
}
