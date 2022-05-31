#pragma once
#include "component.h"
#include <xtd/ustring.h>
#include <xtd/delegate.h>
#include <xtd/drawing/icon.h>
#include <xtd/event.h>
#include <xtd/event_args.h>
#include <chrono>
///TODO: Documentation

namespace xtd {
  namespace forms {

    enum class notifier_result {
      none = 0,
      ok = 1,
      cancel = 2,
      yes = 3,
      no = 4,
      abort = 5,
      retry = 6,
      ignore = 4
     };
    inline std::ostream& operator<<(std::ostream& os, const notifier_result value) { return os << to_string(value, { {notifier_result::none, "none"}, {notifier_result::ok, "ok"}, {notifier_result::cancel, "cancel"}, {notifier_result::yes, "yes"}, {notifier_result::no, "no"}, {notifier_result::abort, "abort"}, {notifier_result::retry, "retry"}, {notifier_result::ignore, "ignore"}}); }
    inline std::wostream& operator<<(std::wostream& os, const notifier_result value) { return os << to_string(value, { {notifier_result::none, L"none"}, {notifier_result::ok, L"ok"}, {notifier_result::cancel, L"cancel"}, {notifier_result::yes, L"yes"}, {notifier_result::no, L"no"}, {notifier_result::abort, L"abort"}, {notifier_result::retry, L"retry"}, {notifier_result::ignore, L"ignore"}}); }

    enum class message_notifier_buttons {
      none = 0, // notification without buttons
      ok = 1,
      ok_cancel = 2,
      abort_retry_ignore = 3,
      yes_no_cancel = 4,
      yes_no = 5,
      retry_cancel = 6
    };
    inline std::ostream& operator<<(std::ostream& os, const message_notifier_buttons value) { return os << to_string(value, { {message_notifier_buttons::none, "none"}, {message_notifier_buttons::ok, "ok"}, {message_notifier_buttons::ok_cancel, "ok_cancel"}, {message_notifier_buttons::abort_retry_ignore, "abort_retry_ignore"}, {message_notifier_buttons::yes_no_cancel, "yes_no_cancel"}, {message_notifier_buttons::yes_no, "yes_no"}, {message_notifier_buttons::retry_cancel, "retry_cancel"}}); }
    inline std::wostream& operator<<(std::wostream& os, const message_notifier_buttons value) { return os << to_string(value, { {message_notifier_buttons::none, L"none"}, {message_notifier_buttons::ok, L"ok"}, {message_notifier_buttons::ok_cancel, L"ok_cancel"}, {message_notifier_buttons::abort_retry_ignore, L"abort_retry_ignore"}, {message_notifier_buttons::yes_no_cancel, L"yes_no_cancel"}, {message_notifier_buttons::yes_no, L"yes_no"}, {message_notifier_buttons::retry_cancel, L"retry_cancel"}}); }

    enum class message_notifier_icon {
      information = 0,
      warning = 1,
      error = 2
    };
    inline std::ostream& operator<<(std::ostream& os, const message_notifier_icon value) { return os << to_string(value, { {message_notifier_icon::information, "information"}, {message_notifier_icon::warning, "warning"}, {message_notifier_icon::error, "error"}}); }
    inline std::wostream& operator<<(std::wostream& os, const message_notifier_icon value) { return os << to_string(value, { {message_notifier_icon::information, L"information"}, {message_notifier_icon::warning, L"warning"}, {message_notifier_icon::error, L"error"}}); }


    class notifier_closed_event_args : public xtd::event_args {
    public:
      xtd::forms::notifier_result notifier_result() const {
        //..
        return notifier_result::ok;
      }
    };
    using notifier_closed_event_handler = delegate<void(object& sender, const notifier_closed_event_args& e)>;


    class forms_export_ message_notifier final : public component {
    public:
      message_notifier() = default;

      /// Properties
      xtd::ustring title() const { return title_; }
      message_notifier& title(const xtd::ustring& title) { title_ = title; return *this; }

      xtd::ustring message() const { return message_; }
      message_notifier& message(const xtd::ustring& message) { message_ = message; return *this; }

      const xtd::drawing::image& icon() const { return icon_; }
      //xtd::forms::message_notifier_icon icon() const { return system_icon_; }
      message_notifier& icon(xtd::forms::message_notifier_icon icon) {system_icon_ = icon; return *this; }
      message_notifier& icon(const xtd::drawing::image& image) {icon_ = image; return *this; }
      message_notifier& icon(const xtd::drawing::icon& icon) { icon_ = icon.to_bitmap(); return *this; }

      bool close_timeout_enabled() const { return close_timeout_enabled_; }
      message_notifier& close_timeout_enabled(bool value) { close_timeout_enabled_ = value; return *this; }

      std::chrono::milliseconds close_timeout_interval() const { return close_timeout_interval_; }
      message_notifier& close_timeout_interval(std::chrono::milliseconds value) { close_timeout_interval_ = value; return *this; }
      message_notifier& close_timeout_interval_milliseconds(int32_t value) { close_timeout_interval_ = std::chrono::milliseconds(value); return *this; }

      xtd::forms::message_notifier_buttons buttons() const { return buttons_; }
      message_notifier& buttons(xtd::forms::message_notifier_buttons value) { buttons_ = value; return *this; }

      xtd::forms::notifier_result notifier_result() const { return result_; }


      xtd::forms::notifier_result show();

      //const xtd::ustring& button_ok_text() const;
      //message_notifier& button_ok_text(const xtd::ustring& value);
      //message_notifier& button_ok_text(std::nullptr_t); // Reset to default value


      /// Events

      event<message_notifier, xtd::forms::notifier_closed_event_handler> notifier_closed;


    protected:
      virtual void on_notifier_closed(const xtd::forms::notifier_closed_event_args& e) { result_ = e.notifier_result(); notifier_closed(*this, e); }

    private:
      xtd::ustring title_;
      xtd::ustring message_;
      xtd::drawing::image icon_ = xtd::drawing::image::empty;
      xtd::forms::message_notifier_icon system_icon_ = xtd::forms::message_notifier_icon::information;
      xtd::forms::message_notifier_buttons buttons_ = xtd::forms::message_notifier_buttons::none;
      bool close_timeout_enabled_ = false;
      std::chrono::milliseconds close_timeout_interval_ = std::chrono::milliseconds(10'000);
      xtd::forms::notifier_result result_ = xtd::forms::notifier_result::none;

    };
  }
}
