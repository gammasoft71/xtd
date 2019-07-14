/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides a set of methods and properties that help you debug the execution of your code. This class cannot be inherited.
    /// @remarks You can use the properties and methods in the debug class to instrument release builds. Instrumentation allows you to monitor the health of your application running in real-life settings. Tracing helps you isolate problems and fix them without disturbing a running system.
    /// @remarks This class provides methods to display an assert dialog box, and to emit an assertion that will always Fail. This class provides write methods in the following variations: write, write_line, write_if, and write_line_if.
    /// @remarks The boolean_switch and trace_switch classes provide means to dynamically control the tracing output. You can modify the values of these switches without recompiling your application. For information on using the configuration file to set a switch, see the switch class and the trace_switches topic.
    /// @remarks You can customize the tracing output's target by adding trace_listener instances to or removing instances from the listeners collection. The listeners collection is shared by both the debug and the trace classes; adding a trace listener to either class adds the listener to both. By default, trace output is emitted using the default_trace_listener class.
    /// @note Adding a trace listener to the listeners collection can cause an exception to be thrown while tracing, if a resource used by the trace listener is not available. The conditions and the exception thrown depend on the trace listener and cannot be enumerated in this topic. It may be useful to place calls to the debug methods in try/catch blocks to detect and handle any exceptions from trace listeners.
    /// @remarks The debug class provides properties to get or set the level of indent, the indent_size, and whether to auto_flush after each write.
    /// @remarks You must enable debug mode to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build nanager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your porject, or you can add #define DEBUG to the top of your file.
    /// @remarks To activete your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
    /// @par Examples
    /// The following example uses debug to indicate the beginning and the end of a program's execution. The example also uses the debug::indent and debug::unindent methods to distinguish the tracing output.
    /// @include debug.cpp
    class debug {
    public:
      
    private:
      debug() = delete;
    };
  }
}
