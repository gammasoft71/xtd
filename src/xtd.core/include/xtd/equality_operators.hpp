/// @file
/// @brief Contains xtd::equality_operators class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Internal comparable operators definition.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t, typename equatable_t>
  /// class equality_operators
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/equality_operators
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @warning Internal use only for xtd::iequatable interfece.
  template<typename type_t, typename equatable_t>
  class equality_operators {
  public:
    /// @name Public Operators
    
    /// @{
    /// @brief Equal to operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return true if lhs is equal to rhs; otherwise false.
    friend bool operator ==(const type_t& lhs, const type_t& rhs) noexcept {return lhs.equals(rhs);}
    /// @brief Not equal to operator with specidied lhs ans rhs values.
    /// @param lhs The left hand side value to compare.
    /// @param rhs The right hand side value to compare.
    /// @return true if lhs is not equal to rhs; otherwise false.
    friend bool operator !=(const type_t& lhs, const type_t& rhs) noexcept {return !operator ==(lhs, rhs);}
    /// @}
  private:
    friend equatable_t;
    equality_operators() = default;
  };
}
