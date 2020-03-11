#pragma once

#include "delegate.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename... arguments_t>
  using action = delegate <void(arguments_t...)>;
}
