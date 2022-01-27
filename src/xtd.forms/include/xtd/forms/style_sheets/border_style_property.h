/// @file
/// @brief Contains xtd::forms::style_sheets::border_style_property class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
#include "border_type.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The style specifies what kind of borders to display.
      /// @code
      /// class forms_export_ border_style_property : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_style_property
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_style_property : public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a xtd::forms::style_sheets::border_style_property object with no xtd::forms::style_sheets::border_style_property.
        static const border_style_property empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_style_property class.
        border_style_property() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_style_property class using the supplied xtd::forms::style_sheets::border_style_property size for all edges.
        /// @param all The number of pixels to be used for xtd::forms::style_sheets::border_style_property for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        border_style_property(border_type all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {}
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_style_property class using a separate xtd::forms::style_sheets::border_style_property size for each edge.
        /// @param left The xtd::forms::style_sheets::border_style_property size for the left edge.
        /// @param top The xtd::forms::style_sheets::border_style_property size for the top edge.
        /// @param right The xtd::forms::style_sheets::border_style_property size for the right edge.
        /// @param bottom The xtd::forms::style_sheets::border_style_property size for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_style_property(border_type left, border_type top, border_type right, border_type bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {}
        /// @}
        
        /// @cond
        border_style_property(const border_style_property&) = default;
        border_style_property& operator=(const border_style_property&) = default;
        bool operator==(const border_style_property& value) {return all_ == value.all_ && left_ == value.left_ && top_ == value.top_ && right_ == value.right_ && bottom_ == value.bottom_;}
        bool operator!=(const border_style_property& value) {return !operator==(value);}
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_style_property value for all the edges.
        /// @return The xtd::forms::style_sheets::border_style_property for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_style_property value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_style_property values are not equal.
        border_type all() const {return all_ ? top_ : border_type();}
        /// @brief Sets the xtd::forms::style_sheets::border_style_property value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_style_property for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_style_property value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_style_property values are not equal.
        void all(border_type all) {
          if (!all_ || left_ != all) {
            all_ = true;
            left_ = top_ = right_ = bottom_ = all;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_style_property value for the bottom edge.
        /// @return The xtd::forms::style_sheets::border_style_property for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        border_type bottom() const {return bottom_;}
        /// @brief Sets the xtd::forms::style_sheets::border_style_property value for the bottom edge.
        /// @param bottom The xtd::forms::style_sheets::border_style_property for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(border_type bottom) {
          if (all_ || bottom_ != bottom) {
            all_ = false;
            bottom_ = bottom;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_style_property value for the left edge.
        /// @return The xtd::forms::style_sheets::border_style_property for the left edge.
        /// @remarks Setting this value can also alter the all property.
        border_type left() const {return left_;}
        /// @brief Sets the xtd::forms::style_sheets::border_style_property value for the left edge.
        /// @param left The xtd::forms::style_sheets::border_style_property for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(border_type left) {
          if (all_ || left_ != left) {
            all_ = false;
            left_ = left;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_style_property value for the right edge.
        /// @return The xtd::forms::style_sheets::border_style_property for the right edge.
        /// @remarks Setting this value can also alter the all property.
        border_type right() const {return right_;}
        /// @brief Sets the xtd::forms::style_sheets::border_style_property value for the right edge.
        /// @param right The xtd::forms::style_sheets::border_style_property for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(border_type right) {
          if (all_ || right_ != right) {
            all_ = false;
            right_ = right;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_style_property value for the top edge.
        /// @return The xtd::forms::style_sheets::border_style_property for the top edge.
        /// @remarks Setting this value can also alter the all property.
        border_type top() const {return top_;}
        /// @brief Sets the xtd::forms::style_sheets::border_style_property value for the top edge.
        /// @param top The xtd::forms::style_sheets::border_style_property for the top edge.
        /// @remarks Setting this value can also alter the all property.
        void top(border_type top) {
          if (all_ || top_ != top) {
            all_ = false;
            top_ = top;
          }
        }
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Returns a string that represents the current xtd::forms::style_sheets::border_style_property.
        /// @return A string that represents the current xtd::forms::style_sheets::border_style_property.
        /// @remarks This method returns a string containing the labeled values of the xtd::forms::style_sheets::border_style_property for all four edges.
        xtd::ustring to_string() const noexcept override {return xtd::ustring::format("border_style_property [all={}, left={}, top={}, right={}, bottom={}]", all_, left_, top_, right_, bottom_);}
        /// @}
        
        /// @cond
        bool operator==(const border_style_property& p) const {return all_ == p.all_ && left_ == p.left_ && top_ == p.top_ && right_ == p.right_ && bottom_ == p.bottom_;}
        friend std::ostream& operator<<(std::ostream& os, const xtd::forms::style_sheets::border_style_property& border_style_property) noexcept {return os << border_style_property.to_string();}
        /// @endcond
        
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
