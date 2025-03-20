/// @file
/// @brief Contains xtd::tunit::assert class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.hpp"
#define __XTD_TUNIT_INTERNAL__
#include "__default_insert_basic_ostream_operator.hpp"
#include "__tunit_join__items.hpp"
#define __XTD_TUNIT_INTERNAL__
#include "abort_error.hpp"
#include "assert_error.hpp"
#include "ignore_error.hpp"
#include <xtd/math>
#include <xtd/static>
#include <xtd/types>
#include <xtd/typeof>
#include <xtd/string>
#include <xtd/diagnostics/stack_frame>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The base class for assert.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ base_assert static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Abort current test. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::abort(); // test throws an abort_error exception.
      /// ```
      static void abort(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Abort current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::abort("User message..."); // test throws an abort_error exception.
      /// ```
      static void abort(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::fail(); // test throws an assert_error exception.
      /// ```
      static void fail(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::fail("User message..."); // test throws an assert_error exception.
      /// ```
      static void fail(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::ignore(); // test throws an ignore_error exception.
      /// ```
      static void ignore(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::ignore("User message..."); // test throws an ignore_error exception.
      /// ```
      static void ignore(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::succeed(); // test ok.
      /// ```
      static void succeed(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::succeed("User message..."); // test ok.
      /// ```
      static void succeed(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @}
      
    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::error(); // test throws an assert_error exception.
      /// ```
      static void error();
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::error("User message..."); // test throws an assert_error exception.
      /// ```
      static void error(const xtd::string& message);
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::error(actual_str, expected_str, "User message..."); // test throws an assert_error exception.
      /// ```
      static void error(const xtd::string& actual, const xtd::string& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::fail(actual_str, expected_str, "User message..."); // test throws an assert_error exception.
      /// ```
      static void fail(const xtd::string& actual, const xtd::string& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Convert specified value to xtd::string.
      /// @param value The value to convert to xtd::string.
      /// @return The xtd::string that contains the value.
      template<class value_t>
      static xtd::string to_string(const value_t& value) {return __tunit_to_string(value);}
      /// @brief Convert specified value to xtd::string.
      /// @param value The value to convert to xtd::string.
      /// @return The xtd::string that contains the value.
      template<class value_t>
      static xtd::string to_string(const value_t* value) {return __tunit_to_string(value);}
      
      /// @brief Join specified collection into xtd::string.
      /// @param collection The collection to join into xtd::string.
      /// @return The xtd::string that contains the joined collection.
      template<class collection_t>
      static xtd::string join_items(const collection_t& collection) {return __tunit_join__items(collection);}
      /// @brief Join specified string into xtd::string.
      /// @param str The joined to join into xtd::string.
      /// @return The xtd::string that contains the joined string.
      static xtd::string join_items(const xtd::string& str);
      /// @}
      
    protected:
      template<class expected_t, class actual_t>
      static bool equals(const expected_t& expected, const actual_t& actual) {
        return expected == actual;
      }
      
      template<class char_t>
      static bool equals(const char_t* expected, const string& actual) {
        return xtd::string {expected} == actual;
      }
      
      template<class char_t>
      static bool equals(const string&  expected, const char_t* actual) {
        return expected == xtd::string {actual};
      }

      static bool equals(double expected, double actual) {
        return equals(expected, actual, 0.0001);
      }

      static bool equals(float expected, float actual) {
        return equals(expected, actual, 0.0001f);
      }

      static bool equals(double expected, double actual, double relative_difference_factor) {
        const auto greater_magnitude = xtd::math::max(xtd::math::abs(expected), xtd::math::abs(actual));
        return xtd::math::abs(expected - actual) < (relative_difference_factor * greater_magnitude);
      }
      
      static bool equals(float expected, float actual, float relative_difference_factor) {
        const auto greater_magnitude = xtd::math::max(xtd::math::abs(expected), xtd::math::abs(actual));
        return xtd::math::abs(expected - actual) < (relative_difference_factor * greater_magnitude);
      }
      
    private:
      static bool is_debug() noexcept;
    };
  }
}
