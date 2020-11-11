#include <xtd/xtd.io>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd::io;

// The main entry point for the application.
int main(int argc, char* argv[]) {
  string file_name = path::combine(path::get_temp_path(), "file.txt");
  
  file::write_all_text(file_name, "Hello, World!");
  cout << file::read_all_text(file_name) << endl;
  
  file::remove(file_name);
}

// This code produces the following output:
//
// Hello, World!
