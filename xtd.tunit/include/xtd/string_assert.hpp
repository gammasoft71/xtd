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
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal("value", std::string("VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal("key", std::string("VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::string& expected, const std::string& actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(u"value", std::u16string(u"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal(u"key", std::u16string(u"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::u16string& expected, const std::u16string& actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::string_assert::are_equal(L"value", std::wstring(L"VALUE")); // test ok.
      /// xtd::tunit::string_assert::are_equal(L"key", std::wstring(L"VALUE")); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal_ingoring_case(const std::wstring& expected, const std::wstring& actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      
      /// @brief Asserts that two type are equal.
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
      static void are_equal_ingoring_case(const char* expected, const char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(to_lower(std::string(expected)), to_lower(std::string(actual)), message, line_info);}

      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_equal_ingoring_case(const char16_t* expected, const char16_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(to_lower(std::u16string(expected)), to_lower(std::u16string(actual)), message, line_info);}

      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_equal_ingoring_case(const char32_t* expected, const char32_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(to_lower(std::u32string(expected)), to_lower(std::u32string(actual)), message, line_info);}

      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual) {are_equal_ingoring_case(expected, actual, "", line_info());}
      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const xtd::tunit::line_info& line_info) {are_equal_ingoring_case(expected, actual, "", line_info);}
      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message) {are_equal_ingoring_case(expected, actual, message, line_info());}
      static void are_equal_ingoring_case(const wchar_t* expected, const wchar_t* actual, const std::string& message, const xtd::tunit::line_info& line_info) {assert::are_equal(to_lower(std::wstring(expected)), to_lower(std::wstring(actual)), message, line_info);}
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
