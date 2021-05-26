/// @file
/// @brief Contains xtd::diagnostics::trace_switch class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "switch_base.h"
#include "debug.h"
#include "trace_level.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a multilevel switch to control tracing and debug output without recompiling your code.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core debug
    /// @remarks You can use a trace switch to filter out messages based on their importance. The trace_switch class provides the trace_error, trace_warning, trace_info, and trace_verbose properties to test the level of the switch. The level property gets or sets the switch's trace_level.
    /// @remarks You can set the level of a trace_switch through the application configuration file and then use the configured trace_switch level in your application. Alternately, you can create a trace_switch in your code and set the level directly to instrument a specific section of code.
    class trace_switch : public xtd::diagnostics::switch_base {
    public:
      trace_switch(const std::string& display_name, const std::string& description) : switch_base(display_name, description) {}
      trace_switch(const std::string& display_name, const std::string& description, const std::string& default_switch_value) : switch_base(display_name, description, default_switch_value) {}

      xtd::diagnostics::trace_level level() const {return static_cast<xtd::diagnostics::trace_level>(switch_setting());}
      void level(xtd::diagnostics::trace_level level) {switch_setting(static_cast<int32_t>(level));}
      
      bool trace_error() const {return static_cast<int32_t>(level()) >= static_cast<int32_t>(xtd::diagnostics::trace_level::error);}
      bool trace_info() const {return static_cast<int32_t>(level()) >= static_cast<int32_t>(xtd::diagnostics::trace_level::info);}
      bool trace_verbose() const {return static_cast<int32_t>(level()) == static_cast<int32_t>(xtd::diagnostics::trace_level::verbose);}
      bool trace_warning() const {return static_cast<int32_t>(level()) >= static_cast<int32_t>(xtd::diagnostics::trace_level::warning);}

    protected:
      void on_switch_setting_changed() override {
        switch_base::on_switch_setting_changed();
        int32_t level = switch_setting();
        if (level < static_cast<int32_t>(xtd::diagnostics::trace_level::off)) {
          //xtd::diagnostics::debug::write_line<std::string>(std::string("trace_switch level too low"), display_name());
          switch_setting(static_cast<int32_t>(xtd::diagnostics::trace_level::off));
        } else if (level > static_cast<int32_t>(xtd::diagnostics::trace_level::verbose)) {
          //xtd::diagnostics::debug::write_line<std::string>(std::string("trace_switch level too high"), display_name());
          switch_setting(static_cast<int32_t>(xtd::diagnostics::trace_level::verbose));
        }
      }
      
      void on_value_changed() override {
        switch_base::on_value_changed();
        switch_setting(static_cast<int32_t>(xtd::parse<xtd::diagnostics::trace_level>(value())));
      }
    };
  }
}
