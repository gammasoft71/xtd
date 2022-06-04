#pragma once
#include <xtd/ustring.h>
// TODO: Documentation

namespace xtd {
  namespace forms {
      enum class message_notifier_icon {
        none = 0,
        information = 0x00000001,
        warning = 0x00000002,
        error = 0x00000003
      };
      inline std::ostream& operator<<(std::ostream& os, const message_notifier_icon value) { return os << to_string(value, { {message_notifier_icon::none, "none"}, {message_notifier_icon::information, "information"}, {message_notifier_icon::warning, "warning"}, {message_notifier_icon::error, "error"}}); }
      inline std::wostream& operator<<(std::wostream& os, const message_notifier_icon value) { return os << to_string(value, { {message_notifier_icon::none, L"none"}, {message_notifier_icon::information, L"information"}, {message_notifier_icon::warning, L"warning"}, {message_notifier_icon::error, L"error"}}); }
  }
}
