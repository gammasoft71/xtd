/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <ostream>
#include "trace_listener.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class default_trace_listener : public trace_listener {
    public:
      default_trace_listener() = default;
      ~default_trace_listener() {this->flush();}

      void close() override {}
      void flush() override {
        if (!this->default_trace_listener_data_->message_line_.empty())
          this->write_line("");

      }
      
      using trace_listener::write;
      void write(const std::string& message) override {
        if (this->need_indent())
          this->write_indent();
        this->default_trace_listener_data_->message_line_ += message;
      }
      
      using trace_listener::write_line;
      void write_line(const std::string& message) override {
        this->write_to_output_debug(xtd::strings::format("{}{}{}", this->default_trace_listener_data_->message_line_, message, xtd::environment::new_line()));
        this->default_trace_listener_data_->message_line_ = "";
        this->need_indent(true);
      }
      
    private:
      void write_to_output_debug(const std::string& message);
      
      struct default_trace_listener_data {
        std::string log_file_name_;
        std::ofstream log_stream_;
        std::string message_line_;

      };
      
      std::shared_ptr<default_trace_listener_data> default_trace_listener_data_ = std::make_shared<default_trace_listener_data>();
    };
  }
}
