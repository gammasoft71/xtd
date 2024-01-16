#include "../../../include/xtd/tunit/ostream_event_listener.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include <xtd/console>
#include <xtd/ustring>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

ostream_event_listener::ostream_event_listener(ostream& os) noexcept : os_(os) {
}

void ostream_event_listener::on_class_end(const class_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << e.test_class().test_count() << " tests from " << e.test_class().name() << " (" << e.test_class().elapsed_time().count() << " ms total)" << endl << endl;
  }
  event_listener::on_class_end(e);
}

void ostream_event_listener::on_class_start(const class_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << e.test_class().test_count() << " tests from " << e.test_class().name() << endl;
  }
  event_listener::on_class_start(e);
}

void ostream_event_listener::on_test_aborted(const test_event_args& e) const {
  event_listener::on_test_aborted(e);
  if (settings::default_settings().gtest_compatibility()) {
    os_ << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << endl;
    if (e.test().actual() != "") os_ << "Value of: " << e.test().actual() << endl;
    if (e.test().actual() != "") os_ << "  Actual: " << e.test().actual() << endl;
    if (e.test().expect() != "") os_ << "Expected: " << e.test().expect() << endl;
    if (e.test().message() != "") os_ << e.test().message() << endl;
    console::foreground_color(console_color::dark_red);
    os_ << "[  ABORTED ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << endl;
  } else {
    console::foreground_color(console_color::dark_magenta);
    os_ << "  ABORTED ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << endl;
    if (e.test().expect() != "")
      os_ << "    Expected: " << e.test().expect() << endl;
    if (e.test().actual() != "")
      os_ << "    But was:  " << e.test().actual() << endl;
    if ((e.test().expect() != "" || e.test().actual() != "") && e.test().stack_frame() != stack_frame::empty()) {
      os_ << "    Stack Trace: in " << e.test().stack_frame().get_file_name();
      if (e.test().stack_frame().get_file_line_number() != 0) os_ << ":" << e.test().stack_frame().get_file_line_number();
    }
    os_ << endl;
  }
}

void ostream_event_listener::on_unit_test_cleanup_start(const tunit_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << "Global test environment tear-down" << endl;
  }
  event_listener::on_unit_test_cleanup_start(e);
}

void ostream_event_listener::on_unit_test_initialize_start(const tunit_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << "Global test environment set-up." << endl;
  }
  event_listener::on_unit_test_initialize_start(e);
}

void ostream_event_listener::on_test_failed(const test_event_args& e) const {
  event_listener::on_test_failed(e);
  if (settings::default_settings().gtest_compatibility()) {
    os_ << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << endl;
    if (e.test().actual() != "") os_ << "Value of: " << e.test().actual() << endl;
    if (e.test().actual() != "") os_ << "  Actual: " << e.test().actual() << endl;
    if (e.test().expect() != "") os_ << "Expected: " << e.test().expect() << endl;
    if (e.test().message() != "") os_ << e.test().message() << endl;
    console::foreground_color(console_color::dark_red);
    os_ << "[  FAILED  ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << endl;
  } else {
    console::foreground_color(console_color::dark_red);
    os_ << "  FAILED  ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << endl;
    if (e.test().expect() != "")
      os_ << "    Expected: " << e.test().expect() << endl;
    if (e.test().actual() != "")
      os_ << "    But was:  " << e.test().actual() << endl;
    if (e.test().stack_frame() != stack_frame::empty()) {
      os_ << "    Stack Trace: in " << e.test().stack_frame().get_file_name();
      if (e.test().stack_frame().get_file_line_number() != 0) os_ << ":" << e.test().stack_frame().get_file_line_number();
    }
    os_ << endl;
  }
}

void ostream_event_listener::on_test_ignored(const test_event_args& e) const {
  event_listener::on_test_ignored(e);
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_yellow);
    os_ << "[ DISABLED ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << endl;
  } else {
    console::foreground_color(console_color::dark_yellow);
    os_ << "  IGNORED ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << endl;
  }
}

void ostream_event_listener::on_test_start(const test_event_args& e) const {
  if (settings::default_settings().gtest_compatibility() && !e.test().name().starts_with("DISABLED_")) {
    console::foreground_color(console_color::dark_green);
    os_ << "[ RUN      ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << endl;
  }
  event_listener::on_test_start(e);
}

