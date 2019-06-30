#pragma once
#include <ostream>

namespace xtd {
  namespace drawing {
    class point {
    public:
      static const point empty;
      
      point() = default;
      point(int x, int y) : x_(x), y_(y) {}

      /// @cond
      point(const point&) = default;
      point& operator=(const point&) = default;
      /// @endcond
      
      bool operator==(const point& value) const {return this->x_ == value.x_ && this->y_ == value.y_;}
      bool operator!=(const point& value) const {return !this->operator==(value);}
      
      bool is_empty() const {return *this == point::empty;}
      
      int x() const {return x_;}
      
      void x(int x) {this->x_ = x;}
      
      int y() const {return y_;}

      void y(int y) {this->y_ = y;}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::point& point) noexcept {
        return os << "{x=" << point.x_ << ", y=" << point.y_ << "}";
      }
      /// @endcond
      
    private:
      int x_ = 0;
      int y_ = 0;
    };
  }
}
