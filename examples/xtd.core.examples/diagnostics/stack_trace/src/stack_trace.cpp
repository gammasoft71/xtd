#include <xtd/diagnostics/stack_trace>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::diagnostics;

namespace stack_trace_example {
  class main_class {
    static void method3() {
      console::write_line("stack_trace:");
      console::write_line(stack_trace {});
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

startup_(stack_trace_example::main_class::main);

// This code produces the following output :
//
// stack_trace:
//    at stack_trace_example::main_class::method3()
//    at stack_trace_example::main_class::method2()
//    at stack_trace_example::main_class::method1()
//    at stack_trace_example::main_class::main()
//    at main
