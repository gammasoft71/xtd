#pragma once
#include "border_style.hpp"
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class text_box : public control {
    public:
      text_box();

      forms::border_style border_style() const {return this->border_style_;}
      text_box& border_style(forms::border_style border_style);
      
      drawing::color default_back_color() const override;
      
      drawing::color default_fore_color() const override;
      
      drawing::size default_size() const override {return {100, 23};}

      using control::text;
      control& text(const std::string& text) override;
      
    protected:
      forms::create_params create_params() const override;

    private:
      forms::border_style border_style_ = forms::border_style::fixed_single;
    };
  }
}
