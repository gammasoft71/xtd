/// @file
/// @brief Contains xtd::drawing::size_f class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include <xtd/icomparable>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/string>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    struct point_f;
    struct size;
    /// @endcond
    
    /// @brief Stores an ordered pair of floating-point, which specify a height and width.
    /// ```cpp
    /// class drawing_export_ size_f : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::drawing::size_f
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing coordinates
    struct drawing_export_ size_f : xtd::object, xtd::icomparable<size_f>, xtd::iequatable<size_f> {
      /// @name Public Fields
      
      /// @{
      /// @brief Gets a Size class that has a Height and Width value of 0. This field is constant.
      static const xtd::drawing::size_f empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the Size class that has a Height and Width value of 0.
      size_f() noexcept = default;
      
      /// @brief Initializes a new instance of the xtd::drawing::size_f class from the specified xtd::drawing::point_f class.
      /// @param point The xtd::drawing::point_f class from which to initialize this xtd::drawing::size_f class
      explicit size_f(const xtd::drawing::point_f& point) noexcept;
      
      /// @brief Initializes a new instance of the xtd::drawing::size_f class from the specified dimensions.
      /// @param width The width component of the new xtd::drawing::size_f.
      /// @param height The height component of the new xtd::drawing::size_f.
      size_f(float width, float height) noexcept;
      /// @}
      
      /// @cond
      size_f(const xtd::drawing::size_f&) noexcept = default;
      size_f& operator =(const xtd::drawing::size_f& size) noexcept = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets or sets the horizontal component of this xtd::drawing::size_f class.
      /// @param width The horizontal component of this xtd::drawing::size_f class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size_f::height and xtd::drawing::size_f::width of the xtd::drawing::size_f class depend on the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::graphics object that is used to draw.
      float width = .0f;
      
      /// @brief Gets or sets he vertical component of this xtd::drawing::size_f class.
      /// @param height The vertical component of this xtd::drawing::size_f class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size_f::height and xtd::drawing::size_f::width of the xtd::drawing::size_f class depend on the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::graphics object that is used to draw.
      float height = .0f;
      
      /// @brief Tests whether this Size class has xtd::drawing::size_f::width and xtd::drawing::size_f::height of 0.
      /// @return Returns `true`  when this xtd::drawing::size_f class has both a xtd::drawing::size_fwidth and xtd::drawing::size_fheight of 0; otherwise, `false`.
      bool is_empty() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
      /// The return value has these meanings:
      ///
      /// | Value             | Condition                          |
      /// | ----------------- | ---------------------------------- |
      /// | Less than zero    | This instance is less than obj.    |
      /// | Zero              | This instance is equal to obj.     |
      /// | Greater than zero | This instance is greater than obj. |
      int32 compare_to(const xtd::drawing::size_f& obj) const noexcept override;
      /// @{
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const xtd::object& obj) const noexcept override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const xtd::drawing::size_f& other) const noexcept override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      xtd::size get_hash_code() const noexcept override;
      
      /// @brief Creates a human-readable string that represents this xtd::drawing::size_f class.
      /// @return A xtd::string that represents this size.
      xtd::string to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Adds the width and height of one xtd::drawing::size_f class to the width and height of another xtd::drawing::size_f class.
      /// @param size1 The first xtd::drawing::size_f class to add.
      /// @param size2 The second xtd::drawing::size_f class to add.
      /// @return A xtd::drawing::size_f class that is the result of the addition operation.
      static xtd::drawing::size_f add(const xtd::drawing::size_f& size1, const xtd::drawing::size_f& size2) noexcept;
      
      /// @brief Returns the result of subtracting specified xtd::drawing::size_f from the specified xtd::drawing::size_f.
      /// @param sz1 The xtd::drawing::size_f to be subtracted from.
      /// @param sz2 The xtd::drawing::size_f to subtract from the Size.
      /// @return The xtd::drawing::size_f that is the result of the subtraction operation.
      static xtd::drawing::size_f subtract(const xtd::drawing::size_f& sz1, const xtd::drawing::size_f& sz2) noexcept;
      /// @}
      
      /// @name Operators
      
      /// @{
      /// @brief Increases a xtd::drawing::size_f with a given xtd::drawing::size_f.
      /// @param size A xtd::drawing::size_f that specifies the pair of numbers to add to the size of this xtd::drawing::size_f.
      /// @return The increased xtd::drawing::size.
      size_f operator +(const xtd::drawing::size_f& size) const noexcept;
      /// @brief Increases a xtd::drawing::size_f with a given xtd::drawing::size.
      /// @param size A xtd::drawing::size that specifies the pair of numbers to add to the size of this xtd::drawing::size_f.
      /// @return The increased xtd::drawing::size_f.
      size_f operator +(const xtd::drawing::size& size) const noexcept;
      
      /// @brief Increases a xtd::drawing::size_f wuth a given xtd::drawing::size_f.
      /// @param size A xtd::drawing::size_f that specifies the pair of numbers to add to the size of this xtd::drawing::size_f.
      /// @return The increased xtd::drawing::size_f.
      size_f& operator +=(const xtd::drawing::size_f& size) noexcept;
      /// @brief Increases a xtd::drawing::size_f wuth a given xtd::drawing::size.
      /// @param size A xtd::drawing::size that specifies the pair of numbers to add to the size of this xtd::drawing::size_f.
      /// @return The increased xtd::drawing::size_f.
      size_f& operator +=(const xtd::drawing::size& size) noexcept;
      
      /// @brief Decreases a xtd::drawing::size_f with the a given xtd::drawing::size_f.
      /// @param size A xtd::drawing::size_f that specifies the pair of numbers to subtract from the size of this xtd::drawing::size_f.
      /// @return The decreased xtd::drawing::size_f.
      size_f operator -(const xtd::drawing::size_f& size) const noexcept;
      /// @brief Decreases a xtd::drawing::size_f with the a given xtd::drawing::size.
      /// @param size A xtd::drawing::size that specifies the pair of numbers to subtract from the size of this xtd::drawing::size_f.
      /// @return The decreased xtd::drawing::size_f.
      size_f operator -(const xtd::drawing::size& size) const noexcept;
      
      /// @brief Decreases a xtd::drawing::size_f with the a given xtd::drawing::size_f.
      /// @param size A xtd::drawing::size_f that specifies the pair of numbers to subtract from the size of this xtd::drawing::size_f.
      /// @return The decreased xtd::drawing::size_f.
      size_f& operator -=(const xtd::drawing::size_f& size) noexcept;
      /// @brief Decreases a xtd::drawing::size_f with the a given xtd::drawing::size.
      /// @param size A xtd::drawing::size that specifies the pair of numbers to subtract from the size of this xtd::drawing::size_f.
      /// @return The decreased xtd::drawing::size_f.
      size_f& operator -=(const xtd::drawing::size& size) noexcept;
      /// @}
    };
  }
  
  /// @cond
  template<>
  inline drawing::size_f parse<drawing::size_f>(const std::string& str) {
    auto values = xtd::string(str).replace("}", xtd::string::empty_string).replace(" height=", xtd::string::empty_string).replace("{width=", xtd::string::empty_string).split(',');
    return {xtd::parse<float>(values[0]), xtd::parse<float>(values[1])};
  }
  /// @endcond
}
