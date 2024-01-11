# assert_is_negative

Shows how to use [xtd::tunit::assert::is_negative](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#a8abb7245e1167d5ac35b5ee71a80944d) method.

## Sources

[src/assert_is_negative.cpp](src/assert_is_negative.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: negative
    But was:  1
    Stack Trace: in |---OMITTED---|/assert_is_negative.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
