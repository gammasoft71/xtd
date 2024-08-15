#include <xtd/string>

using namespace std;
using namespace xtd;

auto main() -> int {
  auto ptr = static_cast<int*>(nullptr);
  cout << ustring::format("{}", ptr) << endl;
  ptr = new int(42);
  cout << ustring::format("0x{:x}", ptr) << endl;
  cout << ustring::format("{}", *ptr) << endl;
  delete ptr;
  
  auto sptr = xtd::sptr<int> {};
  cout << ustring::format("{}", sptr) << endl;
  sptr = new_sptr<int>(42);
  cout << ustring::format("0x{:x}", sptr) << endl;
  cout << ustring::format("{}", *sptr) << endl;
  
  auto uptr = xtd::uptr<int> {};
  cout << ustring::format("{}", uptr) << endl;
  uptr = new_uptr<int>(42);
  cout << ustring::format("0x{:x}", uptr) << endl;
  cout << ustring::format("{}", *uptr) << endl;
}

// This code produces the following output :
//
// (null)
// 0x1007380f0
// 42
// (null)
// 0x1053075c8
// 42
// (null)
// 0x1052191a0
// 42
