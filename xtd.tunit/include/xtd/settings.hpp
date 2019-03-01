/// @file
/// @brief Contains xtd::tunit::settings class.
#pragma once
#include <cstdlib>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The settings class contains xtd.tunit settings.
    class settings final {
    public:
      /// @brief Creates new instance of settings.
      settings() = default;
      
      /// @cond
      settings(const settings&) = default;
      settings& operator=(const settings&) = default;
      /// @endcond

      /// @brief Get default settings intance.
      /// @return Default settings instance.
      static xtd::tunit::settings& default_settings() noexcept {
        static xtd::tunit::settings settings;
        return settings;
      }

      /// @brief Gets also run ignored test.
      /// @return true if  also run ignored test; otherwise false.
      bool also_run_ignored_tests() const noexcept {return this->also_run_ignored_tests_;}

      /// @brief Sets also run ignored test.
      /// @param also_run_ignored_tests  true if  also run ignored test; otherwise false.
      void also_run_ignored_tests(bool also_run_ignored_tests) noexcept {this->also_run_ignored_tests_ = also_run_ignored_tests;}
      
      /// @brief Gets exit status.
      /// @return exit status.
      /// @remarks The value by default is EXIT_SUCCESS.
      /// @remarks When an error occured in unit test the value is set to EXIT_FAILURE.
      int exit_status() const noexcept {return this->exit_status_;}
      
      /// @brief Sets exit status.
      /// @param exit_status exit status.
      /// @remarks The value by default is EXIT_SUCCESS.
      /// @remarks When an error occured in unit test the value is set to EXIT_FAILURE.
      void exit_status(int exit_status) noexcept {this->exit_status_ = exit_status;}
      
      /// @brief Gets filter tests.
      /// @return filter tests.
      /// @remarks The value by default is "*.*".
      const std::string& filter_tests() const noexcept {return this->filter_tests_;}

      /// @brief Sets filter tests.
      /// @param filter_tests filter tests.
      /// @remarks The value by default is "*.*".
      void filter_tests(const std::string& filter_tests) noexcept {this->filter_tests_ = filter_tests;}

      /// @brief Return true if a specified test class name and specified test name are valid with the current filter tests.
      /// @return Return true if class name and test name are valid with the current filter tests; otherwise false.
      bool is_valid_test_name(const std::string& test_class_name, const std::string& test_name) const noexcept {return this->pattern_compare(test_class_name + "." + test_name, this->filter_tests_);}

      /// @brief Gets if show duration for each test.
      /// @return true if show duration for each test; otherwise false.
      bool show_duration() const noexcept {return this->show_duration_;}
      
      /// @brief Sets if show duration for each test.
      /// @param show_duration true if show duration for each test; otherwise false.
      void show_duration(bool show_duration) noexcept {this->show_duration_ = show_duration;}

      /// @brief Gets output xml path.
      /// @return Output xml path.
      /// @remarks By default is set to "out.xml".
      /// @remarks If you cal xtd::unit_test constructor with argc and argv, the output xml path is set with application name (argv[0]).
      std::string output_xml() const noexcept {return this->output_xml_;}
      
      /// @brief Sets output xml path.
      /// @param output_xml Output xml path.
      /// @remarks By default is set to "out.xml".
      /// @remarks If you cal xtd::unit_test constructor with argc and argv, the output xml path is set with application name (argv[0]).
      void output_xml(const std::string& output_xml) noexcept {this->output_xml_ = output_xml;}

    private:
      bool pattern_compare(const std::string& name, const std::string& pattern) const noexcept {
        if (pattern == "") return name == "";
        if (name == "") return false;
        if (pattern == "*" || pattern == "*.*") return true;
        if (pattern[0] == '*') return this->pattern_compare(name, pattern.substr(1)) || this->pattern_compare(name.substr(1), pattern);
        return ((pattern[0] == '?') || (name[0] == pattern[0])) && this->pattern_compare(name.substr(1), pattern.substr(1));
      }
      
      bool also_run_ignored_tests_ = false;
      std::string filter_tests_ = "*.*";
      int exit_status_ = EXIT_SUCCESS;
      bool show_duration_ = true;
      std::string output_xml_ = "out.xml";
    };
  }
}
