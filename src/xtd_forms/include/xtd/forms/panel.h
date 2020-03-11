#pragma once
#include "scrollable_control.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class panel : public scrollable_control {
    public:
      panel();

      virtual forms::auto_size_mode auto_size_mode() const {return this->auto_size_mode_;}
      virtual panel& auto_size_mode(forms::auto_size_mode value);
      
      virtual forms::border_style border_style() const {return this->border_style_;}
      virtual panel& border_style(forms::border_style border_style);

      drawing::size default_size() const override {return{200, 100};}
      
    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;

      void on_layout(const event_args& e) override;
      
      forms::border_style border_style_ = forms::border_style::none;
    };
  }
}
