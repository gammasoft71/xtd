#include <xtd/xtd>

auto trace_message(const string& message, const diagnostics::stack_frame& sf = diagnostics::stack_frame::current()) -> void {
  console::out << "message: " << message << environment::new_line;
  console::out << "member name: " << sf.get_method() << environment::new_line;
  console::out << "source file path: " << sf.get_file_name() << environment::new_line;
  console::out << "source line number: " << sf.get_file_line_number() << environment::new_line;
}

auto main() -> int {
  trace_message("Something happened.");
}

// This code can produce the following output :
//
// message: Something happened.
// member name: main
// source file path: !---OMITTED---!/line_info/src/line_info.cpp
// source line number: 11
