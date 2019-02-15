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
  
  for (auto test_method : this->tests_)
    test_method.run(unit_test, *this);
  unit_test.on_class_end(xtd::tunit::class_event_args(*this));
  
  unit_test.on_class_cleanup_start(xtd::tunit::class_event_args(*this));
  this->class_cleanup().method()();
  unit_test.on_class_cleanup_end(xtd::tunit::class_event_args(*this));
  this->end_time_point = std::chrono::high_resolution_clock::now();
}
