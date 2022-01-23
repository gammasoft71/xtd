/// @file
/// @brief Contains xtd::forms::style_sheets::border_radius class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
#include "color_data.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      class forms_export_ border_radius : public object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a Padding object with no border_radius.
        static const border_radius empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the border_radius class.
        border_radius() = default;
        
        /// @brief Initializes a new instance of the border_radius class using the supplied border_radius size for all edges.
        /// @param all The number of pixels to be used for border_radius for all edges.
        /// @remarks This constructor sets the bottom_left, top_left, bottom_right, top_right and all properties to the value of the all parameter.
        border_radius(int all) : all_(true), top_left_(all), top_right_(all), bottom_left_(all), bottom_right_(all) {}
        
        /// @brief Initializes a new instance of the border_radius class using a separate border_radius size for each edge.
        /// @param top_left The border_radius size, in pixels, for the top_left edge.
        /// @param top_right The border_radius size, in pixels, for the top_right edge.
        /// @param bottom_left The border_radius size, in pixels, for the bottom_left edge.
        /// @param bottom_right The border_radius size, in pixels, for the bottom_right edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_radius(int top_left, int top_right, int bottom_left, int bottom_right) : all_(top_left == top_right && top_left == bottom_left && top_left == bottom_right), top_left_(top_left), top_right_(top_right), bottom_left_(bottom_left), bottom_right_(bottom_right) {}
        /// @}
        
        /// @cond
        border_radius(const border_radius&) = default;
        border_radius& operator=(const border_radius&) = default;
        bool operator==(const border_radius& value) {return all_ == value.all_ && top_left_ == value.top_left_ && top_right_ == value.top_right_ && bottom_left_ == value.bottom_left_ && bottom_right_ == value.bottom_right_;}
        bool operator!=(const border_radius& value) {return !operator==(value);}
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the border_radius value for all the edges.
        /// @return The border_radius, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same border_radius value, then this common value is returned. Otherwise, -1 is returned to indicate that all the border_radius values are not equal.
        int all() const {return all_ ? top_right_ : -1;}
        /// @brief Sets the border_radius value for all the edges.
        /// @param all The border_radius, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same border_radius value, then this common value is returned. Otherwise, -1 is returned to indicate that all the border_radius values are not equal.
        void all(int all) {
          if (!all_ || top_left_ != all) {
            all_ = true;
            top_left_ = top_right_ = bottom_left_ = bottom_right_ = all;
          }
        }
        
        /// @brief Gets the border_radius value for the bottom_right edge.
        /// @return The border_radius, in pixels, for the bottom_right edge.
        /// @remarks Setting this value can also alter the all property.
        int bottom_right() const {return bottom_right_;}
        /// @brief Sets the border_radius value for the bottom_right edge.
        /// @param bottom_right The border_radius, in pixels, for the bottom_right edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom_right(int bottom_right) {
          if (all_ || bottom_right_ != bottom_right) {
            all_ = false;
            bottom_right_ = bottom_right;
          }
        }
        
        /// @brief Gets the border_radius value for the top_left edge.
        /// @return The border_radius, in pixels, for the top_left edge.
        /// @remarks Setting this value can also alter the all property.
        int top_left() const {return top_left_;}
        /// @brief Sets the border_radius value for the top_left edge.
        /// @param top_left The border_radius, in pixels, for the top_left edge.
        /// @remarks Setting this value can also alter the all property.
        void top_left(int top_left) {
          if (all_ || top_left_ != top_left) {
            all_ = false;
            top_left_ = top_left;
          }
        }
        
        /// @brief Gets the border_radius value for the bottom_left edge.
        /// @return The border_radius, in pixels, for the bottom_left edge.
        /// @remarks Setting this value can also alter the all property.
        int bottom_left() const {return bottom_left_;}
        /// @brief Sets the border_radius value for the bottom_left edge.
        /// @param bottom_left The border_radius, in pixels, for the bottom_left edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom_left(int bottom_left) {
          if (all_ || bottom_left_ != bottom_left) {
            all_ = false;
            bottom_left_ = bottom_left;
          }
        }
        
        /// @brief Gets the border_radius value for the top_right edge.
        /// @return The border_radius, in pixels, for the top_right edge.
        /// @remarks Setting this value can also alter the all property.
        int top_right() const {return top_right_;}
        /// @brief Sets the border_radius value for the top_right edge.
        /// @param top_right The border_radius, in pixels, for the top_right edge.
        /// @remarks Setting this value can also alter the all property.
        void top_right(int top_right) {
          if (all_ || top_right_ != top_right) {
            all_ = false;
            top_right_ = top_right;
          }
        }
        
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Returns a string that represents the current border_radius.
        /// @return A string that represents the current border_radius.
        /// @remarks This method returns a string containing the labeled values of the border_radius for all four edges.
        xtd::ustring to_string() const noexcept override {return xtd::ustring::format("border_radius [all={}, top_left={}, top_right={}, bottom_left={}, bottom_right={}]", all_, top_left_, top_right_, bottom_left_, bottom_right_);}
        /// @}
        
        /// @cond
        bool operator==(const border_radius& p) const {return all_ == p.all_ && top_left_ == p.top_left_ && top_right_ == p.top_right_ && bottom_left_ == p.bottom_left_ && bottom_right_ == p.bottom_right_;}
        friend std::ostream& operator<<(std::ostream& os, const xtd::forms::style_sheets::border_radius& border_radius) noexcept {return os << border_radius.to_string();}
        /// @endcond
        
      private:
        bool all_ = true;
        int top_left_ = 0;
        int top_right_ = 0;
        int bottom_left_ = 0;
        int bottom_right_ = 0;
      };
    }
  }
}
