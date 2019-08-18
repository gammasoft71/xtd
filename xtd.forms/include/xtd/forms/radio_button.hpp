#pragma once
#include "appearance.hpp"
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class radio_button : public control {
    public:
      radio_button() = default;

      virtual forms::appearance appearance() const {return this->appearance_;}
      virtual radio_button& appearance(forms::appearance appearance);
      
      drawing::size default_size() const override {return {104, 24};}

      virtual bool auto_check() const {return this->auto_check_;}
      virtual radio_button& auto_check(bool auto_check);
      
      virtual bool checked() const {return this->checked_;}
      virtual radio_button& checked(bool checked);
      
      void create_handle() override;
      
      event<radio_button, event_handler<control>> appearance_changed;

      event<radio_button, event_handler<control>> checked_changed;

    protected:
      virtual void on_appearance_changed(const event_args& e) {this->appearance_changed(*this, e);}
      
      virtual void on_checked_changed(const event_args& e) {this->checked_changed(*this, e);}
      
      void wnd_proc(message& message) override;

    private:
      void wm_mouse_double_click(message& message);
      void wm_mouse_up(message& message);

      forms::appearance appearance_ = forms::appearance::normal;
      bool auto_check_ = true;
      bool checked_ = false;
    };
  }
}
