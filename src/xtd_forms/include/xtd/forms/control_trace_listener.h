#pragma once
#include <xtd/diagnostics/trace_listener.h>
#include "icontrol_trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class control_trace_listener : public xtd::diagnostics::trace_listener {
    public:
      control_trace_listener(xtd::forms::icontrol_trace& control_trace) : control_trace_(&control_trace) {}
      ~control_trace_listener() {flush();}
      
      virtual xtd::forms::icontrol_trace& control_trace() {return *control_trace_;}
      virtual void control_trace(xtd::forms::icontrol_trace& control_trace) {control_trace_ = &control_trace;}
      
      static std::shared_ptr<xtd::diagnostics::trace_listener> create(xtd::forms::icontrol_trace& control_trace) {return std::make_shared<control_trace_listener>(control_trace);}
      
      void close() override { }
      void flush() override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (control_trace_) control_trace_->flush();
#endif
      }
      
      using trace_listener::write;
      void write(const std::string& message) override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (need_indent()) write_indent();
        if (control_trace_) control_trace_->write(message);
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
      xtd::forms::icontrol_trace* control_trace_ = nullptr;
    };
  }
}
