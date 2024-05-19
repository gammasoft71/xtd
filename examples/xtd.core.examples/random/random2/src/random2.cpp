#include <xtd/console>
#include <xtd/random>

using namespace std;
using namespace xtd;

auto main() -> int {
  // Instantiate random number generator using system-supplied value as seed.
  auto rand = xtd::random {};
  
  // Generate and display 5 random byte (integer) values.
  auto bytes = vector<unsigned char>(5);
  rand.next_bytes(bytes);
  
  console::write_line("Five random byte values:");
  for (auto byte_value : bytes)
    console::write("{, 5}", byte_value);
  console::write_line();
  
  // Generate and display 5 random integers.
  console::write_line("Five random integer values:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{, 15}", rand.next());
  console::write_line();
  
  // Generate and display 5 random integers between 0 and 100.//
  console::write_line("Five random integers between 0 and 100:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{, 10}", rand.next(101));
  console::write_line();
  
  // Generate and display 5 random integers from 50 to 100.
  console::write_line("Five random integers between 50 and 100:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{, 10}", rand.next(50, 101));
  console::write_line();
  
  // Generate and display 5 random floating point values from 0 to 1.
  console::write_line("Five Doubles:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{, 10}", rand.next_double());
  console::write_line();
  
  // Generate and display 5 random floating point values from 0 to 5.
  console::write_line("Five Doubles between 0 and 5:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{, 10}", rand.next_double() * 5);
  console::write_line();
}

// This code can produces the following output:
//
// Five random byte values:
//   150  243   92  141    0
// Five random integer values:
//     4.14343E+08    2.14086E+09    1.73486E+09    1.88133E+09    1.69685E+09
// Five random integers between 0 and 100:
//         35        86        86        68        10
// Five random integers between 50 and 100:
//         76        57        66        97        56
// Five Doubles:
//   0.211096  0.172007  0.507414   0.48576  0.754658
// Five Doubles between 0 and 5:
//    1.40691    2.7078   3.87732    1.0691  0.478343
