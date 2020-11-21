/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <ostream>
#include "trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class ostream_trace_listener : public trace_listener {
    public:
      ostream_trace_listener(const std::ostream& ostream) {
        this->ostream(ostream);
      };
      ~ostream_trace_listener() {flush();}
      
      virtual const std::ostream& ostream() const {return ostream_;}
      virtual void ostream(const std::ostream& ostream) {ostream_.rdbuf(ostream.rdbuf());}

      void close() override { }
      void flush() override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (ostream_.good())
          ostream_ << std::flush;
#endif
      }
      
      using trace_listener::write;
      void write(const std::string& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (need_indent())
          write_indent();
        if (ostream_.good())
          ostream_ << message;
#endif
      }
      
      using trace_listener::write_line;
      void write_line(const std::string& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write(message + "\n");
         need_indent(true);
#endif
      }
      
    private:
      void write_to_output_debug(const std::string& message);
      std::ostream ostream_ {nullptr};
    };
  }
}
