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
    /// @brief The contraints namespace contains the constraint-based assert model.
    namespace constraints {
      template<class actual_t>
      class is_not_value : public actual_value<actual_t> {
      public:
        is_not_value() = default;
        is_not_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move(v)} {}
        is_not_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        
        /// @brief Asserts that value is empty.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto v1 = xtd::array {0, 1, 2, 3};
        /// auto v2 = xtd::array<int> {};
        /// valid_that(v1).is().not_().empty(); // test ok.
        /// assert_that(v2).is().not_().empty(); // test throws an assert_error exception.
        /// ```
        auto empty(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::is_not_empty(actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::is_not_empty(actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::is_not_empty(actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that value is empty.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto v1 = xtd::array {0, 1, 2, 3};
        /// auto v2 = xtd::array<int> {};
        /// valid_that(v1).is().not_().empty("User message..."); // test ok.
        /// assert_that(v2).is().not_().empty("User message..."); // test throws an assert_error exception.
        /// ```
        auto empty(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::is_not_empty(actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::is_not_empty(actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::is_not_empty(actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        
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
        template<class expected_t>
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
        /// int b = 24;
        /// int& c = a;
        /// valid_that(a).is().not_().same_as(b); // test ok.
        /// assert_that(a).is().not_().same_as(c); // test throws an assert_error exception.
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
        /// int b = 24;
        /// int& c = a;
        /// valid_that(a).is().not_().same_as(b "User message..."); // test ok.
        /// assert_that(a).is().not_().same_as(c, "User message..."); // test throws an assert_error exception.
        /// ```
        template<class expected_t>
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
