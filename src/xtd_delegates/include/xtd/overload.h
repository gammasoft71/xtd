#pragma once

#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template <typename... args_t>
  struct non_const_overload {
    template <typename result_t, typename type_t>
    constexpr auto operator()(result_t (type_t::*method)(args_t...)) const noexcept -> decltype(method) {return method;}
    template <typename result_t, typename type_t>
    static constexpr auto of(result_t (type_t::*method)(args_t...)) noexcept -> decltype(method) {return method;}
  };

  template <typename... args_t>
  struct const_overload {
    template <typename result_t, typename type_t>
    constexpr auto operator()(result_t (type_t::*method)(args_t...) const) const noexcept -> decltype(method) {return method;}
    template <typename result_t, typename type_t>
    static constexpr auto of(result_t (type_t::*method)(args_t...) const) noexcept -> decltype(method) {return method;}
  };

  template <typename... args_t>
  struct overload : const_overload<args_t...>, non_const_overload<args_t...> {
    /// @cond
    using const_overload<args_t...>::of;
    using const_overload<args_t...>::operator();
    using non_const_overload<args_t...>::of;
    using non_const_overload<args_t...>::operator();
    /// @endcond
    
    template <typename result_t>
    constexpr auto operator()(result_t (*method)(args_t...)) const noexcept -> decltype(method) {return method;}
    template <typename result_t>
    static constexpr auto of(result_t (*method)(args_t...)) noexcept -> decltype(method) {return method;}
  };

  /// @cond
  template <typename... args_t>
  inline constexpr overload<args_t...> overload_;

  template <typename... args_t>
  inline constexpr const_overload<args_t...> const_overload_;

  template <typename... args_t>
  inline constexpr non_const_overload<args_t...> non_const_overload_;
  /// @endcond
}

#define overload_ xtd::overload_

#define const_overload_ xtd::const_overload_

#define non_const_overload_ xtd::non_const_overload_
