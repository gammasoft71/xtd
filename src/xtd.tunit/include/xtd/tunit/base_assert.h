/// @file
/// @brief Contains xtd::tunit::assert class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.h"
#define __XTD_TUNIT_INTERNAL__
#include "__default_insert_basic_ostream_operator.h"
#include "__tunit_join__items.h"
#define __XTD_TUNIT_INTERNAL__
#include "abort_error.h"
#include "assert_error.h"
#include "ignore_error.h"
#include <xtd/environment>
#include <xtd/types>
#include <xtd/typeof>
#include <xtd/ustring>
#include <xtd/diagnostics/stack_frame>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The base class for assert.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ base_assert {
    public:
      /// @cond
      base_assert() = delete;
      /// @endcond
      
      /// @name Methods
      
      /// @{
      /// @brief Abort current test. This is used by the other assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort(); // test throws an abort_error exception.
      /// @endcode
      static void abort();
      /// @brief Abort current test. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort(csf_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Abort current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message..."); // test throws an abort_error exception.
      /// @endcode
      static void abort(const xtd::ustring& message);
      
      /// @brief Abort current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::abort("User message...", csf_); // test throws an abort_error exception.
      /// @endcode
      static void abort(const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail(); // test throws an assert_error exception.
      /// @endcode
      static void fail();
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail(csf_); // test throws an assert_error exception.
      /// @endcode
      static void fail(const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message..."); // test throws an assert_error exception.
      /// @endcode
      static void fail(const xtd::ustring& message);
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail("User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void fail(const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore(); // test throws an ignore_error exception.
      /// @endcode
      static void ignore();
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @param stack_frame Contains information about current file and current line.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore(csf_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message..."); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const xtd::ustring& message);
      /// @brief Ignore current test. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::ignore("User message...", csf_); // test throws an ignore_error exception.
      /// @endcode
      static void ignore(const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(); // test ok.
      /// @endcode
      static void succeed();
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed(csf_); // test ok.
      /// @endcode
      static void succeed(const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message..."); // test ok.
      /// @endcode
      static void succeed(const xtd::ustring& message);
      /// @brief Generates a success with a generic message. This is used by the other assert functions.
      /// @param message A user message to display if the assertion fails. This message can be seen in the unit test results.
      /// @param stack_frame Contains information about current file and current line.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::succeed("User message...", csf_); // test ok.
      /// @endcode
      static void succeed(const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::error(); // test throws an assert_error exception.
      /// @endcode
      static void error();
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::error("User message..."); // test throws an assert_error exception.
      /// @endcode
      static void error(const xtd::ustring& message);
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::error(actual_str, expected_str, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void error(const xtd::ustring& actual, const xtd::ustring& expected, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Throws an xtd::tunit::assert_error exception. This is used by the other assert functions.
      /// @exception xtd::tunit::assert_error If bad assertion.
      /// @par Examples
      /// @code
      /// xtd::tunit::assert::fail(actual_str, expected_str, "User message...", csf_); // test throws an assert_error exception.
      /// @endcode
      static void fail(const xtd::ustring& actual, const xtd::ustring& expected, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      
      /// @brief Convert specified value to xtd::ustring.
      /// @param value The value to convert to xtd::ustring.
      /// @return The xtd::ustring that contains the value.
      template <typename value_t>
      static xtd::ustring to_string(const value_t& value) {return __tunit_to_string(value);}
      /// @brief Convert specified value to xtd::ustring.
      /// @param value The value to convert to xtd::ustring.
      /// @return The xtd::ustring that contains the value.
      template <typename value_t>
      static xtd::ustring to_string(const value_t* value) {return __tunit_to_string(value);}
      
      /// @brief Join specified collection into xtd::ustring.
      /// @param collection The collection to join into xtd::ustring.
      /// @return The xtd::ustring that contains the joined collection.
      template<typename collection_t>
      static xtd::ustring join_items(const collection_t& collection) {return __tunit_join__items(collection);}
      /// @brief Join specified string into xtd::ustring.
      /// @param str The joined to join into xtd::ustring.
      /// @return The xtd::ustring that contains the joined string.
      static xtd::ustring join_items(const xtd::ustring& str);
      /// @}
      
    private:
      static bool is_debug() noexcept {return environment::compiler_version().build_type() == build_type::debug;}
    };
  }
}
