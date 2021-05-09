#include <xtd/xtd.tunit>
#include <iostream>

using namespace std;
using namespace xtd::tunit;

void trace_message(const string& message, const line_info& info) {
  cout << "message: " << message << endl;
  cout << "member name: " << info.member_name() << endl;
  cout << "source file path: " << info.file_path() << endl;
  cout << "source line number: " << info.line_number() << endl;
}

int main() {
  trace_message("Something happened.", line_info_);
}

// This code can produce the following output:
//
// message: Something happened.
// member name: main
// source file path: !---OMITTED---!/line_info/src/line_info.cpp
// source line number: 16
