/// @file
/// @brief Contains xtd::ostream_unit_test class.
#pragma once
#include "unit_test.hpp"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace tunit {
    /// @brief The ostream_unit_test class.
    class ostream_unit_test : public unit_test {
    public:
      ostream_unit_test(std::ostream& os) noexcept : os_(os) {}
            
      void on_class_end(const xtd::tunit::class_event_args& e) const override {
        this->unit_test::on_unit_test_end(e);
        this->os_ << "  End " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name() << " (" << e.test_class().elapsed_time().count() << " ms total) " << std::endl;
      }
      
      void on_class_start(const xtd::tunit::class_event_args& e) const override {
        this->os_ << "  Start " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name() << std::endl;
        this->unit_test::on_unit_test_start(e);
      }
      
      void on_test_failed(const xtd::tunit::test_event_args& e) const override {
        this->unit_test::on_test_failed(e);
        if (e.test().user_message() != "")
          this->os_ << e.test().user_message() << std::endl;
        this->os_ << e.test().message() << std::endl;
        if (e.test().line_info() != xtd::tunit::line_info::empty()) {
          this->os_ << "error: " << e.test().line_info().file_path();
          if (e.test().line_info().line_number() != 0) this->os_ << ":" << e.test().line_info().line_number();
          this->os_ << std::endl;
        }
        this->os_ << "    FAILED " << e.test().name()<< " (" << e.test().elapsed_time().count() << " ms total)" << std::endl;
      }
      
      void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
        this->unit_test::on_test_succeed(e);
        this->os_ << "    PASSED " << e.test().name()<< " (" << e.test().elapsed_time().count() << " ms total)" << std::endl;
      }

      void on_unit_test_end(const xtd::event_args& e) const override {
        this->unit_test::on_unit_test_end(e);
        this->os_ << std::endl;
        this->os_ << "  Summary :" << std::endl;
        this->os_ << "   PASSED " << this->passed_test_count() << " tests." << std::endl;
        if (this->failed_test_count()) {
          this->os_ << "   FAILED " << this->failed_test_count() << " tests." << std::endl;
        }
        this->os_ << "End " << this->test_count() << " test" << (this->test_count() < 2 ? "" : "s") << " from " << this->test_cases_count() << " test case" << (this->test_cases_count() < 2 ? "" : "s") << " ran. (" << this->elapsed_time().count() << " ms total)" << std::endl;
      }
      
      void on_unit_test_start(const xtd::event_args& e) const override {
        this->os_ << "Start " << this->test_count() << " test" << (this->test_count() < 2 ? "" : "s") << " from " << this->test_cases_count() << " test case" << (this->test_cases_count() < 2 ? "" : "s") << std::endl;
        this->unit_test::on_unit_test_start(e);
      }
      
    private:
      std::ostream& os_;
    };
  }
}
