#pragma once
#include <type_traits>

namespace xtdc_gui {
  enum class project_language {
    xtd = 0b1,
    xtd_c = 0b10,
    cpp = 0b100,
    c = 0b1000,
    csharp = 0b10000,
    objectivec = 0b100000,
    all = xtd | xtd_c | cpp | c | csharp | objectivec,
  };
  
  /// @cond
  [[maybe_unused]] inline project_language& operator ^=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) ^ static_cast<std::underlying_type<project_language>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_language& operator &=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) & static_cast<std::underlying_type<project_language>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_language& operator |=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) | static_cast<std::underlying_type<project_language>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_language& operator +=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) + static_cast<std::underlying_type<project_language>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_language& operator -=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) - static_cast<std::underlying_type<project_language>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_language operator ^(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) ^ static_cast<std::underlying_type<project_language>::type>(rhs));}
  [[maybe_unused]] inline project_language operator &(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) & static_cast<std::underlying_type<project_language>::type>(rhs));}
  [[maybe_unused]] inline project_language operator |(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) | static_cast<std::underlying_type<project_language>::type>(rhs));}
  [[maybe_unused]] inline project_language operator +(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) + static_cast<std::underlying_type<project_language>::type>(rhs));}
  [[maybe_unused]] inline project_language operator -(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<std::underlying_type<project_language>::type>(lhs) - static_cast<std::underlying_type<project_language>::type>(rhs));}
  [[maybe_unused]] inline project_language operator ~(project_language lhs) {return static_cast<project_language>(~static_cast<std::underlying_type<project_language>::type>(lhs));} \
  /// @endcond
}
