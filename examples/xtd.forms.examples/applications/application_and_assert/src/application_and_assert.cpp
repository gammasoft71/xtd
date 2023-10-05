#include <xtd/diagnostics/assert>
#include <xtd/diagnostics/debug>
#include <xtd/diagnostics/debug_break>
#include <xtd/diagnostics/debugger>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class main_form : public form {
public:
  static auto main() {
    application::run(main_form());
  }
  
  main_form() {
    text("application and assert example");
    
    // Uncomment following line to remove assert dialog
    //debug::show_assert_dialog(false);
    
    generate_assert_button.auto_size(true);
    generate_assert_button.location({10, 10});
    generate_assert_button.parent(*this);
    generate_assert_button.text("Generate assert_");
    generate_assert_button.click += event_handler(*this, &main_form::generate_assert);
    
    generate_debug_dassert_button.auto_size(true);
    generate_debug_dassert_button.location({10, 50});
    generate_debug_dassert_button.parent(*this);
    generate_debug_dassert_button.text("Generate debug::cassert_");
    generate_debug_dassert_button.click += event_handler(*this, &main_form::generate_debug_cassert);
    
    generate_debug_break_button.auto_size(true);
    generate_debug_break_button.location({10, 90});
    generate_debug_break_button.parent(*this);
    generate_debug_break_button.text("Generate debug_break_");
    generate_debug_break_button.click += event_handler(*this, &main_form::generate_debug_break);
    
    generate_debugger_debug_break_button.auto_size(true);
    generate_debugger_debug_break_button.location({10, 130});
    generate_debugger_debug_break_button.parent(*this);
    generate_debugger_debug_break_button.text("Generate debugger::debug break");
    generate_debugger_debug_break_button.click += event_handler(*this, &main_form::generate_debugger_debug_break);
  }
  
private:
  void generate_assert() {
    auto index = 0;
    assert_(index > 0, "Out of range", "Index must be greather than 0");
  }
  
  void generate_debug_cassert() {
    auto index = 0;
    debug::cassert_(index > 0, "Out of range", "Index must be greather than 0");
  }
  
  void generate_debug_break() {
    debug_break_();
  }
  
  void generate_debugger_debug_break() {
    debugger::debug_break();
  }
  
  button generate_assert_button;
  button generate_debug_dassert_button;
  button generate_debug_break_button;
  button generate_debugger_debug_break_button;
};

startup_(main_form::main);
