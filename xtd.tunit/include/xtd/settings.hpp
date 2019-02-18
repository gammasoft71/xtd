/// @file
/// @brief Contains xtd::settings class.
#pragma once
#include <cstdlib>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The settings class.
    class settings final {
    public:
      settings() = default;
      settings(const settings&) = default;
      settings& operator=(const settings&) = default;

      static xtd::tunit::settings& default_settings() {
        static xtd::tunit::settings settings;
        return settings;
      }
      
      bool also_run_ignored_tests() const noexcept {return this->also_run_ignored_tests_;}
      void also_run_ignored_tests(bool also_run_ignored_tests) noexcept {this->also_run_ignored_tests_ = also_run_ignored_tests;}
      
      int exit_status() const noexcept {return this->exit_status_;}
      void exit_status(int exit_status) noexcept {this->exit_status_ = exit_status;}
      
      const std::string& filter_tests() const noexcept {return this->filter_tests_;}
      void filter_tests(const std::string& filter_tests) noexcept {this->filter_tests_ = filter_tests;}

      bool is_valid_test_name(const std::string& test_class_name, const std::string& test_name) const noexcept {return this->pattern_compare(test_class_name + "." + test_name, this->filter_tests_);}

      bool show_duration() const noexcept {return this->show_duration_;}
      void show_duration(bool show_duration) noexcept {this->show_duration_ = show_duration;}

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
    };
  }
}
