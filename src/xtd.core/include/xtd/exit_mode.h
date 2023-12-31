/// @file
/// @brief Contains xtd::exit_mode enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"
#include <cstdlib>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies exit mode for the xtd::environment::program_exit event.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks Each of the above values represents a constant, which represent different exit status of to the program.
  /// @remarks For more information about exit_mode, see <a href="https://en.cppreference.com/w/cpp/utility/program/EXIT_status">EXIT_status</a>.
  enum class exit_mode {
    /// @brief Represent the exit mode when the terminates normally (via xtd::environment::exit or returning from the main function).
    normal = 0,
    /// @brief Represent the exit mode when the terminates quickly (via xtd::environment::quick_exit).
    quick = 1,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::exit_mode> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::exit_mode> {{xtd::exit_mode::normal, "normal"}, {xtd::exit_mode::quick, "quick"}};}
};
/// @endcond
