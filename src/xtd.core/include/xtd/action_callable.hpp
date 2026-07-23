/// @file
/// @brief Contains xtd::action_callable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "invocable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/action_callable_.hpp
  template<typename function_t, typename... args_t>
  concept action_callable = xtd::invocable<function_t, void, args_t...>;
}
