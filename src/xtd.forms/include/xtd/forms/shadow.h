/// @file
/// @brief Contains xtd::forms::shadow class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/drawing/color>
#include <xtd/drawing/point>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a shadow within a xtd::forms::shadow_label control.
    /// @par Header
    /// @code #include <xtd/forms/shadow> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The xtd::forms::shadow_label::shadow class defines the properties of a shadow within a xtd::forms::shadow_label control. You can use these properties to provide data to the xtd::forms::shadow_label::shadow_clicked event of the xtd::forms::shadow_label control to perform tasks when the shadow is clicked in the control. The xtd::forms::shadow_label::shadow_data property enables you to define information that the xtd::forms::shadow_label::shadow_clicked event can use to display a URL within your web browser or to open a file.
    /// @remarks In addition to information related to the shadow, the properties of the xtd::forms::shadow_label::shadow class also help define the text of the xtd::forms::shadow_label::lLink and its display state. The xtd::forms::shadow_label::start and xtd::forms::shadow_label::length properties define the location and length of text from the text of the xtd::forms::shadow_label control to display as a shadow. The xtd::forms::shadow_label::enabled property allows you to display the shadow as a disabled shadow, and the xtd::forms::shadow_label::visited property can alert the user that they already visited the specified shadow in the current instance of the xtd::forms::shadow_label.
    /// @remarks You can display multiple shadows in a single xtd::forms::shadow_label control. Each xtd::forms::shadow_label::shadow is added into the xtd::forms::shadow_label::shadow_collection associated with the xtd::forms::shadow_label control. To obtain the collection of shadows defined in a xtd::forms::shadow_label control, use the xtd::forms::shadow_label::shadows property.
    class forms_export_ shadow : public object, public xtd::iequatable<shadow> {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::shadow class.
      /// @remarks When you create an instance of xtd::forms::shadow, the following read/write properties are set to initial values.
      /// | Property | Initial Value                                                 |
      /// | -------- | ------------------------------------------------------------- |
      /// | color    | xtd::application::style_sheet().system_colors().shadow_text() |
      /// | offset x | 2                                                             |
      /// | offset y | 2                                                             |
      /// | radius   | 0                                                             |
      shadow();
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset x, and offset y.
      /// @param x The shadow offset x in pixels.
      /// @param y The shadow offset y in pixels.
      shadow(int32 x, int32 y);
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset x, offset y, and radius.
      /// @param x The shadow offset x in pixels.
      /// @param y The shadow offset y in pixels.
      /// @param radius The shadow blurring radius.
      shadow(int32 x, int32 y, int32 radius);
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset x, offset y and color.
      /// @param x The shadow offset x in pixels.
      /// @param y The shadow offset y in pixels.
      shadow(int32 x, int32 y, const xtd::drawing::color& color);
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset x, offset y, and color.
      /// @param x The shadow offset x in pixels.
      /// @param y The shadow offset y in pixels.
      /// @param radius The shadow blurring radius.
      shadow(int32 x, int32 y, int32 radius, const xtd::drawing::color& color);
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset point.
      /// @param offset The shadow offset point in pixels.
      explicit shadow(const xtd::drawing::point& offset);
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset point, and radius.
      /// @param offset The shadow offset point in pixels.
      /// @param radius The shadow blurring radius.
      shadow(const xtd::drawing::point& offset, int32 radius);
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset point, and color.
      /// @param offset The shadow offset point in pixels.
      /// @param color The shadow color.
      shadow(const xtd::drawing::point& offset, const xtd::drawing::color& color);
      /// @brief Initializes a new instance of the xtd::forms::shadow class with the specified offset point, radius, and color.
      /// @param offset The shadow offset point in pixels.
      /// @param radius The shadow blurring radius.
      /// @param color The shadow color.
      shadow(const xtd::drawing::point& offset, int32 radius, const xtd::drawing::color& color);
      /// @}
      
      /// @cond
      shadow(const shadow&);
      shadow(shadow&&) = default;
      shadow& operator =(const shadow&);
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the shadow color.
      /// @return The shadow color.
      const xtd::drawing::color& color() const noexcept;
      /// @brief Sets the shadow color.
      /// @param value The shadow color.
      /// @return This current instance.
      shadow& color(const xtd::drawing::color& value) noexcept;
      /// @brief Gets the shadow offset in pixels.
      /// @return The shadow offset.
      const xtd::drawing::point& offset() const noexcept;
      /// @brief Sets the shadow offset point in pixels.
      /// @param value The shadow offset point.
      /// @return This current instance.
      shadow& offset(const xtd::drawing::point& value) noexcept;
      /// @brief Gets the shadow blurring radius in pixels.
      /// @return The shadow blurring radius.
      int32 radius() const noexcept;
      /// @brief Sets the shadow blurring radius in pixels.
      /// @param value The shadow blurring radius.
      /// @return This current instance.
      shadow& radius(int32 value) noexcept;
      /// @brief Gets the shadow offset x in pixels.
      /// @return The shadow offset x.
      int32 x() const noexcept;
      /// @brief Sets the shadow offset x in pixels.
      /// @param value The shadow offset x.
      /// @return This current instance.
      shadow& x(int32 value) noexcept;
      /// @brief Gets the shadow offset y in pixels.
      /// @return The shadow offset y.
      int32 y() const noexcept;
      /// @brief Sets the shadow offset y in pixels.
      /// @param value The shadow offset y.
      /// @return This current instance.
      shadow& y(int32 value) noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const shadow& other) const noexcept override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}

