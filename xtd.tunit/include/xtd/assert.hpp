/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "__demangle.hpp"
#include "assert_error.hpp"
#include "line_info.hpp"
#include <algorithm>
#include <exception>
#include <functional>
#include <iterator>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>

/// @cond
#ifdef assert
#undef assert
#endif

template <typename Char, typename CharTraits, typename Type>
std::basic_ostream<Char, CharTraits>& operator<<(std::basic_ostream<Char, CharTraits>& os, const Type& value) {
  size_t size = sizeof(value) > 32 ? 32 : sizeof(value);
  os << size << "-byte object <";
  for (size_t index = 0; index != size; index++)
    os <<  (index != 0 ? (index % 2 == 0 ? " " : "-") : "") << std::hex << std::setiosflags(std::ios_base::uppercase) << std::setw(2) << std::setfill('0') << static_cast<int>(reinterpret_cast<const unsigned char*>(&value)[index]) << std::resetiosflags(std::ios_base::dec) << std::dec;
  return os << (size < sizeof(value) ? "-..." : "") << ">";
}

template<typename TCollection>
std::string __join__collection(const TCollection& collection) {
  std::stringstream ss;
  bool first = true;
  for (const auto& item : collection) {
    if (!first) ss << ", ";
    ss << std::to_string(item);
    first = false;
  }
  return ss.str();
}

template<>
inline std::string __join__collection<std::string>(const std::string& collection) {
  std::stringstream ss;
  bool first = true;
  for (const char& item : collection) {
    if (!first) ss << ", ";
    ss << '\'' << item << '\'';
    first = false;
  }
  return ss.str();
}

