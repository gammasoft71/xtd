#include <xtd/diagnostics/stack_frame>
#include <xtd/diagnostics/stack_trace>
#include <xtd/console>

using namespace xtd;
using namespace xtd::diagnostics;

void method2(int count) {
  try {
    if (count < 5)
      throw argument_exception("count too large", "count");
  } catch (const system_exception&) {
    auto st = stack_trace {};
    auto st1 = stack_trace {stack_frame {2, true}};
    console::write_line(" Stack trace for Method2: {0}", st1.to_string());
    console::write_line(st.to_string());
    throw;
  }
}

void method1() {
  try {
    method2(4);
  } catch (const system_exception&) {
    auto st = stack_trace {};
    auto st1 = stack_trace {stack_frame {true}};
    console::write_line(" Stack trace for Method1: {0}", st1.to_string());
    console::write_line(st.to_string());
    // Build a stack trace for the next frame.
    auto st2 = stack_trace {stack_frame {1, true}};
    console::write_line(" Stack trace for next level frame: {0}", st2.to_string());
    throw;
  }
}

auto main() -> int {
  try {
    method1();
  } catch (const system_exception&) {
    auto st = stack_trace {};
    auto st1 = stack_trace {stack_frame {true}};
    console::write_line(" Stack trace for Main: {0}", st1.to_string());
    console::write_line(st.to_string());
  }
  console::write_line("Press Enter to exit.");
  console::read_key();
}

// This code produces the following output :
//
//  Stack trace for Method2:    at main [0x000030B0] in /!---OMITTED---!/stack_frame:line 0
//    at method2(int)
//    at method1()
//    at main
//  Stack trace for Method1:    at method1() [0x00002D20] in /!---OMITTED---!/stack_frame:line 0
//    at method1()
//    at main
//  Stack trace for next level frame:    at main [0x000030B0] in /!---OMITTED---!/stack_frame:line 0
//  Stack trace for Main:    at main [0x000030B0] in /!---OMITTED---!/stack_frame:line 0
//    at main
// Press Enter to exit.
