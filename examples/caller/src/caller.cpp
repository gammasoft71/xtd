#include <xtd/tunit>
#include <iostream>

using namespace std;
using namespace xtd::tunit;

void trace_message(const string& message, const caller& caller) {
  cout << "message: " << message << endl;
  cout << "member name: " << caller.member_name() << endl;
  cout << "source file path: " << caller.file_path() << endl;
  cout << "source line number: " << caller.line_number() << endl;
}

// The main entry point for the application.
int main() {
  trace_message("Something happened.", caller_);
}

// This code can produce the following output:
//
// message: Something happened.
// member name: main
// source file path: /Users/UserName/Projects/xtd/xtd.tunit/examples/caller/src/caller.cpp
// source line number: 18
