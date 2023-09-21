#include "../../../include/xtd/tunit/ostream_unit_test"
#include "../../../include/xtd/tunit/unit_test"
#include <xtd/console>

using namespace xtd;
using namespace xtd::tunit;

ostream_unit_test::ostream_unit_test(std::ostream& os) noexcept : xtd::tunit::unit_test(std::make_unique<xtd::tunit::ostream_event_listener>(os)), os_(os) {
}

ostream_unit_test::ostream_unit_test(std::ostream& os, int argc, char* argv[]) : xtd::tunit::unit_test(std::make_unique<xtd::tunit::ostream_event_listener>(os), argc, argv), os_(os) {
}

std::ostream& ostream_unit_test::ostream() {
  return os_;
}

int ostream_unit_test::count_tests(int32 count) {
  os_ << count << std::endl;
  return unit_test::count_tests(count);
}

int ostream_unit_test::list_tests(const std::vector<std::string>& tests) {
  if (!settings::default_settings().gtest_compatibility()) {
    for (auto name : tests)
      os_ << name << std::endl;
  } else {
    os_ << "Running main() from " << settings::default_settings().file_name_ << std::endl;
    std::map<std::string, std::vector<std::string>> lists;
    for (auto name : tests) {
      auto key_value =  ustring(name).split({'.'});
      if (key_value.size() == 2) {
        if (lists.find(key_value[0]) == lists.end()) lists.insert({key_value[0], {}});
        lists.at(key_value[0]).push_back(key_value[1]);
      }
    }
    for (auto key_value : lists) {
      os_ << key_value.first << "." << std::endl;
      for (auto value : key_value.second)
        os_ << "  " << value << std::endl;
    }
  }
  return unit_test::list_tests(tests);
}

bool ostream_unit_test::parse_arguments(const std::vector<ustring>& args) {
  for (auto arg : args)
    if (arg == "--help" || arg == "--gtest_help") {
      write_help();
      return true;
    }
  return unit_test::parse_arguments(args);
}

void ostream_unit_test::write_help() {
  os_ << "This program contains tests written using xtd::tunit. You can use the" << std::endl;
  os_ << "following command line flags to control its behavior:" << std::endl;
  os_ << std::endl;
  os_ << "Test selection:" << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --list_tests" << std::endl;
  console::reset_color();
  os_ << "      List the names of all tests instead of running them." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --filter_tests=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "POSITIVE_PATTERN[–NEGATIVE_PATERN]" << std::endl;
  console::reset_color();
  os_ << "      Run only the tests whose name matches one of the positive patterns but" << std::endl;
  os_ << "      none of the negative patterns. '?' matches any single character; '*'" << std::endl;
  os_ << "      matches any substring; ':' separates two patterns." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --also_run_ignored_tests" << std::endl;
  console::reset_color();
  os_ << "      Run all ignored tests too." << std::endl;
  os_ << std::endl;
  os_ << "Test execution:" << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --repeat_tests=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "[COUNT]" << std::endl;
  console::reset_color();
  os_ << "      Run the tests repeatedly; use a negative count to repeat forever." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --shuffle_tests" << std::endl;
  console::reset_color();
  os_ << "      Randomize tests' orders on every iteration." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --random_seed=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "[NUMBER]" << std::endl;
  console::reset_color();
  os_ << "      Random number seed to use for shuffling test order. (any number" << std::endl;
  os_ << "      or 0 to use a seed based on the current time)." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --enable_stack_trace=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << std::endl;
  console::reset_color();
  os_ << "      Enable/disable stack trace (disable by default to speed up execution)." << std::endl;
  os_ << std::endl;
  os_ << "Test output:" << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --output_color=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << std::endl;
  console::reset_color();
  os_ << "      Enable/disable colored output." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --brief=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << std::endl;
  console::reset_color();
  os_ << "      Enable/disable printing of test failures only." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --show_duration=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(true|false)" << std::endl;
  console::reset_color();
  os_ << "      Enable/disable the elapsed time of each test display." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --output=";
  console::reset_color();
  console::foreground_color(console_color::dark_yellow);
  os_ << "(json|xml)[:PATH]" << std::endl;
  console::reset_color();
  os_ << "      Generate a JSON or XML report in the given directory or with the given" << std::endl;
  os_ << "      file name. PATH defaults to tests.xml." << std::endl;
  os_ << std::endl;
  os_ << "Assertion Behavior:" << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --break_on_failure" << std::endl;
  console::reset_color();
  os_ << "      Turn assertion failures into debugger break-points." << std::endl;
  console::foreground_color(console_color::dark_green);
  os_ << "  --throw_on_failure" << std::endl;
  console::reset_color();
  os_ << "      Turn assertion failures into C++ exceptions for use by an external test framework." << std::endl;
  os_ << std::endl;
}
