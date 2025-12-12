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
    /// @brief The contraints namespace contains the constraint-based assert model.
    namespace constraints {
      /// @cond
      template<class actual_t> class that_value;
      /// @endcond
      
      template<class actual_t>
      class does_value : public actual_value<actual_t> {
      public:
        /// @name Public Methods
        
        /// @{
        inline auto not_() {return does_not_value<actual_t>(self_);}
        
        /// @brief Asserts that string ends with specified item.
        /// @param item object to verify.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto s = "value";
        /// xtd::tunit::constraints::assert_that(s).does().end_with("val"); // test ok.
        /// xtd::tunit::constraints::assert_that(s).does().end_with("law"); // test throws an assert_error exception.
        /// ```
        template<class item_t>
        auto end_with(const item_t& item, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::ends_with(item, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::ends_with(item, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::string_assume::ends_with(item, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that string ends with specified item and specified user message.
        /// @param item object to verify.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// auto s = "value";
        /// xtd::tunit::constraints::assert_that(s).does().end_with("val", "User message..."); // test ok.
        /// xtd::tunit::constraints::assert_that(s).does().end_with("law", "User message..."); // test throws an assert_error exception.
        /// ```
        template<class item_t>
        auto end_with(const item_t& item, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::ends_with(item, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::ends_with(item, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::string_assume::ends_with(item, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }
        
        /// @brief Asserts that string starts with specified item.
        /// @param item object to verify.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// xtd::string s = "value";
        /// xtd::tunit::constraints::assert_that(s).does().start_with("val"); // test ok.
        /// xtd::tunit::constraints::assert_that(s).does().start_with("zoe"); // test throws an assert_error exception.
        /// ```
        template<class item_t>
        auto start_with(const item_t& item, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::starts_with(item, actual_value<actual_t>::actual(), stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::starts_with(item, actual_value<actual_t>::actual(), stack_frame);
          else xtd::tunit::string_assume::starts_with(item, actual_value<actual_t>::actual(), stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @brief Asserts that string starts with specified item and specified user message.
        /// @param item object to verify.
        /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
        /// @param stack_frame Contains information about current file and current line.
        /// @exception xtd::tunit::assert_error If bad assertion.
        /// @par Examples
        /// ```cpp
        /// xtd::string s = "value";
        /// xtd::tunit::constraints::assert_that(s).does().start_with("val", "User message..."); // test ok.
        /// xtd::tunit::constraints::assert_that(s).does().start_with("zoe", "User message..."); // test throws an assert_error exception.
        /// ```
        template<class item_t>
        auto start_with(const item_t& item, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) const {
          if (actual_value<actual_t>::is_assert()) xtd::tunit::string_assert::starts_with(item, actual_value<actual_t>::actual(), message, stack_frame);
          else if (actual_value<actual_t>::is_valid()) xtd::tunit::string_valid::starts_with(item, actual_value<actual_t>::actual(), message, stack_frame);
          else xtd::tunit::string_assume::starts_with(item, actual_value<actual_t>::actual(), message, stack_frame);
          return operator_value<actual_t>(self_);
        }
        /// @}
        
      protected:
        /// @name Protected Construtors
        
        /// @{
        does_value() = default;
        does_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move(v)} {}
        does_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        /// @}
        
      private:
        template<class value_t> friend class that_value;
      };
    }
  }
}
