#include <xtd/xtd>

using namespace std;
using namespace xtd;

int main() {
  int* ptr = nullptr;
  cout << ustring::format("{}", ptr) << endl;
  ptr = new int(42);
  cout << ustring::format("{}", ptr) << endl;
  cout << ustring::format("{}", *ptr) << endl;
  delete ptr;

  shared_ptr<int> sptr;
  cout << ustring::format("{}", sptr) << endl;
  sptr = make_shared<int>(42);
  cout << ustring::format("{}", sptr) << endl;
  cout << ustring::format("{}", *sptr) << endl;

  unique_ptr<int> uptr;
  cout << ustring::format("{}", uptr) << endl;
  uptr = make_unique<int>(42);
  cout << ustring::format("{}", uptr) << endl;
  cout << ustring::format("{}", *uptr) << endl;
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
