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
        is_not_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move(v)} {}
        is_not_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        
        /// @brief Asserts that value not is equal to specified expected.
        /// @param expected the expected value.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto value = 24;
        /// valid_that(value).is().not_().equal_to(23); // test ok.
        /// assert_that(value).is().not_().equal_to(24); // test throws an assert_error exception.
        /// ```
        template<class expected_t>
        auto equal_to(const expected_t& expected, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_not_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_not_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::are_not_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that value is not equal to specified expected with specified user message.
        /// @param expected the expected value.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto value = 24;
        /// valid_that(value).is().not_().equal_to(23 "User message..."); // test ok.
        /// assert_that(value).is().not_().equal_to(24, "User message..."); // test throws an assert_error exception.
        /// ```
        auto equal_to(const expected_t& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_not_equal(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_not_equal(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::assume::are_not_equal(expected, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }
        
        /// @brief Asserts that value is not same as specified expected.
        /// @param expected the expected value.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// int a = 24;
        /// int& b = a;
        /// int c = 24;
        /// valid_that(a).is().not_().same_as(c); // test ok.
        /// assert_that(a).is().not_().same_as(b); // test throws an assert_error exception.
        /// ```
        template<class expected_t>
        auto same_as(const expected_t& expected, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_not_same(expected, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_not_same(expected, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::are_not_same(expected, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that value is not same as specified expected with specified user message.
        /// @param expected the expected value.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// int a = 24;
        /// int& b = a;
        /// int c = 24;
        /// valid_that(a).is().equal_to(b "User message..."); // test ok.
        /// assert_that(a).is().equal_to(c, "User message..."); // test throws an assert_error exception.
        /// ```
        auto same_as(const expected_t& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_not_same(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_not_same(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::assume::are_not_same(expected, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }
      };
    }
  }
}
