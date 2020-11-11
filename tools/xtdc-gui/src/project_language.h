#pragma once

namespace xtdc_gui {
  enum class project_language {
    xtd = 0b1,
    cpp = 0b10,
    c = 0b100,
    csharp = 0b1000,
    objectivec = 0b10000,
    all = xtd|cpp|c|csharp|objectivec,
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
