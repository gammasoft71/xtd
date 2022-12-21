/// @file
/// @brief Contains xtd::enum_register.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "enum_collection.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the registration struct for enumerations.
  /// @code
  /// template<typename enum_t>
  /// struct enum_register
  /// @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The overloading of this operator is necessary for enum classes to be recognized by xtd::ustring::format().
  /// @remarks For more information about enumeration, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/enum_class.md">enum class</a> guide.
  /// @remarks When an enumeration is registered, we can display its name instead of its value, we can format it and parse it.
  /// @remarks See <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_enumeration_format_strings.md">Enumeration Format Strings</a>. For more information about formatting in general, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_overview.md">Formatting Types</a>.
  /// @par Examples
  /// The following code show how to use xtd::enum_register operator for an enum.
  /// @include enum_class_without_helper.cpp
  /// The following code show how to use xtd::enum_register operator for an enum flags.
  /// @include enum_class_flags_without_helpers.cpp
  template<typename enum_t>
  struct enum_register {
    /// Allows to register an enumeration that can be used by xtd::enum_object.
    /// @return An xtd::enum_collection collection that represent enumeration.
    /// @remarks To register an enumeration just override xtd::enum_register.
    /// @par Examples
    /// The following code show how to register the values enum class.
    /// @code
    /// enum class values {
    ///   value_one,
    ///   value_two
    /// };
    ///
    /// template<>
    /// xtd::enum_register<values> {
    ///   explicit operator auto() const noexcept {return xtd::enum_collection<values> {{values::value_one, "value_one"}, {values::value_two, "value_two"}};}
    /// };
    /// @endcode
    explicit operator auto() const noexcept {return xtd::enum_collection<enum_t> {};}
  };
}

#define enum_ut_(namespace_name, enum_type, underlying_type, ...) \
  namespace namespace_name { enum enum_type : underlying_type {__VA_ARGS__}; } \
    template<> struct xtd::enum_register<namespace_name::enum_type> { \
    explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_type>(#__VA_ARGS__);} \
  }

#define enum_class_ut_(namespace_name, enum_class_type, underlying_type, ...) \
  namespace namespace_name { enum class enum_class_type : underlying_type { __VA_ARGS__ }; } \
    template<> struct xtd::enum_register<namespace_name::enum_class_type> { \
    explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_class_type>(#__VA_ARGS__);} \
  }

#define enum_struct_ut_(namespace_name, enum_struct_type, underlying_type, ...) \
  namespace namespace_name { enum struct enum_struct_type : underlying_type { __VA_ARGS__ }; } \
    template<> struct xtd::enum_register<namespace_name::enum_struct_type> { \
    explicit operator auto() const {return __enum_definition_to_enum_collection__<namespace_name::enum_struct_type>(#__VA_ARGS__);} \
}

#define enum_(namespace_name, enum_type, ...) \
  enum_ut_(namespace_name, enum_type, int32, __VA_ARGS__)

#define enum_class_(namespace_name, enum_class_type, ...) \
  enum_class_ut_(namespace_name, enum_class_type, int32, __VA_ARGS__)

#define enum_struct_(namespace_name, enum_struct_type, ...) \
  @enum_struct_ut_(namespace_name, enum_struct_type, int32, __VA_ARGS__)
