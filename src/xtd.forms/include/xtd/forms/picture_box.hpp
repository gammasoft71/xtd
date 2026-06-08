/// @file
/// @brief Contains xtd::forms::picture_box control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "border_sides.hpp"
#include "border_style.hpp"
#include "control.hpp"
#include "picture_box_size_mode.hpp"
#include <xtd/drawing/image>
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows picture box.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/picture_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                  | macOS                                    | Gnome                                    |
    /// | ----- | ---------------------------------------- | ---------------------------------------- | ---------------------------------------- |
    /// | Light |  @image html control_picture_box_w.png   |  @image html control_picture_box_m.png   |  @image html control_picture_box_g.png   |
    /// | Dark  |  @image html control_picture_box_wd.png  |  @image html control_picture_box_md.png  |  @image html control_picture_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of picture box control.
    /// @include picture_box.cpp
    class forms_export_ picture_box : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      picture_box();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the bitwise combination values. The default is border_style::all.
      [[nodiscard]] virtual auto border_sides() const noexcept -> xtd::forms::border_sides;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual auto border_sides(xtd::forms::border_sides border_sides) -> picture_box&;
      
      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      [[nodiscard]] virtual auto border_style() const noexcept -> xtd::forms::border_style;
      /// @brief Sets the border style for the control.
      /// @param value One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current picture_box.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual auto border_style(forms::border_style value) -> picture_box&;
      /// @brief Resets the border style for the control.
      /// @param xtd::null.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual auto border_style(xtd::null_ptr) -> picture_box&;
      
      /// @brief Gets the image that is displayed by picture_box.
      /// @return The xtd::drawing::image to display.
      /// @remarks The image property is set to the xtd::drawing::image to display. You can do this either at design time or at run time.
      [[nodiscard]] virtual auto image() const noexcept -> std::optional<xtd::drawing::image>;
      /// @brief Sets the image that is displayed by picture_box.
      /// @param value The xtd::drawing::image to display.
      /// @return Current picture_box.
      /// @remarks The image property is set to the xtd::drawing::image to display. You can do this either at design time or at run time.
      virtual auto image(const xtd::drawing::image& value) -> picture_box&;
      /// @brief Resets the image that is displayed by picture_box.
      /// @param xtd::null.
      /// @return Current picture_box.
      /// @remarks The image property is set to the xtd::drawing::image to display. You can do this either at design time or at run time.
      virtual auto image(xtd::null_ptr) -> picture_box&;
      
      /// @brief Indicates how the image is displayed.
      /// @return One of the picture_box_size_mode values. The default is normal.
      /// @remarks By default, in normal mode, the Image is positioned in the upper-left corner of the picture_box, and any part of the image that is too big for the picture_box is clipped. Using the stretch_image value causes the image to stretch or shrink to fit the picture_box. Using the zoom value causes the image to be stretched or shrunk to fit the picture_box; however, the aspect ratio in the original is maintained.
      [[nodiscard]] auto size_mode() const noexcept -> xtd::forms::picture_box_size_mode;
      /// @brief Indicates how the image is displayed.
      /// @param value One of the picture_box_size_mode values. The default is normal.
      /// @return Current picture_box.
      /// @remarks By default, in normal mode, the Image is positioned in the upper-left corner of the picture_box, and any part of the image that is too big for the picture_box is clipped. Using the stretch_image value causes the image to stretch or shrink to fit the picture_box. Using the zoom value causes the image to be stretched or shrunk to fit the picture_box; however, the aspect ratio in the original is maintained.
      auto size_mode(xtd::forms::picture_box_size_mode value) -> picture_box&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create() -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image.
      /// @param image The image that is displayed by picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image, and location.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image, const xtd::drawing::point& location) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image, location, and size.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image, location, size, and name.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image, and location.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode, const xtd::drawing::point& location) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image, location, and size.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified image, location, size, and name.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, and image.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, and location.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image, const xtd::drawing::point& location) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, and image.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, and location.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode, const xtd::drawing::point& location) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size) -> picture_box;
      /// @brief A factory to create an xtd::forms::picture_box with specified parent, image, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::picture_box.
      /// @param image The image that is displayed by picture_box.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::picture_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::picture_box.
      /// @param name The name of the xtd::forms::picture_box.
      /// @return New xtd::forms::picture_box created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::image& image, xtd::forms::picture_box_size_mode size_mode, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> picture_box;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      
      /// @brief Overrides the on_handle_created(const event_args&) method.
      /// @param e An event_args that contains the event data.
      auto on_handle_created(const xtd::event_args& e) -> void override;
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
