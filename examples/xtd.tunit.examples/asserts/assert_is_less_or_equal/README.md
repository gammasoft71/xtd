# assert_is_less_or_equal

Shows how to use [xtd::tunit::assert::is_less_or_equal](../../../../src/xtd.tunit/include/xtd/assert.h) method.

## Sources

[src/assert_is_less_or_equal.cpp](src/assert_is_less_or_equal.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 3 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed1 (0 ms total)
  SUCCEED test.test_case_succeed2 (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: less than or equal to 12
    But was:  24
    Stack Trace: in |---OMITTED---|/assert_is_less_or_equal.cpp:18

Test results:
  SUCCEED 2 tests.
  FAILED  1 test.
End 3 tests from 1 test case ran. (0 ms total)
```
