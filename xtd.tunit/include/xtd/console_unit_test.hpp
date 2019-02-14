/// @file
/// @brief Contains xtd::console_unit_test class.
#pragma once
#include "unit_test.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace tunit {
    /// @brief The console_unit_test class.
    class console_unit_test : public unit_test {
    public:
      console_unit_test() = default;
      
      console_unit_test(char* argv[], int argc) : unit_test(argv, argc) {}
      
      void on_class_end(const xtd::tunit::class_event_args& e) const override {
        this->unit_test::on_unit_test_end(e);
        std::cout << "  End " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name() << " (" << std::chrono::duration_cast<std::chrono::milliseconds>(e.test_class().elapsed_time()).count() << " ms total) " << std::endl;
      }
      
      void on_class_start(const xtd::tunit::class_event_args& e) const override {
        std::cout << "  Start " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name() << std::endl;
        this->unit_test::on_unit_test_start(e);
      }
      
      void on_unit_test_end(const xtd::event_args& e) const override {
        this->unit_test::on_unit_test_end(e);
        std::cout << "End " << this->test_count() << " test" << (this->test_count() < 2 ? "" : "s") << " from " << this->test_cases_count() << " test case" << (this->test_cases_count() < 2 ? "" : "s") << " ran. (" << std::chrono::duration_cast<std::chrono::milliseconds>(this->elapsed_time()).count() << " ms total)" << std::endl;
      }
      
      void on_unit_test_start(const xtd::event_args& e) const override {
        std::cout << "Start " << this->test_count() << " test" << (this->test_count() < 2 ? "" : "s") << " from " << this->test_cases_count() << " test case" << (this->test_cases_count() < 2 ? "" : "s") << std::endl;
        this->unit_test::on_unit_test_start(e);
      }
    };
  }
}
