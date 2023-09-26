/// @file
/// @brief Contains xtd::forms::style_sheets::lengths class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export"
#include "length"
#include <xtd/iequatable>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The length specifies the length of the borders.
      /// @code
      /// class forms_export_ lengths : public xtd::iequatable<lengths>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::lengths
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/lengths> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ lengths : public xtd::iequatable<lengths>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a xtd::forms::style_sheets::lengths object with no xtd::forms::style_sheets::lengths.
        static const lengths empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::lengths class.
        lengths() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::lengths class using the supplied xtd::forms::style_sheets::lengths size for all edges.
        /// @param all The number of pixels to be used for xtd::forms::style_sheets::lengths for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        explicit lengths(xtd::forms::style_sheets::length all);
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::lengths class using a separate xtd::forms::style_sheets::lengths size for each edge.
        /// @param left The xtd::forms::style_sheets::lengths size, in pixels, for the left edge.
        /// @param top The xtd::forms::style_sheets::lengths size, in pixels, for the top edge.
        /// @param right The xtd::forms::style_sheets::lengths size, in pixels, for the right edge.
        /// @param bottom The xtd::forms::style_sheets::lengths size, in pixels, for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        lengths(xtd::forms::style_sheets::length left, xtd::forms::style_sheets::length top, xtd::forms::style_sheets::length right, xtd::forms::style_sheets::length bottom);
        /// @}
        
        /// @cond
        lengths(const lengths&) = default;
        lengths& operator =(const lengths&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::lengths value for all the edges.
        /// @return The xtd::forms::style_sheets::lengths, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::lengths value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::lengths values are not equal.
        xtd::forms::style_sheets::length all() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::lengths value for all the edges.
        /// @param all The xtd::forms::style_sheets::lengths, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::lengths value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::lengths values are not equal.
        void all(xtd::forms::style_sheets::length all) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::lengths value for the bottom edge.
        /// @return The xtd::forms::style_sheets::lengths, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length bottom() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::lengths value for the bottom edge.
        /// @param bottom The xtd::forms::style_sheets::lengths, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(xtd::forms::style_sheets::length bottom) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::lengths value for the left edge.
        /// @return The xtd::forms::style_sheets::lengths, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length left() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::lengths value for the left edge.
        /// @param left The xtd::forms::style_sheets::lengths, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(xtd::forms::style_sheets::length left) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::lengths value for the right edge.
        /// @return The xtd::forms::style_sheets::lengths, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length right() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::lengths value for the right edge.
        /// @param right The xtd::forms::style_sheets::lengths, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(xtd::forms::style_sheets::length right) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::lengths value for the top edge.
        /// @return The xtd::forms::style_sheets::lengths, in pixels, for the top edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length top() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::lengths value for the top edge.
        /// @param top The xtd::forms::style_sheets::lengths, in pixels, for the top edge.
        /// @remarks Setting this value can also alter the all property.
        void top(xtd::forms::style_sheets::length top) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const lengths& other) const noexcept override;
        xtd::ustring to_string() const noexcept override;
        /// @}
        
      private:
        bool all_ = true;
        xtd::forms::style_sheets::length left_ {0};
        xtd::forms::style_sheets::length top_ {0};
        xtd::forms::style_sheets::length right_ {0};
        xtd::forms::style_sheets::length bottom_ {0};
      };
    }
  }
}
