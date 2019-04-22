#include <xtd/environment>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

// The main entry point for the application.
int main() {
  //cout << "Hello, World!" << endl;
  cout << "Hello, " << environment::user_name() << "!" << endl;
  cout << "desktop = " << environment::get_folder_path(environment::special_folder::desktop) << endl;
}

// This code produces the following output with colors:
//
// Hello, World!
