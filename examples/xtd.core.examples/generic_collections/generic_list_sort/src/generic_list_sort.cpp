#include <xtd/xtd>

struct superhero {
  string name;
  string alter_ego;
  
  auto to_string() const noexcept -> string {return string::format("{}/{}", name, alter_ego);}
  auto operator<=>(const superhero& other) const noexcept -> std::strong_ordering {
    auto result = name <=> other.name;
    return result != 0 ? result : alter_ego <=> other.alter_ego;
  }
};

struct supervillain : istringable<supervillain>, icomparable<supervillain> {
  supervillain() = default;
  supervillain(string name, string alter_ego) : name {name}, alter_ego {alter_ego} {}

  string name;
  string alter_ego;
  
  auto to_string() const noexcept -> string override {return string::format("{}/{}", name, alter_ego);}
  auto compare_to(const supervillain& other) const noexcept -> int override {
    auto result = name.compare_to(other.name);
    return result != 0 ? result : alter_ego.compare_to(other.alter_ego);
  }
};

auto main() -> int {
  auto numbers = list {10, 6, 5, 7, 8, 2, 9, 3, 1, 4};
  numbers.sort();
  println("numbers = {}", numbers);
  
  auto fruits = list<string> {"Orange", "Apple", "Banana", "Strawberry", "Watermelon", "Pear", "Coconut", "Kiwi", "Plum", "Grapes"};
  fruits.sort();
  println("fruits = {}", fruits);
  
  auto superheroes = list<superhero> {
    {.name = "Barry Allen", .alter_ego = "The Flash"},
    {.name = "Oliver Queen", .alter_ego = "Arrow"},
    {.name = "Hal Jordan", .alter_ego = "Green Lantern"},
    {.name = "Bruce Wayne", .alter_ego = "Batman"},
    {.name = "Clark Kent", .alter_ego = "Superman"},
    {.name = "Jefferson Pierce", .alter_ego = "Black Lightning"},
    {.name = "Kara Zor-El", .alter_ego = "Supergirl"},
  };
  superheroes.sort();
  println("superheroes = {}", superheroes);
  
  auto supervillains = list<supervillain> {
    {"Pamela Isley", "Poison Ivy"},
    {"George Harkness", "Captain Boomerang"},
    {"El-Kal", "Bizarro"},
    {"Winslow Schott", "Toyman"},
    {"Theo Adam", "Black Adam"},
    {"Joar Mahkent", "Icicle"},
    {"Caitlin Snow", "Killer Frost"}
  };
  supervillains.sort();
  println("supervillains = {}", supervillains);
}

// This code produces the following output :
//
// numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
// fruits = [Apple, Banana, Coconut, Grapes, Kiwi, Orange, Pear, Plum, Strawberry, Watermelon]
// superheroes = [Barry Allen/The Flash, Bruce Wayne/Batman, Clark Kent/Superman, Hal Jordan/Green Lantern, Jefferson Pierce/Black Lightning, Kara Zor-El/Supergirl, Oliver Queen/Arrow]
// supervillains = [Caitlin Snow/Killer Frost, El-Kal/Bizarro, George Harkness/Captain Boomerang, Joar Mahkent/Icicle, Pamela Isley/Poison Ivy, Theo Adam/Black Adam, Winslow Schott/Toyman]
