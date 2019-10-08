#include <iostream>
#include <xtd/xtd.drawing>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

int main() {
  point location = {10, 235};
  cout << format("location = {}", location) << endl;

  location.x(location.x() + 20);
  location.y(location.y() - 15);
  cout << format("location = {}", location) << endl;
  
  location = point(10, 10) + drawing::size(20, 50);
  cout << format("location = {}", location) << endl;
  
  location.offset({70, 140});
  cout << format("location = {}", location) << endl;
}
