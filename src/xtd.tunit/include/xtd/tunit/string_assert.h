/// @file
/// @brief Contains xtd::tunit::string_assert class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring>
#include "assert.h"
#include <locale>
#include <cstring>
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
      
      /// @name Static methods
      
      /// @{
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE")); // test throws an assert_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual);
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE")); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual);
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assert_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, csf_); // test throws an assert_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assert_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that string does not end with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s); // test throws an assert_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", xtd::ustring("Hello, World!")); // test throws an assert_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual);
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", xtd::ustring("Hello, World!"), csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that string does not start with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s); // test throws an assert_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that string ends with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s); // test throws an assert_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, csf_); // test throws an assert_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("lue", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", xtd::ustring("Hello, World!")); // test throws an assert_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual);
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", xtd::ustring("Hello, World!"), csf_); // test throws an assert_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message);
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test throws an assert_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s); // test throws an assert_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, csf_); // test throws an assert_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message);
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      /// @}
    };
  }
}

/// @brief Asserts that two type are equal ignoring case.
/// @param expected the expected value.
/// @param actual the actual value.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::tunit::string_assert::are_equal_ignoring_case_("value", xtd::ustring("VALUE")); // test ok.
/// xtd::tunit::string_assert::are_equal_ignoring_case_("key", xtd::ustring("VALUE"), "User message..."); // test error.
/// xtd::tunit::string_assume::are_equal_ignoring_case_("value", xtd::ustring("VALUE")); // test ok.
/// xtd::tunit::string_assume::are_equal_ignoring_case_("key", xtd::ustring("VALUE"), "User message..."); // test error.
/// xtd::tunit::string_valid::are_equal_ignoring_case_("value", xtd::ustring("VALUE")); // test ok.
/// xtd::tunit::string_valid::are_equal_ignoring_case_("key", xtd::ustring("VALUE"), "User message..."); // test error.
/// @endcode
#define are_equal_ignoring_case_(...) __CMD_ASSERT_ARGS(are_equal_ignoring_case, __VA_ARGS__)

/// @brief Asserts that two type are not equal ignoring case.
/// @param expected the expected value.
/// @param actual the actual value.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::tunit::string_assert::are_not_equal_ignoring_case_("key", xtd::ustring("VALUE")); // test ok.
/// xtd::tunit::string_assert::are_not_equal_ignoring_case_("value", xtd::ustring("VALUE"), "User message..."); // test error.
/// xtd::tunit::string_assume::are_not_equal_ignoring_case_("key", xtd::ustring("VALUE")); // test ok.
/// xtd::tunit::string_assume::are_not_equal_ignoring_case_("value", xtd::ustring("VALUE"), "User message..."); // test error.
/// xtd::tunit::string_valid::are_not_equal_ignoring_case_("key", xtd::ustring("VALUE")); // test ok.
/// xtd::tunit::string_valid::are_not_equal_ignoring_case_("value", xtd::ustring("VALUE"), "User message..."); // test error.
/// @endcode
#define are_not_equal_ignoring_case_(...) __CMD_ASSERT_ARGS(are_not_equal_ignoring_case, __VA_ARGS__)

/// @brief Asserts that string starts with item.
/// @param item object to verify.
/// @param collection that contains object.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::ustring s = "value";
/// xtd::tunit::string_assert::does_not_end_with_("law", s); // test ok.
/// xtd::tunit::string_assert::does_not_end_with_("lue", s, "User message..."); // test error.
/// xtd::tunit::string_assume::does_not_end_with_("law", s); // test ok.
/// xtd::tunit::string_assume::does_not_end_with_("lue", s, "User message..."); // test error.
/// xtd::tunit::string_valid::does_not_end_with_("law", s); // test ok.
/// xtd::tunit::string_valid::does_not_end_with_("lue", s, "User message..."); // test error.
/// @endcode
#define does_not_end_with_(...) __CMD_ASSERT_ARGS(does_not_end_with, __VA_ARGS__)

