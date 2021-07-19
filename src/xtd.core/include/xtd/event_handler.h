/// @file
/// @brief Contains xtd::event_handler event handler.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "delegate.h"
#include "event.h"
#include "event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the method that will handle an event that has no event data.
  /// @param sender The source of the event.
  /// @param e An object that contains no event data.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  using event_handler = xtd::delegate<void(object& sender, const event_args& e)>;
}
