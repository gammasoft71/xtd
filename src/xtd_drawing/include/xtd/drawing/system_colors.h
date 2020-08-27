#pragma once
#include "color.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_colors class is a xtd::drawing::Color structure that is the color of a Windows display element.
    /// @remarks Better performance is achieved by using the properties of the xtd::drawing::SystemPens or xtd::drawing::SystemBrushes classes rather than creating a new pen or brush based on a value from xtd::drawing::system_colors. For example, if you wanted to get a brush for the face color of a 3-D element, use the SystemBrushes.Control property because it gets a brush that already exists, whereas calling the SolidBrush.#ctor(Color) constructor with a parameter value of system_colors::Control will create a new brush.
    class system_colors static_ {
    public:
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
      static xtd::drawing::color active_border();

      /// @brief Gets a system-defined color that has an ARGB value of 0xFF0054E3. This field is constant.
      static xtd::drawing::color active_caption();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static xtd::drawing::color active_caption_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
      static xtd::drawing::color app_workspace();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
      static xtd::drawing::color control();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
      static xtd::drawing::color control_dark();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF716F64. This field is constant.
      static xtd::drawing::color control_dark_dark();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF1EFE2. This field is constant.
      static xtd::drawing::color control_light();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static xtd::drawing::color control_light_light();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static xtd::drawing::color control_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF004E98. This field is constant.
      static xtd::drawing::color desktop();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
      static xtd::drawing::color gray_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
      static xtd::drawing::color highlight();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static xtd::drawing::color highlight_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
      static xtd::drawing::color hot_track();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
      static xtd::drawing::color inactive_border();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF7A96DF. This field is constant.
      static xtd::drawing::color inactive_caption();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8E4F8. This field is constant.
      static xtd::drawing::color inactive_caption_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE1. This field is constant.
      static xtd::drawing::color info();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static xtd::drawing::color info_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static xtd::drawing::color menu();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static xtd::drawing::color menu_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
      static xtd::drawing::color scroll_bar();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static xtd::drawing::color window();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static xtd::drawing::color window_frame();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static xtd::drawing::color window_text();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
      static xtd::drawing::color button_face();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static xtd::drawing::color button_highlight();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
      static xtd::drawing::color button_shadow();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF3D95FF. This field is constant.
      static xtd::drawing::color gradient_active_caption();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF9DB9EB. This field is constant.
      static xtd::drawing::color gradient_inactive_caption();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
      static xtd::drawing::color menu_bar();
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
      static xtd::drawing::color menu_highlight();

      /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
      static xtd::drawing::color accent();

      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static xtd::drawing::color accent_text();
    };
  }
}
