/// @file
/// @brief Contains xtd::tunit::assume class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The assume class contains a collection of static methods that implement the most common assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assume.cpp
    class assume final : private base_assert {
    public:
      /// @cond
      assume() = delete;
      /// @endcond
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_equal(24, int(24)); // test ok.
      /// xtd::tunit::assume::are_equal(23, int(24)); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_equal(24, int(24), csf_); // test ok.
      /// xtd::tunit::assume::are_equal(23, int(24), csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_equal(24, int(24), "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal(23, int(24), "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_equal(24, int(24), "User message...", csf_); // test ok.
      /// xtd::tunit::assume::are_equal(23, int(24), "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void are_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try{
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_equal(const char8_t* expected, const char8_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try{
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_equal(const char16_t* expected, const char16_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_equal(const char32_t* expected, const char32_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void are_equal(float expected, float actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_equal(double expected, double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_equal(long double expected, long double actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.0000000000001f); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.00000000000001f); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance) {are_equal(expected, actual, tolerance, "", csf_);}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.0000000000001f, csf_); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.00000000000001f, csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, tolerance, "", stack_frame);}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.0000000000001f, "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.00000000000001f, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(float expected, float& actual, float tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.0000000000001f, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.00000000000001f, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(float expected, float actual, float tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, tolerance, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.0000000000001); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.00000000000001); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance) {are_equal(expected, actual, tolerance, "", csf_);}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.0000000000001, csf_); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.00000000000001, csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, tolerance, "", stack_frame);}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.0000000000001, "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.00000000000001, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double d = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.0000000000001, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.00000000000001, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(double expected, double actual, double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, tolerance, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.0000000000001l); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.00000000000001l); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance) {are_equal(expected, actual, tolerance, "", csf_);}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.0000000000001l, csf_); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.00000000000001l, csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, tolerance, "", stack_frame);}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.0000000000001l, "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.00000000000001l, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message) {are_equal(expected, actual, tolerance, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.0000000000001l, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.00000000000001l, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_equal(expected, actual, tolerance, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_not_equal(23, int(24)); // test ok.
      /// xtd::tunit::assume::are_not_equal(24, int(24)); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_not_equal(23, int(24), csf_); // test ok.
      /// xtd::tunit::assume::are_not_equal(24, int(24), csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      
      /// @brief Assumes that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_not_equal(23, int(24), "User message..."); // test ok.
      /// xtd::tunit::assume::are_not_equal(24, int(24), "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::are_not_equal(23, int(24), "User message...", csf_); // test ok.
      /// xtd::tunit::assume::are_not_equal(24, int(24), "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      /// @cond
      static void are_not_equal(const char* expected, const char* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_not_equal(const char8_t* expected, const char8_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_not_equal(const char16_t* expected, const char16_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_not_equal(const char32_t* expected, const char32_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond

      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_not_same(c, a); // test ok.
      /// xtd::tunit::assume::are_not_same(b, a); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual) {are_not_same(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_not_same(c, a, csf_); // test ok.
      /// xtd::tunit::assume::are_not_same(b, a, stack_frame); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_same(expected, actual, "", stack_frame);}
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_not_same(c, a, "User message..."); // test ok.
      /// xtd::tunit::assume::are_not_same(b, a, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_not_same(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_not_same(c, a, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::are_not_same(b, a, "User message...", stack_frame); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_not_same(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_same(b, a); // test ok.
      /// xtd::tunit::assume::are_same(c, a); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual) {are_same(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_same(b, a, csf_); // test ok.
      /// xtd::tunit::assume::are_same(c, a, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_same(expected, actual, "", stack_frame);}
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_same(b, a, "User message..."); // test ok.
      /// xtd::tunit::assume::are_same(c, a, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message) {are_same(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assume::are_same(b, a, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::are_same(c, a, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::are_same(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assume::contains(2, v1); // test ok.
      /// xtd::tunit::assume::contains(4, v1); // test throws an abort_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection) {contains(item, collection, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assume::contains(2, v1, csf_); // test ok.
      /// xtd::tunit::assume::contains(4, v1, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame) {contains(item, collection, "", stack_frame);}
      
      /// @brief Assumes that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assume::contains(2, v1, "User message..."); // test ok.
      /// xtd::tunit::assume::contains(4, v1, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::ustring& message) {contains(item, collection, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assume::contains(2, v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::contains(4, v1, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::contains(item, collection, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
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
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void contains(char item, const char* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void contains(char8_t item, const char8_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void contains(char16_t item, const char16_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void contains(char32_t item, const char32_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void contains(wchar_t item, const wchar_t* values, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(2);}); // test ok.
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(5);}); // test throws an abort_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement) {does_not_throw(statement, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(2);}, csf_); // test ok.
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(5);}, csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {does_not_throw(statement, "", stack_frame);}
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(2);}, "User message..."); // test ok.
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(5);}, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::ustring& message) {does_not_throw(statement, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(2);}, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(5);}, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::does_not_throw(statement, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
     
      /// @brief Assumes that collection contains an item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assume::is_empty(v1); // test ok.
      /// xtd::tunit::assume::is_empty(v2); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value) {is_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that collection contains an item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assume::is_empty(v1, csf_); // test ok.
      /// xtd::tunit::assume::is_empty(v2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_empty(value, "", stack_frame);}
      
      /// @brief Assumes that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assume::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_empty(v2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::ustring& message) {is_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assume::is_empty(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_empty(v2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
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
        try {
          assert::is_empty(values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_empty(const char8_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_empty(const char16_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_empty(const char32_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endocnd
      
      /// @brief Assumes that ta condition is false.
      /// @param condition The condition to check is false.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assume::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2)); // test throws an abort_error exception.
      /// @endcode
      static void is_false(bool condition) {is_false(condition, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that a condition is false.
      /// @param condition The condition to check is false.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assume::is_false(std::empty(s1), csf_); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {is_false(condition, "", stack_frame);}
      
      /// @brief Assumes that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assume::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::ustring& message) {is_false(condition, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assume::is_false(std::empty(s1), "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_false(condition, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater(24, 12); // test ok.
      /// xtd::tunit::assume::is_greater(24, 48); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2) {is_greater(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater(24, 12, csf_); // test ok.
      /// xtd::tunit::assume::is_greater(24, 48, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_greater(val1, val2, "", stack_frame);}
      
      /// @brief Assumes that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assume::is_greater(24, 48, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_greater(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater(24, 12, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_greater(24, 48, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_greater(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_greater(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_greater(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_greater(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_greater(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond

      /// @brief Assumes that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater_or_equal(24, 12); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 24); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 48); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2) {is_greater_or_equal(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater_or_equal(24, 12, csf_); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 24, csf_); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 48, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_greater_or_equal(val1, val2, "", stack_frame);}
      
      /// @brief Assumes that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater_or_equal(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 48, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_greater_or_equal(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_greater_or_equal(24, 12, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 24, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 48, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_greater_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_greater_or_equal(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_greater_or_equal(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_greater_or_equal(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond

      /// @brief Assumes that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_instance_of<std::logic_error>(except); // test ok.
      /// xtd::tunit::assume::is_instance_of<std::bad_cast>(except); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value) {is_instance_of<type_t>(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_instance_of<std::logic_error>(except, csf_); // test ok.
      /// xtd::tunit::assume::is_instance_of<std::bad_cast>(except, csf_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_instance_of<type_t>(value, "", stack_frame);}
      
      /// @brief Assumes that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_instance_of<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::assume::is_instance_of<std::bad_cast>(except, "User message..."); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::ustring& message) {is_instance_of<type_t>(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_instance_of<std::logic_error>(except, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_instance_of<std::bad_cast>(except, "User message...", csf_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_instance_of<type_t>(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less(24, 48); // test ok.
      /// xtd::tunit::assume::is_less(24, 12); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2) {is_less(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less(24, 48, csf_); // test ok.
      /// xtd::tunit::assume::is_less(24, 12, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_less(val1, val2, "", stack_frame);}
      
      /// @brief Assumes that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assume::is_less(24, 12, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_less(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less(24, 48, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_less(24, 12, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_less(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond

      /// @brief Assumes that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less_or_equal(24, 48); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 24); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 12); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2) {is_less_or_equal(val1, val2, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less_or_equal(24, 48, csf_); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 24, csf_); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 12, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame) {is_less_or_equal(val1, val2, "", stack_frame);}
      
      /// @brief Assumes that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less_or_equal(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 12, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message) {is_less_or_equal(val1, val2, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_less_or_equal(24, 48, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 24, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 12, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_less_or_equal(const char* val1, const char* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less_or_equal(const char8_t* val1, const char8_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less_or_equal(const char16_t* val1, const char16_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less_or_equal(const char32_t* val1, const char32_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond

      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1); // test ok.
      /// xtd::tunit::assume::is_NaN(v2); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(double value) {is_NaN(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, csf_); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::diagnostics::stack_frame& stack_frame) {is_NaN(value, "", stack_frame);}
      
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::ustring& message) {is_NaN(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_NaN(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assume::is_NaN(v1); // test ok.
      /// xtd::tunit::assume::is_NaN(v2); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(long double value) {is_NaN(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assume::is_NaN(v1, csf_); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(long double value, const xtd::diagnostics::stack_frame& stack_frame) {is_NaN(value, "", stack_frame);}
      
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assume::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(long double value, const xtd::ustring& message) {is_NaN(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assume::is_NaN(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(long double value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_NaN(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1); // test ok.
      /// xtd::tunit::assume::is_NaN(v2); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(float value) {is_NaN(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, csf_); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::diagnostics::stack_frame& stack_frame) {is_NaN(value, "", stack_frame);}
      
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::ustring& message) {is_NaN(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_NaN(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that ta condition is negative.
      /// @param value The value to check is negative.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assume::is_negative(i1); // test ok.
      /// xtd::tunit::assume::is_negative(i2); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value) {is_negative(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assume::is_negative(i1, csf_); // test ok.
      /// xtd::tunit::assume::is_negative(i2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_negative(value, "", stack_frame);}
      
      /// @brief Assumes that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assume::is_negative(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_negative(i2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::ustring& message) {is_negative(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assume::is_negative(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_negative(i2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_negative(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that collection oes not contain any item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assume::is_not_empty(v1); // test ok.
      /// xtd::tunit::assume::is_not_empty(v2); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value) {is_not_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assume::is_not_empty(v1, csf_); // test ok.
      /// xtd::tunit::assume::is_not_empty(v2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_empty(value, "", stack_frame);}
      
      /// @brief Assumes that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assume::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_empty(v2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::ustring& message) {is_not_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assume::is_not_empty(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_not_empty(v2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
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
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_not_empty(const char* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_not_empty(const char8_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_not_empty(const char16_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      static void is_not_empty(const char32_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }

      static void is_not_empty(const wchar_t* value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @endcond
      
      /// @brief Assumes that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_not_instance_of<std::bad_cast>(except); // test ok.
      /// xtd::tunit::assume::is_not_instance_of<std::logic_error>(except); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value) {is_not_instance_of<type_t>(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_not_instance_of<std::bad_cast>(except, csf_); // test ok.
      /// xtd::tunit::assume::is_not_instance_of<std::logic_error>(except, csf_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_instance_of<type_t>(value, "", stack_frame);}
      
      /// @brief Assumes that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_not_instance_of<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_instance_of<std::logic_error>(except, "User message..."); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::ustring& message) {is_not_instance_of<type_t>(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_not_instance_of<std::bad_cast>(except, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_not_instance_of<std::logic_error>(except, "User message...", csf_); test fails
      /// @endcode
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_instance_of<type_t>(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assume::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assume::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, csf_); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message...", csf_); // test ok.
      /// @endcode
      template<typename pointer_t>
      static void is_not_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {assert::succeed(message, stack_frame);}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_not_null(nullptr); // test throws an abort_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer) {is_not_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_not_null(nullptr, csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_not_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_not_null(nullptr, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::ustring& message) {is_not_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_not_null(nullptr, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assume::is_not_zero(i1); // test ok.
      /// xtd::tunit::assume::is_not_zero(i2); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value) {is_not_zero(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assume::is_not_zero(i1, csf_); // test ok.
      /// xtd::tunit::assume::is_not_zero(i2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_zero(value, "", stack_frame);}
      
      /// @brief Assumes that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assume::is_not_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_zero(i2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::ustring& message) {is_not_zero(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assume::is_not_zero(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_not_zero(i2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_zero(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assume::is_null(s1); // test ok.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assume::is_null(s1, csf_); // test ok.
      /// xtd::tunit::assume::is_null(s2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assume::is_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1); // test ok.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, csf_); // test ok.
      /// xtd::tunit::assume::is_null(s2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::unique_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1); // test ok.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, csf_); // test ok.
      /// xtd::tunit::assume::is_null(s2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::shared_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assume::is_null(s1); // test throws an abort_error exception.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assume::is_null(s1, csf_); // test throws an abort_error exception.
      /// xtd::tunit::assume::is_null(s2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test throws an abort_error exception.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assume::is_null(s1, "User message...", csf_); // test throws an abort_error exception.
      /// xtd::tunit::assume::is_null(s2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename pointer_t>
      static void is_null(const std::weak_ptr<pointer_t>& pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_null(nullptr); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer) {is_null(pointer, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_null(nullptr, csf_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame) {is_null(pointer, "", stack_frame);}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_null(nullptr, "User message..."); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::ustring& message) {is_null(pointer, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assume::is_null(nullptr, "User message...", csf_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {assert::succeed(message, stack_frame);}
      
      /// @brief Assumes that ta condition is positive.
      /// @param value The value to check is positive.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assume::is_positive(i1); // test ok.
      /// xtd::tunit::assume::is_positive(i2); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value) {is_positive(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assume::is_positive(i1, csf_); // test ok.
      /// xtd::tunit::assume::is_positive(i2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_positive(value, "", stack_frame);}
      
      /// @brief Assumes that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assume::is_positive(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_positive(i2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::ustring& message) {is_positive(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assume::is_positive(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_positive(i2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_positive(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that ta condition is true.
      /// @param condition The condition to check is true.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assume::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2)); // test throws an abort_error exception.
      /// @endcode
      static void is_true(bool condition) {is_true(condition, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that a condition is true.
      /// @param condition The condition to check is true.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assume::is_false(std::empty(s1), csf_); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::diagnostics::stack_frame& stack_frame) {is_true(condition, "", stack_frame);}
      
      /// @brief Assumes that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assume::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::ustring& message) {is_true(condition, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assume::is_false(std::empty(s1), "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_true(condition, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that ta condition is zero.
      /// @param value The value to check is zero.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assume::is_zero(i1); // test ok.
      /// xtd::tunit::assume::is_zero(i2); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value) {is_zero(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assume::is_zero(i1, csf_); // test ok.
      /// xtd::tunit::assume::is_zero(i2, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_zero(value, "", stack_frame);}
      
      /// @brief Assumes that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assume::is_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_zero(i2, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::ustring& message) {is_zero(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assume::is_zero(i1, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::is_zero(i2, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::is_zero(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(2);}); // test throws an abort_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement) {throws<exception_t>(statement, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(5);}, csf_); // test ok.
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(2);}, csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {throws<exception_t>(statement, "", stack_frame);}
      
      /// @brief Assumes that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(2);}, "User message..."); // test throws an abort_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::ustring& message) {throws<exception_t>(statement, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(5);}, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(2);}, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::throws<exception_t>(statement, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws_any([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assume::throws_any([&] {v1.at(2);}); // test throws an abort_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement) {throws_any(statement, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws_any([&] {v1.at(5);}, csf_); // test ok.
      /// xtd::tunit::assume::throws_any([&] {v1.at(2);}, csf_); // test throws an abort_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame) {throws_any(statement, "", stack_frame);}
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws_any([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assume::throws_any([&] {v1.at(2);}, "User message..."); // test throws an abort_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::ustring& message) {throws_any(statement, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws_any([&] {v1.at(5);}, "User message...", csf_); // test ok.
      /// xtd::tunit::assume::throws_any([&] {v1.at(2);}, "User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          assert::throws_any(statement, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
    };
  }
}
