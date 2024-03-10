/// @file
/// @brief Contains xtd::unboxing methods.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "box.h"
#include "byte.h"
#include "char.h"
#include "char16.h"
#include "char32.h"
#include "char8.h"
#include "decimal.h"
#include "double.h"
#include "int16.h"
#include "int32.h"
#include "int64.h"
#include "intptr.h"
#include "sbyte.h"
#include "single.h"
#include "size.h"
#include "uint16.h"
#include "uint32.h"
#include "uint64.h"
#include "uintptr.h"
#include "wchar.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Allows to unbox an object
  /// @param value Object to box.
  /// @return Unboxed object.
  /// @par Header
  /// @code #include <xtd/unboxing> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  template<typename type_t>
  inline type_t unboxing(const xtd::box<type_t>& value) noexcept {return value.value();}
  
  /// @cond
  template<typename type_t>
  inline type_t unboxing(xtd::box<type_t>& value) noexcept {return value.value();}
  
  template<typename type_t>
  inline type_t unboxing(const xtd::enum_object<type_t>& value) noexcept {return value.value();}
  
  template<typename type_t>
  inline type_t unboxing(xtd::enum_object<type_t>& value) noexcept {return value.value();}
  
  inline const object& unboxing(const object& value) noexcept {return value;}
  inline object& unboxing(object& value) noexcept {return value;}
  
  inline const char* unboxing(const ustring& value) noexcept {return value.c_str();}
  inline const char* unboxing(ustring& value) noexcept {return value.c_str();}
  
  template<typename char_t>
  inline const char_t* unboxing(const ustring& value) {throw invalid_cast_exception("Invalid character type");}
  template<typename char_t>
  inline const char_t* unboxing(ustring& value) {throw invalid_cast_exception("Invalid character type");}
  
  template<>
  inline const char* unboxing<char>(const ustring& value) {return value.c_str();}
  template<>
  inline const char* unboxing<char>(ustring& value) {return value.c_str();}
  
#if defined(__cpp_lib_char8_t)
  template<>
  inline const char8* unboxing<char8>(const ustring& value) {
    thread_local static std::u8string result;
    result = convert_string::to_u8string(value);
    return result.c_str();
  }
  template<>
  inline const char8* unboxing<char8>(ustring& value) {
    thread_local static std::u8string result;
    result = convert_string::to_u8string(value);
    return result.c_str();
  }
#endif
  
  template<>
  inline const char16* unboxing<char16>(const ustring& value) {
    thread_local static std::u16string result;
    result = convert_string::to_u16string(value);
    return result.c_str();
  }
  template<>
  inline const char16* unboxing<char16>(ustring& value) {
    thread_local static std::u16string result;
    result = convert_string::to_u16string(value);
    return result.c_str();
  }
  
  template<>
  inline const char32* unboxing<char32>(const ustring& value) {
    thread_local static std::u32string result;
    result = convert_string::to_u32string(value);
    return result.c_str();
  }
  template<>
  inline const char32* unboxing<char32>(ustring& value) {
    thread_local static std::u32string result;
    result = convert_string::to_u32string(value);
    return result.c_str();
  }
  
  template<>
  inline const wchar* unboxing<wchar>(const ustring& value) {
    thread_local static std::wstring result;
    result = convert_string::to_wstring(value);
    return result.c_str();
  }
  template<>
  inline const wchar* unboxing<wchar>(ustring& value) {
    thread_local static std::wstring result;
    result = convert_string::to_wstring(value);
    return result.c_str();
  }
  
  /*
  template<typename type_t>
  inline const type_t& unboxing(const type_t& value) noexcept {
    if (dynamic_cast<const xtd::enum_object<type_t>*>(&value) != nullptr) {
      thread_local static type_t result = dynamic_cast<const xtd::enum_object<type_t>*>(&value)->value();
      return result;
    }
    if (dynamic_cast<const xtd::box<type_t>*>(&value) != nullptr)
      return dynamic_cast<const xtd::box<type_t>*>(&value)->value();
    return value;
  }
  
  template<typename type_t>
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
#if defined(__cpp_lib_char8_t)
  inline char8 unboxing(const char8& value) noexcept {return value;}
#endif
  inline char16 unboxing(const char16& value) noexcept {return value;}
  inline char32 unboxing(const char32& value) noexcept {return value;}
  inline wchar unboxing(const wchar& value) noexcept {return value;}
  inline char unboxing(char& value) noexcept {return value;}
#if defined(__cpp_lib_char8_t)
  inline char8 unboxing(char8& value) noexcept {return value;}
#endif
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

  template<typename type_t>
  inline std::string to_string(const xtd::box<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  
  template<typename type_t>
  inline std::string to_string(const xtd::box_char<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  
  template<typename type_t>
  inline std::string to_string(const xtd::box_integer<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  
  template<typename type_t>
  inline std::string to_string(const xtd::box_floating_point<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}
