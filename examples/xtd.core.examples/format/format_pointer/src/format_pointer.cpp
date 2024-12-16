#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  auto ptr = static_cast<int*>(nullptr);
  console::out << string::format("{}", ptr) << environment::new_line;
  ptr = new int(42);
  console::out << string::format("0x{:x}", ptr) << environment::new_line;
  console::out << string::format("{}", *ptr) << environment::new_line;
  delete ptr;
  
  auto sptr = xtd::sptr<int> {};
  console::out << string::format("{}", sptr) << environment::new_line;
  sptr = new_sptr<int>(42);
  console::out << string::format("0x{:x}", sptr) << environment::new_line;
  console::out << string::format("{}", *sptr) << environment::new_line;
  
  auto uptr = xtd::uptr<int> {};
  console::out << string::format("{}", uptr) << environment::new_line;
  uptr = new_uptr<int>(42);
  console::out << string::format("0x{:x}", uptr) << environment::new_line;
  console::out << string::format("{}", *uptr) << environment::new_line;
}

// This code can produce the following output :
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
