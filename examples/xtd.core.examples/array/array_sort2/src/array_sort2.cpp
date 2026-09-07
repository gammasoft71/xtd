#include <xtd/xtd>

struct my_own_descending_comparer : icomparer<int> {
  [[nodiscard]] auto compare(const int& x, const int& y) const -> int override {return x > y ? -1 : x < y ? 1 : 0;}
};

auto main() -> int {
  auto items = array {10, 6, 5, 7, 8, 2, 9, 3, 1, 4};
  
  // C++ standard
  //items.sort([](auto&& a, auto&& b) {return a < b;});
  items.sort(_1 < _2);
  println("ascending sorted items = {}", items);
  //items.sort([](auto&& a, auto&& b) {return a > b;});
  items.sort(_1 > _2);
  println("descending sorted items = {}", items);
  println();
  
  // C++ modern with ordering
  //items.sort([](auto&& a, auto&& b) {return a <=> b;});
  items.sort(_1 <=> _2);
  println("ascending sorted items = {}", items);
  //items.sort([](auto&& a, auto&& b) {return a <=> b == std::strong_ordering::greater;});
  items.sort(_1 <=> _2 == std::strong_ordering::greater);
  println("descending sorted items = {}", items);
  println();
  
  // C# style
  //items.sort([](auto&& a, auto&& b) {return a > b ? 1 : a < b ? -1 : 0;});
  items.sort(if_then_else(_1 > _2, 1, if_then_else(_1 < _2, -1, 0)));
  println("ascending sorted items = {}", items);
  //items.sort([](auto&& a, auto&& b) {return a > b ? -1 : a < b ? 1 : 0;});
  items.sort([](auto&& a, auto&& b) {return a > b ? -1 : a < b ? 1 : 0;});
  println("descending sorted items = {}", items);
  println();
  
  // C# style with comparer
  items.sort(comparer<int>::default_comparer);
  println("ascending sorted items = {}", items);
  items.sort(my_own_descending_comparer {});
  println("descending sorted items = {}", items);
  println();
}

// This code produces the following output :
//
// ascending sorted items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// descending sorted items = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
//
// ascending sorted items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// descending sorted items = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
//
// ascending sorted items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// descending sorted items = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
//
// ascending sorted items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// descending sorted items = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
//
