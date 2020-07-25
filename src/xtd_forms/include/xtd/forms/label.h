#pragma once
#include "control.h"
#include "border_style.h"
#include "content_alignment.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class label : public control {
    public:
      label();

      virtual forms::border_style border_style() const {return this->border_style_;}
      virtual label& border_style(forms::border_style border_style);
      
      drawing::size default_size() const override {return {100, 23};}
      
      /// @brief Gets the alignment of the text on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      virtual content_alignment text_align() const {return this->text_align_;}
      /// @brief Gets the alignment of the text on the button control.
      /// @param text_align One of the content_alignment values. The default is middle_center.
      virtual label& text_align(content_alignment text_align);

    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      forms::border_style border_style_ = forms::border_style::none;
      content_alignment text_align_ = content_alignment::top_left;
    };
  }
}
