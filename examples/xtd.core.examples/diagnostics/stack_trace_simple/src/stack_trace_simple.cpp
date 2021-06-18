#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class stack_trace_sample {
public:
  void my_public_method () {
    my_protected_method();
  }
  
protected:
  void my_protected_method () {
    my_internal_class mic;
    mic.throws_exception();
  }
  
private:
  class my_internal_class {
  public:
    void throws_exception() {
      try {
        throw system_exception("A problem was encountered.");
      } catch (const system_exception& e) {
        // Create a StackTrace that captures filename, line number and column information.
        stack_trace st(true);
        string stack_indent = "";
        for (size_t i = 0; i < st.frame_count(); i++) {
          // Note that at this level, there are four stack frames, one for each method invocation.
          stack_frame sf = st.get_frame(i);
          console::write_line();
          console::write_line(stack_indent + " Method: {0}", sf.get_method() );
          console::write_line(  stack_indent + " File: {0}", sf.get_file_name());
          console::write_line(  stack_indent + " Line Number: {0}", sf.get_file_line_number());
          stack_indent += "  ";
        }
        throw e;
      }
    }
  };
};

int main() {
  stack_trace_sample sample;
  try {
    sample.my_public_method();
  } catch (const system_exception&) {
    // Create a StackTrace that captures filename, line number, and column information for the current thread.
    stack_trace st(true);
    for (size_t i = 0; i < st.frame_count(); i++) {
      // Note that high up the call stack, there is only one stack frame.
      stack_frame sf = st.get_frame(i);
      console::write_line();
      console::write_line("High up the call stack, Method: {0}", sf.get_method());
      
      console::write_line("High up the call stack, Line Number: {0}", sf.get_file_line_number());
    }
  }
}

// This code produces the following output :
//
//  File: /!---OMITTED---!/stack_trace_simple
//  Line Number: 24
//
//    Method: stack_trace_sample::my_protected_method()
//    File: /!---OMITTED---!/stack_trace_simple
//    Line Number: 14
//
//      Method: stack_trace_sample::my_public_method()
//      File: /!---OMITTED---!/stack_trace_simple
//      Line Number: 9
//
//        Method: main
//        File: /!---OMITTED---!/stack_trace_simple
//        Line Number: 44
//
// High up the call stack, Method: main
// High up the call stack, Line Number: 0
