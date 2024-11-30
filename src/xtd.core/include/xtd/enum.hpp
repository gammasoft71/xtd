/// @file
/// @brief Contains enum_ and enum_ut_ keywords.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum_attribute.hpp"
#include "enum_collection.hpp"
#include "enum_object.hpp"
#include "enum_register.hpp"
#include "enum_set_attribute.hpp"
#include "flags_attribute.hpp"

/// @brief Provides the registration struct for enum with specified underlying type.
/// @par Header
/// ```cpp
/// #include <xtd/enum>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_type The name of the enum.
/// @param underlying_type The underying type.
/// @param ... The enumeration list.
/// @remarks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_ut_ helper.
/// @include enum_ut.cpp
#define enum_ut_(namespace_name, enum_t, underlying_t, ...) \
  namespace namespace_name {enum enum_t : underlying_t {__VA_ARGS__};} \
  __enum_introspection__(namespace_name, enum_t, underlying_t, __VA_ARGS__) \
  template<> struct xtd::enum_register<namespace_name::enum_t> {explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_t>(#__VA_ARGS__);}}

/// @brief Provides the registration struct for enum.
/// @par Header
/// ```cpp
/// #include <xtd/enum>
/// ```
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_type The name of the enum.
/// @param ... The enumeration list.
/// @remarks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_ helper.
/// @include enum.cpp
#define enum_(namespace_name, enum_t, ...) \
  enum_ut_(namespace_name, enum_t, xtd::int32, __VA_ARGS__)

