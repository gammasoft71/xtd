/// @file
/// @brief Contains xtd::drawing::graphics_unit enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the unit of measure for the given data. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    enum class graphics_unit {
      /// @brief Specifies the world coordinate system unit as the unit of measure.
      world = 0,
      /// @brief Specifies 1/75 inch as the unit of measure.
      display = 1,
      /// @brief Specifies a device pixel as the unit of measure.
      pixel = 2,
      /// @brief Specifies a printer's point (1/72 inch) as the unit of measure.
      point = 3,
      /// @brief Specifies the inch as the unit of measure.
      inch = 4,
      /// @brief Specifes the document unit (1/300 inch) as the unit of measure.
      document = 5,
      /// @brief Specifies the millimeter as the unit of measure.
      millimeter = 6
    };

    /// @cond
   inline std::ostream& operator<<(std::ostream& os, graphics_unit value) {return os << xtd::to_string(value, {{graphics_unit::world, "world"}, {graphics_unit::display, "display"}, {graphics_unit::pixel, "pixel"}, {graphics_unit::point, "point"}, {graphics_unit::inch, "inch"}, {graphics_unit::document, "document"}, {graphics_unit::millimeter, "millimeter"}});}
    inline std::wostream& operator<<(std::wostream& os, graphics_unit value) {return os << xtd::to_string(value, {{graphics_unit::world, L"world"}, {graphics_unit::display, L"display"}, {graphics_unit::pixel, L"pixel"}, {graphics_unit::point, L"point"}, {graphics_unit::inch, L"inch"}, {graphics_unit::document, L"document"}, {graphics_unit::millimeter, L"millimeter"}});}
    /// @endcond
  }
}
