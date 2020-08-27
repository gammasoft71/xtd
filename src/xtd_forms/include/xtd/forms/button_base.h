#pragma once
#include <xtd/drawing/image.h>
#include "control.h"
#include "content_alignment.h"
#include "image_list.h"
#include "flat_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Implements the basic functionality common to button controls.
    /// @remarks You do not typically inherit from button_base. To create your own button class, inherit from the button, check_box, or radio_button class.
    /// @remarks To have the derived button control display an image, set the Image property or the image_list and image_index properties. The image can be aligned on the button control by setting the image_align property. Likewise, to align the text displayed on the button control, set the text_align property.
    /// @remarks The flat_style property determines the style and appearance of the control. If the flat_style property is set to flat_style::system, the user's operating system determines the appearance of the control.
    class button_base : public control {
    public:      
      /// @brief Gets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
      /// @return true if the additional label text is to be indicated by an ellipsis; otherwise, false. The default is true.
      /// @remarks Set auto_ellipsis to true to display text that extends beyond the width of the control when the user passes over the control with the mouse. You must set the control's auto_size property to false if you want AutoEllipsis to be true. If AutoSize is true, the control will grow to fit the text and an ellipsis will not appear.
      bool auto_ellipsis() const {return this->auto_ellipsis_;}
      
      /// @brief Sets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
      /// @param true if the additional label text is to be indicated by an ellipsis; otherwise, false. The default is true.
      /// @remarks Set auto_ellipsis to true to display text that extends beyond the width of the control when the user passes over the control with the mouse. You must set the control's auto_size property to false if you want AutoEllipsis to be true. If AutoSize is true, the control will grow to fit the text and an ellipsis will not appear.
      virtual button_base& auto_ellipsis(bool auto_ellipsis) {
        if (this->auto_ellipsis_ != auto_ellipsis)
          this->auto_ellipsis_ = auto_ellipsis;
        return *this;
      }
      
      /// @brief Gets a value that indicates whether the control resizes based on its contents.
      /// @return true if enabled; otherwise, false.
      bool auto_size() const override {return this->control::auto_size();}
      
      /// @brief Sets a value that indicates whether the control resizes based on its contents.
      /// @param auto_size true if enabled; otherwise, false.
      control& auto_size(bool auto_size) override {
        this->control::auto_size(auto_size);
        if (this->get_state(state::auto_size))
          this->auto_ellipsis_ = false;
        return *this;
      }
      
      virtual xtd::forms::flat_style flat_style() const {return flat_style_;}
      virtual xtd::forms::button_base& flat_style(xtd::forms::flat_style flat_style);

      virtual const drawing::image& image() const {return image_;}
      virtual button_base& image(const drawing::image& value);
      
      /// @brief Gets the alignment of the image on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      virtual content_alignment image_align() const {return image_align_;}
      /// @brief Gets the alignment of the image on the button control.
      /// @param value One of the content_alignment values. The default is middle_center.
      virtual button_base& image_align(content_alignment value);
      
      virtual int32_t image_index() const {return image_index_;}
      virtual button_base& image_index(int32_t value);

      virtual const forms::image_list& image_list() const {return image_list_;}
      virtual button_base& image_list(const forms::image_list& value);

      /// @brief Gets the alignment of the text on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      virtual content_alignment text_align() const {return text_align_;}
      /// @brief Gets the alignment of the text on the button control.
      /// @param value One of the content_alignment values. The default is middle_center.
      virtual button_base& text_align(content_alignment value);

    protected:
      /// @brief Initializes a new instance of the ButtonBase class.
      button_base();

      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const override;
      
      /// @brief Gets the default size of the control.
      /// @return The default Size of the control.
      drawing::size default_size() const override {return {75, 25};}

      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This method is used when auto_size is true.
      drawing::size measure_control() const override;
      
    protected:
      /// @cond
      bool auto_ellipsis_ = false;
      /// @todo set flat_style_ to xtd::forms::flat_style::standard for all platforms.
      xtd::forms::flat_style flat_style_ = xtd::forms::flat_style::system;
      drawing::image image_ = drawing::image::empty;
      forms::image_list image_list_;
      int32_t image_index_ = -1;
      content_alignment image_align_ = content_alignment::middle_center;
      content_alignment text_align_ = content_alignment::middle_center;
      /// @endcond
    };
  }
}
