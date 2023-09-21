#include "../../../include/xtd/tunit/test_class"
#include "../../../include/xtd/tunit/unit_test"

using namespace xtd::tunit;

std::chrono::milliseconds test_class::elapsed_time() const noexcept {
  using namespace std::chrono_literals;
  if (start_time_.ticks() == 0 && end_time_point.ticks() == 0) return 0ms;
  if (end_time_point.ticks() == 0) return std::chrono::duration_cast<std::chrono::milliseconds>((date_time::now() - start_time_).ticks_duration());
  return std::chrono::duration_cast<std::chrono::milliseconds>((end_time_point - start_time_).ticks_duration());
}

std::string test_class::name() const noexcept {
  return name_;
}

size_t test_class::test_count() const noexcept {
  size_t count = 0;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name())) count++;
  return count;
}

size_t test_class::aborted_test_count() const noexcept {
  size_t count = 0;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.aborted()) count++;
  return count;
}

size_t test_class::failed_test_count() const noexcept {
  size_t count = 0;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.failed()) count++;
  return count;
}

size_t test_class::ignored_test_count() const noexcept {
  size_t count = 0;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.ignored()) count++;
  return count;
}

size_t test_class::succeed_test_count() const noexcept {
  size_t count = 0;
  for (auto method : tests_)
    if (settings::default_settings().is_match_test_name(name(), method.name()) && method.succeed()) count++;
  return count;
}

const xtd::date_time& test_class::start_time() const noexcept {
  return start_time_;
}

const std::vector<xtd::tunit::test>& test_class::tests() const noexcept {
  return tests_;
}

void test_class::add_class_cleanup(const xtd::tunit::test& class_cleanup) noexcept {
  class_cleanup_ = class_cleanup;
}

void test_class::add_class_initialize(const xtd::tunit::test& class_initialize) noexcept {
  class_initialize_ = class_initialize;
}

void test_class::add_test_cleanup(const xtd::tunit::test& test_cleanup) noexcept {
  test_cleanup_ = test_cleanup;
}

void test_class::add_test_initialize(const xtd::tunit::test& test_initialize) noexcept {
  test_initialize_ = test_initialize;
}

void test_class::add_test_method(const xtd::tunit::test& test) noexcept {
  tests_.push_back(test);
}

const xtd::tunit::test& test_class::class_cleanup() const noexcept {
  return class_cleanup_;
}

const xtd::tunit::test& test_class::class_initialize() const noexcept {
  return class_initialize_;
}

const xtd::tunit::test& test_class::test_cleanup() const noexcept {
  return test_cleanup_;
}

const xtd::tunit::test& test_class::test_initialize() const noexcept {
  return test_initialize_;
}

const std::vector<xtd::tunit::test>& test_class::test_methods() const noexcept {
  return tests_;
}

void test_class::run(const unit_test& unit_test) {
  if (xtd::tunit::settings::default_settings().shuffle_test())
    std::shuffle(tests_.begin(), tests_.end(), xtd::tunit::settings::default_settings().random_seed() ? xtd::random(xtd::tunit::settings::default_settings().random_seed()).generator() : xtd::random().generator());
    
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_initialize_start(xtd::tunit::class_event_args(*this, unit_test));
  if (class_initialize().method() != nullptr)
    class_initialize().method()();
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_initialize_end(xtd::tunit::class_event_args(*this, unit_test));
  
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_start(xtd::tunit::class_event_args(*this, unit_test));
  
  start_time_ = date_time::now();
  for (auto& test_method : tests_)
    test_method.run(unit_test, *this);
  end_time_point = date_time::now();
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_end(xtd::tunit::class_event_args(*this, unit_test));
  
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_cleanup_start(xtd::tunit::class_event_args(*this, unit_test));
  if (class_cleanup().method() != nullptr)
    class_cleanup().method()();
  if (!settings::default_settings().brief()) unit_test.event_listener_->on_class_cleanup_end(xtd::tunit::class_event_args(*this, unit_test));
}
