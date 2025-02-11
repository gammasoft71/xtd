#include <xtd/xtd>

/*
template <>
struct std::hash<xtd::string> {
  std::size_t operator()(const xtd::string& k) const {return k.get_hash_code();}
};
 */

auto main() -> int {
  println();
  //auto items = fixed_array<string, 4> {"one", "two", "three", "four"};
  string items[4] {"one", "two", "three", "four"};
  println("items = {}", items);

  println();
  println("array<string>         = {}", array<string> {"one", "two", "three", "four"});
  println("fixed_array<string>   = {}", fixed_array<string, 4> {"one", "two", "three", "four"});
  println("std::array<string, 4> = {}", std::array<string, 4> {"one", "two", "three", "four"});

  println();
  println("list<string>        = {}", list<string> {"one", "two", "three", "four"});
  println("std::vector<string> = {}", std::vector<string> {"one", "two", "three", "four"});
  
  println();
  println("linked_list<string>       = {}", linked_list<string> {"one", "two", "three", "four"});
  println("std::forward_list<string> = {}", std::forward_list<string> {"one", "two", "three", "four"});
  println("std::list<string>         = {}", std::list<string> {"one", "two", "three", "four"});

  println();
  println("hash_set<string>                                    = {}", hash_set<string> {"one", "two", "three", "four"});
  //println("std::unordered_set<string>                          = {}", std::unordered_set<string> {"one", "two", "three", "four"});
  println("std::unordered_set<string, helpers::hasher<string>> = {}", std::unordered_set<string, xtd::collections::generic::helpers::hasher<string>> {"one", "two", "three", "four"});

  println();
  println("sorted_set<string>                        = {}", sorted_set<string> {"one", "two", "three", "four"});
  println("std::set<string>                          = {}", std::set<string> {"one", "two", "three", "four"});
  println("std::set<string, helpers::lesser<string>> = {}", std::set<string, xtd::collections::generic::helpers::lesser<string>> {"one", "two", "three", "four"});
  
  //println("items = {}", items);
  
  //println("Hello, world!");
}

// This code can produces the following output:
//
// Hello, World!
