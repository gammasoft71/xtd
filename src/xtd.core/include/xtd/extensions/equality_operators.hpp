/// @file
/// @brief Contains xtd::extensions::equality_operators class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::extensions namespace contains interface extensions.
  namespace extensions {
    /// @brief Internal equality operators definition.
    /// @par Definition
    /// ```cpp
    /// template<class type_t, class equatable_t>
    /// class equality_operators
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/extensions/equality_operators
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core extensions
    /// @warning Internal use only for xtd::iequatable interfece.
    template<class type_t, class equatable_t>
    class equality_operators {
    public:
      /// @name Public Operators
      
      /// @{
      /// @brief Equal to operator with specidied lhs ans rhs values.
      /// @param lhs The left hand side value to compare.
      /// @param rhs The right hand side value to compare.
      /// @return `true` if lhs is equal to rhs; otherwise `false`.
      friend bool operator ==(const type_t& lhs, const type_t& rhs) noexcept {return lhs.equals(rhs);}
      /// @brief Not equal to operator with specidied lhs ans rhs values.
      /// @param lhs The left hand side value to compare.
      /// @param rhs The right hand side value to compare.
      /// @return `true` if lhs is not equal to rhs; otherwise `false`.
      friend bool operator !=(const type_t& lhs, const type_t& rhs) noexcept {return !lhs.equals(rhs);}
      /// @}
    
    private:
      friend equatable_t;
      equality_operators() = default;
    };
  }
}
