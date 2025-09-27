/// @file
/// @brief Contains xtd::diagnostics::ostream_trace_listener listener.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <ostream>
#include "trace_listener.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Directs tracing or debugging output to a std::ostream, such as std::fstream, std::stream...
    /// ```cpp
    /// class core_export_ ostream_trace_listener : public xtd::diagnostics::trace_listener
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::abstract_object → xtd::diagnostics::trace_listener → xtd::diagnostics::ostream_trace_listener
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/ostream_trace_listener>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    class core_export_ ostream_trace_listener : public xtd::diagnostics::trace_listener {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::diagnostics::ostream_trace_listener class with a specified ostream.
      /// @param ostream An std::ostream that represents the stream the xtd::diagnostics::ostream_trace_listener writes to.
      /// @remarks This constructor initializes the name property to an empty string ("").
      explicit ostream_trace_listener(const std::ostream& ostream);
      /// @cond
      ~ostream_trace_listener();
      /// @endcond
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the underlying stream.
      /// @return A std::ostream that represents the stream the ostream_trace_listener writes to.
      virtual const std::ostream& ostream() const;
      /// @brief Sets the underlying stream.
      /// @param ostream A std::ostream that represents the stream the ostream_trace_listener writes to.
      virtual void ostream(const std::ostream& ostream);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      void close() override;
      void flush() override {
        #if !defined(NTRACE)
        flush_();
        #endif
      }
      
      using xtd::diagnostics::trace_listener::write;
      void write(const xtd::string& message) override {
        #if !defined(NTRACE)
        write_(message);
        #endif
      }
      
      using xtd::diagnostics::trace_listener::write_line;
      void write_line(const xtd::string& message) override {
        #if !defined(NTRACE)
        write_line_(message);
        #endif
      }
      /// @}
      
    private:
      void flush_();
      void write_(const xtd::string& message);
      void write_line_(const xtd::string& message);
      std::ostream ostream_ {nullptr};
    };
  }
}
