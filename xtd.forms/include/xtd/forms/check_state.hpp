#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    enum class check_state {
      unchecked = 0,
      checked = 1,
      indeterminate = 2
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, check_state value) {return os << to_string(value, {{check_state::unchecked, "unchecked"}, {check_state::checked, "checked"}, {check_state::indeterminate, "indeterminate"}});}
    inline std::wostream& operator<<(std::wostream& os, check_state value) {return os << to_string(value, {{check_state::unchecked, L"unchecked"}, {check_state::checked, L"checked"}, {check_state::indeterminate, L"indeterminate"}});}
    /// @endcond
  }
}
