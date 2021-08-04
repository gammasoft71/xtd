/// @file
/// @brief Contains xtd::diagnostics::trace class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "debug.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a set of methods and properties that help you debug the execution of your code. This class cannot be inherited.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core diagnostics debug
    /// @remarks You can use the properties and methods in the debug class to instrument release builds. Instrumentation allows you to monitor the health of your application running in real-life settings. Tracing helps you isolate problems and fix them without disturbing a running system.
    /// @remarks This class provides methods to display an assert dialog box, and to emit an assertion that will always Fail. This class provides write methods in the following variations: write, write_line, write_if, and write_line_if.
    /// @remarks The boolean_switch and trace_switch classes provide means to dynamically control the tracing output. You can modify the values of these switches without recompiling your application. For information on using the configuration file to set a switch, see the switch class and the trace_switches topic.
    /// @remarks You can customize the tracing output's target by adding trace_listener instances to or removing instances from the listeners collection. The listeners collection is shared by both the debug and the trace classes; adding a trace listener to either class adds the listener to both. By default, trace output is emitted using the default_trace_listener class.
    /// @note Adding a trace listener to the listeners collection can cause an exception to be thrown while tracing, if a resource used by the trace listener is not available. The conditions and the exception thrown depend on the trace listener and cannot be enumerated in this topic. It may be useful to place calls to the debug methods in try/catch blocks to detect and handle any exceptions from trace listeners.
    /// @remarks The debug class provides properties to get or set the level of indent, the indent_size, and whether to auto_flush after each write.
    /// @remarks You must enable debug or trace mode to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build nanager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your porject, or you can add #define DEBUG to the top of your file.
    ///  * To enable trace mode with cmake, add the add_definitions(-DTRACE) command line in the CMakeLists.txt of your porject, or you can add #define TRACE to the top of your file.
    /// @remarks To activete your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
    /// @remarks To activete your code if TRACE is defined, you must enclose calls to the methods of Debug in an #if defined(TRACE) ... #endif block, and add the /DTRACE option to the compiler command line or add #define TRACE to the file.
    /// @par Examples
    /// The following example uses debug to indicate the beginning and the end of a program's execution. The example also uses the debug::indent and debug::unindent methods to distinguish the tracing output.
    /// @include debug.cpp
    class core_export_ trace static_ {
    public:
      /// @brief Represents a collection of xtd::diagnostics::trace_listener.
      using listener_collection = xtd::diagnostics::trace_listener_collection;
      
      /// @brief Get whether Flush should be called on the Listeners after every write.
      /// @return true if Flush is called on the Listeners after every write; otherwise, false.
      /// @remarks The default is false.
      /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call Flush or Close. Setting AutoFlush to true means that data will be flushed from the buffer to the stream, but the encoder state will not be flushed. This allows the encoder to keep its state (partial characters) so that it can encode the next block of characters correctly. This scenario affects UTF8 and UTF7 where certain characters can only be encoded after the encoder receives the adjacent character or characters.
      static bool auto_flush();
      /// @brief Sets whether Flush should be called on the Listeners after every write.
      /// @param auto_flush true if Flush is called on the Listeners after every write; otherwise, false.
      /// @remarks The default is false.
      /// @remarks Flushing the stream will not flush its underlying encoder unless you explicitly call Flush or Close. Setting AutoFlush to true means that data will be flushed from the buffer to the stream, but the encoder state will not be flushed. This allows the encoder to keep its state (partial characters) so that it can encode the next block of characters correctly. This scenario affects UTF8 and UTF7 where certain characters can only be encoded after the encoder receives the adjacent character or characters.
      static void auto_flush(bool auto_flush);
      
      /// @brief Gets the indent level.
      /// @return The indent level. The default is zero.
      /// @remarks The IndentLevel property represents the number of times the indent of size IndentSize is applied. This property is stored on per-thread/per-request basis.
      static uint32_t indent_level();
      /// @brief Sets the indent level.
      /// @param indent_level The indent level. The default is zero.
      /// @remarks The IndentLevel property represents the number of times the indent of size IndentSize is applied. This property is stored on per-thread/per-request basis.
      static void indent_level(uint32_t indent_level);
      
      /// @brief Gets the number of spaces in an indent.
      /// @return The number of spaces in an indent. The default is four.
      /// @remarks A ostream_trace_listener interprets this number as spaces. An event_log_trace_listener ignores this value.
      static uint32_t indent_size();
      /// @brief Sets the number of spaces in an indent.
      /// @param indent_size The number of spaces in an indent. The default is four.
      /// @remarks A ostream_trace_listener interprets this number as spaces. An event_log_trace_listener ignores this value.
      static void indent_size(uint32_t indent_size);
      
      /// @brief Gets the collection of listeners that is monitoring the trace output.
      /// @return A listener_collection that represents a collection of type trace_listener monitoring the trace output.
      /// @remarks The listeners produce formatted output from the trace output. By default, the collection contains an instance of the default_trace_listener class. If you want to remove the default listener, call the Remove method, and pass it the instance of the default_trace_listener. To redirect output to the console window, add an instance of the console_trace_listener class.
      /// @note The Listeners collection is shared by both the Debug and the Trace classes; adding a trace listener to either class adds the listener to both.
      static listener_collection& listeners();
      /// @brief Sets the collection of listeners that is monitoring the trace output.
      /// @param listeners A listener_collection that represents a collection of type trace_listener monitoring the trace output.
      /// @remarks The listeners produce formatted output from the trace output. By default, the collection contains an instance of the default_trace_listener class. If you want to remove the default listener, call the Remove method, and pass it the instance of the default_trace_listener. To redirect output to the console window, add an instance of the console_trace_listener class.
      /// @note The Listeners collection is shared by both the Debug and the Trace classes; adding a trace listener to either class adds the listener to both.
      static void listeners(const listener_collection& listeners);
      
      /// @brief Gets a value indicating whether the assert dialog should be show.
      /// @return true if assert dialog is to be shown; otherwise, false. The default is true.
      /// @remarks The show assert dialog is used when xtd::diagnostics::debug::cassert or td::diagnostics::trace::cassert or #assert_ is called to ask user to ignore, continue or retry the assert.
      /// @note The xtd::diagnostics::debug::show_assert_dialog boolean is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; updating the boolean to either class modify the show assert dialog to both.
      static bool show_assert_dialog();
      /// @brief Sets a value indicating whether the assert dialog should be show.
      /// @return true if assert dialog is to be shown; otherwise, false. The default is true.
      /// @remarks The show assert dialog is used when xtd::diagnostics::debug::cassert or td::diagnostics::trace::cassert or #assert_ is called to ask user to ignore, continue or retry the assert.
      /// @note The xtd::diagnostics::debug::show_assert_dialog boolean is shared by both the xtd::diagnostics::debug and the xtd::diagnostics::trace classes; updating the boolean to either class modify the show assert dialog to both.
      static void show_assert_dialog(bool show_assert_dialog);

      /// @brief Gets a value indicating whether the global lock should be used.
      /// @return true if the global lock is to be used; otherwise, false. The default is true.
      /// @remarks The global lock is always used if the trace listener is not thread safe, regardless of the value of UseGlobalLock. The IsThreadSafe property is used to determine if the listener is thread safe. The global lock is not used only if the value of UseGlobalLock is false and the value of IsThreadSafe is true. The default behavior is to use the global lock.
      static bool use_global_lock();
      /// @brief Sets a value indicating whether the global lock should be used.
      /// @param use_global_lock true if the global lock is to be used; otherwise, false. The default is true.
      /// @remarks The global lock is always used if the trace listener is not thread safe, regardless of the value of UseGlobalLock. The IsThreadSafe property is used to determine if the listener is thread safe. The global lock is not used only if the value of UseGlobalLock is false and the value of IsThreadSafe is true. The default behavior is to use the global lock.
      static void use_global_lock(bool use_global_lock);
      
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @par Examples
      /// The following example shows how to use xtd::diagnostics::trace::cassert_ method.
      /// @include trace_cassert.cpp
      static void cassert(bool condition);
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @param message The message to send to the Listeners collection.
      static void cassert(bool condition, const xtd::ustring& message);
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @param message The message to send to the xtd::diagnostics::debug::listeners collection.
      /// @param stack_frame The stack frame corresponding to the generated assert.
      static void cassert(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame);
      /// @brief Checks for a condition; if the condition is false, displays a message box that shows the call stack.
      /// @param condition The conditional expression to evaluate. If the condition is true, a failure message is not sent and the message box is not displayed.
      /// @param stack_frame The stack frame corresponding to the generated assert.
      static void cassert(bool condition, const xtd::diagnostics::stack_frame& stack_frame);

      /// @brief Emits the specified error message.
      /// @param message A message to emit.
      /// @remarks The default behavior is that the default_trace_listener outputs the message to a message box when the application is running in user interface mode and to the TraceListener instances in the Listeners collection.
      /// @note The display of the message box is dependent on the presence of the default_trace_listener. If the default_trace_listener is not in the listeners collection, the message box is not displayed. The default_trace_listener can be removed by the <clear>, the <remove>, or by calling the clear method on the listeners property (xtd::diagnostics::trace::listeners().clear()).
      static void fail(const xtd::ustring& message) {
#if defined(TRACE)
        fail__(message);
#endif
      }
      /// @brief Emits an error message and a detailed error message.
      /// @param message A message to emit.
      /// @param detail_message A detailed message to emit.
      /// @remarks The default behavior is that the default_trace_listener outputs the message to a message box when the application is running in user interface mode and to the TraceListener instances in the Listeners collection.
      /// @note The display of the message box is dependent on the presence of the default_trace_listener. If the default_trace_listener is not in the listeners collection, the message box is not displayed. The default_trace_listener can be removed by the <clear>, the <remove>, or by calling the clear method on the listeners property (xtd::diagnostics::trace::listeners().clear()).
      static void fail(const xtd::ustring& message, const xtd::ustring& detail_message) {
#if defined(TRACE)
        fail__(message, detail_message);
#endif
      }
      
      /// @brief Flushes the output buffer and causes buffered data to write to the listeners collection.
      static void flush() {
#if defined(TRACE)
        flush_();
#endif
      }
      
      /// @brief Increases the current indent_level by one.
      static void indent();
      
      /// @brief Writes a message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message The message to write.
      /// @remarks The default line terminator is a carriage return followed by a line feed. By default, the output is written to an instance of default_trace_listener.
      static void print(const xtd::ustring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(message);
#endif
      }
      /// @brief Writes a formatted string followed by a line terminator to the trace listeners in the listeners collection.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @exception xtd::format_exception format is invalid. -or- The number that indicates an argument to format is less than zero, or greater than or equal to the number of specified objects to format.
      template<typename ...args_t>
      static void print(const xtd::ustring& format, args_t&&... args) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(xtd::ustring::format(format, args...));
#endif
      }
      /// @cond
      template<typename ...args_t>
      static void print(const char* format, args_t&&... args) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_line_(xtd::ustring::format(format, args...));
