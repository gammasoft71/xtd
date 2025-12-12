/// @file
/// @brief Contains xtd::tunit::constraints::is_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "is_not_value.hpp"
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
    /// @brief The constraints namespace contains the constraint-based assert model.
    namespace constraints {
      /// @cond
      template<class actual_t> class that_value;
      /// @endcond
      
      template<class actual_t>
      class is_value : public actual_value<actual_t> {
      public:
        /// @name Public Methods
        
        /// @{
        inline auto not_() {return is_not_value<actual_t>(self_);}
        
        /// @brief Asserts that value is empty.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto v1 = xtd::array<int> {};
        /// auto v2 = xtd::array {0, 1, 2, 3};
        /// valid_that(v1).is().empty(); // test ok.
        /// assert_that(v2).is().empty(); // test throws an assert_error exception.
        /// ```
        auto empty(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::is_empty(actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::is_empty(actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::is_empty(actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that value is empty and specified user message.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto v1 = xtd::array<int> {};
        /// auto v2 = xtd::array {0, 1, 2, 3};
        /// valid_that(v1).is().empty("User message..."); // test ok.
        /// assert_that(v2).is().empty("User message..."); // test throws an assert_error exception.
        /// ```
        auto empty(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::is_empty(actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::is_empty(actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::is_empty(actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        
        /// @brief Asserts that value is equal to specified expected.
        /// @param expected the expected value.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto value = 24;
        /// valid_that(value).is().equal_to(24); // test ok.
        /// assert_that(value).is().equal_to(23); // test throws an assert_error exception.
        /// ```
        template<class expected_t>
        auto equal_to(const expected_t& expected, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::are_equal(expected, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that value is equal to specified expected with specified user message.
        /// @param expected the expected value.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto value = 24;
        /// valid_that(value).is().equal_to(24 "User message..."); // test ok.
        /// assert_that(value).is().equal_to(23, "User message..."); // test throws an assert_error exception.
        /// ```
        template<class expected_t>
        auto equal_to(const expected_t& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_equal(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_equal(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::assume::are_equal(expected, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }
        
        /// @brief Asserts that value is same as specified expected.
        /// @param expected the expected value.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// int a = 24;
        /// int& b = a;
        /// int c = 24;
        /// valid_that(a).is().same_as(b); // test ok.
        /// assert_that(a).is().same_as(c); // test throws an assert_error exception.
        /// ```
        template<class expected_t>
        auto same_as(const expected_t& expected, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_same(expected, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_same(expected, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::assume::are_same(expected, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that value is same as specified expected with specified user message.
        /// @param expected the expected value.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// int a = 24;
        /// int& b = a;
        /// int c = 24;
        /// valid_that(a).is().same_as(b "User message..."); // test ok.
        /// assert_that(a).is().same_as(c, "User message..."); // test throws an assert_error exception.
        /// ```
        template<class expected_t>
        auto same_as(const expected_t& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::assert::are_same(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::valid::are_same(expected, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::assume::are_same(expected, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @}
        
      protected:
        /// @name Protected Construtors
        
        /// @{
        is_value() = default;
        is_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move(v)} {}
        is_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        /// @}
        
      private:
        template<class value_t> friend class that_value;
      };
    }
  }
}
