/// @file
/// @brief Contains xtd::forms::debug_form form.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control_trace_listener.h"
#include "trace_form_base.h"
#include "icontrol_trace.h"
#include <xtd/diagnostics/debug>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a form that displays debug form. This class cannot be inherited.
    /// @par Header
    /// @code #include <xtd/forms/debug_form> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms debug
    /// @remarks This form is used in a development phase to trace all written debug with xtd::diagnostics::debug class.
    /// @remarks You must enable debug mode to use a debug form. The syntax is compiler specific. If you use other than cmake to manage your build, refer to the documentation of your build manager.
    ///  * To enable debug mode with cmake, add the add_definitions(-DDEBUG) command line in the CMakeLists.txt of your project, or you can add #define DEBUG to the top of your file.
    /// @remarks To activate your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if defined(DEBUG) ... #endif block, and add the /DDEBUG option to the compiler command line or add #define DEBUG to the file.
    /// @par Appearance
    /// |       | Windows                              | macOS                                | Gnome                                |
    /// | ----- | ------------------------------------ | ------------------------------------ | ------------------------------------ |
    /// | Light |  @image html form_debug_form_w.png   |  @image html form_debug_form_m.png   |  @image html form_debug_form_g.png   |
    /// | Dark  |  @image html form_debug_form_wd.png  |  @image html form_debug_form_md.png  |  @image html form_debug_form_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of debug_form form.
    /// @include debug_form.cpp
    class debug_form final : public xtd::forms::icontrol_trace, public xtd::forms::trace_form_base {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the debug_form class.
      debug_form() : trace_form_base("Debug") {
        xtd::diagnostics::debug::listeners().push_back(listener_);
        #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        visible(true);
        defined = true;
        #endif
      }
      /// @}
      
      /// @cond
      ~debug_form();
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
      void flush() override;
      
      void write(const xtd::ustring& debug) override {
        if (!defined) return;
        trace_form_base::write(debug);
      }
      void write_line(const xtd::ustring& debug) override {
        if (!defined) return;
        trace_form_base::write_line(debug);
      }
      /// @}

    protected:
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      std::unique_ptr<xtd::object> clone() const override;      
      /// @}
      
    private:
      std::shared_ptr<xtd::diagnostics::trace_listener> listener_ = xtd::forms::control_trace_listener::create(*this);
      bool defined = false;
    };
  }
}
