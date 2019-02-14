/// @file
/// @brief Contains xtd::tunit::test_state enum class.
#pragma once
#include "class_event_args.hpp"
#include <xtd/delegate.hpp>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    template<typename Type>
    using class_event_handler = xtd::delegate<void(const Type&, const xtd::tunit::class_event_args&)>;
  }
}
