#include <xtd/array>
#include <xtd/console>
#include <xtd/span>

using namespace xtd;

auto main() -> int {
  // Create a span over an array.
  auto bytes = array<byte>(100);
  auto array_span = span(bytes);
  
  auto data = byte {};
  for (auto ctr = 0_z; ctr < array_span.length(); ++ctr)
    array_span[ctr] = data++;
  
  auto array_sum = 0;
  for (auto value : bytes)
    array_sum += value;
  
  console::write_line("The sum is {}", array_sum);
}

// This code produces the following output :
//
// The sum is 4950
