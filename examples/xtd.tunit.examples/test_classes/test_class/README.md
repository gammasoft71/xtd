# test_class

Shows how to use [xtd::tunit::test_class](../../../../src/xtd.tunit/include/xtd/test_class.h) class.

## Sources

[src/test_class.cpp](src/test_class.cpp)

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
  SUCCEED test.test_case2 (0 ms total)
  IGNORED test.test_case3 (0 ms total)
    Test ignored

Test results:
  SUCCEED 2 tests.
  IGNORED 1 test.
End 3 tests from 1 test case ran. (0 ms total)
```
