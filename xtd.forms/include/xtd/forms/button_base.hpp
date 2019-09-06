#pragma once
#include "control.hpp"

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
      /// @cond
      button_base(const button_base& value) {*this = value;}
      button_base& operator=(const button_base& value);
      /// @endcond
      
      /// @brief Gets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
      /// @return true if the additional label text is to be indicated by an ellipsis; otherwise, false. The default is true.
      /// @remarks Set auto_ellipsis to true to display text that extends beyond the width of the control when the user passes over the control with the mouse. You must set the control's auto_size property to false if you want AutoEllipsis to be true. If AutoSize is true, the control will grow to fit the text and an ellipsis will not appear.
      bool auto_ellipsis() const {return this->data_->auto_ellipsis_;}
      
      /// @brief Sets a value indicating whether the ellipsis character (...) appears at the right edge of the control, denoting that the control text extends beyond the specified length of the control.
      /// @param true if the additional label text is to be indicated by an ellipsis; otherwise, false. The default is true.
      /// @remarks Set auto_ellipsis to true to display text that extends beyond the width of the control when the user passes over the control with the mouse. You must set the control's auto_size property to false if you want AutoEllipsis to be true. If AutoSize is true, the control will grow to fit the text and an ellipsis will not appear.
      virtual button_base& auto_ellipsis(bool auto_ellipsis) {
        if (this->data_->auto_ellipsis_ != auto_ellipsis)
          this->data_->auto_ellipsis_ = auto_ellipsis;
        return *this;
      }
      
      /// @brief Gets a value that indicates whether the control resizes based on its contents.
      /// @return true if enabled; otherwise, false.
      bool auto_size() const {return this->control::auto_size();}
      
      /// @brief Sets a value that indicates whether the control resizes based on its contents.
      /// @param auto_size true if enabled; otherwise, false.
      control& auto_size(bool auto_size) {
        this->control::auto_size(auto_size);
        if (this->control::data_->auto_size_)
          this->data_->auto_ellipsis_ = false;
        return *this;
      }

      /// @brief Gets the default size of the control.
      /// @return The default Size of the control.
      drawing::size default_size() const override {return {75, 25};}
      
    protected:
      /// @brief Initializes a new instance of the ButtonBase class.
      button_base();

      /// @brief Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const override;

      drawing::size measure_control() const override;
      
    private:
      struct data {
        bool auto_ellipsis_ = false;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
