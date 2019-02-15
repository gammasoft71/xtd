#include "../include/xtd/assert.hpp"
#include "../include/xtd/test.hpp"
#include <string>

using namespace xtd::tunit;
using namespace std;
using namespace std::string_literals;

void assert::succeed(const std::string& user_message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().user_message_ = user_message;
}

void assert::failed(const std::string& failed_message, const std::string& user_message, const xtd::tunit::line_info& line_info) {
  if (line_info != xtd::tunit::line_info::empty())
    xtd::tunit::test::current_test().info_ = line_info;
  xtd::tunit::test::current_test().message_ = failed_message;
  xtd::tunit::test::current_test().passed_ = false;
  xtd::tunit::test::current_test().user_message_ = user_message;
  throw assert_error(user_message != ""s ? user_message : "assertion failed!"s);
}
