#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void trace_message(const string& message, const stack_frame& sf) {
  console::out << "message: " << message << environment::new_line;
  console::out << "member name: " << sf.get_method() << environment::new_line;
  console::out << "source file path: " << sf.get_file_name() << environment::new_line;
  console::out << "source line number: " << sf.get_file_line_number() << environment::new_line;
}

auto main() -> int {
  trace_message("Something happened.", csf_);
}

// This code can produce the following output :
//
// message: Something happened.
// member name: main
// source file path: !---OMITTED---!/line_info/src/line_info.cpp
// source line number: 16
