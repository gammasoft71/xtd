#pragma once
#include "control.hpp"
#include "border_style.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class label : public control {
    public:
      label();

      /// @cond
      label(const label& value) {*this = value;}
      label& operator=(const label& value);
      /// @endcond

      forms::border_style border_style() const {return this->data_->border_style_;}
      label& border_style(forms::border_style border_style);

      using control::size;
      control& size(const drawing::size& size) override {
        if (!this->control::data_->auto_size_) this->control::size(size);
        return *this;
      }
      
      using control::text;
      control& text(const std::string& text) override {
         this->control::text(text);
        if (this->control::data_->auto_size_) this->force_update_size();
        return *this;
      }
      
      drawing::size default_size() const override {return{100, 23};}
      
    protected:
      forms::create_params create_params() const override;
      
      void on_auto_size_changed(const event_args& e) override {
        this->force_update_size();
        this->recreate_handle();
      }

    private:
      drawing::size measure_string() const;
      void force_update_size();
      
      struct data {
        forms::border_style border_style_ = forms::border_style::none;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
