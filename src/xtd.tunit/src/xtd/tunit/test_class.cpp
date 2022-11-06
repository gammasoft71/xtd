#include "../../../include/xtd/tunit/test_class.h"
#include "../../../include/xtd/tunit/unit_test.h"

using namespace xtd::tunit;

void test_class::run(const unit_test& unit_test) {
  if (xtd::tunit::settings::default_settings().shuffle_test())
    std::shuffle(tests_.begin(), tests_.end(), xtd::tunit::settings::default_settings().random_seed() ? xtd::random(xtd::tunit::settings::default_settings().random_seed()).generator() : xtd::random().generator());
  
  unit_test.event_listener_->on_class_initialize_start(xtd::tunit::class_event_args(*this, unit_test));
  if (class_initialize().method() != nullptr)
    class_initialize().method()();
  unit_test.event_listener_->on_class_initialize_end(xtd::tunit::class_event_args(*this, unit_test));
  
  unit_test.event_listener_->on_class_start(xtd::tunit::class_event_args(*this, unit_test));
  
  start_time_ = date_time::now();
  for (auto& test_method : tests_)
    test_method.run(unit_test, *this);
  end_time_point = date_time::now();
  unit_test.event_listener_->on_class_end(xtd::tunit::class_event_args(*this, unit_test));
  
  unit_test.event_listener_->on_class_cleanup_start(xtd::tunit::class_event_args(*this, unit_test));
  if (class_cleanup().method() != nullptr)
    class_cleanup().method()();
  unit_test.event_listener_->on_class_cleanup_end(xtd::tunit::class_event_args(*this, unit_test));
}
