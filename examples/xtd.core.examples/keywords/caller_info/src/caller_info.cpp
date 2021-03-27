#include <xtd/xtd>

using namespace std;
using namespace xtd;

void trace_message(const string& message, const caller_info& info) {
  console::write_line("message: {}", message);
  console::write_line("member name: {}", info.member_name());
  console::write_line("member file path: {}", info.file_path());
  console::write_line("member line number: {}", info.line_number());
}

int main() {
  trace_message("Something happened.", caller_info_);
}

// This code can produce the following output:
//
// message: Something happened.
// member name: main
// source file path: /Users/UserName/Projects/xtd/examples/xtd.core.examples/keywords/caller_info/src/caller_info.cpp
// source line number: 14
