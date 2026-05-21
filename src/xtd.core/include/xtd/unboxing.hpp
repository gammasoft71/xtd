/// @file
/// @brief Contains xtd::unboxing methods.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "box.hpp"
#include "byte.hpp"
#include "char.hpp"
#include "char16.hpp"
#include "char32.hpp"
#include "char8.hpp"
#include "decimal.hpp"
#include "double.hpp"
#include "int16.hpp"
#include "int32.hpp"
#include "int64.hpp"
#include "intptr.hpp"
#include "sbyte.hpp"
#include "single.hpp"
#include "ssize.hpp"
#include "uint16.hpp"
#include "uint32.hpp"
#include "uint64.hpp"
#include "uintptr.hpp"
#include "usize.hpp"
#include "wchar.hpp"
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Static Methods
  
  /// @{
  /// @brief Allows to unbox an object
  /// @param value Object to box.
  /// @return Unboxed object.
  /// @par Header
  /// ```cpp
  /// #include <xtd/unboxing>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  template<typename type_t>
  [[nodiscard]] inline auto unboxing(const xtd::box<type_t>& value) noexcept -> type_t {return value.value;}
  /// @}
  
  /// @cond
  template<typename type_t>
  [[nodiscard]] inline auto unboxing(xtd::box<type_t>& value) noexcept -> type_t {return value.value;}
  
  template<typename type_t>
  [[nodiscard]] inline auto unboxing(const xtd::enum_object<type_t>& value) noexcept -> type_t {return value.value;}
  
  template<typename type_t>
  [[nodiscard]] inline auto unboxing(xtd::enum_object<type_t>& value) noexcept -> type_t {return value.value;}
  
  [[nodiscard]] inline auto unboxing(const xtd::object& value) noexcept -> const xtd::object& {return value;}
  [[nodiscard]] inline auto unboxing(xtd::object& value) noexcept -> xtd::object& {return value;}
  
  [[nodiscard]] inline auto unboxing(const xtd::string& value) noexcept -> const char* {return value.chars().c_str();}
  [[nodiscard]] inline auto unboxing(xtd::string& value) noexcept -> const char* {return value.chars().c_str();}
  
  template<typename char_t>
  [[nodiscard]] inline auto unboxing(const xtd::string& value) -> const char_t* {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, "Invalid character type");}
  template<typename char_t>
  [[nodiscard]] inline auto unboxing(xtd::string& value) -> const char_t* {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, "Invalid character type");}
  
  template<>
  [[nodiscard]] inline auto unboxing<char>(const xtd::string& value) -> const char* {return value.chars().c_str();}
  template<>
  [[nodiscard]] inline auto unboxing<char>(xtd::string& value) -> const char* {return value.chars().c_str();}
  
  template<>
  [[nodiscard]] inline auto unboxing<xtd::char8>(const xtd::string& value) -> const xtd::char8* {
    thread_local static xtd::u8string result;
    result = convert_string::to_u8string(value);
    return result.c_str();
  }
  template<>
  [[nodiscard]] inline auto unboxing<xtd::char8>(xtd::string& value) -> const xtd::char8* {
    thread_local static xtd::u8string result;
    result = convert_string::to_u8string(value);
    return result.c_str();
  }
  
  template<>
  [[nodiscard]] inline auto unboxing<xtd::char16>(const xtd::string& value) -> const xtd::char16* {
    thread_local static xtd::u16string result;
    result = convert_string::to_u16string(value);
    return result.c_str();
  }
  template<>
  [[nodiscard]] inline auto unboxing<xtd::char16>(xtd::string& value) -> const xtd::char16* {
    thread_local static xtd::u16string result;
    result = convert_string::to_u16string(value);
    return result.c_str();
  }
  
  template<>
  [[nodiscard]] inline auto unboxing<xtd::char32>(const xtd::string& value) -> const xtd::char32* {
    thread_local static xtd::u32string result;
    result = convert_string::to_u32string(value);
    return result.c_str();
  }
  template<>
  [[nodiscard]] inline auto unboxing<char32>(xtd::string& value) -> const char32* {
    thread_local static xtd::u32string result;
    result = convert_string::to_u32string(value);
    return result.c_str();
  }
  
  template<>
  [[nodiscard]] inline auto unboxing<xtd::wchar>(const xtd::string& value) -> const xtd::wchar* {
    thread_local static xtd::wstring result;
    result = convert_string::to_wstring(value);
    return result.c_str();
  }
  template<>
  [[nodiscard]] inline auto unboxing<xtd::wchar>(string& value) -> const xtd::wchar* {
    thread_local static std::wstring result;
    result = convert_string::to_wstring(value);
    return result.c_str();
  }
  
  /*
  template<typename type_t>
   [[nodiscard]] inline auto unboxing(const type_t& value) noexcept -> const type_t& {
    if (dynamic_cast<const xtd::enum_object<type_t>*>(&value) != nullptr) {
      thread_local static type_t result = dynamic_cast<const xtd::enum_object<type_t>*>(&value)->value();
      return result;
    }
    if (dynamic_cast<const xtd::box<type_t>*>(&value) != nullptr)
      return dynamic_cast<const xtd::box<type_t>*>(&value)->value();
    return value;
  }
  
  template<typename type_t>
   [[nodiscard]] inline auto unboxing(type_t& value) noexcept -> type_t& {
    if (dynamic_cast<xtd::enum_object<type_t>*>(&value) != nullptr) {
      thread_local static type_t result = dynamic_cast<xtd::enum_object<type_t>*>(&value)->value();
      return result;
    }
    auto result = dynamic_cast<xtd::box<type_t>*>(&value);
    if (result != nullptr)
      return dynamic_cast<xtd::box<type_t>*>(&value)->value();
    return value;
  }
   */
  
  [[nodiscard]] inline auto unboxing(const char& value) noexcept -> char {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::char8& value) noexcept -> xtd::char8 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::char16& value) noexcept -> xtd::char16 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::char32& value) noexcept -> xtd::char32 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::wchar& value) noexcept -> xtd::wchar {return value;}
  [[nodiscard]] inline auto unboxing(char& value) noexcept -> char {return value;}
  [[nodiscard]] inline auto unboxing(xtd::char8& value) noexcept -> xtd::char8 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::char16& value) noexcept -> xtd::char16 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::char32& value) noexcept -> xtd::char32 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::wchar& value) noexcept -> xtd::wchar {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::byte& value) noexcept -> xtd::byte {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::int16& value) noexcept -> xtd::int16 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::int32& value) noexcept -> xtd::int32 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::int64& value) noexcept -> xtd::int64 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::slong& value) noexcept -> xtd::slong {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::sbyte& value) noexcept -> xtd::sbyte {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::uint16& value) noexcept -> xtd::uint16 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::uint32& value) noexcept -> xtd::uint32 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::uint64& value) noexcept -> xtd::uint64 {return value;}
  [[nodiscard]] inline auto unboxing(const xtd::ulong& value) noexcept -> xtd::ulong {return value;}
  [[nodiscard]] inline auto unboxing(xtd::byte& value) noexcept -> xtd::byte {return value;}
  [[nodiscard]] inline auto unboxing(xtd::int16& value) noexcept -> xtd::int16 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::int32& value) noexcept -> xtd::int32 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::int64& value) noexcept -> xtd::int64 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::slong& value) noexcept -> xtd::slong {return value;}
  [[nodiscard]] inline auto unboxing(xtd::sbyte& value) noexcept -> xtd::sbyte {return value;}
  [[nodiscard]] inline auto unboxing(xtd::uint16& value) noexcept -> xtd::uint16 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::uint32& value) noexcept -> xtd::uint32 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::uint64& value) noexcept -> xtd::uint64 {return value;}
  [[nodiscard]] inline auto unboxing(xtd::ulong& value) noexcept -> xtd::ulong {return value;}
  [[nodiscard]] inline auto unboxing(const float& value) noexcept -> float {return value;}
  [[nodiscard]] inline auto unboxing(const double& value) noexcept -> double {return value;}
  [[nodiscard]] inline auto unboxing(const decimal& value) noexcept -> decimal {return value;}
  [[nodiscard]] inline auto unboxing(float& value) noexcept -> float {return value;}
  [[nodiscard]] inline auto unboxing(double& value) noexcept -> double {return value;}
  [[nodiscard]] inline auto unboxing(xtd::decimal& value) noexcept -> xtd::decimal {return value;}
  /// @endcond
}
