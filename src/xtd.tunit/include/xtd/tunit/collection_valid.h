/// @file
/// @brief Contains xtd::tunit::collection_valid class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "valid.h"
#include "collection_valid.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The collection_valid class contains a collection of static methods that implement the most collection assertions used in xtd::tUnit.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class collection_valid final : private base_assert {
    public:
      /// @cond
      collection_valid() = delete;
      /// @endcond

      /// @brief Valids that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::ios_base*>(a); // test ok.
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::basic_ostream<char>*>(a); // test fails.
      /// @endcode
      template<typename expected_t, typename collection_t>
      static void all_items_are_instances_of(const collection_t& collection) {all_items_are_instances_of<expected_t>(collection, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::ios_base*>(a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename collection_t>
      static void all_items_are_instances_of(const collection_t& collection, const std::string& message) {all_items_are_instances_of<expected_t>(collection, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::ios_base*>(a, csf_); // test ok.
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::basic_ostream<char>*>(a, csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename collection_t>
      static void all_items_are_instances_of(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame) {all_items_are_instances_of<expected_t>(collection, "", stack_frame);}
      
      /// @brief Valids that all collection items are of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<std::ios_base*> a = {&std::cout, &std::cerr, &std::cin};
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::ios_base*>(a, "User message...", csf_); // test ok.
      /// xtd::tunit::collection_valid::all_items_are_instances_of<std::basic_ostream<char>*>(a, "User message...", csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename collection_t>
      static void all_items_are_instances_of(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::all_items_are_instances_of<expected_t>(collection, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename expected_t, typename item_t>
      static void all_items_are_instances_of(const std::initializer_list<item_t>& collection) {all_items_are_instances_of<expected_t>(collection, "", xtd::diagnostics::stack_frame::empty());}
      template<typename expected_t, typename item_t>
      static void all_items_are_instances_of(const std::initializer_list<item_t>& collection, const std::string& message) {all_items_are_instances_of<expected_t>(collection, message, xtd::diagnostics::stack_frame::empty());}
      template<typename expected_t, typename item_t>
      static void all_items_are_instances_of(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame) {all_items_are_instances_of<expected_t>(collection, "", stack_frame);}
      template<typename expected_t, typename item_t>
      static void all_items_are_instances_of(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::all_items_are_instances_of<expected_t>(collection, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 0, i2 = 3;
      /// std::vector<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a1); // test ok.
      /// std::vector<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a2); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_not_null(const collection_t& collection) {all_items_are_not_null(collection, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 0, i2 = 3;
      /// std::vector<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a1, "User message..."); // test ok.
      /// std::vector<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a2, "User message..."); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_not_null(const collection_t& collection, const std::string& message) {all_items_are_not_null(collection, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 0, i2 = 3;
      /// std::vector<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a1, csf_); // test ok.
      /// std::vector<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a2, csf_); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_not_null(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame) {all_items_are_instances_of(collection, "", stack_frame);}
      
      /// @brief Valids that all collection items are not null.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int i1 = 0, i2 = 3;
      /// std::vector<int*> a1 = {&i1, &i2};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a1, "User message...", csf_); // test ok.
      /// std::vector<int*> a2 = {&i1, &i2, nullptr};
      /// xtd::tunit::collection_valid::all_items_are_not_null(a2, "User message...", csf_); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_not_null(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::all_items_are_not_null(collection, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }

      /// @cond
      template<typename item_t>
      static void all_items_are_not_null(const std::initializer_list<item_t>& collection) {all_items_are_not_null(collection, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void all_items_are_not_null(const std::initializer_list<item_t>& collection, const std::string& message) {all_items_are_not_null(collection, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void all_items_are_not_null(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame) {all_items_are_instances_of(collection, "", stack_frame);}
      template<typename item_t>
      static void all_items_are_not_null(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::all_items_are_not_null(collection, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::all_items_are_unique(a1); // test ok.
      /// std::vector<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_valid::all_items_are_unique(a2); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_unique(const collection_t& collection) {all_items_are_unique(collection, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::all_items_are_unique(a1, "User message..."); // test ok.
      /// std::vector<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_valid::all_items_are_unique(a2, "User message..."); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_unique(const collection_t& collection, const std::string& message) {all_items_are_unique(collection, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::all_iall_items_are_uniquetems_are_not_null(a1, csf_); // test ok.
      /// std::vector<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_valid::all_items_are_unique(a2, csf_); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_unique(const collection_t& collection, const xtd::diagnostics::stack_frame& stack_frame) {all_items_are_unique(collection, "", stack_frame);}
      
      /// @brief Valids that all collection items are unique.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a1 = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::all_items_are_unique(a1, "User message...", csf_); // test ok.
      /// std::vector<int> a2 = {1, 2, 3, 4, 1};
      /// xtd::tunit::collection_valid::all_items_are_unique(a2, "User message...", csf_); // test fails.
      /// @endcode
      template<typename collection_t>
      static void all_items_are_unique(const collection_t& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::all_items_are_unique(collection, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }

      /// @cond
      template<typename item_t>
      static void all_items_are_unique(const std::initializer_list<item_t>& collection) {all_items_are_unique(collection, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void all_items_are_unique(const std::initializer_list<item_t>& collection, const xtd::diagnostics::stack_frame& stack_frame) {all_items_are_unique(collection, "", stack_frame);}
      template<typename item_t>
      static void all_items_are_unique(const std::initializer_list<item_t>& collection, const std::string& message) {all_items_are_unique(collection, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void all_items_are_unique(const std::initializer_list<item_t>& collection, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::all_items_are_unique(collection, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equal({1, 2, 3, 4}, a); // test ok.
      /// xtd::tunit::collection_valid::are_equal({4, 3, 2, 1}, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equal({1, 2, 3, 4}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_equal({4, 3, 2, 1}, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equal({1, 2, 3, 4}, a, csf_); // test ok.
      /// xtd::tunit::collection_valid::are_equal({4, 3, 2, 1}, a, csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      
      /// @brief Valids that all collection items are equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equal({1, 2, 3, 4}, a, "User message...", csf_); // test ok.
      /// xtd::tunit::collection_valid::are_equal({4, 3, 2, 1}, a, "User message...", csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equal(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      template<typename item_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename collection_t, typename item_t>
      static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      template<typename collection_t, typename item_t>
      static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t, typename collection_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual) {are_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equal(expected, actual, "", stack_frame);}
      template<typename item_t, typename collection_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message) {are_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equivalent({4, 3, 2, 1}, a); // test ok.
      /// xtd::tunit::collection_valid::are_equivalent({1, 2, 3, 5}, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const expected_t& expected, const actual_t& actual) {are_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equivalent({4, 3, 2, 1}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_equivalent({1, 2, 3, 5}, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message) {are_equivalent(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equivalent({4, 3, 2, 1}, a, csf_); // test ok.
      /// xtd::tunit::collection_valid::are_equivalent({1, 2, 3, 5}, a, csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equivalent(expected, actual, "", stack_frame);}
      
      /// @brief Valids that all collection items are equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_equivalent({4, 3, 2, 1}, a, "User message...", csf_); // test ok.
      /// xtd::tunit::collection_valid::are_equivalent({1, 2, 3, 5}, a, "User message...", csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual) {are_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equivalent(expected, actual, "", stack_frame);}
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message) {are_equal(are_equivalent, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename expected_t, typename actual_t>
      static void are_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename collection_t, typename item_t>
      static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual) {are_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equivalent(expected, actual, "", stack_frame);}
      template<typename collection_t, typename item_t>
      static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message) {are_equivalent(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t, typename collection_t>
      static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual) {are_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_equivalent(expected, actual, "", stack_frame);}
      template<typename item_t, typename collection_t>
      static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message) {are_equivalent(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that all collection items are not equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equal({4, 3, 2, 1}, a); // test ok.
      /// xtd::tunit::collection_valid::are_not_equal({1, 2, 3, 4}, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are not equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equal({4, 3, 2, 1}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_not_equal({1, 2, 3, 4}, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are not equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equal({4, 3, 2, 1}, a, csf_); // test ok.
      /// xtd::tunit::collection_valid::are_not_equal({1, 2, 3, 4}, a, csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      
      /// @brief Valids that all collection items arenot  equal.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equal({4, 3, 2, 1}, a, "User message...", csf_); // test ok.
      /// xtd::tunit::collection_valid::are_not_equal({1, 2, 3, 4}, a, "User message...", csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equal(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      template<typename item_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename collection_t, typename item_t>
      static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      template<typename collection_t, typename item_t>
      static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_not_equal(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t, typename collection_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual) {are_not_equal(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equal(expected, actual, "", stack_frame);}
      template<typename item_t, typename collection_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message) {are_not_equal(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_not_equal(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equal(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond
 
      /// @brief Valids that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equivalent({1, 2, 3, 5}, a); // test ok.
      /// xtd::tunit::collection_valid::are_not_equivalent({4, 3, 2, 1}, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const expected_t& expected, const actual_t& actual) {are_not_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equivalent({1, 2, 3, 5}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::are_not_equivalent({4, 3, 2, 1}, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message) {are_not_equivalent(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equivalent({1, 2, 3, 5}, a, csf_); // test ok.
      /// xtd::tunit::collection_valid::are_not_equivalent({4, 3, 2, 1}, a, csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equivalent(expected, actual, "", stack_frame);}
      
      /// @brief Valids that all collection items are not equivalent.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::are_not_equivalent({1, 2, 3, 5}, a, "User message...", csf_); // test ok.
      /// xtd::tunit::collection_valid::are_not_equivalent({4, 3, 2, 1}, a, "User message...", csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual) {are_not_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equivalent(expected, actual, "", stack_frame);}
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message) {are_not_equivalent(are_equivalent, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename expected_t, typename actual_t>
      static void are_not_equivalent(const std::initializer_list<expected_t>& expected, const std::initializer_list<actual_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename collection_t, typename item_t>
      static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual) {are_not_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equivalent(expected, actual, "", stack_frame);}
      template<typename collection_t, typename item_t>
      static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message) {are_not_equivalent(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void are_not_equivalent(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t, typename collection_t>
      static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual) {are_not_equivalent(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {are_not_equivalent(expected, actual, "", stack_frame);}
      template<typename item_t, typename collection_t>
      static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message) {are_not_equivalent(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void are_not_equivalent(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::are_not_equivalent(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that ollection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::contains({1, 2, a); // test ok.
      /// xtd::tunit::collection_valid::contains({1, 2, 6}, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void contains(const expected_t& expected, const actual_t& actual) {contains(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::contains({1, 2}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::contains({1, 2, 6}, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void contains(const expected_t& expected, const actual_t& actual, const std::string& message) {contains(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::contains({1, 2}, a, csf_); // test ok.
      /// xtd::tunit::collection_valid::contains({1, 2, 6}, a, csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void contains(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {contains(expected, actual, "", stack_frame);}
      
      /// @brief Valids that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::contains({1, 2}, a, "User message...", csf_); // test ok.
      /// xtd::tunit::collection_valid::contains({1, 2, 6}, a, "User message...", csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void contains(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t>
      static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual) {contains(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {contains(expected, actual, "", stack_frame);}
      template<typename item_t>
      static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message) {contains(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void contains(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename collection_t, typename item_t>
      static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual) {contains(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {contains(expected, actual, "", stack_frame);}
      template<typename collection_t, typename item_t>
      static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message) {contains(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void contains(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t, typename collection_t>
      static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual) {contains(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {contains(expected, actual, "", stack_frame);}
      template<typename item_t, typename collection_t>
      static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message) {contains(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void contains(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::contains(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond

      /// @brief Valids that ollection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::does_not_contain({1, 2, a); // test ok.
      /// xtd::tunit::collection_valid::does_not_contain({1, 2, 6}, a); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void does_not_contain(const expected_t& expected, const actual_t& actual) {does_not_contain(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::does_not_contain({1, 2}, a, "User message..."); // test ok.
      /// xtd::tunit::collection_valid::does_not_contain({1, 2, 6}, a, "User message..."); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void does_not_contain(const expected_t& expected, const actual_t& actual, const std::string& message) {does_not_contain(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::does_not_contain({1, 2}, a, csf_); // test ok.
      /// xtd::tunit::collection_valid::does_not_contain({1, 2, 6}, a, csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void does_not_contain(const expected_t& expected, const actual_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {does_not_contain(expected, actual, "", stack_frame);}
      
      /// @brief Valids that collection contains all items.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> a = {1, 2, 3, 4};
      /// xtd::tunit::collection_valid::does_not_contain({1, 2}, a, "User message...", csf_); // test ok.
      /// xtd::tunit::collection_valid::does_not_contain({1, 2, 6}, a, "User message...", csf_); // test fails.
      /// @endcode
      template<typename expected_t, typename actual_t>
      static void does_not_contain(const expected_t& expected, const actual_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual) {does_not_contain(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {does_not_contain(expected, actual, "", stack_frame);}
      template<typename item_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message) {does_not_contain(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename collection_t, typename item_t>
      static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual) {does_not_contain(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual, const xtd::diagnostics::stack_frame& stack_frame) {does_not_contain(expected, actual, "", stack_frame);}
      template<typename collection_t, typename item_t>
      static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message) {does_not_contain(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename collection_t, typename item_t>
      static void does_not_contain(const collection_t& expected, const std::initializer_list<item_t>& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename item_t, typename collection_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual) {does_not_contain(expected, actual, "", xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual, const xtd::diagnostics::stack_frame& stack_frame) {does_not_contain(expected, actual, "", stack_frame);}
      template<typename item_t, typename collection_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message) {does_not_contain(expected, actual, message, xtd::diagnostics::stack_frame::empty());}
      template<typename item_t, typename collection_t>
      static void does_not_contain(const std::initializer_list<item_t>& expected, const collection_t& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::does_not_contain(expected, actual, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond
      
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1); // test ok.
      /// xtd::tunit::assert::is_empty(v2); // test fails
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value) {is_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, csf_); // test fails
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_empty(value, "", stack_frame);}
      
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message..."); // test fails
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const std::string& message) {is_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message...", csf_); // test fails
      /// @endcode
      template<typename value_t>
      static void is_empty(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::is_empty(value, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value) {is_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame) {is_empty(value, "", stack_frame);}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const std::string& message) {is_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_empty(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::is_empty(value, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond
      
      /// @brief Valids that collection does not contain any item.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2); // test fails
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value) {is_not_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, csf_); // test fails
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_empty(value, "", stack_frame);}
      
      /// @brief Valids that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message..."); // test fails
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const std::string& message) {is_not_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message...", csf_); // test fails
      /// @endcode
      template<typename value_t>
      static void is_not_empty(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::is_not_empty(value, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value) {is_not_empty(value, "", xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame) {is_not_empty(value, "", stack_frame);}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const std::string& message) {is_not_empty(value, message, xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_not_empty(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::is_not_empty(value, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond
      
      /// @brief Valids that collection is ordered.
      /// @param value The value to check is empty.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// std::vector<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::assert::is_ordered(v1); // test ok.
      /// xtd::tunit::assert::is_ordered(v2); // test fails
      /// @endcode
      template<typename value_t>
      static void is_ordered(const value_t& value) {is_ordered(value, "", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection is ordered.
      /// @param value The value to check is empty.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// std::vector<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::assert::is_ordered(v1, csf_); // test ok.
      /// xtd::tunit::assert::is_ordered(v2, csf_); // test fails
      /// @endcode
      template<typename value_t>
      static void is_ordered(const value_t& value, const xtd::diagnostics::stack_frame& stack_frame) {is_ordered(value, "", stack_frame);}
      
      /// @brief Valids that collection is ordered.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// std::vector<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::assert::is_ordered(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_ordered(v2, "User message..."); // test fails
      /// @endcode
      template<typename value_t>
      static void is_ordered(const value_t& value, const std::string& message) {is_ordered(value, message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Valids that collection is ordered.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// std::vector<int> v2 = {1, 2, 4, 3};
      /// xtd::tunit::assert::is_ordered(v1, "User message...", csf_); // test ok.
      /// xtd::tunit::assert::is_ordered(v2, "User message...", csf_); // test fails
      /// @endcode
      template<typename value_t>
      static void is_ordered(const value_t& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::is_ordered(value, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      
      /// @cond
      template<typename value_t>
      static void is_ordered(const std::initializer_list<value_t>& value) {is_ordered(value, "", xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_ordered(const std::initializer_list<value_t>& value, const xtd::diagnostics::stack_frame& stack_frame) {is_ordered(value, "", stack_frame);}
      template<typename value_t>
      static void is_ordered(const std::initializer_list<value_t>& value, const std::string& message) {is_ordered(value, message, xtd::diagnostics::stack_frame::empty());}
      template<typename value_t>
      static void is_ordered(const std::initializer_list<value_t>& value, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        try {
          collection_assert::is_ordered(value, message, stack_frame);
        } catch(...) {
          base_assert::error();
        }
      }
      /// @endcond
    };
  }
}
