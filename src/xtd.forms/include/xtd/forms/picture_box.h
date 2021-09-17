/// @file
/// @brief Contains xtd::forms::picture_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <optional>
#include "control.h"
#include "border_style.h"
#include "picture_box_size_mode.h"
#include <xtd/drawing/image.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows picture box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of picture box control.
    /// @include picture_box.cpp
    class forms_export_ picture_box : public control {
    public:
      picture_box();

      /// @brief Gets the border style for the control.
      /// @return One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual forms::border_style border_style() const {return border_style_;}
      /// @brief Sets the border style for the control.
      /// @param border_style One of the xtd::forms::border_style values. The default is xtd::forms::border_style::none.
      /// @return Current picture_box.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual picture_box& border_style(forms::border_style border_style);

      drawing::size default_size() const override {return {100, 50};}
      
      /// @brief Gets the image that is displayed by picture_box.
      /// @return The xtd::drawing::image to display.
      /// @remarks The image property is set to the xtd::drawing::image to display. You can do this either at design time or at run time.
      const std::optional<drawing::image> image() const {return image_;}
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
      picture_box_size_mode size_mode() const {return size_mode_;}
      /// @brief Indicates how the image is displayed.
      /// @param size_mode One of the picture_box_size_mode values. The default is normal.
      /// @return Current picture_box.
      /// @remarks By default, in normal mode, the Image is positioned in the upper-left corner of the picture_box, and any part of the image that is too big for the picture_box is clipped. Using the stretch_image value causes the image to stretch or shrink to fit the picture_box. Using the zoom value causes the image to be stretched or shrunk to fit the picture_box; however, the aspect ratio in the original is maintained.
      picture_box& size_mode(picture_box_size_mode size_mode);

    protected:
      forms::create_params create_params() const override;

      /// @brief Overrides the on_handle_created(const event_args&) method.
      /// @param e An event_args that contains the event data.
      void on_handle_created(const event_args& e) override;

      drawing::size measure_control() const override;

      /// @cond
      forms::border_style border_style_ = forms::border_style::none;
      std::optional<drawing::image> image_;
      picture_box_size_mode size_mode_ = picture_box_size_mode::normal;
      /// @endcond
    };
  }
}
