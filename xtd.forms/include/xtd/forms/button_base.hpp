#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class button_base : public control {
    public:
      button_base();

      /// @cond
      button_base(const button_base& value) {*this = value;}
      button_base& operator=(const button_base& value);
      /// @endcond

      forms::auto_size_mode auto_size_mode() const {return this->control::data_->auto_size_mode_;}
      virtual button_base& auto_size_mode(forms::auto_size_mode value);
      
      drawing::size default_size() const override {return {75, 25};}

    protected:
      forms::create_params create_params() const override;

      drawing::size measure_control() const override;
      
 private:
      struct data {
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
