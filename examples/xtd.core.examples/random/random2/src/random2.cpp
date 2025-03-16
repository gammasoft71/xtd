#include <xtd/console>
#include <xtd/random>

using namespace xtd;

auto main() -> int {
  // Instantiate random number generator using system-supplied value as seed.
  auto rand = xtd::random {};
  
  // Generate and display 5 random byte (integer) values.
  auto bytes = array<byte>(5);
  rand.next_bytes(bytes);
  
  console::write_line("Five random byte values:");
  for (auto byte_value : bytes)
    console::write("{,5}", byte_value);
  console::write_line();
  
  // Generate and display 5 random integers.
  console::write_line("Five random integer values:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{,15:N0}", rand.next());
  console::write_line();
  
  // Generate and display 5 random integers between 0 and 100.//
  console::write_line("Five random integers between 0 and 100:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{,8:N0}", rand.next(101));
  console::write_line();
  
  // Generate and display 5 random integers from 50 to 100.
  console::write_line("Five random integers between 50 and 100:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{,8:N0}", rand.next(50, 101));
  console::write_line();
  
  // Generate and display 5 random floating point values from 0 to 1.
  console::write_line("Five Doubles:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{,8:N3}", rand.next_double());
  console::write_line();
  
  // Generate and display 5 random floating point values from 0 to 5.
  console::write_line("Five Doubles between 0 and 5:");
  for (auto ctr = 0; ctr <= 4; ctr++)
    console::write("{,8:N3}", rand.next_double() * 5);
  console::write_line();
}

// This code can produce the following output :
//
// Five random byte values:
//    56   13  183  186    9
// Five random integer values:
//       393336251     1630901725      159175947     1510060072      592602585
// Five random integers between 0 and 100:
//       26      50      32       9      50
// Five random integers between 50 and 100:
//       84      63      52      69      68
// Five Doubles:
//    0.186   0.070   0.021   0.892   0.313
// Five Doubles between 0 and 5:
//    2.938   0.848   0.060   3.667   0.042
