#pragma once
#include "control.hpp"
#include "border_styles.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class panel : public control {
    public:
      panel() = default;

      forms::border_styles border_styles() const {return this->border_styles_;}
      void border_styles(forms::border_styles border_styles);

      drawing::size default_size() const override {return{200, 100};}
      
      void create_handle() override;
      
    private:
      forms::border_styles border_styles_ = forms::border_styles::none;
    };
  }
}
