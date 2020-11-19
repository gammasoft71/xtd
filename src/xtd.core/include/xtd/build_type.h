#pragma once
#include <xtd/strings.h>
#undef unix

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the compiler, supported by an assembly.
  /// @see compileer
  enum class build_type {
    /// @brief The compiler is unknown.
    debug = 0,
    /// @brief The compiler is Microsoft Visual Studio.
    release,
  };

  inline std::ostream& operator<<(std::ostream& os, build_type value) {return os << to_string(value, {{build_type::debug, "debug"}, {build_type::release, "release"}});}
  inline std::wostream& operator<<(std::wostream& os, build_type value) {return os << to_string(value, {{build_type::debug, L"debug"}, {build_type::release, L"release"}});}
}
