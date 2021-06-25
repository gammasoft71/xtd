/// @file
/// @brief Contains xtd::tunit::string_assert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "assert.h"
#include <locale>
#include <cstring>
#include <regex>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The string_assert class contains a collection of static methods that implement the most string assertions used in xtd::tUnit.
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
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", std::string("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", std::string("VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::string& expected, const std::string& actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", std::string("VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", std::string("VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::string& expected, const std::string& actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", std::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", std::string("VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::string& expected, const std::string& actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case("value", std::string("VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case("key", std::string("VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail(base_assert::to_string(expected) + ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"value", std::u16string(u"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"key", std::u16string(u"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"value", std::u16string(u"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"key", std::u16string(u"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"value", std::u16string(u"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"key", std::u16string(u"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"value", std::u16string(u"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(u"key", std::u16string(u"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail(base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"value", std::u32string(U"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"key", std::u32string(U"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"value", std::u32string(U"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"key", std::u32string(U"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"value", std::u32string(U"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"key", std::u32string(U"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"value", std::u32string(U"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(U"key", std::u32string(U"Value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail(base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"value", std::wstring(L"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"key", std::wstring(L"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"value", std::wstring(L"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"key", std::wstring(L"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"value", std::wstring(L"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"key", std::wstring(L"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"value", std::wstring(L"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal_ignoring_case(L"key", std::wstring(L"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail(base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @cond
      static void are_equal_ignoring_case(const char* expected, const char* actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_equal_ignoring_case(const char* expected, const char* actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_equal_ignoring_case(const char* expected, const char* actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_equal_ignoring_case(const char* expected, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(std::string(expected), std::string(actual), message, line_info);}

      static void are_equal_ignoring_case(const char16_t* expected, const char16_t* actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_equal_ignoring_case(const char16_t* expected, const char16_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_equal_ignoring_case(const char16_t* expected, const char16_t* actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_equal_ignoring_case(const char16_t* expected, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(std::u16string(expected), std::u16string(actual), message, line_info);}

      static void are_equal_ignoring_case(const char32_t* expected, const char32_t* actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_equal_ignoring_case(const char32_t* expected, const char32_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_equal_ignoring_case(const char32_t* expected, const char32_t* actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_equal_ignoring_case(const char32_t* expected, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(std::u32string(expected), std::u32string(actual), message, line_info);}

      static void are_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual) {are_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message) {are_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ignoring_case(std::wstring(expected), std::wstring(actual), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", std::string("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", std::string("VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::string& expected, const std::string& actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", std::string("VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", std::string("VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::string& expected, const std::string& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", std::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", std::string("VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::string& expected, const std::string& actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("key", std::string("VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case("value", std::string("VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail("not " + base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"key", std::u16string(u"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"value", std::u16string(u"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"key", std::u16string(u"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"value", std::u16string(u"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"key", std::u16string(u"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"value", std::u16string(u"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"key", std::u16string(u"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(u"value", std::u16string(u"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail("not " + base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(U"key", std::u32string(U"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(U"value", std::u32string(U"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(U"key", std::u32string(U"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(U"value", std::u32string(U"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(U"key", std::u32string(U"vValuealue"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(U"value", std::u32string(U"Value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail("not " + base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"key", std::wstring(L"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"value", std::wstring(L"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"key", std::wstring(L"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"value", std::wstring(L"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"key", std::wstring(L"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"value", std::wstring(L"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"key", std::wstring(L"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal_ignoring_case(L"value", std::wstring(L"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ignoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          base_assert::fail("not " + base_assert::to_string(expected)+ ", ignoring case", base_assert::to_string(actual), message, line_info);
      }
      
      /// @cond
      static void are_not_equal_ignoring_case(const char* expected, const char* actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ignoring_case(const char* expected, const char* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ignoring_case(const char* expected, const char* actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ignoring_case(const char* expected, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(std::string(expected), std::string(actual), message, line_info);}
      
      static void are_not_equal_ignoring_case(const char16_t* expected, const char16_t* actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ignoring_case(const char16_t* expected, const char16_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ignoring_case(const char16_t* expected, const char16_t* actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ignoring_case(const char16_t* expected, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(std::u16string(expected), std::u16string(actual), message, line_info);}
      
      static void are_not_equal_ignoring_case(const char32_t* expected, const char32_t* actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ignoring_case(const char32_t* expected, const char32_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ignoring_case(const char32_t* expected, const char32_t* actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ignoring_case(const char32_t* expected, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(std::u32string(expected), std::u32string(actual), message, line_info);}
      
      static void are_not_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual) {are_not_equal_ignoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message) {are_not_equal_ignoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ignoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ignoring_case(std::wstring(expected), std::wstring(actual), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::string& item, const std::string& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::string& item, const std::string& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::string& item, const std::string& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::string& item, const std::string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != std::string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u16string& item, const std::u16string& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u16string& item, const std::u16string& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u16string& item, const std::u16string& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u16string& item, const std::u16string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != std::u16string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u32string& item, const std::u32string& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u32string& item, const std::u32string& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u32string& item, const std::u32string& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::u32string& item, const std::u32string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != std::u32string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::wstring& item, const std::wstring& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::wstring& item, const std::wstring& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::wstring& item, const std::wstring& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(const std::wstring& item, const std::wstring& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != std::wstring::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }

      /// @cond
      static void contains(const char* item, const char* string) {contains(item, string, "", line_info());}
      static void contains(const char* item, const char* string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      static void contains(const char* item, const char* string, const std::string& message) {contains(item, string, message, line_info());}
      static void contains(const char* item, const char* string, const std::string& message, const xtd::tunit::line_info& line_info) {contains(std::string(item), std::string(string), message, line_info);}

      static void contains(const char16_t* item, const char16_t* string) {contains(item, string, "", line_info());}
      static void contains(const char16_t* item, const char16_t* string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      static void contains(const char16_t* item, const char16_t* string, const std::string& message) {contains(item, string, message, line_info());}
      static void contains(const char16_t* item, const char16_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {contains(std::u16string(item), std::u16string(string), message, line_info);}

      static void contains(const char32_t* item, const char32_t* string) {contains(item, string, "", line_info());}
      static void contains(const char32_t* item, const char32_t* string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      static void contains(const char32_t* item, const char32_t* string, const std::string& message) {contains(item, string, message, line_info());}
      static void contains(const char32_t* item, const char32_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {contains(std::u32string(item), std::u32string(string), message, line_info);}

      static void contains(const wchar_t* item, const wchar_t* string) {contains(item, string, "", line_info());}
      static void contains(const wchar_t* item, const wchar_t* string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      static void contains(const wchar_t* item, const wchar_t* string, const std::string& message) {contains(item, string, message, line_info());}
      static void contains(const wchar_t* item, const wchar_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {contains(std::wstring(item), std::wstring(string), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s); // test ok.
      /// xtd::tunit::string_assert::contains("z", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::string& item, const std::string& string) {does_not_contain(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::string& item, const std::string& string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::string& item, const std::string& string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains("a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains("z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::string& item, const std::string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == std::string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u16string& item, const std::u16string& string) {does_not_contain(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u16string& item, const std::u16string& string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u16string& item, const std::u16string& string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u"a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(u"z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u16string& item, const std::u16string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == std::u16string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u32string& item, const std::u32string& string) {does_not_contain(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u32string& item, const std::u32string& string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u32string& item, const std::u32string& string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U"a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(U"z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::u32string& item, const std::u32string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == std::u32string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::wstring& item, const std::wstring& string) {does_not_contain(item, string, "", line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::wstring& item, const std::wstring& string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::wstring& item, const std::wstring& string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      
      /// @brief Asserts that string contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L"a", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(L"z", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_contain(const std::wstring& item, const std::wstring& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == std::wstring::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string containing " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @cond
      static void does_not_contain(const char* item, const char* string) {does_not_contain(item, string, "", line_info());}
      static void does_not_contain(const char* item, const char* string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      static void does_not_contain(const char* item, const char* string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      static void does_not_contain(const char* item, const char* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_contain(std::string(item), std::string(string), message, line_info);}
      
      static void does_not_contain(const char16_t* item, const char16_t* string) {does_not_contain(item, string, "", line_info());}
      static void does_not_contain(const char16_t* item, const char16_t* string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      static void does_not_contain(const char16_t* item, const char16_t* string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      static void does_not_contain(const char16_t* item, const char16_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_contain(std::u16string(item), std::u16string(string), message, line_info);}
      
      static void does_not_contain(const char32_t* item, const char32_t* string) {does_not_contain(item, string, "", line_info());}
      static void does_not_contain(const char32_t* item, const char32_t* string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      static void does_not_contain(const char32_t* item, const char32_t* string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      static void does_not_contain(const char32_t* item, const char32_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_contain(std::u32string(item), std::u32string(string), message, line_info);}

      static void does_not_contain(const wchar_t* item, const wchar_t* string) {does_not_contain(item, string, "", line_info());}
      static void does_not_contain(const wchar_t* item, const wchar_t* string, const xtd::tunit::line_info& line_info) {does_not_contain(item, string, "", line_info);}
      static void does_not_contain(const wchar_t* item, const wchar_t* string, const std::string& message) {does_not_contain(item, string, message, line_info());}
      static void does_not_contain(const wchar_t* item, const wchar_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_contain(std::wstring(item), std::wstring(string), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::string& item, const std::string& string) {starts_with(item, string, "", line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::string& item, const std::string& string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::string& item, const std::string& string, const std::string& message) {starts_with(item, string, message, line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::starts_with("val", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with("zoe", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::string& item, const std::string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::starts_with(u"val", s); // test ok.
      /// xtd::tunit::string_assert::starts_with(u"zoe", s); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u16string& item, const std::u16string& string) {starts_with(item, string, "", line_info());}
      
      /// @brief Asserts that srinbg start with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::starts_with(u"val", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with(u"zoe", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u16string& item, const std::u16string& string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::starts_with(u"val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::starts_with(u"zoe", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u16string& item, const std::u16string& string, const std::string& message) {starts_with(item, string, message, line_info());}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::starts_with(u"val", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with(u"zoe", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u16string& item, const std::u16string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::starts_with(U"val", s); // test ok.
      /// xtd::tunit::string_assert::starts_with(U"zoe", s); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u32string& item, const std::u32string& string) {starts_with(item, string, "", line_info());}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::starts_with(U"val", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with(U"zoe", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u32string& item, const std::u32string& string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::starts_with(U"val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::starts_with(U"zoe", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u32string& item, const std::u32string& string, const std::string& message) {starts_with(item, string, message, line_info());}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::starts_with(U"val", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with(U"zoe", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::u32string& item, const std::u32string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::starts_with(L"val", s); // test ok.
      /// xtd::tunit::string_assert::starts_with(L"zoe", s); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::wstring& item, const std::wstring& string) {starts_with(item, string, "", line_info());}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::starts_with(L"val", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with(L"zoe", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::wstring& item, const std::wstring& string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::starts_with(L"val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::starts_with(L"zoe", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::wstring& item, const std::wstring& string, const std::string& message) {starts_with(item, string, message, line_info());}
      
      /// @brief Asserts that string starts witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::starts_with(L"val", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::starts_with(L"zoe", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void starts_with(const std::wstring& item, const std::wstring& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) == 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string starts with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @cond
      static void starts_with(const char* item, const char* string) {starts_with(item, string, "", line_info());}
      static void starts_with(const char* item, const char* string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      static void starts_with(const char* item, const char* string, const std::string& message) {starts_with(item, string, message, line_info());}
      static void starts_with(const char* item, const char* string, const std::string& message, const xtd::tunit::line_info& line_info) {starts_with(std::string(item), std::string(string), message, line_info);}
      
      static void starts_with(const char16_t* item, const char16_t* string) {starts_with(item, string, "", line_info());}
      static void starts_with(const char16_t* item, const char16_t* string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      static void starts_with(const char16_t* item, const char16_t* string, const std::string& message) {starts_with(item, string, message, line_info());}
      static void starts_with(const char16_t* item, const char16_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {starts_with(std::u16string(item), std::u16string(string), message, line_info);}
      
      static void starts_with(const char32_t* item, const char32_t* string) {starts_with(item, string, "", line_info());}
      static void starts_with(const char32_t* item, const char32_t* string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      static void starts_with(const char32_t* item, const char32_t* string, const std::string& message) {starts_with(item, string, message, line_info());}
      static void starts_with(const char32_t* item, const char32_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {starts_with(std::u32string(item), std::u32string(string), message, line_info);}
      
      static void starts_with(const wchar_t* item, const wchar_t* string) {starts_with(item, string, "", line_info());}
      static void starts_with(const wchar_t* item, const wchar_t* string, const xtd::tunit::line_info& line_info) {starts_with(item, string, "", line_info);}
      static void starts_with(const wchar_t* item, const wchar_t* string, const std::string& message) {starts_with(item, string, message, line_info());}
      static void starts_with(const wchar_t* item, const wchar_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {starts_with(std::wstring(item), std::wstring(string), message, line_info);}
      /// @endcond

      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::string& item, const std::string& string) {does_not_start_with(item, string, "", line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::string& item, const std::string& string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::string& item, const std::string& string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_start_with("zoe", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with("val", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::string& item, const std::string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_start_with(u"zoe", s); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(u"val", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u16string& item, const std::u16string& string) {does_not_start_with(item, string, "", line_info());}
      
      /// @brief Asserts that srinbg start with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_start_with(u"zoe", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(u"val", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u16string& item, const std::u16string& string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_start_with(u"zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(u"val", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u16string& item, const std::u16string& string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_start_with(u"zoe", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(u"val", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u16string& item, const std::u16string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_start_with(U"zoe", s); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(U"val", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u32string& item, const std::u32string& string) {does_not_start_with(item, string, "", line_info());}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_start_with(U"zoe", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(U"val", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u32string& item, const std::u32string& string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_start_with(U"zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(U"val", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u32string& item, const std::u32string& string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_start_with(U"zoe", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(U"val", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::u32string& item, const std::u32string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_start_with(L"zoe", s); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(L"val", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::wstring& item, const std::wstring& string) {does_not_start_with(item, string, "", line_info());}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_start_with(L"zoe", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(L"val", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::wstring& item, const std::wstring& string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_start_with(L"zoe", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(L"val", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::wstring& item, const std::wstring& string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      
      /// @brief Asserts that string does noy start witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_start_with(L"zoe", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_start_with(L"val", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_start_with(const std::wstring& item, const std::wstring& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.find(item) != 0)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string starting with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @cond
      static void does_not_start_with(const char* item, const char* string) {does_not_start_with(item, string, "", line_info());}
      static void does_not_start_with(const char* item, const char* string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      static void does_not_start_with(const char* item, const char* string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      static void does_not_start_with(const char* item, const char* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_start_with(std::string(item), std::string(string), message, line_info);}
      
      static void does_not_start_with(const char16_t* item, const char16_t* string) {does_not_start_with(item, string, "", line_info());}
      static void does_not_start_with(const char16_t* item, const char16_t* string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      static void does_not_start_with(const char16_t* item, const char16_t* string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      static void does_not_start_with(const char16_t* item, const char16_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_start_with(std::u16string(item), std::u16string(string), message, line_info);}
      
      static void does_not_start_with(const char32_t* item, const char32_t* string) {does_not_start_with(item, string, "", line_info());}
      static void does_not_start_with(const char32_t* item, const char32_t* string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      static void does_not_start_with(const char32_t* item, const char32_t* string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      static void does_not_start_with(const char32_t* item, const char32_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_start_with(std::u32string(item), std::u32string(string), message, line_info);}
      
      static void does_not_start_with(const wchar_t* item, const wchar_t* string) {does_not_start_with(item, string, "", line_info());}
      static void does_not_start_with(const wchar_t* item, const wchar_t* string, const xtd::tunit::line_info& line_info) {does_not_start_with(item, string, "", line_info);}
      static void does_not_start_with(const wchar_t* item, const wchar_t* string, const std::string& message) {does_not_start_with(item, string, message, line_info());}
      static void does_not_start_with(const wchar_t* item, const wchar_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_start_with(std::wstring(item), std::wstring(string), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::string& item, const std::string& string) {ends_with(item, string, "", line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::string& item, const std::string& string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::ends_with("val", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::string& item, const std::string& string, const std::string& message) {ends_with(item, string, message, line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::ends_with("lue", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with("law", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::string& item, const std::string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) != std::string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::ends_with(u"lue", s); // test ok.
      /// xtd::tunit::string_assert::ends_with(u"law", s); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u16string& item, const std::u16string& string) {ends_with(item, string, "", line_info());}
      
      /// @brief Asserts that srinbg start with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::ends_with(u"lue", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with(u"law", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u16string& item, const std::u16string& string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::ends_with(u"lue", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::ends_with(u"law", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u16string& item, const std::u16string& string, const std::string& message) {ends_with(item, string, message, line_info());}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::ends_with(u"lue", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with(u"law", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u16string& item, const std::u16string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) != std::u16string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::ends_with(U"lue", s); // test ok.
      /// xtd::tunit::string_assert::ends_with(U"law", s); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u32string& item, const std::u32string& string) {ends_with(item, string, "", line_info());}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::ends_with(U"lue", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with(U"law", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u32string& item, const std::u32string& string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::ends_with(U"lue", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::ends_with(U"law", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u32string& item, const std::u32string& string, const std::string& message) {ends_with(item, string, message, line_info());}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::ends_with(U"lue", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with(U"law", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::u32string& item, const std::u32string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) != std::u32string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::ends_with(L"lue", s); // test ok.
      /// xtd::tunit::string_assert::ends_with(L"law", s); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::wstring& item, const std::wstring& string) {ends_with(item, string, "", line_info());}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::ends_with(L"val", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with(L"law", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::wstring& item, const std::wstring& string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::ends_with(L"lue", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::ends_with(L"law", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::wstring& item, const std::wstring& string, const std::string& message) {ends_with(item, string, message, line_info());}
      
      /// @brief Asserts that string ends witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::ends_with(L"lue", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::ends_with(L"law", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void ends_with(const std::wstring& item, const std::wstring& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) != std::wstring::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @cond
      static void ends_with(const char* item, const char* string) {ends_with(item, string, "", line_info());}
      static void ends_with(const char* item, const char* string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      static void ends_with(const char* item, const char* string, const std::string& message) {ends_with(item, string, message, line_info());}
      static void ends_with(const char* item, const char* string, const std::string& message, const xtd::tunit::line_info& line_info) {ends_with(std::string(item), std::string(string), message, line_info);}
      
      static void ends_with(const char16_t* item, const char16_t* string) {ends_with(item, string, "", line_info());}
      static void ends_with(const char16_t* item, const char16_t* string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      static void ends_with(const char16_t* item, const char16_t* string, const std::string& message) {ends_with(item, string, message, line_info());}
      static void ends_with(const char16_t* item, const char16_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {ends_with(std::u16string(item), std::u16string(string), message, line_info);}
      
      static void ends_with(const char32_t* item, const char32_t* string) {ends_with(item, string, "", line_info());}
      static void ends_with(const char32_t* item, const char32_t* string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      static void ends_with(const char32_t* item, const char32_t* string, const std::string& message) {ends_with(item, string, message, line_info());}
      static void ends_with(const char32_t* item, const char32_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {ends_with(std::u32string(item), std::u32string(string), message, line_info);}
      
      static void ends_with(const wchar_t* item, const wchar_t* string) {ends_with(item, string, "", line_info());}
      static void ends_with(const wchar_t* item, const wchar_t* string, const xtd::tunit::line_info& line_info) {ends_with(item, string, "", line_info);}
      static void ends_with(const wchar_t* item, const wchar_t* string, const std::string& message) {ends_with(item, string, message, line_info());}
      static void ends_with(const wchar_t* item, const wchar_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {ends_with(std::wstring(item), std::wstring(string), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::string& item, const std::string& string) {does_not_end_with(item, string, "", line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::string& item, const std::string& string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::string& item, const std::string& string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::does_not_end_with("law", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with("lue", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::string& item, const std::string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) == std::string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string starts with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_end_with(u"law", s); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(u"lue", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u16string& item, const std::u16string& string) {does_not_end_with(item, string, "", line_info());}
      
      /// @brief Asserts that srinbg start with item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_end_with(u"law", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(u"lue", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u16string& item, const std::u16string& string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_end_with(u"law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(u"lue", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u16string& item, const std::u16string& string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::does_not_end_with(u"law", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(u"lue", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u16string& item, const std::u16string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) == std::u16string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_end_with(U"law", s); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(U"lue", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u32string& item, const std::u32string& string) {does_not_end_with(item, string, "", line_info());}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_end_with(U"law", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(U"lue", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u32string& item, const std::u32string& string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_end_with(U"law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(U"lue", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u32string& item, const std::u32string& string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::does_not_end_with(U"law", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(U"lue", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::u32string& item, const std::u32string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) == std::u32string::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_end_with(L"law", s); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(L"lue", s); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::wstring& item, const std::wstring& string) {does_not_end_with(item, string, "", line_info());}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_end_with(L"law", s, line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(L"lue", s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::wstring& item, const std::wstring& string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_end_with(L"law", s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(L"lue", s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::wstring& item, const std::wstring& string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      
      /// @brief Asserts that string does not end witdh item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::does_not_end_with(L"law", s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_end_with(L"lue", s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_end_with(const std::wstring& item, const std::wstring& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (string.rfind(item) == std::wstring::npos)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string ending with " + base_assert::to_string(item), base_assert::to_string(string), message, line_info);
      }
      
      /// @cond
      static void does_not_end_with(const char* item, const char* string) {does_not_end_with(item, string, "", line_info());}
      static void does_not_end_with(const char* item, const char* string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      static void does_not_end_with(const char* item, const char* string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      static void does_not_end_with(const char* item, const char* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_end_with(std::string(item), std::string(string), message, line_info);}
      
      static void does_not_end_with(const char16_t* item, const char16_t* string) {does_not_end_with(item, string, "", line_info());}
      static void does_not_end_with(const char16_t* item, const char16_t* string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      static void does_not_end_with(const char16_t* item, const char16_t* string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      static void does_not_end_with(const char16_t* item, const char16_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_end_with(std::u16string(item), std::u16string(string), message, line_info);}
      
      static void does_not_end_with(const char32_t* item, const char32_t* string) {does_not_end_with(item, string, "", line_info());}
      static void does_not_end_with(const char32_t* item, const char32_t* string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      static void does_not_end_with(const char32_t* item, const char32_t* string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      static void does_not_end_with(const char32_t* item, const char32_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_end_with(std::u32string(item), std::u32string(string), message, line_info);}
      
      static void does_not_end_with(const wchar_t* item, const wchar_t* string) {does_not_end_with(item, string, "", line_info());}
      static void does_not_end_with(const wchar_t* item, const wchar_t* string, const xtd::tunit::line_info& line_info) {does_not_end_with(item, string, "", line_info);}
      static void does_not_end_with(const wchar_t* item, const wchar_t* string, const std::string& message) {does_not_end_with(item, string, message, line_info());}
      static void does_not_end_with(const wchar_t* item, const wchar_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_end_with(std::wstring(item), std::wstring(string), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", std::string("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", std::string("Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::string& regex_pattern, const std::string& actual) {matches(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", std::string("Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", std::string("Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::string& regex_pattern, const std::string& actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", std::string("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", std::string("Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::string& regex_pattern, const std::string& actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches("^Hello", "Hello, World!", std::string("User message..."), line_info_); // test ok.
      /// xtd::tunit::string_assert::matches("^Salut", "Hello, World!", std::string("User message..."), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::string& regex_pattern, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        std::regex r(regex_pattern);
        std::smatch m;
        if (std::regex_search(actual, m, r) == true)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }
      /** @todo : when std::regex ready: remove this comment.
       
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(u"^Hello", std::u16string(u"Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::matches(u"^Salut", std::u16string(u"Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u16string& regex_pattern, const std::u16string& actual) {matches(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(u"^Hello", std::u16string(u"Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::matches(u"^Salut",std::u16string(u "Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u16string& regex_pattern, const std::u16string& actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(u"^Hello", std::u16string(u"Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::matches(u"^Salut", std::u16string(u"Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u16string& regex_pattern, const std::u16string& actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(u"^Hello", std::u16string(u"Hello, World!"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::matches(u"^Salut", std::u16string(u"Hello, World!"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u16string& regex_pattern, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        //std::u16regex r(regex_pattern);
        //std::u16smatch m;
        std::basic_regex<char16_t> r(regex_pattern);
        std::match_results<std::u16string::const_iterator> m;
        if (std::regex_search(actual, m, r))
          assert::succeed(message, line_info);
        else
          base_assert::fail("string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(U"^Hello", std::u32string(U"Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::matches(U"^Salut", std::u32string(U"Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u32string& regex_pattern, const std::u32string& actual) {matches(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(U"^Hello", std::u32string(U"Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::matches(U"^Salut", std::u32string(U"Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u32string& regex_pattern, const std::u32string& actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(U"^Hello", std::u32string(U"Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::matches(U"^Salut", std::u32string(U"Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u32string& regex_pattern, const std::u32string& actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(U"^Hello", std::u32string(U"Hello, World!"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::matches(U"^Salut", std::u32string(U"Hello, World!"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::u32string& regex_pattern, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        //std::u32regex r(regex_pattern);
        //std::u32smatch m;
        std::basic_regex<char32_t> r(regex_pattern);
        std::match_results<std::u32string::const_iterator> m;
        if (std::regex_search(actual, m, r) == true)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }
*/
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(L"^Hello", std::wstring(L"Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::matches(L"^Salut", std::wstring(L"Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::wstring& regex_pattern, const std::wstring& actual) {matches(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(L"^Hello", std::wstring(L"Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::matches(L"^Salut", std::wstring(L"Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::wstring& regex_pattern, const std::wstring& actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(L"^Hello", std::wstring(L"Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::matches(L"^Salut", std::wstring(L"Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::wstring& regex_pattern, const std::wstring& actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that matches regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::matches(L"^Hello", std::wstring(L"Hello, World!"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::matches(L"^Salut", std::wstring(L"Hello, World!"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void matches(const std::wstring& regex_pattern, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        std::wregex r(regex_pattern);
        std::wsmatch m;
        if (std::regex_search(actual, m, r) == true)
          assert::succeed(message, line_info);
        else
          base_assert::fail("string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }
      
      /// @cond
      static void matches(const char* regex_pattern, const char* actual) {matches(regex_pattern, actual, "", line_info());}
      static void matches(const char* regex_pattern, const char* actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      static void matches(const char* regex_pattern, const char* actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      static void matches(const char* regex_pattern, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {matches(std::string(regex_pattern), std::string(actual), message, line_info);}
      
      /*
      static void matches(const char16_t* regex_pattern, const char16_t* actual) {matches(regex_pattern, actual, "", line_info());}
      static void matches(const char16_t* regex_pattern, const char16_t* actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      static void matches(const char16_t* regex_pattern, const char16_t* actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      static void matches(const char16_t* regex_pattern, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {matches(std::u16string(regex_pattern), std::u16string(actual), message, line_info);}
      
      static void matches(const char32_t* regex_pattern, const char32_t* actual) {matches(regex_pattern, actual, "", line_info());}
      static void matches(const char32_t* regex_pattern, const char32_t* actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      static void matches(const char32_t* regex_pattern, const char32_t* actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      static void matches(const char32_t* regex_pattern, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {matches(std::u32string(regex_pattern), std::u32string(actual), message, line_info);}
       */
      
      static void matches(const wchar_t* regex_pattern, const wchar_t* actual) {matches(regex_pattern, actual, "", line_info());}
      static void matches(const wchar_t* regex_pattern, const wchar_t* actual, const xtd::tunit::line_info& line_info) {matches(regex_pattern, actual, "", line_info);}
      static void matches(const wchar_t* regex_pattern, const wchar_t* actual, const std::string& message) {matches(regex_pattern, actual, message, line_info());}
      static void matches(const wchar_t* regex_pattern, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {matches(std::wstring(regex_pattern), std::wstring(actual), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", std::string("Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", std::string("Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::string& regex_pattern, const std::string& actual) {does_not_match(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", std::string("Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", std::string("Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::string& regex_pattern, const std::string& actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", std::string("Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", std::string("Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::string& regex_pattern, const std::string& actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match("^Salut", "Hello, World!", std::string("User message..."), line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match("^Hello", "Hello, World!", std::string("User message..."), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::string& regex_pattern, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        std::regex r(regex_pattern);
        std::smatch m;
        if (std::regex_search(actual, m, r) == false)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }

      /** @todo : when std::regex ready: remove this comment.

      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(u"^Salut", std::u16string(u"Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::does_not_match(u"^Hello", std::u16string(u"Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u16string& regex_pattern, const std::u16string& actual) {does_not_match(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(u"^Salut", std::u16string(u"Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match(u"^Hello",std::u16string(u "Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u16string& regex_pattern, const std::u16string& actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(u"^Salut", std::u16string(u"Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_match(u"^Hello", std::u16string(u"Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u16string& regex_pattern, const std::u16string& actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(u"^Salut", std::u16string(u"Hello, World!"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match(u"^Hello", std::u16string(u"Hello, World!"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u16string& regex_pattern, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        //std::u16regex r(regex_pattern);
        //std::u16smatch m;
        std::basic_regex<char16_t> r(regex_pattern);
        std::match_results<std::u16string::const_iterator> m;
        if (std::regex_search(actual, m, r) == false)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(U"^Salut", std::u32string(U"Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::does_not_match(U"^Hello", std::u32string(U"Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u32string& regex_pattern, const std::u32string& actual) {does_not_match(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(U"^Salut", std::u32string(U"Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match(U"^Hello", std::u32string(U"Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u32string& regex_pattern, const std::u32string& actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(U"^Salut", std::u32string(U"Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_match(U"^Hello", std::u32string(U"Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u32string& regex_pattern, const std::u32string& actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(U"^Hello", std::u32string(U"Hello, World!"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match(U"^Hello", std::u32string(U"Hello, World!"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::u32string& regex_pattern, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        //std::u32regex r(regex_pattern);
        //std::u32smatch m;
        std::basic_regex<char32_t> r(regex_pattern);
        std::match_results<std::u32string::const_iterator> m;
        if (std::regex_search(actual, m, r) == false)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }
*/
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(L"^Salut", std::wstring(L"Hello, World!")); // test ok.
      /// xtd::tunit::string_assert::does_not_match(L"^Hello", std::wstring(L"Hello, World!")); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::wstring& regex_pattern, const std::wstring& actual) {does_not_match(regex_pattern, actual, "", line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(L"^Salut", std::wstring(L"Hello, World!"), line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match(L"^Hello", std::wstring(L"Hello, World!"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::wstring& regex_pattern, const std::wstring& actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(L"^Salut", std::wstring(L"Hello, World!"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::does_not_match(L"^Hello", std::wstring(L"Hello, World!"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::wstring& regex_pattern, const std::wstring& actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
      
      /// @brief Asserts that does not match regex patern.
      /// @param regex_pattern the regex patern.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::does_not_match(L"^Salut", std::wstring(L"Hello, World!"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::does_not_match(L"^Hello", std::wstring(L"Hello, World!"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_match(const std::wstring& regex_pattern, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        std::wregex r(regex_pattern);
        std::wsmatch m;
        if (std::regex_search(actual, m, r) == false)
          assert::succeed(message, line_info);
        else
          base_assert::fail("not string matching " + base_assert::to_string(regex_pattern), base_assert::to_string(actual), message, line_info);
      }
      
      /// @cond
      static void does_not_match(const char* regex_pattern, const char* actual) {does_not_match(regex_pattern, actual, "", line_info());}
      static void does_not_match(const char* regex_pattern, const char* actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
      static void does_not_match(const char* regex_pattern, const char* actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
      static void does_not_match(const char* regex_pattern, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_match(std::string(regex_pattern), std::string(actual), message, line_info);}
      
      /*
       static void does_not_match(const char16_t* regex_pattern, const char16_t* actual) {does_not_match(regex_pattern, actual, "", line_info());}
       static void does_not_match(const char16_t* regex_pattern, const char16_t* actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
       static void does_not_match(const char16_t* regex_pattern, const char16_t* actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
       static void does_not_match(const char16_t* regex_pattern, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_match(std::u16string(regex_pattern), std::u16string(actual), message, line_info);}
       
       static void does_not_match(const char32_t* regex_pattern, const char32_t* actual) {does_not_match(regex_pattern, actual, "", line_info());}
       static void does_not_match(const char32_t* regex_pattern, const char32_t* actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
       static void does_not_match(const char32_t* regex_pattern, const char32_t* actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
       static void does_not_match(const char32_t* regex_pattern, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_match(std::u32string(regex_pattern), std::u32string(actual), message, line_info);}
       */
      
      static void does_not_match(const wchar_t* regex_pattern, const wchar_t* actual) {does_not_match(regex_pattern, actual, "", line_info());}
      static void does_not_match(const wchar_t* regex_pattern, const wchar_t* actual, const xtd::tunit::line_info& line_info) {does_not_match(regex_pattern, actual, "", line_info);}
      static void does_not_match(const wchar_t* regex_pattern, const wchar_t* actual, const std::string& message) {does_not_match(regex_pattern, actual, message, line_info());}
      static void does_not_match(const wchar_t* regex_pattern, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {does_not_match(std::wstring(regex_pattern), std::wstring(actual), message, line_info);}
      /// @endcond

    private:
      static std::string to_lower(const std::string& value) {
        std::string result;
        std::locale lc = std::locale();
        for(char c : value) result.push_back(std::tolower(c, lc));
        return result;
      }
      static std::u16string to_lower(const std::u16string& value) {
        std::u16string result;
        std::locale lc = std::locale();
        //for(char16_t c : value) result.push_back(std::tolower(c, lc));
        for(char16_t c : value) result.push_back(c <= 0xFF ? static_cast<char16_t>(std::tolower(static_cast<char>(c), lc)) : c);
        return result;
      }
      static std::u32string to_lower(const std::u32string& value) {
        std::u32string result;
        std::locale lc = std::locale();
        //for(char32_t c : value) result.push_back(std::tolower(c, lc));
        for(char32_t c : value) result.push_back(c <= 0xFF ? static_cast<char32_t>(std::tolower(static_cast<char>(c), lc)) : c);
        return result;
      }
      static std::wstring to_lower(const std::wstring& value) {
        std::wstring result;
        std::locale lc = std::locale();
        for(wchar_t c : value) result.push_back(std::tolower(c, lc));
        return result;
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
