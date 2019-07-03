#pragma once
#include "color.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::system_colors class is a xtd::drawing::Color structure that is the color of a Windows display element.
    /// @remarks Better performance is achieved by using the properties of the xtd::drawing::SystemPens or xtd::drawing::SystemBrushes classes rather than creating a new pen or brush based on a value from xtd::drawing::system_colors. For example, if you wanted to get a brush for the face color of a 3-D element, use the SystemBrushes.Control property because it gets a brush that already exists, whereas calling the SolidBrush.#ctor(Color) constructor with a parameter value of system_colors::Control will create a new brush.
    class system_colors {
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
      static const xtd::drawing::color ActiveBorder;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF0054E3. This field is constant.
      static const xtd::drawing::color ActiveCaption;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static const xtd::drawing::color ActiveCaptionText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF808080. This field is constant.
      static const xtd::drawing::color AppWorkspace;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
      static const xtd::drawing::color Control;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
      static const xtd::drawing::color ControlDark;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF716F64. This field is constant.
      static const xtd::drawing::color ControlDarkDark;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFF1EFE2. This field is constant.
      static const xtd::drawing::color ControlLight;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static const xtd::drawing::color ControlLightLight;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static const xtd::drawing::color ControlText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF004E98. This field is constant.
      static const xtd::drawing::color Desktop;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
      static const xtd::drawing::color GrayText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
      static const xtd::drawing::color Highlight;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static const xtd::drawing::color HighlightText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000080. This field is constant.
      static const xtd::drawing::color HotTrack;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
      static const xtd::drawing::color InactiveBorder;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF7A96DF. This field is constant.
      static const xtd::drawing::color InactiveCaption;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD8E4F8. This field is constant.
      static const xtd::drawing::color InactiveCaptionText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFE1. This field is constant.
      static const xtd::drawing::color Info;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static const xtd::drawing::color InfoText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static const xtd::drawing::color Menu;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static const xtd::drawing::color MenuText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFD4D0C8. This field is constant.
      static const xtd::drawing::color ScrollBar;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static const xtd::drawing::color Window;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static const xtd::drawing::color WindowFrame;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF000000. This field is constant.
      static const xtd::drawing::color WindowText;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
      static const xtd::drawing::color ButtonFace;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFFFFFFF. This field is constant.
      static const xtd::drawing::color ButtonHighlight;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFACA899. This field is constant.
      static const xtd::drawing::color ButtonShadow;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF3D95FF. This field is constant.
      static const xtd::drawing::color GradientActiveCaption;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF9DB9EB. This field is constant.
      static const xtd::drawing::color GradientInactiveCaption;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFFECE9D8. This field is constant.
      static const xtd::drawing::color MenuBar;
      
      /// @brief Gets a system-defined color that has an ARGB value of 0xFF316AC5. This field is constant.
      static const xtd::drawing::color MenuHighlight;
      
    private:
      system_colors() = delete;
    };
  }
}
