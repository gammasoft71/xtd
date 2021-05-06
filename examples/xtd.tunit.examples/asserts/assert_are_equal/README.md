# assert_are_equal

Shows how to use [xtd::tunit::assert::assert_are_equal](../../../../src/xtd.tunit/include/xtd/assert.h) method.

## Sources

[src/assert_are_equal.cpp](src/assert_are_equal.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: 23
    But was:  24
    Stack Trace: in |---OMITTED---|/assert_are_equal.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
