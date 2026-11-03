/// @file
/// @brief Contains xtd::env mathods and #env_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "environment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {

  /// @brief Retrieves the value of an environment variable from the current process.
  /// @param variable The name of the environment variable.
  /// @return xtd::string The value of the environment variable specified by variable, or empty "" if the environment variable is not found.
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/env>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The get_environment_variable(xtd::string) method retrieves an environment variable from the environment block of the current process only. It is equivalent to calling the xtd::environment::get_environment_variable(xtd::string, xtd::environment_variable_target) method with a target value of xtd::environment_variable_target::process.
  /// @remarks To retrieve all environment variables along with their values, call the xtd::environment::get_environment_variables method.
  /// @remarks Environment variable names are case-sensitive on Linux and macOS but are not case-sensitive on Windows.
  [[nodiscard]] inline auto env(const xtd::string& variable) -> xtd::string {return xtd::environment::get_environment_variable(variable);}
  /// @brief Retrieves the value of an environment variable from the current process or from the Windows operating system registry key for the current user or local machine.
  /// @param variable The name of an environment variable.
  /// @param target One of the xtd::environment_variable_target values.
  /// @exception std::invalid_argument target is not a valid environment_variable_target value.
  /// @return xtd::string The value of the environment variable specified by the variable and target parameters, or empty "" if the environment variable is not found.
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/env>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks To retrieve all environment variables along with their values, call the xtd::environment::get_environment_variables method.
  /// @remarks Environment variable names are case-sensitive on Linux and macOS but are not case-sensitive on Windows.
  [[nodiscard]] inline auto env(const xtd::string& variable, xtd::environment_variable_target target) -> xtd::string {return xtd::environment::get_environment_variable(variable, target);}
}

/// @brief Retrieves the value of an environment variable from the current process or from the Windows operating system registry key for the current user or local machine.
/// @param variable The name of an environment variable.
/// @param target One of the xtd::environment_variable_target values. Optional by default if not specified is xtd:environment_variable_target::process.
/// @exception std::invalid_argument target is not a valid environment_variable_target value.
/// @return xtd::string The value of the environment variable specified by the variable and target parameters, or empty "" if the environment variable is not found.
/// ```cpp
/// #define env_
/// ```
/// @par Header
/// ```cpp
/// #include <xtd/env>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks To retrieve all environment variables along with their values, call the xtd::environment::get_environment_variables method.
/// @remarks Environment variable names are case-sensitive on Linux and macOS but are not case-sensitive on Windows.
#define env_(...) xtd::env(__VA_ARGS__)
