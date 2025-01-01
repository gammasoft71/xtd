/// @file
/// @brief Contains xtd::forms::trace_form dialog.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "control_trace_listener.hpp"
#include "icontrol_trace.hpp"
#include "trace_form_base.hpp"
#include <xtd/diagnostics/trace>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a form that displays trace form.  This class cannot be inherited.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/trace_form>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms debug
    /// @remarks This form is used in a development phase to trace all written trace with xtd::diagnostics::trace class.
    /// @remarks You must enable debug mode to use a trace listener. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build manager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your project, or you can add #define DEBUG to the top of your file.
    /// @remarks To activate your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
    /// @par Appearance
    /// |       | Windows                              | macOS                                | Gnome                                |
    /// | ----- | ------------------------------------ | ------------------------------------ | ------------------------------------ |
    /// | Light |  @image html form_trace_form_w.png   |  @image html form_trace_form_m.png   |  @image html form_trace_form_g.png   |
    /// | Dark  |  @image html form_trace_form_wd.png  |  @image html form_trace_form_md.png  |  @image html form_trace_form_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of trace_form form.
    /// @include trace_form.cpp
    class trace_form final : public xtd::forms::icontrol_trace, public xtd::forms::trace_form_base {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the trace_form class.
      trace_form() : trace_form_base("Trace") {
        xtd::diagnostics::trace::listeners().push_back(listener_);
        #if defined(TRACE)
        visible(true);
        defined = true;
        #endif
      }
      /// @}
      
      /// @cond
      ~trace_form();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets underlying trace listener.
      /// @return A xtd::diagnostics::trace_listener trace listener. In this case a xtd::forms::control_trace_listener.
      const xtd::diagnostics::trace_listener& trace_listener() const noexcept;
      /// @brief Gets underlying trace listener.
      /// @return A xtd::diagnostics::trace_listener trace listener. In this case a xtd::forms::control_trace_listener.
      xtd::diagnostics::trace_listener& trace_listener();
      /// @}
      
      /// @name Public Methods
      
      /// @{
      void write(const xtd::string& trace) override {
        if (!defined) return;
        trace_form_base::write(trace);
      }
      void write_line(const xtd::string& trace) override {
        if (!defined) return;
        trace_form_base::write_line(trace);
      }
      
      void flush() override;
      /// @}

    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      xtd::uptr<xtd::object> clone() const override;
      /// @}
      
    private:
      xtd::sptr<xtd::diagnostics::trace_listener> listener_ = xtd::forms::control_trace_listener::create(*this);
      bool defined = false;
    };
  }
}
