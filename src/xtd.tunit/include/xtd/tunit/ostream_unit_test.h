/// @file
/// @brief Contains xtd::tunit::ostream_event_listener class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "ostream_event_listener"
#include "unit_test"
#include <ostream>
#include <map>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The ostream_unit_test class is ostream unit test interface.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks All messages are written on the specified ostream.
    class tunit_export_ ostream_unit_test : public xtd::tunit::unit_test {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Create a new console unit test with ostream specified.
      /// @param os The ostream to write events.
      explicit ostream_unit_test(std::ostream& os) noexcept;
      
      /// @brief Create a new console unit test with ostream specified, argv specified and argc specified.
      /// @param os The ostream to write events.
      /// @param argc Argument count from main method.
      /// @param argv Arguments array from main method.
      ostream_unit_test(std::ostream& os, int argc, char* argv[]);
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the ostream used by this instance.
      /// @return The ostream used by this instance.
      /// @warning Used it only if you need to write specific user messages. If you change or redirect it when tests running, the unit test output result will be indeterminate.
      std::ostream& ostream();
      /// @}
      
      /// @name Methods
      
      /// @{
      int count_tests(int32 count) override;
      int list_tests(const std::vector<std::string>& tests) override;
      bool parse_arguments(const std::vector<ustring>& args) override;
      
      /// @brief Write usage help on the ostream of this instance.
      void write_help();
      /// @}
      
    private:
      std::ostream& os_;
    };
  }
}

