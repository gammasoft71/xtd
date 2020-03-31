#pragma once

namespace xtdc_gui {
  enum class project_platform {
    windows = 0b1,
    linux = 0b10,
    macos = 0b100,
    all = windows|linux|macos,
  };

  /// @cond
  inline project_platform& operator +=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
  inline project_platform& operator -=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
  inline project_platform& operator &=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
  inline project_platform& operator |=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
  inline project_platform& operator ^=(project_platform& lhs, project_platform rhs) {lhs = static_cast<project_platform>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
  inline project_platform operator +(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
  inline project_platform operator -(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
  inline project_platform operator ~(project_platform rhs) {return static_cast<project_platform>(~static_cast<long long>(rhs));}
  inline project_platform operator &(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
  inline project_platform operator |(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
  inline project_platform operator ^(project_platform lhs, project_platform rhs) {return static_cast<project_platform>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
  /// @endcond
}
