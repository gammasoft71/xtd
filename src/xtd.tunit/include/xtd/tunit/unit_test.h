/// @file
/// @brief Contains xtd::tunit::unit_test class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "../tunit_export.h"
#include "event_listener.h"
#include "registered_test_class.h"
#include "settings.h"
#include <xtd/convert.h>
#include <xtd/date_time.h>
#include <xtd/random.h>
#include <xtd/system_exception.h>
#include <iomanip>
#include <fstream>
#include <memory>
#include <random>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    template <typename test_class_t>
    class test_class_attribute;
    /// @endcond
    
    /// @brief The template class.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ unit_test {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of xtd::tunit::unit_test with specified xtd::tunit::event_listener.
      /// @param event_listener The event listener associate to the unit tests.
      /// @remarks The arguments of the unit test application are detected automatically.
      explicit unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener) noexcept;
      
      /// @brief Initializes a new instance of xtd::tunit::unit_test with specified xtd::tunit::event_listener, argument counts and arguments array.
      /// @param event_listener The event listener associate to the unit tests.
      /// @param argc Argument count from main method.
      /// @param argv Arguments array from main method.
      unit_test(std::unique_ptr<xtd::tunit::event_listener> event_listener, int argc, char* argv[]) noexcept;
      /// @}
      
      /// @cond
      virtual ~unit_test();
      /// @endcond
      
      /// @name Properties
      
      /// @{
      int32 repeat_iteration() const noexcept;
      
      int32 repeat_iteration_count() const noexcept;
      
      bool repeat_tests() const noexcept;
      
      size_t test_cases_count() const noexcept;
      
      size_t test_count() const noexcept;
      
      size_t aborted_test_count() const noexcept;
      
      std::vector<std::string> aborted_test_names() const noexcept;
      
      std::chrono::milliseconds elapsed_time() const noexcept;
      
      size_t ignored_test_count() const noexcept;
      
      std::vector<std::string> ignored_test_names() const noexcept;
      
      size_t failed_test_count() const noexcept;
      
      std::vector<std::string> failed_test_names() const noexcept;
      
      size_t succeed_test_count() const noexcept;
      
      std::vector<std::string> succeed_test_names() const noexcept;
      /// @}
      
      
      /// @name Methods
      
      /// @{
      /// @brief Runs all tests in this unit_test object and prints the result.
      /// @return EXIT_SUCCESS (0) if succeed; otherwise return EXIT_FAILURE (1).
      int32 run();
      /// @}

      
    protected:
      /// @name Protected methods
      
      /// @{
      virtual int32 list_tests(const std::vector<std::string>& tests);
      
      virtual bool parse_arguments(const std::vector<std::string>& args);
      /// @}
      
    private:
      template <typename test_class_t>
      friend class xtd::tunit::test_class_attribute;
      friend class xtd::tunit::test_class;
      friend class xtd::tunit::test;
      friend class xtd::tunit::base_assert;
      
      static void add(const xtd::tunit::registered_test_class& test_class);
      static std::vector<xtd::tunit::registered_test_class>& test_classes();
      std::string get_filename(const std::string& path);
      std::string cdata_message_to_xml_string(const xtd::tunit::test& test);
      std::string escape_path_to_json_string(const std::string& path);
      std::string escape_to_json_string(const std::string& str);
      std::string escape_to_xml_string(const std::string& str);
      std::string message_to_json_string(const xtd::tunit::test& test);
      std::string message_to_xml_string(const xtd::tunit::test& test);
      std::string name_to_string(const std::string& name);
      std::string status_to_string(const xtd::tunit::test& test);
      std::string to_string(const std::chrono::milliseconds& ms);
      std::string to_string(const std::chrono::time_point<std::chrono::system_clock>& time);
      void unit_test_cleanup();
      void unit_test_initialize();
      void write_list_tests_json();
      void write_list_tests_xml();
      void write_tests_json();
      void write_tests_xml();

      std::vector<std::string> arguments;
      std::string name_ = "AllTests";
      std::unique_ptr<xtd::tunit::event_listener> event_listener_;
      xtd::date_time end_time_point_;
      int32 repeat_iteration_ = 0;
      xtd::date_time start_time_point_;
    };
  }
}
