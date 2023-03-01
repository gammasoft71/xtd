/// @file
/// @brief Contains xtd::signal enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"
#include <csignal>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Specifies signals that can interrupt the current process.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks Each of the above values represents a constant, which represent different signals sent to the program.
  enum class signal {
    /// @brief Abnormal termination condition, as is e.g. initiated by std::abort().
    abort = SIGABRT,
    /// @brief Erroneous arithmetic operation such as divide by zero.
    floating_point_exception = SIGFPE,
    /// @brief Invalid program image, such as invalid instruction.
    illegal_instruction = SIGILL,
    /// @brief external interrupt, usually initiated by the user.
    interrupt = SIGINT,
    /// @brief Invalid memory access (segmentation fault).
    segmentation_violation = SIGSEGV,
    /// @brief Termination request, sent to the program.
    software_termination = SIGTERM,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::signal> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::signal> {{xtd::signal::abort, "abort"}, {xtd::signal::floating_point_exception, "floating_point_exception"}, {xtd::signal::illegal_instruction, "illegal_instruction"}, {xtd::signal::interrupt, "interrupt"}, {xtd::signal::segmentation_violation, "segmentation_violation"}, {xtd::signal::software_termination, "software_termination"}};}
};
/// @endcond
