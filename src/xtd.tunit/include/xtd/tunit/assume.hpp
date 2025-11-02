/// @file
/// @brief Contains xtd::tunit::assume class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The assume class contains a collection of static methods that implement the most common assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit assumptions
    /// @remarks Assumptions are intended to express the state a test must be in to provide a meaningful result. They are functionally similar to assertions, however a unmet assumption will produce an aborted test result, as opposed to a failure.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assume.cpp
    class tunit_export_ assume final : private base_assert {
    public:
      /// @cond
      assume() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::are_equal(24, int(24)); // test ok.
      /// xtd::tunit::assume::are_equal(23, int(24)); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::are_equal(24, int(24), "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal(23, int(24), "User message..."); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void are_equal(const char* expected, const char* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_equal(const char8* expected, const char8* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_equal(const char16* expected, const char16* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_equal(const char32* expected, const char32* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_equal(const wchar_t* expected, const wchar_t* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_equal(float expected, float actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_equal(double expected, double actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_equal(long double expected, long double actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.0000000000001f); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.00000000000001f); // test throws an abort_error exception.
      /// ```
      static void are_equal(float expected, float actual, float tolerance, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// float f = 0.00007999999999f;
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.0000000000001f, "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008f, f, 0.00000000000001f, "User message..."); // test throws an abort_error exception.
      /// ```
      static void are_equal(float expected, float actual, float tolerance, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// double d = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.0000000000001); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.00000000000001); // test throws an abort_error exception.
      /// ```
      static void are_equal(double expected, double actual, double tolerance, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// double d = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.0000000000001, "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008, d, 0.00000000000001, "User message..."); // test throws an abort_error exception.
      /// ```
      static void are_equal(double expected, double actual, double tolerance, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.0000000000001l); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.00000000000001l); // test throws an abort_error exception.
      /// ```
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param tolerance Indicates a tolerance within which they will be considered as equal.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// long double ld = 0.00007999999999;
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.0000000000001l, "User message..."); // test ok.
      /// xtd::tunit::assume::are_equal_(0.00008l, ld, 0.00000000000001l, "User message..."); // test throws an abort_error exception.
      /// ```
      static void are_equal(long double expected, long double actual, long double tolerance, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Assumes that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::are_not_equal(23, int(24)); // test ok.
      /// xtd::tunit::assume::are_not_equal(24, int(24)); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      
      /// @brief Assumes that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::are_not_equal(23, int(24), "User message..."); // test ok.
      /// xtd::tunit::assume::are_not_equal(24, int(24), "User message..."); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void are_not_equal(const char* expected, const char* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_not_equal(const char8* expected, const char8* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_not_equal(const char16* expected, const char16* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_not_equal(const char32* expected, const char32* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void are_not_equal(const wchar_t* expected, const wchar_t* actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::assume::are_not_same(c, a); // test ok.
      /// xtd::tunit::assume::are_not_same(b, a, stack_frame); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_same(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::assume::are_not_same(c, a, "User message..."); // test ok.
      /// xtd::tunit::assume::are_not_same(b, a, "User message...", stack_frame); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_same(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::are_not_same(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::assume::are_same(b, a); // test ok.
      /// xtd::tunit::assume::are_same(c, a); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_same(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_same(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int a = 24;
      /// int& b = a;
      /// int c = 24;
      /// xtd::tunit::assume::are_same(b, a, "User message..."); // test ok.
      /// xtd::tunit::assume::are_same(c, a, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_same(const expected_t& expected, const actual_t& actual, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::are_same(expected, actual, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assume::contains(2, v1); // test ok.
      /// xtd::tunit::assume::contains(4, v1); // test throws an abort_error exception.
      /// ```
      template<class item_t, class collection_t>
      inline static void contains(const item_t& item, const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(item, collection, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assume::contains(2, v1, "User message..."); // test ok.
      /// xtd::tunit::assume::contains(4, v1, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class item_t, class collection_t>
      inline static void contains(const item_t& item, const collection_t& collection, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::contains(item, collection, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      template<class item_t, class value_t>
      inline static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(item, values, xtd::string::empty_string, stack_frame);}
      template<class item_t, class value_t>
      inline static void contains(const item_t& item, const std::initializer_list<value_t>& values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::contains(item, values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      static void contains(char item, const char* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void contains(char8 item, const char8* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void contains(char16 item, const char16* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void contains(char32 item, const char32* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void contains(wchar_t item, const wchar_t* values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(2);}); // test ok.
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(5);}); // test throws an abort_error exception.
      /// ```
      static void does_not_throw(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(2);}, "User message..."); // test ok.
      /// xtd::tunit::assume::does_not_throw([&] {v1.at(5);}, "User message..."); // test throws an abort_error exception.
      /// ```
      static void does_not_throw(const std::function<void()>& statement, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Assumes that collection contains an item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1;
      /// xtd::array<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assume::is_empty(v1); // test ok.
      /// xtd::tunit::assume::is_empty(v2); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1;
      /// xtd::array<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assume::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_empty(v2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_empty(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      template<class value_t>
      inline static void is_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_empty(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      inline static void is_empty(const std::initializer_list<value_t>& values, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_empty(values, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      static void is_empty(const char* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_empty(const char8* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_empty(const char16* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_empty(const char32* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_empty(const wchar_t* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that a condition is `false`.
      /// @param condition The condition to check is `false`.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assume::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2)); // test throws an abort_error exception.
      /// ```
      static void is_false(bool condition, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that a condition is `false`.
      /// @param condition The condition to check is `false`.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assume::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), "User message..."); // test throws an abort_error exception.
      /// ```
      static void is_false(bool condition, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Assumes that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_greater(24, 12); // test ok.
      /// xtd::tunit::assume::is_greater(24, 48); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_greater(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_greater(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assume::is_greater(24, 48, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_greater(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_greater(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_greater(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_greater_or_equal(24, 12); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 24); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 48); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_greater_or_equal(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_greater_or_equal(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assume::is_greater_or_equal(24, 48, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_greater_or_equal(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_greater_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_greater_or_equal(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater_or_equal(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater_or_equal(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater_or_equal(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_greater_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_instance_of<std::logic_error>(except); // test ok.
      /// xtd::tunit::assume::is_instance_of<std::bad_cast>(except); // test fails
      /// ```
      template<class type_t, class value_t>
      inline static void is_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_instance_of<type_t>(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_instance_of<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::assume::is_instance_of<std::bad_cast>(except, "User message..."); // test fails
      /// ```
      template<class type_t, class value_t>
      inline static void is_instance_of(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_instance_of<type_t>(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_less(24, 48); // test ok.
      /// xtd::tunit::assume::is_less(24, 12); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_less(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_less(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the first value is is_less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_less(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assume::is_less(24, 12, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_less(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_less(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_less(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_less_or_equal(24, 48); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 24); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 12); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_less_or_equal(val1, val2, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the first value is is_less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_less_or_equal(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assume::is_less_or_equal(24, 12, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value1_t, class value2_t>
      inline static void is_less_or_equal(const value1_t& val1, const value2_t& val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_less_or_equal(val1, val2, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      static void is_less_or_equal(const char* val1, const char* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less_or_equal(const char8* val1, const char8* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less_or_equal(const char16* val1, const char16* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less_or_equal(const char32* val1, const char32* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_less_or_equal(const wchar_t* val1, const wchar_t* val2, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1); // test ok.
      /// xtd::tunit::assume::is_NaN(v2); // test throws an abort_error exception.
      /// ```
      static void is_NaN(double value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message..."); // test throws an abort_error exception.
      /// ```
      static void is_NaN(double value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assume::is_NaN(v1); // test ok.
      /// xtd::tunit::assume::is_NaN(v2); // test throws an abort_error exception.
      /// ```
      static void is_NaN(long double value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// long double v1 = std::numeric_limits<long double>::quiet_NaN();
      /// long double v2 = 3.14159265358979323846l;
      /// xtd::tunit::assume::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message..."); // test throws an abort_error exception.
      /// ```
      static void is_NaN(long double value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1); // test ok.
      /// xtd::tunit::assume::is_NaN(v2); // test throws an abort_error exception.
      /// ```
      static void is_NaN(float value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assume::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_NaN(v2, "User message..."); // test throws an abort_error exception.
      /// ```
      static void is_NaN(float value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Assumes that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assume::is_negative(i1); // test ok.
      /// xtd::tunit::assume::is_negative(i2); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_negative(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_negative(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that ta condition is negative.
      /// @param value The value to check is negative.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = -1;
      /// int i2 = 1;
      /// xtd::tunit::assume::is_negative(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_negative(i2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_negative(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_negative(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {0, 1, 2, 3};
      /// xtd::array<int> v2;
      /// xtd::tunit::assume::is_not_empty(v1); // test ok.
      /// xtd::tunit::assume::is_not_empty(v2); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_not_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {0, 1, 2, 3};
      /// xtd::array<int> v2;
      /// xtd::tunit::assume::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_empty(v2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_not_empty(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @cond
      template<class value_t>
      inline static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      inline static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      static void is_not_empty(const char* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_not_empty(const char8* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_not_empty(const char16* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_not_empty(const char32* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      static void is_not_empty(const wchar_t* value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @endcond
      
      /// @brief Assumes that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_not_instance_of<std::bad_cast>(except); // test ok.
      /// xtd::tunit::assume::is_not_instance_of<std::logic_error>(except); // test fails
      /// ```
      template<class type_t, class value_t>
      inline static void is_not_instance_of(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_instance_of<type_t>(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::inassume_argument except("inassume argument");
      /// xtd::tunit::assume::is_not_instance_of<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_instance_of<std::logic_error>(except, "User message..."); // test fails
      /// ```
      template<class type_t, class value_t>
      inline static void is_not_instance_of(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_instance_of<type_t>(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const pointer_t* pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the optional is not std::nullopt.
      /// @param opt The optional to check is std::nullopt.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1 = "Anything";
      /// std::optional<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test throws an abort_error exception.
      /// ```
      template<class optional_t>
      inline static void is_not_null(const std::optional<optional_t>& opt, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_null(opt, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the optional is not std::nullopt.
      /// @param opt The optional to check is std::nullopt.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1 = "Anything";
      /// std::optional<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class optional_t>
      inline static void is_not_null(const std::optional<optional_t>& opt, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_null(opt, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1 = xtd::new_uptr<std::string>("Anything");
      /// xtd::uptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const xtd::uptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1 = xtd::new_uptr<std::string>("Anything");
      /// xtd::uptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const xtd::uptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1 = xtd::new_sptr<std::string>("Anything");
      /// xtd::sptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const xtd::sptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1 = xtd::new_sptr<std::string>("Anything");
      /// xtd::sptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const xtd::sptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1 = s;
      /// xtd::wptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1); // test ok.
      /// xtd::tunit::assume::is_not_null(s2); // test ok.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const xtd::wptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1 = s;
      /// xtd::wptr<std::string> s2;
      /// xtd::tunit::assume::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_null(s2, "User message..."); // test ok.
      /// ```
      template<class pointer_t>
      inline static void is_not_null(const xtd::wptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always `false`, a std::nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_not_null(nullptr); // test throws an abort_error exception.
      /// ```
      static void is_not_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always `false`, a std::nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_not_null(nullptr, "User message..."); // test throws an abort_error exception.
      /// ```
      static void is_not_null(std::nullptr_t pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Assumes that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assume::is_not_zero(i1); // test ok.
      /// xtd::tunit::assume::is_not_zero(i2); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_not_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_zero(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that ta condition is not zero.
      /// @param value The value to check is not zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 42;
      /// int i2 = 0;
      /// xtd::tunit::assume::is_not_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_not_zero(i2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_not_zero(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_not_zero(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assume::is_null(s1); // test ok.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const pointer_t* pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const pointer_t* pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the optional is std::nullopt.
      /// @param opt The optional to check is std::nullopt.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1;
      /// std::optional<std::string> s2 = "Anything";
      /// xtd::tunit::assume::is_null(s1); // test ok.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// ```
      template<class optional_t>
      inline static void is_null(const std::optional<optional_t>& opt, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_null(opt, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the optional is std::nullopt.
      /// @param pointer The optional to check is std::nullopt.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::optional<std::string> s1;
      /// std::optional<std::string> s2 = "Anything";
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class optional_t>
      inline static void is_null(const std::optional<optional_t>& opt, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_null(opt, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1;
      /// xtd::uptr<std::string> s2 = xtd::new_uptr<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1); // test ok.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const xtd::uptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::uptr<std::string> s1;
      /// xtd::uptr<std::string> s2 = xtd::new_uptr<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const xtd::uptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1;
      /// xtd::sptr<std::string> s2 = xtd::new_sptr<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1); // test ok.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const xtd::sptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s1;
      /// xtd::sptr<std::string> s2 = xtd::new_sptr<std::string>("Anything");
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const xtd::sptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always `false`, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1;
      /// xtd::wptr<std::string> s2 = s;
      /// xtd::tunit::assume::is_null(s1); // test throws an abort_error exception.
      /// xtd::tunit::assume::is_null(s2); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const xtd::wptr<pointer_t>& pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_null(pointer, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always `false`, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::sptr<std::string> s = xtd::new_sptr<std::string>("Anything");
      /// xtd::wptr<std::string> s1;
      /// xtd::wptr<std::string> s2 = s;
      /// xtd::tunit::assume::is_null(s1, "User message..."); // test throws an abort_error exception.
      /// xtd::tunit::assume::is_null(s2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class pointer_t>
      inline static void is_null(const xtd::wptr<pointer_t>& pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_null(pointer, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always `false`, a std::nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_null(nullptr); // test ok.
      /// ```
      static void is_null(std::nullptr_t pointer, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @remarks Always `false`, a std::nullptr_t is always equal to nullptr.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::tunit::assume::is_null(nullptr, "User message..."); // test ok.
      /// ```
      static void is_null(std::nullptr_t pointer, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Assumes that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assume::is_positive(i1); // test ok.
      /// xtd::tunit::assume::is_positive(i2); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_positive(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_positive(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that ta condition is positive.
      /// @param value The value to check is positive.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 1;
      /// int i2 = -1;
      /// xtd::tunit::assume::is_positive(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_positive(i2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_positive(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_positive(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that a condition is `true`.
      /// @param condition The condition to check is `true`.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assume::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2)); // test throws an abort_error exception.
      /// ```
      static void is_true(bool condition, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that a condition is `true`.
      /// @param condition The condition to check is `true`.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assume::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assume::is_false(std::empty(s2), "User message..."); // test throws an abort_error exception.
      /// ```
      static void is_true(bool condition, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Assumes that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assume::is_zero(i1); // test ok.
      /// xtd::tunit::assume::is_zero(i2); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_zero(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_zero(value, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that ta condition is zero.
      /// @param value The value to check is zero.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0;
      /// int i2 = 42;
      /// xtd::tunit::assume::is_zero(i1, "User message..."); // test ok.
      /// xtd::tunit::assume::is_zero(i2, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class value_t>
      inline static void is_zero(const value_t& value, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::is_zero(value, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(2);}); // test throws an abort_error exception.
      /// ```
      template<class exception_t>
      inline static void throws(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {throws<exception_t>(statement, xtd::string::empty_string, stack_frame);}
      /// @brief Assumes that the statement throws a particular exception when called.
      /// @tparam exception_t The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assume::throws<std::out_of_range>([&] {v1.at(2);}, "User message..."); // test throws an abort_error exception.
      /// ```
      template<class exception_t>
      inline static void throws(const std::function<void()>& statement, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          assert::throws<exception_t>(statement, message, stack_frame);
        } catch (...) {
          assert::abort();
        }
      }
      
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws_any([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assume::throws_any([&] {v1.at(2);}); // test throws an abort_error exception.
      /// ```
      static void throws_any(const std::function<void()>& statement, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Assumes that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::abort_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assume::throws_any([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assume::throws_any([&] {v1.at(2);}, "User message..."); // test throws an abort_error exception.
      /// ```
      static void throws_any(const std::function<void()>& statement, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @}
    };
  }
}
