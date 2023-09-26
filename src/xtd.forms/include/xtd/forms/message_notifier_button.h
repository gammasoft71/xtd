#pragma once
#include "component"
#include <xtd/iequatable>
#include <xtd/ustring>

// TODO: documentation
namespace xtd {
  namespace forms {
    class message_notifier_button : public xtd::forms::component, public xtd::iequatable<message_notifier_button> {
    public:
      message_notifier_button() = default;
      explicit message_notifier_button(const xtd::ustring& text) : text_(text) {}
      
      const xtd::ustring& text() const noexcept {
        return text_;
      }
      
      message_notifier_button& text(const xtd::ustring& value) {
        text_ = value;
        return *this;
      }
      
      //TODO:
      bool equals(const message_notifier_button& other) const noexcept override {
        return text_ == other.text_;
      }
      
    private:
      xtd::ustring text_;
    };
    
    using message_notifier_button_ref = std::reference_wrapper<message_notifier_button>;
  }
}

