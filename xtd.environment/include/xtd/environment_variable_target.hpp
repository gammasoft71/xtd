#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies the location where an environment variable is stored or retrieved in a set or get operation.
  enum class environment_variable_target {
    /// @brief The environment variable is stored or retrieved from the environment block associated with the current process.
    process = 0,
    /// @brief The environment variable is stored or retrieved from the HKEY_CURRENT_USER\Environment key in the Windows operating system registry.
    user,
    /// @brief The environment variable is stored or retrieved from the HKEY_LOCAL_MACHINE\System\CurrentControlSet\Control\Session Manager\Environment key in the Windows operating system registry.
    machine = 2,
  };
}
