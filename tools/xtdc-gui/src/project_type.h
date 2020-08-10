#pragma once

namespace xtdc_gui {
  enum class project_type {
    gui = 0b1,
    console = 0b10,
    shared_library = 0b100,
    static_library = 0b1000,
    unit_tests_project = 0b10000,
    solution_file = 0b100000,
    all = gui|console|shared_library|static_library|unit_tests_project|solution_file,
  };

  /// @cond
  inline project_type& operator +=(project_type& lhs, project_type rhs) {lhs = static_cast<project_type>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
  inline project_type& operator -=(project_type& lhs, project_type rhs) {lhs = static_cast<project_type>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
  inline project_type& operator &=(project_type& lhs, project_type rhs) {lhs = static_cast<project_type>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
  inline project_type& operator |=(project_type& lhs, project_type rhs) {lhs = static_cast<project_type>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
  inline project_type& operator ^=(project_type& lhs, project_type rhs) {lhs = static_cast<project_type>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
  inline project_type operator +(project_type lhs, project_type rhs) {return static_cast<project_type>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
  inline project_type operator -(project_type lhs, project_type rhs) {return static_cast<project_type>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
  inline project_type operator ~(project_type rhs) {return static_cast<project_type>(~static_cast<long long>(rhs));}
  inline project_type operator &(project_type lhs, project_type rhs) {return static_cast<project_type>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
  inline project_type operator |(project_type lhs, project_type rhs) {return static_cast<project_type>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
  inline project_type operator ^(project_type lhs, project_type rhs) {return static_cast<project_type>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
  /// @endcond
}
