#include <xtd/xtd.tunit>
#include <iostream>

using namespace std;
using namespace xtd::diagnostics;
using namespace xtd::tunit;

void trace_message(const string& message, const stack_frame& sf) {
  cout << "message: " << message << endl;
  cout << "member name: " << sf.get_method() << endl;
  cout << "source file path: " << sf.get_file_name() << endl;
  cout << "source line number: " << sf.get_file_line_number() << endl;
}

int main() {
  trace_message("Something happened.", csf_);
}

// This code can produce the following output:
//
// message: Something happened.
// member name: main
// source file path: !---OMITTED---!/line_info/src/line_info.cpp
// source line number: 16
