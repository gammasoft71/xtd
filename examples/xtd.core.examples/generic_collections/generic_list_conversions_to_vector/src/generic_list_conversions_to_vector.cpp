#include <xtd/xtd>

auto main() -> int {
  auto l = list<string> {"one", "two", "three", "four", "five"};
  println("l  = {}", l);
  
  auto v = std::vector<std::string> {"one", "two", "three", "four", "five"};
  println("v  = {}", v);
  
  println();
  
  // xtd::collections::generic::list<xtd::string> -> std::vector<xtd::string>
  auto v1 = std::vector<string> {l}; // direct construction
  println("v1 = {}", v1);
  
  // xtd::collections::generic::list<xtd::string> -> std::vector<std::string>
  auto v2 = std::vector<std::string> {l.cast<std::string>()}; // explicit cast
  println("v2 = {}", v2);
  
  // xtd::collections::generic::list<xtd::string> -> std::vector<std::string>
  auto v3 = std::vector<std::string> {l.count()};
  std::transform(l.begin(), l.end(), v3.begin(), [](const auto& s) {return s;}); // manual transform
  println("v3 = {}", v3);
  
  // Move xtd::collections::generic::list<xtd::string> -> std::vector<xtd::string>
  auto v4 = std::vector<string> {std::move(l.items())}; // using underlying collection
  println("v4 = {}", v4);
  
  println();
  
  // std::vector<std::string> -> xtd::collections::generic::list<std::string>
  auto l1 = list<std::string> {v}; // direct construction
  println("l1 = {}", l1);
  
  // std::vector<std::string> -> xtd::collections::generic::list<xtd::string>
  auto l2 = list<string> {from(v).cast<string>()}; // explicit cast
  println("l2 = {}", l2);
  
  // std::vector<std::string> -> xtd::collections::generic::list<xtd::string>
  auto l3 = list<string> {};
  std::for_each(v.begin(), v.end(), [&](const auto& s) {l3.add(s);}); // manual transform
  println("l3 = {}", l3);
  
  // Move std::vector<std::string> -> xtd::collections::generic::list<std::string>
  auto l4 = list<std::string> {std::move(v)};
  println("l4 = {}", l4);
  
  println();
  
  println("l  = {}", l);
  println("v  = {}", v);
}

// This code produces the following output :
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
