#pragma once
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    struct point_f;
    struct size;
    /// @endcond

    struct point {
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

      void offset(const point& pt) {this->offset(pt.x_, pt.y_);}

      void offset(int dx, int dy) {
        this->x_ += dx;
        this->y_ += dy;
      }

      std::string to_string() const {return "{x=" + std::to_string(this->x_) + ", y=" + std::to_string(this->y_) + "}";}
      
      int x() const {return x_;}
      
      void x(int x) {this->x_ = x;}
      
      int y() const {return y_;}

      void y(int y) {this->y_ = y;}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::point& point) noexcept {
        return os << point.to_string();
      }
      /// @endcond
      
    private:
      int x_ = 0;
      int y_ = 0;
    };
  }
}
