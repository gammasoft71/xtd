#pragma once

#include "delegate.hpp"
#include "event.hpp"
#include "event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename type_t>
  using event_handler = delegate<void(const type_t&, const event_args&)>;
}
