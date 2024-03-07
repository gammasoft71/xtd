/// @file
/// @brief Contains xtd::diagnostics::console_trace_listener class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <iostream>
#include "ostream_trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Directs tracing or debugging output to either the standard output or the standard error stream.
    /// @code
    /// class core_export_ console_trace_listener : public xtd::diagnostics::ostream_trace_listener
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::abstract_object → xtd::diagnostics::trace_listener → xtd::diagnostics::ostream_trace_listener → xtd::diagnostics::console_trace_listener
    /// @par Header
    /// @code #include <xtd/diagnostics/console_trace_listener> @endcode
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    /// @par Examples
    /// The following example shows how to use xtd::diagnostics::console_trace_listener class.
    /// @include console_trace_listener.cpp
    class core_export_ console_trace_listener : public xtd::diagnostics::ostream_trace_listener {
    public:
      /// @name Public Constructors
      /// @{
      
      /// @brief Initializes a new instance of the xtd::diagnostics::console_trace_listener class with trace output written to the standard output stream.
      /// @remarks This constructor initializes a xtd::diagnostics::console_trace_listener object to write messages to either the std::cout or the std::cerr stream. Its xtd::diagnostics:::console_trace_listener::name property is initialized to an empty string ("").
      console_trace_listener();
      /// @brief Initializes a new instance of the xtd::diagnostics::console_trace_listener class with an option to write trace output to the standard output stream or the standard error stream.
      /// @param use_error_stream true to write tracing and debugging output to the standard error stream; false to write tracing and debugging output to the standard output stream.
      /// @remarks This constructor initializes a xtd::diagnostics::console_trace_listener object to write messages to either the std::cout or the std::cerr stream. Its xtd::diagnostics::console_trace_listener::name property is initialized to an empty string ("").
      explicit console_trace_listener(bool use_error_stream);
      
      /// @}
      
    private:
      using xtd::diagnostics::ostream_trace_listener::ostream;
    };
  }
}
