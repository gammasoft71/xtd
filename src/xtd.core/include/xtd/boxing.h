/// @file
/// @brief Contains xtd::boxing methods.
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
#include "slong.h"
#include "uint16.h"
#include "uint32.h"
#include "uint64.h"
#include "uintptr.h"
#include "ulong.h"
#include "wchar.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__box_enum_or_object.h"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Allows to box an object
  /// @param value Value used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Header
  /// @code #include <xtd/boxing> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  template<typename type_t>
  inline auto boxing(const type_t& value) noexcept {return typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type(value);}
  /// @brief Allows to box an object
  /// @param ...args  Params used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Header
  /// @code #include <xtd/boxing> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  template<typename type_t, typename ...args_t>
  inline box<type_t> boxing(args_t&& ...args) noexcept {return box<type_t>(args...);}

  /// @cond
  inline const object& boxing(const object& value) noexcept {return value;}
  inline ustring boxing(const char* value) noexcept {return ustring(value);}
#if defined(__cpp_lib_char8_t)
  inline ustring boxing(const char8* value) noexcept {return ustring(value);}
#endif
  inline ustring boxing(const char16* value) noexcept {return ustring(value);}
  inline ustring boxing(const char32* value) noexcept {return ustring(value);}
  inline ustring boxing(const wchar* value) noexcept {return ustring(value);}
  inline char_object boxing(const char& value) noexcept {return char_object(value);}
#if defined(__cpp_lib_char8_t)
  inline char8_object boxing(const char8& value) noexcept {return char8_object(value);}
#endif
  inline char16_object boxing(const char16& value) noexcept {return char16_object(value);}
  inline char32_object boxing(const char32& value) noexcept {return char32_object(value);}
  inline wchar_object boxing(const wchar& value) noexcept {return wchar_object(value);}
  inline char_object boxing(char& value) noexcept {return char_object(value);}
#if defined(__cpp_lib_char8_t)
  inline char8_object boxing(char8& value) noexcept {return char8_object(value);}
#endif
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
  /// @endcond
}
