#include "../../../include/xtd/tunit/settings.h"

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

settings& settings::default_settings() noexcept {
  static auto settings = tunit::settings {};
  return settings;
}

bool settings::also_run_ignored_tests() const noexcept {
  return also_run_ignored_tests_;
}

void settings::also_run_ignored_tests(bool also_run_ignored_tests) noexcept {
  also_run_ignored_tests_ = also_run_ignored_tests;
}

bool settings::break_on_failure() const noexcept {
  return break_on_failure_;
}

void settings::break_on_failure(bool break_on_failure) noexcept {
  break_on_failure_ = break_on_failure;
}

bool settings::brief() const noexcept {
  return brief_;
}

void settings::brief(bool brief) noexcept {
  brief_ = brief;
}

bool settings::throw_on_failure() const noexcept {
  return throw_on_failure_;
}

void settings::throw_on_failure(bool throw_on_failure) noexcept {
  throw_on_failure_ = throw_on_failure;
}

bool settings::count_tests() const noexcept {
  return count_tests_;
}

void settings::count_tests(bool count_tests) noexcept {
  count_tests_ = count_tests;
}

int32 settings::exit_status() const noexcept {
  return exit_status_;
}

void settings::exit_status(int32 exit_status) noexcept {
  exit_status_ = exit_status;
}

const vector<ustring>& settings::filter_tests() const noexcept {
  return filter_tests_;
}

void settings::filter_tests(const vector<ustring>& filter_tests) noexcept {
  filter_tests_ = !filter_tests.empty() ? filter_tests : vector<ustring> {"*.*"};
}

bool settings::gtest_compatibility() const noexcept {
  return gtest_compatibility_;
}

void settings::gtest_compatibility(bool gtest_compatibility) noexcept {
  gtest_compatibility_ = gtest_compatibility;
}

bool settings::is_match_test_name(const ustring& test_class_name, const ustring& test_name) const noexcept {
  auto result = false;
  auto found_filter_test_count = false;
  for (auto filter_test : filter_tests())
    if (!filter_test.starts_with('-')) {
      result |= pattern_compare(test_class_name + "." + test_name, filter_test);
      found_filter_test_count = true;
    }
  if (!found_filter_test_count) result = true; // same as filter_test {"*.*"}.
  
  for (auto filter_test : filter_tests())
    if (filter_test.starts_with('-'))
      result &= !pattern_compare(test_class_name + "." + test_name, filter_test.substring(1));

  return result;
}

bool settings::list_tests() const noexcept {
  return list_tests_;
}

void settings::list_tests(bool list_tests) noexcept {
  list_tests_ = list_tests;
}

bool settings::output_color() const noexcept {
  return output_color_;
}

void settings::output_color(bool output_color) noexcept {
  output_color_ = output_color;
}

bool settings::output_json() const noexcept {
  return output_json_;
}

void settings::output_json(bool output_json) noexcept {
  output_json_ = output_json;
}

bool settings::output_xml() const noexcept {
  return output_xml_;
}

void settings::output_xml(bool output_xml) noexcept {
  output_xml_ = output_xml;
}

ustring settings::output_json_path() const noexcept {
  return output_json_path_;
}

void settings::output_json_path(const ustring& output_json_path) noexcept {
  output_json_path_ = output_json_path;
}

ustring settings::output_xml_path() const noexcept {
  return output_xml_path_;
}

void settings::output_xml_path(const ustring& output_xml_path) noexcept {
  output_xml_path_ = output_xml_path;
}

bool settings::shuffle_test() const noexcept {
  return shuffle_tests_;
}

void settings::shuffle_test(bool shuffle_test) noexcept {
  shuffle_tests_ = shuffle_test;
}

uint32 settings::random_seed() const noexcept {
  return random_seed_;
}

void settings::random_seed(uint32 random_seed) noexcept {
  random_seed_ = random_seed;
}

int32 settings::repeat_test() const noexcept {
  return repeat_tests_;
}

void settings::repeat_tests(int32 repeat_tests) noexcept {
  repeat_tests_ = repeat_tests;
}

bool settings::show_duration() const noexcept {
  return show_duration_;
}

void settings::show_duration(bool show_duration) noexcept {
  show_duration_ = show_duration;
}

const date_time& settings::end_time() const noexcept {
  return end_time_;
}

const date_time& settings::start_time() const noexcept {
  return start_time_;
}

bool settings::enable_stack_trace() const noexcept {
  return enable_stack_trace_;
}

void settings::enable_stack_trace(bool enable_stack_trace) noexcept {
  enable_stack_trace_ = enable_stack_trace;
}

bool settings::pattern_compare(const ustring& name, const ustring& pattern) const noexcept {
  if (pattern == "") return name == "";
  if (name == "") return false;
  if (pattern == "*" || pattern == "*.*") return true;
  if (pattern[0] == '*') return pattern_compare(name, pattern.substr(1)) || pattern_compare(name.substr(1), pattern);
  return ((pattern[0] == '?') || (name[0] == pattern[0])) && pattern_compare(name.substr(1), pattern.substr(1));
}

void settings::end_time(const date_time& end_time) noexcept {
  start_time_ = end_time;
}

void settings::start_time(const date_time& start_time) noexcept {
  start_time_ = start_time;
}
