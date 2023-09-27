/// @file
/// @brief Contains xtd::drawing::graphics_unit enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the unit of measure for the given data. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @par Namespace
    /// xtd::drawing
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
      /// @brief Specifies the document unit (1/300 inch) as the unit of measure.
      document = 5,
      /// @brief Specifies the millimeter as the unit of measure.
      millimeter = 6
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::drawing::graphics_unit> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::drawing::graphics_unit> {{xtd::drawing::graphics_unit::world, "world"}, {xtd::drawing::graphics_unit::display, "display"}, {xtd::drawing::graphics_unit::pixel, "pixel"}, {xtd::drawing::graphics_unit::point, "point"}, {xtd::drawing::graphics_unit::inch, "inch"}, {xtd::drawing::graphics_unit::document, "document"}, {xtd::drawing::graphics_unit::millimeter, "millimeter"}};}
};
/// @endcond
