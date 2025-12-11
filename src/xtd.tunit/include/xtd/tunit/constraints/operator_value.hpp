/// @file
/// @brief Contains xtd::tunit::constraints::operator_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "actual_value.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    namespace constraints {
      template<class actual_t>
      class operator_value : public actual_value<actual_t> {
      public:
        operator_value() = default;
        operator_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move(v)} {}
        operator_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        
        inline auto and_();
      };
    }
  }
}
