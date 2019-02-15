/// @file
/// @brief Contains xtd::tunit::test_class class.
#include "../include/xtd/test.hpp"
#include "../include/xtd/unit_test.hpp"

using namespace xtd::tunit;

int test::run(const unit_test& unit_test, const xtd::tunit::test_class& test_class) {
  int result = EXIT_SUCCESS;
  this->start_time_point = std::chrono::high_resolution_clock::now();
  
  if (!this->ignore_ || settings::default_settings().also_run_ignored_tests()) {
    unit_test.on_test_initialize_start(xtd::event_args::empty());
    test_class.test_initialize().method()();
    unit_test.on_test_initialize_end(xtd::event_args::empty());
    
    unit_test.on_test_start(xtd::event_args::empty());
    try {
      this->method()();
      unit_test.on_test_succeed(xtd::event_args::empty());
    } catch(...) {
      unit_test.on_test_failed(xtd::event_args::empty());
    }
    
    unit_test.on_test_cleanup_start(xtd::event_args::empty());
    test_class.test_cleanup().method()();
    unit_test.on_test_cleanup_end(xtd::event_args::empty());
    
    unit_test.on_test_end(xtd::event_args::empty());
  }
  
  this->end_time_point = std::chrono::high_resolution_clock::now();
  return result;
}

