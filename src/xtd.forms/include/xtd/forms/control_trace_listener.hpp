/// @file
/// @brief Contains xtd::forms::control_trace_listener listener.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "icontrol_trace.hpp"
#include <xtd/diagnostics/trace_listener>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Directs tracing or debugging output to a icontrol_trace object.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/control_trace_listener>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    /// @par Examples
    /// @remarks To disable debug mode with CMake, add the command line `add_definitions(-DNDEBUG)` in your CMakeLists.txt, or define NDEBUG at the top of your file.
    /// @note If you define `#define DEBUG` above your includes, debug mode will still be active even if NDEBUG is defined.
    /// @remarks To activate your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block.
    /// @remarks To disable trace mode with CMake, add the command line `add_definitions(-DNTRACE)` in your CMakeLists.txt, or define NTRACE at the top of your file.
    /// @note If you define `#define TRACE` above your includes, trace mode will still be active even if NTRACE is defined.
    /// @remarks To activate your code if TRACE is defined, you must enclose calls to the methods of Debug in an #if defined(TRACE) ... #endif block.
    class control_trace_listener : public xtd::diagnostics::trace_listener {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the control_trace_listener class with specified control_trace.
      /// @param control_trace A control that inherits to the icontrol_trace interface.
      /// @see see xtd::forms::icontrol_trace interface.
      control_trace_listener(xtd::forms::icontrol_trace& control_trace) : control_trace_(&control_trace) {}
      /// @}
      
      /// @cond
      ~control_trace_listener() {flush();}
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets icontroll_trace object.
      /// @return The icontrol_trace object used.
      virtual xtd::forms::icontrol_trace& control_trace() noexcept {return *control_trace_;}
      /// @brief Sets icontroll_trace object.
      /// @param control_trace The icontrol_trace object to use.
      virtual void control_trace(xtd::forms::icontrol_trace& control_trace) {control_trace_ = &control_trace;}
      /// @}
      
      /// @name Public Methods
      
      /// @{
      void close() override { }
      
      void flush() override {
        #if defined(DEBUG) || defined(TRACE)
        if (control_trace_) control_trace_->flush();
        #endif
      }
      
      using trace_listener::write;
      /// @brief Writes the message to the listener you create when you implement the trace_listener class.
      /// @param message A string you want to write.
      void write(const xtd::string& message) override {
        #if defined(DEBUG) || defined(TRACE)
        if (need_indent()) write_indent();
        if (control_trace_) control_trace_->write(message);
        #endif
      }
      
      using trace_listener::write_line;
      /// @brief Writes the message to the listener you create when you implement the trace_listener class.
      /// @param message A string you want to write.
      void write_line(const xtd::string& message) override {
        #if defined(DEBUG) || defined(TRACE)
        //write(message + "\n");
        if (need_indent()) write_indent();
        if (control_trace_) control_trace_->write_line(message);
        need_indent(true);
        #endif
      }
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create new control_trace_listener.
      /// @return New created trace listener.
      static xtd::sptr<xtd::diagnostics::trace_listener> create(xtd::forms::icontrol_trace& control_trace) {return xtd::new_sptr<control_trace_listener>(control_trace);}
      /// @}
      
    private:
      xtd::forms::icontrol_trace* control_trace_ = nullptr;
    };
  }
}
