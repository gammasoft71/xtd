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
#include <string>

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
  inline std::string to_string(const value_t& value, const std::string& fmt, const std::locale& loc) {return __to_string_polymorphic(value, fmt, loc, std::is_polymorphic<value_t>());}

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
  inline std::string to_string(const bool& value, const std::string& fmt, const std::locale& loc) {return __boolean_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const sbyte& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const char& value, const std::string& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const unsigned char& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const short& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const unsigned short& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const int& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const unsigned int& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const unsigned long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const long long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const unsigned long long& value, const std::string& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const float& value, const std::string& fmt, const std::locale& loc) {return __floating_point_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const double& value, const std::string& fmt, const std::locale& loc) {return __floating_point_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const long double& value, const std::string& fmt, const std::locale& loc) {return __floating_point_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const std::chrono::system_clock::time_point& value, const std::string& fmt, const std::locale& loc) {return __date_time_formatter(fmt, std::chrono::system_clock::to_time_t(value), std::chrono::duration_cast<std::chrono::nanoseconds>(value.time_since_epoch()).count() % 1000000000, loc);}
  
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
  inline std::string to_string(const std::tm& value, const std::string& fmt, const std::locale& loc) {return __date_time_formatter(fmt, value, 0, loc);}
  
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
  template<typename type_t, typename Period>
  inline std::string to_string(const std::chrono::duration<type_t, Period>& value, const std::string& fmt, const std::locale& loc) {return __duration_formatter(fmt, value, loc);}

