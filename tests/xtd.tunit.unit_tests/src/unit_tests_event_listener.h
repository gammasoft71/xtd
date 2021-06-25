/// @file
/// @brief Contains xtd::tunit::unit_tests_event_listener class.
#pragma once
#include <xtd/tunit/event_listener.h>
#include <xtd/tunit/unit_test.h>
#include <ostream>

namespace assert_unit_tests {
  class unit_tests_event_listener : public xtd::tunit::event_listener {
  public:
    unit_tests_event_listener(std::ostream& os) noexcept : os_(os) {}
    
    void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
      event_listener::on_test_aborted(e);
      os_ << "  ABORTED " << e.test_class().name() << "." << e.test().name() << std::endl;
      if (e.test().message() != "")
        os_ << "    " << e.test().message() << std::endl;
    }
    
    void on_test_failed(const xtd::tunit::test_event_args& e) const override {
      event_listener::on_test_failed(e);
      os_ << "  FAILED  " << e.test_class().name() << "." << e.test().name() << std::endl;
      if (e.test().expect() != "")
        os_ << "    Expected: " << e.test().expect() << std::endl;
      if (e.test().actual() != "")
        os_ << "    But was:  " << e.test().actual() << std::endl;
      if (e.test().message() != "")
        os_ << "    " << e.test().message() << std::endl;
    }
    
    void on_test_ignored(const xtd::tunit::test_event_args& e) const override {
      event_listener::on_test_ignored(e);
      os_ << "  IGNORED " << e.test_class().name() << "." << e.test().name() << std::endl;
      if (e.test().message() != "")
        os_ << "    " << e.test().message() << std::endl;
    }

    void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
      event_listener::on_test_succeed(e);
      os_ << "  SUCCEED " << e.test_class().name() << "." << e.test().name() << std::endl;
    }
    
    void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
      event_listener::on_unit_test_end(e);
      os_ << "End " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << " ran." << std::endl;
    }
    
    void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
      event_listener::on_unit_test_start(e);
      os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << std::endl;
    }
    
  private:
    std::ostream& os_;
  };
}
