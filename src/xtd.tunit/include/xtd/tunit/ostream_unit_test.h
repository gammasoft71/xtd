/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ostream_event_listener.h"
#include "unit_test.h"
#include <ostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The ostream_unit_test class is ostream unit test interface.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    /// @remarks All messages are writting on the specified ostream.
    class ostream_unit_test : public xtd::tunit::unit_test {
    public:
      /// @brief Create a new console unit test with ostream specified.
      /// @param os The ostream to write events.
      explicit ostream_unit_test(std::ostream& os) noexcept : xtd::tunit::unit_test(std::make_unique<xtd::tunit::ostream_event_listener>(os)), os_(os) {}
      
      /// @brief Create a new console unit test with ostream specified, argv specified and argc specified.
      /// @param os The ostream to write events.
      /// @param argc Argument count from main method.
      /// @param argv Arguments array from main method.
      ostream_unit_test(std::ostream& os, int argc, char* argv[]) : xtd::tunit::unit_test(std::make_unique<xtd::tunit::ostream_event_listener>(os), argc, argv), os_(os) {}
      
      /// @brief Gets the ostream used by this instance.
      /// @return The ostream used by this instance.
      /// @warning Used it only if you need to write specific user messages. If you change or redirect it when tests running, the unit test output result will be indeterminate.
      std::ostream& ostream() {return os_;}

      int list_tests(const std::vector<std::string>& tests) override {
        for (auto name : tests)
          os_ << name << std::endl;
        return unit_test::list_tests(tests);
      }
      
      bool parse_arguments(const std::vector<std::string>& args) override {
        for (auto arg : args)
          if (arg == "--help") {
            write_help();
            return true;
          }
        return unit_test::parse_arguments(args);
      }
      
      void write_help() {
        os_ << "This program contains tests written using xtd::tunit. You can use the" << std::endl;
        os_ << "following command line flags to control its behavior:" << std::endl;
        os_ << std::endl;
        os_ << "Test selection:" << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --list_tests" << std::endl;
        os_ << __reset_color();
        os_ << "      List the names of all tests instead of running them." << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --filter_tests=";
        os_ << __reset_color();
        os_ << __foreground_color(__console_color::yellow);
        os_ << "[PATTERN]" << std::endl;
        os_ << __reset_color();
        os_ << "      Run only the tests whose name matches one of the pattern." << std::endl;
        os_ << "      '?' matches any single character; '*' matches any substring." << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --also_run_ignored_tests" << std::endl;
        os_ << __reset_color();
        os_ << "      Run all ignored tests too." << std::endl;
        os_ << std::endl;
        os_ << "Test execution:" << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --repeat_tests=";
        os_ << __reset_color();
        os_ << __foreground_color(__console_color::yellow);
        os_ << "[COUNT]" << std::endl;
        os_ << __reset_color();
        os_ << "      Run the tests repeatedly; use a negative count to repeat forever." << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --shuffle_tests" << std::endl;
        os_ << __reset_color();
        os_ << "      Randomize tests' orders on every iteration." << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --random_seed=";
        os_ << __reset_color();
        os_ << __foreground_color(__console_color::yellow);
        os_ << "[NUMBER]" << std::endl;
        os_ << __reset_color();
        os_ << "      Random number seed to use for shuffling test order. (any number" << std::endl;
        os_ << "      or 0 to use a seed based on the current time)." << std::endl;
        os_ << std::endl;
        os_ << "Test output:" << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --output_color=";
        os_ << __reset_color();
        os_ << __foreground_color(__console_color::yellow);
        os_ << "(true|false)" << std::endl;
        os_ << __reset_color();
        os_ << "      Enable/disable colored output." << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --show_duration=";
        os_ << __reset_color();
        os_ << __foreground_color(__console_color::yellow);
        os_ << "(true|false)" << std::endl;
        os_ << __reset_color();
        os_ << "      Enable/disable the elapsed time of each test display." << std::endl;
        os_ << __foreground_color(__console_color::green);
        os_ << "  --output_xml=xml";
        os_ << __reset_color();
        os_ << __foreground_color(__console_color::yellow);
        os_ << "[=PATH]" << std::endl;
        os_ << __reset_color();
        os_ << "      Generate an xml report in the given directory or with the given file" << std::endl;
        os_ << "      name. PATH defaults to tests.xml." << std::endl;
        os_ << std::endl;
      }
      
    private:
      std::ostream& os_;
    };
  }
}
