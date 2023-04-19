/// @file
/// @brief Contains xtd::enum_register.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "enum_attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the set attribute struct for enumerations.
  /// @code
  /// template<typename enum_t>
  /// struct enum_set_attribute
  /// @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The overloading of this operator is necessary for enum classes to be recognized as having a flags attribute to be properly handled by xtd::ustring::format().
  /// @remarks For more information about enumeration, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/enum_class">enum class</a> guide.
  /// @remarks When an enumeration is registered, we can display its name instead of its value, we can format it and parse it.
  /// @remarks See <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/enumeration_format_strings">Enumeration Format Strings</a>. For more information about formatting in general, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/overview">Formatting Types</a>.
  /// @par Examples
  /// The following code show how to use xtd::enum_set_attribute operator.
  /// @include format_enum_class_flags_without_helpers.cpp
  template<typename enum_t>
  struct enum_set_attribute {
    /// Allows to set attribute to an enumeration that can be used by xtd::enum_object.
    /// @return One of xtd::enum_attribute values.
    /// @remarks To set attribute to an enumeration just override xtd::enum_set_attribute.
    /// @par Examples
    /// The following code show how to set attribute to the value_flags enum class.
    /// @code
    /// enum class value_flags {
    ///   value_none = 0,
    ///   value_one = 0b1,
    ///   value_two = 0b10,
    ///   value_three = 0b100,
    /// };
    ///
    /// template<>
    /// xtd::enum_set_attribute<value_flags> {
    ///   explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
    /// };
    /// @endcode
    explicit operator auto() const noexcept {return xtd::enum_attribute::standard;}
  };
}

/// @brief Provides the set attribute struct for enumerations helper.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_type The name of the enum flags.
/// @remaks This helper is created to facilitate to set the xtd::enum_set_attribute with the xtd::enum_attribute::flags atribute and the implementation of the following operators for enum flags:
/// | Operator | Name                   |
/// | -------- | ---------------------- |
/// | ^=       | Bitwise XOR assignment |
/// | &=       | Bitwise AND assignment |
/// | \|=      | Bitwise OR assignment  |
/// | +=       | Addition assignment    |
/// | -=       | Subtraction assignment |
/// | ^        | Bitwise XOR            |
/// | &        | Bitwise AND            |
/// | \|       | Bitwise OR             |
/// | +        | Addition               |
/// | -        | Subtraction            |
/// | ~        | Bitwise NOT            |
/// @warning The helper as one limitiation :
///  * The enum's flags cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enum flags is in a class or struct, add operators manually and use xtd::enum_set_attribute to register the xtd::enum_attribute::flags attribute.
/// @par Examples
/// The following code show how to use #flags_attribute_ helper.
/// @include format_enum_class_flags.cpp
#define flags_attribute_(namespace_name, enum_type) \
  namespace namespace_name { \
    [[maybe_unused]] inline enum_type& operator ^=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) ^ static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator &=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) & static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator |=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) | static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator +=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) + static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type& operator -=(enum_type& lhs, enum_type rhs) {lhs = static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) - static_cast<std::underlying_type<enum_type>::type>(rhs)); return lhs;} \
    [[maybe_unused]] inline enum_type operator ^(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) ^ static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator &(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) & static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator |(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) | static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator +(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) + static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator -(enum_type lhs, enum_type rhs) {return static_cast<enum_type>(static_cast<std::underlying_type<enum_type>::type>(lhs) - static_cast<std::underlying_type<enum_type>::type>(rhs));} \
    [[maybe_unused]] inline enum_type operator ~(enum_type lhs) {return static_cast<enum_type>(~static_cast<std::underlying_type<enum_type>::type>(lhs));} \
  }\
  template<> struct xtd::enum_set_attribute<namespace_name::enum_type> {explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}}
