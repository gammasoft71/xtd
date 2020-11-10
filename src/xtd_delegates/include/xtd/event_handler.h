#pragma once

#include "delegate.h"
#include "event.h"
#include "event_args.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename type_t>
  using event_handler = delegate<void(type_t, const event_args&)>;
}
