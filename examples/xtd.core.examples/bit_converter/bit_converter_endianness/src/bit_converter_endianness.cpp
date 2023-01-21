#include <xtd/xtd>

using namespace xtd;

namespace examples {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      console::write_line(
        "This example of the bit_converter::endianness field "
        "generates \nthe following output when run on "
        "x86-class computers.\n");
      console::write_line("endianness:  {}",
        bit_converter::endianness);
    }
  };
}

startup_(examples::program);

/*
 This example of the bit_converter::endianness field generates
 the following output when run on x86-class computers.

 endianness:  little
 */
