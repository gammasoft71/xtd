/// @file
/// @brief Contains xtd::const_overload.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents class that use to determine one of const overloaded methods.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename ...args_t>
  struct const_overload_type {
    /// @name Operators
    
    /// @{
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template<typename result_t, typename type_t>
    constexpr auto operator()(result_t (type_t::*method)(args_t...) const) const noexcept -> decltype(method) {return method;}
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template<typename result_t, typename type_t>
    static constexpr auto of(result_t (type_t::*method)(args_t...) const) noexcept -> decltype(method) {return method;}
    /// @}
  };

  /// @name Public Variables

  /// @{
  template<typename ...args_t>
  inline constexpr const_overload_type<args_t...> const_overload;
  /// @}
}

/// @brief Helper keyword that use to determine one of const overloaded methods.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core
#define const_overload_ xtd::const_overload
