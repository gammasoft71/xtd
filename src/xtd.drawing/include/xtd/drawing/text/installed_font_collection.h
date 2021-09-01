/// @file
/// @brief Contains xtd::drawing::text::installed_font_collection class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include "../../drawing_export.h"
#include "font_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::text namespace provides advanced GDI+ typography functionality.
    namespace text {
      /// @brief Represents the fonts installed on the system. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::text
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks The xtd::drawing::text::installed_font_collection allows you to get a list of fonts families that are installed on the computer running the application with its Families property. For additional information on fonts and text, including example code, see Using fonts and text.
      /// @remarks Do not use the xtd::drawing::text::installed_font_collection class to install a font to Windows, macOS or linux. Instead use the GDI add_font_resource function. An xtd::drawing::text::installed_font_collection object sees only fonts that are installed in Windows before the object is created.
      class drawing_export_ installed_font_collection final : public font_collection {
      public:
        /// @brief Initializes a new instance of the xtd::drawing::text::installed_font_collection class.
        installed_font_collection();
      };
    }
  }
}
