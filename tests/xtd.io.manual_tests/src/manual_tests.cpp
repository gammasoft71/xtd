#include <xtd/xtd.io>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;
using namespace xtd::io;

int main(int argc, char* argv[]) {
  auto file_path = xtd::io::path::get_temp_file_name<char>();
  cout << file_path << endl;
  file::remove(file_path);
}
