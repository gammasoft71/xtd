/// @file
/// @brief Contains xtd::args mathod and #args_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "environment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Returns a string array containing the command-line arguments for the current process.
  /// @return An array of string where each element contains a command-line argument. The first element is the executable file name, and the following zero or more elements contain the remaining command-line arguments.
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/args>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The first element in the array contains the file name of the executing program. If the file name is not available, the first element is equal to string empty "". The remaining elements contain any additional tokens entered on the command line.
  /// @remarks The program file name can, but is not required to, include path information.
  /// @remarks Command line arguments are delimited by spaces. You can use double quotation marks (") to include spaces within an argument. The single quotation mark ('), however, does not provide this functionality.
  /// @remarks If a double quotation mark follows two or an even number of backslashes, each proceeding backslash pair is replaced with one backslash and the double quotation mark is removed. If a double quotation mark follows an odd number of backslashes, including just one, each preceding pair is replaced with one backslash and the remaining backslash is removed; however, in this case the double quotation mark is not removed.
  /// @remarks The following table shows how command line arguments can be delimited, and assumes MyApp as the current executing application.
  ///
  /// | Input at the command line                    | Resulting command line arguments           |
  /// | -------------------------------------------- | ------------------------------------------ |
  /// | MyApp alpha beta                             | MyApp, alpha, beta                         |
  /// | MyApp "alpha with spaces" "beta with spaces" | MyApp, alpha with spaces, beta with spaces |
  /// | MyApp 'alpha with spaces' beta               | MyApp, 'alpha, with, spaces', beta         |
  /// | MyApp \\\alpha \\\\"beta                     | MyApp, \\\alpha, \\beta                    |
  /// | MyApp \\\\\"alpha \"beta                     | MyApp, \\"alpha, "beta                     |
  /// @remarks To obtain the command line as a single string, use the xtd::environment::command_line method.
  [[nodiscard]] inline auto args() -> xtd::argument_collection {return xtd::environment::get_command_line_args();}
}

/// @brief Returns a string array containing the command-line arguments for the current process.
/// @return An array of string where each element contains a command-line argument. The first element is the executable file name, and the following zero or more elements contain the remaining command-line arguments.
/// ```cpp
/// #define args_
/// ```
/// @par Header
/// ```cpp
/// #include <xtd/args>
/// ```
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks The first element in the array contains the file name of the executing program. If the file name is not available, the first element is equal to string empty "". The remaining elements contain any additional tokens entered on the command line.
/// @remarks The program file name can, but is not required to, include path information.
/// @remarks Command line arguments are delimited by spaces. You can use double quotation marks (") to include spaces within an argument. The single quotation mark ('), however, does not provide this functionality.
/// @remarks If a double quotation mark follows two or an even number of backslashes, each proceeding backslash pair is replaced with one backslash and the double quotation mark is removed. If a double quotation mark follows an odd number of backslashes, including just one, each preceding pair is replaced with one backslash and the remaining backslash is removed; however, in this case the double quotation mark is not removed.
/// @remarks The following table shows how command line arguments can be delimited, and assumes MyApp as the current executing application.
/// | Input at the command line                    | Resulting command line arguments           |
/// | -------------------------------------------- | ------------------------------------------ |
/// | MyApp alpha beta                             | MyApp, alpha, beta                         |
/// | MyApp "alpha with spaces" "beta with spaces" | MyApp, alpha with spaces, beta with spaces |
/// | MyApp 'alpha with spaces' beta               | MyApp, 'alpha, with, spaces', beta         |
/// | MyApp \\\alpha \\\\"beta                     | MyApp, \\\alpha, \\beta                    |
/// | MyApp \\\\\"alpha \"beta                     | MyApp, \\"alpha, "beta                     |
/// @remarks To obtain the command line as a single string, use the xtd::environment::command_line method.
#define args_ xtd::args()
