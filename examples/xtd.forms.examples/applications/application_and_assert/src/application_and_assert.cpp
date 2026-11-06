#include <xtd/xtd>
#include <version>
#if __cpp_lib_debugging
#include <debugging>
#endif

class main_form : public form {
public:
  static auto main() {
    application::run(main_form());
  }
  
  main_form() {
    text("application and assert example");
    client_size({400, 250});
    
    generate_debug_assert_button.auto_size(true);
    generate_debug_assert_button.location({10, 10});
    generate_debug_assert_button.parent(*this);
    generate_debug_assert_button.text("Generate xtd::diagnostics::debug::assert()");
    generate_debug_assert_button.click += event_handler(*this, &main_form::generate_debug_assert);
    
    generate_breakpoint_button.auto_size(true);
    generate_breakpoint_button.location({10, 50});
    generate_breakpoint_button.parent(*this);
    generate_breakpoint_button.text("Generate std::breakpoint()");
    generate_breakpoint_button.click += event_handler(*this, &main_form::generate_breakpoint);
#if __cpp_lib_debugging
    generate_breakpoint_button.enabled(true);
#else
    generate_breakpoint_button.enabled(false);
#endif
    
    generate_debugger_debug_break_button.auto_size(true);
    generate_debugger_debug_break_button.location({10, 90});
    generate_debugger_debug_break_button.parent(*this);
    generate_debugger_debug_break_button.text("Generate xtd::diagnostics::debugger::debug break()");
    generate_debugger_debug_break_button.click += event_handler(*this, &main_form::generate_debugger_debug_break);
    
    show_assert_dialog_check_box.auto_size(true);
    for (auto listener : diagnostics::debug::listeners())
      if (is<diagnostics::default_trace_listener>(listener) && as<diagnostics::default_trace_listener>(listener)->assert_ui_enabled())
        show_assert_dialog_check_box.checked(true);
    show_assert_dialog_check_box.location({10, 190});
    show_assert_dialog_check_box.parent(*this);
    show_assert_dialog_check_box.text("Show assert dialog");
    show_assert_dialog_check_box.click += event_handler(*this, &main_form::show_assert_dialog);
  }
  
private:
  void generate_debug_assert() {
    auto index = 0;
    diagnostics::debug::assert(index > 0, "Out of range", "Index must be greater than 0");
  }
  
  void generate_breakpoint() {
#if __cpp_lib_debugging
    std::breakpoint_if_debugging(); // Same as : if (std::is_debugger_present()) std::breakpoint();
#endif
  }
  
  void generate_debugger_debug_break() {
    diagnostics::debugger::debug_break();
  }
  
  void show_assert_dialog() {
    for (auto listener : diagnostics::debug::listeners())
      if (is<diagnostics::default_trace_listener>(listener))
        as<diagnostics::default_trace_listener>(listener)->assert_ui_enabled(show_assert_dialog_check_box.checked());
  }

  button generate_debug_assert_button;
  button generate_breakpoint_button;
  button generate_debugger_debug_break_button;
  check_box show_assert_dialog_check_box;
};

startup_(main_form::main);
