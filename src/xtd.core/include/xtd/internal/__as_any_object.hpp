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
    auto operator()(const any_object& o) const -> type_t {return as<enum_object<type_t>>(o.value());}
  };
  
  template<class type_t>
  struct __enum_any_object__<type_t, std::false_type> {
    auto operator()(const any_object& o) const -> type_t {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);}
  };
  
  template<class type_t, class bool_t>
  struct __polymorphic_any_object__ {};
  
  template<class type_t>
  struct __polymorphic_any_object__<type_t, std::true_type> {
    auto operator()(const any_object& o) const -> type_t {return as<type_t>(o.value());}
  };
  
  template<class type_t>
  struct __polymorphic_any_object__<type_t, std::false_type> {
    auto operator()(const any_object& o) const -> type_t {return __enum_any_object__<type_t, typename std::is_enum<type_t>::type> {}(o);}
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
  requires (!std::integral<type_t> || std::same_as<type_t, bool>)
  [[nodiscard]] inline auto as(any_object& o) -> type_t {
    if (is<box<type_t>>(o.value())) return as<box<type_t >> (o.value()).value;
    return __polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type> {}(o);
  }

  /// @cond
  template<class type_t>
  requires (std::integral<type_t> && !std::same_as<type_t, bool>)
  [[nodiscard]] inline auto as(any_object& o) -> type_t {
    if (xtd::is<xtd::box_integer<xtd::byte>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::byte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int16>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::int16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int32>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::int32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int64>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::int64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::sbyte>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::sbyte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::slong>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::slong>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint16>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::uint16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint32>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::uint32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint64>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::uint64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::ulong>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::ulong>&>(o.value()).value);
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }

  template<>
  [[nodiscard]] inline auto as<xtd::null_ptr>(any_object& o) -> xtd::null_ptr {
    if (o.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    return xtd::null;
  }
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
  requires (!std::integral<type_t> || std::same_as<type_t, bool>)
  [[nodiscard]] inline auto as(const any_object& o) -> type_t {
    if (is<box<type_t>>(o.value())) return as<box<type_t >> (o.value()).value;
    return __polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type> {}(o);
  }
 
  /// @cond
  template<class type_t>
  requires (std::integral<type_t> && !std::same_as<type_t, bool>)
  [[nodiscard]] inline auto as(const any_object& o) -> type_t {
    if (xtd::is<xtd::box_integer<xtd::byte>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::byte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int16>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::int16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int32>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::int32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::int64>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::int64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::sbyte>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::sbyte>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::slong>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::slong>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint16>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::uint16>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint32>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::uint32>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::uint64>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::uint64>&>(o.value()).value);
    if (xtd::is<xtd::box_integer<xtd::ulong>>(o.value())) return xtd::as<type_t>(static_cast<const xtd::box_integer<xtd::ulong>&>(o.value()).value);
    xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
  }
  
  template<>
  [[nodiscard]] inline auto as<xtd::null_ptr>(const any_object& o) -> xtd::null_ptr {
    if (o.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast);
    return xtd::null;
  }
  /// @endcond

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
  [[nodiscard]] inline auto as<string>(xtd::any_object& value) -> string {
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
  [[nodiscard]] inline auto as<string>(const xtd::any_object& value) -> string {
    return xtd::convert::to_string(value);
  }
}
