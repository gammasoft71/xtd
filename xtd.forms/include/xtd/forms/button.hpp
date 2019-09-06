#pragma once
#include "button_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class button : public button_base {
    public:
      button();

      /// @cond
      button(const button& value) {*this = value;}
      button& operator=(const button& value);
      /// @endcond

      forms::auto_size_mode auto_size_mode() const {return this->control::data_->auto_size_mode_;}
      virtual button& auto_size_mode(forms::auto_size_mode value);

    protected:
      forms::create_params create_params() const override;
    };
  }
}
