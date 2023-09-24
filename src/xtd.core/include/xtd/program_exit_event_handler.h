/// @file
/// @brief Contains xtd::program_exit_event_handler event handler.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "event_handler"
#include "program_exit_event_args"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that will handle the program exit events of a xtd::environment.
  /// @param e A xtd::program_exit_event_args object that contains the exit data.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  using program_exit_event_handler = xtd::delegate<void(const program_exit_event_args&)>;
}
