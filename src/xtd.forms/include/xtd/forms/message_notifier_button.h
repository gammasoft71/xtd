#pragma once
#include <xtd/forms/component.h>
#include <xtd/ustring.h>
#include <xtd/forms/component.h>
// TODO: documentation
namespace xtd {
namespace forms {
    class message_notifier_button : public xtd::forms::component {
    public:
        message_notifier_button() = default;
        message_notifier_button(const xtd::ustring& text) : text_(text) {}
        const xtd::ustring& text() const noexcept {
            return text_;
        }
        message_notifier_button& text(const xtd::ustring& value) {
            text_ = value;
            return *this;
        }

        //TODO:
        bool operator ==(const message_notifier_button& other) const {
            return text_ == other.text_;
        }
        bool operator !=(const message_notifier_button& other) const {
            return !((*this) == other);
        }
    private:
        xtd::ustring text_;
    };
    using message_notifier_button_ref = std::reference_wrapper<message_notifier_button>;
    }
}
