#pragma once
#include "trace_form_base.h"
#include "icontrol_trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class trace_form final : public xtd::forms::icontrol_trace, public xtd::forms::trace_form_base {
    public:
      trace_form() : trace_form_base("Trace") {
        xtd::diagnostics::trace::listeners().push_back(listener_);
#if defined(TRACE)
        visible(true);
#endif
      }
      /// @cond
      ~trace_form() {xtd::diagnostics::trace::listeners().erase(std::find(xtd::diagnostics::trace::listeners().begin(), xtd::diagnostics::trace::listeners().end(), listener_));}
      /// @endcond
      
      const xtd::diagnostics::trace_listener& trace_listener() const {return *listener_;}
      xtd::diagnostics::trace_listener& trace_listener() {return *listener_;}

      void write(const std::string& trace) override {
#if defined(TRACE)
        write_trace(trace);
#endif
      }
      void flush() override {}
      
    private:
      std::shared_ptr<xtd::diagnostics::trace_listener> listener_ = xtd::forms::control_trace_listener::create(*this);
    };
  }
}
