/// @file
/// @brief Contains xtd::to_string methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#define __XTD_CORE_INTERNAL__
#include "internal/__binary_formatter.hpp"
#include "internal/__boolean_formatter.hpp"
#include "internal/__character_formatter.hpp"
#include "internal/__currency_formatter.hpp"
#include "internal/__date_time_formatter.hpp"
#include "internal/__duration_formatter.hpp"
#include "internal/__iformatable_formatter.hpp"
#include "internal/__floating_point_formatter.hpp"
#include "internal/__natural_formatter.hpp"
#include "internal/__numeric_formatter.hpp"
#include "internal/__format_stringer.hpp"
#undef __XTD_CORE_INTERNAL__
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
/// @endcond
#include "generic_stream_output.hpp"
#include "register_any_stringer.hpp"
#include "types.hpp"
#include "string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class value_t>
  inline xtd::string to_string(const value_t& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const bool& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const sbyte& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const char& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const unsigned char& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const short& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const unsigned short& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const int& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const unsigned int& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const long& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const unsigned long& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const long long& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const unsigned long long& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const float& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const double& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const long double& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const std::chrono::system_clock::time_point& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const std::tm& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class type_t, class period_t>
  inline xtd::string to_string(const std::chrono::duration<type_t, period_t>& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const char8& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const char16& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const char32& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @brief Convert a specified value into a string with specified format and locale.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @param loc An object of class std::locale is an immutable indexed set of immutable facets.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<>
  inline xtd::string to_string(const wchar& value, const xtd::string& fmt, const std::locale& loc);
  
  /// @cond
  xtd::string to_string(const char* value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const char8* value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const char16* value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const char32* value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const wchar* value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const std::string& value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const xtd::string& value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const std::u8string& value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const std::u16string& value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const std::u32string& value, const xtd::string& fmt, const std::locale& loc);
  xtd::string to_string(const std::wstring& value, const xtd::string& fmt, const std::locale& loc);
  /// @endcond
  
  /// @brief Convert a specified value into a string with specified format.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @param value Value to convert.
  /// @param fmt A composite format string.
  /// @remarks for more information about format see @ref FormatPage "Format".
  template<class value_t>
  inline xtd::string to_string(const value_t& value, const xtd::string& fmt);
  
  /// @cond
  inline xtd::string to_string(const char*  value, const xtd::string& fmt);
  
  template<>
  inline xtd::string to_string(const std::partial_ordering& value, const xtd::string& fmt, const std::locale& loc);
  
  template<>
  inline xtd::string to_string(const std::strong_ordering& value, const xtd::string& fmt, const std::locale& loc);
  
  template<>
  inline xtd::string to_string(const std::weak_ordering& value, const xtd::string& fmt, const std::locale& loc);
  
  template<class value_t>
  inline xtd::string to_string(const value_t* value, const xtd::string& fmt, const std::locale& loc);
  
  template<class value_t>
  inline xtd::string to_string(value_t* const value, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t>
  inline xtd::string to_string(const std::shared_ptr<type_t>& value, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t>
  inline xtd::string to_string(const std::unique_ptr<type_t>& value, const xtd::string& fmt, const std::locale& loc);
  
  template<>
  inline xtd::string to_string(const xtd::any& value, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t>
  inline xtd::string to_string(const std::optional<type_t>& value, const xtd::string& fmt, const std::locale& loc);
  
  template<>
  inline xtd::string to_string(const std::nullopt_t& value, const xtd::string& fmt, const std::locale& loc);
  
  template<>
  inline xtd::string to_string(const std::nullptr_t&, const xtd::string& fmt, const std::locale& loc);
  
  template<class type1_t, class type2_t>
  inline xtd::string to_string(const std::pair<type1_t, type2_t>& value, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, unsigned n_t, unsigned last_t>
  struct __xtd_tuple_stringer {
    static xtd::string to_string(const std::string& str, const type_t& value, const xtd::string& fmt, const std::locale& loc);
  };
  
  template<class type_t, unsigned n_t>
  struct __xtd_tuple_stringer<type_t, n_t, n_t> {
    static xtd::string to_string(const std::string& str, const type_t& value, const xtd::string& fmt, const std::locale& loc);
  };
  
  template<class ...types_t>
  inline xtd::string to_string(const std::tuple<types_t ...>& value, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, size_t size>
  inline xtd::string to_string(const std::array<type_t, size>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<size_t size>
  inline xtd::string to_string(const std::bitset<size>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class allocator_t>
  inline xtd::string to_string(const std::deque<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class allocator_t>
  inline xtd::string to_string(const std::forward_list<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t>
  inline xtd::string to_string(const std::initializer_list<type_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class allocator_t>
  inline xtd::string to_string(const std::list<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class container_t>
  inline xtd::string to_string(const std::queue<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class container_t>
  inline xtd::string to_string(const std::priority_queue<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class container_t>
  inline xtd::string to_string(const std::stack<type_t, container_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t>
  inline xtd::string to_string(const std::valarray<type_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class allocator_t>
  inline xtd::string to_string(const std::vector<type_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class value_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::map<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class value_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::multimap<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::multiset<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::set<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class value_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::unordered_map<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class value_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::unordered_multimap<key_t, value_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::unordered_multiset<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class key_t, class compare_t, class allocator_t>
  inline xtd::string to_string(const std::unordered_set<key_t, compare_t, allocator_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t>
  inline xtd::string to_string(type_t value, const std::initializer_list<std::pair<type_t, xtd::string>>& il);
  
  xtd::string to_string(const std::locale& value, const xtd::string& fmt, const std::locale& loc);

  #if defined(__xtd__cpp_lib_ranges)
  //template <std::ranges::range range_t>
  //inline xtd::string to_string(const range_t& values, const xtd::string& fmt, const std::locale& loc);
  
  //template <std::ranges::range range_t>
  //inline xtd::string to_string(const range_t& values, const xtd::string& fmt, const std::locale& loc);
  #endif
  
  template<class type_t>
  inline xtd::string to_string(const xtd::collections::generic::ienumerable<type_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t>
  inline xtd::string to_string(const xtd::collections::generic::helpers::raw_array<type_t>& values, const xtd::string& fmt, const std::locale& loc);
  
  template<class type_t, class string_t>
  inline string_t to_string(type_t value, const std::map<type_t, string_t, std::greater<type_t>>& values);
  
  template<class type_t, class string_t>
  inline string_t to_string(type_t value, const std::map<type_t, string_t>& values);
  /// @endcond
}

#define __XTD_TO_STRING_INTERNAL__
#include "to_string_.hpp"
#undef  __XTD_TO_STRING_INTERNAL__
