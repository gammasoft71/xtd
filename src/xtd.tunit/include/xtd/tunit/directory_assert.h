/// @file
/// @brief Contains xtd::tunit::directory_assert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "assert.h"
#include <sys/stat.h>
#if defined(__cpp_lib_filesystem)
#include <filesystem>
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The directory_assert class contains a collection of static methods that implement the most directory assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class directory_assert final : private base_assert {
    public:
      /// @cond
      directory_assert() = delete;
      /// @endcond
      
#if defined(__cpp_lib_filesystem)
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::directory_assert::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d2); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_equal(d1, d2, csf_); // test ok.
      /// xtd::tunit::file_assert::are_equal(d1, d2, csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (expected != actual)
          base_assert::fail(base_assert::to_string(expected.path().string()), base_assert::to_string(actual.path().string()), message, stack_frame);
        else
          assert::succeed(message, stack_frame);
      }

      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        if (expected != actual)
          base_assert::fail(base_assert::to_string(expected.path().string()), base_assert::to_string(actual.path().string()), message, stack_frame);
        else
          assert::succeed(message, stack_frame);
      }
#endif
      
      /// @brief Asserts that directory exists.
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
      static void exists(const std::basic_string<Char>& directory) {exists(directory, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that directory exists.
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
      static void exists(const std::basic_string<Char>& directory, const xtd::diagnostics::stack_frame& stack_frame) {exists(directory, "", stack_frame);}
      
      /// @brief Asserts that directory exists.
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
      static void exists(const std::basic_string<Char>& directory, const std::string& message) {exists(directory, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that directory exists.
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
      static void exists(const std::basic_string<Char>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        struct stat info;
        if(stat(directory.c_str(), &info ) != 0 || (info.st_mode & S_IFDIR) != S_IFDIR)
          base_assert::fail("directory exists", base_assert::to_string(directory), message, stack_frame);
        else
          assert::succeed(message, stack_frame);
      }
      
      /// @cond
      template<typename Char>
      static void exists(const Char* directory) {exists(directory, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void exists(const Char* directory, const xtd::diagnostics::stack_frame& stack_frame) {exists(directory, "", stack_frame);}
      template<typename Char>
      static void exists(const Char* directory, const std::string& message) {exists(directory, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void exists(const Char* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {exists(std::basic_string<Char>(directory), message, stack_frame);}
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
      static void does_not_exist(const std::basic_string<Char>& directory) {does_not_exist(directory, "", xtd::diagnostics::stack_frame::empty());}
      
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
      static void does_not_exist(const std::basic_string<Char>& directory, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(directory, "", stack_frame);}
      
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
      static void does_not_exist(const std::basic_string<Char>& directory, const std::string& message) {does_not_exist(directory, message, xtd::diagnostics::stack_frame::empty());}
      
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
      static void does_not_exist(const std::basic_string<Char>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        struct stat info;
        if(stat(directory.c_str(), &info ) == 0 && (info.st_mode & S_IFDIR) == S_IFDIR)
          base_assert::fail("not directory exists", base_assert::to_string(directory), message, stack_frame);
        else
          assert::succeed(message, stack_frame);
      }
      
      /// @cond
      template<typename Char>
      static void does_not_exist(const Char* directory) {does_not_exist(directory, "", xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void does_not_exist(const Char* directory, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(directory, "", stack_frame);}
      template<typename Char>
      static void does_not_exist(const Char* directory, const std::string& message) {does_not_exist(directory, message, xtd::diagnostics::stack_frame::empty());}
      template<typename Char>
      static void does_not_exist(const Char* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(std::basic_string<Char>(directory), message, stack_frame);}
      /// @endcond
    };
  }
}

#define exists_(...) __CMD_ASSERT_ARGS(exists, __VA_ARGS__)

#define does_not_exist_(...) __CMD_ASSERT_ARGS(does_not_exist, __VA_ARGS__)
