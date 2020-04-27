#pragma once
#include <xtd/static.h>
#include "solid_brush.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the system_brushes class is a solid_brush that is the color of a Windows display element.
    class system_brushes static_ {
    public:
      /// Gets a solid_brush that is the color of the active border.
      static xtd::drawing::solid_brush active_border();
      
      /// Gets a solid_brush that is the color of the active caption.
      static xtd::drawing::solid_brush active_caption();
      
      /// Gets a solid_brush that is the color of the active caption text.
      static xtd::drawing::solid_brush active_caption_text();
      
      /// Gets a solid_brush that is the color of the app workspace.
      static xtd::drawing::solid_brush app_workspace();
      
      /// Gets a solid_brush that is the color of the control.
      static xtd::drawing::solid_brush control();
      
      /// Gets a solid_brush that is the color of the control dark.
      static xtd::drawing::solid_brush control_dark();
      
      /// Gets a solid_brush that is the color of the control dark dark.
      static xtd::drawing::solid_brush control_dark_dark();
      
      /// Gets a solid_brush that is the color of the control light.
      static xtd::drawing::solid_brush control_light();
      
      /// Gets a solid_brush that is the color of the control light light.
      static xtd::drawing::solid_brush control_light_light();
      
      /// Gets a solid_brush that is the color of the control text.
      static xtd::drawing::solid_brush control_text();
      
      /// Gets a solid_brush that is the color of the desktop.
      static xtd::drawing::solid_brush desktop();
      
      /// Gets a solid_brush that is the color of the gray text.
      static xtd::drawing::solid_brush gray_text();
      
      /// Gets a solid_brush that is the color of the highlight.
      static xtd::drawing::solid_brush highlight();
      
      /// Gets a solid_brush that is the color of the highlight text.
      static xtd::drawing::solid_brush highlight_text();
      
      /// Gets a solid_brush that is the color of the hot track.
      static xtd::drawing::solid_brush hot_track();
      
      /// Gets a solid_brush that is the color of the inactive border.
      static xtd::drawing::solid_brush inactive_border();
      
      /// Gets a solid_brush that is the color of the inactive caption.
      static xtd::drawing::solid_brush inactive_caption();
      
      /// Gets a solid_brush that is the color of the inactive caption text.
      static xtd::drawing::solid_brush inactive_caption_text();
      
      /// Gets a solid_brush that is the color of the info.
      static xtd::drawing::solid_brush info();
      
      /// Gets a solid_brush that is the color of the info text.
      static xtd::drawing::solid_brush info_text();
      
      /// Gets a solid_brush that is the color of the menu.
      static xtd::drawing::solid_brush menu();
      
      /// Gets a solid_brush that is the color of the menu text.
      static xtd::drawing::solid_brush menu_text();
      
      /// Gets a solid_brush that is the color of the scroll bar.
      static xtd::drawing::solid_brush scroll_bar();
      
      /// Gets a solid_brush that is the color of the window.
      static xtd::drawing::solid_brush window();
      
      /// Gets a solid_brush that is the color of the window frame.
      static xtd::drawing::solid_brush window_frame();
      
      /// Gets a solid_brush that is the color of the window text.
      static xtd::drawing::solid_brush window_text();
      
      /// Gets a solid_brush that is the color of the button face.
      static xtd::drawing::solid_brush button_face();
      
      /// Gets a solid_brush that is the color of the button highlight.
      static xtd::drawing::solid_brush button_highlight();
      
      /// Gets a solid_brush that is the color of the button shadow.
      static xtd::drawing::solid_brush button_shadow();
      
      /// Gets a solid_brush that is the color of the gradient active caption.
      static xtd::drawing::solid_brush gradient_active_caption();
      
      /// Gets a solid_brush that is the color of the gradient inactive caption.
      static xtd::drawing::solid_brush gradient_inactive_caption();
      
      /// Gets a solid_brush that is the color of the menu bar.
      static xtd::drawing::solid_brush menu_bar();
      
      /// Gets a solid_brush that is the color of the menu highlight.
      static xtd::drawing::solid_brush menu_highlight();      
    };
  }
}
