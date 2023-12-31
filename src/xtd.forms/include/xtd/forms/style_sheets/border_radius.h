/// @file
/// @brief Contains xtd::forms::style_sheets::border_radius class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.h"
#include "length.h"
#include <xtd/iequatable>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The radius is used to add rounded borders to an element.
      /// @code
      /// class forms_export_ border_radius : public xtd::iequatable<border_radius>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_radius
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/brer_rzdius> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_radius : public xtd::iequatable<border_radius>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::border_radius object.
        static const border_radius empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_radius class.
        border_radius() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_radius class using the supplied xtd::forms::style_sheets::border_radius size for all edges.
        /// @param all The number of pixels to be used for xtd::forms::style_sheets::border_radius for all edges.
        /// @remarks This constructor sets the bottom_left, top_left, bottom_right, top_right and all properties to the value of the all parameter.
        explicit border_radius(xtd::forms::style_sheets::length all);
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_radius class using a separate xtd::forms::style_sheets::border_radius size for each edge.
        /// @param top_left The xtd::forms::style_sheets::border_radius size, in pixels, for the top_left edge.
        /// @param top_right The xtd::forms::style_sheets::border_radius size, in pixels, for the top_right edge.
        /// @param bottom_right The xtd::forms::style_sheets::border_radius size, in pixels, for the bottom_right edge.
        /// @param bottom_left The xtd::forms::style_sheets::border_radius size, in pixels, for the bottom_left edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_radius(xtd::forms::style_sheets::length top_left, xtd::forms::style_sheets::length top_right, xtd::forms::style_sheets::length bottom_right, xtd::forms::style_sheets::length bottom_left);
        /// @}
        
        /// @cond
        border_radius(const border_radius&) = default;
        border_radius& operator =(const border_radius&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_radius value for all the edges.
        /// @return The xtd::forms::style_sheets::border_radius, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_radius value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_radius values are not equal.
        xtd::forms::style_sheets::length all() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_radius value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_radius, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_radius value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_radius values are not equal.
        void all(xtd::forms::style_sheets::length all) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius value for the bottom_right edge.
        /// @return The xtd::forms::style_sheets::border_radius, in pixels, for the bottom_right edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length bottom_right() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_radius value for the bottom_right edge.
        /// @param bottom_right The xtd::forms::style_sheets::border_radius, in pixels, for the bottom_right edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom_right(xtd::forms::style_sheets::length bottom_right) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius value for the top_left edge.
        /// @return The xtd::forms::style_sheets::border_radius, in pixels, for the top_left edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length top_left() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_radius value for the top_left edge.
        /// @param top_left The xtd::forms::style_sheets::border_radius, in pixels, for the top_left edge.
        /// @remarks Setting this value can also alter the all property.
        void top_left(xtd::forms::style_sheets::length top_left) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius value for the bottom_left edge.
        /// @return The xtd::forms::style_sheets::border_radius, in pixels, for the bottom_left edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length bottom_left() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_radius value for the bottom_left edge.
        /// @param bottom_left The xtd::forms::style_sheets::border_radius, in pixels, for the bottom_left edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom_left(xtd::forms::style_sheets::length bottom_left) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius value for the top_right edge.
        /// @return The xtd::forms::style_sheets::border_radius, in pixels, for the top_right edge.
        /// @remarks Setting this value can also alter the all property.
        xtd::forms::style_sheets::length top_right() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_radius value for the top_right edge.
        /// @param top_right The xtd::forms::style_sheets::border_radius, in pixels, for the top_right edge.
        /// @remarks Setting this value can also alter the all property.
        void top_right(xtd::forms::style_sheets::length top_right) noexcept;
        
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const border_radius& other) const noexcept override;
        /// @}
        
      private:
        bool all_ = true;
        xtd::forms::style_sheets::length top_left_ {0};
        xtd::forms::style_sheets::length top_right_ {0};
        xtd::forms::style_sheets::length bottom_left_ {0};
        xtd::forms::style_sheets::length bottom_right_ {0};
      };
    }
  }
}
