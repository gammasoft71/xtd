#pragma once
#include <xtd/ustring.h>
//TODO: Documentation

namespace xtd {
  namespace forms {
      enum class message_notifier_buttons {
        none = 0,
        ok = 1,
        ok_cancel = 2,
        abort_retry_ignore = 3,
        yes_no_cancel = 4,
        yes_no = 5,
        retry_cancel = 6
      };
      inline std::ostream& operator<<(std::ostream& os, const message_notifier_buttons value) { return os << to_string(value, { {message_notifier_buttons::none, "none"}, {message_notifier_buttons::ok, "ok"}, {message_notifier_buttons::ok_cancel, "ok_cancel"}, {message_notifier_buttons::abort_retry_ignore, "abort_retry_ignore"}, {message_notifier_buttons::yes_no_cancel, "yes_no_cancel"}, {message_notifier_buttons::yes_no, "yes_no"}, {message_notifier_buttons::retry_cancel, "retry_cancel"}}); }
      inline std::wostream& operator<<(std::wostream& os, const message_notifier_buttons value) { return os << to_string(value, { {message_notifier_buttons::none, L"none"}, {message_notifier_buttons::ok, L"ok"}, {message_notifier_buttons::ok_cancel, L"ok_cancel"}, {message_notifier_buttons::abort_retry_ignore, L"abort_retry_ignore"}, {message_notifier_buttons::yes_no_cancel, L"yes_no_cancel"}, {message_notifier_buttons::yes_no, L"yes_no"}, {message_notifier_buttons::retry_cancel, L"retry_cancel"}}); }
  }
}
