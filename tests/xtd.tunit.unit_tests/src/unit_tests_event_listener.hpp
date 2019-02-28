/// @file
/// @brief Contains xtd::tunit::unit_tests_event_listener class.
#pragma once
#include <xtd/event_listener.hpp>
#include <xtd/unit_test.hpp>
#include <ostream>

namespace assert_unit_tests {
  class unit_tests_event_listener : public xtd::tunit::event_listener {
  public:
    unit_tests_event_listener(std::ostream& os) noexcept : os_(os) {}
    
    void on_class_end(const xtd::tunit::class_event_args& e) const override {
      this->event_listener::on_class_end(e);
      this->os_ << "  End " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name();
      if (xtd::tunit::settings::default_settings().show_duration())
        this->os_<< " (" << e.test_class().elapsed_time().count() << " ms total)";
      this->os_ << std::endl;
    }
    
    void on_class_start(const xtd::tunit::class_event_args& e) const override {
      this->os_ << "  Start " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name() << std::endl;
      this->event_listener::on_class_start(e);
    }
    
    void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_aborted(e);
      this->os_ << "    ABORTED ";
      this->os_ << e.test().name();
      if (xtd::tunit::settings::default_settings().show_duration())
        this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
      this->os_ << std::endl;
    }
    
    void on_test_failed(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_failed(e);
      this->os_ << "    FAILED  ";
      this->os_ << e.test().name();
      if (xtd::tunit::settings::default_settings().show_duration())
        this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
      this->os_ << std::endl;
      this->os_ << std::endl;
      if (e.test().expect() != "")
        this->os_ << "Expected: " << e.test().expect() << std::endl;
      if (e.test().actual() != "")
        this->os_ << "But was:  " << e.test().actual() << std::endl;
      if (e.test().line_info() != xtd::tunit::line_info::empty()) {
        this->os_ << "error: " << e.test().line_info().file_path();
        if (e.test().line_info().line_number() != 0) this->os_ << ":" << e.test().line_info().line_number();
        this->os_ << std::endl;
      }
      if (e.test().user_message() != "")
        this->os_ << e.test().user_message() << std::endl;
      this->os_ << std::endl;
    }
    
    void on_test_ignored(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_ignored(e);
      this->os_ << "    IGNORED ";
      this->os_ << e.test().name();
      if (xtd::tunit::settings::default_settings().show_duration())
        this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
      this->os_ << std::endl;
    }
    
    void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
      this->event_listener::on_test_succeed(e);
      this->os_ << "    SUCCEED ";
      this->os_ << e.test().name();
      if (xtd::tunit::settings::default_settings().show_duration())
        this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
      this->os_ << std::endl;
    }
    
    void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
      this->event_listener::on_unit_test_end(e);
      this->os_ << "End " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << " ran.";
      if (xtd::tunit::settings::default_settings().show_duration())
        this->os_ << " (" << e.unit_test().elapsed_time().count() << " ms total)";
      this->os_ << std::endl << std::endl;
    }
    
    void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
      this->os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << std::endl;
      this->event_listener::on_unit_test_start(e);
    }
    
  private:
    std::ostream& os_;
  };
}

