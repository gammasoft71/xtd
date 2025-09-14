#include <xtd/xtd>

auto main() -> int {
  auto items = array {10, 20, 30};
  
  tunit::assert::is_greater_or_equal(items.count(), 4, "The items count is less than 4");
  // Same as two following lines
  //diagnostics::debug::cassert(items.count() >= 4, "The items count is less than 4");
  //assert_(items.count() >= 4, "The items count is less than 4");
  println(items[3]);
}

// This code produces the following outputs :
//
// ---- DEBUG ASSERTION FAILED ----
// ---- Assert Short Message----
// The items count is less than 4
// ---- Assert Long Message----
//
//    at xtd::diagnostics::debug::assert_dialog(bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
//    at xtd::diagnostics::debug::__should_aborted__(bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
//    at xtd::diagnostics::debug::__should_aborted__(bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
//    at xtd::diagnostics::debug::cassert(bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
//    at main
