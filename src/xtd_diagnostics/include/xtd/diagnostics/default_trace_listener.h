/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <xtd/xtd.io>
#include "trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class default_trace_listener : public trace_listener {
    public:
      default_trace_listener() : trace_listener("default") {};
      ~default_trace_listener() {this->flush();}
      
      std::string log_file_name() const {return this->log_file_name_;}
      void log_file_name(const std::string log_file_name) {this->log_file_name_ = log_file_name;}

      void close() override {}
      void flush() override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (!this->message_line_.empty())
          this->write_line("");
#endif
      }
      
      using trace_listener::write;
      void write(const std::string& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (this->need_indent())
          this->write_indent();
        this->message_line_ += message;
        if (!this->log_file_name_.empty())
          xtd::io::file::append_all_text(this->log_file_name_, message);
#endif
      }
      
      using trace_listener::write_line;
      void write_line(const std::string& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        this->write(message + "\n");
        this->write_to_output_debug(this->message_line_);
        this->message_line_ = "";
        this->need_indent(true);
#endif
      }
      
    private:
      void write_to_output_debug(const std::string& message);
      
      std::string log_file_name_;
      std::string message_line_;
    };
  }
}
