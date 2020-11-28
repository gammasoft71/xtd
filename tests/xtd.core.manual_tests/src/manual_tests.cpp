#include <xtd/xtd.core>

using namespace xtd;


int main() {
  console::write_line("Hello, World!");
  char c = 'c';
  console::write_line(c);
  std::cout << c << std::endl;
  char8_t c8 = 'c';
  console::write_line(c8);
  std::cout << c8 << std::endl;
  
  c = c8;
}
