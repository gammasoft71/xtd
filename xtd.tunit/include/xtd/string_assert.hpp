/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "assert.hpp"
#include <locale>
#include <cstring>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The string_assert class contains a collection of static methods that implement the most string assertions used in xtd::tUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class string_assert final {
    public:
      /// @cond
      string_assert() = delete;
      /// @endcond
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("value")); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::string& expected, const std::string& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::string& expected, const std::string& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::string& expected, const std::string& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"value")); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u16string& expected, const std::u16string& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u16string& expected, const std::u16string& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u16string& expected, const std::u16string& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u16string& expected, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"value")); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u32string& expected, const std::u32string& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u32string& expected, const std::u32string& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u32string& expected, const std::u32string& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::u32string& expected, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"value")); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::wstring& expected, const std::wstring& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::wstring& expected, const std::wstring& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::wstring& expected, const std::wstring& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::wstring& expected, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}

      /// @cond
      static void are_equal(const char* expected, const char* actual) {are_equal(expected, actual, "", line_info());}
      static void are_equal(const char* expected, const char* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      static void are_equal(const char* expected, const char* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      static void are_equal(const char* expected, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}

      static void are_equal(const char16_t* expected, const char16_t* actual) {are_equal(expected, actual, "", line_info());}
      static void are_equal(const char16_t* expected, const char16_t* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      static void are_equal(const char16_t* expected, const char16_t* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      static void are_equal(const char16_t* expected, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}

      static void are_equal(const char32_t* expected, const char32_t* actual) {are_equal(expected, actual, "", line_info());}
      static void are_equal(const char32_t* expected, const char32_t* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      static void are_equal(const char32_t* expected, const char32_t* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      static void are_equal(const char32_t* expected, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}

      static void are_equal(const wchar_t* expected, const wchar_t* actual) {are_equal(expected, actual, "", line_info());}
      static void are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      static void are_equal(const wchar_t* expected, const wchar_t* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      static void are_equal(const wchar_t* expected, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(expected, actual, message, line_info);}
      /// @endcond
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::string& expected, const std::string& actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::string& expected, const std::string& actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::string& expected, const std::string& actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail(assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail(assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(U"value", std::u32string(U"vValuealue"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(U"key", std::u32string(U"Value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail(assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) == to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail(assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @cond
      static void are_equal_ingoring_case(const char* expected, const char* actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_equal_ingoring_case(const char* expected, const char* actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_equal_ingoring_case(const char* expected, const char* actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_equal_ingoring_case(const char* expected, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(std::string(expected), std::string(actual), message, line_info);}

      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(std::u16string(expected), std::u16string(actual), message, line_info);}

      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(std::u32string(expected), std::u32string(actual), message, line_info);}

      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(std::wstring(expected), std::wstring(actual), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("value")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::string& expected, const std::string& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::string& expected, const std::string& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::string& expected, const std::string& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"key", std::u16string(u"value")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u16string& expected, const std::u16string& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"vakeylue", std::u16string(u"value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u16string& expected, const std::u16string& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"key", std::u16string(u"value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u16string& expected, const std::u16string& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"key", std::u16string(u"value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u16string& expected, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"value")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u32string& expected, const std::u32string& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u32string& expected, const std::u32string& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u32string& expected, const std::u32string& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::u32string& expected, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"value")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"value")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::wstring& expected, const std::wstring& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"value"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"value"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::wstring& expected, const std::wstring& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"value"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"value"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::wstring& expected, const std::wstring& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"value"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::wstring& expected, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      
      /// @cond
      static void are_not_equal(const char* expected, const char* actual) {are_not_equal(expected, actual, "", line_info());}
      static void are_not_equal(const char* expected, const char* actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      static void are_not_equal(const char* expected, const char* actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      static void are_not_equal(const char* expected, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      
      static void are_not_equal(const char16_t* expected, const char16_t* actual) {are_not_equal(expected, actual, "", line_info());}
      static void are_not_equal(const char16_t* expected, const char16_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      static void are_not_equal(const char16_t* expected, const char16_t* actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      static void are_not_equal(const char16_t* expected, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      
      static void are_not_equal(const char32_t* expected, const char32_t* actual) {are_not_equal(expected, actual, "", line_info());}
      static void are_not_equal(const char32_t* expected, const char32_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      static void are_not_equal(const char32_t* expected, const char32_t* actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      static void are_not_equal(const char32_t* expected, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual) {are_not_equal(expected, actual, "", line_info());}
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_not_equal(expected, actual, message, line_info);}
      /// @endcond
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::string& expected, const std::string& actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::string& expected, const std::string& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::string& expected, const std::string& actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal("key", std::string("VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal("value", std::string("VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail("not " + assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"key", std::u16string(u"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"key", std::u16string(u"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"key", std::u16string(u"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(u"key", std::u16string(u"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(u"value", std::u16string(u"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail("not " + assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      
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
      static void are_not_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(U"key", std::u32string(U"vValuealue"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(U"value", std::u32string(U"Value"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::u32string& expected, const std::u32string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail("not " + assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"VALUE"), line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"VALUE"), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"VALUE"), "User message..."); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"VALUE"), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal ignoring case.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_not_equal(L"key", std::wstring(L"VALUE"), "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::are_not_equal(L"value", std::wstring(L"VALUE"), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (to_lower(actual) != to_lower(expected))
          assert::succeed(message, line_info);
        else
          assert::fail("not " + assert::to_string(expected), assert::to_string(actual), message, line_info);
      }
      
      /// @cond
      static void are_not_equal_ingoring_case(const char* expected, const char* actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ingoring_case(const char* expected, const char* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ingoring_case(const char* expected, const char* actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ingoring_case(const char* expected, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(std::string(expected), std::string(actual), message, line_info);}
      
      static void are_not_equal_ingoring_case(const char16_t* expected, const char16_t* actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(std::u16string(expected), std::u16string(actual), message, line_info);}
      
      static void are_not_equal_ingoring_case(const char32_t* expected, const char32_t* actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(std::u32string(expected), std::u32string(actual), message, line_info);}
      
      static void are_not_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual) {are_not_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_not_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_not_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message) {are_not_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_not_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_not_equal_ingoring_case(std::wstring(expected), std::wstring(actual), message, line_info);}
      /// @endcond
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains('a', s); // test ok.
      /// xtd::tunit::string_assert::contains('z', s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char item, const std::string& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains('a', s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains('z', s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char item, const std::string& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains('a', s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains('z', s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char item, const std::string& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s = "value";
      /// xtd::tunit::string_assert::contains('a', s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains('z', s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char item, const std::string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(string.begin(), string.end(), item);
        if (result != string.end())
          assert::succeed(message, line_info);
        else
          assert::fail("string containing " + assert::to_string(item), "< " + __join__items(string) + " >", message, line_info);
      }
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u'a', s); // test ok.
      /// xtd::tunit::string_assert::contains(u'z', s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char16_t item, const std::u16string& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u'a', s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(u'z', s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char16_t item, const std::u16string& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u'a', s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(u'z', s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char16_t item, const std::u16string& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u16string s = u"value";
      /// xtd::tunit::string_assert::contains(u'a', s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(u'z', s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char16_t item, const std::u16string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(string.begin(), string.end(), item);
        if (result != string.end())
          assert::succeed(message, line_info);
        else
          assert::fail("string containing " + assert::to_string(item), "< " + __join__items(string) + " >", message, line_info);
      }
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U'a', s); // test ok.
      /// xtd::tunit::string_assert::contains(U'z', s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char32_t item, const std::u32string& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U'a', s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(U'z', s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char32_t item, const std::u32string& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U'a', s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(U'z', s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char16_t item, const std::u32string& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::u32string s = U"value";
      /// xtd::tunit::string_assert::contains(U'a', s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(U'z', s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(char32_t item, const std::u32string& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(string.begin(), string.end(), item);
        if (result != string.end())
          assert::succeed(message, line_info);
        else
          assert::fail("string containing " + assert::to_string(item), "< " + __join__items(string) + " >", message, line_info);
      }
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L'a', s); // test ok.
      /// xtd::tunit::string_assert::contains(L'z', s); // test throws an assertion_error exception.
      /// @endcode
      static void contains(wchar_t item, const std::wstring& string) {contains(item, string, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L'a', s, line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(L'z', s, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(wchar_t item, const std::wstring& string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L'a', s, "User message..."); // test ok.
      /// xtd::tunit::string_assert::contains(L'z', s, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void contains(wchar_t item, const std::wstring& string, const std::string& message) {contains(item, string, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::wstring s = L"value";
      /// xtd::tunit::string_assert::contains(L'a', s, "User message...", line_info_); // test ok.
      /// xtd::tunit::string_assert::contains(L'z', s, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void contains(wchar_t item, const std::wstring& string, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(string.begin(), string.end(), item);
        if (result != string.end())
          assert::succeed(message, line_info);
        else
          assert::fail("string containing " + assert::to_string(item), "< " + __join__items(string) + " >", message, line_info);
      }

      /// @cond
      static void contains(char item, const char* string) {contains(item, string, "", line_info());}
      static void contains(char item, const char* string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      static void contains(char item, const char* string, const std::string& message) {contains(item, string, message, line_info());}
      static void contains(char item, const char* string, const std::string& message, const xtd::tunit::line_info& line_info) {contains(item, std::string(string), message, line_info);}

      static void contains(char16_t item, const char16_t* string) {contains(item, string, "", line_info());}
      static void contains(char16_t item, const char16_t* string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      static void contains(char16_t item, const char16_t* string, const std::string& message) {contains(item, string, message, line_info());}
      static void contains(char16_t item, const char16_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {contains(item, std::u16string(string), message, line_info);}

      static void contains(char32_t item, const char32_t* string) {contains(item, string, "", line_info());}
      static void contains(char32_t item, const char32_t* string, const xtd::tunit::line_info& line_info) {contains(item, string, "", line_info);}
      static void contains(char32_t item, const char32_t* string, const std::string& message) {contains(item, string, message, line_info());}
      static void contains(char32_t item, const char32_t* string, const std::string& message, const xtd::tunit::line_info& line_info) {contains(item, std::u32string(string), message, line_info);}
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
