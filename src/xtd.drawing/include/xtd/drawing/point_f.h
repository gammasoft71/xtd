/// @file
/// @brief Contains xtd::drawing::point_f class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class point;
    class point_f;
    class size;
    class size_f;
    /// @endcond
    
    /// @brief Represents an ordered pair of floating-point x- and y-coordinates that defines a point in a two-dimensional plane.
    /// @code
    /// class drawing_export_ point_f : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::point_f
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing coordinates
    class drawing_export_ point_f : public xtd::object, public xtd::iequatable<point_f> {
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Represents a xtd::drawing::point_f that has xtd::drawing::point_f::x and xtd::drawing::point_f::y values set to zero.
      static const point_f empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::drawing::point_f class
      /// @remarks xtd::drawing::point::x and xtd::drawing::point::y values are set to zero.
      point_f() noexcept = default;
      /// @brief Initializes a new instance of the xtd::drawing::point_f class with the specified coordinates.
      /// @param x The horizontal position of the point.
      /// @param y The vertical position of the point.
      point_f(float x, float y) noexcept;
      /// @brief Initializes a new instance of the xtd::drawing::point_t class from a xtd::drawing::size_f.
      /// @param sz A size that specifies the coordinates for the new point.
      explicit point_f(const size_f& sz) noexcept;
      /// @}
      
      /// @cond
      point_f(const point_f&) noexcept = default;
      point_f& operator =(const point_f&) noexcept = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether this xtd::drawing::point_f is empty.
      /// @return true if both xtd::drawing::point_f::x and xtd::drawing::point_f::y are 0; otherwise, false.
      bool is_empty() const noexcept;
      
      /// @brief Gets the x-coordinate of this xtd::drawing::point_f.
      /// @return The x-coordinate of this xtd::drawing::point_f.
      float x() const noexcept;
      
      /// @brief Sets the x-coordinate of this xtd::drawing::point_f.
      /// @param x The x-coordinate of this xtd::drawing::point_f.
      void x(float x) noexcept;
      
      /// @brief Gets the y-coordinate of this xtd::drawing::point_f.
      /// @return The y-coordinate of this xtd::drawing::point_f.
      float y() const noexcept;
      
      /// @brief Sets the y-coordinate of this xtd::drawing::point_f.
      /// @param y The x-coordinate of this xtd::drawing::point_f.
      void y(float y) noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      bool equals(const point_f& value) const noexcept override;
      
      /// @brief Translates this xtd::drawing::point_f by the specified amount.
      /// @param dx The amount to offset the x-coordinate.
      /// @param dy The amount to offset the y-coordinate.
      void offset(float dx, float dy) noexcept;
      
      /// @brief Translates this xtd::drawing::point_f by the specified xtd::drawing::point_f.
      /// @param p The xtd::drawing::point used offset this xtd::drawing::point_f.
      /// @remarks This method adjusts the xtd::drawing::point_f::x and xtd::drawing::point_f::y values of this xtd::drawing::point_f to the sum of the xtd::drawing::point_f::x and xtd::drawing::point_f::y values of this xtd::drawing::point_f and p.
      void offset(const point_f& pt) noexcept;
      
      /// @brief Converts this point to a human-readable string.
      /// @return An xtd::ustring that represents this xtd::drawing::point.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Adds the specified xtd::drawing::size to the specified xtd::drawing::point_f.
      /// @param pt The xtd::drawing::point_f to add.
      /// @param sz The xtd::drawing::size to add.
      /// @return The xtd::drawing::point_f that is the result of the addition operation.
      /// @remarks The xtd::drawing::point::add adds the xtd::drawing::size::width and xtd::drawing::size::height of the specified size to the xtd::drawing::point_f::x and xtd::drawing::point_f::y values of the specified xtd::drawing::point_f.
      static point_f add(const point_f& pt, const size& sz) noexcept;
      /// @brief Adds the specified xtd::drawing::size_f to the specified xtd::drawing::point_f.
      /// @param pt The xtd::drawing::point_f to add.
      /// @param sz The xtd::drawing::size_f to add.
      /// @return The xtd::drawing::point_f that is the result of the addition operation.
      /// @remarks The xtd::drawing::point::add adds the xtd::drawing::size_f::width and xtd::drawing::size_f::height of the specified size to the xtd::drawing::point_f::x and xtd::drawing::point_f::y values of the specified xtd::drawing::point_f.
      static point_f add(const point_f& pt, const size_f& sz) noexcept;
      /// @brief Adds the specified xtd::drawing::point to the specified xtd::drawing::point_f.
      /// @param pt1 The xtd::drawing::point_f to add.
      /// @param pt2 The xtd::drawing::point to add.
      /// @return The xtd::drawing::point_f that is the result of the addition operation.
      static point_f add(const point_f& pt1, const point& pt2) noexcept;
      /// @brief Adds the specified xtd::drawing::point_f to the specified xtd::drawing::point_f.
      /// @param pt1 The xtd::drawing::point_f to add.
      /// @param pt2 The xtd::drawing::point_f to add.
      /// @return The xtd::drawing::point_f that is the result of the addition operation.
      static point_f add(const point_f& pt1, const point_f& pt2) noexcept;
      
      /// @brief Returns the result of subtracting specified xtd::drawing::size from the specified xtd::drawing::point_f.
      /// @param pt The xtd::drawing::point_f to be subtracted from.
      /// @param sz The xtd::drawing::size to subtract from the xtd::drawing::point.
      /// @return The xtd::drawing::point_f that is the result of the subtraction operation.
      /// @remarks The xtd::drawing::point_f::subtract subtracts the xtd::drawing::size::width and xtd::drawing::size::height of the specified xtd::drawing::size from the xtd::drawing::point_f::x and xtd::drawing::point_f::y values of the specified xtd::drawing::point_f.
      static point_f subtract(const point_f& pt, const size& sz) noexcept;
      /// @brief Returns the result of subtracting specified xtd::drawing::size_f from the specified xtd::drawing::point_f.
      /// @param pt The xtd::drawing::point_f to be subtracted from.
      /// @param sz The xtd::drawing::size_f to subtract from the xtd::drawing::point.
      /// @return The xtd::drawing::point_f that is the result of the subtraction operation.
      /// @remarks The xtd::drawing::point_f::subtract subtracts the xtd::drawing::size_f::width and xtd::drawing::size_F::height of the specified xtd::drawing::size_f from the xtd::drawing::point_f::x and xtd::drawing::point_f::y values of the specified xtd::drawing::poin_ft.
      static point_f subtract(const point_f& pt, const size_f& sz) noexcept;
      /// @brief Returns the result of subtracting specified xtd::drawing::point from the specified xtd::drawing::point.
      /// @param pt1 The xtd::drawing::point_f to be subtracted from.
      /// @param pt2 The xtd::drawing::point to subtract from the xtd::drawing::point_f.
      /// @return The xtd::drawing::point_f that is the result of the subtraction operation.
      static point_f subtract(const point_f& pt1, const point& pt2) noexcept;
      /// @brief Returns the result of subtracting specified xtd::drawing::point from the specified xtd::drawing::point.
      /// @param pt1 The xtd::drawing::point_f to be subtracted from.
      /// @param pt2 The xtd::drawing::point_f to subtract from the xtd::drawing::point_f.
      /// @return The xtd::drawing::point_f that is the result of the subtraction operation.
      static point_f subtract(const point_f& pt1, const point_f& pt2) noexcept;
      /// @}

      /// @name Operators
      
      /// @{
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f operator +(const size& sz) const noexcept;
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::size_f.
      /// @param sz A xtd::drawing::size_f that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f operator +(const size_f& sz) const noexcept;
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f operator +(const point& pt) const noexcept;
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::point_f.
      /// @param pt A xtd::drawing::size that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f operator +(const point_f& pt) const noexcept;
      
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f& operator +=(const size& sz) noexcept;
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::size_f.
      /// @param sz A xtd::drawing::size_f that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f& operator +=(const size_f& sz) noexcept;
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f& operator +=(const point& pt) noexcept;
      /// @brief Translates a xtd::drawing::point_f by a given xtd::drawing::point_f.
      /// @param pt A xtd::drawing::point_f that specifies the pair of numbers to add to the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f& operator +=(const point_f& pt) noexcept;
      
      /// @brief Translates a xtd::drawing::point_f by the negative of a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point_f.
      /// @return A xtd::drawing::point_f structure that is translated by the negative of a given xtd::drawing::size structure.
      point_f operator -(const size& sz) const noexcept;
      /// @brief Translates a xtd::drawing::point_f by the negative of a given xtd::drawing::size_f.
      /// @param sz A xtd::drawing::size_f that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point_f.
      /// @return A xtd::drawing::point_f structure that is translated by the negative of a given xtd::drawing::size_f structure.
      point_f operator -(const size_f& sz) const noexcept;
      /// @brief Translates a xtd::drawing::point_f by the negative of a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point.
      /// @return A xtd::drawing::point_f structure that is translated by the negative of a given xtd::drawing::point structure.
      point_f operator -(const point& pt) const noexcept;
      /// @brief Translates a xtd::drawing::point by the negative of a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point.
      /// @return A xtd::drawing::point structure that is translated by the negative of a given xtd::drawing::point structure.
      point_f operator -(const point_f& pt) const noexcept;
      
      /// @brief Translates a xtd::drawing::point_f by the negative of a given xtd::drawing::size.
      /// @param sz A xtd::drawing::size that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point_f.
      /// @return A xtd::drawing::point_f structure that is translated by the negative of a given xtd::drawing::size structure.
      point_f& operator -=(const size& sz) noexcept;
      /// @brief Translates a xtd::drawing::point_f by the negative of a given xtd::drawing::size_f.
      /// @param sz A xtd::drawing::size_f that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point_f.
      /// @return A xtd::drawing::point_f structure that is translated by the negative of a given xtd::drawing::size_f structure.
      point_f& operator -=(const size_f& sz) noexcept;
      /// @brief Translates a xtd::drawing::point_f by the negative of a given xtd::drawing::point.
      /// @param pt A xtd::drawing::point that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f& operator -=(const point& pt) noexcept;
      /// @brief Translates a xtd::drawing::point_f by the negative of a given xtd::drawing::point_f.
      /// @param pt A xtd::drawing::point_f that specifies the pair of numbers to subtract from the coordinates of this xtd::drawing::point_f.
      /// @return The translated xtd::drawing::point_f.
      point_f& operator -=(const point_f& pt) noexcept;
      /// @}
      
    private:
      float x_ = 0;
      float y_ = 0;
    };
  }
}
