/// @file
/// @brief Contains xtd::forms::style_sheets::length class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.h"
#include "length_unit.h"
#include <xtd/drawing/rectangle>
#include <xtd/iequatable>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::length specifies the legth and unit of many properties of the xtd::forms::style_sheets::ibox_model.
      /// @code
      /// class forms_export_ length : public xtd::iequatable<length>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::length
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/lenght> @endcode
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
      class forms_export_ length : public xtd::iequatable<length>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a xtd::forms::style_sheets::length object with 0 pixels.
        static const length empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::length class.
        length() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::length class with specifed value in pixels.
        /// @param value The number of pixels to be used for xtd::forms::style_sheets::length.
        explicit length(double value);
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::length class with specifed value and unit.
        /// @param value The number of unit to be used for xtd::forms::style_sheets::length.
        /// @param unit One of xtd::forms::style_sheets::legth_unit values.
        length(double value, length_unit unit);
        /// @}
        
        /// @cond
        length(const length&) = default;
        length& operator =(const length&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::length value.
        /// @return The value of the xtd::forms::style_sheets::length.
        double value() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::length value.
        /// @param value The value of the xtd::forms::style_sheets::length.
        void value(double value) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::length unit.
        /// @return One of xtd::forms::style_sheets::legth_unit values.
        length_unit unit() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::length unit.
        /// @param value One of xtd::forms::style_sheets::legth_unit values.
        void unit(length_unit value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const length& other) const noexcept override;
        
        /// @brief Gets the legnth in pixels.
        /// @param rect The xtd::drawing::rectangle is used to compute the length for relative length units.
        /// @return The legnth in pixels.
        int32 get_pixels(const xtd::drawing::rectangle& rect) const noexcept;
        
        xtd::ustring to_string() const noexcept override;
        /// @}
        
      private:
        double value_ = -1;
        length_unit unit_ = length_unit::pixels;
      };
    }
  }
}
