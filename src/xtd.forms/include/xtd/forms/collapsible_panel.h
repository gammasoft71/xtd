#pragma once
#include "control.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class collapsible_panel : public control {
    public:
      collapsible_panel();

      /// @cond
      virtual bool auto_size() const override {return true;}
      /// @cond

      virtual forms::border_style border_style() const {return this->border_style_;}
      virtual collapsible_panel& border_style(forms::border_style border_style);

      drawing::size default_size() const override {return {0, 0};}
      
      bool expanded() const {return expanded_;}
      collapsible_panel& expanded(bool expanded);

      /// @cond
      const xtd::drawing::size& client_size() const override {return control::client_size();}
      const xtd::drawing::size& size() const override {return control::size();}
      /// @endcond

      void collapse() {expanded(false);}

      void expand() {expanded(true);}
      
      xtd::event<collapsible_panel, xtd::event_handler<control&>> expanded_changed;

    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      void on_expanded_changed(const xtd::event_args& e) {
        if (parent_) parent().value().get().perform_layout();
        expanded_changed(*this, e);
      }

      void on_handle_created(const event_args& e) override;

      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      void wnd_proc(message& message) override;

      forms::border_style border_style_ = forms::border_style::none;
      bool expanded_ = false;
      
    private:
      control& auto_size(bool auto_size) override {return control::auto_size(auto_size);}
      control& client_size(const xtd::drawing::size& client_size) override {return control::size(client_size);}
      control& size(const xtd::drawing::size& size) override {return control::size(size);}
      void wm_command(message& message);
    };
  }
}
