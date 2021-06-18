#include <filesystem>
#include <xtd/xtd.core>
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/priority_class.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

class xtd_core_manual_test {
public:
  static void main() {
    stack_trace st;
    stack_trace st1(stack_frame(true));
    console::write_line("stack_frame : {}", st1);
    console::write_line(st);
  }
};

startup_(xtd_core_manual_test);