#endif
      }
      /// @endcond
      
      /// @brief Writes an error message to the trace listeners in the Listeners collection using the specified message.
      /// @param message The informative message to write.
      /// @remarks trace_error calls the trace_event method for each trace listener, with the trace event type error, passing the informative message as the message string.
      static void trace_error(const xtd::ustring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::error, message);
#endif
      }
      /// @brief Writes an error message to the trace listeners in the listeners collection using the specified array of objects and formatting information.
      /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks trace_error calls the trace_event methods in the trace listeners with the trace event type error, passing the message content as an object array with formatting information.
      template<typename ...objects>
      static void trace_error(const xtd::ustring& message, const objects& ... args) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::error, message, args...);
#endif
      }
      
      /// @brief Writes an informational message to the trace listeners in the listeners collection using the specified message.
      /// @param message The informative message to write.
      /// @remarks trace_information calls the trace_event method for each trace listener, with the trace event type information, passing the informative message as the message string.
      static void trace_information(const xtd::ustring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::information, message);
#endif
      }
      /// @brief Writes an informational message to the trace listeners in the listeners collection using the specified array of objects and formatting information.
      /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks trace_information calls the trace_event methods in the trace listeners with the trace event type information, passing the message content as an object array with formatting information.
      template<typename ...objects>
      static void trace_information(const xtd::ustring& message, const objects& ... args) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::information, xtd::ustring::format(message, args...));
