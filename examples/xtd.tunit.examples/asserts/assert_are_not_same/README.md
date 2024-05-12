# assert_are_not_same

Shows how to use [xtd::tunit::assert::are_not_same](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#a0910dad3d164ec8a336c10c01a002cea) method.

## Sources

[src/assert_are_not_same.cpp](src/assert_are_not_same.cpp)

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
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_failed (0 ms total)
    Expected: not same as 24
    But was:  24
    Stack Trace: in |---OMITTED---|/assert_are_not_same.cpp:14

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
