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
      
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      template<class value_a_t, class value_b_t>
      static bool equals(const value_a_t& value_a, const value_b_t& value_b) {
        return value_a == value_b;
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      template<class char_t>
      static bool equals(const char_t* value_a, const string& value_b) {
        return xtd::string {value_a} == value_b;
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      template<class char_t>
      static bool equals(const string&  value_a, const char_t* value_b) {
        return value_a == xtd::string {value_b};
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      static bool equals(long double value_a, long double value_b) {
        return equals(value_a, value_b, 0.0001l);
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      static bool equals(double value_a, double value_b) {
        return equals(value_a, value_b, 0.0001);
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      static bool equals(float value_a, float value_b) {
        return equals(value_a, value_b, 0.0001f);
      }
      /// @brief Determines if specified values are equal with tolerance.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal in percent. For example 0.0001l repsesent 0.01%.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      static bool equals(double value_a, double value_b, double tolerance) {
        return value_a == value_b ? true : xtd::math::abs(value_a - value_b) <= (xtd::math::abs(tolerance) * xtd::math::max(xtd::math::abs(value_a), xtd::math::abs(value_b)));
      }
      /// @brief Determines if specified values are equal with tolerance.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal in percent. For example 0.0001 repsesent 0.01%.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      static bool equals(long double value_a, long double value_b, long double tolerance) {
        return value_a == value_b ? true : xtd::math::abs(value_a - value_b) <= (xtd::math::abs(tolerance) * xtd::math::max(xtd::math::abs(value_a), xtd::math::abs(value_b)));
      }
      /// @brief Determines if specified values are equal with tolerance.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal in percent. For example 0.0001f repsesent 0.01%.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      static bool equals(float value_a, float value_b, float tolerance) {
        return value_a == value_b ? true : xtd::math::abs(value_a - value_b) <= (xtd::math::abs(tolerance) * xtd::math::max(xtd::math::abs(value_a), xtd::math::abs(value_b)));
      }
      /// @}
      
    private:
      static bool is_debug() noexcept;
    };
  }
}
