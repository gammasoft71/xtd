#include <algorithm>
#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  vector<ustring> names {"Bruce", "Alfred", "Tim", "Richard"};
  
  action<const ustring&> print([](const ustring& value) {
    console::write_line(value);
  });
  
  // Display the contents of the list using the print delegate.
  for_each(names.begin(), names.end(), print);
  
  // The following demonstrates the lambda of c++ to display the contents of the list to the console.
  for_each(names.begin(), names.end(), [](const ustring& value) {
    console::write_line(value);
  });
}

// This code produces the following output:
//
// Bruce
// Alfred
// Tim
// Richard
// Bruce
// Alfred
// Tim
// Richard
