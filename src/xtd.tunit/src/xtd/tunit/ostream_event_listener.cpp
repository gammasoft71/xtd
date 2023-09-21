#include "../../../include/xtd/tunit/ostream_event_listener.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include <xtd/console>

using namespace xtd;
using namespace xtd::tunit;

ostream_event_listener::ostream_event_listener(std::ostream& os) noexcept : os_(os) {
}

void ostream_event_listener::on_class_end(const xtd::tunit::class_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << e.test_class().test_count() << " tests from " << e.test_class().name() << " (" << e.test_class().elapsed_time().count() << " ms total)" << std::endl << std::endl;
  }
  event_listener::on_class_end(e);
}

void ostream_event_listener::on_class_start(const xtd::tunit::class_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << e.test_class().test_count() << " tests from " << e.test_class().name() << std::endl;
  }
  event_listener::on_class_start(e);
}

void ostream_event_listener::on_test_aborted(const xtd::tunit::test_event_args& e) const {
  event_listener::on_test_aborted(e);
  if (settings::default_settings().gtest_compatibility()) {
    os_ << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << std::endl;
    if (e.test().actual() != "") os_ << "Value of: " << e.test().actual() << std::endl;
    if (e.test().actual() != "") os_ << "  Actual: " << e.test().actual() << std::endl;
    if (e.test().expect() != "") os_ << "Expected: " << e.test().expect() << std::endl;
    if (e.test().message() != "") os_ << e.test().message() << std::endl;
    console::foreground_color(console_color::dark_red);
    os_ << "[  ABORTED ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << std::endl;
  } else {
    console::foreground_color(console_color::dark_magenta);
    os_ << "  ABORTED ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (xtd::tunit::settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << std::endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << std::endl;
    if (e.test().expect() != "")
      os_ << "    Expected: " << e.test().expect() << std::endl;
    if (e.test().actual() != "")
      os_ << "    But was:  " << e.test().actual() << std::endl;
    if ((e.test().expect() != "" || e.test().actual() != "") && e.test().stack_frame() != xtd::diagnostics::stack_frame::empty()) {
      os_ << "    Stack Trace: in " << e.test().stack_frame().get_file_name();
      if (e.test().stack_frame().get_file_line_number() != 0) os_ << ":" << e.test().stack_frame().get_file_line_number();
    }
    os_ << std::endl;
  }
}

void ostream_event_listener::on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << "Global test environment tear-down" << std::endl;
  }
  event_listener::on_unit_test_cleanup_start(e);
}

void ostream_event_listener::on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[----------] ";
    console::reset_color();
    os_ << "Global test environment set-up." << std::endl;
  }
  event_listener::on_unit_test_initialize_start(e);
}

void ostream_event_listener::on_test_failed(const xtd::tunit::test_event_args& e) const {
  event_listener::on_test_failed(e);
  if (settings::default_settings().gtest_compatibility()) {
    os_ << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << std::endl;
    if (e.test().actual() != "") os_ << "Value of: " << e.test().actual() << std::endl;
    if (e.test().actual() != "") os_ << "  Actual: " << e.test().actual() << std::endl;
    if (e.test().expect() != "") os_ << "Expected: " << e.test().expect() << std::endl;
    if (e.test().message() != "") os_ << e.test().message() << std::endl;
    console::foreground_color(console_color::dark_red);
    os_ << "[  FAILED  ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << std::endl;
  } else {
    console::foreground_color(console_color::dark_red);
    os_ << "  FAILED  ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (xtd::tunit::settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << std::endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << std::endl;
    if (e.test().expect() != "")
      os_ << "    Expected: " << e.test().expect() << std::endl;
    if (e.test().actual() != "")
      os_ << "    But was:  " << e.test().actual() << std::endl;
    if (e.test().stack_frame() != xtd::diagnostics::stack_frame::empty()) {
      os_ << "    Stack Trace: in " << e.test().stack_frame().get_file_name();
      if (e.test().stack_frame().get_file_line_number() != 0) os_ << ":" << e.test().stack_frame().get_file_line_number();
    }
    os_ << std::endl;
  }
}

void ostream_event_listener::on_test_ignored(const xtd::tunit::test_event_args& e) const {
  event_listener::on_test_ignored(e);
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_yellow);
    os_ << "[ DISABLED ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << std::endl;
  } else {
    console::foreground_color(console_color::dark_yellow);
    os_ << "  IGNORED ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (xtd::tunit::settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << std::endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << std::endl;
  }
}

void ostream_event_listener::on_test_start(const xtd::tunit::test_event_args& e) const {
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[ RUN      ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << std::endl;
  }
  event_listener::on_test_start(e);
}

