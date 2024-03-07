/// @file
/// @brief Contains xtd::forms::picture_box control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.h"
#include "border_style.h"
#include "control.h"
#include "picture_box_size_mode.h"
#include <xtd/drawing/image>
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows picture box.
    /// @par Header
    /// @code #include <xtd/forms/picture_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html control_picture_box_w.png   |  @image html control_picture_box_m.png   |  @image html control_picture_box_g.png   |
    /// | Dark  |  @image html control_picture_box_wd.png  |  @image html control_picture_box_md.png  |  @image html control_picture_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of picture box control.
    /// @include picture_box.cpp
    class forms_export_ picture_box : public control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      picture_box();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual picture_box& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual forms::border_style border_style() const noexcept;
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current picture_box.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual picture_box& border_style(forms::border_style border_style);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual picture_box& border_style(std::nullptr_t);

      /// @brief Gets the image that is displayed by picture_box.
      /// @return The xtd::drawing::image to display.
      /// @remarks The image property is set to the xtd::drawing::image to display. You can do this either at design time or at run time.
      std::optional<drawing::image> image() const noexcept;
      /// @brief Sets the image that is displayed by picture_box.
      /// @param image The xtd::drawing::image to display.
      /// @return Current picture_box.
      /// @remarks The image property is set to the xtd::drawing::image to display. You can do this either at design time or at run time.
      picture_box& image(const drawing::image& image);
      /// @brief Resets the image that is displayed by picture_box.
      /// @param nullptr.
      /// @return Current picture_box.
      /// @remarks The image property is set to the xtd::drawing::image to display. You can do this either at design time or at run time.
      picture_box& image(std::nullptr_t);
      
      /// @brief Indicates how the image is displayed.
      /// @return One of the picture_box_size_mode values. The default is normal.
      /// @remarks By default, in normal mode, the Image is positioned in the upper-left corner of the picture_box, and any part of the image that is too big for the picture_box is clipped. Using the stretch_image value causes the image to stretch or shrink to fit the picture_box. Using the zoom value causes the image to be stretched or shrunk to fit the picture_box; however, the aspect ratio in the original is maintained.
      picture_box_size_mode size_mode() const noexcept;
      /// @brief Indicates how the image is displayed.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @return Current picture_box.
      /// @remarks By default, in normal mode, the Image is positioned in the upper-left corner of the picture_box, and any part of the image that is too big for the picture_box is clipped. Using the stretch_image value causes the image to stretch or shrink to fit the picture_box. Using the zoom value causes the image to be stretched or shrunk to fit the picture_box; however, the aspect ratio in the original is maintained.
      picture_box& size_mode(picture_box_size_mode size_mode);
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create();
      /// @brief A factory to create an xtd::forms::picture_box with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::picture_box with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create( const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::picture_box with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::picture_box with specified image.
      /// @param image The image that is displayed by picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const xtd::drawing::image& image);
      /// @brief A factory to create an xtd::forms::picture_box with specified image, and location.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const xtd::drawing::image& image, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::picture_box with specified image, location, and size.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::picture_box with specified image, location, size, and name.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, and image.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent, const xtd::drawing::image& image);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, and location.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent, const xtd::drawing::image& image, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent, const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      static picture_box create(const control& parent, const xtd::drawing::image& image, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Overrides the on_handle_created(const event_args&) method.
      /// @param e An event_args that contains the event data.
      void on_handle_created(const event_args& e) override;
      void on_paint(paint_event_args& e) override;
      
      drawing::size measure_control() const noexcept override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
