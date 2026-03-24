/// @file
/// @brief Contains xtd::stream_insertable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "is_stream_insertable.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++20 concept, the documentation for this concept is declared in xtd/stream_insertable_.hpp
  template<typename value_t>
  concept stream_insertable = xtd::is_stream_insertable_v<value_t>;
}
