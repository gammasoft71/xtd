#pragma once
#include <cstdint>
#include <ostream>
#include <string>
#include "point.h"
#include "size.h"
#include "rectangle_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    class rectangle {
    public:
      static const rectangle empty;
      
      rectangle() = default;
      rectangle(int32_t x, int32_t y, int32_t width, int32_t height) : x_(x), y_(y), width_(width), height_(height) {}
      rectangle(const point& location, const drawing::size& size) : x_(location.x()), y_(location.y()), width_(size.width()), height_(size.height()) {}

      /// @cond
      rectangle(const rectangle&) = default;
      rectangle& operator=(const rectangle&) = default;
      operator rectangle_f() const {return rectangle_f(static_cast<float>(this->x_), static_cast<float>(this->y_), static_cast<float>(this->width_), static_cast<float>(this->height_));}
      /// @endcond
      
      bool operator==(const rectangle& value) const {return this->x_ == value.x_ && this->y_ == value.y_ && this->width_ == value.width_ && this->height_ == value.height_;}
      
      bool operator!=(const rectangle& value) const {return !this->operator==(value);}
      
      int32_t bottom() const {return this->y_ + this->height_;}
      
      int32_t left() const {return this->x_;}

      void left(int32_t left) {this->x_ = left;}

      point location() const {return {this->x_, this->y_};}
      
      void location(const point& location) {
        this->x_ = location.x();
        this->y_ = location.y();
      }
      
      int32_t right() const {return this->x_ + this->width_;}
      
      int32_t top() const {return this->y_;}
      
      void top(int32_t top) {this->y_ = top;}
      
      int32_t x() const {return this->x_;}
      
      void x(int32_t x) {this->x_ = x;}
      
      int32_t y() const {return this->y_;}

      void y(int32_t y) {this->y_ = y;}

      int32_t height() const {return this->height_;}
      
      void height(int32_t height) {this->height_ = height;}
      
      drawing::size size() const {return {this->width_, this->height_};}
      
      void size(const drawing::size& size) {
        this->width_ = size.width();
        this->height_ = size.height();
      }

      int32_t width() const {return this->width_;}
      
      void width(int32_t width) {this->width_ = width;}
      
      bool is_empty() const {return *this == rectangle::empty;}

      static rectangle make_intersect(const rectangle& a, const rectangle& b);
      
      static rectangle make_union(const rectangle& a, const rectangle& b);
      
      void offset(const rectangle& pt) {this->offset(pt.x_, pt.y_);}

      void offset(int32_t dx, int32_t dy) {
        this->x_ += dx;
        this->y_ += dy;
      }

      std::string to_string() const {return "{x=" + std::to_string(this->x_) + ", y=" + std::to_string(this->y_) + ", width=" + std::to_string(this->width_) + ", height=" + std::to_string(this->height_) + "}";}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::rectangle& rectangle) noexcept {
        return os << rectangle.to_string();
      }
      /// @endcond
      
    private:
      int32_t x_ = 0;
      int32_t y_ = 0;
      int32_t width_ = 0;
      int32_t height_ = 0;
    };
  }
}
