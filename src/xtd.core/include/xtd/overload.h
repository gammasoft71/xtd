/// @file
/// @brief Contains xtd::overload class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents class that use to determine one of non const overloaded methods.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template <typename... args_t>
  struct non_const_overload {
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template <typename result_t, typename type_t>
    constexpr auto operator()(result_t (type_t::*method)(args_t...)) const noexcept -> decltype(method) {return method;}
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template <typename result_t, typename type_t>
    static constexpr auto of(result_t (type_t::*method)(args_t...)) noexcept -> decltype(method) {return method;}
  };

  /// @brief Represents class that use to determine one of const overloaded methods.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template <typename... args_t>
  struct const_overload {
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template <typename result_t, typename type_t>
    constexpr auto operator()(result_t (type_t::*method)(args_t...) const) const noexcept -> decltype(method) {return method;}
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template <typename result_t, typename type_t>
    static constexpr auto of(result_t (type_t::*method)(args_t...) const) noexcept -> decltype(method) {return method;}
  };

  /// @brief Represents class that use to determine one of const and non const overloaded methods.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template <typename... args_t>
  struct overload : const_overload<args_t...>, non_const_overload<args_t...> {
    /// @cond
    using const_overload<args_t...>::of;
    using const_overload<args_t...>::operator();
    using non_const_overload<args_t...>::of;
    using non_const_overload<args_t...>::operator();
    /// @endcond
    
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template <typename result_t>
    constexpr auto operator()(result_t (*method)(args_t...)) const noexcept -> decltype(method) {return method;}
    /// @brief Returns a pointer to an overloaded method. The template parameter is the list of the argument types of the method.
    /// @param method is the pointer to the (member) method
    /// @return Pointer to an overloaded method.
    template <typename result_t>
    static constexpr auto of(result_t (*method)(args_t...)) noexcept -> decltype(method) {return method;}
  };

  /// @cond
  template <typename... args_t>
  inline const overload<args_t...> overload_;

  template <typename... args_t>
  inline const const_overload<args_t...> const_overload_;

  template <typename... args_t>
  inline const non_const_overload<args_t...> non_const_overload_;
  /// @endcond
}

/// @brief Helper keyword that use to determine one of const and non const overloaded methods.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core
#define overload_ xtd::overload_

/// @brief Helper keyword that use to determine one of const overloaded methods.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core
#define const_overload_ xtd::const_overload_

/// @brief Helper keyword that use to determine one of non const overloaded methods.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core
#define non_const_overload_ xtd::non_const_overload_
