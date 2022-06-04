#pragma once
#include <xtd/ustring.h>
//TODO: Documentation

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
        ignore = 7
       };
      inline std::ostream& operator<<(std::ostream& os, const notifier_result value) { return os << to_string(value, { {notifier_result::none, "none"}, {notifier_result::ok, "ok"}, {notifier_result::cancel, "cancel"}, {notifier_result::yes, "yes"}, {notifier_result::no, "no"}, {notifier_result::abort, "abort"}, {notifier_result::retry, "retry"}, {notifier_result::ignore, "ignore"}}); }
      inline std::wostream& operator<<(std::wostream& os, const notifier_result value) { return os << to_string(value, { {notifier_result::none, L"none"}, {notifier_result::ok, L"ok"}, {notifier_result::cancel, L"cancel"}, {notifier_result::yes, L"yes"}, {notifier_result::no, L"no"}, {notifier_result::abort, L"abort"}, {notifier_result::retry, L"retry"}, {notifier_result::ignore, L"ignore"}}); }
  }
}
