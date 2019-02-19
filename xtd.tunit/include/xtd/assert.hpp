/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "__demangle.hpp"
#include "__join__items.hpp"
#include "assert_error.hpp"
#include "default_insert_basic_ostream_operator.hpp"
#include "line_info.hpp"
#include <algorithm>
#include <cmath>
#include <exception>
#include <functional>
#include <iterator>
#include <memory>
#include <string>

/// @cond
#ifdef assert
#undef assert
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The assert class contains a collection of static methods that implement the most common assertions used in xtd::tUnit.
    /// @par Examples
    /// This example show how to used some methods :
    /// @include assert.cpp
    class assert final {
    public:
      /// @cond
      assert() = delete;
      /// @endcond
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24)); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), line_info_); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), "User message..."); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_equal(24, int(24), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_equal(23, int(24), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (actual == expected)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: " << expected << "\nBut was:  " << actual;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24)); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), line_info_); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message..."); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_not_equal(24, int(24), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (actual != expected)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: not " << expected << "\nBut was:  " << actual;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual) {are_not_same(expected, actual, "", line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, line_info_); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, line_info); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_not_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message..."); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_not_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_not_same(b, a, "User message...", line_info); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (&actual != &expected)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: not same as " << expected << "\nBut was:  " << actual;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a); // test ok.
      /// xtd::tunit::assert::are_same(c, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual) {are_same(expected, actual, "", line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, line_info_); // test ok.
      /// xtd::tunit::assert::are_same(c, a, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message..."); // test ok.
      /// xtd::tunit::assert::are_same(c, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::are_same(c, a, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (&actual == &expected)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: same as " << expected << "\nBut was:  " << actual;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1); // test ok.
      /// xtd::tunit::assert::contains(4, v1); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection) {contains(item, collection, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, line_info_); // test ok.
      /// xtd::tunit::assert::contains(4, v1, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const xtd::tunit::line_info& line_info) {contains(item, collection, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message..."); // test ok.
      /// xtd::tunit::assert::contains(4, v1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message) {contains(item, collection, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::contains(4, v1, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(collection.begin(), collection.end(), item);
        if (result != collection.end())
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: collection containing " << item << "\nBut was:  < " << __join__items(collection) << " >";
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement) {does_not_throw(statement, "", line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, line_info_); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {does_not_throw(statement, "", line_info);}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, "User message..."); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const std::string& message) {does_not_throw(statement, message, line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(2);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::does_not_throw([&] {v1.at(5);}, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throw(const std::function<void()>& statement, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          statement();
          succeed(message, line_info);
        } catch (const std::exception& e) {
          fail("Expected: No Exception to be thrown\nBut was:  <" + __demangle(typeid(e).name()) + ">", message, line_info);
        } catch (...) {
          fail("Expected: No Exception to be thrown\nBut was:  <exception>", message, line_info);
        }
      }
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail() {fail("", line_info());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const xtd::tunit::line_info& line_info) {fail("", line_info);}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message) {fail(message, line_info());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message, const xtd::tunit::line_info& line_info) {
        fail("Failled", message, line_info);
      }

      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param fail_message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("Fail message", "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& failed_message, const std::string& message, const xtd::tunit::line_info& line_info);

      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12); // test ok.
      /// xtd::tunit::assert::greater(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater(const TValue1& val1, const TValue2& val2) {greater(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12, line_info_); // test ok.
      /// xtd::tunit::assert::greater(24, 48, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {greater(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assert::greater(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater(const TValue1& val1, const TValue2& val2, const std::string& message) {greater(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is greater than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::greater(24, 48, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 > val2)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: greater than " << val2 << "\nBut was:  " << val1;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 24); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater_or_equal(const TValue1& val1, const TValue2& val2) {greater_or_equal(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12, line_info_); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 24, line_info_); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 48, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater_or_equal(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {greater_or_equal(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12, "User message..."); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message) {greater_or_equal(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 24, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::greater_or_equal(24, 48, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 >= val2)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: greater than or equal to " << val2 << "\nBut was:  " << val1;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that collection or traits contains an item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1); // test ok.
      /// xtd::tunit::assert::is_empty(v2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value) {is_empty(value, "", line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value, const xtd::tunit::line_info& line_info) {is_empty(value, "", line_info);}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value, const std::string& message) {is_empty(value, message, line_info());}
      
      /// @brief Asserts that collection contains an item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_empty(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_empty(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::empty(value))
          succeed(message, line_info);
        else
          fail("Expected: collection <empty>\nBut was:  < " + __join__items(value) + " >", message, line_info);
      }

      /// @brief Asserts that ta condition is false.
      /// @param condition The condition to check is false.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2)); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition) {is_false(condition, "", line_info());}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::tunit::line_info& line_info) {is_false(condition, "", line_info);}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const std::string& message) {is_false(condition, message, line_info());}
      
      /// @brief Asserts that a condition is false.
      /// @param condition The condition to check is false.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (condition == false)
          succeed(message, line_info);
        else
          fail("Expected: false\nBut was:  true", message, line_info);
      }
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value) {is_instance_of<Type>(value, "", line_info());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, line_info_); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value, const xtd::tunit::line_info& line_info) {is_instance_of<Type>(value, "", line_info);}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value, const std::string& message) {is_instance_of<Type>(value, message, line_info());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of<std::logic_error>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_instance_of<std::bad_cast>(except, "User message...", line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_instance_of(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (dynamic_cast<const Type*>(&value) != nullptr)
          succeed(message, line_info);
        else
          fail("Expected: instance of <" + __demangle(typeid(Type).name()) + ">\nBut was:  <" + __demangle(typeid(value).name()) + ">", message, line_info);
      }
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of_type<std::logic_error>(except); // test ok.
      /// xtd::tunit::assert::is_instance_of_type<std::bad_cast>(except); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_instance_of_type(const TValue& value) {is_instance_of_type<Type>(value, "", line_info());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of_type<std::logic_error>(except, line_info_); // test ok.
      /// xtd::tunit::assert::is_instance_of_type<std::bad_cast>(except, line_info_); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_instance_of_type(const TValue& value, const xtd::tunit::line_info& line_info) {is_instance_of_type<Type>(value, "", line_info);}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of_type<std::logic_error>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_instance_of_type<std::bad_cast>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_instance_of_type(const TValue& value, const std::string& message) {is_instance_of_type<Type>(value, message, line_info());}
      
      /// @brief Asserts that an object is of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_instance_of_type<std::logic_error>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_instance_of_type<std::bad_cast>(except, "User message...", line_info_); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_instance_of_type(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {is_instance_of<Type>(value, message, line_info);}

      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const std::string& message) {is_NaN(value, message, line_info());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// double v1 = std::numeric_limits<double>::quiet_NaN();
      /// double v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(double value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(value))
          succeed(message, line_info);
        else
          fail("Expected: false\nBut was:  true", message, line_info);
      }

      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1); // test ok.
      /// xtd::tunit::assert::is_NaN(v2); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value) {is_NaN(value, "", line_info());}
      
      /// @brief that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const xtd::tunit::line_info& line_info) {is_NaN(value, "", line_info);}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const std::string& message) {is_NaN(value, message, line_info());}
      
      /// @brief Asserts that a value is NaN.
      /// @param value The value to check is NaN.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// float v1 = std::numeric_limits<float>::quiet_NaN();
      /// float v2 = 3.14159265358979323846;
      /// xtd::tunit::assert::is_NaN(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_NaN(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_NaN(float value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::isnan(value))
          succeed(message, line_info);
        else
          fail("Expected: false\nBut was:  true", message, line_info);
      }
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value) {is_not_empty(value, "", line_info());}
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value, const xtd::tunit::line_info& line_info) {is_not_empty(value, "", line_info);}
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value, const std::string& message) {is_not_empty(value, message, line_info());}
      
      /// @brief Asserts that collection or traits does not contain any item.
      /// @param value The value to check is empty.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// std::vector<int> v2;
      /// xtd::tunit::assert::is_not_empty(v1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_empty(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue>
      static void is_not_empty(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (!std::empty(value))
          succeed(message, line_info);
        else
          fail("Expected: collection not <empty>\nBut was:  <empty>", message, line_info);
      }
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value) {is_not_instance_of<Type>(value, "", line_info());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value, const xtd::tunit::line_info& line_info) {is_not_instance_of<Type>(value, "", line_info);}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value, const std::string& message) {is_not_instance_of<Type>(value, message, line_info());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of<std::bad_cast>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of<std::logic_error>(except, "User message...", line_info_); test throws an assertion_error exception.
      /// @endcode
      template<typename Type, typename TValue>
      static void is_not_instance_of(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (dynamic_cast<const Type*>(&value) == nullptr)
          succeed(message, line_info);
        else
          fail("Expected: instance of <" + __demangle(typeid(Type).name()) + ">\nBut was:  <" + __demangle(typeid(value).name()) + ">", message, line_info);
      }
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of_type<std::bad_cast>(except); // test ok.
      /// xtd::tunit::assert::is_not_instance_of_type<std::logic_error>(except); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_not_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_not_instance_of_type(const TValue& value) {is_not_instance_of_type<Type>(value, "", line_info());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of_type<std::bad_cast>(except, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of_type<std::logic_error>(except, line_info_); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_not_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_not_instance_of_type(const TValue& value, const xtd::tunit::line_info& line_info) {is_not_instance_of_type<Type>(value, "", line_info);}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of_type<std::bad_cast>(except, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_instance_of_type<std::logic_error>(except, "User message..."); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_not_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_not_instance_of_type(const TValue& value, const std::string& message) {is_not_instance_of_type<Type>(value, message, line_info());}
      
      /// @brief Asserts that an object is not of the type supplied or a derived type.
      /// @param value The object to verify
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::invalid_argument except("invalid argument");
      /// xtd::tunit::assert::is_not_instance_of_type<std::bad_cast>(except, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_instance_of_type<std::logic_error>(except, "User message...", line_info_); test throws an assertion_error exception.
      /// @endcode
      /// @see td::tunit::assert::is_not_instance_of<Type, TValue>
      template<typename Type, typename TValue>
      static void is_not_instance_not_of_type(const TValue& value, const std::string& message, const xtd::tunit::line_info& line_info) {is_not_instance_of<Type>(value, message, line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const TPointer* pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer != nullptr)
          succeed(message, line_info);
        else
          fail("Expected: not null\nBut was:  null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::unique_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer != nullptr)
          succeed(message, line_info);
        else
          fail("Expected: not null\nBut was:  null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::shared_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer != nullptr)
          succeed(message, line_info);
        else
          fail("Expected: not null\nBut was:  null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1); // test ok.
      /// xtd::tunit::assert::is_not_null(s2); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer) {is_not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, line_info_); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message..."); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer, const std::string& message) {is_not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::is_not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_not_null(s2, "User message...", line_info_); // test ok.
      /// @endcode
      template<typename TPointer>
      static void is_not_null(const std::weak_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {succeed(message, line_info);}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer) {is_not_null(pointer, "", line_info());}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {is_not_null(pointer, "", line_info);}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const std::string& message) {is_not_null(pointer, message, line_info());}

      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_not_null(nullptr, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_not_null(std::nullptr_t pointer, const std::string& message, const xtd::tunit::line_info& line_info) {fail("Expected: not null\nBut was:  null", message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const TPointer* pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer == nullptr)
          succeed(message, line_info);
        else
          fail("Expected: not null\nBut was:  null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::unique_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer == nullptr)
          succeed(message, line_info);
        else
          fail("Expected: not null\nBut was:  null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1); // test ok.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::shared_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (pointer -= nullptr)
          succeed(message, line_info);
        else
          fail("Expected: not null\nBut was:  null", message, line_info);
      }
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, line_info_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, "User message..."); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::is_null(s1, "User message...", line_info_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::is_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void is_null(const std::weak_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {fail("Expected: not null\nBut was:  null", message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer) {is_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, line_info_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {is_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, "User message..."); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const std::string& message) {is_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::is_null(nullptr, "User message...", line_info_); // test ok.
      /// @endcode
      static void is_null(std::nullptr_t pointer, const std::string& message, const xtd::tunit::line_info& line_info) {succeed(message, line_info);}

      /// @brief Asserts that ta condition is true.
      /// @param condition The condition to check is true.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1)); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2)); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition) {is_true(condition, "", line_info());}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const xtd::tunit::line_info& line_info) {is_true(condition, "", line_info);}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message..."); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const std::string& message) {is_true(condition, message, line_info());}
      
      /// @brief Asserts that a condition is true.
      /// @param condition The condition to check is true.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string s1;
      /// std::string s2 = "Anything";
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_true(bool condition, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (condition == true)
          succeed(message, line_info);
        else
          fail("Expected: true\nBut was:  false", message, line_info);
      }
      
      /// @brief Asserts that the first value is less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less(24, 48); // test ok.
      /// xtd::tunit::assert::less(24, 12); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less(const TValue1& val1, const TValue2& val2) {less(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less(24, 48, line_info_); // test ok.
      /// xtd::tunit::assert::less(24, 12, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {less(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assert::less(24, 12, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less(const TValue1& val1, const TValue2& val2, const std::string& message) {less(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is less than the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less(24, 48, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::less(24, 12, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 < val2)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: less than " << val2 << "\nBut was:  " << val1;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that the first value is less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less_or_equal(24, 48); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 24); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 12); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less_or_equal(const TValue1& val1, const TValue2& val2) {less_or_equal(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less_or_equal(24, 48, line_info_); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 24, line_info_); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 12, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less_or_equal(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {less_or_equal(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less_or_equal(24, 48, "User message..."); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 24, "User message..."); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 12, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message) {less_or_equal(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is less than or equal to the second value.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::less_or_equal(24, 48, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 24, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::less_or_equal(24, 12, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void less_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (val1 <= val2)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: less than " << val2 << "\nBut was:  " << val1;
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::not_null(s1); // test ok.
      /// xtd::tunit::assert::not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const TPointer* pointer) {not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const TPointer* pointer, const xtd::tunit::line_info& line_info) {not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const TPointer* pointer, const std::string& message) {not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = &str;
      /// std::string* s2 = nullptr;
      /// xtd::tunit::assert::not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const TPointer* pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_not_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1); // test ok.
      /// xtd::tunit::assert::not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::unique_ptr<TPointer>& pointer) {not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::unique_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::unique_ptr<TPointer>& pointer, const std::string& message) {not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1 = std::make_unique<std::string>("Anything");
      /// std::unique_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::unique_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_not_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1); // test ok.
      /// xtd::tunit::assert::not_null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::shared_ptr<TPointer>& pointer) {not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::shared_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::shared_ptr<TPointer>& pointer, const std::string& message) {not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1 = std::make_shared<std::string>("Anything");
      /// std::shared_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::shared_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_not_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1); // test ok.
      /// xtd::tunit::assert::not_null(s2); // test ok.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::weak_ptr<TPointer>& pointer) {not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, line_info_); // test ok.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::weak_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message..."); // test ok.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::weak_ptr<TPointer>& pointer, const std::string& message) {not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1 = s;
      /// std::weak_ptr<std::string> s2;
      /// xtd::tunit::assert::not_null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::not_null(s2, "User message...", line_info_); // test ok.
      /// @endcode
      template<typename TPointer>
      static void not_null(const std::weak_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_not_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::not_null(nullptr); // test throws an assertion_error exception.
      /// @endcode
      static void not_null(std::nullptr_t pointer) {not_null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::not_null(nullptr, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void not_null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {not_null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::not_null(nullptr, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void not_null(std::nullptr_t pointer, const std::string& message) {not_null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is not null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::not_null(nullptr, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void not_null(std::nullptr_t pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_not_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::null(s1); // test ok.
      /// xtd::tunit::assert::null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const TPointer* pointer) {null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const TPointer* pointer, const xtd::tunit::line_info& line_info) {null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const TPointer* pointer, const std::string& message) {null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::string str = "Anything";
      /// std::string* s1 = nullptr;
      /// std::string* s2 = &str;
      /// xtd::tunit::assert::null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const TPointer* pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::null(s1); // test ok.
      /// xtd::tunit::assert::null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::unique_ptr<TPointer>& pointer) {null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::unique_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::unique_ptr<TPointer>& pointer, const std::string& message) {null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::unique_ptr<std::string> s1;
      /// std::unique_ptr<std::string> s2 = std::make_unique<std::string>("Anything");
      /// xtd::tunit::assert::null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::unique_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::null(s1); // test ok.
      /// xtd::tunit::assert::null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::shared_ptr<TPointer>& pointer) {null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::null(s1, line_info_); // test ok.
      /// xtd::tunit::assert::null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::shared_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::null(s1, "User message..."); // test ok.
      /// xtd::tunit::assert::null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::shared_ptr<TPointer>& pointer, const std::string& message) {null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s1;
      /// std::shared_ptr<std::string> s2 = std::make_shared<std::string>("Anything");
      /// xtd::tunit::assert::null(s1, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::shared_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::null(s1); // test throws an assertion_error exception.
      /// xtd::tunit::assert::null(s2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::weak_ptr<TPointer>& pointer) {null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::null(s1, line_info_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::null(s2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::weak_ptr<TPointer>& pointer, const xtd::tunit::line_info& line_info) {null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::null(s1, "User message..."); // test throws an assertion_error exception.
      /// xtd::tunit::assert::null(s2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::weak_ptr<TPointer>& pointer, const std::string& message) {null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @remarks Always true, a weaptr can't be equal to nullptr by contruction or assignation.
      /// @par Examples
      /// @code
      /// std::shared_ptr<std::string> s = std::make_shared<std::string>("Anything");
      /// std::weak_ptr<std::string> s1;
      /// std::weak_ptr<std::string> s2 = s;
      /// xtd::tunit::assert::null(s1, "User message...", line_info_); // test throws an assertion_error exception.
      /// xtd::tunit::assert::null(s2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TPointer>
      static void null(const std::weak_ptr<TPointer>& pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_null(pointer, message, line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::null(nullptr); // test ok.
      /// @endcode
      static void null(std::nullptr_t pointer) {null(pointer, "", line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::null(nullptr, line_info_); // test ok.
      /// @endcode
      static void null(std::nullptr_t pointer, const xtd::tunit::line_info& line_info) {null(pointer, "", line_info);}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::null(nullptr, "User message..."); // test ok.
      /// @endcode
      static void null(std::nullptr_t pointer, const std::string& message) {null(pointer, message, line_info());}
      
      /// @brief Asserts that the pointer is null.
      /// @param pointer The pointer to check is null.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @remarks Always false, a nullptr_t is always equal to nullptr.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::null(nullptr, "User message...", line_info_); // test ok.
      /// @endcode
      static void null(std::nullptr_t pointer, const std::string& message, const xtd::tunit::line_info& line_info) {is_null(pointer, message, line_info);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(); // test ok.
      /// @endcode
      static void succeed() {succeed("", line_info_);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(line_info_); // test ok.
      /// @endcode
      static void succeed(const xtd::tunit::line_info& line_info) {succeed("", line_info);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message..."); // test ok.
      /// @endcode
      static void succeed(const std::string& message) {succeed(message, line_info_);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message...", line_info_); // test ok.
      /// @endcode
      static void succeed(const std::string& message, const xtd::tunit::line_info& line_info);

      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement) {throws<TException>(statement, "", line_info());}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, line_info_); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {throws<TException>(statement, "", line_info);}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement, const std::string& message) {throws<TException>(statement, message, line_info());}
      
      /// @brief Asserts that the statement throws a particular exception when called.
      /// @param TException The exception type that must be throw.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(5);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::throws<std::out_of_range>([&] {v1.at(2);}, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TException>
      static void throws(const std::function<void()>& statement, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          statement();
          fail("Expected: <"  + __demangle(typeid(TException).name()) + ">\nBut was:  <nothing>", message, line_info);
        } catch (const TException&) {
          succeed(message, line_info);
        } catch (const xtd::tunit::assert_error&) {
          fail("Expected: <"  + __demangle(typeid(TException).name()) + ">\nBut was:  <nothing>", message, line_info);
        } catch (const std::exception& e) {
          fail("Expected: <"  + __demangle(typeid(TException).name()) + ">\nBut was:  <" + __demangle(typeid(e).name()) + ">", message, line_info);
        } catch (...) {
          fail("Expected: <"  + __demangle(typeid(TException).name()) + ">\nBut was:  <exception>", message, line_info);
        }
      }
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement) {throws_any(statement, "", line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, line_info_); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {throws_any(statement, "", line_info);}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, "User message..."); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const std::string& message) {throws_any(statement, message, line_info());}
      
      /// @brief Asserts that the staement does not throw an exception.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::throws_any([&] {v1.at(5);}, "User message...", line_info_); // test ok.
      /// xtd::tunit::assert::throws_any([&] {v1.at(2);}, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void throws_any(const std::function<void()>& statement, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          statement();
          fail("Expected: <exception>\nBut was:  <nothing>", message, line_info);
        } catch (const xtd::tunit::assert_error&) {
          throw;
        } catch (...) {
          succeed(message, line_info);
        }
      }
    };
  }
}

/// @cond
#define __CMD_ASSERT_0_ARGS__(cmd) cmd(line_info_)
#define __CMD_ASSERT_1_ARGS__(cmd, arg1) cmd(arg1, line_info_)
#define __CMD_ASSERT_2_ARGS__(cmd, arg1, arg2) cmd(arg1, arg2, line_info_)
#define __CMD_ASSERT_3_ARGS__(cmd, arg1, arg2, arg3) cmd(arg1, arg2, arg3, line_info_)
#define __CMD_ASSERT_4_ARGS__(cmd, arg1, arg2, arg3, arg4) cmd(arg1, arg2, arg3, arg4)
#define __GET_LAST_ARG(arg1, arg2, arg3, arg4, arg5, ...) arg5
#define __CMD_ASSERT_MACRO_CHOOSER(cmd, ...) __GET_LAST_ARG(__VA_ARGS__, __CMD_ASSERT_4_ARGS__, __CMD_ASSERT_3_ARGS__, __CMD_ASSERT_2_ARGS__, __CMD_ASSERT_1_ARGS__, __CMD_ASSERT_0_ARGS__, )
#define __CMD_ASSERT_ARGS(cmd, ...) __CMD_ASSERT_MACRO_CHOOSER(cmd, __VA_ARGS__)(cmd, __VA_ARGS__)
/// @endcond

#define are_equal_(...) __CMD_ASSERT_ARGS(are_equal, __VA_ARGS__)

#define are_not_equal_(...) __CMD_ASSERT_ARGS(are_not_equal, __VA_ARGS__)

#define are_not_same_(...) __CMD_ASSERT_ARGS(are_not_same, __VA_ARGS__)

#define are_same_(...) __CMD_ASSERT_ARGS(are_same, __VA_ARGS__)

#define contains_(...) __CMD_ASSERT_ARGS(contains, __VA_ARGS__)

#define does_not_throw_(...) __CMD_ASSERT_ARGS(does_not_throw, __VA_ARGS__)

#define fail_() fail(line_info_)

#define greater_(...) __CMD_ASSERT_ARGS(greater, __VA_ARGS__)

#define greater_or_equal_(...) __CMD_ASSERT_ARGS(greater_or_equal, __VA_ARGS__)

#define is_empty_(...) __CMD_ASSERT_ARGS(is_empty, __VA_ARGS__)

#define is_false_(...) __CMD_ASSERT_ARGS(is_false, __VA_ARGS__)

#define is_instance_of_(...) __CMD_ASSERT_ARGS(is_instance_of, __VA_ARGS__)

#define is_instance_of_type_(...) __CMD_ASSERT_ARGS(is_instance_of_type, __VA_ARGS__)

#define is_NaN_(...) __CMD_ASSERT_ARGS(is_NaN, __VA_ARGS__)

#define is_not_empty_(...) __CMD_ASSERT_ARGS(is_not_empty, __VA_ARGS__)

#define is_not_instance_of_(...) __CMD_ASSERT_ARGS(is_not_instance_of, __VA_ARGS__)

#define is_not_instance_of_type_(...) __CMD_ASSERT_ARGS(is_not_instance_of_type, __VA_ARGS__)

#define is_not_null_(...) __CMD_ASSERT_ARGS(is_not_null, __VA_ARGS__)

#define is_null_(...) __CMD_ASSERT_ARGS(is_null, __VA_ARGS__)

#define is_true_(...) __CMD_ASSERT_ARGS(is_true, __VA_ARGS__)

#define is_less_(...) __CMD_ASSERT_ARGS(is_less, __VA_ARGS__)

#define is_less_or_equal_(...) __CMD_ASSERT_ARGS(is_less_or_equal, __VA_ARGS__)

#define not_null_(...) __CMD_ASSERT_ARGS(not_null, __VA_ARGS__)

#define null_(...) __CMD_ASSERT_ARGS(null, __VA_ARGS__)

#define succeed_(...) __CMD_ASSERT_ARGS(succeed, __VA_ARGS__)

#define throws_(TException, ...) __CMD_ASSERT_ARGS(throws<TException>, __VA_ARGS__)

#define throws_any_(...) __CMD_ASSERT_ARGS(throws_any, __VA_ARGS__)
