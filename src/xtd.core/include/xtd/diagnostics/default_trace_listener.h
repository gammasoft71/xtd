/// @file
/// @brief Contains xtd::diagnostics::default_trace_listener class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../core_export.h"
#include "trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides the default output methods and behavior for tracing.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    class core_export_ default_trace_listener : public xtd::diagnostics::trace_listener {
    public:
      /// @brief Initializes a new instance of the default_trace_listener class with "default" as its Name property value.
      default_trace_listener();
      /// @cond
      ~default_trace_listener();
      /// @endcond

      /// @brief Gets the name of a log file to write trace or debug messages to.
      /// @return The name of a log file to write trace or debug messages to.
      std::string log_file_name() const;
      /// @brief Sets the name of a log file to write trace or debug messages to.
      /// @param log_file_name The name of a log file to write trace or debug messages to.
      void log_file_name(const std::string log_file_name);

      void close() override;
      void flush() override;
      
      using xtd::diagnostics::trace_listener::write;
      void write(const std::string& message) override;
      
      using xtd::diagnostics::trace_listener::write_line;
      void write_line(const std::string& message) override;
      
    private:
      std::string log_file_name_;
      std::string message_line_;
    };
  }
}
