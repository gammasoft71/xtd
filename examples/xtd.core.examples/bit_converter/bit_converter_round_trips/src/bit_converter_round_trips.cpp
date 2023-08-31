#include <xtd/bit_converter>
#include <xtd/console>
#include <xtd/startup>
#include <vector>

using namespace std;
using namespace xtd;

namespace bit_converter_round_trips_example {
  class program {
  public:
    // The main entry point for the application.
    static auto main() {
      auto value = -16;
      auto bytes = bit_converter::get_bytes(value);
      
      // Convert bytes back to int.
      auto int_value = bit_converter::to_int32(bytes, 0);
      console::write_line("{0} = {1}: {2}", value, int_value, value == int_value ? "Round-trips" : "Does not round-trip");
      // Convert bytes to unsigned int.
      auto uint_value = bit_converter::to_uint32(bytes, 0);
      console::write_line("{0} = {1}: {2}", value, uint_value, static_cast<uint>(value) == uint_value ? "Round-trips" : "Does not round-trip");
    }
  };
}

startup_(bit_converter_round_trips_example::program::main);

// This code produces the following output:
//
// -16 = -16: Round-trips
// -16 = 4294967280: Round-trip
