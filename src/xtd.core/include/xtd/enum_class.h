/// @file
/// @brief Contains enum_class_ and enum_class_ut_ keywords.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum_attribute.h"
#include "enum_collection.h"
#include "enum_object.h"
#include "enum_register.h"
#include "enum_set_attribute.h"
#include "flags_attribute.h"

/// @brief Provides the registration struct for enum class with specified underlying type.
/// @par Header
/// @code #include <xtd/enum> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_class_type The name of the enum class.
/// @param underlying_type The underying type.
/// @param ... The enumeration list.
/// @remarks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_class_ut_ helper.
/// @include enum_class_ut.cpp
#define enum_class_ut_(namespace_name, enum_class_t, underlying_t, ...) \
  namespace namespace_name {enum class enum_class_t : underlying_t { __VA_ARGS__ };} \
  __enum_introspection__(namespace_name, enum_class_t, underlying_t, __VA_ARGS__) \
  template<> struct xtd::enum_register<namespace_name::enum_class_t> {explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_class_t>(#__VA_ARGS__);}}

/// @brief Provides the registration struct for enum class.
/// @par Header
/// @code #include <xtd/enum> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core system keywords
/// @param namespace_name The name of the the namespace. Empty if no namespace.
/// @param enum_class_type The name of the enum class.
/// @param ... The enumeration list.
/// @remarks This helper is created to facilitate to set the xtd::enum_register with the enumeration identifiers.
/// @warning The helper has one limitiation :
///  * The enumeration's cannot be in a class or struct. The enum must be in the global namespace or in a namespace hierarchy. If the enumeration is in a class or struct, add operators manually and use xtd::enum_register to register the enumeration identifiers.
/// @par Examples
/// The following code show how to use #enum_ helper.
/// @include enum_class.cpp
#define enum_class_(namespace_name, enum_class_t, ...) \
  enum_class_ut_(namespace_name, enum_class_t, xtd::int32, __VA_ARGS__)
