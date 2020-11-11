
#pragma once
#include <xtd/delegate.h>
#include "cell_event_args.h"

namespace game_of_life {
  template<typename type_t>
  using cell_event_handler = xtd::delegate<void(type_t& sender, const cell_event_args& e)>;
}
