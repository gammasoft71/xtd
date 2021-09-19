/// @file
/// @brief Contains xtd::tunit::string_assume class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "assume.h"
#include "string_assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The string_assume class contains a collection of static methods that implement the most string assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class string_assume final : private base_assert {
    public:
      /// @cond
      string_assume() = delete;
      /// @endcond
      
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_equal_ignoring_case("value", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_assume::are_equal_ignoring_case("key", xtd::ustring("VALUE")); // test throws an abort_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {are_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_assume::are_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal_ignoring_case(expected, actual, "", stack_frame);}
      
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assume::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {are_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::are_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::are_equal_ignoring_case(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("key", xtd::ustring("VALUE")); // test ok.
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("value", xtd::ustring("VALUE")); // test throws an abort_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual) {are_not_equal_ignoring_case(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), csf_); // test ok.
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal_ignoring_case(expected, actual, "", stack_frame);}
      
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message) {are_not_equal_ignoring_case(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("key", xtd::ustring("VALUE"), "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::are_not_equal_ignoring_case("value", xtd::ustring("VALUE"), "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const xtd::ustring& expected, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::are_not_equal_ignoring_case(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s); // test ok.
      /// xtd::tunit::string_assume::contains("z", s); // test throws an abort_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string) {contains(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, csf_); // test throws an abort_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {contains(item, string, "", stack_frame);}
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {contains(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void contains(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::contains(item, string, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s); // test ok.
      /// xtd::tunit::string_assume::contains("z", s); // test throws an abort_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string) {does_not_contain(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s, csf_); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {does_not_contain(item, string, "", stack_frame);}
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {does_not_contain(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::contains("a", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::contains("z", s, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_contain(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::does_not_contain(item, string, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that string starts with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::starts_with("val", s); // test ok.
      /// xtd::tunit::string_assume::starts_with("zoe", s); // test throws an abort_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string) {starts_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::starts_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_assume::starts_with("zoe", s, csf_); // test throws an abort_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {starts_with(item, string, "", stack_frame);}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::starts_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::starts_with("zoe", s, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {starts_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::starts_with("val", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::starts_with("zoe", s, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void starts_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::starts_with(item, string, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      /// @brief Validates that string does not start with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_start_with("zoe", s); // test ok.
      /// xtd::tunit::string_assume::does_not_start_with("val", s); // test throws an abort_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string) {does_not_start_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_start_with("zoe", s, csf_); // test ok.
      /// xtd::tunit::string_assume::does_not_start_with("val", s, csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {does_not_start_with(item, string, "", stack_frame);}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_start_with("zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::does_not_start_with("val", s, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {does_not_start_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_start_with("zoe", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::does_not_start_with("val", s, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_start_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::does_not_start_with(item, string, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that string ends with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::ends_with("val", s); // test ok.
      /// xtd::tunit::string_assume::ends_with("law", s); // test throws an abort_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string) {ends_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::ends_with("val", s, csf_); // test ok.
      /// xtd::tunit::string_assume::ends_with("law", s, csf_); // test throws an abort_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {ends_with(item, string, "", stack_frame);}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::ends_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::ends_with("law", s, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {ends_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::ends_with("lue", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::ends_with("law", s, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void ends_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::ends_with(item, string, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that string does not end with a specific item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_end_with("law", s); // test ok.
      /// xtd::tunit::string_assume::does_not_end_with("lue", s); // test throws an abort_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string) {does_not_end_with(item, string, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_end_with("law", s, csf_); // test ok.
      /// xtd::tunit::string_assume::does_not_end_with("lue", s, csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::diagnostics::stack_frame& stack_frame) {does_not_end_with(item, string, "", stack_frame);}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_end_with("law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assume::does_not_end_with("lue", s, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message) {does_not_end_with(item, string, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring s = "value";
      /// xtd::tunit::string_assume::does_not_end_with("law", s, "User message...", csf_); // test ok.
      /// xtd::tunit::string_assume::does_not_end_with("lue", s, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_end_with(const xtd::ustring& item, const xtd::ustring& string, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::does_not_end_with(item, string, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::matches("^Hello", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_assume::matches("^Salut", xtd::ustring("Hello, World!")); // test throws an abort_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {matches(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::matches("^Hello", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_assume::matches("^Salut", xtd::ustring("Hello, World!"), csf_); // test throws an abort_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {matches(regex_pattern, actual, "", stack_frame);}
      
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::matches("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assume::matches("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {matches(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that matches regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::matches("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_assume::matches("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test throws an abort_error exception.
      /// @endcode
      static void matches(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::matches(regex_pattern, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::does_not_match("^Salut", xtd::ustring("Hello, World!")); // test ok.
      /// xtd::tunit::string_assume::does_not_match("^Hello", xtd::ustring("Hello, World!")); // test throws an abort_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual) {does_not_match(regex_pattern, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::does_not_match("^Salut", xtd::ustring("Hello, World!"), csf_); // test ok.
      /// xtd::tunit::string_assume::does_not_match("^Hello", xtd::ustring("Hello, World!"), csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::diagnostics::stack_frame& stack_frame) {does_not_match(regex_pattern, actual, "", stack_frame);}
      
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::does_not_match("^Salut", xtd::ustring("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assume::does_not_match("^Hello", xtd::ustring("Hello, World!"), "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message) {does_not_match(regex_pattern, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validates that does not match regex pattern.
      /// @param regex_pattern the regex pattern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assume::does_not_match("^Salut", "Hello, World!", xtd::ustring("User message..."), csf_); // test ok.
      /// xtd::tunit::string_assume::does_not_match("^Hello", "Hello, World!", xtd::ustring("User message..."), csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_match(const xtd::ustring& regex_pattern, const xtd::ustring& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          string_assert::does_not_match(regex_pattern, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
    };
  }
}
