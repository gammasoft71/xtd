#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class color_picker : public control {
    public:
      color_picker();

      const drawing::color& color() const {return color_;}
      void color(const drawing::color& color);
      
      drawing::size default_size() const override {return {100, 25};}
      
      
      /// @brief Gets a value indicating whether the dialog box  shows alpha values and an opacity selector (slider).
      /// @return true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false. The default is true.
      bool alpha_color() const {return alpha_color_;}
      /// @brief Sets a value indicating whether the user can use the dialog box to define custom colors.
      /// @param alpha_color true if the dialog box  shows alpha values and an opacity selector (slider); otherwise, false.
      color_picker& alpha_color(bool alpha_color) {
        if (alpha_color_ != alpha_color) {
          alpha_color_ = alpha_color;
          recreate_handle();
        }
        return *this;
      }

      event<color_picker, event_handler<control&>> color_changed;
      
    protected:
      forms::create_params create_params() const override;
      
      void on_color_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;
      
    private:
      void wm_click(message& message);
      drawing::color color_;
      bool alpha_color_ = false;
    };
  }
}
