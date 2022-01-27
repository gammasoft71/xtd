/// @file
/// @brief Contains xtd::forms::style_sheets::border_radius_property class.
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
      /// @brief The radius is used to add rounded borders to an element.
      /// @code
      /// class forms_export_ border_radius_property : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_radius_property
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_radius_property : public object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::border_radius_property object.
        static const border_radius_property empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_radius_property class.
        border_radius_property() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_radius_property class using the supplied xtd::forms::style_sheets::border_radius_property size for all edges.
        /// @param all The number of pixels to be used for xtd::forms::style_sheets::border_radius_property for all edges.
        /// @remarks This constructor sets the bottom_left, top_left, bottom_right, top_right and all properties to the value of the all parameter.
        border_radius_property(int all) : all_(true), top_left_(all), top_right_(all), bottom_left_(all), bottom_right_(all) {}
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_radius_property class using a separate xtd::forms::style_sheets::border_radius_property size for each edge.
        /// @param top_left The xtd::forms::style_sheets::border_radius_property size, in pixels, for the top_left edge.
        /// @param top_right The xtd::forms::style_sheets::border_radius_property size, in pixels, for the top_right edge.
        /// @param bottom_left The xtd::forms::style_sheets::border_radius_property size, in pixels, for the bottom_left edge.
        /// @param bottom_right The xtd::forms::style_sheets::border_radius_property size, in pixels, for the bottom_right edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_radius_property(int top_left, int top_right, int bottom_left, int bottom_right) : all_(top_left == top_right && top_left == bottom_left && top_left == bottom_right), top_left_(top_left), top_right_(top_right), bottom_left_(bottom_left), bottom_right_(bottom_right) {}
        /// @}
        
        /// @cond
        border_radius_property(const border_radius_property&) = default;
        border_radius_property& operator=(const border_radius_property&) = default;
        bool operator==(const border_radius_property& value) {return all_ == value.all_ && top_left_ == value.top_left_ && top_right_ == value.top_right_ && bottom_left_ == value.bottom_left_ && bottom_right_ == value.bottom_right_;}
        bool operator!=(const border_radius_property& value) {return !operator==(value);}
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_radius_property value for all the edges.
        /// @return The xtd::forms::style_sheets::border_radius_property, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_radius_property value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_radius_property values are not equal.
        int all() const {return all_ ? top_right_ : -1;}
        /// @brief Sets the xtd::forms::style_sheets::border_radius_property value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_radius_property, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_radius_property value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_radius_property values are not equal.
        void all(int all) {
          if (!all_ || top_left_ != all) {
            all_ = true;
            top_left_ = top_right_ = bottom_left_ = bottom_right_ = all;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius_property value for the bottom_right edge.
        /// @return The xtd::forms::style_sheets::border_radius_property, in pixels, for the bottom_right edge.
        /// @remarks Setting this value can also alter the all property.
        int bottom_right() const {return bottom_right_;}
        /// @brief Sets the xtd::forms::style_sheets::border_radius_property value for the bottom_right edge.
        /// @param bottom_right The xtd::forms::style_sheets::border_radius_property, in pixels, for the bottom_right edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom_right(int bottom_right) {
          if (all_ || bottom_right_ != bottom_right) {
            all_ = false;
            bottom_right_ = bottom_right;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius_property value for the top_left edge.
        /// @return The xtd::forms::style_sheets::border_radius_property, in pixels, for the top_left edge.
        /// @remarks Setting this value can also alter the all property.
        int top_left() const {return top_left_;}
        /// @brief Sets the xtd::forms::style_sheets::border_radius_property value for the top_left edge.
        /// @param top_left The xtd::forms::style_sheets::border_radius_property, in pixels, for the top_left edge.
        /// @remarks Setting this value can also alter the all property.
        void top_left(int top_left) {
          if (all_ || top_left_ != top_left) {
            all_ = false;
            top_left_ = top_left;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius_property value for the bottom_left edge.
        /// @return The xtd::forms::style_sheets::border_radius_property, in pixels, for the bottom_left edge.
        /// @remarks Setting this value can also alter the all property.
        int bottom_left() const {return bottom_left_;}
        /// @brief Sets the xtd::forms::style_sheets::border_radius_property value for the bottom_left edge.
        /// @param bottom_left The xtd::forms::style_sheets::border_radius_property, in pixels, for the bottom_left edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom_left(int bottom_left) {
          if (all_ || bottom_left_ != bottom_left) {
            all_ = false;
            bottom_left_ = bottom_left;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_radius_property value for the top_right edge.
        /// @return The xtd::forms::style_sheets::border_radius_property, in pixels, for the top_right edge.
        /// @remarks Setting this value can also alter the all property.
        int top_right() const {return top_right_;}
        /// @brief Sets the xtd::forms::style_sheets::border_radius_property value for the top_right edge.
        /// @param top_right The xtd::forms::style_sheets::border_radius_property, in pixels, for the top_right edge.
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
        /// @brief Returns a string that represents the current xtd::forms::style_sheets::border_radius_property.
        /// @return A string that represents the current xtd::forms::style_sheets::border_radius_property.
        /// @remarks This method returns a string containing the labeled values of the xtd::forms::style_sheets::border_radius_property for all four edges.
        xtd::ustring to_string() const noexcept override {return xtd::ustring::format("border_radius_property [all={}, top_left={}, top_right={}, bottom_left={}, bottom_right={}]", all_, top_left_, top_right_, bottom_left_, bottom_right_);}
        /// @}
        
        /// @cond
        bool operator==(const border_radius_property& p) const {return all_ == p.all_ && top_left_ == p.top_left_ && top_right_ == p.top_right_ && bottom_left_ == p.bottom_left_ && bottom_right_ == p.bottom_right_;}
        friend std::ostream& operator<<(std::ostream& os, const xtd::forms::style_sheets::border_radius_property& border_radius_property) noexcept {return os << border_radius_property.to_string();}
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
