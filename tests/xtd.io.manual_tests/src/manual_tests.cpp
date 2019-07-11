#include <xtd/xtd.io>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd::io;

int main(int argc, char* argv[]) {
  cout << xtd::io::path::get_file_name("c:\\temp\\File.ext") << endl;
  cout << xtd::io::path::get_file_name("/temp/File.ext") << endl;
}
