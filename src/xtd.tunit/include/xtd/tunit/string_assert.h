/// @file
/// @brief Contains xtd::tunit::string_assert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>
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
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class string_assert final : private base_assert {
    public:
      /// @cond
      string_assert() = delete;
      /// @endcond
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {are_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal_ignoring_case(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {are_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (actual.to_lower() == expected.to_lower())
          assert::succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected) + ", ignoring case", base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {are_not_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal_ignoring_case(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {are_not_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (actual.to_lower() != expected.to_lower())
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("not " + base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string) {contains(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {contains(item, string, "", stack_frame);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {contains(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (string.find(item) != xtd::ustring::npos)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("string containing " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
      }
       
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string) {does_not_contain(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {does_not_contain(item, string, "", stack_frame);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {does_not_contain(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (string.find(item) == xtd::ustring::npos)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("not string containing " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
      }
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string) {starts_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {starts_with(item, string, "", stack_frame);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {starts_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (string.find(item) == 0)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
      }
 
      /// @brief Asserts that string does not start with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string) {does_not_start_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {does_not_start_with(item, string, "", stack_frame);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {does_not_start_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (string.find(item) != 0)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("not string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
      }
      
      /// @brief Asserts that string ends with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string) {ends_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {ends_with(item, string, "", stack_frame);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {ends_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::ends_with("lue", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (string.rfind(item) != xtd::ustring::npos)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
      }
      
      /// @brief Asserts that string does not end with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string) {does_not_end_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {does_not_end_with(item, string, "", stack_frame);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {does_not_end_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (string.rfind(item) == xtd::ustring::npos)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("not string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, stack_frame);
      }
       
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", xtd::ustring("Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {matches(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", xtd::ustring("Hello, World!"), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {matches(regex_pattern, actual, "", stack_frame);}
      
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {matches(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::string pattern(regex_pattern);
        std::regex r(pattern);
        std::smatch m;
        std::string act(actual);
        if (std::regex_search(act, m, r) == true)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", xtd::ustring("Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {does_not_match(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", xtd::ustring("Hello, World!"), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {does_not_match(regex_pattern, actual, "", stack_frame);}
      
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {does_not_match(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::string pattern(regex_pattern);
        std::regex r(pattern);
        std::smatch m;
        std::string act(actual);
        if (std::regex_search(act, m, r) == false)
          assert::succeed(message, stack_frame);
        else
          base_assert::fail("not string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, stack_frame);
      }
    };
  }
}

#define are_equal_ignoring_case_(...) __CMD_ASSERT_ARGS(are_equal_ignoring_case, __VA_ARGS__)

#define are_not_equal_ignoring_case_(...) __CMD_ASSERT_ARGS(are_not_equal_ignoring_case, __VA_ARGS__)

#define does_not_end_with_(...) __CMD_ASSERT_ARGS(does_not_end_with, __VA_ARGS__)

#define does_not_match_(...) __CMD_ASSERT_ARGS(does_not_match, __VA_ARGS__)

#define does_not_start_with_(...) __CMD_ASSERT_ARGS(does_not_start_with, __VA_ARGS__)

#define ends_with_(...) __CMD_ASSERT_ARGS(ends_with, __VA_ARGS__)

#define matches_(...) __CMD_ASSERT_ARGS(matches, __VA_ARGS__)

#define starts_with_(...) __CMD_ASSERT_ARGS(starts_with, __VA_ARGS__)
