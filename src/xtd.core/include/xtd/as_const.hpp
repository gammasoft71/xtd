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
  template<typename type_t>
  [[nodiscard]] constexpr auto as_const(type_t& type) noexcept -> std::add_const_t<type_t>& {
    return type;
  }
  /// @brief Obtains a pointer to `const` to its argument
  /// @param type The pointer of `type`.
  /// @return The const pointer of `type`.
  /// @remarks Forms lvalue pointer to const type of `type`.
  template<typename type_t>
  [[nodiscard]] constexpr auto as_const(type_t* type) noexcept -> std::add_const_t<type_t>* {
    return type;
  }
  /// @cond
  template<typename type_t>
  auto as_const(const type_t&&) -> void = delete;
  /// @endcond
}
