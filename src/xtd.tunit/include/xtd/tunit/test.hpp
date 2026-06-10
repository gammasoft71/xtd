/// @file
/// @brief Contains xtd::tunit::test class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.hpp"
#include "assert.hpp"
#include "assert_error.hpp"
#include <xtd/diagnostics/stack_frame>
#include <xtd/date_time>

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
    /// @remarks This test contains among others: a name that represents the name of the method, a pointer to the method to call and a status on the state of the test.
    class tunit_export_ test final : public xtd::object {
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
      /// @name Public Constructors
      
      /// @{
      /// @brief Creates a new test instance.
      test() = default;
      /// @brief Creates a new test instance with specified name, method and stack frame.
      /// @param name Represents the name of the method. Generally is the same name as the method name.
      /// @param method The method that contains the test.
      /// @param stack_frame The stack frame of the method.
      test(const xtd::string& name, const std::function<void()>& method, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) noexcept;
      /// @brief Creates a new test instance with specified name, method and stack frame.
      /// @param name Represents the name of the method. Generally is the same name as the method name.
      /// @param method The method that contains the test.
      /// @param ignored If `true`, the test will be ignored during tests execution; otherwise, the test will be taken into account during tests execution.
      /// @param stack_frame The stack frame of the method.
      test(const xtd::string& name, const std::function<void()>& method, bool ignore, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) noexcept;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value that represent an aborted test.
      /// @return `true` is the test is aborted; otherwise `false`.
      [[nodiscard]] auto aborted() const noexcept -> bool;
      
      /// @brief Gets the actual value string.
      /// @return The actual value string. Can be empty.
      [[nodiscard]] auto actual() const noexcept -> const xtd::string&;
      
      /// @brief Gets the elapsed time of the test method.
      /// @return The elapsed time of the test method.
      [[nodiscard]] auto elapsed_time() const noexcept -> xtd::time_span;
      
      /// @brief Gets the expect value string.
      /// @return The expect value string. Can be empty.
      [[nodiscard]] auto expect() const noexcept -> const xtd::string&;
      
      /// @brief Gest a value that represent an failed test.
      /// @return tru is the test is failed; otherwise `false`.
      [[nodiscard]] auto failed() const noexcept -> bool;
      
      /// @brief Get a value that represent an ignored test.
      /// @return `true` is the test is ignored; otherwise `false`.
      [[nodiscard]] auto ignored() const noexcept -> bool;
      
      /// @brief Get a value that represent a not started test.
      /// @return `true` is the test is not started; otherwise `false`.
      [[nodiscard]] auto not_started() const noexcept -> bool;
      
      /// @brief Gets a value that represent an succeed test.
      /// @return `true` is the test is succeed; otherwise `false`.
      [[nodiscard]] auto succeed() const noexcept -> bool;
      
      /// @brief Gets the stack frame of the test method.
      /// @return The stack frame of the test method.
      [[nodiscard]] auto stack_frame() const noexcept -> const xtd::diagnostics::stack_frame&;
      
      /// @brief Gets the start time of the test method.
      /// @return The start time of the test method.
      [[nodiscard]] auto start_time() const noexcept -> const xtd::date_time&;
      
      /// @brief Gets the test method.
      /// @return The test method.
      [[nodiscard]] auto method() const noexcept -> std::function<void()>;
      
      /// @brief Gets the message.
      /// @return The message.
      [[nodiscard]] auto message() const noexcept -> const xtd::string&;
      
      /// @brief Gets the name of the test method.
      /// @return The nzme of the test method.
      [[nodiscard]] auto name() const noexcept -> const xtd::string&;
      
      /// @brief Gets the user message.
      /// @return The user message.
      [[nodiscard]] auto user_message() const noexcept -> const xtd::string&;
      /// @}
      
      /// @cond
      static intptr __internal_tunit_unit_tests_mode__;
      /// @endcond
      
    private:
      friend class xtd::tunit::assert;
      friend class xtd::tunit::base_assert;
      friend class xtd::tunit::test_class;
      friend class xtd::tunit::valid;
      [[nodiscard]] static auto current_test() -> test&;
      [[nodiscard]] static auto current_test_class() -> const test_class&;
      [[nodiscard]] static auto current_unit_test() -> const unit_test&;
      [[nodiscard]] static auto has_current_test() -> bool;
      [[nodiscard]] static auto has_current_test_class() -> bool;
      [[nodiscard]] static auto has_current_unit_test() -> bool;
      
      auto run(const xtd::tunit::unit_test& unit_test, const xtd::tunit::test_class& test_class) -> void;
      
      xtd::date_time end_time_point_;
      static test* current_test_;
      static const test_class* current_test_class_;
      static const unit_test* current_unit_test_;
      xtd::string actual_;
      xtd::string expect_;
      xtd::diagnostics::stack_frame stack_frame_ = null;
      xtd::string message_;
      std::function<void()> method_;
      xtd::string name_;
      xtd::date_time start_time_;
      test_status status_ = test_status::not_started;
      xtd::string user_message_;
    };
  }
}
