/// @file
/// @brief Contains xtd::enum_register.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
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
  /// @remarks For more information about enumeration, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/enum_class.md">enum class</a> guide.
  /// @remarks When an enumeration is registered, we can display its name instead of its value, we can format it and parse it.
  /// @remarks See <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_enumeration_format_strings.md">Enumeration Format Strings</a>. For more information about formatting in general, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/format_overview.md">Formatting Types</a>.
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
    ///   explicit operator auto() const {return xtd::enum_attribute::flags;}
    /// };
    /// @endcode
    explicit operator auto() const {return xtd::enum_attribute::standard;}
  };
}
