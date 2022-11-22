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
  /// @par Examples
  /// The following code show how to use xtd::enum_set_attribute operator.
  /// @include format_enum_class_flags_without_helpers.cpp
  template<typename enum_t>
  struct enum_set_attribute {
    explicit operator auto() const {return xtd::enum_attribute::standard;}
  };
}
