#include "../include/xtd/valid.hpp"
#include "../include/xtd/event_listener.hpp"
#include "../include/xtd/test.hpp"
#include "../include/xtd/test_class.hpp"
#include "../include/xtd/unit_test.hpp"

using namespace xtd::tunit;
using namespace std;
using namespace std::string_literals;

void valid::message() {
  xtd::tunit::settings::default_settings().exit_status(EXIT_FAILURE);
  xtd::tunit::test::current_unit_test().event_listener_->on_test_failed(xtd::tunit::test_event_args(xtd::tunit::test::current_test(), xtd::tunit::test::current_test_class(), xtd::tunit::test::current_unit_test()));
}
