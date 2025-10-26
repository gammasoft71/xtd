#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto items = array {10, 20, 30};
    
    tunit::assert::is_greater_or_equal(items.count(), 4, "The items count is less than 4");
    // Same as two following lines
    //diagnostics::debug::cassert(items.count() >= 4, "The items count is less than 4");
    //assert_(items.count() >= 4, "The items count is less than 4");
    println(items[3]);
  }
};

startup_(program::main);

// This code produces the following output :
//
// ---- DEBUG ASSERTION FAILED ----
// ---- Assert Short Message----
// The items count is less than 4
// ---- Assert Long Message----
//
//    at xtd::diagnostics::debug::assert_dialog(bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
//    at xtd::diagnostics::debug::__should_aborted__(xtd::diagnostics::stack_frame const&, bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
//    at xtd::diagnostics::debug::__should_aborted__(xtd::diagnostics::stack_frame const&, bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
//    at xtd::tunit::base_assert::fail(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
//    at void xtd::tunit::assert::is_greater_or_equal<unsigned long, int>(unsigned long const&, int const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
//    at program::main()
//    at main
//
//
// Unhandled exception: xtd::index_out_of_range_exception : Index was outside the bounds of the array.
//    at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
//    at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::__1::source_location const&) in throw_helper.cpp:line 77
//    at xtd::basic_array<int, std::__1::allocator<int>>::at(unsigned long) in basic_array.hpp:line 0
//    at xtd::basic_array<int, std::__1::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 546
//    at xtd::array<int, 1ul, std::__1::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 233
//    at program::main() in using_xtd_tunit_assert_without_tunit_app.cpp:line 12
//    at main in using_xtd_tunit_assert_without_tunit_app.cpp:line 16
