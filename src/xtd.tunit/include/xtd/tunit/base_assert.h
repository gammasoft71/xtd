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
#include <xtd/diagnostics/stack_frame.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Thebase class for assert.
    /// @par Namespace
    /// xtd::tunit
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
      /// xtd::tunit::assert::abort("User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void abort() {abort("", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const xtd::diagnostics::stack_frame& stack_frame) {abort("", stack_frame);}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const std::string& message) {abort(message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Abort current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void fail() {fail("", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const xtd::diagnostics::stack_frame& stack_frame) {fail("", stack_frame);}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message) {fail(message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Throws an xtd::tunit::assertion_error exception. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", csf_); // test throws an assertion_error exception.
      /// @endcode
      static void fail(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
        base_assert::fail("", "", message, stack_frame);
      }

      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", csf_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore() {ignore("", xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assertion_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", csf_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const xtd::diagnostics::stack_frame& stack_frame) {ignore("", stack_frame);}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", csf_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const std::string& message) {ignore(message, xtd::diagnostics::stack_frame::empty());}
      
      /// @brief Ignore current test. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", csf_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(); // test ok.
      /// @endcode
      static void succeed() {succeed("", csf_);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(csf_); // test ok.
      /// @endcode
      static void succeed(const xtd::diagnostics::stack_frame& stack_frame) {succeed("", stack_frame);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message..."); // test ok.
      /// @endcode
      static void succeed(const std::string& message) {succeed(message, csf_);}
      
      /// @brief Generates a success with a generic message. This is used by the other Assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message...", csf_); // test ok.
      /// @endcode
      static void succeed(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);

    protected:
      static void fail(const std::string& actual, const std::string& expected, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      static void error();
      
      static void error(const std::string& actual, const std::string& expected, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame);
      
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
