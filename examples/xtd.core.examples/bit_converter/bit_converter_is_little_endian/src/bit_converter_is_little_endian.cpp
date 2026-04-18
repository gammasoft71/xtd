#include <xtd/xtd>

auto main() -> int {
  println("This example of the bit_converter::is_little_endian field generates\n"
          "the following output when run on x86-class computers.\n");
  println("is_little_endian: {}", bit_converter::is_little_endian);
}

// This code produces the following output :
//
// This example of the bit_converter::is_little_endian field generates
// the following output when run on x86-class computers.
//
// is_little_endian: true
