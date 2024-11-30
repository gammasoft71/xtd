/// @file
/// @brief Contains xtd::diagnostics::debug class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <cstdlib>
#include "../add_last_arg_to_command.hpp"
#include "../core_export.hpp"
#include "../environment.hpp"
#include "../static.hpp"
#include "../string.hpp"
#include "assert_dialog_result.hpp"
#include "debugger.hpp"
#include "stack_trace.hpp"
#include "trace_listener_collection.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace forms {
    class assert_dialog;
  }
  /// @endcond
  
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @cond
    class trace;
    /// @endcond
    ///
    /// @brief Provides a set of methods and properties that help you debug the execution of your code. This class cannot be inherited.
    /// ```cpp
    /// class core_export_ debug static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::diagnostics::debug
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/debug>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    /// @remarks You can use the properties and methods in the xtd::diagnostics::debug class to instrument release builds. Instrumentation allows you to monitor the health of your application running in real-life settings. Tracing helps you isolate problems and fix them without disturbing a running system.
    /// @remarks This class provides methods to display an assert dialog box, and to emit an assertion that will always fail. This class provides write methods in the following variations: xtd::diagnostics::debug::write, xtd::diagnostics::debug::write_line, xtd::diagnostics::debug::write_if, and xtd::diagnostics::debug::write_line_if.
    /// @remarks The xtd::diagnostics::boolean_switch and xtd::diagnostics::trace_switch classes provide means to dynamically control the tracing output. You can modify the values of these switches without recompiling your application. For information on using the configuration file to set a switch, see the xtd::diagnostics::switch class and the xtd::diagnostics::trace_switches topic.
    /// @remarks You can customize the tracing output's target by adding xtd::diagnostics::trace_listener instances to or removing instances from the xtd::diagnostics::debug::listeners collection. The xtd::diagnostics::debug::listeners collection is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; adding a trace listener to either class adds the listener to both. By default, trace output is emitted using the xtd::diagnostics::default_trace_listener class.
    /// @note Adding a trace listener to the xtd::diagnostics::debug::listeners collection can cause an exception to be thrown while tracing, if a resource used by the trace listener is not available. The conditions and the exception thrown depend on the trace listener and cannot be enumerated in this topic. It may be useful to place calls to the debug methods in try/catch blocks to detect and handle any exceptions from trace listeners.
    /// @remarks You can modify the level of indentation using the xtd::diagnostics::debug::indent method or the xtd::diagnostics::debug::indent_level property. To modify the indent spacing, use the xtd::diagnostics::debug::indent_size property. You can specify whether to automatically flush the output buffer after each write by setting the xtd::diagnostics::debug::auto_flush property to true.
    /// @remarks The debug class provides properties to get or set the level of indent, the xtd::diagnostics::debug::indent_size, and whether to xtd::diagnostics::debug::auto_flush after each write.
    /// @remarks You must enable debug mode to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build manager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your project, or you can add #define DEBUG to the top of your file.
    /// @remarks To activate your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
    /// @par Examples
    /// The following example uses debug to indicate the beginning and the end of a program's execution. The example also uses the debug::indent and debug::unindent methods to distinguish the tracing output.
    /// @include debug.cpp
    class core_export_ debug static_ {
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents a collection of xtd::diagnostics::trace_listener.
      using listener_collection = xtd::diagnostics::trace_listener_collection;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets whether xtd::diagnostics::debug::flush should be called on the xtd::diagnostics::debug::Listeners after every write.
      /// @return true if xtd::diagnostics::debug::flush is called on the xtd::diagnostics::debug::listeners after every write; otherwise, false.
      /// @remarks The default is false.
      /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call xtd::diagnostics::debug::flush or xtd::diagnostics::debug::close. Setting xtd::diagnostics::debug::auto_flush to true means that data will be flushed from the buffer to the stream.
      static bool auto_flush() noexcept;
      /// @brief Sets whether xtd::diagnostics::debug::flush should be called on the xtd::diagnostics::debug::Listeners after every write.
      /// @param auto_flush true if xtd::diagnostics::debug::flush is called on the xtd::diagnostics::debug::listeners after every write; otherwise, false.
      /// @remarks The default is false.
      /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call xtd::diagnostics::debug::flush or xtd::diagnostics::debug::close. Setting xtd::diagnostics::debug::auto_flush to true means that data will be flushed from the buffer to the stream.
      static void auto_flush(bool auto_flush) noexcept;
      
      /// @brief Gets the indent level.
      /// @return The indent level. The default is zero.
      /// @remarks The xtd::diagnostics::debug::indent_level property represents the number of times the indent of size xtd::diagnostics::debug::indent_size is applied. This property is stored on per-thread/per-request basis.
      static uint32 indent_level() noexcept;
      /// @brief Sets the indent level.
      /// @param indent_level The indent level. The default is zero.
      /// @remarks The xtd::diagnostics::debug::indent_level property represents the number of times the indent of size xtd::diagnostics::debug::indent_size is applied. This property is stored on per-thread/per-request basis.
      static void indent_level(uint32 indent_level) noexcept;
      
      /// @brief Gets the number of spaces in an indent.
      /// @return The number of spaces in an indent. The default is four.
      /// @remarks A xtd::diagnostics::ostream_trace_listener interprets this number as spaces. An xtd::diagnostics::event_log_trace_listener ignores this value.
      static uint32 indent_size() noexcept;
      /// @brief Sets the number of spaces in an indent.
      /// @param indent_size The number of spaces in an indent. The default is four.
      /// @remarks A xtd::diagnostics::ostream_trace_listener interprets this number as spaces. An xtd::diagnostics::event_log_trace_listener ignores this value.
      static void indent_size(uint32 indent_size) noexcept;
      
      /// @brief Gets the collection of listeners that is monitoring the trace output.
      /// @return A xtd::diagnostics::debug::listener_collection that represents a collection of type xtd::diagnostics::trace_listener monitoring the trace output.
      /// @remarks The xtd::diagnostics::debug::listeners produce formatted output from the trace output. By default, the collection contains an instance of the xtd::diagnostics::default_trace_listener class. If you want to remove the default listener, call the erase method, and pass it the instance of the xtd::diagnostics::default_trace_listener. To redirect output to the console window, add an instance of the xtd::diagnostics::console_trace_listener class.
      /// @note The xtd::diagnostics::debug::listeners collection is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; adding a trace listener to either class adds the listener to both.
      static listener_collection& listeners() noexcept;
      /// @brief Sets the collection of listeners that is monitoring the trace output.
      /// @paral$m listeners A xtd::diagnostics::debug::listener_collection that represents a collection of type xtd::diagnostics::trace_listener monitoring the trace output.
      /// @remarks The xtd::diagnostics::debug::listeners produce formatted output from the trace output. By default, the collection contains an instance of the xtd::diagnostics::default_trace_listener class. If you want to remove the default listener, call the erase method, and pass it the instance of the xtd::diagnostics::default_trace_listener. To redirect output to the console window, add an instance of the xtd::diagnostics::console_trace_listener class.
      /// @note The xtd::diagnostics::debug::listeners collection is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; adding a trace listener to either class adds the listener to both.
      static void listeners(const listener_collection& listeners) noexcept;
      
      /// @brief Gets a value indicating whether the assert dialog should be show.
      /// @return true if assert dialog is to be shown; otherwise, false. The default is true.
      /// @remarks The show assert dialog is used when xtd::diagnostics::debug::cassert or xtd::diagnostics::trace::cassert or assert_ is called to ask user to ignore, continue or retry the assert.
      /// @note The xtd::diagnostics::debug::show_assert_dialog boolean is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; updating the boolean to either class modify the show assert dialog to both.
      /// @deprecated Replaced by xtd::diagnostics::default_trace_listener::assert_ui_enabled - Will be removed in version 0.4.0.
      [[deprecated("Replaced by xtd::diagnostics::default_trace_listener::assert_ui_enabled - Will be removed in version 0.4.0.")]]
      static bool show_assert_dialog() noexcept;
      /// @brief Sets a value indicating whether the assert dialog should be show.
      /// @param show_assert_dialog true if assert dialog is to be shown; otherwise, false. The default is true.
      /// @remarks The show assert dialog is used when xtd::diagnostics::debug::cassert or xtd::diagnostics::trace::cassert or assert_ is called to ask user to ignore, continue or retry the assert.
      /// @note The xtd::diagnostics::debug::show_assert_dialog boolean is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; updating the boolean to either class modify the show assert dialog to both.
      /// @deprecated Replaced by xtd::diagnostics::default_trace_listener::assert_ui_enabled - Will be removed in version 0.4.0.
      [[deprecated("Replaced by xtd::diagnostics::default_trace_listener::assert_ui_enabled - Will be removed in version 0.4.0.")]]
      static void show_assert_dialog(bool show_assert_dialog) noexcept;
      
      /// @brief Gets a value indicating whether the global lock should be used.
      /// @return true if the global lock is to be used; otherwise, false. The default is true.
      /// @remarks The global lock is always used if the trace listener is not thread safe, regardless of the value of xtd::diagnostics::debug::use_global_lock. The IsThreadSafe property is used to determine if the listener is thread safe. The global lock is not used only if the value of UseGlobalLock is false and the value of IsThreadSafe is true. The default behavior is to use the global lock.
      static bool use_global_lock() noexcept;
      /// @brief Sets a value indicating whether the global lock should be used.
      /// @param use_global_lock true if the global lock is to be used; otherwise, false. The default is true.
      /// @remarks The global lock is always used if the trace listener is not thread safe, regardless of the value of UseGlobalLock. The xtd::diagnostics::debug::is_thread_safe property is used to determine if the listener is thread safe. The global lock is not used only if the value of xtd::diagnostics::debug::use_global_lock is false and the value of xtd::diagnostics::debug::is_thread_safe is true. The default behavior is to use the global lock.
      static void use_global_lock(bool use_global_lock) noexcept;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @param stack_frame The (optional) stack frame corresponding to the generated assert.
      static void cassert(bool condition, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @param message The message to send to the xtd::diagnostics::debug::listeners collection.
      /// @param stack_frame The (optional) stack frame corresponding to the generated assert.
      static void cassert(bool condition, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @param message The message to send to the xtd::diagnostics::debug::listeners collection.
      /// @param detail_message The detailed message to send to the xtd::diagnostics::debug::listeners collection.
      /// @param stack_frame The (optional) stack frame corresponding to the generated assert.
      static void cassert(bool condition, const xtd::string& message, const xtd::string& detail_message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      
      /// @brief Emits the specified error message.
      /// @param message A message to emit.
      /// @remarks The default behavior is that the xtd::diagnostics::default_trace_listener outputs the message to a message box when the application is running in user interface mode and to the xtd::diagnostics::trace_listener instances in the xtd::diagnostics::debug::listeners collection.
      /// @note The display of the message box is dependent on the presence of the xtd::diagnostics::default_trace_listener. If the xtd::diagnostics::default_trace_listener is not in the xtd::diagnostics::debug::listeners collection, the message box is not displayed. The xtd::diagnostics::default_trace_listener can be removed by the <clear>, the <erase>, or by calling the clear method on the xtd::diagnostics::debug::listeners property (xtd::diagnostics::trace::listeners().clear()).
      static void fail(const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        fail__(message);
        #endif
      }
      /// @brief Emits an error message and a detailed error message.
      /// @param message A message to emit.
      /// @param detail_message A detailed message to emit.
      /// @remarks The default behavior is that the default_trace_listener outputs the message to a message box when the application is running in user interface mode and to the TraceListener instances in the Listeners collection.
      /// @note The display of the message box is dependent on the presence of the default_trace_listener. If the default_trace_listener is not in the listeners collection, the message box is not displayed. The default_trace_listener can be removed by the <clear>, the <remove>, or by calling the clear method on the listeners property (xtd::diagnostics::trace::listeners().clear()).
      static void fail(const xtd::string& message, const xtd::string& detail_message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        fail__(message, detail_message);
        #endif
      }
      
      /// @brief Flushes the output buffer and causes buffered data to write to the listeners collection.
      static void flush() {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        flush_();
        #endif
      }
      
      /// @brief Increases the current indent_level by one.
      static void indent() noexcept;
      
      /// @brief Writes a message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message The message to write.
      /// @remarks The default line terminator is a carriage return followed by a line feed. By default, the output is written to an instance of default_trace_listener.
      static void print(const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(message);
        #endif
      }
      /// @brief Writes a formatted string followed by a line terminator to the trace listeners in the listeners collection.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @exception xtd::format_exception format is invalid.<br>-or-<br>The number that indicates an argument to format is less than zero, or greater than or equal to the number of specified objects to format.
      template<typename ...args_t>
      static void print(const xtd::string& format, args_t&& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(xtd::string::format(format, args...));
        #endif
      }
      /// @cond
      template<typename ...args_t>
      static void print(const char* format, args_t&& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(xtd::string::format(format, args...));
        #endif
      }
      /// @endcond
      
      /// @brief Writes an error message to the trace listeners in the Listeners collection using the specified message.
      /// @param message The informative message to write.
      /// @remarks trace_error calls the trace_event method for each trace listener, with the trace event type error, passing the informative message as the message string.
      static void trace_error(const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::error, message);
        #endif
      }
      /// @brief Writes an error message to the trace listeners in the listeners collection using the specified array of objects and formatting information.
      /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks trace_error calls the trace_event methods in the trace listeners with the trace event type error, passing the message content as an object array with formatting information.
      template<typename ...objects_t>
      static void trace_error(const xtd::string& message, const objects_t& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::error, xtd::string::format(message, args...));
        #endif
      }
      
      /// @brief Writes an informational message to the trace listeners in the listeners collection using the specified message.
      /// @param message The informative message to write.
      /// @remarks trace_information calls the trace_event method for each trace listener, with the trace event type information, passing the informative message as the message string.
      static void trace_information(const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::information, message);
        #endif
      }
      /// @brief Writes an informational message to the trace listeners in the listeners collection using the specified array of objects and formatting information.
      /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks trace_information calls the trace_event methods in the trace listeners with the trace event type information, passing the message content as an object array with formatting information.
      template<typename ...objects_t>
      static void trace_information(const xtd::string& message, const objects_t& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::information, xtd::string::format(message, args...));
        #endif
      }
      
      /// @brief Writes a warning message to the trace listeners in the listeners collection using the specified message.
      /// @param message The informative message to write.
      /// @remarks trace_warning calls the trace_event method for each trace listener with the trace event type Warning, passing the informative message as the message string.
      static void trace_warning(const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::warning, message);
        #endif
      }
      /// @brief Writes a warning message to the trace listeners in the listeners collection using the specified array of objects and formatting information.
      /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks trace_warning calls the trace_event methods in the trace listeners with the trace event type Warning, passing the message content as an object array with formatting information.
      template<typename ...objects_t>
      static void trace_warning(const xtd::string& message, const objects_t& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::warning, xtd::string::format(message, args...));
        #endif
      }
      
      /// @brief Decreases the current indent_level by one.
      static void unindent() noexcept;
      
      /// @brief Writes a message to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write(const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_(message);
        #endif
      }
      /// @brief Writes a message to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object_t>
      static void write(const object_t& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_(xtd::string::format("{}", message));
        #endif
      }
      /// @brief Writes a category name and message to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @param category A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks Use the category parameter to group output messages.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object_t>
      static void write(const object_t& message, const xtd::string& category) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_(xtd::string::format("{}", message), category);
        #endif
      }
      /// @brief Writes a formatted string to the trace listeners in the listeners collection.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename ...args_t>
      static void write(const xtd::string& format, args_t&& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_(string::format(format, args...));
        #endif
      }
      /// @cond
      template<typename ...args_t>
      static void write(const char* format, args_t&& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_(string::format(format, args...));
        #endif
      }
      /// @endcond
      
      /// @brief Writes a message to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_if(bool condition, const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (condition) write_(message);
        #endif
      }
      template<typename object_t>
      /// @brief Writes a message to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_if(bool condition, const object_t& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (condition) write_(xtd::string::format("{}", message));
        #endif
      }
      /// @brief Writes a category name and message to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @param category A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object_t>
      static void write_if(bool condition, const object_t& message, const xtd::string& category) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (condition) write_(xtd::string::format("{}", message), category);
        #endif
      }
      
      /// @brief Writes a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_line() {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_("");
        #endif
      }
      /// @brief Writes a message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_line(const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(message);
        #endif
      }
      /// @brief Writes a message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object_t>
      static void write_line(const object_t& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(xtd::string::format("{}", message));
        #endif
      }
      /// @brief Writes a category name and message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @param category A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks Use the category parameter to group output messages.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object_t>
      static void write_line(const object_t& message, const xtd::string& category) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(xtd::string::format("{}", message), category);
        #endif
      }
      /// @brief Writes a formatted string followed by a line terminator to the trace listeners in the listeners collection.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @exception xtd::format_exception format is invalid.<br>-or-<br>The number that indicates an argument to format is less than zero, or greater than or equal to the number of specified objects to format.
      template<typename ...args_t>
      static void write_line(const xtd::string& format, args_t&& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(string::format(format, args...));
        #endif
      }
      /// @cond
      template<typename ...args_t>
      static void write_line(const char* format, args_t&& ... args) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(string::format(format, args...));
        #endif
      }
      /// @endcond
      
      /// @brief Writes a message followed by a line terminator to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_line_if(bool condition, const xtd::string& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (condition) write_line_(message);
        #endif
      }
      /// @brief Writes a message followed by a line terminator to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object_t>
      static void write_line_if(bool condition, const object_t& message) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (condition) write_line_(message);
        #endif
      }
      /// @brief Writes a category name and message followed by a line terminator to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @param category A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object_t>
      static void write_line_if(bool condition, const object_t& message, const xtd::string& category) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (condition) write_line_(message, category);
        #endif
      }
      
      /// @cond
      static inline bool __should_aborted__(bool condition, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {return __should_aborted__(condition, xtd::string::empty_string, stack_frame);}
      static inline bool __should_aborted__(bool condition, const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {return __should_aborted__(condition, message, xtd::string::empty_string, stack_frame);}
      static inline bool __should_aborted__(bool condition, const xtd::string& message, const xtd::string& detail_message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        auto result = xtd::diagnostics::debug::assert_dialog(condition, message, detail_message, stack_frame);
        if (result == xtd::diagnostics::assert_dialog_result::abort) xtd::environment::exit(EXIT_FAILURE);
        if (result == xtd::diagnostics::assert_dialog_result::retry) return true;
        #endif
        return false;
      }
      /// @endcond
      /// @}
      
    private:
      friend trace;
      friend xtd::forms::assert_dialog;
      static xtd::diagnostics::assert_dialog_result assert_dialog(bool condition, const xtd::string& message, const xtd::string& detail_message, const xtd::diagnostics::stack_frame& stack_frame);
      static xtd::string assert_dialog_caption();
      static bool internal_show_assert_dialog() noexcept;
      static void fail__(const xtd::string& message);
      static void fail__(const xtd::string& message, const xtd::string& detail_message);
      static void flush_();
      static void trace_event_(trace_event_type trace_event_type, const xtd::string& message);
      static void write_(const xtd::string& message);
      static void write_(const xtd::string& message, const xtd::string& category);
      static void write_line_(const xtd::string& message);
      static void write_line_(const xtd::string& message, const xtd::string& category);
      
      inline static bool auto_flush_ = false;
      inline static uint32 indent_level_ = 0;
      inline static uint32 indent_size_ = 4;
      static listener_collection& listeners_;
      static xtd::string source_name_;
    };
  }
}
