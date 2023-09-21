/// @file
/// @brief Contains xtd::tunit::directory_valid class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "valid"
#include "directory_assert"

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
      
      /// @name Methods
      
      /// @{
      #if defined(__cpp_lib_filesystem)
      /// @brief Validates that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual);
      /// @brief Validates that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::directory_valid::are_equal(d1, d2, csf_); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d2, csf_); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message..."); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message);
      /// @brief Validates that two directories are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// ...
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message...", csf_); // test fails.
      /// @endcode
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      /// @brief Validates that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d3); // test throws an assert_error exception.
      /// @endcode
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual);
      /// @brief Validates that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_equal(d1, d2, csf_); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d3, csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d3, "User message..."); // test throws an assert_error exception.
      /// @endcode
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message);
      /// @brief Validates that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_equal(d1, d3, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      #if defined(__cpp_lib_filesystem)
      /// @brief Validates that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual);
      /// @brief Validates that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message);
      /// @brief Validates that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      /// @brief Validates that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual);
      /// @brief Validates that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message);
      /// @brief Validates that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_valid::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      #if defined(__cpp_lib_filesystem)
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const std::filesystem::directory_entry& directory);
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const std::filesystem::directory_entry& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message);
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const xtd::io::directory_info& directory);
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const xtd::io::directory_info& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const xtd::io::directory_info& directory, const std::string& message);
      /// @brief Validates that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_valid::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist(d1); // test throws an assert_error exception.
      /// @endcode
      static void does_not_exist(const xtd::io::directory_info& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::does_not_exist("Test2.txt"); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist("Test1.txt"); // test fails.
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& directory) {does_not_exist(directory, "", xtd::diagnostics::stack_frame::empty());}
      /// @brief Validates that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::does_not_exist("Test2.txt", csf_); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist("Test1.txt", csf_); // test fails.
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& directory, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(directory, "", stack_frame);}
      /// @brief Validates that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::does_not_exist("Test2.txt", "User message..."); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist("Test1.txt", "User message..."); // test fails.
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& directory, const std::string& message) {does_not_exist(directory, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validates that file not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::does_not_exist("Test2.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::does_not_exist("Test1.txt", "User message...", csf_); // test fails.
      /// @endcode
      template<typename char_t>
      static void does_not_exist(const std::basic_string<char_t>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          directory_assert::does_not_exist(directory, message, stack_frame);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename char_t>
      static void does_not_exist(const char_t* directory) {does_not_exist(directory, "", xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void does_not_exist(const char_t* directory, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(directory, "", stack_frame);}
      template<typename char_t>
      static void does_not_exist(const char_t* directory, const std::string& message) {does_not_exist(directory, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void does_not_exist(const char_t* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(std::basic_string<char_t>(directory), message, stack_frame);}
      /// @endcond
      
      #if defined(__cpp_lib_filesystem)
      /// @endcond
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const std::filesystem::directory_entry& directory);
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const std::filesystem::directory_entry& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const std::filesystem::directory_entry& directory, const std::string& message);
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const std::filesystem::directory_entry& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtdd;;utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const xtd::io::directory_info& directory);
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtdd;;utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const xtd::io::directory_info& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtdd;;utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const xtd::io::directory_info& directory, const std::string& message);
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::ustring d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtdd;;utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_valid::exists(d1); // test ok.
      /// xtd::tunit::directory_valid::exists(d2); // test throws an assert_error exception.
      /// @endcode
      static void exists(const xtd::io::directory_info& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::exists("Test1.txt"); // test ok.
      /// xtd::tunit::directory_valid::exists("Test2.txt"); // test fails.
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& directory) {exists(directory, "", xtd::diagnostics::stack_frame::empty());}
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::exists("Test1.txt", csf_); // test ok.
      /// xtd::tunit::directory_valid::exists("Test2.txt", csf_); // test fails.
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& directory, const xtd::diagnostics::stack_frame& stack_frame) {exists(directory, "", stack_frame);}
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::exists("Test1.txt", "User message..."); // test ok.
      /// xtd::tunit::directory_valid::exists("Test2.txt", "User message..."); // test fails.
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& directory, const std::string& message) {exists(directory, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Validates that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::ifstream f1("Test1.txt");
      /// f1.close();
      /// xtd::tunit::directory_valid::exists("Test1.txt" "User message...", csf_); // test ok.
      /// xtd::tunit::directory_valid::exists("Test2.txt", "User message...", csf_); // test fails.
      /// @endcode
      template<typename char_t>
      static void exists(const std::basic_string<char_t>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          directory_assert::exists(directory, message, stack_frame);
        } catch (...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename char_t>
      static void exists(const char_t* directory) {exists(directory, "", xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void exists(const char_t* directory, const xtd::diagnostics::stack_frame& stack_frame) {exists(directory, "", stack_frame);}
      template<typename char_t>
      static void exists(const char_t* directory, const std::string& message) {exists(directory, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void exists(const char_t* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {exists(std::basic_string<char_t>(directory), message, stack_frame);}
      /// @endcond
      /// @}
    };
  }
}