#endif
      }
      
      /// @brief Writes a warning message to the trace listeners in the listeners collection using the specified message.
      /// @param message The informative message to write.
      /// @remarks trace_warning calls the trace_event method for each trace listener with the trace event type Warning, passing the informative message as the message string.
      static void trace_warning(const xtd::ustring& message) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::warning, message);
#endif
      }
      /// @brief Writes a warning message to the trace listeners in the listeners collection using the specified array of objects and formatting information.
      /// @param format A format string that contains zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks trace_warning calls the trace_event methods in the trace listeners with the trace event type Warning, passing the message content as an object array with formatting information.
      template<typename ...objects>
      static void trace_warning(const xtd::ustring& message, const objects& ... args) {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        trace_event_(trace_event_type::warning, xtd::ustring::format(message, args...));
#endif
      }
      
      /// @brief Decreases the current indent_level by one.
      static void unindent();
      
      /// @brief Writes a message to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write(const xtd::ustring& message) {
#if defined(TRACE)
        write_(message);
#endif
      }
      
      /// @brief Writes a message to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write(const object& message) {
#if defined(TRACE)
        write_(xtd::ustring::format("", message));
#endif
      }
      /// @brief Writes a category name and message to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @param category A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks Use the category parameter to group output messages.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write(const object& message, const xtd::ustring& category) {
