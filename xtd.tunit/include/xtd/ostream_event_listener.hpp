/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
#pragma once
#include "event_listener.hpp"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access console.
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

      /// @brief Occurs when class is ended.
      /// @param class_event_args Contains class event parameters.
      void on_class_end(const xtd::tunit::class_event_args& e) const override {
        this->event_listener::on_class_end(e);
        this->os_ << "  End " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_<< " (" << e.test_class().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
      }
      
      /// @brief Occurs when class is started.
      /// @param class_event_args Contains class_event parameters.
      void on_class_start(const xtd::tunit::class_event_args& e) const override {
        this->os_ << "  Start " << e.test_class().test_count() << " test" << (e.test_class().test_count() < 2 ? "" : "s") << " from " << e.test_class().name() << std::endl;
        this->event_listener::on_class_start(e);
      }
      
      /// @brief Occurs when test is aborted.
      /// @param test_event_args Contains test event parameters.
      void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_aborted(e);
        //__console_foreground_color(__console_color::yellow);
        this->os_ << "    ABORTED ";
        //__console_reset_color();
        this->os_ << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
      }

      /// @brief Occurs when test is failed.
      /// @param test_event_args Contains test event parameters.
      void on_test_failed(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_failed(e);
        //__console_foreground_color(__console_color::red);
        this->os_ << "    FAILED  ";
        //__console_reset_color();
        this->os_ << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
        this->os_ << std::endl;
        this->os_ << e.test().message() << std::endl;
        if (e.test().line_info() != xtd::tunit::line_info::empty()) {
          this->os_ << "error: " << e.test().line_info().file_path();
          if (e.test().line_info().line_number() != 0) this->os_ << ":" << e.test().line_info().line_number();
          this->os_ << std::endl;
        }
        if (e.test().user_message() != "")
          this->os_ << e.test().user_message() << std::endl;
        this->os_ << std::endl;
      }
      
      /// @brief Occurs when test is ignored.
      /// @param test_event_args Contains test event parameters.
      void on_test_ignored(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_ignored(e);
        //__console_foreground_color(__console_color::magenta);
        this->os_ << "    IGNORED ";
        //__console_reset_color();
        this->os_ << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
      }

      /// @brief Occurs when test is succeed.
      /// @param test_event_args Contains test event parameters.
      void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
        this->event_listener::on_test_succeed(e);
        //__console_foreground_color(__console_color::green);
        this->os_ << "    SUCCEED ";
        //__console_reset_color();
        this->os_ << e.test().name();
        if (xtd::tunit::settings::default_settings().show_duration())
          this->os_ << " (" << e.test().elapsed_time().count() << " ms total)";
        this->os_ << std::endl;
      }
      
      /// @brief Occurs when unit test is ended.
      /// @param tunit_event_args Contains unit test event parameters.
      void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
        this->event_listener::on_unit_test_end(e);
        this->os_ << std::endl;
        this->os_ << "  Summary :" << std::endl;
        
        if (e.unit_test().succeed_test_count()) {
          //__console_foreground_color(__console_color::green);
          this->os_ << "    SUCCEED ";
          //__console_reset_color();
          this->os_ << e.unit_test().succeed_test_count() << " test" << (e.unit_test().succeed_test_count() <2 ? "" : "s") << "." << std::endl;
        }

        if (e.unit_test().aborted_test_count()) {
          //__console_foreground_color(__console_color::yellow);
          this->os_ << "    ABORTED ";
          //__console_reset_color();
          this->os_ << e.unit_test().aborted_test_count() << " test" << (e.unit_test().aborted_test_count() < 2 ? "" : "s") << ", listed below:" << std::endl;
          for(auto name : e.unit_test().aborted_test_names()) {
            //__console_foreground_color(__console_color::yellow);
            this->os_ << "    ABORTED ";
            //__console_reset_color();
            this->os_ << name << std::endl;
          }
        }
        
        if (e.unit_test().failed_test_count()) {
          //__console_foreground_color(__console_color::red);
          this->os_ << "    FAILED  ";
          //__console_reset_color();
          this->os_ << e.unit_test().failed_test_count() << " test" << (e.unit_test().failed_test_count() < 2 ? "" : "s") << ", listed below:" << std::endl;
          for(auto name : e.unit_test().failed_test_names()) {
            //__console_foreground_color(__console_color::red);
            this->os_ << "    FAILED  ";
            //__console_reset_color();
            this->os_ << name << std::endl;
          }
        }
        
        if (e.unit_test().ignored_test_count()) {
          //__console_foreground_color(__console_color::red);
          this->os_ << "    IGNORED ";
          //__console_reset_color();
          this->os_ << e.unit_test().ignored_test_count() << " test" << (e.unit_test().ignored_test_count() < 2 ? "" : "s") << ", listed below:" << std::endl;
          for(auto name : e.unit_test().ignored_test_names()) {
            //__console_foreground_color(__console_color::magenta);
            this->os_ << "    IGNORED ";
            //__console_reset_color();
            this->os_ << name << std::endl;
          }
        }

        if (e.unit_test().aborted_test_count() || e.unit_test().failed_test_count() || e.unit_test().ignored_test_count())
          this->os_ << std::endl;

        if (e.unit_test().aborted_test_count()) {
          //__console_foreground_color(__console_color::yellow);
          this->os_ << "    ABORTED ";
          //__console_reset_color();
          this->os_ << e.unit_test().aborted_test_count() << " test" << (e.unit_test().aborted_test_count() < 2 ? "" : "s") << "." << std::endl;
        }
        if (e.unit_test().failed_test_count()) {
          //__console_foreground_color(__console_color::red);
          this->os_ << "    FAILED  ";
          //__console_reset_color();
          this->os_ << e.unit_test().failed_test_count() << " test" << (e.unit_test().failed_test_count() < 2 ? "" : "s") << "." << std::endl;
        }
        if (e.unit_test().ignored_test_count()) {
          //__console_foreground_color(__console_color::magenta);
          this->os_ << "    IGNORED ";
          //__console_reset_color();
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
        this->os_ << "Start " << e.unit_test().test_count() << " test" << (e.unit_test().test_count() < 2 ? "" : "s") << " from " << e.unit_test().test_cases_count() << " test case" << (e.unit_test().test_cases_count() < 2 ? "" : "s") << std::endl;
        this->event_listener::on_unit_test_start(e);
      }
      
    private:
      std::ostream& os_;
    };
  }
}
