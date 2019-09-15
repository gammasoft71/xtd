#pragma once
#include "button_base.hpp"
#include "dialog_result.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class button : public button_base {
    public:
      button();

      /// @cond
      button(const button& value) : button_base(value) {this->data_ = value.data_;}
      button& operator=(const button& value);
      /// @endcond

      virtual forms::auto_size_mode auto_size_mode() const {return this->control::data_->auto_size_mode_;}
      virtual button& auto_size_mode(forms::auto_size_mode value);

      forms::dialog_result dialog_result() const {return this->data_->dialog_result_;}
      button& dialog_result(forms::dialog_result dialog_result);
      
    protected:
      forms::create_params create_params() const override;
      
      void on_click(const event_args& e) override;

      /// @cond
      struct data {
        forms::dialog_result dialog_result_ = forms::dialog_result::none;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
      /// @endcond
   };
  }
}