#if defined(TRACE)
        write_(xtd::ustring::format("", message), category);
#endif
      }
      /// @brief Writes a formatted string to the trace listeners in the listeners collection.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename ...args_t>
      static void write(const xtd::ustring& format, args_t&&... args) {
#if defined(TRACE)
        write_(ustring::format(format, args...));
#endif
      }
      /// @cond
      template<typename ...args_t>
      static void write(const char* format, args_t&&... args) {
#if defined(TRACE)
        write_(ustring::format(format, args...));
#endif
      }
      /// @endcond

      /// @brief Writes a message to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_if(bool condition, const xtd::ustring& message) {
#if defined(TRACE)
        if (condition) write_(message);
#endif
      }
      /// @brief Writes a message to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write_if(bool condition, const object& message) {
#if defined(TRACE)
        if (condition) write_(xtd::ustring::format("", message));
#endif
      }
      /// @brief Writes a category name and message to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @param categoory A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write_if(bool condition, const object& message, const xtd::ustring& category) {
#if defined(TRACE)
        if (condition) write_(xtd::ustring::format("", message), category);
#endif
      }

      /// @brief Writes a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_line() {
#if defined(TRACE)
        write_line_("");
#endif
      }
      /// @brief Writes a message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_line(const xtd::ustring& message) {
#if defined(TRACE)
        write_line_(message);
#endif
      }
      /// @brief Writes a message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write_line(const object& message) {
#if defined(TRACE)
        write_line_(xtd::ustring::format("", message));
