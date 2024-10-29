/// @file
/// @brief Contains xtd::tunit::assert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "base_assert.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <exception>
#include <functional>
#include <iterator>
#include <memory>
#include <string>

/// @cond
#ifdef assert
#undef assert
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The assert class contains a collection of static methods that implement the most common assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class assert final : public base_assert {
    public:
      /// @cond
      assert() = delete;
      /// @endcond
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24)); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), csf_); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), "User message...", csf_); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (actual == expected)
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @cond
      static void are_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (strcmp(actual, expected) == 0)
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      static void are_equal(const char8_t* expected, const char8_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (ustring(actual) == ustring(expected))
          succeed(message, stack_frame);
        else
          base_assert::base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      static void are_equal(const char16_t* expected, const char16_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u16string(actual) == std::u16string(expected))
          succeed(message, stack_frame);
        else
          base_assert::base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      static void are_equal(const char32_t* expected, const char32_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u32string(actual) == std::u32string(expected))
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }

      static void are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (wcscmp(actual, expected) == 0)
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }

      static void are_equal(float expected, float actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::isnan(actual) && std::isnan(expected))
          succeed(message, stack_frame);
        else if (actual == expected)
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      static void are_equal(double expected, double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::isnan(actual) && std::isnan(expected))
          succeed(message, stack_frame);
        else if (actual == expected)
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      static void are_equal(long double expected, long double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::isnan(actual) && std::isnan(expected))
          succeed(message, stack_frame);
        else if (actual == expected)
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance) {are_equal(expected, actual, tolerance, "", csf_);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f, csf_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, tolerance, "", stack_frame);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f, "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float& actual, float tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.0000000000001f, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008f, f, 0.00000000000001f, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (fabsf(expected - actual) <= fabsf(tolerance))
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance) {are_equal(expected, actual, tolerance, "", csf_);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001, csf_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, tolerance, "", stack_frame);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001, "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.0000000000001, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008, d, 0.00000000000001, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (fabs(expected - actual) <= fabs(tolerance))
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance) {are_equal(expected, actual, tolerance, "", csf_);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l, csf_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, tolerance, "", stack_frame);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l, "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.0000000000001l, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::are_equal_(0.00008l, ld, 0.00000000000001l, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (fabsl(expected - actual) <= fabsl(tolerance))
          succeed(message, stack_frame);
        else
          base_assert::fail(base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24)); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), csf_); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message..."); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message...", csf_); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (actual != expected)
          succeed(message, stack_frame);
        else
          base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }

      /// @cond
      static void are_not_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (strcmp(actual, expected) != 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }

      static void are_not_equal(const char8_t* expected, const char8_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (ustring(actual) != ustring(expected))
          succeed(message, stack_frame);
        else
          base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }

      static void are_not_equal(const char16_t* expected, const char16_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u16string(actual) != std::u16string(expected))
          succeed(message, stack_frame);
        else
          base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }

      static void are_not_equal(const char32_t* expected, const char32_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u32string(actual) != std::u32string(expected))
          succeed(message, stack_frame);
        else
          base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (wcscmp(actual, expected) != 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("not " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      /// @endcond

      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual) {are_not_same(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, csf_); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, stack_frame); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_same(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message..."); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_not_same(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, "User message...", stack_frame); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (&actual != &expected)
          succeed(message, stack_frame);
        else
          base_assert::fail("not same as " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a); // test ok.
      /// xtd::tunit::assert::are_same(c, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual) {are_same(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, csf_); // test ok.
      /// xtd::tunit::assert::are_same(c, a, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_same(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message..."); // test ok.
      /// xtd::tunit::assert::are_same(c, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_same(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::are_same(c, a, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (&actual == &expected)
          succeed(message, stack_frame);
        else
          base_assert::fail("same as " + base_assert::to_string(expected), base_assert::to_string(actual), message, stack_frame);
      }
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1); // test ok.
      /// xtd::tunit::assert::contains(4, v1); // test throws an assertion_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection) {contains(item, collection, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, csf_); // test ok.
      /// xtd::tunit::assert::contains(4, v1, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame) {contains(item, collection, "", stack_frame);}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message..."); // test ok.
      /// xtd::tunit::assert::contains(4, v1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::ustring& message) {contains(item, collection, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::contains(4, v1, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        auto result = std::find(collection.begin(), collection.end(), item);
        if (result != collection.end())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(collection), message, stack_frame);
      }
      
      /// @cond
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values) {contains(item, values, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::diagnostics::stack_frame& stack_frame) {contains(item, values, "", stack_frame);}
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::ustring& message) {contains(item, values, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        auto result = std::find(values.begin(), values.end(), item);
        if (result != values.end())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(values), message, stack_frame);
      }
      
      static void contains(char item, const char* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        ustring s(values);
        auto result = std::find(s.begin(), s.end(), item);
        if (result != s.end())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
      }
      
      static void contains(char8_t item, const char8_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::u8string s(values);
        auto result = std::find(s.begin(), s.end(), item);
        if (result != s.end())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
      }

      static void contains(char16_t item, const char16_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::u16string s(values);
        auto result = std::find(s.begin(), s.end(), item);
        if (result != s.end())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
      }
      
      static void contains(char32_t item, const char32_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::u32string s(values);
        auto result = std::find(s.begin(), s.end(), item);
        if (result != s.end())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
      }

      static void contains(wchar_t item, const wchar_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::wstring s(values);
        auto result = std::find(s.begin(), s.end(), item);
        if (result != s.end())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection containing " + base_assert::to_string(item), base_assert::join_items(s), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement) {does_not_throw(statement, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, csf_); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {does_not_throw(statement, "", stack_frame);}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, "User message..."); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::ustring& message) {does_not_throw(statement, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          statement();
          succeed(message, stack_frame);
        } catch (const std::exception& e) {
          base_assert::fail("No Exception to be thrown", "<" + __tunit_demangle(typeid(e).name()) + ">", message, stack_frame);
        } catch (...) {
          base_assert::fail("No Exception to be thrown", "<exception>", message, stack_frame);
        }
      }
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1); // test ok.
      /// xtd::tunit::assert::is_empty(v2); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value) {is_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_empty(value, "", stack_frame);}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::ustring& message) {is_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::empty(value))
          succeed(message, stack_frame);
        else
          base_assert::fail("collection <empty>", base_assert::join_items(value), message, stack_frame);
      }
      
      /// @cond
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value) {is_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame) {is_empty(value, "", stack_frame);}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const xtd::ustring& message) {is_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::empty(values))
          succeed(message, stack_frame);
        else
          base_assert::fail("collection <empty>", base_assert::join_items(values), message, stack_frame);
      }
      
      static void is_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        ustring s(value);
        if (s.is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
      }
      
      static void is_empty(const char8_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        ustring s(value);
        if (s.is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
      }

      static void is_empty(const char16_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        ustring s(value);
        if (s.is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
      }
      
      static void is_empty(const char32_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        ustring s(value);
        if (s.is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
      }

      static void is_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        ustring s(value);
        if (s.is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection <empty>", base_assert::join_items(s), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that ta condition is false.
      /// @param condition The condition to check is false.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2)); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition) {is_false(condition, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), csf_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {is_false(condition, "", stack_frame);}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::ustring& message) {is_false(condition, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (condition == false)
          succeed(message, stack_frame);
        else
          base_assert::fail("false", "true", message, stack_frame);
      }
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2) {is_greater(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12, csf_); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_greater(val1, val2, "", stack_frame);}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_greater(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater(24, 12, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_greater(24, 48, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (val1 > val2)
          succeed(message, stack_frame);
        else
          base_assert::fail("greater than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      
      /// @cond
      static void is_greater(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (strcmp(val1, val2) > 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      
      static void is_greater(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (ustring(val1) > ustring(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      
      static void is_greater(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u16string(val1) > std::u16string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_greater(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u32string(val1) > std::u32string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_greater(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (wcscmp(val1, val2) > 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      /// @endcond

      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2) {is_greater_or_equal(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12, csf_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24, csf_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_greater_or_equal(val1, val2, "", stack_frame);}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_greater_or_equal(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_greater_or_equal(24, 12, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 24, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_greater_or_equal(24, 48, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (val1 >= val2)
          succeed(message, stack_frame);
        else
          base_assert::fail("greater than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      
      /// @cond
      static void is_greater_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (strcmp(val1, val2) >= 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_greater_or_equal(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (ustring(val1) >= ustring(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_greater_or_equal(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u16string(val1) >= std::u16string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_greater_or_equal(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u32string(val1) >= std::u32string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (wcscmp(val1, val2) >= 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      /// @endcond

      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value) {is_instance_of<type_t>(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, csf_); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, csf_); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_instance_of<type_t>(value, "", stack_frame);}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::ustring& message) {is_instance_of<type_t>(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, "User message...", csf_); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        const type_t* instance = dynamic_cast<const type_t*>(&value);
        if (instance != nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("instance of <" + __tunit_demangle(typeid(type_t).name()) + ">", "<" + __tunit_demangle(typeid(value).name()) + ">", message, stack_frame);
      }
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48); // test ok.
      /// xtd::tunit::assert::is_less(24, 12); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2) {is_less(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48, csf_); // test ok.
      /// xtd::tunit::assert::is_less(24, 12, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_less(val1, val2, "", stack_frame);}
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assert::is_less(24, 12, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_less(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less(24, 48, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_less(24, 12, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (val1 < val2)
          succeed(message, stack_frame);
        else {
          base_assert::fail("less than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
        }
      }
      
      /// @cond
      static void is_less(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (strcmp(val1, val2) < 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("less than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (ustring(val1) < ustring(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u16string(val1) < std::u16string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u32string(val1) < std::u32string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (wcscmp(val1, val2) < 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("less than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      /// @endcond

      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2) {is_less_or_equal(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48, csf_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24, csf_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_less_or_equal(val1, val2, "", stack_frame);}
      
      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_less_or_equal(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_less_or_equal(24, 48, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 24, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_less_or_equal(24, 12, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (val1 <= val2)
          succeed(message, stack_frame);
        else
          base_assert::fail("less than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      
      /// @cond
      static void is_less_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (strcmp(val1, val2) <= 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("less than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less_or_equal(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (ustring(val1) < ustring(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less_or_equal(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u16string(val1) < std::u16string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less_or_equal(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::u32string(val1) < std::u32string(val2))
          succeed(message, stack_frame);
        else
          base_assert::fail("greather than " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }

      static void is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (wcscmp(val1, val2) <= 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("less than or equal to " + base_assert::to_string(val2), base_assert::to_string(val1), message, stack_frame);
      }
      /// @endcond

      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value) {is_NaN(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::diagnostics::stack_frame& stack_frame) {is_NaN(value, "", stack_frame);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::ustring& message) {is_NaN(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::isnan(value))
          succeed(message, stack_frame);
        else
          base_assert::fail("NaN", base_assert::to_string(value), message, stack_frame);
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value) {is_NaN(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value, const xtd::diagnostics::stack_frame& stack_frame) {is_NaN(value, "", stack_frame);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value, const xtd::ustring& message) {is_NaN(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(long double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::isnan(value))
          succeed(message, stack_frame);
        else
          base_assert::fail("NaN", base_assert::to_string(value), message, stack_frame);
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value) {is_NaN(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::diagnostics::stack_frame& stack_frame) {is_NaN(value, "", stack_frame);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::ustring& message) {is_NaN(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::isnan(value))
          succeed(message, stack_frame);
        else
          base_assert::fail("NaN", base_assert::to_string(value), message, stack_frame);
      }
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1); // test ok.
      /// xtd::tunit::assert::is_negative(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value) {is_negative(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1, csf_); // test ok.
      /// xtd::tunit::assert::is_negative(i2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_negative(value, "", stack_frame);}
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_negative(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::ustring& message) {is_negative(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assert::is_negative(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_negative(i2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (value < 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("negative", base_assert::to_string(value), message, stack_frame);
      }
      
      /// @brief Asserts that collection oes not contain any item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value) {is_not_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_empty(value, "", stack_frame);}
      
      /// @brief Asserts that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::ustring& message) {is_not_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (!std::empty(value))
          succeed(message, stack_frame);
        else
          base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
      }
      
      /// @cond
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value) {is_not_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_empty(value, "", stack_frame);}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::ustring& message) {is_not_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (!std::empty(value))
          succeed(message, stack_frame);
        else
          base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
      }
      
      static void is_not_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (!ustring(value).is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
      }
      
      static void is_not_empty(const char8_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (!ustring(value).is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
      }
      
      static void is_not_empty(const char16_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (!ustring(value).is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
      }
      
      static void is_not_empty(const char32_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (!ustring(value).is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
      }

      static void is_not_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (!ustring(value).is_empty())
          succeed(message, stack_frame);
        else
          base_assert::fail("collection not <empty>", "<empty>", message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value) {is_not_instance_of<type_t>(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, csf_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, csf_); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_instance_of<type_t>(value, "", stack_frame);}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::ustring& message) {is_not_instance_of<type_t>(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, "User message...", csf_); test throws an assertion_error exception.
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (dynamic_cast<const type_t*>(&value) == nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("not instance of <" + __tunit_demangle(typeid(type_t).name()) + ">", "<" + __tunit_demangle(typeid(value).name()) + ">", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (pointer != nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("not null", "null", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (pointer != nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("not null", "null", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (pointer != nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("not null", "null", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, csf_); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", csf_); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {succeed(message, stack_frame);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {base_assert::fail("not null", "null", message, stack_frame);}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value) {is_not_zero(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1, csf_); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_zero(value, "", stack_frame);}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::ustring& message) {is_not_zero(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assert::is_not_zero(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_zero(i2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (value != 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("not zero", "0", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, csf_); // test ok.
      /// xtd::tunit::assert::is_null(s2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (pointer == nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("null", "not null", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, csf_); // test ok.
      /// xtd::tunit::assert::is_null(s2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (pointer == nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("null", "not null", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, csf_); // test ok.
      /// xtd::tunit::assert::is_null(s2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (pointer == nullptr)
          succeed(message, stack_frame);
        else
          base_assert::fail("null", "not null", message, stack_frame);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, csf_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, "User message...", csf_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {base_assert::fail("null", "not null", message, stack_frame);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, csf_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, "User message..."); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a std::nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, "User message...", csf_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {succeed(message, stack_frame);}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1); // test ok.
      /// xtd::tunit::assert::is_positive(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value) {is_positive(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1, csf_); // test ok.
      /// xtd::tunit::assert::is_positive(i2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_positive(value, "", stack_frame);}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_positive(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::ustring& message) {is_positive(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assert::is_positive(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_positive(i2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (value > 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("positive", base_assert::to_string(value), message, stack_frame);
      }
      
      /// @brief Asserts that ta condition is true.
      /// @param condition The condition to check is true.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2)); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition) {is_true(condition, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), csf_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {is_true(condition, "", stack_frame);}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::ustring& message) {is_true(condition, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (condition == true)
          succeed(message, stack_frame);
        else
          base_assert::fail("true", "false", message, stack_frame);
      }
      
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1); // test ok.
      /// xtd::tunit::assert::is_zero(i2); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value) {is_zero(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1, csf_); // test ok.
      /// xtd::tunit::assert::is_zero(i2, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_zero(value, "", stack_frame);}
      
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_zero(i2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::ustring& message) {is_zero(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assert::is_zero(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_zero(i2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (value == 0)
          succeed(message, stack_frame);
        else
          base_assert::fail("zero", base_assert::to_string(value), message, stack_frame);
      }
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}); // test throws an assertion_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement) {throws<exception_t>(statement, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, csf_); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {throws<exception_t>(statement, "", stack_frame);}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::ustring& message) {throws<exception_t>(statement, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          statement();
          base_assert::fail("<"  + __tunit_demangle(typeid(exception_t).name()) + ">", "<nothing>", message, stack_frame);
        } catch (const exception_t&) {
          succeed(message, stack_frame);
        } catch (const xtd::tunit::assert_error&) {
          throw;
        } catch (const std::exception& e) {
          base_assert::fail("<"  + __tunit_demangle(typeid(exception_t).name()) + ">", "<" + __tunit_demangle(typeid(e).name()) + ">", message, stack_frame);
        } catch (...) {
          base_assert::fail("<"  + __tunit_demangle(typeid(exception_t).name()) + ">", "<exception>", message, stack_frame);
        }
      }
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement) {throws_any(statement, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, csf_); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {throws_any(statement, "", stack_frame);}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::ustring& message) {throws_any(statement, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          statement();
          base_assert::fail("<exception>", "<nothing>", message, stack_frame);
        } catch (const xtd::tunit::assert_error&) {
          throw;
        } catch (...) {
          succeed(message, stack_frame);
        }
      }
      
    private:
    };
  }
}

/// @cond
#define __CMD_ASSERT_0_ARGS__(cmd) cmd(csf_)
#define __CMD_ASSERT_1_ARGS__(cmd, arg1) cmd(arg1, csf_)
#define __CMD_ASSERT_2_ARGS__(cmd, arg1, arg2) cmd(arg1, arg2, csf_)
#define __CMD_ASSERT_3_ARGS__(cmd, arg1, arg2, arg3) cmd(arg1, arg2, arg3, csf_)
#define __CMD_ASSERT_4_ARGS__(cmd, arg1, arg2, arg3, arg4) cmd(arg1, arg2, arg3, arg4, csf_)
#define __CMD_ASSERT_5_ARGS__(cmd, arg1, arg2, arg3, arg4) cmd(arg1, arg2, arg3, arg4, arg5, csf_)
#define __GET_LAST_ARG(arg1, arg2, arg3, arg4, arg5, arg6, ...) arg6
#define __CMD_ASSERT_MACRO_CHOOSER(cmd, ...) __GET_LAST_ARG(__VA_ARGS__, __CMD_ASSERT_5_ARGS__, __CMD_ASSERT_4_ARGS__, __CMD_ASSERT_3_ARGS__, __CMD_ASSERT_2_ARGS__, __CMD_ASSERT_1_ARGS__, __CMD_ASSERT_0_ARGS__, )
#define __CMD_ASSERT_ARGS(cmd, ...) __CMD_ASSERT_MACRO_CHOOSER(cmd, __VA_ARGS__)(cmd, __VA_ARGS__)
/// @endcond

#define abort_() abort(csf_)

#define are_equal_(...) __CMD_ASSERT_ARGS(are_equal, __VA_ARGS__)

#define are_not_equal_(...) __CMD_ASSERT_ARGS(are_not_equal, __VA_ARGS__)

#define are_not_same_(...) __CMD_ASSERT_ARGS(are_not_same, __VA_ARGS__)

#define are_same_(...) __CMD_ASSERT_ARGS(are_same, __VA_ARGS__)

#define contains_(...) __CMD_ASSERT_ARGS(contains, __VA_ARGS__)

#define does_not_throw_(...) __CMD_ASSERT_ARGS(does_not_throw, __VA_ARGS__)

#define fail_() base_assert::fail(csf_)

#define ignore_() ignore(csf_)

#define is_empty_(...) __CMD_ASSERT_ARGS(is_empty, __VA_ARGS__)

#define is_false_(...) __CMD_ASSERT_ARGS(is_false, __VA_ARGS__)

#define is_greater_(...) __CMD_ASSERT_ARGS(is_greater, __VA_ARGS__)

#define is_greater_or_equal_(...) __CMD_ASSERT_ARGS(is_greater_or_equal, __VA_ARGS__)

#define is_instance_of_(type_t, ...) __CMD_ASSERT_ARGS(is_instance_of<type_t>, __VA_ARGS__)

#define is_less_(...) __CMD_ASSERT_ARGS(is_less, __VA_ARGS__)

#define is_less_or_equal_(...) __CMD_ASSERT_ARGS(is_less_or_equal, __VA_ARGS__)

#define is_NaN_(...) __CMD_ASSERT_ARGS(is_NaN, __VA_ARGS__)

#define is_negative_(...) __CMD_ASSERT_ARGS(is_negative, __VA_ARGS__)

#define is_not_empty_(...) __CMD_ASSERT_ARGS(is_not_empty, __VA_ARGS__)

#define is_not_instance_of_(type_t, ...) __CMD_ASSERT_ARGS(is_not_instance_of<type_t>, __VA_ARGS__)

#define is_not_null_(...) __CMD_ASSERT_ARGS(is_not_null, __VA_ARGS__)

#define is_not_zero_(...) __CMD_ASSERT_ARGS(is_not_zero, __VA_ARGS__)

#define is_null_(...) __CMD_ASSERT_ARGS(is_null, __VA_ARGS__)

#define is_positive_(...) __CMD_ASSERT_ARGS(is_positive, __VA_ARGS__)

#define is_true_(...) __CMD_ASSERT_ARGS(is_true, __VA_ARGS__)

#define is_zero_(...) __CMD_ASSERT_ARGS(is_zero, __VA_ARGS__)

#define succeed_() succeed(csf_)

#define throws_(exception_t, ...) __CMD_ASSERT_ARGS(throws<exception_t>, __VA_ARGS__)

#define throws_any_(...) __CMD_ASSERT_ARGS(throws_any, __VA_ARGS__)
