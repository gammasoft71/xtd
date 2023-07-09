/// @file
/// @brief Contains xtd::boxing methods.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  inline const object& boxing(const object& value) noexcept {return value;}
  inline ustring boxing(const char* value) noexcept {return ustring(value);}
  inline ustring boxing(const char8* value) noexcept {return ustring(value);}
  inline ustring boxing(const char16* value) noexcept {return ustring(value);}
  inline ustring boxing(const char32* value) noexcept {return ustring(value);}
  inline ustring boxing(const wchar* value) noexcept {return ustring(value);}
  /// @endcond
  
  /// @brief Allows to box an object
  /// @param value Value used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t>
  inline auto boxing(const type_t& value) noexcept {return typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type(value);}
  /// @brief Allows to box an object
  /// @param ...args  Params used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t, typename ...args_t>
  inline box<type_t> boxing(args_t&& ...args) noexcept {return box<type_t>(args...);}
}
