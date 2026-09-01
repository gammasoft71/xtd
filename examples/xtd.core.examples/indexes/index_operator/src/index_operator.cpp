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
  auto operator [](xtd::index index) -> persona& {return operator [](index.get_offset(items_.count()));}
  auto operator [](xtd::index index) const -> const persona& {return operator [](index.get_offset(items_.count()));}

private:
  list<persona> items_;
};

auto main() -> int {
  auto items = persona_collection {{.name = "Oliver Queen", .age = 24}, {.name = "Laurel Lance", .age = 23}, {.name = "John \"Dig\" Diggle", .age = 27}, {.name = "Thea Queen", .age = 20}, {.name = "Felicity Smoak", .age = 22}};
  
  println("items = {}", items);
  
  println();
  println("items[0_i] = {}", items[0_i]);
  println("items[2] = {}", items[2]);
  println("items[~1_i] = {}", items[~1_i]);
  
  println();
  println("items[1_i] = {}", items[1_i]);
  items[1_i].age = 24;
  println("items[1_i] (updated) = {}", items[1_i]);
}

// This code produces the following output :
//
// items = [persona {Oliver Queen, 24}, persona {Laurel Lance, 23}, persona {John "Dig" Diggle, 27}, persona {Thea Queen, 20}, persona {Felicity Smoak, 22}]
//
// items[0_i] = persona {Oliver Queen, 24}
// items[2] = persona {John "Dig" Diggle, 27}
// items[~1_i] = persona {Felicity Smoak, 22}
//
// items[1_i] = persona {Laurel Lance, 23}
// items[1_i] (updated) = persona {Laurel Lance, 24}
