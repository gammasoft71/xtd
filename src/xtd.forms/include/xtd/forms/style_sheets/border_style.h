/// @file
/// @brief Contains xtd::forms::style_sheets::color_style enum class.
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
      class forms_export_ border_style : public object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a border_style object with no border_style.
        static const border_style empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the border_style class.
        border_style() = default;
        
        /// @brief Initializes a new instance of the border_style class using the supplied border_style size for all edges.
        /// @param all The number of pixels to be used for border_style for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        border_style(border_type all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {}
        
        /// @brief Initializes a new instance of the border_style class using a separate border_style size for each edge.
        /// @param left The border_style size, in pixels, for the left edge.
        /// @param top The border_style size, in pixels, for the top edge.
        /// @param right The border_style size, in pixels, for the right edge.
        /// @param bottom The border_style size, in pixels, for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_style(border_type left, border_type top, border_type right, border_type bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {}
        /// @}
        
        /// @cond
        border_style(const border_style&) = default;
        border_style& operator=(const border_style&) = default;
        bool operator==(const border_style& value) {return all_ == value.all_ && left_ == value.left_ && top_ == value.top_ && right_ == value.right_ && bottom_ == value.bottom_;}
        bool operator!=(const border_style& value) {return !operator==(value);}
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the border_style value for all the edges.
        /// @return The border_style, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same border_style value, then this common value is returned. Otherwise, -1 is returned to indicate that all the border_style values are not equal.
        border_type all() const {return all_ ? top_ : border_type();}
        /// @brief Sets the border_style value for all the edges.
        /// @param all The border_style, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same border_style value, then this common value is returned. Otherwise, -1 is returned to indicate that all the border_style values are not equal.
        void all(border_type all) {
          if (!all_ || left_ != all) {
            all_ = true;
            left_ = top_ = right_ = bottom_ = all;
          }
        }
        
        /// @brief Gets the border_style value for the bottom edge.
        /// @return The border_style, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        border_type bottom() const {return bottom_;}
        /// @brief Sets the border_style value for the bottom edge.
        /// @param bottom The border_style, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(border_type bottom) {
          if (all_ || bottom_ != bottom) {
            all_ = false;
            bottom_ = bottom;
          }
        }
        
        /// @brief Gets the border_style value for the left edge.
        /// @return The border_style, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        border_type left() const {return left_;}
        /// @brief Sets the border_style value for the left edge.
        /// @param left The border_style, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(border_type left) {
          if (all_ || left_ != left) {
            all_ = false;
            left_ = left;
          }
        }
        
        /// @brief Gets the border_style value for the right edge.
        /// @return The border_style, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        border_type right() const {return right_;}
        /// @brief Sets the border_style value for the right edge.
        /// @param right The border_style, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(border_type right) {
          if (all_ || right_ != right) {
            all_ = false;
            right_ = right;
          }
        }
        
        /// @brief Gets the border_style value for the top edge.
        /// @return The border_style, in pixels, for the top edge.
        /// @remarks Setting this value can also alter the all property.
        border_type top() const {return top_;}
        /// @brief Sets the border_style value for the top edge.
        /// @param top The border_style, in pixels, for the top edge.
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
        /// @brief Returns a string that represents the current border_style.
        /// @return A string that represents the current border_style.
        /// @remarks This method returns a string containing the labeled values of the border_style for all four edges.
        xtd::ustring to_string() const noexcept override {return xtd::ustring::format("border_style [all={}, left={}, top={}, right={}, bottom={}]", all_, left_, top_, right_, bottom_);}
        /// @}
        
        /// @cond
        bool operator==(const border_style& p) const {return all_ == p.all_ && left_ == p.left_ && top_ == p.top_ && right_ == p.right_ && bottom_ == p.bottom_;}
        friend std::ostream& operator<<(std::ostream& os, const xtd::forms::style_sheets::border_style& border_style) noexcept {return os << border_style.to_string();}
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
