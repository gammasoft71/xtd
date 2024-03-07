/// @file
/// @brief Contains xtd::forms::padding class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a display device or multiple display devices on a single system.
    /// @par Header
    /// @code #include <xtd/forms/padding> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class forms_export_ padding : public object, public xtd::iequatable<padding> {
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Provides a Padding object with no padding.
      static const padding empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the padding class.
      padding() = default;
      
      /// @brief Initializes a new instance of the padding class using the supplied padding size for all edges.
      /// @param all The number of pixels to be used for padding for all edges.
      /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
      padding(int32 all); // Can't be explicit by design.
      
      /// @brief Initializes a new instance of the padding class using a separate padding size for each edge.
      /// @param left The padding size, in pixels, for the left edge.
      /// @param top The padding size, in pixels, for the top edge.
      /// @param right The padding size, in pixels, for the right edge.
      /// @param bottom The padding size, in pixels, for the bottom edge.
      /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
      padding(int32 left, int32 top, int32 right, int32 bottom);
      /// @}
      
      /// @cond
      padding(const padding&) = default;
      padding& operator =(const padding&) = default;
      /// @endcond
      
      /// @name Peorperties
      
      /// @{
      /// @brief Gets the padding value for all the edges.
      /// @return The padding, in pixels, for all edges if the same; otherwise, -1.
      /// @remarks When retrieving this property, if all the edges use the same padding value, then this common value is returned. Otherwise, -1 is returned to indicate that all the padding values are not equal.
      int32 all() const noexcept;
      /// @brief Sets the padding value for all the edges.
      /// @param all The padding, in pixels, for all edges if the same; otherwise, -1.
      /// @remarks When retrieving this property, if all the edges use the same padding value, then this common value is returned. Otherwise, -1 is returned to indicate that all the padding values are not equal.
      void all(int32 all);
      
      /// @brief Gets the padding value for the bottom edge.
      /// @return The padding, in pixels, for the bottom edge.
      /// @remarks Setting this value can also alter the all property.
      int32 bottom() const noexcept;
      /// @brief Sets the padding value for the bottom edge.
      /// @param bottom The padding, in pixels, for the bottom edge.
      /// @remarks Setting this value can also alter the all property.
      void bottom(int32 bottom);
      
      /// @brief Gets the combined padding for the right and left edges.
      /// @return Gets the sum, in pixels, of the left and right padding values.
      int32 horizontal() const noexcept;
      
      /// @brief Gets the padding value for the left edge.
      /// @return The padding, in pixels, for the left edge.
      /// @remarks Setting this value can also alter the all property.
      int32 left() const noexcept;
      /// @brief Sets the padding value for the left edge.
      /// @param left The padding, in pixels, for the left edge.
      /// @remarks Setting this value can also alter the all property.
      void left(int32 left);
      
      /// @brief Gets the padding value for the right edge.
      /// @return The padding, in pixels, for the right edge.
      /// @remarks Setting this value can also alter the all property.
      int32 right() const noexcept;
      /// @brief Sets the padding value for the right edge.
      /// @param right The padding, in pixels, for the right edge.
      /// @remarks Setting this value can also alter the all property.
      void right(int32 right);
      
      /// @brief Gets the padding value for the top edge.
      /// @return The padding, in pixels, for the top edge.
      /// @remarks Setting this value can also alter the all property.
      int32 top() const noexcept;
      /// @brief Sets the padding value for the top edge.
      /// @param top The padding, in pixels, for the top edge.
      /// @remarks Setting this value can also alter the all property.
      void top(int32 top);
      
      /// @brief Gets the combined padding for the bottom and top edges.
      /// @param p1 A padding.
      /// @param p2 A padding.
      /// @return Gets the sum, in pixels, of the top and bottom padding values.
      int32 vertical() const noexcept;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      bool equals(const padding& value) const noexcept override;
      
      /// @brief Returns a string that represents the current padding.
      /// @return A string that represents the current padding.
      /// @remarks This method returns a string containing the labeled values of the padding for all four edges.
      xtd::ustring to_string() const noexcept override;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Computes the sum of the two specified padding values.
      /// @return A padding that contains the sum of the two specified padding values.
      static padding add(const padding& p1, const padding& p2);
      
      /// @brief Subtracts one specified Padding value from another.
      /// @param p1 A padding.
      /// @param p2 A padding.
      /// @return A padding that contains the result of the subtraction of one specified padding value from another.
      static padding subtract(const padding& p1, const padding& p2);
      /// @}

    private:
      bool all_ = true;
      int32 left_ = 0;
      int32 top_ = 0;
      int32 right_ = 0;
      int32 bottom_ = 0;
    };
  }
}
