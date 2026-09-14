#include <xtd/xtd>

namespace bit_converter_to_string_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      array<byte> array_one = {0, 1, 2, 4, 8, 16, 32, 64, 128, 255};
      array<byte> array_two = {32, 0, 0, 42, 0, 65, 0, 125, 0, 197, 0, 168, 3, 41, 4, 172, 32};
      array<byte> array_three = {15, 0, 0, 128, 16, 39, 240, 216, 241, 255, 127};
      array<byte> array_four = {15, 0, 0, 0, 0, 16, 0, 255, 3, 0, 0, 202, 154, 59, 255, 255, 255, 255, 127};
      console::write_line("This example of the xtd::bit_converter::to_string(const xtd::array<xtd::byte>&) \n"
                          "method generates the following output.\n");
      write_byte_array(array_one, "array_one");
      write_byte_array(array_two, "array_two");
      write_byte_array(array_three, "array_three");
      write_byte_array(array_four, "array_four");
    }

  private:
    // Display a byte array with a name.
    static void write_byte_array(const array<byte>& bytes, const string& name) {
      string under_line = "--------------------------------";
      console::write_line(name);
      console::write_line(under_line.substring(0, math::min(name.length(), under_line.length())));
      console::write_line(bit_converter::to_string(bytes));
      console::write_line();
    }
  };
}

startup_(bit_converter_to_string_example::program::main);

// This code produces the following output :
//
// This example of the xtd::bit_converter::to_string(const xtd::array<xtd::byte>&)
// method generates the following output.
//
// array_one
// ---------
// 00-01-02-04-08-10-20-40-80-FF
//
// array_two
// ---------
// 20-00-00-2A-00-41-00-7D-00-C5-00-A8-03-29-04-AC-20
//
// array_three
// -----------
// 0F-00-00-80-10-27-F0-D8-F1-FF-7F
//
// array_four
// ----------
// 0F-00-00-00-00-10-00-FF-03-00-00-CA-9A-3B-FF-FF-FF-FF-7F
//
