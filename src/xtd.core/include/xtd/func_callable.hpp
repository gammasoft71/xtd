/// @file
/// @brief Contains xtd::func_callable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "invocable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<class function_t, class result_t = void, class... args_t>
  concept func_callable = xtd::invocable<function_t, result_t, args_t...>;
}
