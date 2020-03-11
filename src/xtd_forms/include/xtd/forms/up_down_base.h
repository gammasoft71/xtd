#pragma once
#include "border_style.h"
#include "container_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class up_down_base : public container_control {
    public:      
      
      virtual forms::border_style border_style() const {return border_style_;}
      virtual up_down_base& border_style(forms::border_style value);

    protected:
      up_down_base();

      forms::create_params create_params() const override;

      forms::border_style border_style_ = forms::border_style::fixed_single;
    };
  }
}
