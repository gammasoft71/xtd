#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  int* ptr = nullptr;
  cout << strings::format("{}", ptr) << endl;
  ptr = new int(42);
  cout << strings::format("{}", ptr) << endl;
  cout << strings::format("{}", *ptr) << endl;
  delete ptr;

  shared_ptr<int> sptr;
  cout << strings::format("{}", sptr) << endl;
  sptr = make_shared<int>(42);
  cout << strings::format("{}", sptr) << endl;
  cout << strings::format("{}", *sptr) << endl;

  unique_ptr<int> uptr;
  cout << strings::format("{}", uptr) << endl;
  uptr = make_unique<int>(42);
  cout << strings::format("{}", uptr) << endl;
  cout << strings::format("{}", *uptr) << endl;
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
