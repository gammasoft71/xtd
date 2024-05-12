# string_assert_starts_with

Shows how to use [xtd::tunit::string_assert::starts_with](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assert.html#a798f3ad026c80669f79045b8f5e96bee) method.

## Sources

[src/string_assert_starts_with.cpp](src/string_assert_starts_with.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that starts_with the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_failed (0 ms total)
    Expected: string starting with "lue"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_assert_starts_with.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
