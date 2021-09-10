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
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(std::any value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(bool value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(byte_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char8_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char16_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char32_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(wchar_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(decimal_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(double value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(float value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(int16_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(int32_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(int64_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(llong_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(sbyte_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(uint16_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(uint32_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(uint64_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(ullong_t value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const xtd::ustring& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const std::string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const std::u8string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const std::u16string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const std::u32string& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const std::wstring& value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const char* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const char8_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char8_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const char16_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char16_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const char32_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(char32_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(const wchar_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new byte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// byte_t result = as<byte_t>(value);
  /// @endcode
  template<>
  inline byte_t as<byte_t>(wchar_t* value) {
    return xtd::convert::to_byte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(std::any value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(bool value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(byte_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char8_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char16_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char32_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(wchar_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(decimal_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(double value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(float value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(int16_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(int32_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(int64_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(llong_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(sbyte_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(uint16_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(uint32_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(uint64_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(ullong_t value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const xtd::ustring& value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const std::string& value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const std::u8string& value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const std::u16string& value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const std::u32string& value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const std::wstring& value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const char* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const char8_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char8_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const char16_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char16_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const char32_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(char32_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(const wchar_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// char result = as<char>(value);
  /// @endcode
  template<>
  inline char as<char>(wchar_t* value) {
    return xtd::convert::to_char(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(std::any value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(bool value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(byte_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char8_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char16_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char32_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(wchar_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(decimal_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(double value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(float value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(int16_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(int32_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(int64_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(llong_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(sbyte_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(uint16_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(uint32_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(uint64_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(ullong_t value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const xtd::ustring& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const std::string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const std::u8string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const std::u16string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const std::u32string& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const std::wstring& value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const char* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const char8_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char8_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const char16_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char16_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const char32_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(char32_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(const wchar_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char8_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// char8_t result = as<char8_t>(value);
  /// @endcode
  template<>
  inline char8_t as<char8_t>(wchar_t* value) {
    return xtd::convert::to_char8(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(std::any value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(bool value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(byte_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char8_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char16_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char32_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(wchar_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(decimal_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(double value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(float value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(int16_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(int32_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(int64_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(llong_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(sbyte_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(uint16_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(uint32_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(uint64_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(ullong_t value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const xtd::ustring& value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const std::string& value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const std::u8string& value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const std::u16string& value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const std::u32string& value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const std::wstring& value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const char* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const char8_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char8_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const char16_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char16_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const char32_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(char32_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(const wchar_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// char16_t result = as<char16_t>(value);
  /// @endcode
  template<>
  inline char16_t as<char16_t>(wchar_t* value) {
    return xtd::convert::to_char16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(std::any value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(bool value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(byte_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char8_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char16_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char32_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(wchar_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(decimal_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(double value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(float value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(int16_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(int32_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(int64_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(llong_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(sbyte_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(uint16_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(uint32_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(uint64_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(ullong_t value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const xtd::ustring& value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const std::string& value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const std::u8string& value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const std::u16string& value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const std::u32string& value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const std::wstring& value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const char* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const char8_t* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char8_t* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const char16_t* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char16_t* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const char32_t* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(char32_t* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(const wchar_t* value) {
    return xtd::convert::to_char32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new char32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// char32_t result = as<char32_t>(value);
  /// @endcode
  template<>
  inline char32_t as<char32_t>(wchar_t* value) {
    return xtd::convert::to_char32(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(std::any value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(bool value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(byte_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char8_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char16_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char32_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(wchar_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(decimal_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(double value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(float value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(int16_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(int32_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(int64_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(llong_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(sbyte_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(uint16_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(uint32_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(uint64_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(ullong_t value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const xtd::ustring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const std::string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const std::u8string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const std::u16string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const std::u32string& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const std::wstring& value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const char* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const char8_t* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char8_t* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const char16_t* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char16_t* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const char32_t* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(char32_t* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(const wchar_t* value) {
    return xtd::convert::to_wchar(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new wchar_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// wchar_t result = as<wchar_t>(value);
  /// @endcode
  template<>
  inline wchar_t as<wchar_t>(wchar_t* value) {
    return xtd::convert::to_wchar(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(std::any value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(bool value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(byte_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char8_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char16_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char32_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(wchar_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(decimal_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(double value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(float value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(int16_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(int32_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(int64_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(llong_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(sbyte_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(uint16_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(uint32_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(uint64_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(ullong_t value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const xtd::ustring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const std::string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const std::u8string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const std::u16string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const std::u32string& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const std::wstring& value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const char* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const char8_t* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char8_t* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const char16_t* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char16_t* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const char32_t* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(char32_t* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(const wchar_t* value) {
    return xtd::convert::to_decimal(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new decimal_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// decimal_t result = as<decimal_t>(value);
  /// @endcode
  template<>
  inline decimal_t as<decimal_t>(wchar_t* value) {
    return xtd::convert::to_decimal(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(std::any value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(bool value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(byte_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char8_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char16_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char32_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(wchar_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(decimal_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(double value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(float value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(int16_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(int32_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(int64_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(llong_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(sbyte_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(uint16_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(uint32_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(uint64_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(ullong_t value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const xtd::ustring& value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const std::string& value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const std::u8string& value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const std::u16string& value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const std::u32string& value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const std::wstring& value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const char* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const char8_t* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char8_t* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const char16_t* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char16_t* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const char32_t* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(char32_t* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(const wchar_t* value) {
    return xtd::convert::to_double(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new double object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// double result = as<double>(value);
  /// @endcode
  template<>
  inline double as<double>(wchar_t* value) {
    return xtd::convert::to_double(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(std::any value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(bool value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  template<>
  inline float as<float>(byte_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char8_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char16_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char32_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(wchar_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(decimal_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(double value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(float value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  template<>
  inline float as<float>(int16_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
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
  template<>
  inline float as<float>(int32_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(int64_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(llong_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(sbyte_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(uint16_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(uint32_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(uint64_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(ullong_t value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const xtd::ustring& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::u8string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::u16string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::u32string& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const std::wstring& value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char8_t* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char8_t* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char16_t* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char16_t* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const char32_t* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(char32_t* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(const wchar_t* value) {
    return xtd::convert::to_single(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new float object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// float result = as<float>(value);
  /// @endcode
  template<>
  inline float as<float>(wchar_t* value) {
    return xtd::convert::to_single(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(std::any value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(bool value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(byte_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char8_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char16_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char32_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(wchar_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(decimal_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(double value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(float value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(int16_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(int32_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(int64_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(llong_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(sbyte_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(uint16_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(uint32_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(uint64_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(ullong_t value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const xtd::ustring& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const std::string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const std::u8string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const std::u16string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const std::u32string& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const std::wstring& value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const char* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const char8_t* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char8_t* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const char16_t* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char16_t* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const char32_t* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(char32_t* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(const wchar_t* value) {
    return xtd::convert::to_int16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// int16_t result = as<int16_t>(value);
  /// @endcode
  template<>
  inline int16_t as<int16_t>(wchar_t* value) {
    return xtd::convert::to_int16(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(std::any value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(bool value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(byte_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char8_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char16_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char32_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(wchar_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(decimal_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(double value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(float value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(int16_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(int32_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(int64_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(llong_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(sbyte_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(uint16_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(uint32_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(uint64_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(ullong_t value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const xtd::ustring& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const std::string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const std::u8string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const std::u16string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const std::u32string& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const std::wstring& value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const char* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const char8_t* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char8_t* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const char16_t* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char16_t* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const char32_t* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(char32_t* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(const wchar_t* value) {
    return xtd::convert::to_int32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// int32_t result = as<int32_t>(value);
  /// @endcode
  template<>
  inline int32_t as<int32_t>(wchar_t* value) {
    return xtd::convert::to_int32(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(std::any value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(bool value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(byte_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char8_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char16_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char32_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(wchar_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(decimal_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(double value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(float value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(int16_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(int32_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(int64_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(llong_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(sbyte_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(uint16_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(uint32_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(uint64_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(ullong_t value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const xtd::ustring& value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const std::string& value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const std::u8string& value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const std::u16string& value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const std::u32string& value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const std::wstring& value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const char* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const char8_t* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char8_t* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const char16_t* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char16_t* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const char32_t* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(char32_t* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(const wchar_t* value) {
    return xtd::convert::to_int64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new int64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// int64_t result = as<int64_t>(value);
  /// @endcode
  template<>
  inline int64_t as<int64_t>(wchar_t* value) {
    return xtd::convert::to_int64(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(std::any value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(bool value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(byte_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char8_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char16_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char32_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(wchar_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(decimal_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(double value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(float value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(int16_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(int32_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(int64_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(llong_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(sbyte_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(uint16_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(uint32_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(uint64_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(ullong_t value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const xtd::ustring& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const std::string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const std::u8string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const std::u16string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const std::u32string& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const std::wstring& value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const char* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const char8_t* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char8_t* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const char16_t* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char16_t* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const char32_t* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(char32_t* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(const wchar_t* value) {
    return xtd::convert::to_llong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new llong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// llong_t result = as<llong_t>(value);
  /// @endcode
  template<>
  inline llong_t as<llong_t>(wchar_t* value) {
    return xtd::convert::to_llong(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(std::any value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(bool value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(byte_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char8_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char16_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char32_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(wchar_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(decimal_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(double value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(float value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(int16_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(int32_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(int64_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(llong_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(sbyte_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(uint16_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(uint32_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(uint64_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(ullong_t value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const xtd::ustring& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const std::string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const std::u8string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const std::u16string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const std::u32string& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const std::wstring& value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const char* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const char8_t* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char8_t* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const char16_t* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char16_t* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const char32_t* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(char32_t* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(const wchar_t* value) {
    return xtd::convert::to_sbyte(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new sbyte_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// sbyte_t result = as<sbyte_t>(value);
  /// @endcode
  template<>
  inline sbyte_t as<sbyte_t>(wchar_t* value) {
    return xtd::convert::to_sbyte(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(std::any value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(bool value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(byte_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char8_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char16_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char32_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(wchar_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(decimal_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(double value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(float value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(int16_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(int32_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(int64_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(llong_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(sbyte_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(uint16_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(uint32_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(uint64_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(ullong_t value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const xtd::ustring& value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const std::string& value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const std::u8string& value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const std::u16string& value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const std::u32string& value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const std::wstring& value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const char* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const char8_t* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char8_t* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const char16_t* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char16_t* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const char32_t* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(char32_t* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(const wchar_t* value) {
    return xtd::convert::to_uint16(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint16_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// uint16_t result = as<uint16_t>(value);
  /// @endcode
  template<>
  inline uint16_t as<uint16_t>(wchar_t* value) {
    return xtd::convert::to_uint16(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(std::any value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(bool value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(byte_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char8_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char16_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char32_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(wchar_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(decimal_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(double value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(float value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(int16_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(int32_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(int64_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(llong_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(sbyte_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(uint16_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(uint32_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(uint64_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(ullong_t value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const xtd::ustring& value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const std::string& value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const std::u8string& value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const std::u16string& value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const std::u32string& value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const std::wstring& value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const char* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const char8_t* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char8_t* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const char16_t* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char16_t* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const char32_t* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(char32_t* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(const wchar_t* value) {
    return xtd::convert::to_uint32(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint32_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// uint32_t result = as<uint32_t>(value);
  /// @endcode
  template<>
  inline uint32_t as<uint32_t>(wchar_t* value) {
    return xtd::convert::to_uint32(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(std::any value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(bool value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(byte_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char8_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char16_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char32_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(wchar_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(decimal_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(double value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(float value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(int16_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(int32_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(int64_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(llong_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(sbyte_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(uint16_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(uint32_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(uint64_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(ullong_t value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const xtd::ustring& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const std::string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const std::u8string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const std::u16string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const std::u32string& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const std::wstring& value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const char* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const char8_t* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char8_t* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const char16_t* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char16_t* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const char32_t* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(char32_t* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(const wchar_t* value) {
    return xtd::convert::to_uint64(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new uint64_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// uint64_t result = as<uint64_t>(value);
  /// @endcode
  template<>
  inline uint64_t as<uint64_t>(wchar_t* value) {
    return xtd::convert::to_uint64(value);
  }

  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// std::any value = true;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(std::any value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// bool value = true;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(bool value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// byte_t value = 42;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(byte_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char value = 'a';
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t value = u8'a';
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char8_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t value = u'a';
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char16_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t value = u'a';
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char32_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::invalid_cast_exception throws always exception.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t value = u'a';
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(wchar_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// decimal_t value = 42.50l;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(decimal_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// double value = 42.50;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(double value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// float value = 42.50f;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(float value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int16_t value = 42;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(int16_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int32_t value = 42;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(int32_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// int64_t value = 42l;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(int64_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// llong_t value = 42ll;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(llong_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// sbyte_t value = 42ll;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(sbyte_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint16_t value = 42u;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(uint16_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint32_t value = 42u;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(uint32_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// uint64_t value = 42ul;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(uint64_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ullong_t value = 42ull;
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(ullong_t value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// ustring value = "42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const xtd::ustring& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// string value = "42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const std::string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u8string value = u8"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const std::u8string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u16string value = u"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const std::u16string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// u32string value = U"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const std::u32string& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wstring value = L"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const std::wstring& value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char* value = "42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const char* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char* value = "42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char8_t* value = u8"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const char8_t* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char8_t* value = u8"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char8_t* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char16_t* value = u"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const char16_t* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char16_t* value = u"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char16_t* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const char32_t* value = U"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const char32_t* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// char32_t* value = U"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(char32_t* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// const wchar_t* value = L"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(const wchar_t* value) {
    return xtd::convert::to_ullong(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new ullong_t object converted from value.
  /// @exception xtd::aegument_exception value does not represent a bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// @code
  /// wchar_t* value = L"42";
  /// ullong_t result = as<ullong_t>(value);
  /// @endcode
  template<>
  inline ullong_t as<ullong_t>(wchar_t* value) {
    return xtd::convert::to_ullong(value);
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
