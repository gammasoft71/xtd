/// @file
/// @brief Contains xtd::as method.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  template<class type_t, class bool_t>
  struct __enum_any_object__ {};
  
  template<class type_t>
  struct __enum_any_object__<type_t, std::true_type> {
    type_t operator()(const any_object& o) const {return as<enum_object<type_t>>(o.value());}
  };
  
  template<class type_t>
  struct __enum_any_object__<type_t, std::false_type> {
    type_t operator()(const any_object& o) const {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);}
  };
  
  template<class type_t, class bool_t>
  struct __polymorphic_any_object__ {};
  
  template<class type_t>
  struct __polymorphic_any_object__<type_t, std::true_type> {
    type_t operator()(const any_object& o) const {return as<type_t>(o.value());}
  };
  
  template<class type_t>
  struct __polymorphic_any_object__<type_t, std::false_type> {
    type_t operator()(const any_object& o) const {return __enum_any_object__<type_t, typename std::is_enum<type_t>::type> {}(o);}
  };
  /// @endcond
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::any value = true;
  /// bool result = as<bool>(value);
  /// ```
  template<class type_t>
  inline type_t as(any_object& o) {
    if (is<box<type_t>>(o.value())) return as<box<type_t >> (o.value()).value;
    return __polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type> {}(o);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new bool object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::any value = true;
  /// bool result = as<bool>(value);
  /// ```
  template<class type_t>
  inline type_t as(const any_object& o) {
    if (is<box<type_t>>(o.value())) return as<box<type_t >> (o.value()).value;
    return __polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type> {}(o);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::any_object value = true;
  /// xtd::string result = as<string>(value);
  /// ```
  template<>
  inline string as<string>(xtd::any_object& value) {
    return xtd::convert::to_string(value);
  }
  
  /// @brief Casts a type into another type.
  /// @param value object to convert.
  /// @return A new xtd::ulong object converted from value.
  /// @exception xtd::invalid_cast_exception the parameters is bad cast.
  /// @par Header
  /// ```cpp
  /// #include <xtd/as>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// xtd::any_object value = true;
  /// xtd::string result = as<string>(value);
  /// ```
  template<>
  inline string as<string>(const xtd::any_object& value) {
    return xtd::convert::to_string(value);
  }
}
