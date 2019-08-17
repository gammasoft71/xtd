#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class radio_button : public control {
    public:
      radio_button() = default;

      drawing::size default_size() const override {return {104, 24};}

      bool auto_check() const {return this->auto_check_;}
      radio_button& auto_check(bool auto_check);
      
      bool checked() const {return this->checked_;}
      radio_button& checked(bool checked);
      
      void create_handle() override;
      
      event<radio_button, event_handler<control>> checked_changed;

    protected:
      virtual void on_checked_changed(const event_args& e) {this->checked_changed(*this, e);}
      
      void wnd_proc(message& message) override;

      virtual void wm_reflect_command(message& message);
      
    private:
      bool auto_check_ = true;
      bool checked_ = false;
    };
  }
}
