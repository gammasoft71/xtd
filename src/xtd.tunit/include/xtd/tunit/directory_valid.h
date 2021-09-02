/// @file
/// @brief Contains xtd::tunit::directory_valid class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "valid.h"
#include "directory_assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The directory_valid class contains a collection of static methods that implement the most directory assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class directory_valid final : private base_assert {
    public:
      /// @cond
      directory_valid() = delete;
      /// @endcond
      
#if defined(__cpp_lib_filesystem)
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_equal(d1, d2, csf_); // test ok.
      /// xtd::tunit::file_assert::are_equal(d1, d2, csf_); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message..."); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_equal(d1, d2, "User message...", csf_); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          directory_assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          base_assert::error();
        }
      }

      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test fails.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test fails.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test fails.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::are_not_equal(d1, d2, "User message...", csf_); // test fails.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          directory_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          base_assert::error();
        }
      }
#endif

      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt"); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt"); // test fails.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& directory) {exists(directory, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt", csf_); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt", csf_); // test fails.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& directory, const xtd::diagnostics::stack_frame& stack_frame) {exists(directory, "", stack_frame);}
      
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt", "User message..."); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt", "User message..."); // test fails.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& directory, const std::string& message) {exists(directory, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::exists("Test1.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::exists("Test2.txt", "User message...", csf_); // test fails.
      /// @endcode
      template<typename Char>
      static void exists(const std::basic_string<Char>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          directory_assert::exists(directory, message, stack_frame);
        } catch (...) {
          base_assert::error();
        }
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
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt"); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt"); // test fails.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& directory) {does_not_exist(directory, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt", csf_); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt", csf_); // test fails.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& directory, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(directory, "", stack_frame);}
      
      /// @brief Asserts that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt", "User message..."); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt", "User message..."); // test fails.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& directory, const std::string& message) {does_not_exist(directory, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Asserts that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::file_assert::does_not_exist("Test2.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::file_assert::does_not_exist("Test1.txt", "User message...", csf_); // test fails.
      /// @endcode
      template<typename Char>
      static void does_not_exist(const std::basic_string<Char>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          directory_assert::does_not_exist(directory, message, stack_frame);
        } catch (...) {
          base_assert::error();
        }
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
