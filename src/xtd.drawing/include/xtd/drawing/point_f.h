#pragma once
#include <cstdint>
#include <ostream>
#include <string>
#include <string>
#include "../drawing_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class size;
    /// @endcond

    class drawing_export_ point_f {
    public:
      static const point_f empty;
      
      point_f() = default;
      point_f(float x, float y) : x_(x), y_(y) {}

      /// @cond
      point_f(const point_f&) = default;
      point_f& operator=(const point_f&) = default;
      /// @endcond
      
      bool operator==(const point_f& value) const {return x_ == value.x_ && y_ == value.y_;}
      
      bool operator!=(const point_f& value) const {return !operator==(value);}
      
      bool is_empty() const {return *this == point_f::empty;}

      void offset(const point_f& pt) {offset(pt.x_, pt.y_);}

      void offset(float dx, float dy) {
        x_ += dx;
        y_ += dy;
      }

      std::string to_string() const {return "{x=" + std::to_string(x_) + ", y=" + std::to_string(y_) + "}";}
      
      float x() const {return x_;}
      
      void x(float x) {x_ = x;}
      
      float y() const {return y_;}

      void y(float y) {y_ = y;}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::point_f& point) noexcept {
        return os << point.to_string();
      }
      /// @endcond
      
    private:
      float x_ = 0;
      float y_ = 0;
    };
  }
}
