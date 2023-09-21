/// @file
/// @brief Contains xtd::tunit::unit_test class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../tunit_export"
#include "event_listener"
#include "registered_test_class"
#include "settings"
#include <xtd/convert>
#include <xtd/date_time>
#include <xtd/random>
#include <xtd/system_exception>
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
    
    /// @brief The unit_test class is unit test base interface.
    /// @remarks This class can be instantiated or inherited as for example xtd::tunit::ostream_unit_test.
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
      /// @brief Gets the repeat iteration number. A number between 0 and xtd::tunit::unit_test::repeat_iteration_count.
      /// @return The repeat iteration number.
      int32 repeat_iteration() const noexcept;
      
      /// @brief Gets the repeat iteration count.
      /// @return The repeat iteration count.
      /// @remarks Is the xtd::tunit::settings::repeat_test for the current setting.
      int32 repeat_iteration_count() const noexcept;
      
      /// @brief Gets a boolean indictaes if there is repeat tests.
      /// @return true is repart test; otherwhise false.
      /// @remarks Returns true if xtd::tunit::unit_test::repeat_test_count greater than 0.
      bool repeat_tests() const noexcept;
      
      /// @brief Gets the test cases count.
      /// @return The test cases count.
      size_t test_cases_count() const noexcept;
      
      /// @brief Gets the test count.
      /// @return The test count.
      size_t test_count() const noexcept;
      
      /// @brief Gets the aborted test count.
      /// @return The aborted test count.
      size_t aborted_test_count() const noexcept;
      
      /// @brief Gets the array of aborted test names.
      /// @return The array of aborted test names.
      std::vector<std::string> aborted_test_names() const noexcept;
      
      /// @brief Gets the elapsed time for the execution of all tests in the unit test.
      /// @return The elapsed time for the execution of all tests in the unit test.
      std::chrono::milliseconds elapsed_time() const noexcept;
      
      /// @brief Gets the ignored test count.
      /// @return The ignored test count.
      size_t ignored_test_count() const noexcept;
      
      /// @brief Gets the array of ignored test names.
      /// @return The array of ignored test names.
      std::vector<std::string> ignored_test_names() const noexcept;
      
      /// @brief Gets the failed test count.
      /// @return The failed test count.
      size_t failed_test_count() const noexcept;
      
      /// @brief Gets the array of failed test names.
      /// @return The array of failed test names.
      std::vector<std::string> failed_test_names() const noexcept;
      
      /// @brief Gets the succeed test count.
      /// @return The succeed test count.
      size_t succeed_test_count() const noexcept;
      
      /// @brief Gets the array of succeed test names.
      /// @return The array of succeed test names.
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
      /// @brief Counts the test names contained in the specified tests.
      /// @param count The tests count.
      /// @return The xtd::tunit::settings::exit_status value.
      /// @remarks This method does nothing by default. The inheritor must overload this method to act as it wants when the unit_lest is asked for the test list.
      /// @remarks This method is typically used to display the list of tests in a stream, or whatever. It depends on the implementation chosen by the inheritor.
      virtual int32 count_tests(int32 count);
      
      /// @brief Lists the test names contained in the specified tests.
      /// @param tests The list of test names.
      /// @return The xtd::tunit::settings::exit_status value.
      /// @remarks This method does nothing by default. The inheritor must overload this method to act as it wants when the unit_lest is asked for the test list.
      /// @remarks This method is typically used to display the list of tests in a stream, or whatever. It depends on the implementation chosen by the inheritor.
      virtual int32 list_tests(const std::vector<std::string>& tests);
      
      /// @brief Parses the specified arguments.
      /// @param The arguments to parse.
      /// @return true the execution process stops immediately after the analysis of the arguments; otherwise false the execution process continues its execution.
      /// @remarks This method can be overloaded by the heirs. It is typically in this method that the heirs can react to their own arguments. Like for example display a helper when the @p -help argument is passed.
      virtual bool parse_arguments(const std::vector<ustring>& args);
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
      
      std::vector<ustring> arguments;
      std::string name_ = "AllTests";
      std::unique_ptr<xtd::tunit::event_listener> event_listener_;
      xtd::date_time end_time_point_;
      int32 repeat_iteration_ = 0;
      xtd::date_time start_time_point_;
    };
  }
}
