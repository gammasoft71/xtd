# assert_contains

Shows how to use [xtd::tunit::contains](../../../../src/xtd.tunit/include/xtd/assert.h) method.

## Sources

[src/assert_contains.cpp](src/assert_contains.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 4 tests from 1 test case
Run tests:
  SUCCEED test.test_case_collection_succeed (0 ms total)
  FAILED  test.test_case_collection_failed (0 ms total)
    Expected: collection containing 4
    But was:  < 0, 1, 2, 3 >
    Stack Trace: in |---OMITTED---|/assert_contains.cpp:14
  SUCCEED test.test_case_string_succeed (0 ms total)
  FAILED  test.test_case_string_failed (0 ms total)
    Expected: collection containing a
    But was:  < 's', 't', 'r', 'i', 'n', 'g' >
    Stack Trace: in |---OMITTED---|/assert_contains.cpp:22

Test results:
  SUCCEED 2 tests.
  FAILED  2 tests.
End 4 tests from 1 test case ran. (0 ms total)
```
