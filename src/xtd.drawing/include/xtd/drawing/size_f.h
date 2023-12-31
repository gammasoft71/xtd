/// @file
/// @brief Contains xtd::drawing::size_f class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class point_f;
    class size;
    /// @endcond
    
    /// @brief Stores an ordered pair of floating-point, which specify a height and width.
    /// @code
    /// class drawing_export_ size_f : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::size_f
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    class drawing_export_ size_f : public xtd::object, public xtd::iequatable<size_f> {
    public:
      /// @name Fields
      
      /// @{
      /// @brief Gets a Size class that has a Height and Width value of 0. This field is constant.
      static const xtd::drawing::size_f empty;
      /// @}
      
      /// @name Constructors
      
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
      
      /// @name Properties
      
      /// @{
      /// @brief Gets he vertical component of this xtd::drawing::size_f class.
      /// @return The vertical component of this xtd::drawing::size_f class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size_f::height and xtd::drawing::size_f::width of the xtd::drawing::size_f class depend on the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::graphics object that is used to draw.
      float height() const noexcept;
      
      /// @brief Sets the vertical component of this xtd::drawing::size_f Class.
      /// @param value The vertical component of this xtd::drawing::size_f class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size_f::height and xtd::drawing::size_f::width of the xtd::drawing::size_f class depend on the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::graphics object that is used to draw.
      void height(float value) noexcept;
      
      /// @brief Tests whether this Size class has xtd::drawing::size_f::width and xtd::drawing::size_f::height of 0.
      /// @return Returns true  when this xtd::drawing::size_f class has both a xtd::drawing::size_fwidth and xtd::drawing::size_fheight of 0; otherwise, false.
      bool is_empty() const noexcept;
      
      /// @brief Gets the horizontal component of this xtd::drawing::size_f class.
      /// @return The horizontal component of this xtd::drawing::size_f class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size_f::height and xtd::drawing::size_f::width of the xtd::drawing::size_f class depend on the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::graphics object that is used to draw.
      float width() const noexcept;
      
      /// @brief Sets the horizontal component of this xtd::drawing::size_f class.
      /// @param value The horizontal component of this xtd::drawing::size_f class, typically measured in pixels.
      /// @remarks The unit for the xtd::drawing::size_f::height and xtd::drawing::size_f::width of the xtd::drawing::size_f class depend on the xtd::drawing::graphics::page_unit and xtd::drawing::graphics::page_scale settings for the xtd::drawing::graphics object that is used to draw.
      void width(float value) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Adds the width and height of one xtd::drawing::size_f class to the width and height of another xtd::drawing::size_f class.
      /// @param size1 The first xtd::drawing::size_f class to add.
      /// @param size2 The second xtd::drawing::size_f class to add.
      /// @return A xtd::drawing::size_f class that is the result of the addition operation.
      static xtd::drawing::size_f add(const xtd::drawing::size_f& size1, const xtd::drawing::size_f& size2) noexcept;
      
      bool equals(const xtd::drawing::size_f& value) const noexcept override;
      
      /// @brief Returns the result of subtracting specified xtd::drawing::size_f from the specified xtd::drawing::size_f.
      /// @param sz1 The xtd::drawing::size_f to be subtracted from.
      /// @param sz2 The xtd::drawing::size_f to subtract from the Size.
      /// @return The xtd::drawing::size_f that is the result of the subtraction operation.
      static xtd::drawing::size_f subtract(const xtd::drawing::size_f& sz1, const xtd::drawing::size_f& sz2) noexcept;
      
      /// @brief Creates a human-readable string that represents this xtd::drawing::size_f class.
      /// @return A xtd::ustring that represents this size.
      xtd::ustring to_string() const noexcept override;
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
      
    private:
      float width_ = 0;
      float height_ = 0;
    };
  }
  
  /// @cond
  template<>
  inline drawing::size_f parse<drawing::size_f>(const std::string& str) {
    auto values = xtd::ustring(str).replace("}", "").replace(" height=", "").replace("{width=", "").split({','});
    return {xtd::parse<float>(values[0]), xtd::parse<float>(values[1])};
  }
  /// @endcond
}
