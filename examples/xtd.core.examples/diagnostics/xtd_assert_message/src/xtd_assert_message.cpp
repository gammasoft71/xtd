#include <xtd/xtd>

using namespace xtd;

int main() {
  // Uncomment following line to remove assert dialog
  //diagnostics::debug::show_assert_dialog(false);
  
  auto index = 0;
  console::write_line("Start application");
  xtd_assert_message(index > 0, "index must be greater than 0");
  console::write_line("End application");
}

// This code produces the following output :
//
// > If user clicks assert dialog 'Abort' button:
// Start application
//
// > If user clicks assert dialog 'Retry' button:
// Start application
// > Break the debugger on file xtd_assert.cpp line 9.
//
// > If user clicks assert dialog 'Ignore' button:
// Start application
// End application
