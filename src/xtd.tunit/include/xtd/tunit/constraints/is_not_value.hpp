/// @file
/// @brief Contains xtd::tunit::constraints::is_not_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "operator_value.hpp"
#include "../assert.hpp"
#include "../assume.hpp"
#include "../collection_assert.hpp"
#include "../collection_assume.hpp"
#include "../collection_valid.hpp"
#include "../string_assert.hpp"
#include "../string_assume.hpp"
#include "../string_valid.hpp"
#include "../valid.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    namespace constraints {
      template<class actual_t>
      class is_not_value : public actual_value<actual_t> {
      public:
        is_not_value() = default;
        is_not_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move (v)} {}
        is_not_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        
        template<class expected_t>
        auto equal_to(const expected_t& expected, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_not_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_not_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::are_not_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
      };
    }
  }
}
