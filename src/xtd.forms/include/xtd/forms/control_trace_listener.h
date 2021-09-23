/// @file
/// @brief Contains xtd::forms::control_trace_listener listener.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/diagnostics/trace_listener.h>
#include "icontrol_trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Directs tracing or debugging output to either icontrol_trace.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    /// @par Examples
    class control_trace_listener : public xtd::diagnostics::trace_listener {
    public:
      /// @brief Initializes a new instance of the control_trace_listener class with specified control_trace.
      /// @param control_trace A controll that hinerits to the icontrol_trace interface.
      /// @see see xtd::forms::icontrol_trace interface.
      control_trace_listener(xtd::forms::icontrol_trace& control_trace) : control_trace_(&control_trace) {}
      /// @cond
      ~control_trace_listener() {flush();}
      /// @endcond
      
      /// @brief Get icontroll_trace object.
      /// @return The icontrol_trace object used.
      virtual xtd::forms::icontrol_trace& control_trace() {return *control_trace_;}
      /// @brief Set icontroll_trace object.
      /// @param control_trace The icontrol_trace object to use.
      virtual void control_trace(xtd::forms::icontrol_trace& control_trace) {control_trace_ = &control_trace;}

      /// @brief Create new control_trace_listener.
      /// @return New created trace listener.
      static std::shared_ptr<xtd::diagnostics::trace_listener> create(xtd::forms::icontrol_trace& control_trace) {return std::make_shared<control_trace_listener>(control_trace);}

      void close() override { }

      void flush() override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (control_trace_) control_trace_->flush();
#endif
      }
      
      using trace_listener::write;
      /// @brief Writes the message to the listener you create when you implement the trace_listener class.
      /// @param message A string you want to write.
      void write(const xtd::ustring& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (need_indent()) write_indent();
        if (control_trace_) control_trace_->write(message);
#endif
      }
      
      using trace_listener::write_line;
      /// @brief Writes the message to the listener you create when you implement the trace_listener class.
      /// @param message A string you want to write.
      void write_line(const xtd::ustring& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        //write(message + "\n");
        if (need_indent()) write_indent();
        if (control_trace_) control_trace_->write_line(message);
        need_indent(true);
#endif
      }
      
    private:
      xtd::forms::icontrol_trace* control_trace_ = nullptr;
    };
  }
}
