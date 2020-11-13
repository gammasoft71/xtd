#pragma once
#include <xtd/static.h>
#include "pen.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the system_pens class is a pen that is the color of a Windows display element and that has a width of 1 pixel.
    class system_pens static_ {
    public:
      /// Gets a pen that is the color of the active border.
      static xtd::drawing::pen active_border();
      
      /// Gets a pen that is the color of the active caption.
      static xtd::drawing::pen active_caption();
      
      /// Gets a pen that is the color of the active caption text.
      static xtd::drawing::pen active_caption_text();
      
      /// Gets a pen that is the color of the app workspace.
      static xtd::drawing::pen app_workspace();
      
      /// Gets a pen that is the color of the control.
      static xtd::drawing::pen control();
      
      /// Gets a pen that is the color of the control dark.
      static xtd::drawing::pen control_dark();
      
      /// Gets a pen that is the color of the control dark dark.
      static xtd::drawing::pen control_dark_dark();
      
      /// Gets a pen that is the color of the control light.
      static xtd::drawing::pen control_light();
      
      /// Gets a pen that is the color of the control light light.
      static xtd::drawing::pen control_light_light();
      
      /// Gets a pen that is the color of the control text.
      static xtd::drawing::pen control_text();
      
      /// Gets a pen that is the color of the desktop.
      static xtd::drawing::pen desktop();
      
      /// Gets a pen that is the color of the gray text.
      static xtd::drawing::pen gray_text();
      
      /// Gets a pen that is the color of the highlight.
      static xtd::drawing::pen highlight();
      
      /// Gets a pen that is the color of the highlight text.
      static xtd::drawing::pen highlight_text();
      
      /// Gets a pen that is the color of the hot track.
      static xtd::drawing::pen hot_track();
      
      /// Gets a pen that is the color of the inactive border.
      static xtd::drawing::pen inactive_border();
      
      /// Gets a pen that is the color of the inactive caption.
      static xtd::drawing::pen inactive_caption();
      
      /// Gets a pen that is the color of the inactive caption text.
      static xtd::drawing::pen inactive_caption_text();
      
      /// Gets a pen that is the color of the info.
      static xtd::drawing::pen info();
      
      /// Gets a pen that is the color of the info text.
      static xtd::drawing::pen info_text();
      
      /// Gets a pen that is the color of the menu.
      static xtd::drawing::pen menu();
      
      /// Gets a pen that is the color of the menu text.
      static xtd::drawing::pen menu_text();
      
      /// Gets a pen that is the color of the scroll bar.
      static xtd::drawing::pen scroll_bar();
      
      /// Gets a pen that is the color of the window.
      static xtd::drawing::pen window();
      
      /// Gets a pen that is the color of the window frame.
      static xtd::drawing::pen window_frame();
      
      /// Gets a pen that is the color of the window text.
      static xtd::drawing::pen window_text();
      
      /// Gets a pen that is the color of the button face.
      static xtd::drawing::pen button_face();
      
      /// Gets a pen that is the color of the button highlight.
      static xtd::drawing::pen button_highlight();
      
      /// Gets a pen that is the color of the button shadow.
      static xtd::drawing::pen button_shadow();
      
      /// Gets a pen that is the color of the gradient active caption.
      static xtd::drawing::pen gradient_active_caption();
      
      /// Gets a pen that is the color of the gradient inactive caption.
      static xtd::drawing::pen gradient_inactive_caption();
      
      /// Gets a pen that is the color of the menu bar.
      static xtd::drawing::pen menu_bar();
      
      /// Gets a pen that is the color of the menu highlight.
      static xtd::drawing::pen menu_highlight();
      
      /// Gets a pen that is the color of the accent
      static xtd::drawing::pen accent();
    };
  }
}
