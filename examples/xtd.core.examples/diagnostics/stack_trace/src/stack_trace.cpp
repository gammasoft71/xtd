#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;

namespace test_console {
  class main_class {
    static void method3() {
      console::write_line("stack_trace:");
      console::write_line(stack_trace());
    }
    
    static void method2() {
      method3();
    }
    
    static void method1() {
      method2();
    }
    
  public:
    static void main() {
      method1();
    }
  };
}

startup_(test_console::main_class);

// This code produces the following output :
//
// stack_trace:
//    at test_console::main_class::method3()
//    at test_console::main_class::method2()
//    at test_console::main_class::method1()
//    at test_console::main_class::main()
//    at main
