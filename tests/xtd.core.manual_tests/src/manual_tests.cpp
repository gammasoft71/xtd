#include <xtd/xtd.core>

using namespace std;
using namespace xtd;

int main() {
  //console::write_line("Hello, Wolrd!");
  console::write_line("{}", initializer_list<int> {1, 2, 3});
}
