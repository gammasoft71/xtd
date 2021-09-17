/// @file
/// @brief Contains xtd::tunit::file_assert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "directory_assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The file_assert class contains a collection of static methods that implement the most file assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class file_assert final : private base_assert {
    public:
      /// @cond
      file_assert() = delete;
      /// @endcond

      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::basic_istream<Char> if_expected(expected.rdbuf());
        std::basic_istream<Char> if_actual(actual.rdbuf());
        
        if_expected.seekg(0, std::ios::end);
        if_actual.seekg(0, std::ios::end);
        size_t size_expected = if_expected.tellg();
        size_t size_actual = if_actual.tellg();
        if (size_expected != size_actual) {
          base_assert::fail("istream length " + base_assert::to_string(size_expected), base_assert::to_string(size_actual), message, stack_frame);
          return;
        }
        
        if_expected.seekg(0, std::ios::beg);
        if_actual.seekg(0, std::ios::beg);
        for (size_t offset = 0; offset < size_actual; ++offset) {
          Char value_expected = if_expected.get();
          Char value_actual = if_actual.get();
          if (value_expected != value_actual) {
            base_assert::fail("istream at offset " + base_assert::to_string(offset) + " value " + base_assert::to_string(value_expected), base_assert::to_string(value_actual), message, stack_frame);
            return;
          }
        }
        assert::succeed(message, stack_frame);
      }
      
      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      
      /// @cond
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      /// @endcond

      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        std::basic_istream<Char> if_expected(expected.rdbuf());
        std::basic_istream<Char> if_actual(actual.rdbuf());
        
        if_expected.seekg(0, std::ios::end);
        if_actual.seekg(0, std::ios::end);
        size_t size_expected = if_expected.tellg();
        size_t size_actual = if_actual.tellg();
        if (size_expected != size_actual) {
          assert::succeed(message, stack_frame);
          return;
        }
        
        if_expected.seekg(0, std::ios::beg);
        if_actual.seekg(0, std::ios::beg);
        for (size_t offset = 0; offset < size_actual; ++offset) {
          Char value_expected = if_expected.get();
          Char value_actual = if_actual.get();
          if (value_expected != value_actual) {
            assert::succeed(message, stack_frame);
            return;
          }
        }
        base_assert::fail("not equal <" + __tunit_demangle(typeid(expected).name()) + ">", "<" + __tunit_demangle(typeid(expected).name()) + ">", message, stack_frame);
      }
      
      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_not_equal(s2, s1, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      
      /// @cond
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_not_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void are_not_equal(const Char* expected, const Char* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual), message, stack_frame);}
      /// @endcond
      
      /// @brief Asserts that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt"); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt"); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file) {exists(file, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt", csf_); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file, const xtd::diagnostics::stack_frame& stack_frame) {exists(file, "", stack_frame);}
      
      /// @brief Asserts that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt", "User message..."); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt", "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file, const std::string& message) {exists(file, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt", "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::basic_ifstream<Char>(file).good() == false)
          base_assert::fail("file exists", base_assert::to_string(file), message, stack_frame);
        else
          assert::succeed(message, stack_frame);
      }
      
      /// @cond
      template<typename Char>
      static void exists(const Char* file) {exists(file, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void exists(const Char* file, const xtd::diagnostics::stack_frame& stack_frame) {exists(file, "", stack_frame);}
      template<typename Char>
      static void exists(const Char* file, const std::string& message) {exists(file, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void exists(const Char* file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {exists(std::basic_string<Char>(file), message, stack_frame);}
      /// @endcond
      
      /// @brief Asserts that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt"); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt"); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file) {does_not_exist(file, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt", csf_); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(file, "", stack_frame);}
      
      /// @brief Asserts that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt", "User message..."); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt", "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file, const std::string& message) {does_not_exist(file, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt", "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (std::basic_ifstream<Char>(file).good() == true)
          base_assert::fail("not file exists", base_assert::to_string(file), message, stack_frame);
        else
          assert::succeed(message, stack_frame);
      }
      
      /// @cond
      template<typename Char>
      static void does_not_exist(const Char* file) {does_not_exist(file, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void does_not_exist(const Char* file, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(file, "", stack_frame);}
      template<typename Char>
      static void does_not_exist(const Char* file, const std::string& message) {does_not_exist(file, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void does_not_exist(const Char* file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(std::basic_string<Char>(file), message, stack_frame);}
      /// @endcond
    };
  }
}
