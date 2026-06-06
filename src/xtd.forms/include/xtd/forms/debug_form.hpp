/// @file
/// @brief Contains xtd::forms::debug_form form.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control_trace_listener.hpp"
#include "trace_form_base.hpp"
#include "icontrol_trace.hpp"
#include <xtd/diagnostics/debug>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a form that displays debug form. This class cannot be inherited.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/debug_form>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms debug
    /// @remarks This form is used in a development phase to trace all written debug with xtd::diagnostics::debug class.
    /// @remarks To disable debug mode with CMake, add the command line `add_definitions(-DNDEBUG)` in your CMakeLists.txt, or define NDEBUG at the top of your file.
    /// @note If you define `#define DEBUG` above your includes, debug mode will still be active even if NDEBUG is defined.
    /// @remarks To activate your code if DEBUG is defined, you must enclose calls to the methods of Debug in an #if DEBUG ... #endif block.
    /// @par Appearance
    /// |       | Windows                              | macOS                                | Gnome                                |
    /// | ----- | ------------------------------------ | ------------------------------------ | ------------------------------------ |
    /// | Light |  @image html form_debug_form_w.png   |  @image html form_debug_form_m.png   |  @image html form_debug_form_g.png   |
    /// | Dark  |  @image html form_debug_form_wd.png  |  @image html form_debug_form_md.png  |  @image html form_debug_form_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of debug_form form.
    /// @include debug_form.cpp
    class debug_form final : public xtd::forms::icontrol_trace, public xtd::forms::trace_form_base {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the debug_form class.
      debug_form() : trace_form_base("Debug") {
        xtd::diagnostics::debug::listeners().add(listener_);
        #if DEBUG
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
      [[nodiscard]] auto trace_listener() const noexcept -> const xtd::diagnostics::trace_listener&;
      /// @brief Gets underlying trace listener.
      /// @return A xtd::diagnostics::trace_listener trace listener. In this case a xtd::forms::control_trace_listener.
      [[nodiscard]] auto trace_listener() -> xtd::diagnostics::trace_listener&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      auto flush() -> void override;
      
      auto write(const xtd::string& debug) -> void override {
        if (!defined) return;
        trace_form_base::write(debug);
      }
      
      auto write_line(const xtd::string& debug) -> void override {
        if (!defined) return;
        trace_form_base::write_line(debug);
      }
      /// @}
      
    private:
      xtd::sptr<xtd::diagnostics::trace_listener> listener_ = xtd::forms::control_trace_listener::create(*this);
      bool defined = false;
    };
  }
}
