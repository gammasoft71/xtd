/// @file
/// @brief Contains xtd::unboxing methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
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
#include "size.hpp"
#include "uint16.hpp"
#include "uint32.hpp"
#include "uint64.hpp"
#include "uintptr.hpp"
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
  template<class type_t>
  inline type_t unboxing(const xtd::box<type_t>& value) noexcept {return value.value;}
  /// @}
  
  /// @cond
  template<class type_t>
  inline type_t unboxing(xtd::box<type_t>& value) noexcept {return value.value;}
  
  template<class type_t>
  inline type_t unboxing(const xtd::enum_object<type_t>& value) noexcept {return value.value;}
  
  template<class type_t>
  inline type_t unboxing(xtd::enum_object<type_t>& value) noexcept {return value.value;}
  
  inline const object& unboxing(const object& value) noexcept {return value;}
  inline object& unboxing(object& value) noexcept {return value;}
  
  inline const char* unboxing(const string& value) noexcept {return value.chars().c_str();}
  inline const char* unboxing(string& value) noexcept {return value.chars().c_str();}
  
  template<class char_t>
  inline const char_t* unboxing(const string& value) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, "Invalid character type");}
  template<class char_t>
  inline const char_t* unboxing(string& value) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, "Invalid character type");}
  
  template<>
  inline const char* unboxing<char>(const string& value) {return value.chars().c_str();}
  template<>
  inline const char* unboxing<char>(string& value) {return value.chars().c_str();}
  
  template<>
  inline const char8* unboxing<char8>(const string& value) {
    thread_local static std::u8string result;
    result = convert_string::to_u8string(value);
    return result.c_str();
  }
  template<>
  inline const char8* unboxing<char8>(string& value) {
    thread_local static std::u8string result;
    result = convert_string::to_u8string(value);
    return result.c_str();
  }
  
  template<>
  inline const char16* unboxing<char16>(const string& value) {
    thread_local static std::u16string result;
    result = convert_string::to_u16string(value);
    return result.c_str();
  }
  template<>
  inline const char16* unboxing<char16>(string& value) {
    thread_local static std::u16string result;
    result = convert_string::to_u16string(value);
    return result.c_str();
  }
  
  template<>
  inline const char32* unboxing<char32>(const string& value) {
    thread_local static std::u32string result;
    result = convert_string::to_u32string(value);
    return result.c_str();
  }
  template<>
  inline const char32* unboxing<char32>(string& value) {
    thread_local static std::u32string result;
    result = convert_string::to_u32string(value);
    return result.c_str();
  }
  
  template<>
  inline const wchar* unboxing<wchar>(const string& value) {
    thread_local static std::wstring result;
    result = convert_string::to_wstring(value);
    return result.c_str();
  }
  template<>
  inline const wchar* unboxing<wchar>(string& value) {
    thread_local static std::wstring result;
    result = convert_string::to_wstring(value);
    return result.c_str();
  }
  
  /*
  template<class type_t>
  inline const type_t& unboxing(const type_t& value) noexcept {
    if (dynamic_cast<const xtd::enum_object<type_t>*>(&value) != nullptr) {
      thread_local static type_t result = dynamic_cast<const xtd::enum_object<type_t>*>(&value)->value();
      return result;
    }
    if (dynamic_cast<const xtd::box<type_t>*>(&value) != nullptr)
      return dynamic_cast<const xtd::box<type_t>*>(&value)->value();
    return value;
  }
  
  template<class type_t>
  inline type_t& unboxing(type_t& value) noexcept {
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
  
  inline char unboxing(const char& value) noexcept {return value;}
  inline char8 unboxing(const char8& value) noexcept {return value;}
  inline char16 unboxing(const char16& value) noexcept {return value;}
  inline char32 unboxing(const char32& value) noexcept {return value;}
  inline wchar unboxing(const wchar& value) noexcept {return value;}
  inline char unboxing(char& value) noexcept {return value;}
  inline char8 unboxing(char8& value) noexcept {return value;}
  inline char16 unboxing(char16& value) noexcept {return value;}
  inline char32 unboxing(char32& value) noexcept {return value;}
  inline wchar unboxing(wchar& value) noexcept {return value;}
  inline xtd::byte unboxing(const xtd::byte& value) noexcept {return value;}
  inline int16 unboxing(const int16& value) noexcept {return value;}
  inline int32 unboxing(const int32& value) noexcept {return value;}
  inline int64 unboxing(const int64& value) noexcept {return value;}
  inline slong unboxing(const slong& value) noexcept {return value;}
  inline sbyte unboxing(const sbyte& value) noexcept {return value;}
  inline uint16 unboxing(const uint16& value) noexcept {return value;}
  inline uint32 unboxing(const uint32& value) noexcept {return value;}
  inline uint64 unboxing(const uint64& value) noexcept {return value;}
  inline xtd::ulong unboxing(const xtd::ulong& value) noexcept {return value;}
  inline xtd::byte unboxing(xtd::byte& value) noexcept {return value;}
  inline int16 unboxing(int16& value) noexcept {return value;}
  inline int32 unboxing(int32& value) noexcept {return value;}
  inline int64 unboxing(int64& value) noexcept {return value;}
  inline slong unboxing(slong& value) noexcept {return value;}
  inline sbyte unboxing(sbyte& value) noexcept {return value;}
  inline uint16 unboxing(uint16& value) noexcept {return value;}
  inline uint32 unboxing(uint32& value) noexcept {return value;}
  inline uint64 unboxing(uint64& value) noexcept {return value;}
  inline xtd::ulong unboxing(xtd::ulong& value) noexcept {return value;}
  inline float unboxing(const float& value) noexcept {return value;}
  inline double unboxing(const double& value) noexcept {return value;}
  inline decimal unboxing(const decimal& value) noexcept {return value;}
  inline float unboxing(float& value) noexcept {return value;}
  inline double unboxing(double& value) noexcept {return value;}
  inline decimal unboxing(decimal& value) noexcept {return value;}
  /// @endcond
}
