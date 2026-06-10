/// @file
/// @brief Contains xtd::tunit::settings class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.hpp"
#include <xtd/reflection/assembly>
#include <xtd/io/path>
#include <xtd/date_time>
#include <xtd/string>
#include <cstdint>
#include <xtd/optional>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    class ostream_event_listener;
    class ostream_unit_test;
    class unit_test;
    /// @endcond
    
    /// @brief The settings class contains xtd.tunit settings.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ settings final {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Creates new instance of settings.
      /// @remarks The following table shows the default value for properties :
      /// @remarks
      /// | Property               | Default value  |
      /// | ---------------------- | -------------- |
      /// | also_run_ignored_tests | `false`        |
      /// | break_on_failure       | `false`        |
      /// | brief                  | `false`        |
      /// | count_tests            | `false`        |
      /// | enable_stack_trace     | `false`        |
      /// | exit_status            | `EXIT_SUCCESS` |
      /// | filter_tests           | `{"*.*"}`      |
      /// | gtest_compatibility    | `false`        |
      /// | list_tests             | `false`        |
      /// | output_color           | `true`         |
      /// | output_json            | `false`        |
      /// | output_json_path       | `""`           |
      /// | output_xml             | `false`        |
      /// | output_xml_path        | `""`           |
      /// | random_seed            | `0`            |
      /// | repeat_test            | `1`            |
      /// | show_duration          | `true`         |
      /// | shuffle_test           | `false`        |
      /// | throw_on_failure       | `false`        |
      settings() = default;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets also run ignored test.
      /// @return `true` if also run ignored test; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto also_run_ignored_tests() const noexcept -> bool;
      /// @brief Sets also run ignored test.
      /// @param value `true` if also run ignored test; otherwise `false`. The default value is `false`.
      auto also_run_ignored_tests(bool value) noexcept -> settings&;
      
      /// @brief Gets break immediatly on failure.
      /// @return `true` if break immediatly on failure; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto break_on_failure() const noexcept -> bool;
      /// @brief Sets break immediatly on failure.
      /// @param value `true` if break immediatly on failure; otherwise `false`. The default value is `false`.
      auto break_on_failure(bool value) noexcept -> settings&;
      
      /// @brief Gets brief.
      /// @return `true` if brief; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto brief() const noexcept -> bool;
      /// @brief Sets brief.
      /// @param value `true` if brief; otherwise `false`. The default value is `false`.
      auto brief(bool value) noexcept -> settings&;
      
      /// @brief Gets count tests.
      /// @return `true` if count tests; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto count_tests() const noexcept -> bool;
      /// @brief Sets count tests.
      /// @param value `true` if count tests; otherwise `false`. The default value is `false`.
      auto count_tests(bool value) noexcept -> settings&;
      
      /// @brief Gets stack trace enabled.
      /// @return `true` if stack trace enabled; otherwise `false`. The default value is `false`.
      /// @warning If the valueur is set to `true`, unit test execution time will increase sharply.
      [[nodiscard]] auto enable_stack_trace() const noexcept -> bool;
      /// @brief Sets stack trace enabled.
      /// @param value `true` if stack trace enabled; otherwise `false`. The default value is `false`.
      /// @warning If the valueur is set to `true`, unit test execution time will increase sharply.
      auto enable_stack_trace(bool value) noexcept -> settings&;
      
      /// @brief Gets unit test end time.
      /// @return Unit test end time.
      [[nodiscard]] auto end_time() const noexcept -> const xtd::date_time&;
      
      /// @brief Gets exit status.
      /// @return exit status. The value by default is `EXIT_SUCCESS`.
      /// @remarks When an error occurred in unit test the value is set to `EXIT_FAILURE`.
      [[nodiscard]] auto exit_status() const noexcept -> xtd::int32;
      /// @brief Sets exit status.
      /// @param value exit status. The value by default is `EXIT_SUCCESS`.
      /// @remarks When an error occurred in unit test the value is set to `EXIT_FAILURE`.
      auto exit_status(xtd::int32 value) noexcept -> settings&;
      
      /// @brief Gets filter tests.
      /// @return filter tests. The value by default is `{"*.*"}`.
      [[nodiscard]] auto filter_tests() const noexcept -> const xtd::array<xtd::string>&;
      /// @brief Sets filter tests.
      /// @param value filter tests. The value by default is `{"*.*"}`.
      auto filter_tests(const xtd::array<xtd::string>& value) noexcept -> settings&;
      
      /// @brief Gets google test comaptibility.
      /// @return `true` if google test comaptibility; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto gtest_compatibility() const noexcept -> bool;
      /// @brief Sets google test comaptibility.
      /// @param value `true` if google test comaptibility; otherwise `false`. The default value is `false`.
      auto gtest_compatibility(bool value) noexcept -> settings&;
      
      /// @brief Return `true` if a specified test class name and specified test name match with the current filter tests.
      /// @return return `true` if class name and test name match with the current filter tests; otherwise `false`.
      [[nodiscard]] auto is_match_test_name(const xtd::string& test_class_name, const xtd::string& test_name) const noexcept -> bool;
      
      /// @brief Gets list tests.
      /// @return `true` if list tests; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto list_tests() const noexcept -> bool;
      /// @brief Sets list tests.
      /// @param value `true` if list tests; otherwise `false`. The default value is `false`.
      auto list_tests(bool value) noexcept -> settings&;
      
      /// @brief Gets output color.
      /// @return `true` for colored output; otherwise `false`. The default value is `true`.
      [[nodiscard]] auto output_color() const noexcept -> bool;
      /// @brief Sets output color.
      /// @param value `true` for colored output; otherwise `false`. The default value is `true`.
      auto output_color(bool value) noexcept -> settings&;
      
      /// @brief Gets output xml.
      /// @return `true` for generate xml report; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto output_json() const noexcept -> bool;
      /// @brief Sets output json.
      /// @param value `true` for generate json report; otherwise `false`. The default value is `false`.
      auto output_json(bool value) noexcept -> settings&;
      
      /// @brief Gets output json path.
      /// @return Output json path. The default value is xtd::string::empty_string ("").
      [[nodiscard]] auto output_json_path() const noexcept -> xtd::string;
      /// @brief Sets output sjon path.
      /// @param value Output json path. The default value is xtd::string::empty_string ("").
      auto output_json_path(const xtd::string& value) noexcept -> settings&;
      
      /// @brief Gets output xml.
      /// @return `true` for generate xml report; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto output_xml() const noexcept -> bool;
      /// @brief Sets output xml.
      /// @param value `true` for generate xml report; otherwise `false`. The default value is `false`.
      auto output_xml(bool value) noexcept -> settings&;
      
      /// @brief Gets output xml path.
      /// @return Output xml path. The default value is xtd::string::empty_string ("").
      [[nodiscard]] auto output_xml_path() const noexcept -> xtd::string;
      /// @brief Sets output xml path.
      /// @param value Output xml path. The default value is xtd::string::empty_string ("").
      auto output_xml_path(const xtd::string& value) noexcept -> settings&;
      
      /// @brief Gets random seed value.
      /// @return Random seed value. The default value is `0` (no seed).
      [[nodiscard]] auto random_seed() const noexcept -> xtd::uint32;
      /// @brief Sets random seed value.
      /// @param value Random seed value. The default value is `0` (no seed).
      auto random_seed(xtd::uint32 value) noexcept -> settings&;
      
      /// @brief Gets repeat tests count.
      /// @return Repeat test count. The default value is `1` (no repeat).
      [[nodiscard]] auto repeat_test() const noexcept -> xtd::int32;
      /// @brief Sets repeat tests count.
      /// @param value Repeat test count. The default value is `1` (no repeat).
      auto repeat_tests(xtd::int32 value) noexcept -> settings&;
      
      /// @brief Gets if show duration for each test.
      /// @return `true` if show duration for each test; otherwise `false`. The default value is `true`.
      [[nodiscard]] auto show_duration() const noexcept -> bool;
      /// @brief Sets if show duration for each test.
      /// @param value `true` if show duration for each test; otherwise `false`. The default value is `true`.
      auto show_duration(bool value) noexcept -> settings&;
      
      /// @brief Gets shuffle tests.
      /// @return `true` if shuffle test; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto shuffle_test() const noexcept -> bool;
      /// @brief Sets shuffle tests.
      /// @param value `true` if shuffle test; otherwise `false`. The default value is `false`.
      auto shuffle_test(bool value) noexcept -> settings&;
      
      /// @brief Gets unit test start time.
      /// @return Unit test start time.
      [[nodiscard]] auto start_time() const noexcept -> const xtd::date_time&;
      
      /// @brief Gets throw on failure.
      /// @return `true` if throw on failure; otherwise `false`. The default value is `false`.
      [[nodiscard]] auto throw_on_failure() const noexcept -> bool;
      /// @brief Sets throw on failure.
      /// @param value `true` if throw on failure; otherwise `false`. The default value is `false`.
      auto throw_on_failure(bool value) noexcept -> settings&;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets default settings instance.
      /// @return Default settings instance.
      /// @remarks The following table shows the default value for properties :
      /// @remarks
      /// | Property               | Default value  |
      /// | ---------------------- | -------------- |
      /// | also_run_ignored_tests | `false`        |
      /// | break_on_failure       | `false`        |
      /// | brief                  | `false`        |
      /// | count_tests            | `false`        |
      /// | enable_stack_trace     | `false`        |
      /// | exit_status            | `EXIT_SUCCESS` |
      /// | filter_tests           | `{"*.*"}`      |
      /// | gtest_compatibility    | `false`        |
      /// | list_tests             | `false`        |
      /// | output_color           | `true`         |
      /// | output_json            | `false`        |
      /// | output_json_path       | `""`           |
      /// | output_xml             | `false`        |
      /// | output_xml_path        | `""`           |
      /// | random_seed            | `0`            |
      /// | repeat_test            | `1`            |
      /// | show_duration          | `true`         |
      /// | shuffle_test           | `false`        |
      /// | throw_on_failure       | `false`        |
      [[nodiscard]] static auto default_settings() noexcept -> xtd::tunit::settings&;
      /// @}
      
    private:
      friend class xtd::tunit::ostream_event_listener;
      friend class xtd::tunit::ostream_unit_test;
      friend class xtd::tunit::unit_test;
      
      auto end_time(const xtd::date_time& end_time) noexcept -> settings&;
      auto start_time(const xtd::date_time& start_time) noexcept -> settings&;
      
      bool also_run_ignored_tests_ = false;
      bool break_on_failure_ = false;
      bool brief_ = false;
      bool count_tests_ = false;
      bool enable_stack_trace_ = false;
      xtd::date_time end_time_;
      xtd::int32 exit_status_ = 0;
      xtd::string file_name_ = xtd::io::path::get_full_path(xtd::reflection::assembly::get_executing_assembly().location());
      xtd::array<string> filter_tests_ = {"*.*"};
      bool gtest_compatibility_ = false;
      bool list_tests_ = false;
      bool output_color_ = true;
      bool output_json_ = false;
      std::optional<xtd::string> output_json_path_;
      bool output_xml_ = false;
      std::optional<xtd::string> output_xml_path_;
      xtd::uint32 random_seed_ = 0;
      xtd::int32 repeat_tests_ = 1;
      bool show_duration_ = true;
      bool shuffle_tests_ = false;
      xtd::date_time start_time_;
      bool throw_on_failure_ = false;
    };
  }
}
