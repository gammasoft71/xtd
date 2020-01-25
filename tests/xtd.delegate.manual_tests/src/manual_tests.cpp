#include <xtd/xtd.delegates>
#include <iostream>
#include <string>

using namespace std;
using namespace xtd;

int main() {
  delegate<void()> d1;
  delegate<void()> d2 = d1;

  d1 += []()  {
    cout << "test" << endl;
  };
  
  d2();
}
