/// @file
/// @brief Contains flags_attribute_ keyword.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum_set_attribute"

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
