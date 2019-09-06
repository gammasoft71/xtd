#pragma once
#include "appearance.hpp"
#include "button_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class radio_button : public button_base {
    public:
      radio_button();

      /// @cond
      radio_button(const radio_button& value) {*this = value;}
      radio_button& operator=(const radio_button& value);
      /// @endcond

      virtual forms::appearance appearance() const {return this->data_->appearance_;}
      virtual radio_button& appearance(forms::appearance appearance);
      
      drawing::size default_size() const override {return {104, 24};}

      virtual bool auto_check() const {return this->data_->auto_check_;}
      virtual radio_button& auto_check(bool auto_check);
      
      virtual bool checked() const {return this->data_->checked_;}
      virtual radio_button& checked(bool checked);
      
      event<radio_button, event_handler<control>> appearance_changed;

      event<radio_button, event_handler<control>> checked_changed;

    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;

      virtual void on_appearance_changed(const event_args& e) {this->appearance_changed(*this, e);}
      
      virtual void on_checked_changed(const event_args& e) {this->checked_changed(*this, e);}
      
      void on_handle_created(const event_args& e) override;
      
      void wnd_proc(message& message) override;

    private:
      void wm_mouse_double_click(message& message);
      void wm_mouse_up(message& message);

      struct data {
        forms::appearance appearance_ = forms::appearance::normal;
        bool auto_check_ = true;
        bool checked_ = false;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
