#pragma once
#include <xtd/strings.h>
#undef unix

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the processor architecture, supported by an assembly.
  /// @see operating_system
  enum class architecture_id {
    /// @brief The processor architecture is unknown.
    unknown = -1,
    /// @brief The processor architecture is x86 (Intel or amd).
    x86,
    /// @brief The processor architecture is ARM.
    arm,
  };

  inline std::ostream& operator<<(std::ostream& os, architecture_id value) {return os << to_string(value, {{architecture_id::unknown, "unknown"}, {architecture_id::x86, "x86"}, {architecture_id::arm, "arm"}});}
  inline std::wostream& operator<<(std::wostream& os, architecture_id value) {return os << to_string(value, {{architecture_id::unknown, L"unknown"}, {architecture_id::x86, L"x86"}, {architecture_id::arm, L"arm"}});}
}
