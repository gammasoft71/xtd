# using_xtd_tunit_assert_without_tunit_app

Shows how to use xtd.tunit assert methods like [xtd::tunit::assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert) in a xtd.console or xtd.forms application.

Normally, the classes [xtd::tunit::assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert), [xtd::tunit::collection_assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assert), and [xtd::tunit::file_assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1file__assert) are mainly used when writing unit tests with xtd.tunit.
However, you can also use them as a complement to [assert_](https://gammasoft71.github.io/xtd/reference_guides/latest/group__debug.html#gad1e9d87aeb065b1eec47e92a49fd01e9) in order to validate that a variable, state, or condition is exactly as expected.  

If the condition is not met, an assertion is raised in **Debug** mode, while nothing happens in **Release** mode.  

## Sources

* [src/using_xtd_tunit_assert_without_tunit_app.cpp](src/using_xtd_tunit_assert_without_tunit_app.cpp)

* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
---- DEBUG ASSERTION FAILED ----
---- Assert Short Message----
The items count is less than 4
---- Assert Long Message----

   at xtd::diagnostics::debug::assert_dialog(bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
   at xtd::diagnostics::debug::__should_aborted__(xtd::diagnostics::stack_frame const&, bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
   at xtd::diagnostics::debug::__should_aborted__(xtd::diagnostics::stack_frame const&, bool, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&)
   at xtd::tunit::base_assert::fail(xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
   at void xtd::tunit::assert::is_greater_or_equal<unsigned long, int>(unsigned long const&, int const&, xtd::basic_string<char, std::char_traits<char>, std::allocator<char>> const&, xtd::diagnostics::stack_frame const&)
   at program::main()
   at main


Unhandled exception: xtd::index_out_of_range_exception : Index was outside the bounds of the array.
   at xtd::index_out_of_range_exception::index_out_of_range_exception(xtd::diagnostics::stack_frame const&) in index_out_of_range_exception.hpp:line 26
   at xtd::helpers::throw_helper::throws(xtd::helpers::exception_case, std::__1::source_location const&) in throw_helper.cpp:line 77
   at xtd::basic_array<int, std::__1::allocator<int>>::at(unsigned long) in basic_array.hpp:line 0
   at xtd::basic_array<int, std::__1::allocator<int>>::operator[](unsigned long) in basic_array.hpp:line 546
   at xtd::array<int, 1ul, std::__1::allocator<int>>::operator[](unsigned long) in array_1.hpp:line 233
   at program::main() in using_xtd_tunit_assert_without_tunit_app.cpp:line 12
   at main in using_xtd_tunit_assert_without_tunit_app.cpp:line 16
```
