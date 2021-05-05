# assert

Shows how to use [xtd::tunit::assert](../../../../src/xtd.tunit/include/xtd/assert.h) class.

## Sources

[src/assert.cpp](src/assert.cpp)

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
  SUCCEED test.test_case1 (0 ms total)
  FAILED  test.test_case2 (0 ms total)
    Expected: false
    But was:  true
    Stack Trace: in /Users/gammasoft71/Projects/xtd/examples/xtd.tunit.examples/assert/src/assert.cpp:14
  FAILED  test.test_case3 (0 ms total)
    Expected: No Exception to be thrown
    But was:  <std::range_error>
    Stack Trace: in /Users/gammasoft71/Projects/xtd/examples/xtd.tunit.examples/assert/src/assert.cpp:18

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```

