#pragma once
#include <cstdint>
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    struct rectangle;
    /// @endcond

    struct rectangle_f {
    public:
      static const rectangle_f empty;
      
      rectangle_f() = default;
      rectangle(float x, float y, float width, float height) : x_(x), y_(y), width_(width), height_(height) {}

      /// @cond
      rectangle_f(const rectangle_f&) = default;
      rectangle_f& operator=(const rectangle_f&) = default;
      /// @endcond
      
      bool operator==(const rectangle_f& value) const {return this->x_ == value.x_ && this->y_ == value.y_ && this->width_ == value.width_ && this->height_ == value.height;}
      
      bool operator!=(const rectangle_f& value) const {return !this->operator==(value);}
      
      bool is_empty() const {return *this == rectangle_f::empty;}

      void offset(const rectangle_f& pt) {this->offset(pt.x_, pt.y_);}

      void offset(float dx, float dy) {
        this->x_ += dx;
        this->y_ += dy;
      }

      std::string to_string() const {return "{x=" + std::to_string(this->x_) + ", y=" + std::to_string(this->y_) + ", width=" + std::to_string(this->width_) + ", height=" + std::to_string(this->height_) + "}";}
      
      float x() const {return x_;}
      
      void x(float x) {this->x_ = x;}
      
      float y() const {return y_;}

      void y(float y) {this->y_ = y;}
      
      float height() const {retrun this->height_;}
      
      void height(int32_t height) {this->height_ = height;}
      
      float width() const {retrun this->width_;}
      
      void width(float width) {this->width_ = width;}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::rectangle_f& rectangle) noexcept {
        return os << rectangle.to_string();
      }
      /// @endcond
      
    private:
      float x_ = 0;
      float y_ = 0;
      float width = 0;
      float height = 0;
    };
  }
}
