#pragma once
#include <cstdint>
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    struct rectangle_f;
    /// @endcond

    struct rectangle {
    public:
      static const rectangle empty;
      
      rectangle() = default;
      rectangle(int32_t x, int32_t y, int32_t width, int32_t height) : x_(x), y_(y), width_(width), height_(height) {}

      /// @cond
      rectangle(const rectangle&) = default;
      rectangle& operator=(const rectangle&) = default;
      /// @endcond
      
      bool operator==(const rectangle& value) const {return this->x_ == value.x_ && this->y_ == value.y_ && this->width_ == value.width_ && this->height_ == value.height_;}
      
      bool operator!=(const rectangle& value) const {return !this->operator==(value);}
      
      bool is_empty() const {return *this == rectangle::empty;}

      void offset(const rectangle& pt) {this->offset(pt.x_, pt.y_);}

      void offset(int32_t dx, int32_t dy) {
        this->x_ += dx;
        this->y_ += dy;
      }

      std::string to_string() const {return "{x=" + std::to_string(this->x_) + ", y=" + std::to_string(this->y_) + ", width=" + std::to_string(this->width_) + ", height=" + std::to_string(this->height_) + "}";}
      
      int32_t x() const {return x_;}
      
      void x(int32_t x) {this->x_ = x;}
      
      int32_t y() const {return y_;}

      void y(int32_t y) {this->y_ = y;}
      
      int32_t height() const {return this->height_;}
      
      void height(int32_t height) {this->height_ = height;}
      
      int32_t width() const {return this->width_;}
      
      void width(int32_t width) {this->width_ = width;}
      
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
