#pragma once

#include "delegate.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename type_t>
  using predicate = delegate<bool(type_t)>;
}