/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
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
      
      /// @brief Asserts that two type are equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_aqual(24, int(24)); // test ok
      /// xtd::tunit::assert::are_equal(23, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual) {are_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_aqual(24, int(24), line_info_); // test ok
      /// xtd::tunit::assert::are_equal(23, int(24), line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_aqual(24, int(24), "User message..."); // test ok
      /// xtd::tunit::assert::are_equal(23, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const std::string& message) {are_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_aqual(24, int(24), "User message...", line_info_); // test ok
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
      
      /// @brief Asserts that two type are not equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24)); // test ok
      /// xtd::tunit::assert::are_not_equal(24, int(24)); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual) {are_not_equal(expected, actual, "", line_info());}
      
      /// @brief Asserts that two type are not equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), line_info_); // test ok
      /// xtd::tunit::assert::are_not_equal(24, int(24), line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_not_equal(expected, actual, "", line_info);}
      
      /// @brief Asserts that two type are not equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message..."); // test ok
      /// xtd::tunit::assert::are_not_equal(24, int(24), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_equal(const TExpected& expected, const TActual& actual, const std::string& message) {are_not_equal(expected, actual, message, line_info());}
      
      /// @brief Asserts that two type are not equal. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::are_not_equal(23, int(24), "User message...", line_info_); // test ok
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
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a); // test ok
      /// xtd::tunit::assert::are_not_same(b, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual) {are_not_same(expected, actual, "", line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, line_info_); // test ok
      /// xtd::tunit::assert::are_not_same(b, a, line_info); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_not_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message..."); // test ok
      /// xtd::tunit::assert::are_not_same(b, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_not_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message...", line_info_); // test ok
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
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a); // test ok
      /// xtd::tunit::assert::are_same(c, a); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual) {are_same(expected, actual, "", line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, line_info_); // test ok
      /// xtd::tunit::assert::are_same(c, a, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message..."); // test ok
      /// xtd::tunit::assert::are_same(c, a, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message...", line_info_); // test ok
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
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1); // test ok
      /// xtd::tunit::assert::contains(4, v1); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection) {contains(item, collection, "", line_info());}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, line_info_); // test ok
      /// xtd::tunit::assert::contains(4, v1, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const xtd::tunit::line_info& line_info) {contains(item, collection, "", line_info);}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message..."); // test ok
      /// xtd::tunit::assert::contains(4, v1, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message) {contains(item, collection, message, line_info());}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// xtd::tunit::assert::contains(2, v1, "User message...", line_info_); // test ok
      /// xtd::tunit::assert::contains(4, v1, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(collection.begin(), collection.end(), item);
        if (result != collection.end())
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: collection containing " << item << "\nBut was:  < " << __join__collection(collection) << " >";
          fail(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that the staement does not throw an exception. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(2);}); // test ok
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(5);}); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throws(const std::function<void()>& statement) {does_not_throws(statement, "", line_info());}
      
      /// @brief Asserts that the staement does not throw an exception. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(2);}, line_info_); // test ok
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(5);}, line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throws(const std::function<void()>& statement, const xtd::tunit::line_info& line_info) {does_not_throws(statement, "", line_info);}
      
      /// @brief Asserts that the staement does not throw an exception. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(2);}, "User message..."); // test ok
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(5);}, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throws(const std::function<void()>& statement, const std::string& message) {does_not_throws(statement, message, line_info());}
      
      /// @brief Asserts that the staement does not throw an exception. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {1, 2, 3, 4};
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(2);}, "User message...", line_info_); // test ok
      /// xtd::tunit::assert::does_not_throws([&] {v1.at(5);}, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void does_not_throws(const std::function<void()>& statement, const std::string& message, const xtd::tunit::line_info& line_info) {
        try {
          statement();
          succeed(message, line_info);
        } catch (std::exception& e) {
          fail("Expected: No Exception to be thrown\nBut was:  <" + __demangle(typeid(e).name()) + ">", message, line_info);
        } catch (...) {
          fail("Expected: No Exception to be thrown\nBut was:  <exception>", message, line_info);
        }
      }
      
      /// @brief Throws an xtd::tunit::assertion_error exception.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail() {fail("", line_info());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const xtd::tunit::line_info& line_info) {fail("", line_info);}
      
      /// @brief Throws an xtd::tunit::assertion_error exception.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message) {fail(message, line_info());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception.
      /// @param fail_message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message, const xtd::tunit::line_info& line_info) {
        fail("Failled", message, line_info);
      }
      
      /// @brief Asserts that the first value is greater than the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12); // test ok
      /// xtd::tunit::assert::greater(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater(const TValue1& val1, const TValue2& val2) {greater(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is greater than the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12, line_info_); // test ok
      /// xtd::tunit::assert::greater(24, 48, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {greater(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is greater than the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12, "User message..."); // test ok
      /// xtd::tunit::assert::greater(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater(const TValue1& val1, const TValue2& val2, const std::string& message) {greater(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is greater than the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater(24, 12, "User message...", line_info_); // test ok
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
      
      /// @brief Asserts that the first value is greater than or equal to the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12); // test ok
      /// xtd::tunit::assert::greater_or_equal(24, 24); // test ok
      /// xtd::tunit::assert::greater_or_equal(24, 48); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater_or_equal(const TValue1& val1, const TValue2& val2) {greater_or_equal(val1, val2, "", line_info());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12, line_info_); // test ok
      /// xtd::tunit::assert::greater_or_equal(24, 24, line_info_); // test ok
      /// xtd::tunit::assert::greater_or_equal(24, 48, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater_or_equal(const TValue1& val1, const TValue2& val2, const xtd::tunit::line_info& line_info) {greater_or_equal(val1, val2, "", line_info);}
      
      /// @brief Asserts that the first value is greater than or equal to the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12, "User message..."); // test ok
      /// xtd::tunit::assert::greater_or_equal(24, 24, "User message..."); // test ok
      /// xtd::tunit::assert::greater_or_equal(24, 48, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TValue1, typename TValue2>
      static void greater_or_equal(const TValue1& val1, const TValue2& val2, const std::string& message) {greater_or_equal(val1, val2, message, line_info());}
      
      /// @brief Asserts that the first value is greater than or equal to the second value. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param val1 the first value.
      /// @param val2 the second value.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::greater_or_equal(24, 12, "User message...", line_info_); // test ok
      /// xtd::tunit::assert::greater_or_equal(24, 24, "User message...", line_info_); // test ok
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
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1); // test ok
      /// xtd::tunit::assert::is_empty(v2); // test throws an assertion_error exception.
      /// @endcode
      template<typename TCollection>
      static void is_empty(const TCollection& collection) {is_empty(collection, "", line_info());}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, line_info_); // test ok
      /// xtd::tunit::assert::is_empty(v2, line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TCollection>
      static void is_empty(const TCollection& collection, const xtd::tunit::line_info& line_info) {is_empty(collection, "", line_info);}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message..."); // test ok
      /// xtd::tunit::assert::is_empty(v2, "User message..."); // test throws an assertion_error exception.
      /// @endcode
      template<typename TCollection>
      static void is_empty(const TCollection& collection, const std::string& message) {is_empty(collection, message, line_info());}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param item object to verify.
      /// @param collection that contains object.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1;
      /// std::vector<int> v2 = {0, 1, 2, 3};
      /// xtd::tunit::assert::is_empty(v1, "User message...", line_info_); // test ok
      /// xtd::tunit::assert::is_empty(v2, "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      template<typename TCollection>
      static void is_empty(const TCollection& collection, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (std::empty(collection))
          succeed(message, line_info);
        else
          fail("Expected: collection <empty>\nBut was:  < " + __join__collection(collection) + " >", message, line_info);
      }

      /// @brief Asserts that ta condition is false. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1)); // test ok
      /// xtd::tunit::assert::is_false(std::empty(s2)); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition) {is_false(condition, "", line_info());}
      
      /// @brief Asserts that a condition is false. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), line_info_); // test ok
      /// xtd::tunit::assert::is_false(std::empty(s2), line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const xtd::tunit::line_info& line_info) {is_false(condition, "", line_info);}
      
      /// @brief Asserts that a condition is false. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message..."); // test ok
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message..."); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const std::string& message) {is_false(condition, message, line_info());}
      
      /// @brief Asserts that a condition is false. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param statement The statement that verify.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::string s1 = "Anything";
      /// std::string s2;
      /// xtd::tunit::assert::is_false(std::empty(s1), "User message...", line_info_); // test ok
      /// xtd::tunit::assert::is_false(std::empty(s2), "User message...", line_info_); // test throws an assertion_error exception.
      /// @endcode
      static void is_false(bool condition, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (condition == false)
          succeed(message, line_info);
        else
          fail("Expected: false\nBut was:  true", message, line_info);
      }

    private:
      static void fail(const std::string& failed_message, const std::string& message, const xtd::tunit::line_info& line_info);
      static void succeed(const std::string& message, const xtd::tunit::line_info& line_info);
    };
  }
}

