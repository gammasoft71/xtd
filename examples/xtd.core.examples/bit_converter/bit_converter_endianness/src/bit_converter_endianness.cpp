#include <xtd/xtd>

auto main() -> int {
  println("This example of the bit_converter::endianness field generates\n"
          "the following output when run on x86-class computers.\n");
  println("endianness: {}", bit_converter::endianness);
}

// This code produces the following output :
//
// This example of the bit_converter::endianness field generates
// the following output when run on x86-class computers.
//
// endianness: little
