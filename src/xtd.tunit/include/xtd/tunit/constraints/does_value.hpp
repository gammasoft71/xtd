/// @file
/// @brief Contains xtd::tunit::constraints::does_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "does_not_value.hpp"
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
      class does_value : public actual_value<actual_t> {
      public:
        does_value() = default;
        does_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move(v)} {}
        does_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        
        inline auto not_() {return does_not_value<actual_t>(self_);}
        
        template<class expected_t>
        auto end_with(const expected_t& expected, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::ends_with(expected, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::ends_with(expected, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::string_assume::ends_with(expected, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        
        template<class expected_t>
        auto end_with(const expected_t& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::ends_with(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::ends_with(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::string_assume::ends_with(expected, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }

        template<class expected_t>
        auto start_with(const expected_t& expected, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::starts_with(expected, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::starts_with(expected, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::string_assume::starts_with(expected, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }

        template<class expected_t>
        auto start_with(const expected_t& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::starts_with(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::starts_with(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::string_assume::starts_with(expected, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }
      };
    }
  }
}