/// @cond
#define __CMD_ASSERT_2_ARGS__(cmd, arg1, arg2) cmd(arg1, arg2, line_info_)
#define __CMD_ASSERT_3_ARGS__(cmd, arg1, arg2, arg3) cmd(arg1, arg2, arg3, line_info_)
#define __CMD_ASSERT_4_ARGS__(cmd, arg1, arg2, arg3, arg4) cmd(arg1, arg2, arg3, arg4)
#define __GET_LAST_ARG(arg1, arg2, arg3, arg4, arg5, ...) arg5
#define __CMD_ASSERT_MACRO_CHOOSER(cmd, ...) __GET_LAST_ARG(__VA_ARGS__, __CMD_ASSERT_4_ARGS__, __CMD_ASSERT_3_ARGS__, __CMD_ASSERT_2_ARGS__, )
#define __CMD_ASSERT_ARGS(cmd, ...) __CMD_ASSERT_MACRO_CHOOSER(cmd, __VA_ARGS__)(cmd, __VA_ARGS__)
/// @endcond

#define are_equal_(...) __CMD_ASSERT_ARGS(are_equal, __VA_ARGS__)

#define are_not_equal_(...) __CMD_ASSERT_ARGS(are_not_equal, __VA_ARGS__)

#define are_not_same_(...) __CMD_ASSERT_ARGS(are_not_same, __VA_ARGS__)

#define are_same_(...) __CMD_ASSERT_ARGS(are_same, __VA_ARGS__)

#define contains_(...) __CMD_ASSERT_ARGS(contains, __VA_ARGS__)

#define does_not_throws_(...) __CMD_ASSERT_ARGS(does_not_throws, __VA_ARGS__)

#define fail_(...) __CMD_ASSERT_ARGS(fail, __VA_ARGS__)

#define greater_(...) __CMD_ASSERT_ARGS(greater, __VA_ARGS__)

#define greater_or_equal_(...) __CMD_ASSERT_ARGS(greater_or_equal, __VA_ARGS__)

#define is_empty_(...) __CMD_ASSERT_ARGS(is_empty, __VA_ARGS__)

#define is_false_(...) __CMD_ASSERT_ARGS(is_false, __VA_ARGS__)
