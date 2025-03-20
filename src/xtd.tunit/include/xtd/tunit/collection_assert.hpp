/// @file
/// @brief Contains xtd::tunit::collection_assert class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The collection_assert class contains a collection of static methods that implement the most collection assertions used in xtd::tUnit.
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
    /// @include collection_assert.cpp
    class tunit_export_ collection_assert final : private base_assert {
    public:
      /// @cond
      collection_assert() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Asserts that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_assert::all_items_are_instances_of<std::ios_base*>(a); // test ok.
      /// xtd::tunit::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class collection_t>
      static void all_items_are_instances_of(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_instances_of<expected_t>(collection, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_assert::all_items_are_instances_of<std::ios_base*>(a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class collection_t>
      static void all_items_are_instances_of(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (auto item : collection)
          if (dynamic_cast<expected_t>(item) == nullptr) {
            fail("all items instance of <" + typeof_<expected_t>().full_name() + ">", join_items(collection), message, stack_frame);
            return;
          }
        succeed(message, stack_frame);
      }
      
      /// @cond
      template<class expected_t, class item_t>
      static void all_items_are_instances_of(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_instances_of<expected_t>(collection, xtd::string::empty_string, stack_frame);}
      template<class expected_t, class item_t>
      static void all_items_are_instances_of(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (auto item : collection)
          if (dynamic_cast<expected_t>(item) == nullptr) {
            fail("all items instance of <" + typeof_<expected_t>().full_name() + ">", join_items(collection), message, stack_frame);
            return;
          }
        succeed(message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0, i2 = 3;
      /// std::vector<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_assert::all_items_are_not_null(a1); // test ok.
      /// std::vector<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_assert::all_items_are_not_null(a2); // test throws an assert_error exception.
      /// ```
      template<class collection_t>
      static void all_items_are_not_null(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_not_null(collection, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0, i2 = 3;
      /// std::vector<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_assert::all_items_are_not_null(a1, "User message..."); // test ok.
      /// std::vector<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_assert::all_items_are_not_null(a2, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class collection_t>
      static void all_items_are_not_null(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (auto item : collection)
          if (item == nullptr) {
            fail("all items are not null", join_items(collection), message, stack_frame);
            return;
          }
        succeed(message, stack_frame);
      }
      
      /// @cond
      template<class item_t>
      static void all_items_are_not_null(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_not_null(collection, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      static void all_items_are_not_null(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (auto item : collection)
          if (item == nullptr) {
            fail("all items are not null", join_items(collection), message, stack_frame);
            return;
          }
        succeed(message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::all_items_are_unique(a1); // test ok.
      /// std::vector<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_assert::all_items_are_unique(a2); // test throws an assert_error exception.
      /// ```
      template<class collection_t>
      static void all_items_are_unique(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_unique(collection, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::all_items_are_unique(a1, "User message..."); // test ok.
      /// std::vector<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_assert::all_items_are_unique(a2, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class collection_t>
      static void all_items_are_unique(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        auto value = *collection.cbegin();
        std::map<decltype(value), int32> counts;
        for (auto item : collection) {
          auto result = counts.emplace(item, 1);
          if (result.second == false)
            fail("all items are unique", join_items(collection), message, stack_frame);
        }
        succeed(message, stack_frame);
      }
      
      /// @cond
      template<class item_t>
      static void all_items_are_unique(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_unique(collection, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      static void all_items_are_unique(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        std::map<item_t, int32> counts;
        for (auto item : collection) {
          auto result = counts.emplace(item, 1);
          if (result.second == false)
            fail("all items are unique", join_items(collection), message, stack_frame);
        }
        succeed(message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_equal({1, 2, 3, 4}, a); // test ok.
      /// xtd::tunit::collection_assert::are_equal({4, 3, 2, 1}, a); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_equal({1, 2, 3, 4}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::are_equal({4, 3, 2, 1}, a, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail(join_items(expected), join_items(actual), message, stack_frame);
      }
      
      /// @cond
      template<class item_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail(join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class collection_t, class item_t>
      static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail(join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class item_t, class collection_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail(join_items(expected), join_items(actual), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a); // test ok.
      /// xtd::tunit::collection_assert::are_equivalent({1, 2, 3, 5}, a); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_equivalent(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_equivalent({4, 3, 2, 1}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::are_equivalent({1, 2, 3, 5}, a, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      
      /// @cond
      template<class expected_t, class actual_t>
      static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class expected_t, class actual_t>
      static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class collection_t, class item_t>
      static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class item_t, class collection_t>
      static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that all collection items are not equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_not_equal({4, 3, 2, 1}, a); // test ok.
      /// xtd::tunit::collection_assert::are_not_equal({1, 2, 3, 4}, a); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that all collection items are not  equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_not_equal({4, 3, 2, 1}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::are_not_equal({1, 2, 3, 4}, a, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail("not " + join_items(expected), join_items(actual), message, stack_frame);
      }
      
      /// @cond
      template<class item_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail("not " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class collection_t, class item_t>
      static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail("not " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class item_t, class collection_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equals(actual.begin(), actual.end(), expected.begin(), expected.end())) succeed(message, stack_frame);
        else fail("not " + join_items(expected), join_items(actual), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_not_equivalent({1, 2, 3, 5}, a); // test ok.
      /// xtd::tunit::collection_assert::are_not_equivalent({4, 3, 2, 1}, a); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_not_equivalent(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::are_not_equivalent({1, 2, 3, 5}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::are_not_equivalent({4, 3, 2, 1}, a, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void are_not_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("not equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      
      /// @cond
      template<class expected_t, class actual_t>
      static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class expected_t, class actual_t>
      static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("not equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class collection_t, class item_t>
      static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("not equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class item_t, class collection_t>
      static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!equivalents(expected.begin(), expected.end(), actual.begin(), actual.end())) succeed(message, stack_frame);
        else fail("not equivalent " + join_items(expected), join_items(actual), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::contains({1, 2}, a); // test ok.
      /// xtd::tunit::collection_assert::contains({1, 2, 6}, a); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void contains(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::contains({1, 2}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::contains({1, 2, 6}, a, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void contains(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const auto& value) {return value == item;}) == std::end(actual)) {
            fail("contains " + join_items(expected), join_items(actual), message, stack_frame);
            return;
          }
        }
        succeed(message, stack_frame);
      }
      
      /// @cond
      template<class item_t>
      static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const item_t& value) {return value == item;}) == std::end(actual)) {
            fail("contains " + join_items(expected), join_items(actual), message, stack_frame);
            return;
          }
        }
        succeed(message, stack_frame);
      }
      template<class collection_t, class item_t>
      static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const item_t& value) {return value == item;}) == std::end(actual)) {
            fail("contains " + join_items(expected), join_items(actual), message, stack_frame);
            return;
          }
        }
        succeed(message, stack_frame);
      }
      template<class item_t, class collection_t>
      static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const item_t& value) {return value == item;}) == std::end(actual)) {
            fail("contains " + join_items(expected), join_items(actual), message, stack_frame);
            return;
          }
        }
        succeed(message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::does_not_contain({1, 2, 6}, a); // test ok.
      /// xtd::tunit::collection_assert::does_not_contain({1, 2}, a); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void does_not_contain(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_assert::does_not_contain({1, 2, 6}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::does_not_contain({1, 2}, a, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class expected_t, class actual_t>
      static void does_not_contain(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const auto& value) {return value == item;}) == std::end(actual)) {
            succeed(message, stack_frame);
            return;
          }
        }
        fail("not contains " + join_items(expected), join_items(actual), message, stack_frame);
      }
      
      /// @cond
      template<class item_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const item_t& value) {return value == item;}) == std::end(actual)) {
            succeed(message, stack_frame);
            return;
          }
        }
        fail("not contains " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class collection_t, class item_t>
      static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const item_t& value) {return value == item;}) == std::end(actual)) {
            succeed(message, stack_frame);
            return;
          }
        }
        fail("not contains " + join_items(expected), join_items(actual), message, stack_frame);
      }
      template<class item_t, class collection_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        for (const auto& item : expected) {
          if (std::find_if(std::begin(actual), std::end(actual), [&](const item_t& value) {return value == item;}) == std::end(actual)) {
            succeed(message, stack_frame);
            return;
          }
        }
        fail("not contains " + join_items(expected), join_items(actual), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::collection_assert::is_empty(v1); // test ok.
      /// xtd::tunit::collection_assert::is_empty(v2); // test throws an assert_error exception.
      /// ```
      template<class value_t>
      static void is_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::collection_assert::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::is_empty(v2, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class value_t>
      static void is_empty(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (std::empty(value)) succeed(message, stack_frame);
        else fail("<empty>", join_items(value), message, stack_frame);
      }
      
      /// @cond
      template<class value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_empty(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (std::empty(value)) succeed(message, stack_frame);
        else fail("<empty>", join_items(value), message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::collection_assert::is_not_empty(v1); // test ok.
      /// xtd::tunit::collection_assert::is_not_empty(v2); // test throws an assert_error exception.
      /// ```
      template<class value_t>
      static void is_not_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::collection_assert::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::is_not_empty(v2, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class value_t>
      static void is_not_empty(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!std::empty(value)) succeed(message, stack_frame);
        else fail("not <empty>", "<empty>", message, stack_frame);
      }
      
      /// @cond
      template<class value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (!std::empty(value)) succeed(message, stack_frame);
        else fail("not <empty>", "<empty>", message, stack_frame);
      }
      /// @endcond
      
      /// @brief Asserts that collection is ordered.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// std::vector<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::collection_assert::is_ordered(v1); // test ok.
      /// xtd::tunit::collection_assert::is_ordered(v2); // test throws an assert_error exception.
      /// ```
      template<class value_t>
      static void is_ordered(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_ordered(value, xtd::string::empty_string, stack_frame);}
      /// @brief Asserts that collection is ordered.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// ```cpp
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// std::vector<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::collection_assert::is_ordered(v1, "User message..."); // test ok.
      /// xtd::tunit::collection_assert::is_ordered(v2, "User message..."); // test throws an assert_error exception.
      /// ```
      template<class value_t>
      static void is_ordered(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (std::is_sorted(value.begin(), value.end())) succeed(message, stack_frame);
        else fail("<ordered>", join_items(value), message, stack_frame);
      }
      
      /// @cond
      template<class value_t>
      static void is_ordered(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_ordered(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      static void is_ordered(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        if (std::is_sorted(value.begin(), value.end())) succeed(message, stack_frame);
        else fail("<ordered>", join_items(value), message, stack_frame);
      }
      /// @endcond
      /// @}
      
    private:
      template <class expected_iterator_t, class actual_iterator_t>
      static bool equals(expected_iterator_t expected_begin, expected_iterator_t expected_end, actual_iterator_t actual_begin, actual_iterator_t actual_end) {
        return std::equal(expected_begin, expected_end, actual_begin, actual_end, [&](const auto& expected, const auto& actual) {return base_assert::equals(expected, actual);});
      }

      template <class expected_iterator_t, class actual_iterator_t>
      static bool equivalents(expected_iterator_t expected_begin, expected_iterator_t expected_end, actual_iterator_t actual_begin, actual_iterator_t actual_end) {
        if (std::distance(expected_begin, expected_end) != std::distance(actual_begin, actual_end)) return false;
        for (auto iterator = expected_begin; iterator != expected_end; ++iterator)
          if (std::find_if(actual_begin, actual_end, [&](const auto& value) {return base_assert::equals(value, *iterator);}) == actual_end) return false;
        return true;
      }
    };
  }
}
