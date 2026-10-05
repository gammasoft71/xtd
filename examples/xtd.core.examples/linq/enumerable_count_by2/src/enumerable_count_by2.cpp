#include <xtd/xtd>

struct student {
  std::string name;
  std::string score;
};

auto main() -> int {
  auto students = std::vector<student> {
    {"Alice", "A"},
    {"Bob", "B"},
    {"Charlie", "C"},
    {"David", "B"},
    {"Eve", "A"}
  };
  
  auto query = from(students).count_by<std::string>([] (auto&& student) {return student.score;});

  for (const auto& [score, count] : query)
    std::println("Students with a {}-score: {}", score, count);
}

// This code produces the following output :
//
// Students with a A-score: 2
// Students with a B-score: 2
// Students with a C-score: 1
