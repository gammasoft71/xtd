/// @file
/// @brief Contains xtd::register_any_stringer and xtd::unregister_any_stringer method.
#pragma once
#include "collections/generic/key_value_pair.hpp"
#include "unregister_any_stringer.hpp"

/// @cond
extern std::unordered_map<std::type_index, std::function<std::string(std::any const&)>> __any_stringer__;

template<class type_t, class function_t>
inline std::pair<const std::type_index, std::function<std::string(std::any const&)>> __to_any_stringer__(function_t const& func) {
  return {
    std::type_index(typeid(type_t)),
    [f = func](std::any const & value)->std::string {
      if constexpr(std::is_void_v<type_t>) return f();
      else return f(std::any_cast<const type_t&>(value));
    }
  };
}
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Static Methods
  
  /// @{
  /// @brief Register an any stringer method for a specified type.
  /// @param func Function to register any stringer for specified type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// Show how to register your own class.
  /// @include format_any.cpp
  template<class type_t, class function_t>
  inline void register_any_stringer(const function_t& func) {
    unregister_any_stringer<type_t>();
    __any_stringer__.insert(__to_any_stringer__<type_t>(func));
  }
  /// @}
}
