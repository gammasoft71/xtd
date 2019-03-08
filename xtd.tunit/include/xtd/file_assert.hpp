/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The file_assert class contains a collection of static methods that implement the most file assertions used in xtd::tUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class file_assert final {
    public:
      /// @cond
      file_assert() = delete;
      /// @endcond

      /// @brief Asserts that two basic_istream<Char> are equal.
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
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two basic_istream<Char> are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two basic_istream<Char> are equal.
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
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two basic_istream<Char> are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_istream<Char>& expected, const std::basic_istream<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        std::basic_istream<Char> if_expected(expected.rdbuf());
        std::basic_istream<Char> if_actual(actual.rdbuf());
        
        if_expected.seekg(0, std::ios::end);
        if_actual.seekg(0, std::ios::end);
        size_t size_expected = if_expected.tellg();
        size_t size_actual = if_actual.tellg();
        if (size_expected != size_actual) {
          assert::fail("istream length " + std::to_string(size_expected), std::to_string(size_actual), message, line_info);
          return;
        }

        if_expected.seekg(0, std::ios::beg);
        if_actual.seekg(0, std::ios::beg);
        for (size_t offset = 0; offset < size_actual; ++offset) {
          Char value_expected = if_expected.get();
          Char value_actual = if_actual.get();
          if (value_expected != value_actual) {
            assert::fail("istream at offset " + std::to_string(offset) + " value " + std::to_string(value_expected), std::to_string(value_actual), message, line_info);
            return;
          }
        }
        assert::succeed(message, line_info);
      }

      /// @brief Asserts that two basic_istream<Char> are equal.
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
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two basic_istream<Char> are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two basic_istream<Char> are equal.
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
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two basic_istream<Char> are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::stringstream s1;
      /// s1 << "Test";
      /// s1.seekg(0, std::ios::beg);
      /// std::stringstream s2;
      /// s2 << "Test";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", line_info_); // test ok.
      /// s2 << "Test2";
      /// s2.seekg(0, std::ios::beg);
      /// xtd::tunit::file_assert::are_equal(s2, s1, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual));}

      /// @cond
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual) {are_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_equal(const std::basic_string<Char>& expected, const Char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual));}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual) {are_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const std::basic_string<Char>& actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual));}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual) {are_equal(expected, actual, "", line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      template<typename Char>
      static void are_equal(const Char* expected, const Char* actual, const std::string& message, const xtd::tunit::line_info& line_info) {are_equal(std::basic_ifstream<Char>(expected), std::basic_ifstream<Char>(actual));}
      /// @endcond
    };
  }
}
