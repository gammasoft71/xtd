#pragma once

#include "delegate.hpp"
#include "event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  using event_handler = delegate<void(const event_args&)>;
}
