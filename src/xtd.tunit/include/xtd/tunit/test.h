/// @file
/// @brief Contains xtd::tunit::test class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "../tunit_export.h"
#include "assert.h"
#include "assert_error.h"
#include <xtd/date_time.h>
#include <xtd/diagnostics/stack_frame.h>
#include <functional>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    class test_class;
    class unit_test;
    class valid;
    /// @endcond
    
    class tunit_export_ test final {
      enum class test_status {
        not_started,
        ignored,
        succeed,
        aborted,
        failed
      };
      
    public:
      test() = default;
      test(const std::string& name, const std::function<void()>& method, const xtd::diagnostics::stack_frame& stack_frame) noexcept : test(name, method, false, stack_frame) {}
      test(const std::string& name, const std::function<void()>& method, bool ignore, const xtd::diagnostics::stack_frame& stack_frame) noexcept :  stack_frame_(stack_frame), method_(method), name_(name), status_(ignore ? test_status::ignored : test_status::not_started) {}
      
      bool aborted() const noexcept {return status_ == test_status::aborted;}
      
      const std::string& actual() const noexcept {return actual_;}
      
      const std::string& expect() const noexcept {return expect_;}
      
      bool failed() const noexcept {return status_ == test_status::failed;}
      
      bool ignored() const noexcept {return status_ == test_status::ignored;}
      
      bool not_started() const noexcept {return status_ == test_status::not_started;}
      
      bool succeed() const noexcept {return status_ == test_status::succeed;}
      
      const xtd::diagnostics::stack_frame stack_frame() const noexcept {return stack_frame_;}
      
      const xtd::date_time& start_time() const noexcept {return start_time_;}
      
      std::function<void()> method() const noexcept {return method_;}
      
      const std::string& message() const noexcept {return message_;}
      
      const std::string& name() const noexcept {return name_;}
      
      const std::string& user_message() const noexcept {return user_message_;}
      
      std::chrono::milliseconds elapsed_time() const noexcept {
        using namespace std::chrono_literals;
        if (start_time_.ticks() == 0ms && end_time_point.ticks() == 0ms) return 0ms;
        if (end_time_point.ticks() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>((date_time::now() - start_time_).ticks());
        return std::chrono::duration_cast<std::chrono::milliseconds>((end_time_point - start_time_).ticks());
      }
      
      /// @cond
      static intptr __internal_tunit_unit_tests_mode__;
      /// @endcond
      
    private:
      friend class xtd::tunit::assert;
      friend class xtd::tunit::base_assert;
      friend class xtd::tunit::test_class;
      friend class xtd::tunit::valid;
      static test& current_test() {return *current_test_;}
      static const test_class& current_test_class() {return *current_test_class_;}
      static const unit_test& current_unit_test() {return *current_unit_test_;}
      static bool has_current_test() {return current_test_ != nullptr;}
      static bool has_current_test_class() {return current_test_class_ != nullptr;}
      static bool has_current_unit_test() {return current_unit_test_ != nullptr;}

      void run(const xtd::tunit::unit_test& unit_test, const xtd::tunit::test_class& test_class);
      
      xtd::date_time end_time_point;
      static test* current_test_;
      static const test_class* current_test_class_;
      static const unit_test* current_unit_test_;
      std::string actual_;
      std::string expect_;
      xtd::diagnostics::stack_frame stack_frame_ = xtd::diagnostics::stack_frame::empty();
      std::string message_;
      std::function<void()> method_;
      std::string name_;
      xtd::date_time start_time_;
      test_status status_ = test_status::not_started;
      std::string user_message_;
    };
  }
}
