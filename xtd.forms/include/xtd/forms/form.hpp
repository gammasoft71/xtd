#pragma once
#include "form_closed_event_handler.hpp"
#include "form_closing_event_handler.hpp"
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class form : public control {
    public:
      form();

      /// @cond
      form(const form& value) = default;
      form& operator=(const form& value);
      /// @endcond

      forms::auto_size_mode auto_size_mode() const {return this->control::data_->auto_size_mode_;}
      virtual form& auto_size_mode(forms::auto_size_mode value);
      
      drawing::size default_size() const override {return{300, 300};}
      
      using control::parent;
      control& parent(const control& parent) override;

      void close();
      
      event<form, form_closed_event_handler<control>> form_closed;
      
      event<form, form_closing_event_handler<control>> form_closing;

    protected:
      forms::create_params create_params() const override;
   
      drawing::size measure_control() const override;

      void on_form_closed(const form_closed_event_args& e) {this->form_closed(*this, e);}
      
      void on_form_closing(form_closing_event_args& e) {this->form_closing(*this, e);}
      
      void wnd_proc(message& message) override;
      
      virtual void wm_close(message& message);

    private:
      struct data {
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
