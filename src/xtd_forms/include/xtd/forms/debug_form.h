#pragma once
#include "form.h"
#include "icontrol_trace.h"
#include "text_box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class debug_form : public xtd::forms::icontrol_trace, public xtd::forms::form {
    public:
      debug_form() {
        xtd::diagnostics::debug::listeners().push_back(listener_);
        dock(xtd::forms::dock_style::bottom);
        start_position(xtd::forms::form_start_position::manual);
        text("Debug form").visible(true);
        text_.multiline(true).read_only(true).word_wrap(false).parent(*this).dock(xtd::forms::dock_style::fill);
      }
      
      /// @cond
      ~debug_form() {xtd::diagnostics::debug::listeners().erase(std::find(xtd::diagnostics::debug::listeners().begin(), xtd::diagnostics::debug::listeners().end(), listener_));}
      /// @endcond
      
      xtd::forms::control& dock(xtd::forms::dock_style dock) override {
        if (dock == xtd::forms::dock_style::left) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).height()});
        else if (dock == xtd::forms::dock_style::top) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height() / 4});
        else if (dock == xtd::forms::dock_style::right) bounds({xtd::forms::screen::get_working_area(handle_).left() + xtd::forms::screen::get_working_area(handle_).width() - xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width() / 4, xtd::forms::screen::get_working_area(handle_).height()});
        else if (dock == xtd::forms::dock_style::bottom) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top() + xtd::forms::screen::get_working_area(handle_).height() - xtd::forms::screen::get_working_area(handle_).height() / 4, xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height() / 4});
        else if (dock == xtd::forms::dock_style::fill) bounds({xtd::forms::screen::get_working_area(handle_).left(), xtd::forms::screen::get_working_area(handle_).top(), xtd::forms::screen::get_working_area(handle_).width(), xtd::forms::screen::get_working_area(handle_).height()});
        return xtd::forms::control::dock(dock);
      }
      
      void write(const std::string& log_str) override {
  #if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        text_.append_text(log_str);
  #endif
      }
      void flush() override {}
      
    private:
      xtd::forms::text_box text_;
      std::shared_ptr<xtd::diagnostics::trace_listener> listener_ = xtd::forms::control_trace_listener::create(*this);
    };
  }
}
