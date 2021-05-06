# assert_is_NaN

Shows how to use [xtd::tunit::assert::is_NaN](../../../../src/xtd.tunit/include/xtd/assert.h) method.

## Sources

[src/assert_is_NaN.cpp](src/assert_is_NaN.cpp)

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
    Expected: NaN
    But was:  3.14159
    Stack Trace: in |---OMITTED---|/assert_is_NaN.cpp:15

// Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
