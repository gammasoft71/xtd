#pragma once
#include <xtd/ustring.h>
//TODO: Documentation

namespace xtd {
  namespace forms {
    enum class notifier_style {
      standard = 0,
      system = 1,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, notifier_style value) {return os << to_string(value, {{notifier_style::standard, "standard"}, {notifier_style::system, "system"}});}
    inline std::wostream& operator<<(std::wostream& os, notifier_style value) {return os << to_string(value, {{notifier_style::standard, L"standard"}, {notifier_style::system, L"system"}});}
    /// @endcond
  }
}
