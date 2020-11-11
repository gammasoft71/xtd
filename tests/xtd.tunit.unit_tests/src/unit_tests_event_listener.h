/// @file
/// @brief Contains xtd::tunit::unit_tests_event_listener class.
#pragma once
#include <xtd/event_listener.h>
#include <xtd/unit_test.h>
#include <ostream>

namespace assert_unit_tests {
  class unit_tests_event_listener : public xtd::tunit::event_listener {
  public:
    unit_tests_event_listener(std::ostream& os) noexcept : os_(os) {}
    
    void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_aborted(e);
      this->os_ << "  ABORTED " << e.test_class().name() << "." << e.test().name() << std::endl;
      if (e.test().message() != "")
        this->os_ << "    " << e.test().message() << std::endl;
    }
    
    void on_test_failed(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_failed(e);
      this->os_ << "  FAILED  " << e.test_class().name() << "." << e.test().name() << std::endl;
      if (e.test().expect() != "")
        this->os_ << "    Expected: " << e.test().expect() << std::endl;
      if (e.test().actual() != "")
        this->os_ << "    But was:  " << e.test().actual() << std::endl;
      if (e.test().message() != "")
        this->os_ << "    " << e.test().message() << std::endl;
    }
    
    void on_test_ignored(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_ignored(e);
      this->os_ << "  IGNORED " << e.test_class().name() << "." << e.test().name() << std::endl;
      if (e.test().message() != "")
        this->os_ << "    " << e.test().message() << std::endl;
    }

    void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_succeed(e);
      this->os_ << "  SUCCEED " << e.test_class().name() << "." << e.test().name() << std::endl;
    }
    
    void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
      this->event_listener::on_unit_test_end(e);
      this->os_ << "End " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << " ran." << std::endl;
    }
    
    void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
      this->event_listener::on_unit_test_start(e);
      this->os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << std::endl;
    }
    
  private:
    std::ostream& os_;
  };
}
