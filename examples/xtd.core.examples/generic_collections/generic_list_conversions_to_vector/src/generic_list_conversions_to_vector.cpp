#include <xtd/xtd>

auto main() -> int {
  auto l = list<string> {"one", "two", "three", "four", "five"};
  println("l  = {}", l);
  
  auto v = std::vector<std::string> {"one", "two", "three", "four", "five"};
  println("v  = {}", l);
  
  println();
  
  auto v1 = std::vector<string>(l);
  println("v1 = {}", v1);
  
  auto v2 = std::vector<std::string>(l.cast<std::string>());
  println("v2 = {}", v2);
  
  auto v3 = std::vector<std::string>(l.size());
  std::transform(l.begin(), l.end(), v3.begin(), [](const auto& s) {return s;});
  println("v3 = {}", v3);
  
  auto v4 = std::vector<string>(std::move(l.items()));
  println("v4 = {}", v4);
  
  println();
  
  auto l1 = list<std::string>(v);
  println("l1 = {}", l1);
  
  auto l2 = list<string>(from(v).cast<string>());
  println("l2 = {}", l2);
  
  auto l3 = list<string>(v.size());
  std::transform(v.begin(), v.end(), l3.begin(), [](const auto& s) {return s;});
  println("l3 = {}", l3);
  
  auto l4 = list<std::string>(std::move(v));
  println("l4 = {}", l4);
  
  println();

  println("l  = {}", l);
  println("v  = {}", v);
}

// This code can produces the following output:
//
// l  = [one, two, three, four, five]
// v  = [one, two, three, four, five]
//
// v1 = [one, two, three, four, five]
// v2 = [one, two, three, four, five]
// v3 = [one, two, three, four, five]
// v4 = [one, two, three, four, five]
//
// l1 = [one, two, three, four, five]
// l2 = [one, two, three, four, five]
// l3 = [one, two, three, four, five]
// l4 = [one, two, three, four, five]
//
// l  = []
// v  = []
