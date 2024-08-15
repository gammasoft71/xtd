#pragma once
#include "component.h"
#include <xtd/iequatable>
#include <xtd/string>

// TODO: documentation
namespace xtd {
  namespace forms {
    class message_notifier_button : public xtd::forms::component, public xtd::iequatable<message_notifier_button> {
    public:
      message_notifier_button() = default;
      explicit message_notifier_button(const xtd::string& text) : text_(text) {}
      
      const xtd::string& text() const noexcept {
        return text_;
      }
      
      message_notifier_button& text(const xtd::string& value) {
        text_ = value;
        return *this;
      }
      
      //TODO:
      using object::equals;
      bool equals(const message_notifier_button& other) const noexcept override {
        return text_ == other.text_;
      }
      
    private:
      xtd::string text_;
    };
    
    using message_notifier_button_ref = std::reference_wrapper<message_notifier_button>;
  }
}

