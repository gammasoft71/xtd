/// @file
/// @brief Contains xtd::envs mathods and #envs_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "environment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Retrieves all environment variable names and their values from the current process.
  /// @return std::map A dictionary that contains all environment variable names and their values; otherwise, an empty dictionary if no environment variables are found.
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/envs>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned xtd::collections::specialized::string_dictionary.
  [[nodiscard]] inline auto envs() -> xtd::collections::specialized::string_dictionary {return xtd::environment::get_environment_variables();}
  /// @brief Retrieves all environment variable names and their values from the current process, or from the Windows operating system registry key for the current user or local machine.
  /// @param target One of the environment_variable_target values.
  /// @return std::map A dictionary that contains all environment variable names and their values from the source specified by the target parameter; otherwise, an empty dictionary if no environment variables are found.
  /// @exception std::invalid_argument target is not a valid environment_variable_target value.
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/envs>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The names and values for the environment variables are stored as key-value pairs in the returned xtd::collections::specialized::string_dictionary.
  [[nodiscard]] inline auto envs(xtd::environment_variable_target target) -> xtd::collections::specialized::string_dictionary {return xtd::environment::get_environment_variables(target);}
}

/// @brief Retrieves all environment variable names and their values from the current process.
/// @return std::map A dictionary that contains all environment variable names and their values; otherwise, an empty dictionary if no environment variables are found.
/// ```cpp
/// #define envs_
/// ```
/// @par Header
/// ```cpp
/// #include <xtd/envs>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks The names and values for the environment variables are stored as key-value pairs in the returned xtd::collections::specialized::string_dictionary.
#define envs_ xtd::envs()
