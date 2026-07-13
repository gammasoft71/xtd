/// @file
/// @brief Contains xtd::predicate_callable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "invocable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/predicate_callable_.hpp
  template<class function_t, class arg_t>
  concept predicate_callable = xtd::invocable<function_t, bool, arg_t>;
}
