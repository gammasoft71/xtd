/// @file
/// @brief Contains xtd::signal_cancel_event_handler event handler.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "event_handler.hpp"
#include "signal_cancel_event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that will handle the signal events of a xtd::environment.
  /// @param e A xtd::signal_cancel_event_args object that contains the event data.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  using signal_cancel_event_handler = xtd::delegate<void(signal_cancel_event_args&)>;
}
