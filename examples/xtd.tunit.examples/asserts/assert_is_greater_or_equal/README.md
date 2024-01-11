# assert_is_greater_or_equal

Shows how to use [xtd::tunit::assert::is_greater_or_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#a4a1368e05eb8f61b113fabc7de62d6ad) method.

## Sources

[src/assert_is_greater_or_equal.cpp](src/assert_is_greater_or_equal.cpp)

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
  SUCCEED test.test_case_succeed1 (0 ms total)
  SUCCEED test.test_case_succeed2 (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: greater than or equal to 48
    But was:  24
    Stack Trace: in |---OMITTED---|/assert_is_greater_or_equal.cpp:18

Test results:
  SUCCEED 2 tests.
  FAILED  1 test.
End 3 tests from 1 test case ran. (0 ms total)
```
