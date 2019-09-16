#pragma once
#include "button_base.hpp"
#include "dialog_result.hpp"
#include "ibutton_control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class button : public ibutton_control, public button_base {
    public:
      button() = default;

      virtual forms::auto_size_mode auto_size_mode() const {return this->auto_size_mode_;}
      virtual button& auto_size_mode(forms::auto_size_mode value);

      forms::dialog_result dialog_result() const override {return this->dialog_result_;}
      ibutton_control& dialog_result(forms::dialog_result dialog_result) override;
      
    protected:
      forms::create_params create_params() const override;
      
      void on_click(const event_args& e) override;

      /// @cond
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      /// @endcond
   };
  }
}
