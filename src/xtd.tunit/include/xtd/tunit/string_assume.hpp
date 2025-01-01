/// @file
/// @brief Contains xtd::tunit::string_assume class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "assume.hpp"
#include "string_assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The string_assume class contains a collection of static methods that implement the most string assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit assumptions
    /// @remarks Assumptions are intended to express the state a test must be in to provide a meaningful result. They are functionally similar to assertions, however a unmet assumption will produce an aborted test result, as opposed to a failure.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include string_assume.cpp
    class tunit_export_ string_assume final : private base_assert {
    public:
      /// @cond
      string_assume() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::are_equal_ignoring_case("value", xtd::string("VALUE")); // test ok.
      /// xtd::tunit::string_assume::are_equal_ignoring_case("key", xtd::string("VALUE")); // test throws an abort_error exception.
      /// ```
      static void are_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::are_equal_ignoring_case("value", xtd::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assume::are_equal_ignoring_case("key", xtd::string("VALUE"), "User message..."); // test throws an abort_error exception.
      /// ```
      static void are_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("key", xtd::string("VALUE")); // test ok.
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("value", xtd::string("VALUE")); // test throws an abort_error exception.
      /// ```
      static void are_not_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("key", xtd::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("value", xtd::string("VALUE"), "User message..."); // test throws an abort_error exception.
      /// ```
      static void are_not_equal_ignoring_case(const xtd::string& expected, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::contains("a", s); // test ok.
      /// xtd::tunit::string_assume::contains("z", s); // test throws an abort_error exception.
      /// ```
      static void contains(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, "User message..."); // test throws an abort_error exception.
      /// ```
      static void contains(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::contains("a", s); // test ok.
      /// xtd::tunit::string_assume::contains("z", s); // test throws an abort_error exception.
      /// ```
      static void does_not_contain(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, "User message..."); // test throws an abort_error exception.
      /// ```
      static void does_not_contain(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::does_not_end_with("law", s); // test ok.
      /// xtd::tunit::string_assume::does_not_end_with("lue", s); // test throws an abort_error exception.
      /// ```
      static void does_not_end_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::does_not_end_with("law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::does_not_end_with("lue", s, "User message..."); // test throws an abort_error exception.
      /// ```
      static void does_not_end_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::does_not_match("^Salut", xtd::string("Hello, World!")); // test ok.
      /// xtd::tunit::string_assume::does_not_match("^Hello", xtd::string("Hello, World!")); // test throws an abort_error exception.
      /// ```
      static void does_not_match(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::does_not_match("^Salut", "Hello, World!", xtd::string("User message...")); // test ok.
      /// xtd::tunit::string_assume::does_not_match("^Hello", "Hello, World!", xtd::string("User message...")); // test throws an abort_error exception.
      /// ```
      static void does_not_match(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::does_not_start_with("zoe", s); // test ok.
      /// xtd::tunit::string_assume::does_not_start_with("val", s); // test throws an abort_error exception.
      /// ```
      static void does_not_start_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::does_not_start_with("zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::does_not_start_with("val", s, "User message..."); // test throws an abort_error exception.
      /// ```
      static void does_not_start_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());

      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::ends_with("val", s); // test ok.
      /// xtd::tunit::string_assume::ends_with("law", s); // test throws an abort_error exception.
      /// ```
      static void ends_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::ends_with("lue", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::ends_with("law", s, "User message..."); // test throws an abort_error exception.
      /// ```
      static void ends_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::matches("^Hello", xtd::string("Hello, World!")); // test ok.
      /// xtd::tunit::string_assume::matches("^Salut", xtd::string("Hello, World!")); // test throws an abort_error exception.
      /// ```
      static void matches(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::string_assume::matches("^Hello", "Hello, World!", xtd::string("User message...")); // test ok.
      /// xtd::tunit::string_assume::matches("^Salut", "Hello, World!", xtd::string("User message...")); // test throws an abort_error exception.
      /// ```
      static void matches(const xtd::string& regex_pattern, const xtd::string& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::starts_with("val", s); // test ok.
      /// xtd::tunit::string_assume::starts_with("zoe", s); // test throws an abort_error exception.
      /// ```
      static void starts_with(const xtd::string& item, const xtd::string& string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string s = "value";
      /// xtd::tunit::string_assume::starts_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::starts_with("zoe", s, "User message..."); // test throws an abort_error exception.
      /// ```
      static void starts_with(const xtd::string& item, const xtd::string& string, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @}
    };
  }
}
