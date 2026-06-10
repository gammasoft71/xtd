#include "../../../include/xtd/tunit/settings.hpp"

using namespace xtd;
using namespace xtd::tunit;

namespace {
  auto pattern_compare(const string& name, const string& pattern) noexcept -> bool {
    if (pattern == "") return name == "";
    if (name == "") return false;
    if (pattern == "*" || pattern == "*.*") return true;
    if (pattern[0] == '*') return pattern_compare(name, pattern.chars().substr(1)) || pattern_compare(name.chars().substr(1), pattern);
    return ((pattern[0] == '?') || (name[0] == pattern[0])) && pattern_compare(name.chars().substr(1), pattern.chars().substr(1));
  }
}

auto settings::also_run_ignored_tests() const noexcept -> bool {
  return also_run_ignored_tests_;
}

auto settings::also_run_ignored_tests(bool also_run_ignored_tests) noexcept -> settings& {
  also_run_ignored_tests_ = also_run_ignored_tests;
  return *this;
}

auto settings::break_on_failure() const noexcept -> bool {
  return break_on_failure_;
}

auto settings::break_on_failure(bool break_on_failure) noexcept -> settings& {
  break_on_failure_ = break_on_failure;
  return *this;
}

auto settings::brief() const noexcept -> bool {
  return brief_;
}

auto settings::brief(bool brief) noexcept -> settings& {
  brief_ = brief;
  return *this;
}

auto settings::count_tests() const noexcept -> bool {
  return count_tests_;
}

auto settings::count_tests(bool count_tests) noexcept -> settings& {
  count_tests_ = count_tests;
  return *this;
}

auto settings::exit_status() const noexcept -> int32 {
  return exit_status_;
}

auto settings::exit_status(int32 exit_status) noexcept -> settings& {
  exit_status_ = exit_status;
  return *this;
}

auto settings::filter_tests() const noexcept -> const array<string>& {
  return filter_tests_;
}

auto settings::filter_tests(const array<string>& filter_tests) noexcept -> settings& {
  filter_tests_ = filter_tests.empty() ? array<string> {"*.*"} : filter_tests;
  return *this;
}

auto settings::gtest_compatibility() const noexcept -> bool {
  return gtest_compatibility_;
}

auto settings::gtest_compatibility(bool gtest_compatibility) noexcept -> settings& {
  gtest_compatibility_ = gtest_compatibility;
  return *this;
}

auto settings::is_match_test_name(const string& test_class_name, const string& test_name) const noexcept -> bool {
  auto result = false;
  for (const auto& filter_test : filter_tests())
    if (!filter_test.starts_with('-'))
      result |= pattern_compare(test_class_name + "." + test_name, filter_test);
      
  for (const auto& filter_test : filter_tests())
    if (filter_test.starts_with('-'))
      result &= !pattern_compare(test_class_name + "." + test_name, filter_test.substring(1));
      
  return result;
}

auto settings::list_tests() const noexcept -> bool {
  return list_tests_;
}

auto settings::list_tests(bool list_tests) noexcept -> settings& {
  list_tests_ = list_tests;
  return *this;
}

auto settings::output_color() const noexcept -> bool {
  return output_color_;
}

auto settings::output_color(bool output_color) noexcept -> settings& {
  output_color_ = output_color;
  return *this;
}

auto settings::output_json() const noexcept -> bool {
  return output_json_;
}

auto settings::output_json(bool output_json) noexcept -> settings& {
  output_json_ = output_json;
  return *this;
}

auto settings::output_xml() const noexcept -> bool {
  return output_xml_;
}

auto settings::output_xml(bool output_xml) noexcept -> settings& {
  output_xml_ = output_xml;
  return *this;
}

auto settings::output_json_path() const noexcept -> string {
  return output_json_path_.value_or(gtest_compatibility() ? "test_detail.json" : "tests.json");
}

auto settings::output_json_path(const string& output_json_path) noexcept -> settings& {
  output_json_path_ = output_json_path;
  return *this;
}

auto settings::output_xml_path() const noexcept -> string {
  return output_xml_path_.value_or(gtest_compatibility() ? "test_detail.xml" : "tests.xml");
}

auto settings::output_xml_path(const string& output_xml_path) noexcept -> settings& {
  output_xml_path_ = output_xml_path;
  return *this;
}

auto settings::shuffle_test() const noexcept -> bool {
  return shuffle_tests_;
}

auto settings::shuffle_test(bool shuffle_test) noexcept -> settings& {
  shuffle_tests_ = shuffle_test;
  return *this;
}

auto settings::random_seed() const noexcept -> uint32 {
  return random_seed_;
}

auto settings::random_seed(uint32 random_seed) noexcept -> settings& {
  random_seed_ = random_seed;
  return *this;
}

auto settings::repeat_test() const noexcept -> int32 {
  return repeat_tests_;
}

auto settings::repeat_tests(int32 repeat_tests) noexcept -> settings& {
  repeat_tests_ = repeat_tests;
  return *this;
}

auto settings::show_duration() const noexcept -> bool {
  return show_duration_;
}

auto settings::show_duration(bool show_duration) noexcept -> settings& {
  show_duration_ = show_duration;
  return *this;
}

auto settings::end_time() const noexcept -> const date_time& {
  return end_time_;
}

auto settings::start_time() const noexcept -> const date_time& {
  return start_time_;
}

auto settings::enable_stack_trace() const noexcept -> bool {
  return enable_stack_trace_;
}

auto settings::enable_stack_trace(bool enable_stack_trace) noexcept -> settings& {
  enable_stack_trace_ = enable_stack_trace;
  return *this;
}

auto settings::throw_on_failure() const noexcept -> bool {
  return throw_on_failure_;
}

auto settings::throw_on_failure(bool throw_on_failure) noexcept -> settings& {
  throw_on_failure_ = throw_on_failure;
  return *this;
}

auto settings::default_settings() noexcept -> settings& {
  static auto settings = tunit::settings {};
  return settings;
}

auto settings::end_time(const date_time& end_time) noexcept -> settings& {
  start_time_ = end_time;
  return *this;
}

auto settings::start_time(const date_time& start_time) noexcept -> settings& {
  start_time_ = start_time;
  return *this;
}
