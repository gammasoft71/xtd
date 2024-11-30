/// @file
/// @brief Contains xtd::enum_register.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum_collection.hpp"
#include "types.hpp"
#define __XTD_CORE_INTERNAL__
#include "internal/__enum_introspection.hpp"
#include "internal/__enum_definition_to_enum_collection.hpp"
#undef __XTD_CORE_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the registration struct for enumerations.
  /// ```cpp
  /// template<typename enum_t>
  /// struct enum_register
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/enum_register>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The overloading of this operator is necessary for enum classes to be recognized by xtd::string::format().
  /// @remarks For more information about enumeration, see [enum class](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/enum_class) guide.
  /// @remarks When an enumeration is registered, we can display its name instead of its value, we can format it and parse it.
  /// @remarks See [Enumeration Format Strings](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/enumeration_format_strings). For more information about formatting in general, see [Formatting Types](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Format%20number%20dates%20other%20types/overview).
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
    /// ```cpp
    /// enum class values {
    ///   value_one,
    ///   value_two
    /// };
    ///
    /// template<>
    /// xtd::enum_register<values> {
    ///   explicit operator auto() const noexcept {return xtd::enum_collection<values> {{values::value_one, "value_one"}, {values::value_two, "value_two"}};}
    /// };
    /// ```
    explicit operator auto() const noexcept {return xtd::enum_collection<enum_t> {};}
  };
}
