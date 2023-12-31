/// @file
/// @brief Contains xtd::environment_variable_target enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the location where an environment variable is stored or retrieved in a set or get operation.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core utilities
  enum class environment_variable_target {
    /// @brief The environment variable is stored or retrieved from the environment block associated with the current process.
    process = 0,
    /// @brief The environment variable is stored or retrieved from the HKEY_CURRENT_USER\Environment key in the Windows operating system registry.
    user = 1,
    /// @brief The environment variable is stored or retrieved from the HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment key in the Windows operating system registry.
    machine = 2,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::environment_variable_target> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::environment_variable_target> {{xtd::environment_variable_target::process, "process"}, {xtd::environment_variable_target::user, "user"}, {xtd::environment_variable_target::machine, "machine"}};}
};
/// @endcond
