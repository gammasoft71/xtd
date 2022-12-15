#include "../../../include/xtd/tunit/base_assert.h"
#include "../../../include/xtd/tunit/settings.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include "../../../include/xtd/tunit/test.h"
#include <string>

using namespace xtd::tunit;
using namespace std;
using namespace std::string_literals;

void base_assert::abort() {
  abort("", xtd::diagnostics::stack_frame::empty());
}

void base_assert::abort(const xtd::diagnostics::stack_frame& stack_frame) {
  abort("", stack_frame);
}

void base_assert::abort(const std::string& message) {
  abort(message, xtd::diagnostics::stack_frame::empty());
}

void base_assert::abort(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!xtd::tunit::test::has_current_test()) throw abort_error(!message.empty() ? message : "Test aborted"s);
  else {
    if (stack_frame != xtd::diagnostics::stack_frame::empty())
      xtd::tunit::test::current_test().stack_frame_ = stack_frame;
    if (xtd::tunit::test::current_test().message_.empty())
      xtd::tunit::test::current_test().message_ = !message.empty() ? message : "Test aborted"s;
    xtd::tunit::test::current_test().status_ = test::test_status::aborted;
    throw abort_error(xtd::tunit::test::current_test().message_);
  }
}

void base_assert::fail() {
  fail("", xtd::diagnostics::stack_frame::empty());
}

void base_assert::fail(const xtd::diagnostics::stack_frame& stack_frame) {
  fail("", stack_frame);
}

void base_assert::fail(const std::string& message) {
  fail(message, xtd::diagnostics::stack_frame::empty());
}

void base_assert::fail(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  base_assert::fail("", "", message, stack_frame);
}

void base_assert::error() {
  xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
  if (!xtd::tunit::test::has_current_unit_test()) throw assert_error("Test failed"s);
  else xtd::tunit::test::current_unit_test().event_listener_->on_test_failed(xtd::tunit::test_event_args(xtd::tunit::test::current_test(), xtd::tunit::test::current_test_class(), xtd::tunit::test::current_unit_test()));
}

void base_assert::error(const std::string& message) {
  xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
  if (!xtd::tunit::test::has_current_unit_test()) throw assert_error(!message.empty() ? message : "Test failed"s);
  else xtd::tunit::test::current_unit_test().event_listener_->on_test_failed(xtd::tunit::test_event_args(xtd::tunit::test::current_test(), xtd::tunit::test::current_test_class(), xtd::tunit::test::current_unit_test()));
}

void base_assert::error(const std::string& expected, const std::string& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!xtd::tunit::test::has_current_test()) base_assert::error(message);
  else {
    if (stack_frame != xtd::diagnostics::stack_frame::empty())
      xtd::tunit::test::current_test().stack_frame_ = stack_frame;
    xtd::tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
    xtd::tunit::test::current_test().actual_ = actual;
    xtd::tunit::test::current_test().expect_ = expected;
    base_assert::error();
  }
}

void base_assert::fail(const std::string& expected, const std::string& actual, const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (xtd::tunit::test::has_current_test()) {
    if (stack_frame != xtd::diagnostics::stack_frame::empty())
      xtd::tunit::test::current_test().stack_frame_ = stack_frame;
    xtd::tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
    xtd::tunit::test::current_test().actual_ = actual;
    xtd::tunit::test::current_test().expect_ = expected;
    xtd::tunit::test::current_test().status_ = test::test_status::failed;
  }
  throw assert_error(message != ""s ? message : "assertion failed!"s);
}

void base_assert::ignore() {
  ignore("", xtd::diagnostics::stack_frame::empty());
}

void base_assert::ignore(const xtd::diagnostics::stack_frame& stack_frame) {
  ignore("", stack_frame);
}

void base_assert::ignore(const std::string& message) {
  ignore(message, xtd::diagnostics::stack_frame::empty());
}

void base_assert::ignore(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (!xtd::tunit::test::has_current_test()) throw ignore_error(!message.empty() ? message : "Test ignored"s);
  else {
    if (stack_frame != xtd::diagnostics::stack_frame::empty())
      xtd::tunit::test::current_test().stack_frame_ = stack_frame;
    xtd::tunit::test::current_test().message_ = message != ""s ? message : "Test ignored"s;
    xtd::tunit::test::current_test().status_ = test::test_status::ignored;
    throw ignore_error(xtd::tunit::test::current_test().message_);
  }
}

void base_assert::succeed() {
  succeed("", csf_);
}

void base_assert::succeed(const xtd::diagnostics::stack_frame& stack_frame) {
  succeed("", stack_frame);
}

void base_assert::succeed(const std::string& message) {
  succeed(message, csf_);
}

void base_assert::succeed(const std::string& message, const xtd::diagnostics::stack_frame& stack_frame) {
  if (xtd::tunit::test::has_current_test()) {
    if (stack_frame != xtd::diagnostics::stack_frame::empty())
      xtd::tunit::test::current_test().stack_frame_ = stack_frame;
    xtd::tunit::test::current_test().message_ = message;
    if (xtd::tunit::test::current_test().status_ != test::test_status::failed)
      xtd::tunit::test::current_test().status_ = test::test_status::succeed;
  }
}

std::string base_assert::join_items(const std::string& str) {
  return __tunit_join__items(str);
}
