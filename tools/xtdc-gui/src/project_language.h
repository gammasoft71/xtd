#pragma once

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
  inline project_language& operator +=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
  inline project_language& operator -=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
  inline project_language& operator &=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
  inline project_language& operator |=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
  inline project_language& operator ^=(project_language& lhs, project_language rhs) {lhs = static_cast<project_language>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
  inline project_language operator +(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
  inline project_language operator -(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
  inline project_language operator ~(project_language rhs) {return static_cast<project_language>(~static_cast<long long>(rhs));}
  inline project_language operator &(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
  inline project_language operator |(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
  inline project_language operator ^(project_language lhs, project_language rhs) {return static_cast<project_language>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
  /// @endcond
}
