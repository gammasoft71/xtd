/// @file
/// @brief Contains xtd::invocable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#pragma once
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/invocable_.hpp
  template<typename function_t, typename result_t = void, typename... args_t>
  concept invocable = std::invocable<function_t, args_t...> && std::convertible_to<std::invoke_result_t<function_t, args_t...>, result_t>;
}
