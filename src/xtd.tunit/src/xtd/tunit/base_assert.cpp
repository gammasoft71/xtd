#include "../../../include/xtd/tunit/base_assert.h"
#include "../../../include/xtd/tunit/settings.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include "../../../include/xtd/tunit/test.h"
#include <xtd/diagnostics/assert>
#include <xtd/environment>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void base_assert::abort() {
  abort(ustring::empty_string, stack_frame::empty());
}

void base_assert::abort(const stack_frame& stack_frame) {
  abort(ustring::empty_string, stack_frame);
}

void base_assert::abort(const ustring& message) {
  abort(message, stack_frame::empty());
}

void base_assert::abort(const ustring& message, const stack_frame& stack_frame) {
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

void base_assert::fail() {
  fail(ustring::empty_string, stack_frame::empty());
}

void base_assert::fail(const stack_frame& stack_frame) {
  fail(ustring::empty_string, stack_frame);
}

void base_assert::fail(const ustring& message) {
  fail(message, stack_frame::empty());
}

void base_assert::fail(const ustring& message, const stack_frame& stack_frame) {
  fail(ustring::empty_string, ustring::empty_string, message, stack_frame);
}

void base_assert::error() {
  settings::default_settings().exit_status(EXIT_FAILURE);
  if (!test::has_current_unit_test()) throw assert_error("Test failed"_s);
  else test::current_unit_test().event_listener_->on_test_failed(test_event_args(test::current_test(), test::current_test_class(), test::current_unit_test()));
}

void base_assert::error(const ustring& message) {
  settings::default_settings().exit_status(EXIT_FAILURE);
  if (!test::has_current_unit_test()) throw assert_error(!message.empty() ? message : "Test failed"_s);
  else test::current_unit_test().event_listener_->on_test_failed(test_event_args(test::current_test(), test::current_test_class(), test::current_unit_test()));
}

void base_assert::error(const ustring& expected, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
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

void base_assert::fail(const ustring& expected, const ustring& actual, const ustring& message, const stack_frame& stack_frame) {
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
  } else throw assert_error(message != ""_s ? message : "assertion failed!"_s);
}

void base_assert::ignore() {
  ignore(ustring::empty_string, stack_frame::empty());
}

void base_assert::ignore(const stack_frame& stack_frame) {
  ignore(ustring::empty_string, stack_frame);
}

void base_assert::ignore(const ustring& message) {
  ignore(message, stack_frame::empty());
}

void base_assert::ignore(const ustring& message, const stack_frame& stack_frame) {
  if (!test::has_current_test()) throw ignore_error(!message.empty() ? message : "Test ignored"_s);
  else {
    if (stack_frame != stack_frame::empty())
      test::current_test().stack_frame_ = stack_frame;
    test::current_test().message_ = message != ""_s ? message : "Test ignored"_s;
    test::current_test().status_ = test::test_status::ignored;
    throw ignore_error(test::current_test().message_);
  }
}

void base_assert::succeed() {
  succeed(ustring::empty_string, csf_);
}

void base_assert::succeed(const stack_frame& stack_frame) {
  succeed(ustring::empty_string, stack_frame);
}

void base_assert::succeed(const ustring& message) {
  succeed(message, csf_);
}

void base_assert::succeed(const ustring& message, const stack_frame& stack_frame) {
  if (test::has_current_test()) {
    if (stack_frame != diagnostics::stack_frame::empty())
      test::current_test().stack_frame_ = stack_frame;
    test::current_test().message_ = message;
    if (test::current_test().status_ != test::test_status::failed)
      test::current_test().status_ = test::test_status::succeed;
  }
}

ustring base_assert::join_items(const ustring& str) {
  return __tunit_join__items(str);
}

bool base_assert::is_debug() noexcept {
  return environment::compiler_version().build_type() == build_type::debug;
}
