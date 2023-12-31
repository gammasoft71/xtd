/// @file
/// @brief Contains xtd::tunit::test class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.h"
#include "assert.h"
#include "assert_error.h"
#include <xtd/diagnostics/stack_frame>
#include <xtd/date_time>
#include <xtd/using>
#include <functional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    class test_class;
    class unit_test;
    class valid;
    /// @endcond
    
    /// @brief Represents a test method.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks Typically this is a representation a test method in a test class.
    /// @remakrs This test contains among others: a name that represents the name of the method, a pointer to the method to call and a status on the state of the test.
    class tunit_export_ test final {
      /// @brief Represents a test status.
      /// @remarks The test status enmeration is know the state of the test.
      enum class test_status {
        /// @brief The test is not started.
        not_started,
        /// @brief The test is ignored.
        ignored,
        /// @brief The test is succeed.
        succeed,
        /// @brief The test is aborted.
        aborted,
        /// @brief The test is failed.
        failed
      };
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Creates a new test instance.
      test() = default;
      /// @brief Creates a new test instance with specified name, method and stack frame.
      /// @param name Represents the name of the method. Generally is the same name as the method name.
      /// @param method The method that contains the test.
      /// @param stack_frame The stack frame of the method.
      test(const xtd::ustring& name, const std::function<void()>& method, const xtd::diagnostics::stack_frame& stack_frame) noexcept;
      /// @brief Creates a new test instance with specified name, method and stack frame.
      /// @param name Represents the name of the method. Generally is the same name as the method name.
      /// @param method The method that contains the test.
      /// @param ignored If true, the test will be ignored during tests execution; otherwise, the test will be taken into account during tests execution.
      /// @param stack_frame The stack frame of the method.
      test(const xtd::ustring& name, const std::function<void()>& method, bool ignore, const xtd::diagnostics::stack_frame& stack_frame) noexcept;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a value that represent an aborted test.
      /// @return true is the test is aborted; otherwise false.
      bool aborted() const noexcept;
      
      /// @brief Gets the actual value string.
      /// @return The actual value string. Can be empty.
      const xtd::ustring& actual() const noexcept;
      
      /// @brief Gets the elapsed time of the test method.
      /// @return The elapsed time of the test method.
      std::chrono::milliseconds elapsed_time() const noexcept;
      
      /// @brief Gets the expect value string.
      /// @return The expect value string. Can be empty.
      const xtd::ustring& expect() const noexcept;
      
      /// @brief Gest a value that represent an failed test.
      /// @return tru is the test is failed; otherwise false.
      bool failed() const noexcept;
      
      /// @brief Get a value that represent an ignored test.
      /// @return true is the test is ignored; otherwise false.
      bool ignored() const noexcept;
      
      /// @brief Get a value that represent a not started test.
      /// @return true is the test is not started; otherwise false.
      bool not_started() const noexcept;
      
      /// @brief Gets a value that represent an succeed test.
      /// @return true is the test is succeed; otherwise false.
      bool succeed() const noexcept;
      
      /// @brief Gets the stack frame of the test method.
      /// @return The stack frame of the test method.
      const xtd::diagnostics::stack_frame stack_frame() const noexcept;
      
      /// @brief Gets the start time of the test method.
      /// @return The start time of the test method.
      const xtd::date_time& start_time() const noexcept;
      
      /// @brief Gets the test method.
      /// @return The test method.
      std::function<void()> method() const noexcept;
      
      /// @brief Gets the message.
      /// @return The message.
      const xtd::ustring& message() const noexcept;
      
      /// @brief Gets the name of the test method.
      /// @return The nzme of the test method.
      const xtd::ustring& name() const noexcept;
      
      /// @brief Gets the user message.
      /// @return The user message.
      const xtd::ustring& user_message() const noexcept;
      /// @}
      
      /// @cond
      static intptr __internal_tunit_unit_tests_mode__;
      /// @endcond
      
    private:
      friend class xtd::tunit::assert;
      friend class xtd::tunit::base_assert;
      friend class xtd::tunit::test_class;
      friend class xtd::tunit::valid;
      static test& current_test();
      static const test_class& current_test_class();
      static const unit_test& current_unit_test();
      static bool has_current_test();
      static bool has_current_test_class();
      static bool has_current_unit_test();
      
      void run(const xtd::tunit::unit_test& unit_test, const xtd::tunit::test_class& test_class);
      
      xtd::date_time end_time_point;
      static test* current_test_;
      static const test_class* current_test_class_;
      static const unit_test* current_unit_test_;
      xtd::ustring actual_;
      xtd::ustring expect_;
      xtd::diagnostics::stack_frame stack_frame_ = xtd::diagnostics::stack_frame::empty();
      xtd::ustring message_;
      std::function<void()> method_;
      xtd::ustring name_;
      xtd::date_time start_time_;
      test_status status_ = test_status::not_started;
      xtd::ustring user_message_;
    };
  }
}
