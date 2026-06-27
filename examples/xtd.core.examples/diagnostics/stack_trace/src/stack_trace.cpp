#include <xtd/xtd>

namespace stack_trace_example {
  class main_class {
    static void method3() {
      console::write_line("stack_trace :");
      console::write_line(diagnostics::stack_trace {true});
    }
    
    static auto method2() {
      method3();
    }
    
    static auto method1() {
      method2();
    }
    
  public:
    static auto main() {
      method1();
    }
  };
}

startup_(stack_trace_example::main_class::main);

// This code produces the following output if stack_trace consructor has true parameter :
//
// stack_trace :
//    at stack_trace_example::main_class::method3() in stack_trace.cpp:line 7
//    at stack_trace_example::main_class::method2() in stack_trace.cpp:line 12
//    at stack_trace_example::main_class::method1() in stack_trace.cpp:line 15
//    at stack_trace_example::main_class::main() in stack_trace.cpp:line 20
//    at main in stack_trace.cpp:line 25
//
//
// This code produces the following output if stack_trace consructor has no or false parameter  :
//
// stack_trace :
//    at stack_trace_example::main_class::method3()
//    at stack_trace_example::main_class::method2()
//    at stack_trace_example::main_class::method1()
//    at stack_trace_example::main_class::main()
//    at main
