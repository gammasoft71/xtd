/// @file
/// @brief Contains xtd::as method.
#pragma once
#include <any>
#include <memory>
#include "convert.h"
#include "convert_pointer.h"
#include "convert_string.h"
#include "invalid_cast_exception.h"
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // ___________________________________________________________________________________________
  //                                                                                     generic

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = 42;
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(std::any value) {
    try {
      return any_cast<new_type_t>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(bool value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(byte_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char8_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u'a';
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char16_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = U'a';
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char32_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = L'a';
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(wchar_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.0l;
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(decimal_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.0;
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(double value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.0f;
  /// int result = as<int>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(float value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(int16_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(int32_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(int64_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(llong_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(sbyte_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(uint16_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(uint32_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(uint64_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42;
  /// float result = as<float>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(ullong_t value) {
    return static_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "Gammasoft";
  /// object result = as<object>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const xtd::ustring& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
    throw std::bad_cast();
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t>
  new_type_t as(const std::string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
    throw std::bad_cast();
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t>
  new_type_t as(const std::u8string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
    throw std::bad_cast();
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t>
  new_type_t as(const std::u16string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
    throw std::bad_cast();
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t>
  new_type_t as(const std::u32string& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
    throw std::bad_cast();
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @exception xtd::invalid_cast_exception value bad type
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  template<typename new_type_t>
  new_type_t as(const std::wstring& value) {
    try {
      return dynamic_cast<const new_type_t&>(value);
    } catch (const std::exception& e) {
      throw invalid_cast_exception(e.what(), csf_);
    }
    throw std::bad_cast();
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const char* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const char8_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char8_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const char16_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char16_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const char32_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(char32_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(const wchar_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new new_type_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"Gammasoft";
  /// intptr_t result = as<intptr_t>(value);
  /// @endcode
  template<typename new_type_t>
  new_type_t as(wchar_t* value) {
    return reinterpret_cast<new_type_t>(value);
  }
  
  // ___________________________________________________________________________________________
  //                                                                 xtd::convert specialization
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(std::any value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(bool value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(byte_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char8_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char16_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char32_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(wchar_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(decimal_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(double value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(float value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(int16_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(int32_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(int64_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(llong_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(sbyte_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(uint16_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(uint32_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(uint64_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(ullong_t value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const xtd::ustring& value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const std::string& value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const std::u8string& value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const std::u16string& value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const std::u32string& value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const std::wstring& value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const char* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const char8_t* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char8_t* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const char16_t* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char16_t* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const char32_t* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(char32_t* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(const wchar_t* value) {
    return xtd::convert::to_boolean(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// bool result = as<bool>(value);
  /// @endcode
  template<>
  inline bool as<bool>(wchar_t* value) {
    return xtd::convert::to_boolean(value);
  }

  // ___________________________________________________________________________________________
  //                                                         xtd::convert_pointer specialization
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const button* value = new xtd::forms::button();
  /// const control& result = as<xtd::forms::control>(*value);
  /// @endcode
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  const new_type_t& as(const current_type_t& value) {
    return xtd::convert_pointer::to_ref<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// button* value = new xtd::forms::button();
  /// control& result = as<xtd::forms::control>(*value);
  /// @endcode
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  new_type_t& as(current_type_t& value) {
    return xtd::convert_pointer::to_ref<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const button* value = new xtd::forms::button();
  /// const control* result = as<xtd::forms::control>(value);
  /// @endcode
  template<typename new_type_t, typename current_type_t>
  const new_type_t* as(const current_type_t* value) {
    return xtd::convert_pointer::to_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// button* value = new xtd::forms::button();
  /// control* result = as<xtd::forms::control>(value);
  /// @endcode
  template<typename new_type_t, typename current_type_t>
  new_type_t* as(current_type_t* value) {
    return xtd::convert_pointer::to_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::unique_ptr<button> value = std::make_unique<xtd::forms::button>();
  /// std::unique_ptr<control> result = as<xtd::forms::control>(value);
  /// @endcode
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  std::unique_ptr<new_type_t> as(std::unique_ptr<current_type_t>& value) {
    return xtd::convert_pointer::to_unique_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::unique_ptr<control> result = as<xtd::forms::control>(std::make_unique<xtd::forms::button>());
  /// @endcode
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  std::unique_ptr<new_type_t> as(std::unique_ptr<current_type_t>&& value) {
    return xtd::convert_pointer::to_unique_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const std::shared_ptr<button> value = std::make_shared<xtd::forms::button>();
  /// const std::shared_ptr<control> result = as<xtd::forms::control>(value);
  /// @endcode
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  std::shared_ptr<new_type_t> as(const std::shared_ptr<current_type_t>& value) {
    return xtd::convert_pointer::to_shared_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::shared_ptr<control> result = as<xtd::forms::control>(std::make_shared<xtd::forms::button>());
  /// @endcode
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  std::shared_ptr<new_type_t> as(std::shared_ptr<current_type_t>& value) {
    return xtd::convert_pointer::to_shared_ptr<new_type_t>(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const std::shared_ptr<button> value = std::make_shared<xtd::forms::button>();
  /// const std::shared_ptr<control> result = as<xtd::forms::control>(value);
  /// @endcode
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  template<typename new_type_t, typename current_type_t>
  std::shared_ptr<new_type_t> as(std::shared_ptr<current_type_t>&& value) {
    return xtd::convert_pointer::to_shared_ptr<new_type_t>(value);
  }
  
  // ___________________________________________________________________________________________
  //                                                          xtd::convert_string specialization
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const std::string& value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::string& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const std::string& value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const std::string& value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const std::string& value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const std::string& value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const char* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const char* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* cvalue1 = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const char* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const char* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const char* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const char* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(char* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(char* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(char* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(char* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(char* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(char* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const xtd::ustring& value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const xtd::ustring& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const xtd::ustring& value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const xtd::ustring& value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const xtd::ustring& value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const xtd::ustring& value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const std::u8string& value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::u8string& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const std::u8string& value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const std::u8string& value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const std::u8string& value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const std::u8string& value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const char8_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const char8_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const char8_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const char8_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const char8_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const char8_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(char8_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(char8_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(char8_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(char8_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(char8_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(char8_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const std::u16string& value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::u16string& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = "Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const std::u16string& value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const std::u16string& value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const std::u16string& value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const std::u16string& value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const char16_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const char16_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const char16_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const char16_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const char16_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const char16_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(char16_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(char16_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(char16_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(char16_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(char16_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(char16_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const std::u32string& value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::u32string& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const std::u32string& value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const std::u32string& value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const std::u32string& value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const std::u32string& value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const char32_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const char32_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const char32_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const char32_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const char32_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const char32_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(char32_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(char32_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(char32_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(char32_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(char32_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(char32_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const std::wstring& value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const std::wstring& value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const std::wstring& value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const std::wstring& value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const std::wstring& value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const std::wstring& value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(const wchar_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(const wchar_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(const wchar_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(const wchar_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(const wchar_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(const wchar_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"Gammasoft";
  /// string result = as<string>(value);
  /// @endcode
  template<>
  inline std::string as<std::string>(wchar_t* value) {
    return xtd::convert_string::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"Gammasoft";
  /// ustring result = as<ustring>(value);
  /// @endcode
  template<>
  inline xtd::ustring as<xtd::ustring>(wchar_t* value) {
    return xtd::convert_string::to_ustring(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"Gammasoft";
  /// u8string result = as<u8string>(value);
  /// @endcode
  template<>
  inline std::u8string as<std::u8string>(wchar_t* value) {
    return xtd::convert_string::to_u8string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"Gammasoft";
  /// u16string result = as<u16string>(value);
  /// @endcode
  template<>
  inline std::u16string as<std::u16string>(wchar_t* value) {
    return xtd::convert_string::to_u16string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"Gammasoft";
  /// u32string result = as<u32string>(value);
  /// @endcode
  template<>
  inline std::u32string as<std::u32string>(wchar_t* value) {
    return xtd::convert_string::to_u32string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"Gammasoft";
  /// wstring result = as<wstring>(value);
  /// @endcode
  template<>
  inline std::wstring as<std::wstring>(wchar_t* value) {
    return xtd::convert_string::to_wstring(value);
  }
}
