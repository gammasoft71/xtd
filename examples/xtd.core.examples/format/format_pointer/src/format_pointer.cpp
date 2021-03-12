#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  int* ptr = nullptr;
  cout << format("{}", ptr) << endl;
  ptr = new int(42);
  cout << format("{}", ptr) << endl;
  cout << format("{}", *ptr) << endl;
  delete ptr;

  shared_ptr<int> sptr;
  cout << format("{}", sptr) << endl;
  sptr = make_shared<int>(42);
  cout << format("{}", sptr) << endl;
  cout << format("{}", *sptr) << endl;

  unique_ptr<int> uptr;
  cout << format("{}", uptr) << endl;
  uptr = make_unique<int>(42);
  cout << format("{}", uptr) << endl;
  cout << format("{}", *uptr) << endl;
}

// This code can produces the following output :
//
// 0x0
// 0x1007380f0
// 42
// 0x0
// 0x1053075c8
// 42
// 0x0
// 0x1052191a0
// 42
