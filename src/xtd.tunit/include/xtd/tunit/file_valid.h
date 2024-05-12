/// @file
/// @brief Contains xtd::tunit::file_valid class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "valid.h"
#include "file_assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The file_valid class contains a collection of static methods that implement the most file assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit validations
    /// @remarks Validations are the same as assertions with the difference, no exception is thrown, but an error is generated.
    /// @remarks If a validation fails, he test can be continued to the end or to an assertion is generated.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include file_valid.cpp
    class tunit_export_ file_valid final : private base_assert {
    public:
      /// @cond
      file_valid() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual) {are_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          file_assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual) {are_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that two files are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_equal(s2, s1, "User message...", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      
      /// @cond
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const char_t* actual) {are_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const char_t* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const char_t* actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_equal(const std::basic_string<char_t>& expected, const char_t* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      template<typename char_t>
      static void are_equal(const char_t* expected, const std::basic_string<char_t>& actual) {are_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_equal(const char_t* expected, const std::basic_string<char_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void are_equal(const char_t* expected, const std::basic_string<char_t>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_equal(const char_t* expected, const std::basic_string<char_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      template<typename char_t>
      static void are_equal(const char_t* expected, const char_t* actual) {are_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_equal(const char_t* expected, const char_t* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void are_equal(const char_t* expected, const char_t* actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_equal(const char_t* expected, const char_t* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      /// @endcond
      
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual) {are_not_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_istream<char_t>& expected, const std::basic_istream<char_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          file_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual) {are_not_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message..."); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that two files are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", csf_); // test ok.
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_valid::are_not_equal(s2, s1, "User message...", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const std::basic_string<char_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      
      /// @cond
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const char_t* actual) {are_not_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const char_t* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const char_t* actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_not_equal(const std::basic_string<char_t>& expected, const char_t* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const std::basic_string<char_t>& actual) {are_not_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const std::basic_string<char_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const std::basic_string<char_t>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const std::basic_string<char_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const char_t* actual) {are_not_equal(expected, actual, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const char_t* actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const char_t* actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void are_not_equal(const char_t* expected, const char_t* actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(std::basic_ifstream<char_t>(expected), std::basic_ifstream<char_t>(actual), message, stack_frame);}
      /// @endcond
      
      /// @brief Validate that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt"); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt"); // test fails
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& file) {does_not_exist(file, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt", csf_); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& file, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(file, xtd::ustring::empty_string, stack_frame);}
      /// @brief Validate that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt", "User message..."); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt", "User message..."); // test fails
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& file, const std::string& message) {does_not_exist(file, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::does_not_exist("Test2.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::file_valid::does_not_exist("Test1.txt", "User message...", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          file_assert::does_not_exist(file, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<typename char_t>
      static void does_not_exist(const char_t* file) {does_not_exist(file, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void does_not_exist(const char_t* file, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(file, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void does_not_exist(const char_t* file, const std::string& message) {does_not_exist(file, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void does_not_exist(const char_t* file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(std::basic_string<char_t>(file), message, stack_frame);}
      /// @endcond
      
      /// @brief Validate that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt"); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt"); // test fails
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& file) {exists(file, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt", csf_); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& file, const xtd::diagnostics::stack_frame& stack_frame) {exists(file, xtd::ustring::empty_string, stack_frame);}
      /// @brief Validate that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt", "User message..."); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt", "User message..."); // test fails
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& file, const std::string& message) {exists(file, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validate that file exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_valid::exists("Test1.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::file_valid::exists("Test2.txt", "User message...", csf_); // test fails
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          file_assert::exists(file, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<typename char_t>
      static void exists(const char_t* file) {exists(file, xtd::ustring::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void exists(const char_t* file, const xtd::diagnostics::stack_frame& stack_frame) {exists(file, xtd::ustring::empty_string, stack_frame);}
      template<typename char_t>
      static void exists(const char_t* file, const std::string& message) {exists(file, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void exists(const char_t* file, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {exists(std::basic_string<char_t>(file), message, stack_frame);}
      /// @endcond
      /// @}
    };
  }
}