void ostream_event_listener::on_test_succeed(const test_event_args& e) const {
  event_listener::on_test_succeed(e);
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[       OK ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << endl;
  } else {
    console::foreground_color(console_color::dark_green);
    os_ << "  SUCCEED ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << endl;
  }
}

void ostream_event_listener::on_unit_test_end(const tunit_event_args& e) const {
  event_listener::on_unit_test_end(e);
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[==========] ";
    console::reset_color();
    os_ << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test suite" << (e.unit_test().test_cases_count() > 1 ?  "s" : "") <<  " ran. (" << e.unit_test().elapsed_time().count() << " ms total)" << endl;
    console::foreground_color(console_color::dark_green);
    os_ << "[  PASSED  ] ";
    console::reset_color();
    os_ << e.unit_test().succeed_test_count() << " tests." << endl;
    if (e.unit_test().failed_test_count()) {
      console::foreground_color(console_color::dark_red);
      os_ << "[  FAILED  ] ";
      console::reset_color();
      os_ << e.unit_test().failed_test_count() << " test, listed below:" << endl;
      for (ustring name : e.unit_test().failed_test_names()) {
        console::foreground_color(console_color::dark_red);
        os_ << "[  FAILED  ] ";
        console::reset_color();
        os_ << name << endl;
      }
      os_ << endl;
      os_ << " " << e.unit_test().failed_test_count() << " FAILED TEST" << endl;
    }
    if (!e.unit_test().failed_test_count() && e.unit_test().ignored_test_count()) os_ << endl;
    if (e.unit_test().ignored_test_count()) {
      console::foreground_color(console_color::dark_yellow);
      os_ << "  YOU HAVE " << e.unit_test().ignored_test_count() << " DISABLED TEST" << (e.unit_test().ignored_test_count() > 1 ? "S" : "") << endl << endl;
      console::reset_color();
    }
  } else {
    os_ << endl;
    console::reset_color();
    os_ << "Test results:" << endl;
    if (e.unit_test().succeed_test_count()) {
      console::foreground_color(console_color::dark_green);
      os_ << "  SUCCEED ";
      console::reset_color();
      os_ << e.unit_test().succeed_test_count() << " test" << (e.unit_test().succeed_test_count() > 1 ? "s" : "") << "." << endl;
    }
    if (e.unit_test().aborted_test_count()) {
      console::foreground_color(console_color::dark_magenta);
      os_ << "  ABORTED ";
      console::reset_color();
      os_ << e.unit_test().aborted_test_count() << " test" << (e.unit_test().aborted_test_count() > 1 ? "s" : "") << "." << endl;
    }
    if (e.unit_test().failed_test_count()) {
      console::foreground_color(console_color::dark_red);
      os_ << "  FAILED  ";
      console::reset_color();
      os_ << e.unit_test().failed_test_count() << " test" << (e.unit_test().failed_test_count() > 1 ? "s" : "") << "." << endl;
    }
    if (e.unit_test().ignored_test_count()) {
      console::foreground_color(console_color::dark_yellow);
      os_ << "  IGNORED ";
      console::reset_color();
      os_ << e.unit_test().ignored_test_count() << " test" << (e.unit_test().ignored_test_count() > 1 ? "s" : "") << "." << endl;
    }
    
    os_ << "End " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() > 1 ? "s" : "") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() > 1 ? "s" : "") << " ran.";
    if (settings::default_settings().show_duration())
      os_ << " (" << e.unit_test().elapsed_time().count() << " ms total)";
    os_ << endl << endl;
  }
}

void ostream_event_listener::on_unit_test_start(const tunit_event_args& e) const {
  if (e.unit_test().repeat_tests()) {
    if (!settings::default_settings().gtest_compatibility()) console::foreground_color(console_color::dark_cyan);
    os_ << "Repeating all tests (iteration " << e.unit_test().repeat_iteration() << ") . . ." << endl << endl;
    console::reset_color();
  }
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[==========] ";
    console::reset_color();
    os_ << "Running " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test suite" << (e.unit_test().test_cases_count() > 1 ? "s" : "") << "." << endl;
  } else {
    os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() > 1 ? "s" : "") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() > 1 ? "s" : "") << endl;
    os_ << "Run tests:" << endl;
  }
  event_listener::on_unit_test_start(e);
}
