#include "../include/xtd/assert.hpp"
#include "../include/xtd/test.hpp"
#include <string>

using namespace xtd::tunit;
using namespace std;
using namespace std::string_literals;

void assert::abort(const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message != ""s ? message : "Test aborted"s;
  xtd::tunit::test::current_test().status_ = test::test_status::aborted;
  throw abort_error(xtd::tunit::test::current_test().message_);
}

void assert::fail(const std::string& expected, const std::string& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message == "" && expected == "" && actual == "" ? "Test failed"s : message;
  xtd::tunit::test::current_test().actual_ = actual;
  xtd::tunit::test::current_test().expect_ = expected;
  xtd::tunit::test::current_test().status_ = test::test_status::failed;
  throw assert_error(message != ""s ? message : "assertion failed!"s);
}


void assert::ignore(const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message != ""s ? message : "Test ignored"s;
  xtd::tunit::test::current_test().status_ = test::test_status::ignored;
  throw ignore_error(xtd::tunit::test::current_test().message_);
}

void assert::succeed(const std::string& message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = message;
  if (xtd::tunit::test::current_test().status_ != test::test_status::failed)
    xtd::tunit::test::current_test().status_ = test::test_status::succeed;
}
