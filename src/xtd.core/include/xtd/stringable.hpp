/// @file
/// @brief Contains xtd::stringable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "stream_insertable.hpp"
#include "iformatable.hpp"
#include "istringable.hpp"
#include "iterable.hpp"
#include "object.hpp"
#include "raw_type.hpp"
#include "textual.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/stringable_.hpp
  template<typename value_t>
  concept stringable =
    std::derived_from<xtd::raw_type<value_t>, xtd::object> ||
    std::derived_from<xtd::raw_type<value_t>, xtd::istringable<xtd::raw_type<value_t>>> ||
    std::derived_from<xtd::raw_type<value_t>, xtd::iformatable> ||
    requires(const xtd::raw_type<value_t>& value) {{value.to_string()} -> xtd::textual;} ||
    std::derived_from<xtd::raw_type<value_t>, std::exception> ||
    std::is_enum_v<xtd::raw_type<value_t>> ||
    xtd::iterable<xtd::raw_type<value_t>> ||
    xtd::stream_insertable<value_t>;
}
