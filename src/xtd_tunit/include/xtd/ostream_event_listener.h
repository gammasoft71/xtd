/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
#pragma once
#include "__console_color.h"
#include "event_listener.h"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The ostream_unit_test class is a specialisation of event_listener class for writing events in std::ostream.
    /// @remarks This class is use by console_unit_test.
    /// @remarks you can use this class as you want as for example communicate between network.
    /// @par Examples
    /// The following examples show how to use ostream_event_listener.
    /// @include ostream_unit_test.cpp
    class ostream_event_listener : public xtd::tunit::event_listener {
    public:
      /// @brief Creates new instance ostream event lister with ostream specified.
      /// @param os sotream where evnets are writting.
      ostream_event_listener(std::ostream& os) noexcept : os_(os) {}
      
      /// @brief Occurs when test is aborted.
      /// @param test_event_args Contains test event parameters.
      void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_aborted(e);
        this->os_ << __foreground_color(__console_color::magenta);
        this->os_ << "  ABORTED ";
        this->os_ << __reset_color();
        this->os_ << e.test_class().name() << "." << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
        if (e.test().message() != "")
          this->os_ << "    " << e.test().message() << std::endl;
        if (e.test().expect() != "")
          this->os_ << "    Expected: " << e.test().expect() << std::endl;
        if (e.test().actual() != "")
          this->os_ << "    But was:  " << e.test().actual() << std::endl;
        if ((e.test().expect() != "" || e.test().actual() != "") && e.test().line_info() != xtd::tunit::line_info::empty()) {
          this->os_ << "    Stack Trace: in " << e.test().line_info().file_path();
          if (e.test().line_info().line_number() != 0) this->os_ << ":" << e.test().line_info().line_number();
        }
        this->os_ << std::endl;
     }

      /// @brief Occurs when test is failed.
      /// @param test_event_args Contains test event parameters.
      void on_test_failed(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_failed(e);
        this->os_ << __foreground_color(__console_color::red);
        this->os_ << "  FAILED  ";
        this->os_ << __reset_color();
        this->os_ << e.test_class().name() << "." << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
        if (e.test().message() != "")
          this->os_ << "    " << e.test().message() << std::endl;
        if (e.test().expect() != "")
          this->os_ << "    Expected: " << e.test().expect() << std::endl;
        if (e.test().actual() != "")
          this->os_ << "    But was:  " << e.test().actual() << std::endl;
        if (e.test().line_info() != xtd::tunit::line_info::empty()) {
          this->os_ << "    Stack Trace: in " << e.test().line_info().file_path();
          if (e.test().line_info().line_number() != 0) this->os_ << ":" << e.test().line_info().line_number();
        }
        this->os_ << std::endl;
      }
      
      /// @brief Occurs when test is ignored.
      /// @param test_event_args Contains test event parameters.
      void on_test_ignored(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_ignored(e);
        this->os_ << __foreground_color(__console_color::yellow);
        this->os_ << "  IGNORED ";
        this->os_ << __reset_color();
        this->os_ << e.test_class().name() << "." << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
        if (e.test().message() != "")
          this->os_ << "    " << e.test().message() << std::endl;
      }

      /// @brief Occurs when test is succeed.
      /// @param test_event_args Contains test event parameters.
      void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_succeed(e);
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  SUCCEED ";
        this->os_ << __reset_color();
        this->os_ << e.test_class().name() << "." << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
        if (e.test().message() != "")
          this->os_ << "    " << e.test().message() << std::endl;
      }
      
      /// @brief Occurs when unit test is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
        this->event_listener::on_unit_test_end(e);
        this->os_ << std::endl;
        this->os_ << "Test results:" << std::endl;
        if (e.unit_test().succeed_test_count()) {
          this->os_ << __foreground_color(__console_color::green);
          this->os_ << "  SUCCEED ";
          this->os_ << __reset_color();
          this->os_ << e.unit_test().succeed_test_count() << " test" << (e.unit_test().succeed_test_count() < 2 ? "" : "s") << "." << std::endl;
        }
        if (e.unit_test().aborted_test_count()) {
          this->os_ << __foreground_color(__console_color::magenta);
          this->os_ << "  ABORTED ";
          this->os_ << __reset_color();
          this->os_ << e.unit_test().aborted_test_count() << " test" << (e.unit_test().aborted_test_count() < 2 ? "" : "s") << "." << std::endl;
        }
        if (e.unit_test().failed_test_count()) {
          this->os_ << __foreground_color(__console_color::red);
          this->os_ << "  FAILED  ";
          this->os_ << __reset_color();
          this->os_ << e.unit_test().failed_test_count() << " test" << (e.unit_test().failed_test_count() < 2 ? "" : "s") << "." << std::endl;
        }
        if (e.unit_test().ignored_test_count()) {
          this->os_ << __foreground_color(__console_color::yellow);
          this->os_ << "  IGNORED ";
          this->os_ << __reset_color();
          this->os_ << e.unit_test().ignored_test_count() << " test" << (e.unit_test().ignored_test_count() < 2 ? "" : "s") << "." << std::endl;
        }
        
        this->os_ << "End " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << " ran.";
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.unit_test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl << std::endl;
      }
      
      /// @brief Occurs when unit test cleanup is started.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
        if (e.unit_test().repeat_tests()) {
          this->os_ << __foreground_color(__console_color::cyan);
          this->os_ << "Repeating all tests (iteration " << e.unit_test().repeat_iteration() << ") . . ." << std::endl << std::endl;
          this->os_ << __reset_color();
        }
        this->os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << std::endl;
        this->os_ << "Run tests:" << std::endl;
        this->event_listener::on_unit_test_start(e);
      }
      
    private:
      std::ostream& os_;
    };
  }
}
