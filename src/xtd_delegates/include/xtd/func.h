#pragma once

#include "delegate.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename result_t, typename... arguments_t>
  using func = delegate<result_t(arguments_t...)>;
}
