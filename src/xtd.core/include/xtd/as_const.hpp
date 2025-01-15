/// @file
/// @brief Contains xtd::as_const method.
#pragma once
#include <type_traits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Obtains a reference to `const` to its argument
  /// @param type The referecne of `type`.
  /// @return The const reference of `type`.
  /// @remarks Forms lvalue reference to const type of `type`.
  template<class type_t>
  constexpr std::add_const_t<type_t>& as_const(type_t& type) noexcept {
    return type;
  }
  /// @cond
  template<class type_t>
  void as_const(const type_t&&) = delete;
  /// @endcond
}
