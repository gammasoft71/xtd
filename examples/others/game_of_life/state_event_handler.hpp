
#pragma once
#include <xtd/delegate.hpp>
#include "state_event_args.hpp"

namespace game_of_life {
  template<typename type_t>
  using state_event_handler = xtd::delegate<void(const type_t& sender, const state_event_args& e)>;
}
