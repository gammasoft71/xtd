#include "../../../include/xtd/tunit/base_assert.hpp"
#include "../../../include/xtd/tunit/settings.hpp"
#include "../../../include/xtd/tunit/unit_test.hpp"
#include "../../../include/xtd/tunit/test.hpp"
#include <xtd/diagnostics/assert>
#include <xtd/environment>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void base_assert::abort(const stack_frame& stack_frame) {
  abort(string::empty_string, stack_frame);
}

void base_assert::abort(const string& message, const stack_frame& stack_frame) {
  if (!test::has_current_test()) throw abort_error(!message.empty() ? message : "Test aborted"_s);
  else {
    if (stack_frame != stack_frame::empty())
      test::current_test().stack_frame_ = stack_frame;
    if (test::current_test().message_.empty())
      test::current_test().message_ = !message.empty() ? message : "Test aborted"_s;
    test::current_test().status_ = test::test_status::aborted;
    throw abort_error(test::current_test().message_);
  }
}

void base_assert::fail(const stack_frame& stack_frame) {
  fail(string::empty_string, stack_frame);
}

void base_assert::fail(const string& message, const stack_frame& stack_frame) {
  fail(string::empty_string, string::empty_string, message, stack_frame);
}

void base_assert::error() {
  settings::default_settings().exit_status(EXIT_FAILURE);
  if (!test::has_current_unit_test()) {
    if (settings::default_settings().break_on_failure()) debug_break_();
    throw assert_error("Test failed"_s);
  } else test::current_unit_test().event_listener_->on_test_failed(test_event_args(test::current_test(), test::current_test_class(), test::current_unit_test()));
}

void base_assert::error(const string& message) {
  settings::default_settings().exit_status(EXIT_FAILURE);
  if (!test::has_current_unit_test()) {
    if (settings::default_settings().break_on_failure()) debug_break_();
    throw assert_error(!message.empty() ? message : "Test failed"_s);
  } else test::current_unit_test().event_listener_->on_test_failed(test_event_args(test::current_test(), test::current_test_class(), test::current_unit_test()));
}

void base_assert::error(const string& expected, const string& actual, const string& message, const stack_frame& stack_frame) {
  if (!test::has_current_test()) base_assert::error(message);
  else {
    if (stack_frame != stack_frame::empty())
      test::current_test().stack_frame_ = stack_frame;
    test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"_s : message;
    test::current_test().actual_ = actual;
    test::current_test().expect_ = expected;
    base_assert::error();
  }
}

void base_assert::fail(const string& expected, const string& actual, const string& message, const stack_frame& stack_frame) {
  if (test::has_current_test()) {
    if (stack_frame != stack_frame::empty())
      test::current_test().stack_frame_ = stack_frame;
    test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"_s : message;
    test::current_test().actual_ = actual;
    test::current_test().expect_ = expected;
    test::current_test().status_ = test::test_status::failed;
  }
  if (!test::has_current_unit_test() && is_debug()) {
    assert_(false, message != ""_s ? message : "assertion failed!"_s);
  } else {
    if (settings::default_settings().break_on_failure() && diagnostics::debugger::is_attached()) debug_break_();
    throw assert_error(message != ""_s ? message : "assertion failed!"_s);
  }
}

void base_assert::ignore(const stack_frame& stack_frame) {
  ignore(string::empty_string, stack_frame);
}

void base_assert::ignore(const string& message, const stack_frame& stack_frame) {
  if (settings::default_settings().also_run_ignored_tests()) return;
  if (!test::has_current_test()) throw ignore_error(message);
  else {
    if (stack_frame != stack_frame::empty())
      test::current_test().stack_frame_ = stack_frame;
    test::current_test().message_ = message;
    test::current_test().status_ = test::test_status::ignored;
    throw ignore_error(test::current_test().message_);
  }
}

void base_assert::succeed(const stack_frame& stack_frame) {
  succeed(string::empty_string, stack_frame);
}

void base_assert::succeed(const string& message, const stack_frame& stack_frame) {
  if (test::has_current_test()) {
    if (stack_frame != diagnostics::stack_frame::empty())
      test::current_test().stack_frame_ = stack_frame;
    test::current_test().message_ = message;
    if (test::current_test().status_ != test::test_status::failed)
      test::current_test().status_ = test::test_status::succeed;
  }
}

string base_assert::join_items(const string& str) {
  return __tunit_join__items(str);
}

bool base_assert::is_debug() noexcept {
  return environment::compiler_version().build_type() == build_type::debug;
}
