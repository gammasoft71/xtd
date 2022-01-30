/// @file
/// @brief Contains xtd::forms::style_sheets::border_width class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/iequatable.h>
#include <xtd/ustring.h>
#include "length.h"
#include "../../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The width specifies the width of the borders.
      /// @code
      /// class forms_export_ border_width : public xtd::iequatable<border_width>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_width
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_width : public xtd::iequatable<border_width>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a xtd::forms::style_sheets::border_width object with no xtd::forms::style_sheets::border_width.
        static const border_width empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_width class.
        border_width() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_width class using the supplied xtd::forms::style_sheets::border_width size for all edges.
        /// @param all The number of pixels to be used for xtd::forms::style_sheets::border_width for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        explicit border_width(length all);
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_width class using a separate xtd::forms::style_sheets::border_width size for each edge.
        /// @param left The xtd::forms::style_sheets::border_width size, in pixels, for the left edge.
        /// @param top The xtd::forms::style_sheets::border_width size, in pixels, for the top edge.
        /// @param right The xtd::forms::style_sheets::border_width size, in pixels, for the right edge.
        /// @param bottom The xtd::forms::style_sheets::border_width size, in pixels, for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_width(length left, length top, length right, length bottom);
        /// @}
        
        /// @cond
        border_width(const border_width&) = default;
        border_width& operator=(const border_width&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_width value for all the edges.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_width value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_width values are not equal.
        length all() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_width value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_width, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_width value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_width values are not equal.
        void all(length all) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the bottom edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        length bottom() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the bottom edge.
        /// @param bottom The xtd::forms::style_sheets::border_width, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(length bottom) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the left edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        length left() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the left edge.
        /// @param left The xtd::forms::style_sheets::border_width, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(length left) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the right edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        length right() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the right edge.
        /// @param right The xtd::forms::style_sheets::border_width, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(length right) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the top edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the top edge.
        /// @remarks Setting this value can also alter the all property.
        length top() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the top edge.
        /// @param top The xtd::forms::style_sheets::border_width, in pixels, for the top edge.
        /// @remarks Setting this value can also alter the all property.
        void top(length top) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override;
        bool equals(const border_width& other) const noexcept override;
        /// @}
        
      private:
        bool all_ = true;
        length left_ {3};
        length top_ {3};
        length right_ {3};
        length bottom_ {3};
      };
    }
  }
}
