#pragma once
#include "trace_form_base.h"
#include "icontrol_trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class debug_form final : public xtd::forms::icontrol_trace, public xtd::forms::trace_form_base {
    public:
      debug_form() : trace_form_base("Debug") {xtd::diagnostics::debug::listeners().push_back(listener_);}
      /// @cond
      ~debug_form() {xtd::diagnostics::debug::listeners().erase(std::find(xtd::diagnostics::debug::listeners().begin(), xtd::diagnostics::debug::listeners().end(), listener_));}
      /// @endcond
      
      const xtd::diagnostics::trace_listener& trace_listener() const {return *listener_;}
      xtd::diagnostics::trace_listener& trace_listener() {return *listener_;}
      
      void write(const std::string& debug) override {
  #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        write_trace(debug);
  #endif
      }
      void flush() override {}
      
    private:
      std::shared_ptr<xtd::diagnostics::trace_listener> listener_ = xtd::forms::control_trace_listener::create(*this);
    };
  }
}
