/// @file
/// @brief Contains xtd::istringable interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__string_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "generic_stream_output.hpp"
#include "interface.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides a way to represent the current object as a string.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core interfaces
  /// @par Examples
  /// The following exemple shows how to use xtd::istringable interface.
  /// @include istringable.cpp
  /// @remarks Types inheriting from xtd::object should not implement the xtd::istringable interface. For more info, see xtd::object::to_string Method.
  class istringable interface_ {
  public:
    /// @name Public Methods
    
    /// @{
    /// @brief Gets a string that represents the current object.
    /// @return A string that represents the current object.
    virtual xtd::string to_string() const = 0;
    /// @}
  };
}
