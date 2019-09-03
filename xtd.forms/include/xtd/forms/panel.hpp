#pragma once
#include "control.hpp"
#include "border_style.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class panel : public control {
    public:
      panel();

      /// @cond
      panel(const panel& value) {*this = value;}
      panel& operator=(const panel& value);
      /// @endcond

      forms::border_style border_style() const {return this->data_->border_style_;}
      panel& border_style(forms::border_style border_style);

      drawing::size default_size() const override {return{200, 100};}
      
    protected:
      forms::create_params create_params() const override;

    private:
      struct data {
        forms::border_style border_style_ = forms::border_style::none;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
