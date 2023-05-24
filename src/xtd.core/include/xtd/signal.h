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
  /// @remarks For more information about signal, see <a href="https://en.cppreference.com/w/cpp/utility/program/signal">std::signal</a>.
  enum class signal {
    /// @brief Abnormal termination triggered by abort call. Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGABRT</a>.
    abnormal_termination = SIGABRT,
    /// @brief Erroneous arithmetic operation such as divide by zero. Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGFPE</a>.
    floating_point_exception = SIGFPE,
    /// @brief Invalid program image, such as invalid instruction. Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGILL</a>.
    illegal_instruction = SIGILL,
    /// @brief external interrupt, usually initiated by the user. Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGINT</a>.
    interrupt = SIGINT,
    /// @brief Invalid memory access (segmentation fault). Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGSEGV</a>.
    segmentation_violation = SIGSEGV,
    /// @brief Termination request, sent to the program. Is equal to <a href="https://en.cppreference.com/w/cpp/utility/program/signal">SIGTERM</a>.
    software_termination = SIGTERM,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::signal> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::signal> {{xtd::signal::abnormal_termination, "abnormal_termination"}, {xtd::signal::floating_point_exception, "floating_point_exception"}, {xtd::signal::illegal_instruction, "illegal_instruction"}, {xtd::signal::interrupt, "interrupt"}, {xtd::signal::segmentation_violation, "segmentation_violation"}, {xtd::signal::software_termination, "software_termination"}};}
};
/// @endcond
