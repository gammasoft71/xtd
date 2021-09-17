#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <vector>
#include <xtd/static.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
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
        static uint32_t to_argb(intptr_t color);
        static intptr_t accent();
        static intptr_t accent_text();
        static intptr_t active_border();
        static intptr_t active_caption();
        static intptr_t active_caption_text();
        static intptr_t app_workspace();
        static intptr_t button_face();
        static intptr_t button_highlight();
        static intptr_t button_shadow();
        static intptr_t control();
        static intptr_t control_dark();
        static intptr_t control_dark_dark();
        static intptr_t control_light();
        static intptr_t control_light_light();
        static intptr_t control_text();
        static intptr_t desktop();
        static intptr_t gradient_active_caption();
        static intptr_t gradient_inactive_caption();
        static intptr_t gray_text();
        static intptr_t highlight();
        static intptr_t highlight_text();
        static intptr_t hot_track();
        static intptr_t inactive_border();
        static intptr_t inactive_caption();
        static intptr_t inactive_caption_text();
        static intptr_t info();
        static intptr_t info_text();
        static intptr_t menu();
        static intptr_t menu_bar();
        static intptr_t menu_highlight();
        static intptr_t menu_text();
        static intptr_t scroll_bar();
        static intptr_t window();
        static intptr_t window_frame();
        static intptr_t window_text();
        static intptr_t text_box();
        static intptr_t text_box_text();
      };
    }
  }
}
