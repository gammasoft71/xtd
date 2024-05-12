# string_valid

Shows how to use [xtd::tunit::string_valid](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__valid.html) class.

## Sources

[src/string_valid.cpp](src/string_valid.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 3 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case1 (0 ms total)
  FAILED  unit_tests::test.test_case2 (0 ms total)
    Expected: string containing "item"
    But was:  "A string value"
    Stack Trace: in |---OMITTED---|/string_valid.cpp:17
  FAILED  unit_tests::test.test_case3 (0 ms total)
    Expected: string matching "item$"
    But was:  "A string value"
    Stack Trace: in |---OMITTED---|/string_valid.cpp:22

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
