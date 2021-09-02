/// @file
/// @brief Contains xtd::forms::padding class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a display device or multiple display devices on a single system.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ padding : public object {
    public:
      /// @brief Initializes a new instance of the padding class.
      padding() = default;
      
      /// @brief Initializes a new instance of the padding class using the supplied padding size for all edges.
      /// @param all The number of pixels to be used for padding for all edges.
      /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
      padding(int all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {}
      
      /// @brief Initializes a new instance of the padding class using a separate padding size for each edge.
      /// @param left The padding size, in pixels, for the left edge.
      /// @param topo The padding size, in pixels, for the toop edge.
      /// @param rright The padding size, in pixels, for the right edge.
      /// @param bottom The padding size, in pixels, for the bottom edge.
      /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
      padding(int left, int top, int right, int bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {}
      
      /// @cond
      padding(const padding&) = default;
      padding& operator=(const padding&) = default;
      bool operator==(const padding& value) {return all_ == value.all_ && left_ == value.left_ && top_ == value.top_ && right_ == value.right_ && bottom_ == value.bottom_;}
      bool operator!=(const padding& value) {return !operator==(value);}
      /// @endcond
      
      /// @brief Gets the padding value for all the edges.
      /// @return The padding, in pixels, for all edges if the same; otherwise, -1.
      /// @remarks When retrieving this property, if all the edges use the same padding value, then this common value is returned. Otherwise, -1 is returned to indicate that all the padding values are not equal.
      int all() const {return all_ ? top_ : -1;}
      /// @brief Sets the padding value for all the edges.
      /// @param all The padding, in pixels, for all edges if the same; otherwise, -1.
      /// @remarks When retrieving this property, if all the edges use the same padding value, then this common value is returned. Otherwise, -1 is returned to indicate that all the padding values are not equal.
      void all(int all) {
        if (!all_ || left_ != all) {
          all_ = true;
          left_ = top_ = right_ = bottom_ = all;
        }
      }
      
      /// @brief Gets the padding value for the bottom edge.
      /// @return The padding, in pixels, for the bottom edge.
      /// @remarks Setting this value can also alter the all property.
      int bottom() const {return bottom_;}
      /// @brief Sets the padding value for the bottom edge.
      /// @param bottom The padding, in pixels, for the bottom edge.
      /// @remarks Setting this value can also alter the all property.
      void bottom(int bottom) {
        if (all_ || bottom_ != bottom) {
          all_ = false;
          bottom_ = bottom;
        }
      }
      
      /// @brief Gets the combined padding for the right and left edges.
      /// @return Gets the sum, in pixels, of the left and right padding values.
      int horizontal() const {return left_ + right_;}
      
      /// @brief Gets the padding value for the left edge.
      /// @return The padding, in pixels, for the left edge.
      /// @remarks Setting this value can also alter the all property.
      int left() const {return left_;}
      /// @brief Sets the padding value for the left edge.
      /// @param left The padding, in pixels, for the left edge.
      /// @remarks Setting this value can also alter the all property.
      void left(int left) {
        if (all_ || left_ != left) {
          all_ = false;
          left_ = left;
        }
      }

      /// @brief Gets the padding value for the right edge.
      /// @return The padding, in pixels, for the right edge.
      /// @remarks Setting this value can also alter the all property.
      int right() const {return right_;}
      /// @brief Sets the padding value for the right edge.
      /// @param right The padding, in pixels, for the right edge.
      /// @remarks Setting this value can also alter the all property.
      void right(int right) {
        if (all_ || right_ != right) {
          all_ = false;
          right_ = right;
        }
      }

      /// @brief Gets the padding value for the top edge.
      /// @return The padding, in pixels, for the top edge.
      /// @remarks Setting this value can also alter the all property.
      int top() const {return top_;}
      /// @brief Sets the padding value for the top edge.
      /// @param top The padding, in pixels, for the top edge.
      /// @remarks Setting this value can also alter the all property.
      void top(int top) {
        if (all_ || top_ != top) {
          all_ = false;
          top_ = top;
        }
      }
      
      /// @brief Gets the combined padding for the bottom and top edges.
      /// @param p1 A padding.
      /// @param p2 A padding.
      /// @return Gets the sum, in pixels, of the top and bottom padding values.
      int vertical() const {return top_ + bottom_;}
      
      /// @brief Computes the sum of the two specified padding values.
      /// @return A padding that contains the sum of the two specified padding values.
      static padding add(const padding& p1, const padding& p2) {
        if (p1.all_ && p2.all_) return {p1.left_ + p2.left_};
        return {p1.left_ + p2.left_, p1.top_ + p2.top_, p1.right_ + p2.right_, p1.bottom_ + p2.bottom_};
      }
      
      /// @brief Subtracts one specified Padding value from another.
      /// @param p1 A padding.
      /// @param p2 A padding.
      /// @return A padding that contains the result of the subtraction of one specified padding value from another.
      static padding subtract(const padding& p1, const padding& p2) {
        if (p1.all_ && p2.all_) return {p1.left_ - p2.left_};
        return {p1.left_ - p2.left_, p1.top_ - p2.top_, p1.right_ - p2.right_, p1.bottom_ - p2.bottom_};
      }

      /// @brief Returns a string that represents the current padding.
      /// @return A string that represents the current padding.
      /// @remarks This method returns a string containing the labeled values of the padding for all four edges.
      xtd::ustring to_string() const noexcept override {return xtd::ustring::format("padding [all={}, left={}, top={}, right={}, bottom={}]", all_, left_, top_, right_, bottom_);}
      
      /// @cond
      bool operator==(const padding& p) const {return all_ == p.all_ && left_ == p.left_ && top_ == p.top_ && right_ == p.right_ && bottom_ == p.bottom_;}
      friend std::ostream& operator<<(std::ostream& os, const xtd::forms::padding& padding) noexcept {return os << padding.to_string();}
      /// @endcond

      /// @brief Provides a Padding object with no padding.
      static const padding empty;
                                        
    private:
      bool all_ = true;
      int left_ = 0;
      int top_ = 0;
      int right_ = 0;
      int bottom_ = 0;
    };
  }
}
