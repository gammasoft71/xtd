#pragma once
#include "appearance.hpp"
#include "check_state.hpp"
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class check_box : public control {
    public:
      check_box() = default;

      virtual forms::appearance appearance() const {return this->appearance_;}
      virtual check_box& appearance(forms::appearance appearance);

      virtual bool auto_check() const {return this->auto_check_;}
      virtual check_box& auto_check(bool auto_check);
      
      virtual bool checked() const {return this->checked_;}
      virtual check_box& checked(bool checked);
      
      virtual forms::check_state check_state() const {return this->check_state_;}
      virtual check_box& check_state(forms::check_state check_state);
      
      drawing::size default_size() const override {return {104, 24};}
      
      virtual bool three_state() const {return this->three_state_;}
      virtual check_box& three_state(bool three_state);
      
      void create_handle() override;
      
      event<check_box, event_handler<control>> appearance_changed;
      
      event<check_box, event_handler<control>> checked_changed;
      
      event<check_box, event_handler<control>> check_state_changed;

    protected:
      virtual void on_appearance_changed(const event_args& e) {this->appearance_changed(*this, e);}
      
      virtual void on_checked_changed(const event_args& e) {this->checked_changed(*this, e);}
      
      virtual void on_check_state_changed(const event_args& e) {this->check_state_changed(*this, e);}

      void wnd_proc(message& message) override;

      virtual void wm_reflect_command(message& message);

    private:
      void wm_mouse_double_click(message& message);
      void wm_mouse_down(message& message);

      forms::appearance appearance_ = forms::appearance::normal;
      bool auto_check_ = true;
      bool three_state_ = 0;
      bool checked_ = false;
      forms::check_state check_state_ = forms::check_state::unchecked;
    };
  }
}
