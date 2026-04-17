/// @file
/// @brief Contains xtd::boxing methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "box.hpp"
#include "byte_object.hpp"
#include "char_object.hpp"
#include "char16_object.hpp"
#include "char32_object.hpp"
#include "char8_object.hpp"
#include "decimal_object.hpp"
#include "double_object.hpp"
#include "enum_object.hpp"
#include "int16_object.hpp"
#include "int32_object.hpp"
#include "int64_object.hpp"
#include "intptr_object.hpp"
#include "ptrdiff_object.hpp"
#include "sbyte_object.hpp"
#include "single_object.hpp"
#include "usize_object.hpp"
#include "slong_object.hpp"
#include "uint16_object.hpp"
#include "uint32_object.hpp"
#include "uint64_object.hpp"
#include "uintptr_object.hpp"
#include "ulong_object.hpp"
#include "wchar_object.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__box_enum_or_object.hpp"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Static Methods
  
  /// @{
  /// @brief Allows to box an object
  /// @param value Value used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Header
  /// ```cpp
  /// #include <xtd/boxing>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  template<typename type_t>
  [[nodiscard]] auto boxing(const type_t& value) noexcept {return typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type(value);}
  /// @brief Allows to box an object
  /// @param ...args  Params used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Header
  /// ```cpp
  /// #include <xtd/boxing>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  template<typename type_t, typename ...args_t>
  [[nodiscard]] auto boxing(args_t&& ...args) noexcept -> box<type_t> {return box<type_t>(args...);}
  /// @}
  
  /// @cond
  [[nodiscard]] inline auto boxing(const object& value) noexcept -> const object& {return value;}
  [[nodiscard]] inline auto boxing(const char* value) noexcept -> string {return string(value);}
  [[nodiscard]] inline auto boxing(const char8* value) noexcept -> string {return string(value);}
  [[nodiscard]] inline auto boxing(const char16* value) noexcept -> string {return string(value);}
  [[nodiscard]] inline auto boxing(const char32* value) noexcept -> string {return string(value);}
  [[nodiscard]] inline auto boxing(const wchar* value) noexcept -> string {return string(value);}
  [[nodiscard]] inline auto boxing(const char& value) noexcept -> char_object {return char_object(value);}
  [[nodiscard]] inline auto boxing(const char8& value) noexcept -> char8_object {return char8_object(value);}
  [[nodiscard]] inline auto boxing(const char16& value) noexcept -> char16_object {return char16_object(value);}
  [[nodiscard]] inline auto boxing(const char32& value) noexcept -> char32_object {return char32_object(value);}
  [[nodiscard]] inline auto boxing(const wchar& value) noexcept -> wchar_object {return wchar_object(value);}
  [[nodiscard]] inline auto boxing(char& value) noexcept -> char_object {return char_object(value);}
  [[nodiscard]] inline auto boxing(char8& value) noexcept -> char8_object {return char8_object(value);}
  [[nodiscard]] inline auto boxing(char16& value) noexcept -> char16_object {return char16_object(value);}
  [[nodiscard]] inline auto boxing(char32& value) noexcept -> char32_object {return char32_object(value);}
  [[nodiscard]] inline auto boxing(wchar& value) noexcept -> wchar_object {return wchar_object(value);}
  [[nodiscard]] inline auto boxing(const xtd::byte& value) noexcept -> byte_object {return byte_object(value);}
  [[nodiscard]] inline auto boxing(const int16& value) noexcept -> int16_object {return int16_object(value);}
  [[nodiscard]] inline auto boxing(const int32& value) noexcept -> int32_object {return int32_object(value);}
  [[nodiscard]] inline auto boxing(const int64& value) noexcept -> int64_object {return int64_object(value);}
  [[nodiscard]] inline auto boxing(const slong& value) noexcept -> slong_object {return slong_object(value);}
  [[nodiscard]] inline auto boxing(const sbyte& value) noexcept -> sbyte_object {return sbyte_object(value);}
  [[nodiscard]] inline auto boxing(const uint16& value) noexcept -> uint16_object {return uint16_object(value);}
  [[nodiscard]] inline auto boxing(const uint32& value) noexcept -> uint32_object {return uint32_object(value);}
  [[nodiscard]] inline auto boxing(const uint64& value) noexcept -> uint64_object {return uint64_object(value);}
  [[nodiscard]] inline auto boxing(const xtd::ulong& value) noexcept -> ulong_object {return ulong_object(value);}
  [[nodiscard]] inline auto boxing(xtd::byte& value) noexcept -> byte_object {return byte_object(value);}
  [[nodiscard]] inline auto boxing(int16& value) noexcept -> int16_object {return int16_object(value);}
  [[nodiscard]] inline auto boxing(int32& value) noexcept -> int32_object {return int32_object(value);}
  [[nodiscard]] inline auto boxing(int64& value) noexcept -> int64_object {return int64_object(value);}
  [[nodiscard]] inline auto boxing(slong& value) noexcept -> slong_object {return slong_object(value);}
  [[nodiscard]] inline auto boxing(sbyte& value) noexcept -> sbyte_object {return sbyte_object(value);}
  [[nodiscard]] inline auto boxing(uint16& value) noexcept -> uint16_object {return uint16_object(value);}
  [[nodiscard]] inline auto boxing(uint32& value) noexcept -> uint32_object {return uint32_object(value);}
  [[nodiscard]] inline auto boxing(uint64& value) noexcept -> uint64_object {return uint64_object(value);}
  [[nodiscard]] inline auto boxing(xtd::ulong& value) noexcept -> ulong_object {return ulong_object(value);}
  [[nodiscard]] inline auto boxing(const float& value) noexcept -> single_object {return single_object(value);}
  [[nodiscard]] inline auto boxing(const double& value) noexcept -> double_object {return double_object(value);}
  [[nodiscard]] inline auto boxing(const decimal& value) noexcept -> decimal_object {return decimal_object(value);}
  [[nodiscard]] inline auto boxing(float& value) noexcept -> single_object {return single_object(value);}
  [[nodiscard]] inline auto boxing(double& value) noexcept -> double_object {return double_object(value);}
  [[nodiscard]] inline auto boxing(decimal& value) noexcept -> decimal_object {return decimal_object(value);}
  template<typename value_t>
  [[nodiscard]] auto boxing(std::vector<value_t>&& value) noexcept -> xtd::collections::generic::list<value_t> {return std::move(value);}
  /// @endcond
}
