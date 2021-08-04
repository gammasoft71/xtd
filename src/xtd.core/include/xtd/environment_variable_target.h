/// @file
/// @brief Contains xtd::environment_variable_target enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the location where an environment variable is stored or retrieved in a set or get operation.
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
  
  inline std::ostream& operator<<(std::ostream& os, environment_variable_target value) {return os << to_string(value, {{environment_variable_target::process, "process"}, {environment_variable_target::user, "user"}, {environment_variable_target::machine, "machine"}});}
  inline std::wostream& operator<<(std::wostream& os, environment_variable_target value) {return os << to_string(value, {{environment_variable_target::process, L"process"}, {environment_variable_target::user, L"user"}, {environment_variable_target::machine, L"machine"}});}
}
