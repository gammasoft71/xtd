#pragma once
#include <ostream>
#include <string>
#include "size_f.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    struct point;
    /// @endcond
    
    /// @brief Stores an ordered pair of integers, which specify a height and width.
    struct size {
    public:
      /// @brief Gets a Size class that has a Height and Width value of 0. This field is constant.
      static const xtd::drawing::size empty;
      
      /// @brief Initializes a new instance of the Size class that has a Height and Width value of 0.
      size() = default;

      /// @brief IInitializes a new instance of the Size class from the specified Point class.
      /// @param point The Point class from which to initialize this Size class
      explicit size(const xtd::drawing::point& point);

      /// @brief Initializes a new instance of the Size class from the specified dimensions.
      /// @param width The width component of the new Size
      /// @param height The height component of the new Size
      size(int32_t width, int32_t height) : width_(width), height_(height) {}

      /// @cond
      size(const xtd::drawing::size&) = default;
      bool operator==(const xtd::drawing::size& value) const {return this->width_ == value.width_ && this->height_ == value.height_;}      
      bool operator!=(const xtd::drawing::size& value) const {return !this->operator==(value);}
      size& operator=(const xtd::drawing::size& size) = default;
      size operator+(const xtd::drawing::size& size) const;
      size operator-(const xtd::drawing::size& size) const;
      size& operator+=(const xtd::drawing::size& size);
      size& operator-=(const xtd::drawing::size& size);
      operator size_f() {return size_f(this->width_, this->height_);}
      /// @endcond
      
      /// @brief Gets he vertical component of this Size Class.
      /// @return int The vertical component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      int32_t height() const {return height_;}
      
      /// @brief Sets the vertical component of this Size Class.
      /// @return int The vertical component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      void height(int32_t height) {this->height_ = height;}
      
      /// @brief Gets the horizontal component of this Size class.
      /// @return int The horizontal component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      int32_t width() const {return width_;}
      
      /// @brief Sets the horizontal component of this Size class.
      /// @return int The horizontal component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      void width(int32_t width) {this->width_ = width;}

      /// @brief Adds the width and height of one Size class to the width and height of another size class.
      /// @param size1 The first Size class to add.
      /// @param size2 The second Size class to add.
      /// @return Size A Size class that is the result of the addition operation.
      static xtd::drawing::size add(const xtd::drawing::size& size1, const xtd::drawing::size& size2);

      /// @brief Tests whether this Size class has width and height of 0.
      /// @return bool Returns true  when this Size class has both a width and height of 0; otherwise, false.
      bool is_empty() const {return *this == size::empty;}

      /// @brief Returns the result of subtracting specified size from the specified size.
      /// @param sz1 The Size to be subtracted from.
      /// @param sz2 The Size to subtract from the Size.
      /// @return The Size that is the result of the subtraction operation.
      /// @exception ArgumentNullException sz1 or sz2 are null.
      static xtd::drawing::size subtract(const xtd::drawing::size& sz1, const xtd::drawing::size& sz2);

      /// @brief Creates a human-readable string that represents this size class.
      /// @return string A string that represents this size.
      std::string to_string() const {return "{width=" + std::to_string(this->width_) + ", height=" + std::to_string(this->height_) + "}";}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::size& size) noexcept {
        return os << size.to_string();
      }
      /// @endcond
      
    private:
      int32_t width_ = 0;
      int32_t height_ = 0;
    };
  }
}
