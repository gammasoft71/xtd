#include <xtd/xtd.console>

int main(int argc, char* argv[]) {
  auto number = 1024;
  
  xtd::console::write_line("number '{}' :", number);
  xtd::console::write_line("  binary 0b{:B16}", number);
  xtd::console::write_line("  octal \\{:O}", number);
  xtd::console::write_line("  decimal {:D}", number);
  xtd::console::write_line("  hexa 0x{:X4}", number);
}
