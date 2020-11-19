#pragma once
#include <xtd/strings.h>
#undef unix

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the c++ standard used by assembly.
  /// @see operating_system
  enum class standard_id {
    /// @brief The standard is unknown.
    unknown = -1,
    /// @brief The standard is pre 98.
    cpp_pre98 = 0,
    /// @brief The standard is c++98.
    cpp98,
    /// @brief The standard is c++11.
    cpp11,
    /// @brief The standard is c++14.
    cpp14,
    /// @brief The standard is c++17.
    cpp17,
    /// @brief The standard is c++20.
    cpp20
  };

  inline std::ostream& operator<<(std::ostream& os, standard_id value) {return os << to_string(value, {{standard_id::unknown, "unknown"}, {standard_id::cpp_pre98, "cpp_pre98"}, {standard_id::cpp98, "cpp98"}, {standard_id::cpp11, "cpp11"}, {standard_id::cpp14, "cpp14"}, {standard_id::cpp17, "cpp17"}, {standard_id::cpp20, "cpp20"}});}
  inline std::wostream& operator<<(std::wostream& os, standard_id value) {return os << to_string(value, {{standard_id::unknown, L"unknown"}, {standard_id::cpp_pre98, L"cpp_pre98"}, {standard_id::cpp98, L"cpp98"}, {standard_id::cpp11, L"cpp11"}, {standard_id::cpp14, L"cpp14"}, {standard_id::cpp17, L"cpp17"}, {standard_id::cpp20, L"cpp20"}});}
}
