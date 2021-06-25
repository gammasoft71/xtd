/// @file
/// @brief Contains xtd::tunit::assert class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../tunit_export.h"
#include "__demangle.h"
#include "__tunit_join__items.h"
#include "abort_error.h"
#include "assert_error.h"
#include "default_insert_basic_ostream_operator.h"
#include "ignore_error.h"
#include "line_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Thebase class for assert.
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    class tunit_export_ base_assert {
    public:
      /// @cond
      base_assert() = delete;
      /// @endcond
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort() {abort("", line_info());}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const xtd::tunit::line_info& line_info) {abort("", line_info);}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const std::string& message) {abort(message, line_info());}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", line_info_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const std::string& message, const xtd::tunit::line_info& line_info);
      
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
        base_assert::fail("", "", message, line_info);
      }

      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore() {ignore("", line_info());}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param line_info Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const xtd::tunit::line_info& line_info) {ignore("", line_info);}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const std::string& message) {ignore(message, line_info());}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param line_info Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", line_info_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const std::string& message, const xtd::tunit::line_info& line_info);
      
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

    protected:
      static void fail(const std::string& actual, const std::string& expected, const std::string& message, const xtd::tunit::line_info& line_info);
      
      static void error();
      
      static void error(const std::string& actual, const std::string& expected, const std::string& message, const xtd::tunit::line_info& line_info);
      
      template <typename value_t>
      static std::string to_string(const value_t& value) {return __tunit_to_string(value);}
      
      template <typename value_t>
      static std::string to_string(const value_t* value) {return __tunit_to_string(value);}

      template<typename collection_t>
      static std::string join_items(const collection_t& collection) {return __tunit_join__items(collection);}
      
      static std::string join_items(const std::string& str) {return __tunit_join__items(str);}
    };
  }
}
