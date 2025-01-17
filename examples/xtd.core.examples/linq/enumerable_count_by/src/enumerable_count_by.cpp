#include <xtd/xtd>

using namespace xtd;

struct student : iequatable<student> {
  student() = default;
  student(const string& name, const string& score) : name {name}, score {score} {}
  
  string name;
  string score;
  
  bool equals(const student& other) const noexcept override {
    return name == other.name && score == other.score;
  }
};

auto main() -> int {
  auto students = array<student> {
    {"Alice", "A"},
    {"Bob", "B"},
    {"Charlie", "C"},
    {"David", "B"},
    {"Eve", "A"}
  };
  
  const auto& query = students.count_by<string>([](const auto& student) {return student.score;});
  
  for (const auto& [score, count] : query)
    console::write_line("Students with a {}-score: {}", score, count);
}

// This code produces the following output :
//
// Students with a A-score: 2
// Students with a B-score: 2
// Students with a C-score: 1
