/// @file
/// @brief Contains xtd::tunit::test_class class.
#include "../include/xtd/test_class.hpp"
#include "../include/xtd/unit_test.hpp"

using namespace xtd::tunit;

void test_class::run(const unit_test& unit_test) {
  this->start_time_point = std::chrono::high_resolution_clock::now();
  unit_test.on_class_initialize_start(xtd::tunit::class_event_args(*this));
  this->class_initialize().method()();
  unit_test.on_class_initialize_end(xtd::tunit::class_event_args(*this));
  
  unit_test.on_class_start(xtd::tunit::class_event_args(*this));
  
  for (auto test_method : this->tests_) {
    if (!test_method.ignore_ || unit_test.also_run_ignored_tests()) {
      unit_test.on_test_initialize_start(xtd::event_args::empty());
      this->test_initialize().method()();
      unit_test.on_test_initialize_end(xtd::event_args::empty());
      
      unit_test.on_test_start(xtd::event_args::empty());
      try {
        test_method.method()();
        unit_test.on_test_succeed(xtd::event_args::empty());
      } catch(...) {
        unit_test.on_test_failed(xtd::event_args::empty());
      }
      
      unit_test.on_test_cleanup_start(xtd::event_args::empty());
      this->test_cleanup().method()();
      unit_test.on_test_cleanup_end(xtd::event_args::empty());
      
      unit_test.on_test_end(xtd::event_args::empty());
    }
  }
  unit_test.on_class_end(xtd::tunit::class_event_args(*this));
  
  unit_test.on_class_cleanup_start(xtd::tunit::class_event_args(*this));
  this->class_cleanup().method()();
  unit_test.on_class_cleanup_end(xtd::tunit::class_event_args(*this));
}
