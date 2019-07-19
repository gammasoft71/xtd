#pragma once

#include "delegate.hpp"
#include "event.hpp"
#include "event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename Type>
  using event_handler = delegate<void(const Type&, const event_args&)>;
}
