#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::diagnostics;

int main() {
  process_start_info start_info("args_echo");

  // Start with one argument.
  // Output of args_echo:
  //  [0]=/a
  start_info.arguments("/a");
  process::start(start_info).wait_for_exit();
  
  // Start with multiple arguments separated by spaces.
  // Output of ArgsEcho:
  //  [0] = /a
  //  [1] = /b
  //  [2] = c:\temp
  start_info.arguments("/a /b c:\\temp");
  process::start(start_info).wait_for_exit();
  
  // An argument with spaces inside quotes is interpreted as multiple arguments.
  // Output of ArgsEcho:
  //  [0] = /a
  //  [1] = literal string arg
  start_info.arguments("/a \"literal string arg\"");
  process::start(start_info).wait_for_exit();
  
  // An argument inside double quotes is interpreted as if the quote weren't there,
  // that is, as separate arguments. Equivalent verbatim string is @"/a /b:""string with quotes"""
  // Output of ArgsEcho:
  //  [0] = /a
  //  [1] = /b:string
  //  [2] = in
  //  [3] = double
  //  [4] = quotes
  start_info.arguments("/a /b:\"\"string in double quotes\"\"");
  process::start(start_info).wait_for_exit();
  
  // Triple-escape quotation marks to include the character in the final argument received
  // by the target process. Equivalent verbatim string: @"/a /b:""""""quoted string""""""";
  //  [0] = /a
  //  [1] = /b:"quoted string"
  start_info.arguments("/a /b:\"\"\"quoted string\"\"\"");
  process::start(start_info).wait_for_exit();
}

// This code produces the following output :
//
//
// Received the following arguments:
//
// [0] = /a
//
// Received the following arguments:
//
// [0] = /a
// [1] = /b
// [2] = c:\temp
//
// Received the following arguments:
//
// [0] = /a
// [1] = literal string arg
//
// Received the following arguments:
//
// [0] = /a
// [1] = /b:string
// [2] = in
// [3] = double
// [4] = quotes
//
// Received the following arguments:
//
// [0] = /a
// [1] = /b:"quoted string"
//
