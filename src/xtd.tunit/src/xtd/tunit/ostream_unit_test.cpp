#include "../../../include/xtd/tunit/ostream_unit_test.h"
#include "../../../include/xtd/tunit/unit_test.h"
#include <xtd/console>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

ostream_unit_test::ostream_unit_test(std::ostream& os) noexcept : unit_test(make_unique<ostream_event_listener>(os)), os_(os) {
}

ostream_unit_test::ostream_unit_test(std::ostream& os, int argc, char* argv[]) : unit_test(make_unique<ostream_event_listener>(os), argc, argv), os_(os) {
}

ostream& ostream_unit_test::ostream() {
  return os_;
}

int ostream_unit_test::count_tests(int32 count) {
  os_ << count << endl;
  return unit_test::count_tests(count);
}

int ostream_unit_test::list_tests(const vector<ustring>& tests) {
  if (!settings::default_settings().gtest_compatibility()) {
    for (auto name : tests)
      os_ << name << endl;
  } else {
    os_ << "Running main() from " << settings::default_settings().file_name_ << endl;
    map<string, vector<ustring>> lists;
    for (auto name : tests) {
      auto key_value =  ustring(name).split({'.'});
      if (key_value.size() == 2) {
        if (lists.find(key_value[0]) == lists.end()) lists.insert({key_value[0], {}});
        lists.at(key_value[0]).push_back(key_value[1]);
      }
    }
    for (auto key_value : lists) {
      os_ << key_value.first << "." << endl;
      for (auto value : key_value.second)
        os_ << "  " << value << endl;
    }
  }
  return unit_test::list_tests(tests);
}

bool ostream_unit_test::parse_arguments(const vector<ustring>& args) {
  for (auto arg : args)
    if (arg == "--help" || arg == "--gtest_help") {
      write_help();
      return true;
    }
  return unit_test::parse_arguments(args);
}

void ostream_unit_test::write_help() {
  os_ << "This program contains tests written using xtd::tunit. You can use the" << endl;
  os_ << "following command line flags to control its behavior:" << endl;
  os_ << endl;
  os_ << "Test selection:" << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --list_tests" << endl;
  console::reset_color();
  os_ << "      List the names of all tests instead of running them." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --filter_tests=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "POSITIVE_PATTERN[-NEGATIVE_PATERN]" << endl;
  console::reset_color();
  os_ << "      Run only the tests whose name matches one of the positive patterns but" << endl;
  os_ << "      none of the negative patterns. '?' matches any single character; '*'" << endl;
  os_ << "      matches any substring; ':' separates two patterns." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --also_run_ignored_tests" << endl;
  console::reset_color();
  os_ << "      Run all ignored tests too." << endl;
  os_ << endl;
  os_ << "Test execution:" << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --repeat_tests=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "[COUNT]" << endl;
  console::reset_color();
  os_ << "      Run the tests repeatedly; use a negative count to repeat forever." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --shuffle_tests" << endl;
  console::reset_color();
  os_ << "      Randomize tests' orders on every iteration." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --random_seed=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "[NUMBER]" << endl;
  console::reset_color();
  os_ << "      Random number seed to use for shuffling test order. (any number" << endl;
  os_ << "      or 0 to use a seed based on the current time)." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --enable_stack_trace=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << endl;
  console::reset_color();
  os_ << "      Enable/disable stack trace (disable by default to speed up execution)." << endl;
  os_ << endl;
  os_ << "Test output:" << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --output_color=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << endl;
  console::reset_color();
  os_ << "      Enable/disable colored output." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --brief=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << endl;
  console::reset_color();
  os_ << "      Enable/disable printing of test failures only." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --show_duration=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << endl;
  console::reset_color();
  os_ << "      Enable/disable the elapsed time of each test display." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --output=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(json|xml)[:PATH]" << endl;
  console::reset_color();
  os_ << "      Generate a JSON or XML report in the given directory or with the given" << endl;
  os_ << "      file name. PATH defaults to tests.xml." << endl;
  os_ << endl;
  os_ << "Assertion Behavior:" << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --break_on_failure" << endl;
  console::reset_color();
  os_ << "      Turn assertion failures into debugger break-points." << endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --throw_on_failure" << endl;
  console::reset_color();
  os_ << "      Turn assertion failures into C++ exceptions for use by an external test framework." << endl;
  os_ << endl;
}
