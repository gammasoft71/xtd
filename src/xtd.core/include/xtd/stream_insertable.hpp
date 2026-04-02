/// @file
/// @brief Contains xtd::stream_insertable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "raw_type.hpp"
#include <concepts>
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/stream_insertable_.hpp
  template<typename value_t>
  concept stream_insertable = requires(std::ostream& os, value_t&& v) {os << std::forward<value_t>(v);};
}
