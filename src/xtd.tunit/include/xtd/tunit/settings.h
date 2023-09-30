/// @file
/// @brief Contains xtd::tunit::settings class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.h"
#include <xtd/io/path>
#include <xtd/date_time>
#include <xtd/environment>
#include <xtd/ustring>
#include <cstdint>
#include <cstdlib>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The settings class contains xtd.tunit settings.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ settings final {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Creates new instance of settings.
      settings() = default;
      /// @}
      
      /// @cond
      settings(const settings&) = default;
      settings& operator =(const settings&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets default settings instance.
      /// @return Default settings instance.
      static xtd::tunit::settings& default_settings() noexcept;
      
      /// @brief Gets also run ignored test.
      /// @return true if also run ignored test; otherwise false.
      bool also_run_ignored_tests() const noexcept;
      
      /// @brief Sets also run ignored test.
      /// @param also_run_ignored_tests true if also run ignored test; otherwise false.
      void also_run_ignored_tests(bool also_run_ignored_tests) noexcept;
      
      /// @brief Gets break immediatly on failure.
      /// @return true if break immediatly on failure; otherwise false.
      bool break_on_failure() const noexcept;
      
      /// @brief Gets brief.
      /// @return true if brief; otherwise false.
      bool brief() const noexcept;
      
      /// @brief Sets brief.
      /// @param brief true if brief; otherwise false.
      void brief(bool brief) noexcept;
      
      /// @brief Sets break immediatly on failure.
      /// @param break_on_failure true if break immediatly on failure; otherwise false.
      void break_on_failure(bool break_on_failure) noexcept;
      
      /// @brief Gets throw on failure.
      /// @return true if throw on failure; otherwise false.
      bool throw_on_failure() const noexcept;
      
      /// @brief Sets throw on failure.
      /// @param break_on_failure true if throw on failure; otherwise false.
      void throw_on_failure(bool break_on_failure) noexcept;
      
      /// @brief Gets count tests.
      /// @return true if count tests; otherwise false.
      bool count_tests() const noexcept;
      
      /// @brief Sets count tests.
      /// @param count_tests true if count tests; otherwise false.
      void count_tests(bool count_tests) noexcept;
      
      /// @brief Gets exit status.
      /// @return exit status.
      /// @remarks The value by default is EXIT_SUCCESS.
      /// @remarks When an error occurred in unit test the value is set to EXIT_FAILURE.
      int32 exit_status() const noexcept;
      
      /// @brief Sets exit status.
      /// @param exit_status exit status.
      /// @remarks The value by default is EXIT_SUCCESS.
      /// @remarks When an error occurred in unit test the value is set to EXIT_FAILURE.
      void exit_status(int32 exit_status) noexcept;
      
      /// @brief Gets filter tests.
      /// @return filter tests.
      /// @remarks The value by default is "*.*".
      const std::vector<ustring>& filter_tests() const noexcept;
      
      /// @brief Sets filter tests.
      /// @param filter_tests filter tests.
      /// @remarks The value by default is "*.*".
      void filter_tests(const std::vector<ustring>& filter_tests) noexcept;
      
      /// @brief Gets google test comaptibility.
      /// @return true if google test comaptibility; otherwise false.
      bool gtest_compatibility() const noexcept;
      
      /// @brief Sets google test comaptibility.
      /// @param gtest_compatibility  true if google test comaptibility; otherwise false.
      void gtest_compatibility(bool gtest_compatibility) noexcept;
      
      /// @brief Return true if a specified test class name and specified test name match with the current filter tests.
      /// @return Return true if class name and test name match with the current filter tests; otherwise false.
      bool is_match_test_name(const xtd::ustring& test_class_name, const xtd::ustring& test_name) const noexcept;
      
      /// @brief Gets list tests.
      /// @return true if list tests; otherwise false.
      bool list_tests() const noexcept;
      
      /// @brief Sets list tests.
      /// @param list_tests true if list tests; otherwise false.
      void list_tests(bool list_tests) noexcept;
      
      /// @brief Gets output color.
      /// @return true for colored output; otherwise false.
      bool output_color() const noexcept;
      
      /// @brief Sets output color.
      /// @param output_color true for colored output; otherwise false.
      void output_color(bool output_color) noexcept;
      
      /// @brief Gets output xml.
      /// @return true for generate xml report; otherwise false.
      bool output_json() const noexcept;
      
      /// @brief Sets output json.
      /// @param output_json true for generate json report; otherwise false.
      void output_json(bool output_json) noexcept;
      
      /// @brief Gets output xml.
      /// @return true for generate xml report; otherwise false.
      bool output_xml() const noexcept;
      
      /// @brief Sets output xml.
      /// @param output_xml true for generate xml report; otherwise false.
      void output_xml(bool output_xml) noexcept;
      
      /// @brief Gets output json path.
      /// @return Output json path.
      xtd::ustring output_json_path() const noexcept;
      
      /// @brief Sets output sjon path.
      /// @param output_jsonl_path Output json path.
      void output_json_path(const xtd::ustring& output_json_path) noexcept;
      
      /// @brief Gets output xml path.
      /// @return Output xml path.
      xtd::ustring output_xml_path() const noexcept;
      
      /// @brief Sets output xml path.
      /// @param output_xml_path Output xml path.
      void output_xml_path(const xtd::ustring& output_xml_path) noexcept;
      
      /// @brief Gets shuffle tests.
      /// @return Shuffle test.
      /// @remarks By default is set to false (no shuffle).
      bool shuffle_test() const noexcept;
      
      /// @brief Sets shuffle tests.
      /// @param shuffle_test Shuffle test.
      /// @remarks By default is set to false (no shuffle).
      void shuffle_test(bool shuffle_test) noexcept;
      
      /// @brief Gets random seed value.
      /// @return Random seed value.
      /// @remarks By default is set to 0 (no seed).
      uint32 random_seed() const noexcept;
      
      /// @brief Sets random seed value.
      /// @param random_seed Random seed value.
      /// @remarks By default is set to 0 (no seed).
      void random_seed(uint32 random_seed) noexcept;
      
      /// @brief Gets repeat tests count.
      /// @return Repeat test count.
      /// @remarks By default is set to 1 (no repeat).
      int32 repeat_test() const noexcept;
      
      /// @brief Sets repeat tests count.
      /// @param repeat_tests Repeat test count.
      /// @remarks By default is set to 1 (no repeat).
      void repeat_tests(int32 repeat_tests) noexcept;
      
      /// @brief Gets if show duration for each test.
      /// @return true if show duration for each test; otherwise false.
      bool show_duration() const noexcept;
      
      /// @brief Sets if show duration for each test.
      /// @param show_duration true if show duration for each test; otherwise false.
      void show_duration(bool show_duration) noexcept;
      
      /// @brief Gets unit test end time.
      /// @return Unit test end time.
      const xtd::date_time& end_time() const noexcept;
      
      /// @brief Gets unit test start time.
      /// @return Unit test start time.
      const xtd::date_time& start_time() const noexcept;
      
      /// @brief Gets stack trace enabled.
      /// @return true if stack trace enabled; otherwise false.
      /// @remarks The default value is false for increase the unit test execution.
      bool enable_stack_trace() const noexcept;
      
      /// @brief Sets stack trace enabled.
      /// @param enable_stack_trace true if stack trace enabled; otherwise false.
      /// @remarks The default value is false for increase the unit test execution.
      void enable_stack_trace(bool enable_stack_trace) noexcept;
      /// @}
      
    private:
      friend class unit_test;
      friend class ostream_event_listener;
      friend class ostream_unit_test;
      
      bool pattern_compare(const xtd::ustring& name, const xtd::ustring& pattern) const noexcept;
      
      void end_time(const xtd::date_time& end_time) noexcept;
      void start_time(const xtd::date_time& start_time) noexcept;
      
      bool also_run_ignored_tests_ = false;
      bool break_on_failure_ = false;
      bool brief_ = false;
      bool throw_on_failure_ = false;
      std::vector<ustring> filter_tests_;
      int32 exit_status_ = EXIT_SUCCESS;
      bool gtest_compatibility_ = false;
      bool count_tests_ = false;
      bool list_tests_ = false;
      bool output_color_ = true;
      bool output_json_ = false;
      bool output_xml_ = false;
      xtd::ustring output_json_path_ = "tests.json";
      xtd::ustring output_xml_path_ = "tests.xml";
      xtd::ustring file_name_ = xtd::io::path::get_full_path(xtd::environment::get_command_line_args()[0]);
      bool show_duration_ = true;
      bool shuffle_tests_ = false;
      uint32 random_seed_ = 0;
      int32 repeat_tests_ = 1;
      bool enable_stack_trace_ = false;
      xtd::date_time start_time_;
      xtd::date_time end_time_;
    };
  }
}
