#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class font_picker : public control {
    public:
      font_picker();

      const drawing::color& color() const {return color_;}
      control& color(const drawing::color& color);
      
      drawing::font font() const override {return font_;}
      control& font(const drawing::font& font) override;
      
      drawing::size default_size() const override {return{100, 25};}
      
      event<font_picker, event_handler<control&>> font_changed;

    protected:
      forms::create_params create_params() const override;
      
      void on_font_changed(const event_args& e) override;
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
    private:
      void wm_click(message& message);
      drawing::color color_;
      drawing::font font_ = default_font();
    };
  }
}
