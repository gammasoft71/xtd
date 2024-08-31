/// @file
/// @brief Contains xtd::tunit::directory_assert class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "assert.h"
#define __XTD_STD_INTERNAL__
#include <xtd/internal/__xtd_std_version>
#undef __XTD_STD_INTERNAL__
#if defined(__xtd__cpp_lib_filesystem)
#include <filesystem>
#endif
#include <xtd/io/directory>
#include <xtd/io/directory_info>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The directory_assert class contains a collection of static methods that implement the most directory assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit assertions
    /// @remarks Assertions are central to unit testing in any of the xUnit frameworks, and xtd.tunit is no exception. xtd.tunit provides a rich set of assertions as static methods of the Assert class.
    /// @remarks If an assertion fails, the method call does not return and an error is reported. If a test contains multiple assertions, any that follow the one that failed will not be executed. For this reason, it's usually best to try for one assertion per test.
    /// @remarks Each method may be called without a message, with a simple text message or with a message and arguments. In the last case the message is formatted using the provided text and arguments.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include directory_assert.cpp
    class tunit_export_ directory_assert final : private base_assert {
    public:
      /// @cond
      directory_assert() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      #if defined(__xtd__cpp_lib_filesystem)
      /// @brief Asserts that two std::filesystem::directory_entry are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_assert::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3); // test throws an assert_error exception.
      /// ```
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual);
      /// @brief Asserts that two std::filesystem::directory_entry are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_assert::are_equal(d1, d2, csf_); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3, csf_); // test throws an assert_error exception.
      /// ```
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that two std::filesystem::directory_entry are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_assert::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3, "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message);
      /// @brief Asserts that two std::filesystem::directory_entry are equal.
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
      /// xtd::tunit::directory_assert::are_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      /// @brief Asserts that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_assert::are_equal(d1, d2); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3); // test throws an assert_error exception.
      /// ```
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual);
      /// @brief Asserts that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_assert::are_equal(d1, d2, csf_); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3, csf_); // test throws an assert_error exception.
      /// ```
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that two xtd::io::directory_info are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_assert::are_equal(d1, d2, "User message..."); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3, "User message..."); // test throws an assert_error exception.
      /// ```
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message);
      /// @brief Asserts that two xtd::io::directory_info are equal.
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
      /// xtd::tunit::directory_assert::are_equal(d1, d2, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_equal(d1, d3, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      #if defined(__xtd__cpp_lib_filesystem)
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual);
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::filesystem::directory_entry d1(std::filesystem::path("."));
      /// std::filesystem::directory_entry d2(std::filesystem::path("."));
      /// std::filesystem::directory_entry d3(std::filesystem::path(".."));
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message);
      /// @brief Asserts that two std::filesystem::directory_entry are not equal.
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
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const std::filesystem::directory_entry& expected, const std::filesystem::directory_entry& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      /// @brief Asserts that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual);
      /// @brief Asserts that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that two xtd::io::directory_info are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(".");
      /// xtd::io::directory_info d2(".")
      /// xtd::io::directory_info d3("..")
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message);
      /// @brief Asserts that two xtd::io::directory_info are not equal.
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
      /// xtd::tunit::directory_assert::are_not_equal(d1, d3, "User message...", csf_); // test ok.
      /// xtd::tunit::directory_assert::are_not_equal(d1, d2, "User message...", csf_); // test throws an assert_error exception.
      /// ```
      static void are_not_equal(const xtd::io::directory_info& expected, const xtd::io::directory_info& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      #if defined(__xtd__cpp_lib_filesystem)
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const std::filesystem::directory_entry& directory);
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const std::filesystem::directory_entry& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message);
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const std::filesystem::directory_entry& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const xtd::io::directory_info& directory);
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const xtd::io::directory_info& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const xtd::io::directory_info& directory, const std::string& message);
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(environment::get_folder_path(environment::special_folder::common_application_data));
      /// xtd::io::directory_info d2(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__"));
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      static void does_not_exist(const xtd::io::directory_info& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void does_not_exist(const xtd::basic_string<char_t>& directory) {does_not_exist(directory, xtd::string::empty_string, xtd::diagnostics::stack_frame::empty());}
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void does_not_exist(const xtd::basic_string<char_t>& directory, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(directory, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void does_not_exist(const xtd::basic_string<char_t>& directory, const std::string& message) {does_not_exist(directory, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Asserts that directory not exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::does_not_exist(d2); // test ok.
      /// xtd::tunit::directory_assert::does_not_exist(d1); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void does_not_exist(const xtd::basic_string<char_t>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(xtd::io::directory_info(directory), message, stack_frame);}
      
      /// @cond
      template<typename char_t>
      static void does_not_exist(const char_t* directory) {does_not_exist(directory, xtd::string::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void does_not_exist(const char_t* directory, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(directory, xtd::string::empty_string, stack_frame);}
      template<typename char_t>
      static void does_not_exist(const char_t* directory, const std::string& message) {does_not_exist(directory, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void does_not_exist(const char_t* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {does_not_exist(xtd::basic_string<char_t>(directory), message, stack_frame);}
      /// @endcond

      #if defined(__xtd__cpp_lib_filesystem)
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const std::filesystem::directory_entry& directory);
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const std::filesystem::directory_entry& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const std::filesystem::directory_entry& directory, const std::string& message);
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::io::directory_info d1(std::filesystem::directory_entry d1(std::filesystem::path(environment::get_folder_path(environment::special_folder::common_application_data)));
      /// xtd::io::directory_info d2(std::filesystem::directory_entry d1(std::filesystem::path(xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data)) / "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const std::filesystem::directory_entry& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      #endif
      
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const xtd::io::directory_info& directory);
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const xtd::io::directory_info& directory, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const xtd::io::directory_info& directory, const std::string& message);
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      static void exists(const xtd::io::directory_info& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd;;utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void exists(const xtd::basic_string<char_t>& directory) {exists(directory, xtd::string::empty_string, xtd::diagnostics::stack_frame::empty());}
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void exists(const xtd::basic_string<char_t>& directory, const xtd::diagnostics::stack_frame& stack_frame) {exists(directory, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void exists(const xtd::basic_string<char_t>& directory, const std::string& message) {exists(directory, message, xtd::diagnostics::stack_frame::empty());}
      /// @brief Asserts that directory exists.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::string d1 = environment::get_folder_path(environment::special_folder::common_application_data);
      /// xtd::utring d2 = xtd::io::path::combine(environment::get_folder_path(environment::special_folder::common_application_data), "__xtd_test_directory_not_found__");
      /// xtd::tunit::directory_assert::exists(d1); // test ok.
      /// xtd::tunit::directory_assert::exists(d2); // test throws an assert_error exception.
      /// ```
      template<typename char_t>
      static void exists(const xtd::basic_string<char_t>& directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {exists(xtd::io::directory_info(directory), message, stack_frame);}
      
      /// @cond
      template<typename char_t>
      static void exists(const char_t* directory) {exists(directory, xtd::string::empty_string, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void exists(const char_t* directory, const xtd::diagnostics::stack_frame& stack_frame) {exists(directory, xtd::string::empty_string, stack_frame);}
      template<typename char_t>
      static void exists(const char_t* directory, const std::string& message) {exists(directory, message, xtd::diagnostics::stack_frame::empty());}
      template<typename char_t>
      static void exists(const char_t* directory, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {exists(xtd::basic_string<char_t>(directory), message, stack_frame);}
      /// @endcond
      /// @}
    };
  }
}

/// @brief Asserts that directory exists.
/// @param expected the expected value.
/// @param actual the actual value.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::directory_assert, xtd::tunit::directory_assume and xtd::tunit::directory_valid classes.
/// @par Examples
/// ```cpp
/// std::ifstream f1("Test1.txt");
/// f1.close();
/// xtd::tunit::directory_assert::exists_("Test1.txt"); // test ok.
/// xtd::tunit::directory_assert::exists_("Test2.txt", "User message..."); // test error.
/// ```
#define exists_(...) __CMD_ASSERT_ARGS(exists, __VA_ARGS__)

/// @brief Asserts that file not exists.
/// @param expected the expected value.
/// @param actual the actual value.
/// @param message An optional user message to display if the assertion fails. This message can be seen in the unit test results.
/// @ingroup xtd_tunit tunit
/// @remarks Contains information about current file and current line.
/// @remarks Can be used with xtd::tunit::directory_assert, xtd::tunit::directory_assume and xtd::tunit::directory_valid classes.
/// @par Examples
/// ```cpp
/// std::ifstream f1("Test1.txt");
/// f1.close();
/// xtd::tunit::directory_assert::does_not_exist_("Test2.txt"); // test ok.
/// xtd::tunit::directory_assert::does_not_exist_("Test1.txt", "User message..."); // test error.
/// ```
#define does_not_exist_(...) __CMD_ASSERT_ARGS(does_not_exist, __VA_ARGS__)
