#include <xtd/xtd>

struct persona {
  string name;
  int age;
  
  auto to_string() const noexcept -> string {return string::format("persona {{{}, {}}}", name, age);}
};

class persona_collection {
public:
  persona_collection() = default;
  persona_collection(std::initializer_list<persona> items) : items_ {items} {}
  
  auto to_string() const noexcept -> string {return string::format("[{}]", string::join(", ", items_));}
  
  auto operator [](usize index) -> persona& {return items_[index];}
  auto operator [](usize index) const -> const persona& {return items_[index];}
  auto operator [](xtd::range range) -> span<persona> {return span<persona> {items_, range};}
  auto operator [](xtd::range range) const -> read_only_span<persona> {return read_only_span<persona> {items_, range};}
  
private:
  list<persona> items_;
};

auto main() -> int {
  auto items = persona_collection {{.name = "Oliver Queen", .age = 24}, {.name = "Laurel Lance", .age = 23}, {.name = "John \"Dig\" Diggle", .age = 27}, {.name = "Thea Queen", .age = 20}, {.name = "Felicity Smoak", .age = 22}};
  
  println("items = {}", items);
  
  println();
  println("items[range::all()] = {}", items[range::all()]);
  println("items[range {{2_i, ~0_i}}] = {}", items[range {2_i, ~0_i}]);
  println("items[range {{0, 4}}] = {}", items[range {0, 4}]);
  println(R"(items["1..3"_r] = {})", items["1..3"_r]);
}

// This code produces the following output :
//
// items = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]
//
// items[range::all()] = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]
// items[range {2_i, ~0_i}] = [persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]
// items[range {0, 4}] = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}]
// items["1..3"_r] = [persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}]
