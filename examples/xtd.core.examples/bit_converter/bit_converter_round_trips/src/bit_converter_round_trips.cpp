#include <xtd/xtd>

using namespace std;
using namespace xtd;

namespace examples {
  class program {
  public:
    // The main entry point for the application.
    static void main() {
      int value = -16;
      vector<byte_t> bytes = bit_converter::get_bytes(value);
      
      // Convert bytes back to int32.
      int int_value = bit_converter::to_int32(bytes, 0);
      console::write_line("{0} = {1}: {2}", value, int_value, value == int_value ? "Round-trips" : "Does not round-trip");
      // Convert bytes to uint32.
      uint uint_value = bit_converter::to_uint32(bytes, 0);
      console::write_line("{0} = {1}: {2}", value, uint_value, static_cast<uint>(value) == uint_value ? "Round-trips" : "Does not round-trip");
    }
  };
}

startup_(examples::program);

// This code produces the following output:
//
// -16 = -16: Round-trips
// -16 = 4294967280: Round-trip
