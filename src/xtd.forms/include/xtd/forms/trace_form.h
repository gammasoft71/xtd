/// @file
/// @brief Contains xtd::forms::trace_form dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "trace_form_base.h"
#include "icontrol_trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a form that displays trace form.  This class cannot be inherited.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms debug
    /// @remarks This form is used in a development phase to trace all written trace with xtd::diagnostics::trace class.
    /// @remarks You must enable debug mode to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build manager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your project, or you can add #define DEBUG to the top of your file.
    /// @remarks To activate your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
    /// @par Examples
    /// The following code example demonstrate the use of trace_form form.
    /// @include trace_form.cpp
    class trace_form final : public xtd::forms::icontrol_trace, public xtd::forms::trace_form_base {
    public:
      /// @brief Initializes a new instance of the trace_form class.
      trace_form() : trace_form_base("Trace") {
        xtd::diagnostics::trace::listeners().push_back(listener_);
#if defined(TRACE)
        visible(true);
#endif
      }
      /// @cond
      ~trace_form() {xtd::diagnostics::trace::listeners().erase(std::find(xtd::diagnostics::trace::listeners().begin(), xtd::diagnostics::trace::listeners().end(), listener_));}
      /// @endcond
      
      /// @brief Gets underlying trace listener.
      /// @return A xtd::diagnostics::trace_listener trace listener. In this case a xtd::forms::control_trace_listener.
      const xtd::diagnostics::trace_listener& trace_listener() const {return *listener_;}
      /// @brief Gets underlying trace listener.
      /// @return A xtd::diagnostics::trace_listener trace listener. In this case a xtd::forms::control_trace_listener.
      xtd::diagnostics::trace_listener& trace_listener() {return *listener_;}

      void write(const xtd::ustring& trace) override {
#if defined(TRACE)
        trace_form_base::write(trace);
#endif
      }
      void write_line(const xtd::ustring& trace) override {
#if defined(TRACE)
        trace_form_base::write_line(trace);
#endif
      }
      
      void flush() override {}
      
    private:
      std::shared_ptr<xtd::diagnostics::trace_listener> listener_ = xtd::forms::control_trace_listener::create(*this);
    };
  }
}
