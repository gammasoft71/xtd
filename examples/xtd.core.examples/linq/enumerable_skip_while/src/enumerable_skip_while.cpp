#include <xtd/xtd>

auto main() -> int {
  auto grades = array {59, 82, 70, 56, 92, 98, 85};
  
  auto lower_grades = grades.order(_1 > _2).skip_while(_ >= 80).to_array();
  
  println("All grades below 80:");
  for (auto grade : lower_grades)
    println(grade);
}

// This code produces the following output :
//
// All grades below 80:
// 70
// 59
// 56
