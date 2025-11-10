#include <xtd/xtd>

auto main() -> int {
  //string names[] = {"Burke", "Connor", "Frank", "Everett", "Albert", "George", "Harris", "David"};
  //auto names = fixed_array<string, 8> {"Burke", "Connor", "Frank", "Everett", "Albert", "George", "Harris", "David"};
  //auto names = std::vector {"Burke"_s, "Connor"_s, "Frank"_s, "Everett"_s, "Albert"_s, "George"_s, "Harris"_s, "David"_s};
  //auto names = std::list {"Burke"_s, "Connor"_s, "Frank"_s, "Everett"_s, "Albert"_s, "George"_s, "Harris"_s, "David"_s};
  //auto names = array {"Burke"_s, "Connor"_s, "Frank"_s, "Everett"_s, "Albert"_s, "George"_s, "Harris"_s, "David"_s};
  //auto names = list {"Burke"_s, "Connor"_s, "Frank"_s, "Everett"_s, "Albert"_s, "George"_s, "Harris"_s, "David"_s};
  //auto names = linked_list {"Burke"_s, "Connor"_s, "Frank"_s, "Everett"_s, "Albert"_s, "George"_s, "Harris"_s, "David"_s};
  auto names = {"Burke"_s, "Connor"_s, "Frank"_s, "Everett"_s, "Albert"_s, "George"_s, "Harris"_s, "David"_s};
  
  // xtd::linq query
  auto query1 = from(names)
    .where(delegate_(auto s) {return s.length() == 5;})
    .order_by(delegate_(auto s) {return s;})
    .select(delegate_(auto s) {return s.to_upper();});
  println(query1);
  
  // xtd::ranges query
  auto query2 = names
    | where(delegate_(auto s) {return s.length() == 5;})
    | order_by(delegate_(auto s) {return s;})
    | select(delegate_(auto s) {return s.to_upper();});
  println(query2);
  
  // std::ranges combined with xtd::ranges query
  auto query3 = names
    | std::views::filter(delegate_(auto s) {return s.length() == 5;})
    | order_by(delegate_(auto s) {return s;})
    | std::views::transform(delegate_(auto s) {return s.to_upper();});
  println(query3);
}

// Console output :
//
// [BURKE, DAVID, FRANK]
// [BURKE, DAVID, FRANK]
// [BURKE, DAVID, FRANK]
