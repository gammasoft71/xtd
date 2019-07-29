#pragma once
#include "control.hpp"
#include "border_styles.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class label : public control {
    public:
      label() = default;

      bool auto_size() const {return this->auto_size_;}
      void auto_size(bool auto_size);
      
      forms::border_styles border_styles() const {return this->border_styles_;}
      void border_styles(forms::border_styles border_styles);

      using control::size;
      void size(const drawing::size& size) override {
        if (!this->auto_size_) this->control::size(size);
      }

      drawing::size default_size() const override {return{100, 23};}

      event<label, event_handler<control>> auto_size_changed;
      
      void create_handle() override;

      void on_auto_size_changed(const event_args& e) {this->auto_size_changed(*this, e);}
      
    private:
      bool auto_size_ = false;
      forms::border_styles border_styles_ = forms::border_styles::none;
    };
  }
}
