/// @file
/// @brief Contains xtd::tunit::string_assert class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/string>
#include "assert.hpp"
#include <regex>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The string_assert class contains a collection of static methods that implement the most string assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit assertions
    /// @remarks Assertions are central to unit testing in any of the xUnit frameworks, and xtd.tunit is no exception. xtd.tunit provides a rich set of assertions as static methods of the Assert class.
    /// @remarks If an assertion fails, the method call does not return and an error is reported. If a test contains multiple assertions, any that follow the one that failed will not be executed. For this reason, it's usually best to try for one assertion per test.
    /// @remarks Each method may be called without a message, with a simple text message or with a message and arguments. In the last case the message is formatted using the provided text and arguments.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include string_assert.cpp
    class tunit_export_ string_assert final : private base_assert {
    public:
      /// @cond
      string_assert() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::string("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::string("VALUE")); // test throws an assert_error exception.
      /// ```
      static void are_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::string("VALUE"), "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::string("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::string("VALUE")); // test throws an assert_error exception.
      /// ```
      static void are_not_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::string("VALUE"), "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_not_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assert_error exception.
      /// ```
      static void contains(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assert_error exception.
      /// ```
      static void contains(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assert_error exception.
      /// ```
      static void does_not_contain(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assert_error exception.
      /// ```
      static void does_not_contain(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that string ends with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s); // test throws an assert_error exception.
      /// ```
      static void does_not_end_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that string ends with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, "User message..."); // test throws an assert_error exception.
      /// ```
      static void does_not_end_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::does_not_match("^Salut", xtd::string("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", xtd::string("Hello, World!")); // test throws an assert_error exception.
      /// ```
      static void does_not_match(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::does_not_match("^Salut", "Hello, World!", xtd::string("User message...")); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", "Hello, World!", xtd::string("User message...")); // test throws an assert_error exception.
      /// ```
      static void does_not_match(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s); // test throws an assert_error exception.
      /// ```
      static void does_not_start_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, "User message..."); // test throws an assert_error exception.
      /// ```
      static void does_not_start_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that string ends with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s); // test throws an assert_error exception.
      /// ```
      static void ends_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that string ends with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::ends_with("lue", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, "User message..."); // test throws an assert_error exception.
      /// ```
      static void ends_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::matches("^Hello", xtd::string("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", xtd::string("Hello, World!")); // test throws an assert_error exception.
      /// ```
      static void matches(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assert::matches("^Hello", "Hello, World!", xtd::string("User message...")); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", "Hello, World!", xtd::string("User message...")); // test throws an assert_error exception.
      /// ```
      static void matches(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s); // test throws an assert_error exception.
      /// ```
      static void starts_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, "User message..."); // test throws an assert_error exception.
      /// ```
      static void starts_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @}
    };
  }
}
