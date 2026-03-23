/// @file
/// @brief Contains xtd::value_type struct.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "raw_type.hpp"
#include <concepts>
#include <iostream>
#include <type_traits>
#if defined(__xtd__cpp_lib_format)
#include <format>
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types
  
  /// @{
  /// @brief Represents a value_type struct.
  /// @par Header
  /// ```cpp
  /// #include <xtd/value_type>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks Value_type is used to define xtd tyes : xtd::boolean, xtd::byte, xtd::double_, xtd::int16, xtd::int32, xtd::int64, xtd::sbyte, xtd::single, xtd::uint16, xtd::uint32, xtd::uint64, ...
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  template<typename type_t>
  struct value_type {
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the native type.
    using native_type = type_t;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of the value_type.
    constexpr value_type() noexcept = default;
    /// @brief Create a new instance of the value_type with specified same native type value.
    /// @param value The same native type value to assign.
    template<typename other_t>
    requires std::is_same_v<xtd::raw_type<other_t>, native_type> && (!std::is_same_v<xtd::raw_type<other_t>, value_type>)
    constexpr value_type(other_t&& value) noexcept : __t__ {value} {}
    /// @}

    /// @cond
    template<typename other_t>
    requires std::is_same_v<xtd::raw_type<other_t>, native_type> && (!std::is_same_v<xtd::raw_type<other_t>, value_type>)
    value_type& operator =(other_t&& value) noexcept {__t__ = value; return *this;}
    [[nodiscard]] constexpr operator native_type() const noexcept {return __t__;}
    native_type __t__ {};
    /// @endcond
  };
  /// @}
  
  /// @cond
  template<typename type_t>
  std::ostream& operator <<(std::ostream& os, const xtd::value_type<type_t>& v) {return os << v.__t__;}
  inline std::ostream& operator <<(std::ostream& os, const xtd::value_type<bool>& v) {return os << (v ? "true" : "false");}
  /// @endcond
}

/// @cond
/// Needed for std::format
#if defined(__xtd__cpp_lib_format)
template<typename type_t>
struct std::formatter<xtd::value_type<type_t>> : std::formatter<type_t> {auto format(const xtd::value_type<type_t>& v, format_context& ctx) const {return std::formatter<type_t>::format(v.value, ctx);}};
template<>
struct std::formatter<xtd::value_type<bool>> : std::formatter<bool> {auto format(const xtd::value_type<bool>& v, format_context& ctx) const {return v ? "true" : "false";}};
#endif
/// @endcond
