#include <xtd/ustring>

using namespace std;
using namespace xtd;

auto main() -> int {
  auto ptr = static_cast<int*>(nullptr);
  cout << ustring::format("{}", ptr) << endl;
  ptr = new int(42);
  cout << ustring::format("{}", ptr) << endl;
  cout << ustring::format("{}", *ptr) << endl;
  delete ptr;
  
  auto sptr = shared_ptr<int> {};
  cout << ustring::format("{}", sptr) << endl;
  sptr = make_shared<int>(42);
  cout << ustring::format("{}", sptr) << endl;
  cout << ustring::format("{}", *sptr) << endl;
  
  auto uptr = unique_ptr<int> {};
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
