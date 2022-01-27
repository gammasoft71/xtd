/// @file
/// @brief Contains xtd::forms::style_sheets::border_color_property class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
#include "color_property.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::border_color_property is used to set the color of the borders.
      /// @code
      /// class forms_export_ border_color_property : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_color_property
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_color_property : public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::border_color_property object.
        static const border_color_property empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color_property class.
        border_color_property() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color_property class using the supplied border_color_property for all edges.
        /// @param all The xtd::forms::style_sheets::color_data to be used for border_color_property for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        border_color_property(color_property all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {}
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color_property class using a separate border_color_property for each edge.
        /// @param left The border_color_property for the left edge.
        /// @param top The border_color_property for the top edge.
        /// @param right The border_color_property for the right edge.
        /// @param bottom The border_color_property for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_color_property(color_property left, color_property top, color_property right, color_property bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {}
        /// @}
        
        /// @cond
        border_color_property(const border_color_property&) = default;
        border_color_property& operator=(const border_color_property&) = default;
        bool operator==(const border_color_property& value) {return all_ == value.all_ && left_ == value.left_ && top_ == value.top_ && right_ == value.right_ && bottom_ == value.bottom_;}
        bool operator!=(const border_color_property& value) {return !operator==(value);}
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for all the edges.
        /// @return The xtd::forms::style_sheets::border_color_property for all edges if the same; otherwise, xtd::forms::style_sheets::color_data::empty.
        /// @remarks When retrieving this property, if all the edges use the same border_color_property value, then this common value is returned. Otherwise, xtd::forms::style_sheets::color_data::empty is returned to indicate that all the xtd::forms::style_sheets::border_color_property values are not equal.
        color_property all() const {return all_ ? top_ : color_property::empty;}
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_color_property for all edges if the same; otherwise, xtd::forms::style_sheets::color_data::empty.
        /// @remarks When retrieving this property, if all the edges use the same border_color_property value, then this common value is returned. Otherwise, xtd::forms::style_sheets::color_data::empty is returned to indicate that all the xtd::forms::style_sheets::border_color_property values are not equal.
        void all(color_property all) {
          if (!all_ || left_ != all) {
            all_ = true;
            left_ = top_ = right_ = bottom_ = all;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the bottom edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        color_property bottom() const {return bottom_;}
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the bottom edge.
        /// @param bottom The xtd::forms::style_sheets::border_color_property for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(color_property bottom) {
          if (all_ || bottom_ != bottom) {
            all_ = false;
            bottom_ = bottom;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the left edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the left edge.
        /// @remarks Setting this value can also alter the all property.
        color_property left() const {return left_;}
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the left edge.
        /// @param left The xtd::forms::style_sheets::border_color_property for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(color_property left) {
          if (all_ || left_ != left) {
            all_ = false;
            left_ = left;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the right edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the right edge.
        /// @remarks Setting this value can also alter the all property.
        color_property right() const {return right_;}
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the right edge.
        /// @param right The xtd::forms::style_sheets::border_color_property for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(color_property right) {
          if (all_ || right_ != right) {
            all_ = false;
            right_ = right;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the top edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the top edge.
        /// @remarks Setting this value can also alter the all property.
        color_property top() const {return top_;}
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the top edge.
        /// @param top The xtd::forms::style_sheets::border_color_property for the top edge.
        /// @remarks Setting this value can also alter the all property.
        void top(color_property top) {
          if (all_ || top_ != top) {
            all_ = false;
            top_ = top;
          }
        }
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Returns a string that represents the current xtd::forms::style_sheets::border_color_property.
        /// @return A string that represents the current xtd::forms::style_sheets::border_color_property.
        /// @remarks This method returns a string containing the labeled values of the xtd::forms::style_sheets::border_color_property for all four edges.
        xtd::ustring to_string() const noexcept override {return xtd::ustring::format("border_color_property [all={}, left={}, top={}, right={}, bottom={}]", all_, left_, top_, right_, bottom_);}
        /// @}
        
        /// @cond
        bool operator==(const border_color_property& p) const {return all_ == p.all_ && left_ == p.left_ && top_ == p.top_ && right_ == p.right_ && bottom_ == p.bottom_;}
        friend std::ostream& operator<<(std::ostream& os, const xtd::forms::style_sheets::border_color_property& border_color_property) noexcept {return os << border_color_property.to_string();}
        /// @endcond
        
      private:
        bool all_ = true;
        color_property left_ {xtd::drawing::color::black};
        color_property top_ {xtd::drawing::color::black};
        color_property right_ {xtd::drawing::color::black};
        color_property bottom_ {xtd::drawing::color::black};
      };
    }
  }
}