void ostream_event_listener::on_test_succeed(const xtd::tunit::test_event_args& e) const {
  event_listener::on_test_succeed(e);
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[       OK ] ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << std::endl;
  } else {
    console::foreground_color(console_color::dark_green);
    os_ << "  SUCCEED ";
    console::reset_color();
    os_ << e.test_class().name() << "." << e.test().name();
    if (xtd::tunit::settings::default_settings().show_duration())
      os_ << " (" << e.test().elapsed_time().count() << " ms total)";
    os_ << std::endl;
    if (e.test().message() != "")
      os_ << "    " << e.test().message() << std::endl;
  }
}

void ostream_event_listener::on_unit_test_end(const xtd::tunit::tunit_event_args& e) const {
  event_listener::on_unit_test_end(e);
  if (settings::default_settings().gtest_compatibility()) {
    console::foreground_color(console_color::dark_green);
    os_ << "[==========] ";
    console::reset_color();
    os_ << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test suite" << (e.unit_test().test_cases_count() > 1 ?  "s" : "") <<  " ran. (" << e.unit_test().elapsed_time().count() << " ms total)" << std::endl;
    console::foreground_color(console_color::dark_green);
    os_ << "[  PASSED  ] ";
    console::reset_color();
    os_ << e.unit_test().succeed_test_count() << " tests." << std::endl;
    if (e.unit_test().failed_test_count()) {
      console::foreground_color(console_color::dark_red);
      os_ << "[  FAILED  ] ";
      console::reset_color();
      os_ << e.unit_test().failed_test_count() << " test, listed below:" << std::endl;
      for (std::string name : e.unit_test().failed_test_names()) {
        console::foreground_color(console_color::dark_red);
        os_ << "[  FAILED  ] ";
        console::reset_color();
        os_ << name << std::endl;
      }
      os_ << std::endl;
      os_ << " " << e.unit_test().failed_test_count() << " FAILED TEST" << std::endl;
    }
    if (!e.unit_test().failed_test_count() && e.unit_test().ignored_test_count()) os_ << std::endl;
    if (e.unit_test().ignored_test_count()) {
      console::foreground_color(console_color::dark_yellow);
      os_ << "  YOU HAVE " << e.unit_test().ignored_test_count() << " DISABLED TEST" << (e.unit_test().ignored_test_count() > 1 ? "S" : "") << std::endl << std::endl;
      console::reset_color();
    }
  } else {
    os_ << std::endl;
    console::reset_color();
    os_ << "Test results:" << std::endl;
    if (e.unit_test().succeed_test_count()) {
      console::foreground_color(console_color::dark_green);
      os_ << "  SUCCEED ";
      console::reset_color();
      os_ << e.unit_test().succeed_test_count() << " test" << (e.unit_test().succeed_test_count() > 1 ? "s" : "") << "." << std::endl;
    }
    if (e.unit_test().aborted_test_count()) {
      console::foreground_color(console_color::dark_magenta);
      os_ << "  ABORTED ";
      console::reset_color();
      os_ << e.unit_test().aborted_test_count() << " test" << (e.unit_test().aborted_test_count() > 1 ? "s" : "") << "." << std::endl;
    }
    if (e.unit_test().failed_test_count()) {
      console::foreground_color(console_color::dark_red);
      os_ << "  FAILED  ";
      console::reset_color();
      os_ << e.unit_test().failed_test_count() << " test" << (e.unit_test().failed_test_count() > 1 ? "s" : "") << "." << std::endl;
    }
    if (e.unit_test().ignored_test_count()) {
      console::foreground_color(console_color::dark_yellow);
      os_ << "  IGNORED ";
      console::reset_color();
      os_ << e.unit_test().ignored_test_count() << " test" << (e.unit_test().ignored_test_count() > 1 ? "s" : "") << "." << std::endl;
    }
    
    os_ << "End " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() > 1 ? "s" : "") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() > 1 ? "s" : "") << " ran.";
    if (xtd::tunit::settings::default_settings().show_duration())
      os_ << " (" << e.unit_test().elapsed_time().count() << " ms total)";
    os_ << std::endl << std::endl;
  }
}

void ostream_event_listener::on_unit_test_start(const xtd::tunit::tunit_event_args& e) const {
  if (e.unit_test().repeat_tests()) {
    if (!settings::default_settings().gtest_compatibility()) console::foreground_color(console_color::dark_cyan);
    os_ << "Repeating all tests (iteration " << e.unit_test().repeat_iteration() << ") . . ." << std::endl << std::endl;
    console::reset_color();
  }
  if (settings::default_settings().gtest_compatibility()) {
    os_ << "Running main() from " << settings::default_settings().file_name_ << std::endl;
    console::foreground_color(console_color::dark_green);
    os_ << "[==========] ";
    console::reset_color();
    os_ << "Running " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test suite" << (e.unit_test().test_cases_count() > 1 ? "s" : "") << "." << std::endl;
  } else {
    os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() > 1 ? "s" : "") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() > 1 ? "s" : "") << std::endl;
    os_ << "Run tests:" << std::endl;
  }
  event_listener::on_unit_test_start(e);
}
