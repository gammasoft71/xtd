/// @file
/// @brief Contains xtd::tunit::collection_valid class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "valid.hpp"
#include "collection_assert.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The collection_valid class contains a collection of static methods that implement the most collection assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit validations
    /// @remarks Validations are the same as assertions with the difference, no exception is thrown, but an error is generated.
    /// @remarks If a validation fails, he test can be continued to the end or to an assertion is generated.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include collection_valid.cpp
    class tunit_export_ collection_valid final : private base_assert {
    public:
      /// @cond
      collection_valid() = delete;
      /// @endcond
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Validates that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::ios_base*>(a); // test ok.
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::basic_ostream<char>*>(a); // test fails.
      /// ```
      template<class expected_t, class collection_t>
      inline static void all_items_are_instances_of(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_instances_of<expected_t>(collection, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::ios_base*>(a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message..."); // test fails.
      /// ```
      template<class expected_t, class collection_t>
      inline static void all_items_are_instances_of(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::all_items_are_instances_of<expected_t>(collection, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class expected_t, class item_t>
      inline static void all_items_are_instances_of(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_instances_of<expected_t>(collection, xtd::string::empty_string, stack_frame);}
      template<class expected_t, class item_t>
      inline static void all_items_are_instances_of(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::all_items_are_instances_of<expected_t>(collection, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0, i2 = 3;
      /// xtd::array<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a1); // test ok.
      /// xtd::array<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a2); // test fails.
      /// ```
      template<class collection_t>
      inline static void all_items_are_not_null(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_not_null(collection, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// int i1 = 0, i2 = 3;
      /// xtd::array<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a1, "User message..."); // test ok.
      /// xtd::array<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a2, "User message..."); // test fails.
      /// ```
      template<class collection_t>
      inline static void all_items_are_not_null(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::all_items_are_not_null(collection, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class item_t>
      inline static void all_items_are_not_null(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_not_null(collection, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      inline static void all_items_are_not_null(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::all_items_are_not_null(collection, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::all_items_are_unique(a1); // test ok.
      /// xtd::array<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_valid::all_items_are_unique(a2); // test fails.
      /// ```
      template<class collection_t>
      inline static void all_items_are_unique(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_unique(collection, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::all_items_are_unique(a1, "User message..."); // test ok.
      /// xtd::array<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_valid::all_items_are_unique(a2, "User message..."); // test fails.
      /// ```
      template<class collection_t>
      inline static void all_items_are_unique(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::all_items_are_unique(collection, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class item_t>
      inline static void all_items_are_unique(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {all_items_are_unique(collection, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      inline static void all_items_are_unique(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::all_items_are_unique(collection, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equal({1, 2, 3, 4}, a); // test ok.
      /// xtd::tunit::collection_valid::are_equal({4, 3, 2, 1}, a); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equal({1, 2, 3, 4}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_equal({4, 3, 2, 1}, a, "User message..."); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_equal(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class item_t>
      inline static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      inline static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class collection_t, class item_t>
      inline static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      inline static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class item_t, class collection_t>
      inline static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      inline static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equivalent({4, 3, 2, 1}, a); // test ok.
      /// xtd::tunit::collection_valid::are_equivalent({1, 2, 3, 5}, a); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_equivalent(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equivalent({4, 3, 2, 1}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_equivalent({1, 2, 3, 5}, a, "User message..."); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class expected_t, class actual_t>
      inline static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class expected_t, class actual_t>
      inline static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class collection_t, class item_t>
      inline static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      inline static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class item_t, class collection_t>
      inline static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      inline static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that all collection items are not equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equal({4, 3, 2, 1}, a); // test ok.
      /// xtd::tunit::collection_valid::are_not_equal({1, 2, 3, 4}, a); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that all collection items are not  equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equal({4, 3, 2, 1}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_not_equal({1, 2, 3, 4}, a, "User message..."); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_equal(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class item_t>
      inline static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      inline static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class collection_t, class item_t>
      inline static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      inline static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class item_t, class collection_t>
      inline static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equal(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      inline static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equivalent({1, 2, 3, 5}, a); // test ok.
      /// xtd::tunit::collection_valid::are_not_equivalent({4, 3, 2, 1}, a); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_equivalent(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equivalent({1, 2, 3, 5}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_not_equivalent({4, 3, 2, 1}, a, "User message..."); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void are_not_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class expected_t, class actual_t>
      inline static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class expected_t, class actual_t>
      inline static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class collection_t, class item_t>
      inline static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      inline static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class item_t, class collection_t>
      inline static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {are_not_equivalent(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      inline static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::contains({1, 2}, a); // test ok.
      /// xtd::tunit::collection_valid::contains({1, 2, 6}, a); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void contains(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::contains({1, 2}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::contains({1, 2, 6}, a, "User message..."); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void contains(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class item_t>
      inline static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      inline static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class collection_t, class item_t>
      inline static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      inline static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class item_t, class collection_t>
      inline static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {contains(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      inline static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::does_not_contain({1, 2, 6}, a); // test ok.
      /// xtd::tunit::collection_valid::does_not_contain({1, 2}, a); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void does_not_contain(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::does_not_contain({1, 2, 6}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::does_not_contain({1, 2}, a, "User message..."); // test fails.
      /// ```
      template<class expected_t, class actual_t>
      inline static void does_not_contain(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class item_t>
      inline static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t>
      inline static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class collection_t, class item_t>
      inline static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class collection_t, class item_t>
      inline static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      template<class item_t, class collection_t>
      inline static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {does_not_contain(expected, actual, xtd::string::empty_string, stack_frame);}
      template<class item_t, class collection_t>
      inline static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that collection contains an item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1;
      /// xtd::array<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::collection_valid:is_empty(v1); // test ok.
      /// xtd::tunit::collection_valid:is_empty(v2); // test fails
      /// ```
      template<class value_t>
      inline static void is_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1;
      /// xtd::array<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::collection_valid:is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::collection_valid:is_empty(v2, "User message..."); // test fails
      /// ```
      template<class value_t>
      inline static void is_empty(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::is_empty(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class value_t>
      inline static void is_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_empty(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      inline static void is_empty(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::is_empty(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {0, 1, 2, 3};
      /// xtd::array<int> v2;
      /// xtd::tunit::collection_valid:is_not_empty(v1); // test ok.
      /// xtd::tunit::collection_valid:is_not_empty(v2); // test fails
      /// ```
      template<class value_t>
      inline static void is_not_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {0, 1, 2, 3};
      /// xtd::array<int> v2;
      /// xtd::tunit::collection_valid:is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::collection_valid:is_not_empty(v2, "User message..."); // test fails
      /// ```
      template<class value_t>
      inline static void is_not_empty(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class value_t>
      inline static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_not_empty(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      inline static void is_not_empty(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::is_not_empty(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      
      /// @brief Validates that collection is ordered.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::array<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::collection_valid:is_ordered(v1); // test ok.
      /// xtd::tunit::collection_valid:is_ordered(v2); // test fails
      /// ```
      template<class value_t>
      inline static void is_ordered(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_ordered(value, xtd::string::empty_string, stack_frame);}
      /// @brief Validates that collection is ordered.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// ```cpp
      /// xtd::array<int> v1 = {1, 2, 3, 4};
      /// xtd::array<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::collection_valid:is_ordered(v1, "User message..."); // test ok.
      /// xtd::tunit::collection_valid:is_ordered(v2, "User message..."); // test fails
      /// ```
      template<class value_t>
      inline static void is_ordered(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::is_ordered(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      
      /// @cond
      template<class value_t>
      inline static void is_ordered(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {is_ordered(value, xtd::string::empty_string, stack_frame);}
      template<class value_t>
      inline static void is_ordered(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        try {
          collection_assert::is_ordered(value, message, stack_frame);
        } catch (...) {
          error();
        }
      }
      /// @endcond
      /// @}
    };
  }
}
