# file_valid_are_not_equal

Shows how to use [xtd::tunit::file_valid::are_not_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1file__valid.html#a65f48c856e111c54fc4db6a2a939585d) method.

## Sources

[src/file_valid_are_not_equal.cpp](src/file_valid_are_not_equal.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_failed (0 ms total)
    Expected: not equal <std::basic_istringstream<char, std::char_traits<char>, std::allocator<char>>>
    But was:  <std::basic_istringstream<char, std::char_traits<char>, std::allocator<char>>>
    Stack Trace: in |---OMITTED---|/file_valid_are_not_equal.cpp:14

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
