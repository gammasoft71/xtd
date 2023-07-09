/// @file
/// @brief Contains xtd::unboxing methods.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Allows to unbox an object
  /// @param value Object to box.
  /// @return Unboxed object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
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
  
  template<typename type_t>
  inline std::string to_string(const xtd::box<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}

//#include "box_integer.h"
//#include "box_floating_point.h"
//#include "box_char.h"

