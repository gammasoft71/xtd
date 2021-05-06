# assert_fail

Shows how to use [xtd::tunit::assert::fail](../../../../src/xtd.tunit/include/xtd/assert.h) method.

## Sources

[src/assert_fail.cpp](src/assert_fail.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 1 test from 1 test case
Run tests:
  FAILED  test.test_case_failed (0 ms total)
    Test failed
    Stack Trace: in |---OMITTED---|/assert_fail.cpp:8

Test results:
  FAILED  1 test.
End 1 test from 1 test case ran. (0 ms total)
```
