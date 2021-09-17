/// @file
/// @brief Contains xtd::drawing::text::generic_font_families enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::text namespace provides advanced GDI+ typography functionality.
    namespace text {
      /// @brief Specifies a generic font_family object.
      /// @par Namespace
      /// xtd::drawing::text
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing
      enum class generic_font_families {
        /// @brief A generic Serif font_family object.
        serif = 0,
        /// @brief A generic Sans Serif font_family object.
        sans_serif = 1,
        /// @brief A generic Monospace font_family object.
        monospace = 2
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, generic_font_families value) {return os << xtd::to_string(value, {{generic_font_families::serif, "serif"}, {generic_font_families::sans_serif, "sans_serif"}, {generic_font_families::monospace, "italic"}});}
      inline std::wostream& operator<<(std::wostream& os, generic_font_families value) {return os << xtd::to_string(value, {{generic_font_families::serif, L"serif"}, {generic_font_families::sans_serif, L"sans_serif"}, {generic_font_families::monospace, L"italic"}});}
      /// @endcond
    }
  }
}
