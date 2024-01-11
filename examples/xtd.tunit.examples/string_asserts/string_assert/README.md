# string_assert

Shows how to use [xtd::tunit::string_assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assert.html) class.

## Sources

[src/string_assert.cpp](src/string_assert.cpp)

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
  SUCCEED test.test_case1 (0 ms total)
  FAILED  test.test_case2 (0 ms total)
    Expected: string containing "item"
    But was:  "A string value"
    Stack Trace: in |---OMITTED---|/string_assert.cpp:17
  FAILED  test.test_case3 (0 ms total)
    Expected: string matching "item$"
    But was:  "A string value"
    Stack Trace: in |---OMITTED---|/string_assert.cpp:22

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
