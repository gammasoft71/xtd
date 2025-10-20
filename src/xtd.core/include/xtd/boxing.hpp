/// @file
/// @brief Contains xtd::boxing methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
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
#include "size_object.hpp"
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
  template<class type_t>
  inline auto boxing(const type_t& value) noexcept {return typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type(value);}
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
  template<class type_t, class ...args_t>
  inline box<type_t> boxing(args_t&& ...args) noexcept {return box<type_t>(args...);}
  /// @}
  
  /// @cond
  inline const object& boxing(const object& value) noexcept {return value;}
  inline string boxing(const char* value) noexcept {return string(value);}
  inline string boxing(const char8* value) noexcept {return string(value);}
  inline string boxing(const char16* value) noexcept {return string(value);}
  inline string boxing(const char32* value) noexcept {return string(value);}
  inline string boxing(const wchar* value) noexcept {return string(value);}
  inline char_object boxing(const char& value) noexcept {return char_object(value);}
  inline char8_object boxing(const char8& value) noexcept {return char8_object(value);}
  inline char16_object boxing(const char16& value) noexcept {return char16_object(value);}
  inline char32_object boxing(const char32& value) noexcept {return char32_object(value);}
  inline wchar_object boxing(const wchar& value) noexcept {return wchar_object(value);}
  inline char_object boxing(char& value) noexcept {return char_object(value);}
  inline char8_object boxing(char8& value) noexcept {return char8_object(value);}
  inline char16_object boxing(char16& value) noexcept {return char16_object(value);}
  inline char32_object boxing(char32& value) noexcept {return char32_object(value);}
  inline wchar_object boxing(wchar& value) noexcept {return wchar_object(value);}
  inline byte_object boxing(const xtd::byte& value) noexcept {return byte_object(value);}
  inline int16_object boxing(const int16& value) noexcept {return int16_object(value);}
  inline int32_object boxing(const int32& value) noexcept {return int32_object(value);}
  inline int64_object boxing(const int64& value) noexcept {return int64_object(value);}
  inline slong_object boxing(const slong& value) noexcept {return slong_object(value);}
  inline sbyte_object boxing(const sbyte& value) noexcept {return sbyte_object(value);}
  inline uint16_object boxing(const uint16& value) noexcept {return uint16_object(value);}
  inline uint32_object boxing(const uint32& value) noexcept {return uint32_object(value);}
  inline uint64_object boxing(const uint64& value) noexcept {return uint64_object(value);}
  inline ulong_object boxing(const xtd::ulong& value) noexcept {return ulong_object(value);}
  inline byte_object boxing(xtd::byte& value) noexcept {return byte_object(value);}
  inline int16_object boxing(int16& value) noexcept {return int16_object(value);}
  inline int32_object boxing(int32& value) noexcept {return int32_object(value);}
  inline int64_object boxing(int64& value) noexcept {return int64_object(value);}
  inline slong_object boxing(slong& value) noexcept {return slong_object(value);}
  inline sbyte_object boxing(sbyte& value) noexcept {return sbyte_object(value);}
  inline uint16_object boxing(uint16& value) noexcept {return uint16_object(value);}
  inline uint32_object boxing(uint32& value) noexcept {return uint32_object(value);}
  inline uint64_object boxing(uint64& value) noexcept {return uint64_object(value);}
  inline ulong_object boxing(xtd::ulong& value) noexcept {return ulong_object(value);}
  inline single_object boxing(const float& value) noexcept {return single_object(value);}
  inline double_object boxing(const double& value) noexcept {return double_object(value);}
  inline decimal_object boxing(const decimal& value) noexcept {return decimal_object(value);}
  inline single_object boxing(float& value) noexcept {return single_object(value);}
  inline double_object boxing(double& value) noexcept {return double_object(value);}
  inline decimal_object boxing(decimal& value) noexcept {return decimal_object(value);}
  template<class value_t>
  inline xtd::collections::generic::list<value_t> boxing(std::vector<value_t>&& value) noexcept {return std::move(value);}
  /// @endcond
}
