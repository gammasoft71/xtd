#include <xtd/bit_converter>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;

namespace bit_converter_is_big_endian_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      console::write_line(
        "This example of the bit_converter::is_big_endian field "
        "generates \nthe following output when run on "
        "x86-class computers.\n");
      console::write_line("is_big_endian:  {}",
        bit_converter::is_big_endian);
    }
  };
}

startup_(bit_converter_is_big_endian_example::program::main);

/*
 This example of the bit_converter::is_big_endian field generates
 the following output when run on x86-class computers.

 is_big_endian:  false
 */
