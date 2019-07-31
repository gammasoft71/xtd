#pragma once
#include "check_state.hpp"
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class check_box : public control {
    public:
      check_box() = default;

      drawing::size default_size() const override {return {104, 24};}

      bool auto_check() const {return this->auto_check_;}
      void auto_check(bool auto_check);
      
      bool checked() const {return this->checked_;}
      void checked(bool checked);
      
      forms::check_state check_state() const {return this->check_state_;}
      void check_state(forms::check_state check_state);
      
      bool three_state() const {return this->three_state_;}
      void three_state(bool three_state);
      
      void create_handle() override;
      
      event<check_box, event_handler<control>> check_changed;
 
      event<check_box, event_handler<control>> check_state_changed;

    protected:
      virtual void on_check_changed(const event_args& e) {this->check_changed(*this, e);}
      
      virtual void on_check_state_changed(const event_args& e) {this->check_state_changed(*this, e);}

      void wnd_proc(message& message) override;

    private:
      void wm_reflect_command(message& message);
      
      bool auto_check_ = true;
      bool three_state_ = 0;
      bool checked_ = false;
      forms::check_state check_state_ = forms::check_state::unchecked;
    };
  }
}
