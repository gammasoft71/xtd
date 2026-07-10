/// @file
/// @brief Contains xtd::optional type.
#pragma once
/// @cond
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
/// @endcond

#include <optional>
#include "generic_stream_output.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the optional alias on [std::optional](https://en.cppreference.com/w/cpp/utility/optional).
  /// @par Header
  /// ```cpp
  /// #include <xtd/optional>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  template<typename type_t>
  using optional = std::optional<type_t>;
}

/// @brief Gets the contained value of specified optional if available; otherwhise the specified default_value.
/// @param optional The optional to gets the value.
/// @param default_value The default value if optioanl is empty.
/// @return The contained value of optional if available; otherwise the default value.
template <typename optional_t, typename default_value_t>
optional_t operator |(const xtd::optional<optional_t>& optional, default_value_t&& default_value) {
  return optional.value_or(std::forward<default_value_t>(default_value));
}

/// @brief Sets the default value if the contained value of specified optional i empty (equal to xtd::nullopt)..
/// @param optional The optional to sets the value.
/// @param default_value The default value to set t optional if optioanl is empty.
/// @return The optional updated if empty otherwise; option not updated.
template <typename optional_t, typename default_value_t>
xtd::optional<optional_t>& operator |=(xtd::optional<optional_t>& optional, default_value_t&& default_value) {
  if (!optional) optional = std::forward<default_value_t>(default_value);
  return optional;
}
