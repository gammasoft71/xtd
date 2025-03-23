#include "../../../include/xtd/tunit/test.hpp"
#include "../../../include/xtd/tunit/unit_test.hpp"
#include <xtd/diagnostics//debug_break>
#include <xtd/environment>
#include <xtd/runtime/exception_services/exception_dispatch_info>
#include <xtd/null_pointer_exception>
#include <exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::runtime::exception_services;
using namespace xtd::tunit;

test* test::current_test_ = nullptr;
const test_class* test::current_test_class_ = nullptr;
const unit_test* test::current_unit_test_ = nullptr;
intptr test::__internal_tunit_unit_tests_mode__ = reinterpret_cast<intptr>("");

test::test(const string& name, const std::function<void()>& method, const diagnostics::stack_frame& stack_frame) noexcept : test(name, method, false, stack_frame) {
}

test::test(const string& name, const std::function<void()>& method, bool ignore, const diagnostics::stack_frame& stack_frame) noexcept : stack_frame_(stack_frame), method_(method), name_(name), status_(ignore ? test_status::ignored : test_status::not_started) {
}

bool test::aborted() const noexcept {
  return status_ == test_status::aborted;
}

const string& test::actual() const noexcept {
  return actual_;
}

time_span test::elapsed_time() const noexcept {
  if (start_time_.ticks() == 0 && end_time_point_.ticks() == 0) return 0_ms;
  if (end_time_point_.ticks() == 0) return date_time::now() - start_time_;
  return end_time_point_ - start_time_;
}

const string& test::expect() const noexcept {
  return expect_;
}

bool test::failed() const noexcept {
  return status_ == test_status::failed;
}

bool test::ignored() const noexcept {
  return status_ == test_status::ignored;
}

bool test::not_started() const noexcept {
  return status_ == test_status::not_started;
}

bool test::succeed() const noexcept {
  return status_ == test_status::succeed;
}

const stack_frame test::stack_frame() const noexcept {
  return stack_frame_;
}

const xtd::date_time& test::start_time() const noexcept {
  return start_time_;
}

std::function<void()> test::method() const noexcept {
  return method_;
}

const string& test::message() const noexcept {
  return message_;
}

const string& test::name() const noexcept {
  return name_;
}

const string& test::user_message() const noexcept {
  return user_message_;
}

test& test::current_test() {
  if (!has_current_test()) throw_helper::throws(exception_case::null_pointer);
  return *current_test_;
}

const test_class& test::current_test_class() {
  if (!has_current_test_class()) throw_helper::throws(exception_case::null_pointer);
  return *current_test_class_;
}

const unit_test& test::current_unit_test() {
  if (!has_current_unit_test()) throw_helper::throws(exception_case::null_pointer);
  return *current_unit_test_;
}

bool test::has_current_test() {
  return current_test_ != nullptr;
}

bool test::has_current_test_class() {
  return current_test_class_ != nullptr;
}

bool test::has_current_unit_test() {
  return current_unit_test_ != nullptr;
}

void test::run(const unit_test& unit_test, const test_class& test_class) {
  current_test_ = this;
  current_test_class_ = &test_class;
  current_unit_test_ = &unit_test;
  
  if (ignored() && settings::default_settings().also_run_ignored_tests()) status_ = test_status::not_started;
  
  if ((string(reinterpret_cast<const char*>(__internal_tunit_unit_tests_mode__)) == "internal_tests" || settings::default_settings().repeat_test() != 1) && (aborted() || failed() || succeed())) status_ = test_status::not_started;
  
  if (settings::default_settings().is_match_test_name(test_class.name(), name())) {
    if (ignored()) {
      try {
        assert::ignore();
      } catch (const ignore_error&) {
        if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_ignored(test_event_args(*this, test_class, unit_test));
      }
    } else if (not_started()) {
      if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_initialize_start(test_event_args(*this, test_class, unit_test));
      if (test_class.test_initialize().method() != nullptr)
        test_class.test_initialize().method()();
      if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_initialize_end(test_event_args(*this, test_class, unit_test));
      
      if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_start(test_event_args(*this, test_class, unit_test));
      try {
        start_time_ = date_time::now();
        method()();
        end_time_point_ = date_time::now();
        if (not_started()) status_ = test_status::succeed;
        if (succeed() && !settings::default_settings().brief())
          unit_test.event_listener_->on_test_succeed(test_event_args(*this, test_class, unit_test));
      } catch (const abort_error&) {
        if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_aborted(test_event_args(*this, test_class, unit_test));
      } catch (const ignore_error&) {
        if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_ignored(test_event_args(*this, test_class, unit_test));
      } catch (const assert_error& e) {
        if (settings::default_settings().brief()) unit_test.event_listener_->on_test_start(test_event_args(*this, test_class, unit_test));
        unit_test.event_listener_->on_test_failed(test_event_args(*this, test_class, unit_test));
        if (settings::default_settings().throw_on_failure()) exception_dispatch_info::rethrow(e);
        if (settings::default_settings().break_on_failure()) xtd::environment::abort();
        else settings::default_settings().exit_status(EXIT_FAILURE);
      } catch (const std::exception& e) {
        test::current_test().message_ = "Exception <" + typeof_(e).full_name() + "> throws" + " (" + e.what() + ")";
        test::current_test().status_ = test::test_status::failed;
        if (settings::default_settings().brief()) unit_test.event_listener_->on_test_start(test_event_args(*this, test_class, unit_test));
        unit_test.event_listener_->on_test_failed(test_event_args(*this, test_class, unit_test));
        if (settings::default_settings().throw_on_failure()) throw assert_error {test::current_test().message()};
        if (settings::default_settings().break_on_failure()) xtd::environment::abort();
        else settings::default_settings().exit_status(EXIT_FAILURE);
      } catch (...) {
        test::current_test().message_ = "Exception <unknown> throws";
        test::current_test().status_ = test::test_status::failed;
        if (settings::default_settings().brief()) unit_test.event_listener_->on_test_start(test_event_args(*this, test_class, unit_test));
        unit_test.event_listener_->on_test_failed(test_event_args(*this, test_class, unit_test));
        if (settings::default_settings().throw_on_failure()) throw assert_error {test::current_test().message()};
        if (settings::default_settings().break_on_failure()) xtd::environment::abort();
        else settings::default_settings().exit_status(EXIT_FAILURE);
      }
      
      if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_cleanup_start(test_event_args(*this, test_class, unit_test));
      if (test_class.test_cleanup().method() != nullptr)
        test_class.test_cleanup().method()();
      if (!settings::default_settings().brief()) unit_test.event_listener_->on_test_cleanup_end(test_event_args(*this, test_class, unit_test));
      
      unit_test.event_listener_->on_test_end(test_event_args(*this, test_class, unit_test));
    }
  }
}
