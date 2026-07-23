/// @file
/// @brief Contains xtd::func_callable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "invocable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/func_callable_.hpp
  template<typename function_t, typename result_t = void, typename... args_t>
  concept func_callable = xtd::invocable<function_t, result_t, args_t...>;
}
