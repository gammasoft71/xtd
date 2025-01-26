#include <xtd/console>
#include <xtd/span>

using namespace xtd;

auto main() -> int {
  // Create a span from memory.
  auto memory_pointer = new byte[100];
  auto memory_span = span(memory_pointer, 100);

  auto data = byte {};
  for (auto ctr = 0_z; ctr < memory_span.length(); ++ctr)
    memory_span[ctr] = data++;
  
  auto array_sum = 0;
  for (auto value : memory_span)
    array_sum += value;
  
  console::write_line("The sum is {}", array_sum);
  
  // Don't forget to free memory pointer allocation as xtd::span does not manage memory.
  delete[] memory_pointer;
}

// This code produces the following output :
//
// The sum is 4950
