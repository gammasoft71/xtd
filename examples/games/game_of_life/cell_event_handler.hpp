
#pragma once
#include <xtd/delegate.hpp>
#include "cell_event_args.hpp"

namespace game_of_life {
  template<typename type_t>
  using cell_event_handler = xtd::delegate<void(const type_t& sender, const cell_event_args& e)>;
}
