/// @file
/// @brief Contains xtd::forms::style_sheets::border_width class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
#include "color_value.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The width specifies the width of the borders.
      /// @code
      /// class forms_export_ border_width : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_width
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_width : public object {
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
        border_width(int all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {}
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_width class using a separate xtd::forms::style_sheets::border_width size for each edge.
        /// @param left The xtd::forms::style_sheets::border_width size, in pixels, for the left edge.
        /// @param top The xtd::forms::style_sheets::border_width size, in pixels, for the top edge.
        /// @param right The xtd::forms::style_sheets::border_width size, in pixels, for the right edge.
        /// @param bottom The xtd::forms::style_sheets::border_width size, in pixels, for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_width(int left, int top, int right, int bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {}
        /// @}
        
        /// @cond
        border_width(const border_width&) = default;
        border_width& operator=(const border_width&) = default;
        bool operator==(const border_width& value) {return all_ == value.all_ && left_ == value.left_ && top_ == value.top_ && right_ == value.right_ && bottom_ == value.bottom_;}
        bool operator!=(const border_width& value) {return !operator==(value);}
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_width value for all the edges.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_width value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_width values are not equal.
        int all() const {return all_ ? top_ : -1;}
        /// @brief Sets the xtd::forms::style_sheets::border_width value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_width, in pixels, for all edges if the same; otherwise, -1.
        /// @remarks When retrieving this property, if all the edges use the same xtd::forms::style_sheets::border_width value, then this common value is returned. Otherwise, -1 is returned to indicate that all the xtd::forms::style_sheets::border_width values are not equal.
        void all(int all) {
          if (!all_ || left_ != all) {
            all_ = true;
            left_ = top_ = right_ = bottom_ = all;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the bottom edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        int bottom() const {return bottom_;}
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the bottom edge.
        /// @param bottom The xtd::forms::style_sheets::border_width, in pixels, for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(int bottom) {
          if (all_ || bottom_ != bottom) {
            all_ = false;
            bottom_ = bottom;
          }
        }
        
        /// @brief Gets the combined xtd::forms::style_sheets::border_width for the right and left edges.
        /// @return Gets the sum, in pixels, of the left and right xtd::forms::style_sheets::border_width values.
        int horizontal() const {return left_ + right_;}
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the left edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        int left() const {return left_;}
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the left edge.
        /// @param left The xtd::forms::style_sheets::border_width, in pixels, for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(int left) {
          if (all_ || left_ != left) {
            all_ = false;
            left_ = left;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the right edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        int right() const {return right_;}
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the right edge.
        /// @param right The xtd::forms::style_sheets::border_width, in pixels, for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(int right) {
          if (all_ || right_ != right) {
            all_ = false;
            right_ = right;
          }
        }
        
        /// @brief Gets the xtd::forms::style_sheets::border_width value for the top edge.
        /// @return The xtd::forms::style_sheets::border_width, in pixels, for the top edge.
        /// @remarks Setting this value can also alter the all property.
        int top() const {return top_;}
        /// @brief Sets the xtd::forms::style_sheets::border_width value for the top edge.
        /// @param top The xtd::forms::style_sheets::border_width, in pixels, for the top edge.
        /// @remarks Setting this value can also alter the all property.
        void top(int top) {
          if (all_ || top_ != top) {
            all_ = false;
            top_ = top;
          }
        }
        
        /// @brief Gets the combined xtd::forms::style_sheets::border_width for the bottom and top edges.
        /// @param p1 A xtd::forms::style_sheets::border_width.
        /// @param p2 A xtd::forms::style_sheets::border_width.
        /// @return Gets the sum, in pixels, of the top and bottom xtd::forms::style_sheets::border_width values.
        int vertical() const {return top_ + bottom_;}
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Computes the sum of the two specified xtd::forms::style_sheets::border_width values.
        /// @return A xtd::forms::style_sheets::border_width that contains the sum of the two specified xtd::forms::style_sheets::border_width values.
        static border_width add(const border_width& p1, const border_width& p2) {
          if (p1.all_ && p2.all_) return {p1.left_ + p2.left_};
          return {p1.left_ + p2.left_, p1.top_ + p2.top_, p1.right_ + p2.right_, p1.bottom_ + p2.bottom_};
        }
        
        /// @brief Subtracts one specified xtd::forms::style_sheets::border_width value from another.
        /// @param p1 A xtd::forms::style_sheets::border_width.
        /// @param p2 A xtd::forms::style_sheets::border_width.
        /// @return A xtd::forms::style_sheets::border_width that contains the result of the subtraction of one specified xtd::forms::style_sheets::border_width value from another.
        static border_width subtract(const border_width& p1, const border_width& p2) {
          if (p1.all_ && p2.all_) return {p1.left_ - p2.left_};
          return {p1.left_ - p2.left_, p1.top_ - p2.top_, p1.right_ - p2.right_, p1.bottom_ - p2.bottom_};
        }
        
        /// @brief Returns a string that represents the current xtd::forms::style_sheets::border_width.
        /// @return A string that represents the current xtd::forms::style_sheets::border_width.
        /// @remarks This method returns a string containing the labeled values of the xtd::forms::style_sheets::border_width for all four edges.
        xtd::ustring to_string() const noexcept override {return xtd::ustring::format("border_width [all={}, left={}, top={}, right={}, bottom={}]", all_, left_, top_, right_, bottom_);}
        /// @}
        
        /// @cond
        bool operator==(const border_width& p) const {return all_ == p.all_ && left_ == p.left_ && top_ == p.top_ && right_ == p.right_ && bottom_ == p.bottom_;}
        friend std::ostream& operator<<(std::ostream& os, const xtd::forms::style_sheets::border_width& border_width) noexcept {return os << border_width.to_string();}
        /// @endcond
        
      private:
        bool all_ = true;
        int left_ = 3;
        int top_ = 3;
        int right_ = 3;
        int bottom_ = 3;
      };
    }
  }
}
