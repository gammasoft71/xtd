#pragma once
#include <vector>
#include <xtd/xtd.strings>
#include "../font_family.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::text namespace provides advanced GDI+ typography functionality.
    namespace text {
      /// @brief Provides a base class for installed and private font collections.
      /// @remarks The xtd::drawing::text::font_collection allows you to get a list of the font families contained in the collection with its families property. For additional information on fonts and text, including example code, see Using fonts and text.
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      class font_collection {
      public:
        /// @brief Gets the array of FontFamily objects associated with this FontCollection.
        /// @return Array<FontFamily> An array of FontFamily objects.
        const std::vector<font_family>& families() const {return this->families_;}
        
        /// @cond
      protected:
        font_collection() {}

        std::vector<font_family> families_;
        /// @endcond
      };
    }
  }
}
