/// @file
/// @brief Contains xtd::tunit::directory_valid class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "valid.hpp"
#include "directory_assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The directory_valid class contains a collection of static methods that implement the most directory assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit validations
    /// @remarks Validations are the same as assertions with the difference, no exception is thrown, but an error is generated.
    /// @remarks If a validation fails, he test can be continued to the end or to an assertion is generated.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include directory_valid.cpp
    class tunit_export_ directory_valid final : private base_assert {
    public:
      /// @cond
      directory_valid() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Validates that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// ...
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test fails.
      /// ```
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// ...
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message..."); // test fails.
      /// ```
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d3); // test throws an assert_error exception.
      /// ```
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d3, "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const std::filesystem::directory_entry& directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const xtd::io::directory_info& directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const xtd::io::directory_info& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::does_not_exist("Test2.txt"); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist("Test1.txt"); // test fails.
      /// ```
      template<class char_t>
      inline static void does_not_exist(const xtd::basic_string<char_t>& directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_exist(directory, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::does_not_exist("Test2.txt" "User message..."); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist("Test1.txt", "User message..."); // test fails.
      /// ```
      template<class char_t>
      inline static void does_not_exist(const xtd::basic_string<char_t>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          directory_assert::does_not_exist(directory, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class char_t>
      inline static void does_not_exist(const char_t* directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_exist(directory, xtd::string::empty_string, stack_frame);}
      template<class char_t>
      inline static void does_not_exist(const char_t* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_exist(xtd::basic_string<char_t>(directory), message, stack_frame);}
      /// @endcond
      
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const std::filesystem::directory_entry& directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const std::filesystem::directory_entry& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const xtd::io::directory_info& directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const xtd::io::directory_info& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::exists("Test1.txt"); // test ok.
      /// xtd::tunit::directory_valid::exists("Test2.txt"); // test fails.
      /// ```
      template<class char_t>
      inline static void exists(const xtd::basic_string<char_t>& directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {exists(directory, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::exists("Test1.txt" "User message..."); // test ok.
      /// xtd::tunit::directory_valid::exists("Test2.txt", "User message..."); // test fails.
      /// ```
      template<class char_t>
      inline static void exists(const xtd::basic_string<char_t>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          directory_assert::exists(directory, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class char_t>
      inline static void exists(const char_t* directory, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {exists(directory, xtd::string::empty_string, stack_frame);}
      template<class char_t>
      inline static void exists(const char_t* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {exists(xtd::basic_string<char_t>(directory), message, stack_frame);}
      /// @endcond
      /// @}
    };
  }
}
