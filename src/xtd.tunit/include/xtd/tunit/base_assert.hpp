/// @file
/// @brief Contains xtd::tunit::assert class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.hpp"
#define __XTD_TUNIT_INTERNAL__
#include "__default_insert_basic_ostream_operator.hpp"
#include "__tunit_join__items.hpp"
#define __XTD_TUNIT_INTERNAL__
#include "abort_error.hpp"
#include "assert_error.hpp"
#include "ignore_error.hpp"
#include "settings.hpp"
#include <xtd/environment>
#include <xtd/math>
#include <xtd/static>
#include <xtd/types>
#include <xtd/typeof>
#include <xtd/string>
#include <xtd/diagnostics/assert>
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
      static auto abort(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      /// @brief Abort current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::abort("User message..."); // test throws an abort_error exception.
      /// ```
      static auto abort(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::fail(); // test throws an assert_error exception.
      /// ```
      static auto fail(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::fail("User message..."); // test throws an assert_error exception.
      /// ```
      static auto fail(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::ignore(); // test throws an ignore_error exception.
      /// ```
      static auto ignore(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::ignore("User message..."); // test throws an ignore_error exception.
      /// ```
      static auto ignore(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::succeed(); // test ok.
      /// ```
      static auto succeed(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::succeed("User message..."); // test ok.
      /// ```
      static auto succeed(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
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
      static auto error() -> void;
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::error("User message..."); // test throws an assert_error exception.
      /// ```
      static auto error(const xtd::string& message) -> void;
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::error(actual_str, expected_str, "User message..."); // test throws an assert_error exception.
      /// ```
      static auto error(const xtd::string& actual, const xtd::string& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void;
      
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assert::fail(actual_str, expected_str, "User message..."); // test throws an assert_error exception.
      /// ```
      static auto fail(const xtd::string& actual, const xtd::string& expected, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) -> void {
        if (!test_fail(actual, expected, message, stack_frame) && xtd::environment::compiler_version().build_type() == build_type::debug) {
          auto msg = message != xtd::string {""} ? message : xtd::string {"assertion failed!"}; // Force asyle do not remove {}
          assert_(false, msg);
        } else { /*if (xtd::environment::target_type().is_test_application())*/
          if (settings::default_settings().break_on_failure() && xtd::diagnostics::debugger::is_attached()) debug_break_();
          throw assert_error(message != xtd::string {""} ? message : xtd::string {"assertion failed!"});
        }
      }
      
      /// @brief Convert specified value to xtd::string.
      /// @param value The value to convert to xtd::string.
      /// @return The xtd::string that contains the value.
      template<typename value_t>
      static auto to_string(const value_t& value) -> xtd::string {return __tunit_to_string(value);}
      /// @brief Convert specified value to xtd::string.
      /// @param value The value to convert to xtd::string.
      /// @return The xtd::string that contains the value.
      template<typename value_t>
      static auto to_string(const value_t* value) -> xtd::string {return __tunit_to_string(value);}
      
      /// @brief Join specified collection into xtd::string.
      /// @param collection The collection to join into xtd::string.
      /// @return The xtd::string that contains the joined collection.
      template<typename collection_t>
      static auto join_items(const collection_t& collection) -> xtd::string {return __tunit_join__items(collection);}
      /// @brief Join specified string into xtd::string.
      /// @param str The joined to join into xtd::string.
      /// @return The xtd::string that contains the joined string.
      static auto join_items(const xtd::string& str) -> xtd::string;
      /// @}
      
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      template<typename value_a_t, typename value_b_t>
      [[nodiscard]] static auto equals(const value_a_t& value_a, const value_b_t& value_b) -> bool {
        return value_a == value_b;
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      template<typename char_t>
      [[nodiscard]] static auto equals(const char_t* value_a, const string& value_b) -> bool {
        return xtd::string {value_a} == value_b;
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      template<typename char_t>
      [[nodiscard]] static auto equals(const string&  value_a, const char_t* value_b) -> bool {
        return value_a == xtd::string {value_b};
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      [[nodiscard]] static auto equals(long double value_a, long double value_b) -> bool {
        return equals(value_a, value_b, 0.0001l);
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      [[nodiscard]] static auto equals(double value_a, double value_b) -> bool {
        return equals(value_a, value_b, 0.0001);
      }
      /// @brief Determines if specified values are equal.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      [[nodiscard]] static auto equals(float value_a, float value_b) -> bool {
        return equals(value_a, value_b, 0.0001f);
      }
      /// @brief Determines if specified values are equal with tolerance.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal in percent. For example 0.0001l repsesent 0.01%.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      [[nodiscard]] static auto equals(double value_a, double value_b, double tolerance) -> bool {
        return value_a == value_b ? true : xtd::math::abs(value_a - value_b) <= (xtd::math::abs(tolerance) * xtd::math::max(xtd::math::abs(value_a), xtd::math::abs(value_b)));
      }
      /// @brief Determines if specified values are equal with tolerance.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal in percent. For example 0.0001 repsesent 0.01%.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      [[nodiscard]] static auto equals(long double value_a, long double value_b, long double tolerance) -> bool {
        return value_a == value_b ? true : xtd::math::abs(value_a - value_b) <= (xtd::math::abs(tolerance) * xtd::math::max(xtd::math::abs(value_a), xtd::math::abs(value_b)));
      }
      /// @brief Determines if specified values are equal with tolerance.
      /// @param value_a The first value.
      /// @param value_a The second value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal in percent. For example 0.0001f repsesent 0.01%.
      /// @return `true` if `value_a` is equal to `value_b`; otherwise `false`.
      [[nodiscard]] static auto equals(float value_a, float value_b, float tolerance) -> bool {
        return value_a == value_b ? true : xtd::math::abs(value_a - value_b) <= (xtd::math::abs(tolerance) * xtd::math::max(xtd::math::abs(value_a), xtd::math::abs(value_b)));
      }
      /// @}
      
    private:
      static auto test_fail(const xtd::string& expected, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) -> bool;
    };
  }
}
