/// @file
/// @brief Contains xtd::invocable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#pragma once
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<class function_t, class result_t = void, class... args_t>
  concept invocable = std::invocable<function_t, args_t...> && std::same_as<std::invoke_result_t<function_t, args_t...>, result_t>;
}
