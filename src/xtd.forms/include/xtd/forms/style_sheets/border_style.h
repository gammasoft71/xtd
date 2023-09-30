/// @file
/// @brief Contains xtd::forms::style_sheets::border_style class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.h"
#include "border_type.h"
#include <xtd/iequatable>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The style specifies what kind of borders to display.
      /// @code
      /// class forms_export_ border_style : public xtd::iequatable<border_style>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_style
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/border_style> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_style : public xtd::iequatable<border_style>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a xtd::forms::style_sheets::border_style object with no xtd::forms::style_sheets::border_style.
        static const border_style empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_style class.
        border_style() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_style class using the supplied xtd::forms::style_sheets::border_style size for all edges.
        /// @param all The number of pixels to be used for xtd::forms::style_sheets::border_style for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        explicit border_style(border_type all);
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_style class using a separate xtd::forms::style_sheets::border_style size for each edge.
        /// @param left The xtd::forms::style_sheets::border_style size for the left edge.
        /// @param top The xtd::forms::style_sheets::border_style size for the top edge.
        /// @param right The xtd::forms::style_sheets::border_style size for the right edge.
        /// @param bottom The xtd::forms::style_sheets::border_style size for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_style(border_type left, border_type top, border_type right, border_type bottom);
        /// @}
        
        /// @cond
        border_style(const border_style&) = default;
        border_style& operator =(const border_style&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_style value for all the edges.
        /// @return The xtd::forms::style_sheets::border_style for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_style value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_style values are not equal.
        border_type all() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_style value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_style for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_style value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_style values are not equal.
        void all(border_type all) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_style value for the bottom edge.
        /// @return The xtd::forms::style_sheets::border_style for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        border_type bottom() const;
        /// @brief Sets the xtd::forms::style_sheets::border_style value for the bottom edge.
        /// @param bottom The xtd::f noexceptorms::style_sheets::border_style for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(border_type bottom) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_style value for the left edge.
        /// @return The xtd::forms::style_sheets::border_style for the left edge.
        /// @remarks Setting this value can also alter the all property.
        border_type left() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_style value for the left edge.
        /// @param left The xtd::forms::style_sheets::border_style for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(border_type left) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_style value for the right edge.
        /// @return The xtd::forms::style_sheets::border_style for the right edge.
        /// @remarks Setting this value can also alter the all property.
        border_type right() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_style value for the right edge.
        /// @param right The xtd::forms::style_sheets::border_style for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(border_type right);
        
        /// @brief Gets the xtd::forms::style_sheets::border_style value for the top edge.
        /// @return The xtd::forms::style_sheets::border_style for the top edge.
        /// @remarks Setting this value can also alter the all property.
        border_type top() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_style value for the top edge.
        /// @param top The xtd::forms::style_sheets::border_style for the top edge.
        /// @remarks Setting this value can also alter the all property.
        void top(border_type top) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const border_style& other) const noexcept override;
        /// @}
        
      private:
        bool all_ = true;
        border_type left_ = border_type::none;
        border_type top_ = border_type::none;
        border_type right_ = border_type::none;
        border_type bottom_ = border_type::none;
      };
    }
  }
}