#endif
      }
      /// @brief Writes a category name and message followed by a line terminator to the trace listeners in the listeners collection.
      /// @param message A message to write.
      /// @param category A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks Use the category parameter to group output messages.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write_line(const object& message, const xtd::ustring& category) {
#if defined(TRACE)
        write_line_(xtd::ustring::format("", message), category);
#endif
      }
      /// @brief Writes a formatted string followed by a line terminator to the trace listeners in the listeners collection.
      /// @param format A composite format string that contains text intermixed with zero or more format items, which correspond to objects in the args array.
      /// @param ...args An object array containing zero or more objects to format.
      /// @exception xtd::format_exception format is invalid. -or- The number that indicates an argument to format is less than zero, or greater than or equal to the number of specified objects to format.
      template<typename ...args_t>
      static void write_line(const xtd::ustring& format, args_t&&... args) {
#if defined(TRACE)
        write_line_(xtd::ustring::format(format, args...));
#endif
      }
      /// @cond
      template<typename ...args_t>
      static void write_line(const char* format, args_t&&... args) {
#if defined(TRACE)
        write_line_(xtd::ustring::format(format, args...));
#endif
      }
      /// @endcond

      /// @brief Writes a message followed by a line terminator to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      static void write_line_if(bool condition, const xtd::ustring& message) {
#if defined(TRACE)
        if (condition) write_line_(message);
#endif
      }
      /// @brief Writes a message followed by a line terminator to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write_line_if(bool condition, const object& message) {
#if defined(TRACE)
        if (condition) write_line_(xtd::ustring::format("", message));
#endif
      }
      /// @brief Writes a category name and message followed by a line terminator to the trace listeners in the Listeners collection if a condition is true.
      /// @param condition true to cause a message to be written; otherwise, false.
      /// @param message A message to write.
      /// @param categoory A category name used to organize the output.
      /// @remarks By default, the output is written to an instance of default_trace_listener.
      /// @remarks This method calls the write method of the trace listener.
      template<typename object>
      static void write_line_if(bool condition, const object& message, const xtd::ustring& category) {
#if defined(TRACE)
        if (condition) write_line_(xtd::ustring::format("", message), category);
#endif
      }
      
      /// @cond
      static inline bool __should_aborted__(bool condition) { return __should_aborted__(condition, "", csf_); }
      static inline bool __should_aborted__(bool condition, const xtd::ustring& message) { return __should_aborted__(condition, message, csf_); }
      static inline bool __should_aborted__(bool condition, const xtd::diagnostics::stack_frame& stack_frame) { return __should_aborted__(condition, "", stack_frame); }
      static inline bool __should_aborted__(bool condition, const xtd::ustring& message, const xtd::diagnostics::stack_frame& stack_frame) {
#if defined(TRACE)
        auto result = xtd::diagnostics::debug::assert_dialog(condition, message, stack_frame);
        if (result == xtd::diagnostics::assert_dialog_result::abort) xtd::environment::exit(EXIT_FAILURE);
        if (result == xtd::diagnostics::assert_dialog_result::retry) return true;
#endif
        return false;
      }
      /// @endcond

    private:
      static void fail__(const xtd::ustring& message);
      static void fail__(const xtd::ustring& message, const xtd::ustring& detail_message);
      static void flush_();
      static void trace_event_(trace_event_type trace_event_type, const xtd::ustring& message);
      static void write_(const xtd::ustring& message);
      static void write_(const xtd::ustring& message, const xtd::ustring& category);
      static void write_line_(const xtd::ustring& message);
      static void write_line_(const xtd::ustring& message, const xtd::ustring& category);

      inline static bool auto_flush_ = false;
      inline static unsigned int indent_level_ = 0;
      inline static unsigned int indent_size_ = 4;
      static listener_collection& listeners_;
      static bool& show_assert_dialog_;
      inline static bool use_global_lock_ = true;
      static std::mutex global_lock_;
      static xtd::ustring source_name_;
    };
  }
}
