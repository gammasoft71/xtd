/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include "trace_level.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a multilevel switch to control tracing and debug output without recompiling your code.
    /// @remarks You can use a trace switch to filter out messages based on their importance. The trace_switch class provides the trace_error, trace_warning, trace_info, and trace_verbose properties to test the level of the switch. The level property gets or sets the switch's trace_level.
    /// @remarks You can set the level of a trace_switch through the application configuration file and then use the configured trace_switch level in your application. Alternately, you can create a trace_switch in your code and set the level directly to instrument a specific section of code.
    class trace_switch {
    public:
      trace_switch(const std::string& display_name, const std::string& description) : display_name_(display_name), description_(description) {}
      trace_switch(const std::string& display_name, const std::string& description, const std::string& default_switch_value) : display_name_(display_name), description_(description), default_switch_value_(default_switch_value) {}

      xtd::diagnostics::trace_level level() const {return level_;}
      void level(xtd::diagnostics::trace_level level) {level_ = level;}
      
      bool trace_error() const {return static_cast<int32_t>(level_) >= static_cast<int32_t>(xtd::diagnostics::trace_level::error);}
      bool trace_info() const {return static_cast<int32_t>(level_) >= static_cast<int32_t>(xtd::diagnostics::trace_level::info);}
      bool trace_verbose() const {return static_cast<int32_t>(level_) >= static_cast<int32_t>(xtd::diagnostics::trace_level::verbose);}
      bool trace_warning() const {return static_cast<int32_t>(level_) >= static_cast<int32_t>(xtd::diagnostics::trace_level::warning);}

    private:
      std::string display_name_;
      std::string description_;
      std::string default_switch_value_;
      xtd::diagnostics::trace_level level_ = xtd::diagnostics::trace_level::off;
    };
  }
}
