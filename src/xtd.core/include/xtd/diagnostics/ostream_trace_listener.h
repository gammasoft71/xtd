/// @file
/// @brief Contains xtd::diagnostics::ostream_trace_listener listener.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <ostream>
#include "trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Directs tracing or debugging output to a std::ostream, such as std::fstream, std::stream...
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    class ostream_trace_listener : public trace_listener {
    public:
      /// @brief Initializes a new instance of the ostream_trace_listener class with a specified ostream.
      /// @param ostream An std::ostream that represents the stream the ostream_trace_listener writes to.
      /// @remarks This constructor initializes the name property to an empty string ("").
      ostream_trace_listener(const std::ostream& ostream) {
        this->ostream(ostream);
      };
      /// @cond
      ~ostream_trace_listener() {flush();}
      /// @endcond
      
      /// @brief Gets the underlying stream.
      /// @return A std::ostream that represents the stream the ostream_trace_listener writes to.
      virtual const std::ostream& ostream() const {return ostream_;}
      /// @brief Sets the underlying stream.
      /// @param ostream A std::ostream that represents the stream the ostream_trace_listener writes to.
      virtual void ostream(const std::ostream& ostream) {ostream_.rdbuf(ostream.rdbuf());}

      void close() override {}
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
