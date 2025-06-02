#pragma once
#include "component.hpp"
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
      
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const xtd::object& obj) const noexcept override {
        return is<message_notifier_button>(obj) && equals(static_cast<const message_notifier_button&>(obj));
      }
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const message_notifier_button& other) const noexcept override {
        return text_ == other.text_;
      }
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      xtd::size get_hash_code() const noexcept override {
        return hash_code::combine(text_);
      }

    private:
      xtd::string text_;
    };
    
    using message_notifier_button_ref = std::reference_wrapper<message_notifier_button>;
  }
}

