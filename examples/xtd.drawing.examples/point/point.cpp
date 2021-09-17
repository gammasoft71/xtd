#include <iostream>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  point location = {10, 235};
  cout << ustring::format("location = {}", location) << endl;

  location.x(location.x() + 20);
  location.y(location.y() - 15);
  cout << ustring::format("location = {}", location) << endl;
  
  location = point(10, 10) + drawing::size(20, 50);
  cout << ustring::format("location = {}", location) << endl;
  
  location.offset({70, 140});
  cout << ustring::format("location = {}", location) << endl;
}

// This code produces the following output:
//
// location = {x=10, y=235}
// location = {x=30, y=220}
// location = {x=30, y=60}
// location = {x=100, y=200}
