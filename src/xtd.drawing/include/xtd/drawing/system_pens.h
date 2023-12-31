/// @file
/// @brief Contains xtd::drawing::system_pens factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include "pen.h"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_pens class is a xtd::drawing::xtd::drawing::pen that is the color of a Windows display element and that has a width of 1 pixel.
    /// @code
    /// class drawing_export_ system_pens final static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::drawing::system_pens
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ system_pens final static_ {
    public:
      /// @name Properties
      
      /// @{
      /// @brief Gets a pen that is the color of the accent.
      /// @return A xtd::drawing::pen that is the color of the accent.
      static xtd::drawing::pen accent();
      
      /// @brief Gets a pen that is the color of the accent text.
      /// @return A xtd::drawing::pen that is the color of the accent ext.
      static xtd::drawing::pen accent_text();
      
      /// @brief Gets a pen that is the color of the active border.
      /// @return A xtd::drawing::pen that is the color of the active window's border.
      static xtd::drawing::pen active_border();
      
      /// @brief Gets a pen that is the color of the active caption.
      /// @return A xtd::drawing::pen that is the color of the active caption.
      static xtd::drawing::pen active_caption();
      
      /// @brief Gets a pen that is the color of the active caption text.
      /// @return A xtd::drawing::pen that is the color of the active caption text.
      static xtd::drawing::pen active_caption_text();
      
      /// @brief Gets a pen that is the color of the active text.
      /// @return A xtd::drawing::pen that is the color of the active text.
      static xtd::drawing::pen active_text();
      
      /// @brief Gets a pen that is the color of the app workspace.
      /// @return A xtd::drawing::pen that is the color of the app workspace.
      static xtd::drawing::pen app_workspace();
      
      /// @brief Gets a pen that is the color of the button face.
      /// @return A xtd::drawing::pen that is the color of the button face.
      static xtd::drawing::pen button_face();
      
      /// @brief Gets a pen that is the color of the button highlight.
      /// @return A xtd::drawing::pen that is the color of the button highlight.
      static xtd::drawing::pen button_highlight();
      
      /// @brief Gets a pen that is the color of the button shadow.
      /// @return A xtd::drawing::pen that is the color of the button shadow.
      static xtd::drawing::pen button_shadow();
      
      /// @brief Gets a pen that is the color of the control.
      /// @return A xtd::drawing::pen that is the color of the control.
      static xtd::drawing::pen control();
      
      /// @brief Gets a pen that is the color of the control dark.
      /// @return A xtd::drawing::pen that is the color of the control dark.
      static xtd::drawing::pen control_dark();
      
      /// @brief Gets a pen that is the color of the control dark dark.
      /// @return A xtd::drawing::pen that is the color of the control dark dark.
      static xtd::drawing::pen control_dark_dark();
      
      /// @brief Gets a pen that is the color of the control light.
      /// @return A xtd::drawing::pen that is the color of the control light.
      static xtd::drawing::pen control_light();
      
      /// @brief Gets a pen that is the color of the control light light.
      /// @return A xtd::drawing::pen that is the color of the control light kight.
      static xtd::drawing::pen control_light_light();
      
      /// @brief Gets a pen that is the color of the control text.
      /// @return A xtd::drawing::pen that is the color of the control text.
      static xtd::drawing::pen control_text();
      
      /// @brief Gets a pen that is the color of the desktop.
      /// @return A xtd::drawing::pen that is the color of the desktop.
      static xtd::drawing::pen desktop();
      
      /// @brief Gets a pen that is the color of the gradient active caption.
      /// @return A xtd::drawing::pen that is the color of the gradient active caption.
      static xtd::drawing::pen gradient_active_caption();
      
      /// @brief Gets a pen that is the color of the gradient inactive caption.
      /// @return A xtd::drawing::pen that is the color of the gradient inactive caption.
      static xtd::drawing::pen gradient_inactive_caption();
      
      /// @brief Gets a pen that is the color of the gray text.
      /// @return A xtd::drawing::pen that is the color of the gray text.
      static xtd::drawing::pen gray_text();
      
      /// @brief Gets a pen that is the color of the highlight.
      /// @return A xtd::drawing::pen that is the color of the highlight.
      static xtd::drawing::pen highlight();
      
      /// @brief Gets a pen that is the color of the highlight text.
      /// @return A xtd::drawing::pen that is the color of the highlight text.
      static xtd::drawing::pen highlight_text();
      
      /// @brief Gets a pen that is the color of the hot track.
      /// @return A xtd::drawing::pen that is the color of the hot track.
      static xtd::drawing::pen hot_track();
      
      /// @brief Gets a pen that is the color of the inactive border.
      /// @return A xtd::drawing::pen that is the color of the inactive border.
      static xtd::drawing::pen inactive_border();
      
      /// @brief Gets a pen that is the color of the inactive caption.
      /// @return A xtd::drawing::pen that is the color of the inactive caption.
      static xtd::drawing::pen inactive_caption();
      
      /// @brief Gets a pen that is the color of the inactive caption text.
      /// @return A xtd::drawing::pen that is the color of the inactive caption text.
      static xtd::drawing::pen inactive_caption_text();
      
      /// @brief Gets a pen that is the color of the info.
      /// @return A xtd::drawing::pen that is the color of the info.
      static xtd::drawing::pen info();
      
      /// @brief Gets a pen that is the color of the info text.
      /// @return A xtd::drawing::pen that is the color of the info text.
      static xtd::drawing::pen info_text();
      
      /// @brief Gets a pen that is the color of the link text.
      /// @return A xtd::drawing::pen that is the color of the link text.
      static xtd::drawing::pen link_text();
      
      /// @brief Gets a pen that is the color of the menu.
      /// @return A xtd::drawing::pen that is the color of the menu.
      static xtd::drawing::pen menu();
      
      /// @brief Gets a pen that is the color of the menu bar.
      /// @return A xtd::drawing::pen that is the color of the menu bar.
      static xtd::drawing::pen menu_bar();
      
      /// @brief Gets a pen that is the color of the menu highlight.
      /// @return A xtd::drawing::pen that is the color of the menu highlight.
      static xtd::drawing::pen menu_highlight();
      
      /// @brief Gets a pen that is the color of the menu text.
      /// @return A xtd::drawing::pen that is the color of the menu text.
      static xtd::drawing::pen menu_text();
      
      /// @brief Gets a pen that is the color of the scroll bar.
      /// @return A xtd::drawing::pen that is the color of the scroll bar.
      static xtd::drawing::pen scroll_bar();
      
      /// @brief Gets a pen that is the color of the text box.
      /// @return A xtd::drawing::pen that is the color of the text box.
      static xtd::drawing::pen text_box();
      
      /// @brief Gets a pen that is the color of the text box text.
      /// @return A xtd::drawing::pen that is the color of the text box text.
      static xtd::drawing::pen text_box_text();
      
      /// @brief Gets a pen that is the color of the visited text.
      /// @return A xtd::drawing::pen that is the color of the visited text.
      static xtd::drawing::pen visited_text();
      
      /// @brief Gets a pen that is the color of the window.
      /// @return A xtd::drawing::pen that is the color of the window.
      static xtd::drawing::pen window();
      
      /// @brief Gets a pen that is the color of the window frame.
      /// @return A xtd::drawing::pen that is the color of the window frame.
      static xtd::drawing::pen window_frame();
      
      /// @brief Gets a pen that is the color of the window text.
      /// @return A xtd::drawing::pen that is the color of the window text.
      static xtd::drawing::pen window_text();
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Gets an array of system colors.
      static const std::vector<xtd::drawing::pen>& get_pens();
      /// @}
    };
  }
}
