#include <xtd/xtd>

struct person {
  string first_name;
  string last_name;
  
  friend auto operator <<(std::ostream& os, const person& p) noexcept -> std::ostream& {return os << p.first_name << " " << p.last_name;}
  friend auto operator <=>(const person&, const person&) noexcept = default;
};

struct people : xtd::collections::generic::extensions::enumerable_iterators<person, people>, xtd::collections::generic::extensions::enumerable<person, people> {
  explicit people(iterable auto&& persons) : people_ {persons} {}
  
  auto get_enumerator() const -> enumerator<person> {return people_.get_enumerator();}
  
private:
  list<person> people_;
};

auto main() -> int {
  auto people_values = {
    person {.first_name = "john", .last_name = "smith"},
    person {.first_name = "sue", .last_name = "rabon"},
    person {.first_name = "jim", .last_name = "johnson"},
  };
  
  for (auto&& person : people {people_values}.select([](auto&& p) {return person {p.first_name.to_title_case(), p.last_name.to_upper()};}).order())
    println(person);
}

// This code produces the following output :
//
// Jim JOHNSON
// John SMITH
// Sue RABON
