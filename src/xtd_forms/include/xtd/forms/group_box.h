#pragma once
#include "control.h"
#include "border_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class group_box : public control {
    public:
      group_box();

      virtual forms::auto_size_mode auto_size_mode() const {return this->auto_size_mode_;}
      virtual group_box& auto_size_mode(forms::auto_size_mode value);
      
      drawing::size default_size() const override {return{200, 100};}
      
    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
    };
  }
}
