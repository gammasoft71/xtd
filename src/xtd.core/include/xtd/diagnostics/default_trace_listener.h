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
    /// @par Examples
    /// The following code example calculates binomial coefficients, which are values used in probability and statistics. This example uses a xtd::diagnostics::default_trace_listener to trace results and log errors. It creates a new xtd::diagnostics::default_trace_listener, adds it to the xtd::diagnostics::trace::listeners collection, and sets the xtd::diagnostics::default_trace_listener::log_file_name property to the log file specified in the command-line arguments.<br><br>
    /// If an error is detected while processing the input parameter, or if the calc_binomial function throws an exception, the xtd::diagnostics::default_trace_listener::fail method logs and displays an error message. If the xtd::diagnostics::default_trace_listener::assert_ui_enabled property is false, the error message is also written to the console. When the result is calculated successfully, the xtd::diagnostics::default_trace_listener::write and xtd::diagnostics::default_trace_listener::write_line methods write the results to the log file.<br><br>
    /// The xtd::diagnostics::default_trace_listener::fail, xtd::diagnostics::default_trace_listener::write, and xtd::diagnostics::default_trace_listener::write_line methods cause trace information to be written only to the xtd::diagnostics::default_trace_listener. To write trace information to all listeners in the xtd::diagnostics::trace::listeners collection, use the xtd::diagnostics::trace::fail, xtd::diagnostics::trace::write, and xtd::diagnostics::trace::write_line methods of the xtd::diagnostics::trace class.
    /// @include default_trace_listener.cpp
    class core_export_ default_trace_listener : public xtd::diagnostics::trace_listener {
    public:
      /// @brief Initializes a new instance of the default_trace_listener class with "default" as its xtd::diagnostics::default_trace_listener::name property value.
      /// @par Examples
      /// The following code example removes the xtd::diagnostics::default_trace_listener provided by the application from the xtd::diagnostics::trace::listeners collection and then creates a new xtd::diagnostics::default_trace_listener and adds it to the xtd::diagnostics::trace::listeners collection.
      /// @code
      /// // Remove the original default trace listener.
      /// trace::listeners().erase(trace::listeners().begin());
      ///
      /// // Create and add a new default trace listener.
      /// shared_ptr<default_trace_listener> default_listener = make_shared<default_trace_listener>();
      /// trace::listeners().push_back(default_listener);
      ///
      /// // Assign the log file specification from the command line, if entered.
      /// if (args.size() >= 2)
      ///   default_listener->log_file_name(args[1]);
      /// @endcode
      default_trace_listener();
      /// @cond
      ~default_trace_listener();
      /// @endcond

      /// @brief Gets a value indicating whether the application is running in user-interface mode.
      /// @return true if user-interface mode is enabled; otherwise, false.
      ///  @par Examples
      /// The following code example calls a function that calls the xtd::diagnostics::default_trace_listener::fail method to log an error message if the function throws an exception. If the xtd::diagnostics::default_trace_listener::assert_ui_enabled property is false, the method also writes the error message to the console.
      /// @code
      /// // Compute the next binomial coefficient and handle all exceptions.
      /// /// try {
      ///   result = calc_binomial(possibilities, iter);
      /// } catch (const system_exception& ex) {
      ///   string fail_message = strings::format("An exception was raised when calculating Binomial( {}, {} ).", possibilities, iter);
      ///   default_listener->fail(fail_message, ex.message());
      ///   if (!default_listener->assert_ui_enabled())
      ///     console::write_line(fail_message + "\n" + ex.message());
      ///   return;
      /// }
      /// @endcode
      bool assert_ui_enabled();
      /// @brief Sets a value indicating whether the application is running in user-interface mode.
      /// @param assert_ui_enabled true if user-interface mode is enabled; otherwise, false.
      ///  @par Examples
      /// The following code example calls a function that calls the xtd::diagnostics::default_trace_listener::fail method to log an error message if the function throws an exception. If the xtd::diagnostics::default_trace_listener::assert_ui_enabled property is false, the method also writes the error message to the console.
      /// @code
      /// // Compute the next binomial coefficient and handle all exceptions.
      /// /// try {
      ///   result = calc_binomial(possibilities, iter);
      /// } catch (const system_exception& ex) {
      ///   string fail_message = strings::format("An exception was raised when calculating Binomial( {}, {} ).", possibilities, iter);
      ///   default_listener->fail(fail_message, ex.message());
      ///   if (!default_listener->assert_ui_enabled())
      ///     console::write_line(fail_message + "\n" + ex.message());
      ///   return;
      /// }
      /// @endcode
      void assert_ui_enabled(bool assert_ui_enabled);

      /// @brief Gets the name of a log file to write trace or debug messages to.
      /// @return The name of a log file to write trace or debug messages to.
      /// @par Examples
      /// The following code example creates a new xtd::diagnostics::default_trace_listener, adds it to the xtd::diagnostics::trace::listeners collection, and sets the xtd::diagnostics::default_trace_listener::log_file_name property to the log file specified in the command-line arguments.
      /// @code
      /// // Create and add a new default trace listener.
      /// shared_ptr<default_trace_listener> default_listener = make_shared<default_trace_listener>();
      /// trace::listeners().push_back(default_listener);
      ///
      /// // Assign the log file specification from the command line, if entered.
      /// if (args.size() >= 2)
      ///   default_listener->log_file_name(args[1]);
      /// @endcode
      std::string log_file_name() const;
      /// @brief Sets the name of a log file to write trace or debug messages to.
      /// @param log_file_name The name of a log file to write trace or debug messages to.
      /// @par Examples
      /// The following code example creates a new xtd::diagnostics::default_trace_listener, adds it to the xtd::diagnostics::trace::listeners collection, and sets the xtd::diagnostics::default_trace_listener::log_file_name property to the log file specified in the command-line arguments.
      /// @code
      /// // Create and add a new default trace listener.
      /// shared_ptr<default_trace_listener> default_listener = make_shared<default_trace_listener>();
      /// trace::listeners().push_back(default_listener);
      ///
      /// // Assign the log file specification from the command line, if entered.
      /// if (args.size() >= 2)
      ///   default_listener->log_file_name(args[1]);
      /// @endcode
      void log_file_name(const std::string log_file_name);

      void close() override;
      void flush() override;
      
      using xtd::diagnostics::trace_listener::write;
      void write(const std::string& message) override;
      
      using xtd::diagnostics::trace_listener::write_line;
      void write_line(const std::string& message) override;
      
    private:
#if defined(__CMAKE_TARGET_TYPE__) && __CMAKE_TARGET_TYPE__ == 2 // 2 == GUI_APPLICATION
      bool assert_ui_enabled_ = true;
#else
      bool assert_ui_enabled_ = false;
#endif
      std::string log_file_name_;
      std::string message_line_;
    };
  }
}
