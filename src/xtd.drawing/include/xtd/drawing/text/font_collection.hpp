/// @file
/// @brief Contains xtd::drawing::text::font_collection class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../font_family.hpp"
#include <xtd/object>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::text namespace provides advanced GDI+ typography functionality.
    namespace text {
      /// @brief Provides a base class for installed and private font collections.
      /// @par Namespace
      /// xtd::drawing::text
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing fonts
      /// @remarks The xtd::drawing::text::font_collection allows you to get a list of the font families contained in the collection with its families property. For additional information on fonts and text, including example code, see Using fonts and text.
      class font_collection : public object {
      public:
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the array of FontFamily objects associated with this FontCollection.
        /// @return Array<FontFamily> An array of FontFamily objects.
        const std::vector<font_family>& families() const noexcept {return families_;}
        /// @}
        
      protected:
        /// @brief Initialise new instance of font_collection class.
        font_collection() {}
        
        /// @cond
        std::vector<font_family> families_;
        /// @endcond
      };
    }
  }
}
