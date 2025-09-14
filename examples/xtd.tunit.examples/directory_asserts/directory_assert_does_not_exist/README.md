# directory_assert_does_not_exist

Shows how to use [xtd::tunit::directory_assert::does_not_exist](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1directory__assert.html#a844fc0ffa68b7425a90afba83168e313) method.

## Sources

* [src/directory_assert_does_not_exist.cpp](src/directory_assert_does_not_exist.cpp)
* [CMakeLists.txt](CMakeLists.txt)

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
    Expected: not directory exists
    But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
    Stack Trace: in |---OMITTED---|/directory_assert_does_not_exist.cpp:14

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
