#include <xtd/bit_converter>
#include <xtd/literals>
#include <xtd/console>

using namespace xtd;

auto main() -> int {
  const auto formatter = "{0,25}{1,30}";
  
  auto a_double = 0.1111111111111111111;
  auto a_single = 0.1111111111111111111f;
  auto a_long = 1111111111111111111_s64;
  auto an_int = 1111111111;
  auto a_short = 11111_u16;
  auto a_char = '*';
  auto a_bool = true;
  
  console::write_line("This example of methods of the BitConverter class"
    "\ngenerates the following output.\n");
  console::write_line(formatter, "argument", "byte array");
  console::write_line(formatter, "--------", "----------");
  
  // Convert values to Byte arrays and display them.
  console::write_line(formatter, a_double, bit_converter::to_string(bit_converter::get_bytes(a_double)));
  console::write_line(formatter, a_single, bit_converter::to_string(bit_converter::get_bytes(a_single)));
  console::write_line(formatter, a_long, bit_converter::to_string(bit_converter::get_bytes(a_long)));
  console::write_line(formatter, an_int, bit_converter::to_string(bit_converter::get_bytes(an_int)));
  console::write_line(formatter, a_short, bit_converter::to_string(bit_converter::get_bytes(a_short)));
  console::write_line(formatter, a_char, bit_converter::to_string(bit_converter::get_bytes(a_char)));
  console::write_line(formatter, a_bool, bit_converter::to_string(bit_converter::get_bytes(a_bool)));
}

// This code produces the following output:
//
// This example of methods of the BitConverter class
// generates the following output.
//
//                  argument                    byte array
//                  --------                    ----------
//         0.111111111111111       1C-C7-71-1C-C7-71-BC-3F
//                 0.1111111                   39-8E-E3-3D
//       1111111111111111111       C7-71-C4-2B-AB-75-6B-0F
//                1111111111                   C7-35-3A-42
//                     11111                         67-2B
//                         *                   2A-00-00-00
//                      True                            01
