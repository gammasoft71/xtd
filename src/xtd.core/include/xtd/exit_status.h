/// @file
/// @brief Contains xtd::exit_status enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"
#include <cstdlib>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies exit status for the xtd::environment::exit method.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks Each of the above values represents a constant, which represent different exit status of to the program.
  /// @remarks For more information about exit_status, see <a href="https://en.cppreference.com/w/cpp/utility/program/EXIT_status">EXIT_status</a>.
  enum class exit_status {
    /// @brief Successful execution of a program. Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/EXIT_status">EXIT_SUCCESS</a>.
    success = EXIT_SUCCESS,
    /// @brief Unsuccessful execution of a program. Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/EXIT_status">EXIT_FAILURE</a>.
    failure = EXIT_FAILURE,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::exit_status> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::exit_status> {{xtd::exit_status::success, "success"}, {xtd::exit_status::failure, "failure"}};}
};
/// @endcond
