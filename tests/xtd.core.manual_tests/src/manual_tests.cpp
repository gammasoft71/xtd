#define NDEBUG
#include <xtd/xtd>

auto main() -> int {
  auto items = array {10, 20, 30};
  
  //assert_(items.count() >= 4, "The items count is less than 4");
  tunit::assert::is_greater_or_equal(items.count(), 4_z, "The items count is less than 4");
  //println(items[3]);
}

// This code produces the following outputs :
//
// 20
