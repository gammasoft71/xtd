#include "../../../include/xtd/tunit/base_assert.h"
#include "../../../include/xtd/tunit/settings.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include "../../../include/xtd/tunit/test.h"
#include <string>

using namespace xtd::tunit;
using namespace std;
using namespace std::string_literals;

void base_assert::abort(const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  if (xtd::tunit::test::current_test().message_.empty())
    xtd::tunit::test::current_test().message_ = !message.empty() ? message : "Test aborted"s;
  xtd::tunit::test::current_test().status_ = test::test_status::aborted;
  throw abort_error(xtd::tunit::test::current_test().message_);
}

void base_assert::error() {
  xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
  xtd::tunit::test::current_unit_test().event_listener_->on_test_failed(xtd::tunit::test_event_args(xtd::tunit::test::current_test(), xtd::tunit::test::current_test_class(), xtd::tunit::test::current_unit_test()));
}

void base_assert::error(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
  xtd::tunit::test::current_test().actual_ = actual;
  xtd::tunit::test::current_test().expect_ = expected;
  base_assert::error();
}

void base_assert::fail(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
  xtd::tunit::test::current_test().actual_ = actual;
  xtd::tunit::test::current_test().expect_ = expected;
  xtd::tunit::test::current_test().status_ = test::test_status::failed;
  throw assert_error(message != ""s ? message : "assertion failed!"s);
}

void base_assert::ignore(const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message != ""s ? message : "Test ignored"s;
  xtd::tunit::test::current_test().status_ = test::test_status::ignored;
  throw ignore_error(xtd::tunit::test::current_test().message_);
}

void base_assert::succeed(const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message;
  if (xtd::tunit::test::current_test().status_ != test::test_status::failed)
    xtd::tunit::test::current_test().status_ = test::test_status::succeed;
}
