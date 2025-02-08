/// @file
/// @brief Contains xtd::drawing::text::font_collection class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../font_family.hpp"
#include <xtd/array>
#include <xtd/object>

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
      /// @remarks The xtd::drawing::text::font_collection allows you to get a list of the font families contained in the collection with its xtd::drawing::text::font_collection::families property.
      class font_collection : public object {
      public:
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the array of xtd::drawing::text::font_family objects associated with this xtd::drawing::text::font_collection.
        /// @return xtd::array<xtd::drawing::text::font_family> An array of xtd::drawing::text::font_family objects.
        const xtd::array<font_family>& families() const noexcept {return families_;}
        /// @}
        
      protected:
        /// @brief Initialise new instance of xtd::drawing::text::font_collection class.
        font_collection() = default;
        
        /// @cond
        xtd::array<font_family> families_;
        /// @endcond
      };
    }
  }
}
