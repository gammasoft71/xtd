/// @file
/// @brief Contains xtd::async_callback_callable concept.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "async_result.hpp"
#include "invocable.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  // Since Doxygen does not work properly with the C++ concept, the documentation for this concept is declared in xtd/async_callback_callable_.hpp
  template<class function_t>
  concept async_callback_callable = xtd::invocable<function_t, void, xtd::async_result>;
}
