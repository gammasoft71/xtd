#pragma once
#include "control.h"
#include "border_style.h"
#include "content_alignment.h"
#include "flat_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class label : public control {
    public:
      label();

      virtual xtd::forms::border_style border_style() const {return border_style_;}
      virtual xtd::forms::label& border_style(xtd::forms::border_style border_style);
      
      virtual xtd::forms::flat_style flat_style() const {return flat_style_;}
      virtual xtd::forms::label& flat_style(xtd::forms::flat_style flat_style);

      xtd::drawing::size default_size() const override {return {100, 23};}
      
      /// @brief Gets the alignment of the text on the button control.
      /// @return One of the content_alignment values. The default is middle_center.
      virtual xtd::forms::content_alignment text_align() const {return text_align_;}
      /// @brief Gets the alignment of the text on the button control.
      /// @param text_align One of the content_alignment values. The default is middle_center.
      virtual xtd::forms::label& text_align(xtd::forms::content_alignment text_align);

    protected:
      xtd::forms::create_params create_params() const override;
      
      xtd::drawing::size measure_control() const override;
      
      void on_font_changed(const xtd::event_args& e) override;

      void on_paint(xtd::forms::paint_event_args& e) override;
      
      void on_resize(const xtd::event_args& e) override;
      
      void on_text_changed(const xtd::event_args& e) override;

      xtd::forms::border_style border_style_ = xtd::forms::border_style::none;
      xtd::forms::flat_style flat_style_ = xtd::forms::flat_style::standard;
      xtd::forms::content_alignment text_align_ = xtd::forms::content_alignment::top_left;
    };
  }
}
