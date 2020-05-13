#pragma once

#include <functional>

/// @cond
template <typename... args_t>
struct __non_const_overload__ {
  template <typename result_t, typename type_t>
  constexpr auto operator()(result_t (type_t::*method)(args_t...)) const noexcept -> decltype(method) {return method;}
  template <typename result_t, typename type_t>
  static constexpr auto of(result_t (type_t::*method)(args_t...)) noexcept -> decltype(method) {return method;}
};

template <typename... args_t>
struct __const_overload__ {
  template <typename result_t, typename type_t>
  constexpr auto operator()(result_t (type_t::*method)(args_t...) const) const noexcept -> decltype(method) {return method;}
  template <typename result_t, typename type_t>
  static constexpr auto of(result_t (type_t::*method)(args_t...) const) noexcept -> decltype(method) {return method;}
};
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template <typename... args_t>
  struct overload : __const_overload__<args_t...>, __non_const_overload__<args_t...> {
    /// @cond
    using __const_overload__<args_t...>::of;
    using __const_overload__<args_t...>::operator();
    using __non_const_overload__<args_t...>::of;
    using __non_const_overload__<args_t...>::operator();
    /// @endcond
    
    template <typename result_t>
    constexpr auto operator()(result_t (*method)(args_t...)) const noexcept -> decltype(method) {return method;}
    template <typename result_t>
    static constexpr auto of(result_t (*method)(args_t...)) noexcept -> decltype(method) {return method;}
  };
}
