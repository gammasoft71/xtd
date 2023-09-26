/// @file
/// @brief Contains xtd::forms::style_sheets::length_unit enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The length_unit enum class specifies the units for xtd::forms::style_sheets::length.
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/length_unit> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks CSS has several different units for expressing a length.
      /// @remarks Many CSS properties take "length" values, such as width, margin, padding, font-size, etc.
      /// @remarks <b>Length</b> is a number followed by a length unit, such as 10px, 2em, etc.CSS has several different units for expressing a length.
      /// @par Example
      /// Set different length values, using px (pixels):
      /// @code
      /// control {
      ///   border-width: 3px;
      /// }
      ///
      /// button {
      ///   border-width: 1px;
      ///   border-radius: 5px;
      /// }
      /// @endcode
      /// @note A whitespace cannot appear between the number and the unit. However, if the value is 0, the unit can be omitted.
      /// @remarks For some CSS properties, negative lengths are allowed.
      /// @remarks There are two types of length units: <b>absolute</b> and </b>relative</b>.
      /// @par Absolute lengths
      /// The absolute length units are fixed and a length expressed in any of these will appear as exactly that size.
      /// | Enum class value | Css potfix | Description                  |
      /// | ---------------- | ---------- | ---------------------------- |
      /// | centimeters      | cm         | centimeters                  |
      /// | millimeters      | mm         | millimeters                  |
      /// | inches           | in         | inches (1in = 96px = 2.54cm) |
      /// | pixels           | px         | pixels (1px = 1/96th of 1in) |
      /// | points           | pt         | points (1pt = 1/72 of 1in)   |
      /// | picas            | pc         | picas (1pc = 12 pt)          |
      /// @par Relative lengths
      /// Relative length units specify a length relative to another length property. Relative length units scales better between different rendering mediums.
      /// | Enum class value | Css potfix | Description                                                                               |
      /// | ---------------- | ---------- | ----------------------------------------------------------------------------------------- |
      /// | element          | em         | Relative to the font-size of the element (2em means 2 times the size of the current font) |
      /// | element_x_height | ex         | Relative to the x-height of the current font (rarely used)                                |
      /// | chase            | ch         | Relative to width of the "0" (zero)                                                       |
      /// | root_element     | rem        | Relative to font-size of the root element                                                 |
      /// | viewport_width   | vw         | Relative to 1% of the width of the viewport(*)                                            |
      /// | viewport_height  | vh         | Relative to 1% of the height of the viewport(*)                                           |
      /// | viewport_min     | vmin       | Relative to 1% of viewport's* smaller dimension                                           |
      /// | viewport_max     | vmax       | Relative to 1% of viewport's* larger dimension                                            |
      /// | percent          | %          | Relative to the parent element                                                            |
      /// @Note The element(em) and root_element(rem) units are practical in creating perfectly scalable layout!
      /// (*) Viewport = the bounds of the element. If the viewport is 50cm wide, 1vw = 0.5cm.
      enum class length_unit {
        /// @brief Defines a centimeters unit.
        centimeters,
        /// @brief Defines a millimeters unit.
        millimeters,
        /// @brief Defines a inches unit (1in = 96px = 2.54cm).
        inches,
        /// @brief Defines pixels unit (1px = 1/96th of 1in).
        pixels,
        /// @brief Defines points unit (1pt = 1/72 of 1in).
        points,
        /// @brief Defines a picas unit (1pc = 12 pt).
        picas,
        /// @brief Defines a element unit. Relative to the font-size of the element (2em means 2 times the size of the current font).
        element,
        /// @brief Defines a element_x_height unit. Relative to the x-height of the current font (rarely used).
        element_x_height,
        /// @brief Defines a chase unit. Relative to width of the "0" (zero).
        chase,
        /// @brief Defines a root_element unit. Relative to font-size of the root elementRelative to font-size of the root element.
        root_element,
        /// @brief Defines a viewport_width unit. Relative to 1% of the width of the viewport.
        viewport_width,
        /// @brief Defines a viewport_height unit. Relative to 1% of the height of the viewport.
        viewport_height,
        /// @brief Defines a viewport_min unit. Relative to 1% of viewport's smaller dimension.
        viewport_min,
        /// @brief Defines a viewport_min unit. Relative to 1% of viewport's larger dimension.
        viewport_max,
        /// @brief Defines a percent unit. Relative to the parent element.
        percent,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::style_sheets::length_unit> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::style_sheets::length_unit> {{xtd::forms::style_sheets::length_unit::centimeters, "centimeters"}, {xtd::forms::style_sheets::length_unit::millimeters, "millimeters"}, {xtd::forms::style_sheets::length_unit::inches, "inches"}, {xtd::forms::style_sheets::length_unit::pixels, "pixels"}, {xtd::forms::style_sheets::length_unit::points, "points"}, {xtd::forms::style_sheets::length_unit::picas, "picas"}, {xtd::forms::style_sheets::length_unit::element, "element"}, {xtd::forms::style_sheets::length_unit::element_x_height, "element_x_height"}, {xtd::forms::style_sheets::length_unit::chase, "chase"}, {xtd::forms::style_sheets::length_unit::root_element, "root_element"}, {xtd::forms::style_sheets::length_unit::viewport_width, "viewport_width"}, {xtd::forms::style_sheets::length_unit::viewport_height, "viewport_height"}, {xtd::forms::style_sheets::length_unit::viewport_min, "viewport_min"}, {xtd::forms::style_sheets::length_unit::viewport_max, "viewport_max"}, {xtd::forms::style_sheets::length_unit::percent, "percent"}};}
};
/// @endcond
