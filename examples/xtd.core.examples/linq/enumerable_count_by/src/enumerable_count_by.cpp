#include <xtd/xtd>

struct student {
  string name;
  string score;
};

auto main() -> int {
  auto students = array<student> {
    {"Alice", "A"},
    {"Bob", "B"},
    {"Charlie", "C"},
    {"David", "B"},
    {"Eve", "A"}
  };
  
  auto query = students.count_by<string>(_*member(&student::score));

  for (const auto& [score, count] : query)
    console::write_line("Students with a {}-score: {}", score, count);
}

// This code produces the following output :
//
// Students with a A-score: 2
// Students with a B-score: 2
// Students with a C-score: 1
