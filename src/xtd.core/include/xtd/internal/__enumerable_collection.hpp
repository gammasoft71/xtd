/// @file
/// @brief Contains __opaque_xtd_linq_enumerable_collection__ <type_t> struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../collections/generic/enumerator.hpp"
#include <vector>

/// @cond
namespace xtd::linq {
  class enumerable;
};

template<typename type_t>
struct __opaque_xtd_linq_enumerable_collection__ : xtd::collections::generic::ienumerable<type_t> {
  xtd::collections::generic::enumerator<type_t> get_enumerator() const override {
    return xtd::collections::generic::enumerator<>::create(items);
  }

private:
  friend class xtd::linq::enumerable;
  __opaque_xtd_linq_enumerable_collection__() = default;
  std::vector<type_t> items;
};
/// @endcond
