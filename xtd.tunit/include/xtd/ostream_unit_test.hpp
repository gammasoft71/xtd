/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
#pragma once
#include "ostream_event_listener.hpp"
#include "unit_test.hpp"
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
      
      /// @brief Runs all tests in this UnitTest object and prints the result.
      /// @return EXIT_SUCCESS (0) if succeed; otherwise return EXIT_FAILURE (1).
      int run() override {
        if (xtd::tunit::settings::default_settings().list_tests()) {
          for (auto name : this->list_tests())
            os_ << name << std::endl;
            return xtd::tunit::settings::default_settings().exit_status();
        }
        
        return this->ostream_unit_test::run();
      }
      
    private:
      std::ostream& os_;
    };
  }
}
