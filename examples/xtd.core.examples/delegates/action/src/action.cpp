#include <xtd/xtd>

auto main() -> int {
  auto names = list {"Bruce", "Alfred", "Tim", "Richard"};
  
  auto print = action<const string&> {[](const string & value) {
    console::write_line(value);
  }};
  
  // Display the contents of the list using the print delegate.
  names.for_each(print);
  
  // The following demonstrates the lambda of c++ to display the contents of the list to the console.
  names.for_each([](const string & value) {
    console::write_line(value);
  });
}

// This code produces the following output :
//
// Bruce
// Alfred
// Tim
// Richard
// Bruce
// Alfred
// Tim
// Richard
