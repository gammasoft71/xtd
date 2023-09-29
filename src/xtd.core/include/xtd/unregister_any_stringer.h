/// @file
/// @brief Contains xtd::register_any_stringer and xtd::unregister_any_stringer method.
#pragma once
#include "any.h"
#include <functional>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <vector>

/// @cond
extern std::unordered_map<std::type_index, std::function<std::string(std::any const&)>> __any_stringer__;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Unregister an any stringer method for a specified type.
  /// @par Header
  /// @code #include <xtd/any> @endcode
/// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// Show how to register your own class.
  /// @include format_any.cpp
  template<class type_t>
  inline void unregister_any_stringer() {
    auto it = __any_stringer__.find(std::type_index(typeid(type_t)));
    if (it != __any_stringer__.cend()) __any_stringer__.erase(it);
  }
}
