/// @file
/// @brief Contains xtd::drawing::text::private_font_collection class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <vector>
#include <xtd/ustring.h>
#include "../../drawing_export.h"
#include "font_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::text namespace provides advanced GDI+ typography functionality.
    namespace text {
      /// @brief Provides a collection of font families built from font files that are provided by the client application.
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      /// @remarks The xtd::drawing::text::private_font_collection class allows applications to install a private version of an existing font without the requirement to replace the system version of the font. For example, GDI+ can create a private version of the Arial font in addition to the Arial font that the system uses. xtd::drawing::text::private_font_collection can also be used to install fonts that do not exist in the operating system. This is a temporary font install that does not affect the system-installed collection. To see the installed collection, use the xtd::drawing::text::installed_font_collection class.
      class drawing_export_ private_font_collection final : public font_collection {
      public:
        /// @brief Initializes a new instance of the xtd::drawing::text::private_font_collection class.
        private_font_collection();
        
        /// @brief Adds a font from the specified file to this xtd::drawing::text::private_font_collection.
        /// @param filename A string that contains the file name of the font to add.
        /// @exception std::invalid_argument The specified font is not supported or the font file cannot be found.
        void add_font_file(const xtd::ustring& filename);
        
        /// @brief Adds a font contained in system memory to this td::drawing::text::private_font_collection.
        /// @param memory The memory address of the font to add.
        /// @param length The memory length of the font to add.
        /// @remarks To use the memory font, text on a control must be rendered with GDI+. Use the set_compatible_text_rendering_default method, passing true, to set GDI+ rendering on the application, or on individual controls by setting the control's use_compatible_text_rendering property to true. Some controls cannot be rendered with GDI+.
        void add_memory_font(intptr_t memory, size_t length);
      };
    }
  }
}
