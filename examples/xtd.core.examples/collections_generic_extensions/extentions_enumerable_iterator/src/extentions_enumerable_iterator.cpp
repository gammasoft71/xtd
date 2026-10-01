#include <xtd/xtd>

struct person {
  string first_name;
  string last_name;
  
  auto to_string() const noexcept -> string {return first_name + " " + last_name;}
};

struct people : xtd::collections::generic::extensions::enumerable_iterators<person, people> {
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
  
  auto people_list = people {people_values};

  using_ (auto enumerator = people_list.get_enumerator()) {
    if (!enumerator.move_next()) break;
    println(enumerator.current());
    if (!enumerator.move_next()) break;
    if (!enumerator.move_next()) break;
    println(enumerator.current());
  }
  
  println(string('_', 15));
  for (auto enumerator = people_list.get_enumerator(); enumerator.move_next();)
    println(enumerator.current());

  println(string('_', 15));
  println(*people_list.begin());
  println(*(people_list.begin()+2));
  println(*people_list.cbegin());
  println(*(people_list.cbegin()+2));
  
  println(string('_', 15));
  for (auto iterator = people_list.begin(); iterator < people_list.end(); ++iterator)
    println(*iterator);
  
  println(string('_', 15));
  for (auto&& person : people_list)
    println(person);
}

// This code produces the following output :
//
// john smith
// jim johnson
// _______________
// john smith
// sue rabon
// jim johnson
// _______________
// john smith
// jim johnson
// john smith
// jim johnson
// _______________
// john smith
// sue rabon
// jim johnson
// _______________
// john smith
// sue rabon
// jim johnson
