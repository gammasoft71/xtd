/// @file
/// @brief Contains xtd::diagnostics::default_trace_listener class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/io/file.h>
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
    class core_export_ default_trace_listener : public trace_listener {
    public:
      /// @brief Initializes a new instance of the default_trace_listener class with "default" as its Name property value.
      default_trace_listener() : trace_listener("default") {};
      /// @cond
      ~default_trace_listener() {flush();}
      /// @endcond

      /// @brief Gets the name of a log file to write trace or debug messages to.
      /// @return The name of a log file to write trace or debug messages to.
      std::string log_file_name() const {return log_file_name_;}
      /// @brief Sets the name of a log file to write trace or debug messages to.
      /// @param log_file_name The name of a log file to write trace or debug messages to.
      void log_file_name(const std::string log_file_name) {log_file_name_ = log_file_name;}

      void close() override {}
      void flush() override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (!message_line_.empty())
          write_line("");
#endif
      }
      
      using trace_listener::write;
      void write(const std::string& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (need_indent())
          write_indent();
        message_line_ += message;
        if (!log_file_name_.empty())
          xtd::io::file::append_all_text(log_file_name_, message);
#endif
      }
      
      using trace_listener::write_line;
      void write_line(const std::string& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write(message + "\n");
        write_to_output_debug(message_line_);
        message_line_ = "";
        need_indent(true);
#endif
      }
      
    private:
      void write_to_output_debug(const std::string& message);
      
      std::string log_file_name_;
      std::string message_line_;
    };
  }
}
