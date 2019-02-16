/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "assert_error.hpp"
#include "line_info.hpp"
#include <algorithm>
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
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
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
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
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
          ss << "Expected: " << expected << std::endl << "But was:  " << actual;
          failed(ss.str(), message, line_info);
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
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
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
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
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
          ss << "Expected: not " << expected << std::endl << "But was:  " << actual;
          failed(ss.str(), message, line_info);
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
      /// xtd::tunit::assert::are_not_same(b, a); // test throws an AssertionException.
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
      /// xtd::tunit::assert::are_not_same(b, a, line_info); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_not_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message..."); // test ok
      /// xtd::tunit::assert::are_not_same(b, a, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_not_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_not_same(c, a, "User message...", line_info_); // test ok
      /// xtd::tunit::assert::are_not_same(b, a, "User message...", line_info); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_not_same(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (&actual != &expected)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: not same as " << expected << std::endl << "But was:  " << actual;
          failed(ss.str(), message, line_info);
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
      /// xtd::tunit::assert::are_same(c, a); // test throws an AssertionException.
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
      /// xtd::tunit::assert::are_same(c, a, line_info_); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_same(expected, actual, "", line_info);}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message..."); // test ok
      /// xtd::tunit::assert::are_same(c, a, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const std::string& message) {are_same(expected, actual, message, line_info());}
      
      /// @brief Asserts that two objects do refer to differents objects. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// int a = 24;
      /// int& b = a;
      /// int c=  24;
      /// xtd::tunit::assert::are_same(b, a, "User message...", line_info_); // test ok
      /// xtd::tunit::assert::are_same(c, a, "User message...", line_info_); // test throws an AssertionException.
      /// @endcode
      template<typename TExpected, typename TActual>
      static void are_same(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (&actual == &expected)
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: same as " << expected << std::endl << "But was:  " << actual;
          failed(ss.str(), message, line_info);
        }
      }
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// Txtd::tunit::assert::contains(2, v1); // test ok
      /// xtd::tunit::assert::contains(4, v1); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection) {contains(item, collection, "", line_info());}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// Txtd::tunit::assert::contains(2, v1, line_info_); // test ok
      /// xtd::tunit::assert::contains(4, v1, line_info_); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const xtd::tunit::line_info& line_info) {contains(item, collection, "", line_info);}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// Txtd::tunit::assert::contains(2, v1, "User message..."); // test ok
      /// xtd::tunit::assert::contains(4, v1, "User message..."); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message) {contains(item, collection, message, line_info());}
      
      /// @brief Asserts that collection contains an item. If they are not, then a xtd::tunit::assertion_error excpetion is thrown.
      /// @param expected the expected value.
      /// @param actual the actual value.
      /// @param message A message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// std::vector<int> v1 = {0, 1, 2, 3};
      /// Txtd::tunit::assert::contains(2, v1, "User message...", line_info_); // test ok
      /// xtd::tunit::assert::contains(4, v1, "User message...", line_info_); // test throws an AssertionException.
      /// @endcode
      template<typename TItem, typename TCollection>
      static void contains(const TItem& item, const TCollection& collection, const std::string& message, const xtd::tunit::line_info& line_info) {
        auto result = std::find(collection.begin(), collection.end(), item);
        if (result != collection.end())
          succeed(message, line_info);
        else {
          std::stringstream ss;
          ss << "Expected: collection containing " << item << std::endl << "But was:  < " << __join__collection(collection) << " >";
          failed(ss.str(), message, line_info);
        }
      }

    private:
      static void succeed(const std::string& message, const xtd::tunit::line_info& line_info);
      static void failed(const std::string& failed_message, const std::string& message, const xtd::tunit::line_info& line_info);
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
