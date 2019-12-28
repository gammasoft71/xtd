#include <xtd/xtd.core>
#include <xtd/xtd.strings>
#include <iostream>

using namespace std;
using namespace xtd;

class foo {
public:
  // The main entry point for the application.
  static void main(const std::vector<std::string>& args) {
    cout << format("command line = {}", environment::command_line()) << endl;
    cout << format("command line args = {}", strings::join(", ", environment::get_command_line_args())) << endl;
    cout << format("command line without args = {}", environment::get_command_line_args()[0]) << endl;
    cout << format("args = {}", strings::join(", ", args)) << endl;
  }
};

startup_(foo);

// This code produces the following output :
//
// >startup one two three "four five" six
//
// command line = |---OMITTED---|/startup one two three four five six
// command line args = |---OMITTED---|/startup, one, two, three, four five, six
// command line without args = |---OMITTED---|/startup
// args = one, two, three, four five, six
