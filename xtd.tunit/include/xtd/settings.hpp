/// @file
/// @brief Contains xtd::settings class.
#pragma once
#include <cstdlib>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The TUnit namespace contains a unit test framework.
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

    private:
      bool also_run_ignored_tests_ = false;
      int exit_status_ = EXIT_SUCCESS;
    };
  }
}