#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::string to_string(const char8& value, const std::string& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
#endif
  
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
  inline std::string to_string(const char16& value, const std::string& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const char32& value, const std::string& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
  
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
  inline std::string to_string(const wchar& value, const std::string& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
  
  /// @cond
  std::string to_string(const char* value, const std::string& fmt, const std::locale& loc);
#if defined(__xtd__cpp_lib_char8_t)
  std::string to_string(const char8* value, const std::string& fmt, const std::locale& loc);
#endif
  std::string to_string(const char16* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const char32* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const wchar* value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::string& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const xtd::string& value, const std::string& fmt, const std::locale& loc);
#if defined(__xtd__cpp_lib_char8_t)
  std::string to_string(const std::u8string& value, const std::string& fmt, const std::locale& loc);
#endif
  std::string to_string(const std::u16string& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::u32string& value, const std::string& fmt, const std::locale& loc);
  std::string to_string(const std::wstring& value, const std::string& fmt, const std::locale& loc);
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
  inline std::string to_string(const value_t& value, const std::string& fmt) {return to_string(value, fmt, std::locale());}
  
  /// @cond
  inline std::string to_string(const char*  value, const std::string& fmt) {return to_string(value, fmt, std::locale());}

#if defined(__xtd__cpp_lib_three_way_comparison)
  template<>
  inline std::string to_string(const std::partial_ordering& value, const std::string& fmt, const std::locale& loc) {
    if (value == std::partial_ordering::less) return "less";
    if (value == std::partial_ordering::greater) return "greater";
    return "equivalent";
  }

  template<>
  inline std::string to_string(const std::strong_ordering& value, const std::string& fmt, const std::locale& loc) {
    if (value == std::strong_ordering::less) return "less";
    if (value == std::strong_ordering::greater) return "greater";
    return "equivalent";
  }

  template<>
  inline std::string to_string(const std::weak_ordering& value, const std::string& fmt, const std::locale& loc) {
    if (value == std::weak_ordering::less) return "less";
    if (value == std::weak_ordering::greater) return "greater";
    return "equivalent";
  }
#endif

  template<class value_t>
  inline std::string to_string(const value_t* value, const std::string& fmt, const std::locale& loc) {
    if (!value) return "(null)";
    return __numeric_formatter(fmt, reinterpret_cast<intptr>(value), loc);
  }
  
  template<class value_t>
  inline std::string to_string(value_t* const value, const std::string& fmt, const std::locale& loc) {
    if (!value) return "(null)";
    return __numeric_formatter(fmt, reinterpret_cast<intptr>(value), loc);
  }
  
  template<class type_t>
  inline std::string to_string(const std::shared_ptr<type_t>& value, const std::string& fmt, const std::locale& loc) {
    if (!value) return "(null)";
    return __numeric_formatter(fmt, reinterpret_cast<intptr>(value.get()), loc);
  }
  
  template<class type_t>
  inline std::string to_string(const std::unique_ptr<type_t>& value, const std::string& fmt, const std::locale& loc) {
    if (!value) return "(null)";
    return __numeric_formatter(fmt, reinterpret_cast<intptr>(value.get()), loc);
  }

  template<>
  inline std::string to_string(const std::any& value, const std::string& fmt, const std::locale& loc) {
    auto iterator = __any_stringer__.find(std::type_index(value.type()));
    return iterator != __any_stringer__.cend() ? xtd::to_string(iterator->second(value), fmt, loc) : "(unregistered)";
  }
  
  template<class type_t>
  inline std::string to_string(const std::optional<type_t>& value, const std::string& fmt, const std::locale& loc) {return !value.has_value() ? "(null)" : std::string {"("} + to_string(value.value(), fmt, loc) + std::string {")"};}

  template<>
  inline std::string to_string(const std::nullopt_t& value, const std::string& fmt, const std::locale& loc) {return "(null)";}
  
  template<>
  inline std::string to_string(const std::nullptr_t&, const std::string& fmt, const std::locale& loc) {return "null";}

  template<typename type1_t, typename type2_t>
  inline std::string to_string(const std::pair<type1_t, type2_t>& value, const std::string& fmt, const std::locale& loc) {
    return std::string {"("} + to_string(value.first, fmt, loc) + std::string {", "} + to_string(value.second, fmt, loc) + std::string {")"};
  }
  
  template<typename type_t, unsigned n_t, unsigned last_t>
  struct __xtd_tuple_stringer {
    static std::string to_string(const std::string& str, const type_t& value, const std::string& fmt, const std::locale& loc) {return __xtd_tuple_stringer<type_t, n_t + 1, last_t >::to_string(str + xtd::to_string(std::get<n_t>(value), fmt, loc) + ", ", value, fmt, loc);}
  };
  
  template<typename type_t, unsigned n_t>
  struct __xtd_tuple_stringer<type_t, n_t, n_t> {
    static std::string to_string(const std::string& str, const type_t& value, const std::string& fmt, const std::locale& loc) {return str + xtd::to_string(std::get<n_t>(value), fmt, loc);}
  };

  template<typename ... types_t>
  inline std::string to_string(const std::tuple<types_t ...>& value, const std::string& fmt, const std::locale& loc) {return __xtd_tuple_stringer<std::tuple<types_t ...>, 0, sizeof...(types_t) - 1 >::to_string(std::string {"("}, value, fmt, loc) + ")";}

  template<typename iterator_t>
  inline std::string __xtd_iterator_to_string(const std::string& str, iterator_t iterator, const iterator_t& begin, const iterator_t& end, const std::string& fmt, const std::locale& loc) {
    if (iterator == end) return str;
    auto new_str = str + (iterator == begin ? std::string {} : std::string {", "}) + xtd::to_string(*iterator, fmt, loc);
    return __xtd_iterator_to_string(new_str, ++iterator, begin, end, fmt, loc);
  }

  template<typename iterator_t>
  inline std::string __xtd_sequence_container_to_string(const iterator_t& begin, const iterator_t& end, const std::string& fmt, const std::locale& loc) {return __xtd_iterator_to_string("[", begin, begin, end, fmt, loc) + "]";}
  
  template<typename type_t, size_t size>
  inline std::string to_string(const std::array<type_t, size>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<class type_t, class allocator_t>
  inline std::string to_string(const std::deque<type_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<class type_t, class allocator_t>
  inline std::string to_string(const std::forward_list<type_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<class type_t>
  inline std::string to_string(const std::initializer_list<type_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<class type_t, class allocator_t>
  inline std::string to_string(const std::list<type_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<class type_t>
  inline std::string to_string(const std::valarray<type_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(std::begin(values), std::end(values), fmt, loc);}

  template<class type_t, class allocator_t>
  inline std::string to_string(const std::vector<type_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<typename iterator_t>
  inline std::string __xtd_associative_container_to_string(const iterator_t& begin, const iterator_t& end, const std::string& fmt, const std::locale& loc) {return __xtd_iterator_to_string("{", begin, begin, end, fmt, loc) + "}";}

  template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::map<key_t, value_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}
  
  template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::multimap<key_t, value_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}
  
  template<typename key_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::multiset<key_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}
  
  template<typename key_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::set<key_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::unordered_map<key_t, value_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}
  
  template<typename key_t, typename value_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::unordered_multimap<key_t, value_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}
  
  template<typename key_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::unordered_multiset<key_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}
  
  template<typename key_t, typename compare_t, typename allocator_t>
  inline std::string to_string(const std::unordered_set<key_t, compare_t, allocator_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_associative_container_to_string(values.begin(), values.end(), fmt, loc);}

  template<class type_t>
  inline std::string to_string(const xtd::collections::generic::ienumerable<type_t>& values, const std::string& fmt, const std::locale& loc) {return __xtd_sequence_container_to_string(values.begin(), values.end(), fmt, loc);}
  /// @endcond

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
  inline std::wstring to_string(const value_t& value, const std::wstring& fmt, const std::locale& loc) {return __to_string_polymorphic(value, fmt, loc, std::is_polymorphic<value_t>());}
  
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
  inline std::wstring to_string(const bool& value, const std::wstring& fmt, const std::locale& loc) {return __boolean_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const sbyte& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const char& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const unsigned char& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const short& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const unsigned short& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const int& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const unsigned int& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const unsigned long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const long long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const unsigned long long& value, const std::wstring& fmt, const std::locale& loc) {return __numeric_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const float& value, const std::wstring& fmt, const std::locale& loc) {return __floating_point_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const double& value, const std::wstring& fmt, const std::locale& loc) {return __floating_point_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const long double& value, const std::wstring& fmt, const std::locale& loc) {return __floating_point_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const std::chrono::system_clock::time_point& value, const std::wstring& fmt, const std::locale& loc) {return __date_time_formatter(fmt, std::chrono::system_clock::to_time_t(value), std::chrono::duration_cast<std::chrono::milliseconds>(value.time_since_epoch()).count()  % 1000000000, loc);}
  
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
  inline std::wstring to_string(const std::tm& value, const std::wstring& fmt, const std::locale& loc) {return __date_time_formatter(fmt, value, 0, loc);}
  
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
  template<typename type_t, typename Period>
  inline std::wstring to_string(const std::chrono::duration<type_t, Period>& value, const std::wstring& fmt, const std::locale& loc) {return __duration_formatter(fmt, value, loc);}
 
  /// @cond
  template<typename char_t, typename value_t>
  inline std::basic_string<char_t> __string_formatter(const std::basic_string<char_t>& fmt, value_t value, const std::locale& loc) {
    return __format_stringer<char_t>(value);
  }
  /// @endcond

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
  inline std::wstring to_string(const std::wstring& value, const std::wstring& fmt, const std::locale& loc) {return __string_formatter(fmt, value, loc);}
  
#if defined(__xtd__cpp_lib_char8_t)
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
  inline std::wstring to_string(const char8& value, const std::wstring& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
#endif
  
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
  inline std::wstring to_string(const char16& value, const std::wstring& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const char32& value, const std::wstring& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
  
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
  inline std::wstring to_string(const wchar& value, const std::wstring& fmt, const std::locale& loc) {return __character_formatter(fmt, value, loc);}
  
  /// @cond
  inline std::wstring to_string(const wchar*  value, const std::wstring& fmt, const std::locale& loc) {return __string_formatter(fmt, value, loc);}
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
  inline std::wstring to_string(const value_t& value, const std::wstring& fmt) {return to_string(value, fmt, std::locale());}
  
  /// @cond
  inline std::wstring to_string(const wchar*  value, const std::wstring& fmt) {return to_string(value, fmt, std::locale());}
  /// @endcond
}

