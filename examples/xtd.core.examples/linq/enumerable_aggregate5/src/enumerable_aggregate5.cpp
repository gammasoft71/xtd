#include <xtd/linq/enumerable>
#include <xtd/array>
#include <xtd/println>

using namespace xtd;
using namespace xtd::linq;

auto main() -> int {
  auto ints = array {4, 8, 8, 3, 9, 0, 7, 8, 2};
  
  // Count the even numbers in the array, using a seed value of 0.
  auto num_even = enumerable::aggregate(ints.begin(), ints.end(), 0, [](int total, int next) {
    return next % 2 == 0 ? total + 1 : total;
  });
  
  println("The number of even integers is: {}", num_even);
}

// This code produces the following output :
//
// The number of even integers is: 6
