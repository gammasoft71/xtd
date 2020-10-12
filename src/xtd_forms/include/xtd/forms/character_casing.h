#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, upper, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating upper, Apple macOS and Linux like Ubuntu operating upper.
  namespace forms {
    enum class character_casing {
      normal = 0,
      upper = 1,
      lower = 2,
    };

    /// @cond
  inline std::ostream& operator<<(std::ostream& os, character_casing value) {return os << to_string(value, {{character_casing::normal, "normal"}, {character_casing::upper, "upper"}, {character_casing::lower, "lower"}});}
  inline std::wostream& operator<<(std::wostream& os, character_casing value) {return os << to_string(value, {{character_casing::normal, L"normal"}, {character_casing::upper, L"upper"}, {character_casing::lower, L"lower"}});}
    /// @endcond
  }
}
