#include "../../../include/xtd/tunit/test_class.h"
#include "../../../include/xtd/tunit/unit_test.h"

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::tunit;

milliseconds test_class::elapsed_time() const noexcept {
  using namespace std::chrono_literals;
  if (start_time_.ticks() == 0 && end_time_point.ticks() == 0) return 0ms;
  if (end_time_point.ticks() == 0) return duration_cast<milliseconds>((date_time::now() - start_time_).ticks_duration());
  return duration_cast<milliseconds>((end_time_point - start_time_).ticks_duration());
}

ustring test_class::name() const noexcept {
  return name_;
}

size_t test_class::test_count() const noexcept {
  auto count = 0_sz;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name())) count++;
  return count;
}

size_t test_class::aborted_test_count() const noexcept {
  auto count = 0_sz;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.aborted()) count++;
  return count;
}

size_t test_class::failed_test_count() const noexcept {
  auto count = 0_sz;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.failed()) count++;
  return count;
}

size_t test_class::ignored_test_count() const noexcept {
  auto count = 0_sz;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.ignored()) count++;
  return count;
}

size_t test_class::succeed_test_count() const noexcept {
  auto count = 0_sz;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.succeed()) count++;
  return count;
}

const date_time& test_class::start_time() const noexcept {
  return start_time_;
}

const vector<test>& test_class::tests() const noexcept {
  return tests_;
}

void test_class::add_class_cleanup(const test& class_cleanup) noexcept {
  class_cleanup_ = class_cleanup;
}

void test_class::add_class_initialize(const test& class_initialize) noexcept {
  class_initialize_ = class_initialize;
}

void test_class::add_test_cleanup(const test& test_cleanup) noexcept {
  test_cleanup_ = test_cleanup;
}

void test_class::add_test_initialize(const test& test_initialize) noexcept {
  test_initialize_ = test_initialize;
}

void test_class::add_test_method(const test& test) noexcept {
  tests_.push_back(test);
}

const test& test_class::class_cleanup() const noexcept {
  return class_cleanup_;
}

const test& test_class::class_initialize() const noexcept {
  return class_initialize_;
}

const test& test_class::test_cleanup() const noexcept {
  return test_cleanup_;
}

const test& test_class::test_initialize() const noexcept {
  return test_initialize_;
}

const vector<test>& test_class::test_methods() const noexcept {
  return tests_;
}

void test_class::run(const unit_test& unit_test) {
  if (settings::default_settings().shuffle_test())
    shuffle(tests_.begin(), tests_.end(), settings::default_settings().random_seed() ? random(settings::default_settings().random_seed()).generator() : random().generator());
    
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_initialize_start(class_event_args(*this, unit_test));
  if (class_initialize().method() != nullptr)
    class_initialize().method()();
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_initialize_end(class_event_args(*this, unit_test));
  
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_start(class_event_args(*this, unit_test));
  
  start_time_ = date_time::now();
  for (auto& test_method : tests_)
    test_method.run(unit_test, *this);
  end_time_point = date_time::now();
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_end(class_event_args(*this, unit_test));
  
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_cleanup_start(class_event_args(*this, unit_test));
  if (class_cleanup().method() != nullptr)
    class_cleanup().method()();
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_cleanup_end(class_event_args(*this, unit_test));
}
