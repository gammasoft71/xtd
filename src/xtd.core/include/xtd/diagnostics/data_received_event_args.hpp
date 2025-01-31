/// @file
/// @brief Contains xtd::diagnostics::data_received_event_args event args.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../event_args.hpp"
#include "../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides data for the xtd::diagnostics::process::output_data_received and xtd::diagnostics::process::error_data_received events.
    /// ```cpp
    /// class data_received_event_args final : public xtd::event_args
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::event_args → xtd::diagnostics::data_received_event_args
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/data_received_event_args>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core events
    /// @remarks To asynchronously collect the redirected xtd::diagnostics::process::standard_output or xtd::diagnostics::process::standard_error stream output of a process, you must create a method that handles the redirected stream output events. The event-handler method is called when the process writes to the redirected stream. The event delegate calls your event handler with an instance of xtd::diagnostics::data_received_event_args. The xtd::diagnostics::data_received_event_args::data property contains the text line that the process wrote to the redirected stream.
    class data_received_event_args final : public xtd::event_args {
    public:
      /// @name Public Constructors
      /// @{
      
      /// @brief Initializes a new instance of the data_received_event_args class.
      data_received_event_args() = default;
      
      /// @brief Initializes a new instance of the data_received_event_args class.
      /// @param data The line that was written by an associated Process to its redirected xtd::diagnostics::process::standard_output or xtd::diagnostics::process::standard_error stream.
      explicit data_received_event_args(const xtd::string& data) : data_(data) {}
      
      /// @cond
      data_received_event_args(const data_received_event_args&) = default;
      data_received_event_args& operator =(const data_received_event_args&) = default;
      /// @endcond
      
      /// @}
      
      /// @name Public Properties
      /// @{
      
      /// @brief Gets the line of characters that was written to a redirected Process output stream.
      /// @return `true` if the current process should resume when the event handler concludes; `false` if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
      const xtd::string& data() const noexcept {return data_;}
      
      /// @}
      
    private:
      xtd::string data_;
    };
  }
}
