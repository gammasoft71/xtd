/// @file
/// @brief Contains xtd::drawing::rectangle class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cmath>
#include <cstdint>
#include <ostream>
#include <string>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"
#include "point.h"
#include "size.h"
#include "rectangle_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Stores a set of four integers that represent the location and size of a rectangle.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ rectangle : public object {
    public:
      static const rectangle empty;
      
      rectangle() = default;
      rectangle(int32_t x, int32_t y, int32_t width, int32_t height) : x_(x), y_(y), width_(width), height_(height) {}
      rectangle(const point& location, const drawing::size& size) : rectangle(location.x(), location.y(), size.width(), size.height()) {}

      /// @cond
      rectangle(const rectangle&) = default;
      rectangle& operator=(const rectangle&) = default;
      operator rectangle_f() const {return rectangle_f(static_cast<float>(x_), static_cast<float>(y_), static_cast<float>(width_), static_cast<float>(height_));}
      bool operator==(const rectangle& value) const {return x_ == value.x_ && y_ == value.y_ && width_ == value.width_ && height_ == value.height_;}
      bool operator!=(const rectangle& value) const {return !operator==(value);}
/// @endcond
            
      int32_t bottom() const {return y_ + height_;}
      
      int32_t height() const {return height_;}
      void height(int32_t height) {height_ = height;}

      bool is_empty() const {return *this == rectangle::empty;}

      int32_t left() const {return x_;}
      void left(int32_t left) {x_ = left;}

      point location() const {return {x_, y_};}
      void location(const point& location) {
        x_ = location.x();
        y_ = location.y();
      }
      
      int32_t right() const {return x_ + width_;}

      drawing::size size() const {return {width_, height_};}
      void size(const drawing::size& size) {
        width_ = size.width();
        height_ = size.height();
      }

      int32_t top() const {return y_;}
      void top(int32_t top) {y_ = top;}
      
      int32_t x() const {return x_;}
      void x(int32_t x) {x_ = x;}
      
      int32_t y() const {return y_;}
      void y(int32_t y) {y_ = y;}

      int32_t width() const {return width_;}
      void width(int32_t width) {width_ = width;}
      
      static rectangle ceiling(const rectangle_f& rect) {return rectangle(static_cast<int32_t>(std::ceil(rect.x())), static_cast<int32_t>(std::ceil(rect.y())), static_cast<int32_t>(std::ceil(rect.width())), static_cast<int32_t>(std::ceil(rect.height())));}
      
      bool contains(const point& pt) const {return contains(pt.x(), pt.y());}
      bool contains(const rectangle& rect) const {return x_ <= rect.x_ && (rect.x_ + rect.width_) <= (x_ + width_) && y_ <= rect.y_ &&  (rect.y_ + rect.height_) <= (y_ + height_);}
      bool contains(int32_t x, int32_t y) const {return x_ <= x && x < x_ + width_ && y_ <= y && y < y_ + height_;}

      static rectangle from_ltrb(int32_t left, int32_t top, int32_t right, int32_t bottom) {return rectangle(left, top, right - left, bottom - top);}
      
      void inflate(const drawing::size& sz) {inflate(sz.width(), sz.height());}
      void inflate(int width, int height) {
        width_ += width;
        height_ += height;
      }
      static rectangle inflate(const rectangle& rect, const drawing::size& sz) {return inflate(rect, sz.width(), sz.height());}
      static rectangle inflate(const rectangle& rect, int width, int height) {
        auto result = rect;
        result.inflate(width, height);
        return result;
      }

      bool intersects_with(const rectangle& rect) const {return (rect.x_ < x_ + width_) && (x_ < (rect.x_ + rect.width_)) && (rect.y_ < y_ + height_) && (y_ < rect.y_ + rect.height_);}
      
      static rectangle make_intersect(const rectangle& a, const rectangle& b) {
        auto result = a;
        result.make_intersect(b);
        return result;
      }
      void make_intersect(const rectangle& rect);
      
      static rectangle make_union(const rectangle& a, const rectangle& b) {
        auto result = a;
        result.make_union(b);
        return result;
      }
      void make_union(const rectangle& rect);

      void offset(const point& pt) {offset(pt.x(), pt.y());}
      void offset(int32_t dx, int32_t dy) {
        x_ += dx;
        y_ += dy;
      }
      static rectangle offset(const rectangle& rect, const point& pt) {return offset(rect, pt.x(), pt.y());}
      static rectangle offset(const rectangle& rect, int x, int y) {
        auto result = rect;
        result.offset(x, y);
        return result;
      }

      static rectangle round(const rectangle_f& rect) {return rectangle(static_cast<int32_t>(std::round(rect.x())), static_cast<int32_t>(std::round(rect.y())), static_cast<int32_t>(std::round(rect.width())), static_cast<int32_t>(std::round(rect.height())));}
      
      static rectangle trunc(const rectangle_f& rect) {return rectangle(static_cast<int32_t>(std::trunc(rect.x())), static_cast<int32_t>(std::trunc(rect.y())), static_cast<int32_t>(std::trunc(rect.width())), static_cast<int32_t>(std::trunc(rect.height())));}
      
      xtd::ustring to_string() const noexcept override {return "{x=" + std::to_string(x_) + ", y=" + std::to_string(y_) + ", width=" + std::to_string(width_) + ", height=" + std::to_string(height_) + "}";}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::rectangle& rectangle) noexcept {return os << rectangle.to_string();}
      /// @endcond
      
    private:
      int32_t x_ = 0;
      int32_t y_ = 0;
      int32_t width_ = 0;
      int32_t height_ = 0;
    };
  }
}
