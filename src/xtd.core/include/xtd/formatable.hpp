/// @file
/// @brief Contains xtd::formatable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "stream_insertable.hpp"
#include "iformatable.hpp"
#include "raw_type.hpp"
#include "string_view.hpp"
#include "textual.hpp"
#include <concepts>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace globalization {
    class culture_info;
  }
  /// @endcond
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/formatable_.hpp
  template<typename value_t>
  concept formatable =
  std::derived_from<xtd::raw_type<value_t>, xtd::iformatable> ||
  requires(const xtd::raw_type<value_t>& value, xtd::string_view format, xtd::globalization::culture_info culture) {{value.to_string(format, culture)} -> xtd::textual;} ||
  xtd::stream_insertable<xtd::raw_type<value_t>>;
}
