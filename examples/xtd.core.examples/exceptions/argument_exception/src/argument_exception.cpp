#include <xtd/xtd>

using namespace xtd;

int divide_by_two(int num) {
  // If num is an odd number, throw an argument_exception.
  if ((num & 1) == 1) throw argument_exception("Number must be even");
  
  // num is even, return half of its value.
  return num / 2;
}

int main() {
  // argument_exception is not thrown because 10 is an even number.
  console::write_line("10 divided by 2 is {0}", divide_by_two(10));
  try {
    // argument_exception is thrown because 7 is not an even number.
    console::write_line("7 divided by 2 is {0}", divide_by_two(7));
  } catch (const argument_exception&) {
    // Show the user that 7 cannot be divided by 2.
    console::write_line("7 is not divided by 2 integrally.");
  }
}

// This code can produces the following output :
//
// Exception occured :
// -------------------
// 10 divided by 2 is 5
// 7 is not divided by 2 integrally.
