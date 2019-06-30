#pragma once
#include <ostream>
#include <string>

namespace xtd {
  namespace drawing {
    class size {
    public:
      static const size empty;
      
      size() = default;
      size(int width, int height) : width_(width), height_(height) {}

      /// @cond
      size(const size&) = default;
      size& operator=(const size&) = default;
      /// @endcond
      
      bool operator==(const size& value) const {return this->width_ == value.width_ && this->height_ == value.height_;}
      
      bool operator!=(const size& value) const {return !this->operator==(value);}
      
      bool is_empty() const {return *this == size::empty;}

      std::string to_string() const {return "{width=" + std::to_string(this->width_) + ", height=" + std::to_string(this->height_) + "}";}
      
      int width() const {return width_;}
      
      void width(int width) {this->width_ = width;}
      
      int height() const {return height_;}

      void height(int height) {this->height_ = height;}

      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::size& size) noexcept {
        return os << size.to_string();
      }
      /// @endcond
      
    private:
      int width_ = 0;
      int height_ = 0;
    };
  }
}
