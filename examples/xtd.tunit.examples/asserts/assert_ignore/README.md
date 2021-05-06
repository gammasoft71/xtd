# assert_ignore

Shows how to use [xtd::tunit::assert::ignore](../../../../src/xtd.tunit/include/xtd/assert.h) method.

## Sources

[src/assert_ignore.cpp](src/assert_ignore.cpp)

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
  IGNORED test.test_case_ignored (0 ms total)
    Test ignored

Test results:
  IGNORED 1 test.
End 1 test from 1 test case ran. (0 ms total)
```
