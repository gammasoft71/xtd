/// @file
/// @brief Contains xtd::drawing::size_f class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <ostream>
#include <string>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class point_f;
    /// @endcond
    
    /// @brief Stores an ordered pair of flooating-point, which specify a height and width.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ size_f : public object {
    public:
      /// @brief Gets a Size class that has a Height and Width value of 0. This field is constant.
      static const xtd::drawing::size_f empty;
      
      /// @brief Initializes a new instance of the Size class that has a Height and Width value of 0.
      size_f() = default;

      /// @brief Initializes a new instance of the Size class from the specified Point class.
      /// @param point The Point class from which to initialize this Size class
      explicit size_f(const xtd::drawing::point_f& point);

      /// @brief Initializes a new instance of the Size class from the specified dimensions.
      /// @param width The width component of the new Size
      /// @param height The height component of the new Size
      size_f(float width, float height) : width_(width), height_(height) {}

      /// @cond
      size_f(const xtd::drawing::size_f&) = default;
      bool operator==(const xtd::drawing::size_f& value) const {return width_ == value.width_ && height_ == value.height_;}      
      bool operator!=(const xtd::drawing::size_f& value) const {return !operator==(value);}
      size_f& operator=(const xtd::drawing::size_f& size) = default;
      size_f operator+(const xtd::drawing::size_f& size) const;
      size_f operator-(const xtd::drawing::size_f& size) const;
      size_f& operator+=(const xtd::drawing::size_f& size);
      size_f& operator-=(const xtd::drawing::size_f& size);
      /// @endcond
      
      /// @brief Gets he vertical component of this Size Class.
      /// @return int The vertical component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      float height() const {return height_;}
      
      /// @brief Sets the vertical component of this Size Class.
      /// @return int The vertical component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      void height(float height) {height_ = height;}
      
      /// @brief Gets the horizontal component of this Size class.
      /// @return int The horizontal component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      float width() const {return width_;}
      
      /// @brief Sets the horizontal component of this Size class.
      /// @return int The horizontal component of this Size class, typically measured in pixels.
      /// @remarks The unit for the Height and Width of the Size class depend on the PageUnit and PageScale settings for the Graphics object that is used to draw.
      void width(float width) {width_ = width;}

      /// @brief Adds the width and height of one Size class to the width and height of another size class.
      /// @param size1 The first Size class to add.
      /// @param size2 The second Size class to add.
      /// @return Size A Size class that is the result of the addition operation.
      static xtd::drawing::size_f add(const xtd::drawing::size_f& size1, const xtd::drawing::size_f& size2);

      /// @brief Tests whether this Size class has width and height of 0.
      /// @return bool Returns true  when this Size class has both a width and height of 0; otherwise, false.
      bool is_empty() const {return *this == size_f::empty;}

      /// @brief Returns the result of subtracting specified size from the specified size.
      /// @param sz1 The Size to be subtracted from.
      /// @param sz2 The Size to subtract from the Size.
      /// @return The Size that is the result of the subtraction operation.
      /// @exception ArgumentNullException sz1 or sz2 are null.
      static xtd::drawing::size_f subtract(const xtd::drawing::size_f& sz1, const xtd::drawing::size_f& sz2);

      /// @brief Creates a human-readable string that represents this size class.
      /// @return string A string that represents this size.
      xtd::ustring to_string() const noexcept override {return "{width=" + std::to_string(width_) + ", height=" + std::to_string(height_) + "}";}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::size_f& size) noexcept {
        return os << size.to_string();
      }
      /// @endcond
      
    private:
      float width_ = 0;
      float height_ = 0;
    };
  }
}
