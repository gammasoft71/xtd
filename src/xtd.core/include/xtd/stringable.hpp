/// @file
/// @brief Contains xtd::stringable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include "stream_insertable.hpp"
#include "iformatable.hpp"
#include "istringable.hpp"
#include "object.hpp"
#include "raw_type.hpp"
#include <concepts>
#if defined(__xtd__cpp_lib_ranges)
#include <ranges>
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/stringable_.hpp
  template<typename value_t>
  concept stringable =
    std::derived_from<xtd::raw_type<value_t>, xtd::object> ||
    std::derived_from<xtd::raw_type<value_t>, xtd::istringable<xtd::raw_type<value_t>>> ||
    std::derived_from<xtd::raw_type<value_t>, xtd::iformatable> ||
    std::derived_from<xtd::raw_type<value_t>, std::exception> ||
    std::is_enum_v<xtd::raw_type<value_t>> ||
    #if defined(__xtd__cpp_lib_ranges)
    std::ranges::range<xtd::raw_type<value_t>> ||
    #endif
    xtd::stream_insertable<value_t>;
}