/// @brief Asserts that does not match regex pattern.
/// @param regex_pattern the regex pattern.
/// @param actual the actual value.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::tunit::string_assert::does_not_match_("^Salut", xtd::ustring("Hello, World!")); // test ok.
/// xtd::tunit::string_assert::does_not_match_("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test error.
/// xtd::tunit::string_assume::does_not_match_("^Salut", xtd::ustring("Hello, World!")); // test ok.
/// xtd::tunit::string_assume::does_not_match_("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test error.
/// xtd::tunit::string_valid::does_not_match_("^Salut", xtd::ustring("Hello, World!")); // test ok.
/// xtd::tunit::string_valid::does_not_match_("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test error.
/// @endcode
#define does_not_match_(...) __CMD_ASSERT_ARGS(does_not_match, __VA_ARGS__)

/// @brief Asserts that string starts with item.
/// @param item object to verify.
/// @param collection that contains object.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::ustring s = "value";
/// xtd::tunit::string_assert::does_not_start_with_("zoe", s); // test ok.
/// xtd::tunit::string_assert::does_not_start_with_("val", s, "User message..."); // test error.
/// xtd::tunit::string_assume::does_not_start_with_("zoe", s); // test ok.
/// xtd::tunit::string_assume::does_not_start_with_("val", s, "User message..."); // test error.
/// xtd::tunit::string_valid::does_not_start_with_("zoe", s); // test ok.
/// xtd::tunit::string_valid::does_not_start_with_("val", s, "User message..."); // test error.
/// @endcode
#define does_not_start_with_(...) __CMD_ASSERT_ARGS(does_not_start_with, __VA_ARGS__)

/// @brief Asserts that string starts with item.
/// @param item object to verify.
/// @param collection that contains object.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::ustring s = "value";
/// xtd::tunit::string_assert::ends_with_("val", s); // test ok.
/// xtd::tunit::string_assert::ends_with_("law", s, "User message..."); // test error.
/// xtd::tunit::string_assume::ends_with_("val", s); // test ok.
/// xtd::tunit::string_assume::ends_with_("law", s, "User message..."); // test error.
/// xtd::tunit::string_valid::ends_with_("val", s); // test ok.
/// xtd::tunit::string_valid::ends_with_("law", s, "User message..."); // test error.
/// @endcode
#define ends_with_(...) __CMD_ASSERT_ARGS(ends_with, __VA_ARGS__)

/// @brief Asserts that matches regex pattern.
/// @param regex_pattern the regex pattern.
/// @param actual the actual value.
/// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::tunit::string_assert::matches_("^Hello", xtd::ustring("Hello, World!")); // test ok.
/// xtd::tunit::string_assert::matches_("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test error.
/// xtd::tunit::string_assume::matches_("^Hello", xtd::ustring("Hello, World!")); // test ok.
/// xtd::tunit::string_assume::matches_("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test error.
/// xtd::tunit::string_valid::matches_("^Hello", xtd::ustring("Hello, World!")); // test ok.
/// xtd::tunit::string_valid::matches_("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test error.
/// @endcode
#define matches_(...) __CMD_ASSERT_ARGS(matches, __VA_ARGS__)

/// @brief Asserts that string starts with item.
/// @param item object to verify.
/// @param collection that contains object.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::string_assert, xtd::tunit::string_assume and xtd::tunit::string_valid classes.
/// @par Examples
/// @code
/// xtd::ustring s = "value";
/// xtd::tunit::string_assert::starts_with_("val", s); // test ok.
/// xtd::tunit::string_assert::starts_with_("zoe", s, "User message..."); // test error.
/// xtd::tunit::string_assume::starts_with_("val", s); // test ok.
/// xtd::tunit::string_assume::starts_with_("zoe", s, "User message..."); // test error.
/// xtd::tunit::string_valid::starts_with_("val", s); // test ok.
/// xtd::tunit::string_valid::starts_with_("zoe", s, "User message..."); // test error.
/// @endcode
#define starts_with_(...) __CMD_ASSERT_ARGS(starts_with, __VA_ARGS__)
