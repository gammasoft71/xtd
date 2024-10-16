/// @file
/// @brief Contains xtd::tunit::valid class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "assert.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The valid class contains a collection of static methods that implement the most common assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit validations
    /// @remarks Validations are the same as assertions with the difference, no exception is thrown, but an error is generated.
    /// @remarks If a validation fails, he test can be continued to the end or to an assertion is generated.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include valid.cpp
    class tunit_export_ valid final : private base_assert {
    public:
      /// @cond
      valid() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::are_equal(24, int(24)); // test ok.
      /// xtd::tunit::valid::are_equal(23, int(24)); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = csf_) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::are_equal(24, int(24), "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal(23, int(24), "User message..."); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      static void are_equal(const char* expected, const char* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void are_equal(const char8* expected, const char8* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void are_equal(const char16* expected, const char16* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void are_equal(const char32* expected, const char32* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void are_equal(float expected, float actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void are_equal(double expected, double actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void are_equal(long double expected, long double actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// float f = 0.00007999999999f;
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.0000000000001f); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.00000000000001f); // test fails.
      /// ```
      static void are_equal(float expected, float actual, float tolerance, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// float f = 0.00007999999999f;
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.0000000000001f, "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008f, f, 0.00000000000001f, "User message..."); // test fails.
      /// ```
      static void are_equal(float expected, float actual, float tolerance, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// double d = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.0000000000001); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.00000000000001); // test fails.
      /// ```
      static void are_equal(double expected, double actual, double tolerance, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// double d = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.0000000000001, "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008, d, 0.00000000000001, "User message..."); // test fails.
      /// ```
      static void are_equal(double expected, double actual, double tolerance, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.0000000000001l); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.00000000000001l); // test fails.
      /// ```
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.0000000000001l, "User message..."); // test ok.
      /// xtd::tunit::valid::are_equal_(0.00008l, ld, 0.00000000000001l, "User message..."); // test fails.
      /// ```
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      
      /// @brief Validates that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::are_not_equal(23, int(24)); // test ok.
      /// xtd::tunit::valid::are_not_equal(24, int(24)); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = csf_) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::are_not_equal(23, int(24), "User message..."); // test ok.
      /// xtd::tunit::valid::are_not_equal(24, int(24), "User message..."); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      static void are_not_equal(const char* expected, const char* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void are_not_equal(const char8* expected, const char8* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void are_not_equal(const char16* expected, const char16* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void are_not_equal(const char32* expected, const char32* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that two objects do refer to different objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::valid::are_not_same(c, a); // test ok.
      /// xtd::tunit::valid::are_not_same(b, a, stack_frame); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = csf_) {are_not_same(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that two objects do refer to different objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::valid::are_not_same(c, a, "User message..."); // test ok.
      /// xtd::tunit::valid::are_not_same(b, a, "User message...", stack_frame); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::are_not_same(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that two objects do refer to different objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::valid::are_same(b, a); // test ok.
      /// xtd::tunit::valid::are_same(c, a); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = csf_) {are_same(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that two objects do refer to different objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::valid::are_same(b, a, "User message..."); // test ok.
      /// xtd::tunit::valid::are_same(c, a, "User message..."); // test fails.
      /// ```
      template<typename expected_t, typename actual_t>
      static void are_same(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::are_same(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::valid::contains(2, v1); // test ok.
      /// xtd::tunit::valid::contains(4, v1); // test fails.
      /// ```
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = csf_) {contains(item, collection, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::valid::contains(2, v1, "User message..."); // test ok.
      /// xtd::tunit::valid::contains(4, v1, "User message..."); // test fails.
      /// ```
      template<typename item_t, typename collection_t>
      static void contains(const item_t& item, const collection_t& collection, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::contains(item, collection, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::diagnostics::stack_frame& stack_frame = csf_) {contains(item, values, xtd::string::empty_string, stack_frame);}
      template<typename item_t, typename value_t>
      static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      static void contains(char item, const char* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void contains(char8 item, const char8* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void contains(char16 item, const char16* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void contains(char32 item, const char32* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void contains(wchar_t item, const wchar_t* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that the statement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(2);}); // test ok.
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(5);}); // test fails.
      /// ```
      static void does_not_throw(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that the statement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(2);}, "User message..."); // test ok.
      /// xtd::tunit::valid::does_not_throw([&] {v1.at(5);}, "User message..."); // test fails.
      /// ```
      static void does_not_throw(const std::function<void()>& statement, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      
      /// @brief Validates that collection contains an item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::valid::is_empty(v1); // test ok.
      /// xtd::tunit::valid::is_empty(v2); // test fails.
      /// ```
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::valid::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_empty(v2, "User message..."); // test fails.
      /// ```
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_empty(value, xtd::string::empty_string, stack_frame);}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_empty(values, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      static void is_empty(const char* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void is_empty(const char8* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void is_empty(const char16* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_empty(const char32* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_empty(const wchar_t* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that a condition is false.
      /// @param condition The condition to check is false.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::valid::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2)); // test fails.
      /// ```
      static void is_false(bool condition, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::valid::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), "User message..."); // test fails.
      /// ```
      static void is_false(bool condition, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      
      /// @brief Validates that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_greater(24, 12); // test ok.
      /// xtd::tunit::valid::is_greater(24, 48); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_greater(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_greater(24, 12, "User message..."); // test ok.
      /// xtd::tunit::valid::is_greater(24, 48, "User message..."); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      static void is_greater(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void is_greater(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void is_greater(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_greater(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_greater(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_greater_or_equal(24, 12); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 24); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 48); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_greater_or_equal(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_greater_or_equal(24, 12, "User message..."); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::valid::is_greater_or_equal(24, 48, "User message..."); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      static void is_greater_or_equal(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void is_greater_or_equal(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void is_greater_or_equal(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_greater_or_equal(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_instance_of<std::logic_error>(except); // test ok.
      /// xtd::tunit::valid::is_instance_of<std::bad_cast>(except); // test fails
      /// ```
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_instance_of<type_t>(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_instance_of<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::valid::is_instance_of<std::bad_cast>(except, "User message..."); // test fails
      /// ```
      template<typename type_t, typename value_t>
      static void is_instance_of(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_instance_of<type_t>(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_less(24, 48); // test ok.
      /// xtd::tunit::valid::is_less(24, 12); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_less(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_less(24, 48, "User message..."); // test ok.
      /// xtd::tunit::valid::is_less(24, 12, "User message..."); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_less(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      static void is_less(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void is_less(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void is_less(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_less(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_less(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_less_or_equal(24, 48); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 24); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 12); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_less_or_equal(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_less_or_equal(24, 48, "User message..."); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::valid::is_less_or_equal(24, 12, "User message..."); // test fails.
      /// ```
      template<typename value1_t, typename value2_t>
      static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      static void is_less_or_equal(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void is_less_or_equal(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void is_less_or_equal(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_less_or_equal(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1); // test ok.
      /// xtd::tunit::valid::is_NaN(v2); // test fails.
      /// ```
      static void is_NaN(double value, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message..."); // test fails.
      /// ```
      static void is_NaN(double value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::valid::is_NaN(v1); // test ok.
      /// xtd::tunit::valid::is_NaN(v2); // test fails.
      /// ```
      static void is_NaN(long double value, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::valid::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message..."); // test fails.
      /// ```
      static void is_NaN(long double value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1); // test ok.
      /// xtd::tunit::valid::is_NaN(v2); // test fails.
      /// ```
      static void is_NaN(float value, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::valid::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_NaN(v2, "User message..."); // test fails.
      /// ```
      static void is_NaN(float value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      
      /// @brief Validates that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::valid::is_negative(i1); // test ok.
      /// xtd::tunit::valid::is_negative(i2); // test fails.
      /// ```
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_negative(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::valid::is_negative(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_negative(i2, "User message..."); // test fails.
      /// ```
      template<typename value_t>
      static void is_negative(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_negative(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::valid::is_not_empty(v1); // test ok.
      /// xtd::tunit::valid::is_not_empty(v2); // test fails.
      /// ```
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::valid::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_empty(v2, "User message..."); // test fails.
      /// ```
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      static void is_not_empty(const char* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#if defined(__xtd__cpp_lib_char8_t)
      static void is_not_empty(const char8* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
#endif
      static void is_not_empty(const char16* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_not_empty(const char32* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      static void is_not_empty(const wchar_t* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @endcond
      
      /// @brief Validates that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_not_instance_of<std::bad_cast>(except); // test ok.
      /// xtd::tunit::valid::is_not_instance_of<std::logic_error>(except); // test fails
      /// ```
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_instance_of<type_t>(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::valid::is_not_instance_of<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_instance_of<std::logic_error>(except, "User message..."); // test fails
      /// ```
      template<typename type_t, typename value_t>
      static void is_not_instance_of(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_instance_of<type_t>(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const pointer_t* pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the optional is not std::nullopt.
      /// @param opt The optional to check is std::nullopt.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1 = "Anything";
      /// std::optional<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test fails.
      /// ```
      template<typename optional_t>
      static void is_not_null(const std::optional<optional_t>& opt, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_null(opt, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the optional is not std::nullopt.
      /// @param opt The optional to check is std::nullopt.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1 = "Anything";
      /// std::optional<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test fails.
      /// ```
      template<typename optional_t>
      static void is_not_null(const std::optional<optional_t>& opt, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_null(opt, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1 = xtd::new_uptr<std::string>("Anything");
      /// xtd::uptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const xtd::uptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1 = xtd::new_uptr<std::string>("Anything");
      /// xtd::uptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const xtd::uptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1 = xtd::new_sptr<std::string>("Anything");
      /// xtd::sptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const xtd::sptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1 = xtd::new_sptr<std::string>("Anything");
      /// xtd::sptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const xtd::sptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always true, a xtd::wptr can't be equal to nullptr by construction or assignation.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1 = s;
      /// xtd::wptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1); // test ok.
      /// xtd::tunit::valid::is_not_null(s2); // test ok.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const xtd::wptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always true, a xtd::wptr can't be equal to nullptr by construction or assignation.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1 = s;
      /// xtd::wptr<std::string> s2;
      /// xtd::tunit::valid::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_null(s2, "User message..."); // test ok.
      /// ```
      template<typename pointer_t>
      static void is_not_null(const xtd::wptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {assert::succeed(message, stack_frame);}
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_not_null(nullptr); // test fails.
      /// ```
      static void is_not_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_not_null(nullptr, "User message..."); // test fails.
      /// ```
      static void is_not_null(std::nullptr_t pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      
      /// @brief Validates that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::valid::is_not_zero(i1); // test ok.
      /// xtd::tunit::valid::is_not_zero(i2); // test fails.
      /// ```
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_not_zero(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::valid::is_not_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_not_zero(i2, "User message..."); // test fails.
      /// ```
      template<typename value_t>
      static void is_not_zero(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_not_zero(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::valid::is_null(s1); // test ok.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const pointer_t* pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the optional is std::nullopt.
      /// @param opt The optional to check is std::nullopt.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1;
      /// std::optional<std::string> s2 = "Anything";
      /// xtd::tunit::valid::is_null(s1); // test ok.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// ```
      template<typename optional_t>
      static void is_null(const std::optional<optional_t>& opt, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_null(opt, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the optional is std::nullopt.
      /// @param opt The optional to check is std::nullopt.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1;
      /// std::optional<std::string> s2 = "Anything";
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// ```
      template<typename optional_t>
      static void is_null(const std::optional<optional_t>& opt, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_null(opt, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1;
      /// xtd::uptr<std::string> s2 = xtd::new_uptr<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1); // test ok.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const xtd::uptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1;
      /// xtd::uptr<std::string> s2 = xtd::new_uptr<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const xtd::uptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1;
      /// xtd::sptr<std::string> s2 = xtd::new_sptr<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1); // test ok.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const xtd::sptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1;
      /// xtd::sptr<std::string> s2 = xtd::new_sptr<std::string>("Anything");
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const xtd::sptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a xtd::wptr can't be equal to nullptr by construction or assignation.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1;
      /// xtd::wptr<std::string> s2 = s;
      /// xtd::tunit::valid::is_null(s1); // test fails.
      /// xtd::tunit::valid::is_null(s2); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const xtd::wptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a xtd::wptr can't be equal to nullptr by construction or assignation.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1;
      /// xtd::wptr<std::string> s2 = s;
      /// xtd::tunit::valid::is_null(s1, "User message..."); // test fails.
      /// xtd::tunit::valid::is_null(s2, "User message..."); // test fails.
      /// ```
      template<typename pointer_t>
      static void is_null(const xtd::wptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_null(nullptr); // test ok.
      /// ```
      static void is_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::valid::is_null(nullptr, "User message..."); // test ok.
      /// ```
      static void is_null(std::nullptr_t pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      
      /// @brief Validates that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::valid::is_positive(i1); // test ok.
      /// xtd::tunit::valid::is_positive(i2); // test fails.
      /// ```
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_positive(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::valid::is_positive(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_positive(i2, "User message..."); // test fails.
      /// ```
      template<typename value_t>
      static void is_positive(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_positive(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that a condition is true.
      /// @param condition The condition to check is true.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::valid::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2)); // test fails.
      /// ```
      static void is_true(bool condition, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::valid::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::valid::is_false(std::empty(s2), "User message..."); // test fails.
      /// ```
      static void is_true(bool condition, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      
      /// @brief Validates that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::valid::is_zero(i1); // test ok.
      /// xtd::tunit::valid::is_zero(i2); // test fails.
      /// ```
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = csf_) {is_zero(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::valid::is_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::valid::is_zero(i2, "User message..."); // test fails.
      /// ```
      template<typename value_t>
      static void is_zero(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::is_zero(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }

      /// @brief Validates that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(2);}); // test fails.
      /// ```
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame = csf_) {throws<exception_t>(statement, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::valid::throws<std::out_of_range>([&] {v1.at(2);}, "User message..."); // test fails.
      /// ```
      template<typename exception_t>
      static void throws(const std::function<void()>& statement, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) {
        try {
          assert::throws<exception_t>(statement, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @brief Validates that the statement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws_any([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::valid::throws_any([&] {v1.at(2);}); // test fails.
      /// ```
      static void throws_any(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @brief Validates that the statement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::valid::throws_any([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::valid::throws_any([&] {v1.at(2);}, "User message..."); // test fails.
      /// ```
      static void throws_any(const std::function<void()>& statement, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_);
      /// @}
    };
  }
}
