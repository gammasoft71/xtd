#pragma once
#include <type_traits>

#undef linux

namespace xtdc_gui {
  enum class project_platform {
    windows = 0b1,
    linux = 0b10,
    macos = 0b100,
    all = windows | linux | macos,
  };
  
  /// @cond
  [[maybe_unused]] inline project_platform& operator ^=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) ^ static_cast<std::underlying_type<project_platform>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_platform& operator &=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) & static_cast<std::underlying_type<project_platform>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_platform& operator |=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) | static_cast<std::underlying_type<project_platform>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_platform& operator +=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) + static_cast<std::underlying_type<project_platform>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_platform& operator -=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) - static_cast<std::underlying_type<project_platform>::type>(rhs)); return lhs;}
  [[maybe_unused]] inline project_platform operator ^(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) ^ static_cast<std::underlying_type<project_platform>::type>(rhs));}
  [[maybe_unused]] inline project_platform operator &(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) & static_cast<std::underlying_type<project_platform>::type>(rhs));}
  [[maybe_unused]] inline project_platform operator |(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) | static_cast<std::underlying_type<project_platform>::type>(rhs));}
  [[maybe_unused]] inline project_platform operator +(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) + static_cast<std::underlying_type<project_platform>::type>(rhs));}
  [[maybe_unused]] inline project_platform operator -(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<std::underlying_type<project_platform>::type>(lhs) - static_cast<std::underlying_type<project_platform>::type>(rhs));}
  [[maybe_unused]] inline project_platform operator ~(project_platform lhs) {return static_cast<project_platform>(~static_cast<std::underlying_type<project_platform>::type>(lhs));} \
  /// @endcond
}
