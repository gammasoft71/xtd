#include "../../../include/xtd/tunit/base_assert.h"
#include "../../../include/xtd/tunit/settings.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include "../../../include/xtd/tunit/test.h"
#include <string>

using namespace std;
using namespace string_literals;
using namespace xtd::tunit;

void base_assert::abort() {
  abort("", diagnostics::stack_frame::empty());
}

void base_assert::abort(const diagnostics::stack_frame& stack_frame) {
  abort("", stack_frame);
}

void base_assert::abort(const string& message) {
  abort(message, diagnostics::stack_frame::empty());
}

void base_assert::abort(const string& message, const diagnostics::stack_frame& stack_frame) {
  if (!tunit::test::has_current_test()) throw abort_error(!message.empty() ? message : "Test aborted"s);
  else {
    if (stack_frame != diagnostics::stack_frame::empty())
      tunit::test::current_test().stack_frame_ = stack_frame;
    if (tunit::test::current_test().message_.empty())
      tunit::test::current_test().message_ = !message.empty() ? message : "Test aborted"s;
    tunit::test::current_test().status_ = test::test_status::aborted;
    throw abort_error(tunit::test::current_test().message_);
  }
}

void base_assert::fail() {
  fail("", diagnostics::stack_frame::empty());
}

void base_assert::fail(const diagnostics::stack_frame& stack_frame) {
  fail("", stack_frame);
}

void base_assert::fail(const string& message) {
  fail(message, diagnostics::stack_frame::empty());
}

void base_assert::fail(const string& message, const diagnostics::stack_frame& stack_frame) {
  base_assert::fail("", "", message, stack_frame);
}

void base_assert::error() {
  tunit::settings::default_settings().exit_status(EXIT_FAILURE);
  if (!tunit::test::has_current_unit_test()) throw assert_error("Test failed"s);
  else tunit::test::current_unit_test().event_listener_->on_test_failed(tunit::test_event_args(tunit::test::current_test(), tunit::test::current_test_class(), tunit::test::current_unit_test()));
}

void base_assert::error(const string& message) {
  tunit::settings::default_settings().exit_status(EXIT_FAILURE);
  if (!tunit::test::has_current_unit_test()) throw assert_error(!message.empty() ? message : "Test failed"s);
  else tunit::test::current_unit_test().event_listener_->on_test_failed(tunit::test_event_args(tunit::test::current_test(), tunit::test::current_test_class(), tunit::test::current_unit_test()));
}

void base_assert::error(const string& expected, const string& actual, const string& message, const diagnostics::stack_frame& stack_frame) {
  if (!tunit::test::has_current_test()) base_assert::error(message);
  else {
    if (stack_frame != diagnostics::stack_frame::empty())
      tunit::test::current_test().stack_frame_ = stack_frame;
    tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
    tunit::test::current_test().actual_ = actual;
    tunit::test::current_test().expect_ = expected;
    base_assert::error();
  }
}

void base_assert::fail(const string& expected, const string& actual, const string& message, const diagnostics::stack_frame& stack_frame) {
  if (tunit::test::has_current_test()) {
    if (stack_frame != diagnostics::stack_frame::empty())
      tunit::test::current_test().stack_frame_ = stack_frame;
    tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
    tunit::test::current_test().actual_ = actual;
    tunit::test::current_test().expect_ = expected;
    tunit::test::current_test().status_ = test::test_status::failed;
  }
  throw assert_error(message != ""s ? message : "assertion failed!"s);
}

void base_assert::ignore() {
  ignore("", diagnostics::stack_frame::empty());
}

void base_assert::ignore(const diagnostics::stack_frame& stack_frame) {
  ignore("", stack_frame);
}

void base_assert::ignore(const string& message) {
  ignore(message, diagnostics::stack_frame::empty());
}

void base_assert::ignore(const string& message, const diagnostics::stack_frame& stack_frame) {
  if (!tunit::test::has_current_test()) throw ignore_error(!message.empty() ? message : "Test ignored"s);
  else {
    if (stack_frame != diagnostics::stack_frame::empty())
      tunit::test::current_test().stack_frame_ = stack_frame;
    tunit::test::current_test().message_ = message != ""s ? message : "Test ignored"s;
    tunit::test::current_test().status_ = test::test_status::ignored;
    throw ignore_error(tunit::test::current_test().message_);
  }
}

void base_assert::succeed() {
  succeed("", csf_);
}

void base_assert::succeed(const diagnostics::stack_frame& stack_frame) {
  succeed("", stack_frame);
}

void base_assert::succeed(const string& message) {
  succeed(message, csf_);
}

void base_assert::succeed(const string& message, const diagnostics::stack_frame& stack_frame) {
  if (tunit::test::has_current_test()) {
    if (stack_frame != diagnostics::stack_frame::empty())
      tunit::test::current_test().stack_frame_ = stack_frame;
    tunit::test::current_test().message_ = message;
    if (tunit::test::current_test().status_ != test::test_status::failed)
      tunit::test::current_test().status_ = test::test_status::succeed;
  }
}

string base_assert::join_items(const string& str) {
  return __tunit_join__items(str);
}
