#pragma once

#include "delegate.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  template<typename type_t>
  using predicate = delegate<bool(type_t)>;
}
