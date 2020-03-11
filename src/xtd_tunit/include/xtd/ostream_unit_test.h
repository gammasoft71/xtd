/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
#pragma once
#include "ostream_event_listener.h"
#include "unit_test.h"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The ostream_unit_test class is ostream unit test interface.
    /// @remarks All messages are writting on the specified ostream.
    class ostream_unit_test : public xtd::tunit::unit_test {
    public:
      /// @brief Create a new console unit test with ostream specified.
      /// @param os The ostream to write events.
      explicit ostream_unit_test(std::ostream& os) noexcept : xtd::tunit::unit_test(std::make_unique<xtd::tunit::ostream_event_listener>(os)), os_(os) {}
      
      /// @brief Create a new console unit test with ostream specified, argv specified and argc specified.
      /// @param os The ostream to write events.
      /// @param argv Arguments array from main method.
      /// @param argc Argument count from main method.
      ostream_unit_test(std::ostream& os, char* argv[], int argc) : xtd::tunit::unit_test(std::make_unique<xtd::tunit::ostream_event_listener>(os), argv, argc), os_(os) {}
      
      int list_tests(const std::vector<std::string>& tests) override {
        for (auto name : tests)
          this->os_ << name << std::endl;
        return this->unit_test::list_tests(tests);
      }
      
      bool parse_arguments(const std::vector<std::string>& args) override {
        for (auto arg : args)
          if (arg == "--help") {
            write_help();
            return true;
          }
        return this->unit_test::parse_arguments(args);
      }
      
      void write_help() {
        this->os_ << "This program contains tests written using xtd::tunit. You can use the" << std::endl;
        this->os_ << "following command line flags to control its behavior:" << std::endl;
        this->os_ << std::endl;
        this->os_ << "Test selection:" << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --list_tests" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      List the names of all tests instead of running them." << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --filter_tests=";
        this->os_ << __reset_color();
        this->os_ << __foreground_color(__console_color::yellow);
        this->os_ << "[PATTERN]" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Run only the tests whose name matches one of the pattern." << std::endl;
        this->os_ << "      '?' matches any single character; '*' matches any substring." << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --also_run_ignored_tests" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Run all ignored tests too." << std::endl;
        this->os_ << std::endl;
        this->os_ << "Test execution:" << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --repeat_tests=";
        this->os_ << __reset_color();
        this->os_ << __foreground_color(__console_color::yellow);
        this->os_ << "[COUNT]" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Run the tests repeatedly; use a negative count to repeat forever." << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --shuffle_tests" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Randomize tests' orders on every iteration." << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --random_seed=";
        this->os_ << __reset_color();
        this->os_ << __foreground_color(__console_color::yellow);
        this->os_ << "[NUMBER]" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Random number seed to use for shuffling test order. (any number" << std::endl;
        this->os_ << "      or 0 to use a seed based on the current time)." << std::endl;
        this->os_ << std::endl;
        this->os_ << "Test output:" << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --output_color=";
        this->os_ << __reset_color();
        this->os_ << __foreground_color(__console_color::yellow);
        this->os_ << "(true|false)" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Enable/disable colored output." << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --show_duration=";
        this->os_ << __reset_color();
        this->os_ << __foreground_color(__console_color::yellow);
        this->os_ << "(true|false)" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Enable/disable the elapsed time of each test display." << std::endl;
        this->os_ << __foreground_color(__console_color::green);
        this->os_ << "  --output_xml=xml";
        this->os_ << __reset_color();
        this->os_ << __foreground_color(__console_color::yellow);
        this->os_ << "[=PATH]" << std::endl;
        this->os_ << __reset_color();
        this->os_ << "      Generate an xml report in the given directory or with the given file" << std::endl;
        this->os_ << "      name. PATH defaults to tests.xml." << std::endl;
        this->os_ << std::endl;
      }
      
    private:
      std::ostream& os_;
    };
  }
}
