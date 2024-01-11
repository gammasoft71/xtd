# directory_assert_are_not_equal

Shows how to use [xtd::tunit::directory_assert::are_not_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1directory__assert.html#adb6a94ab27ef36eaec266d8abc4cc60d) method.

## Sources

[src/directory_assert_are_not_equal.cpp](src/directory_assert_are_not_equal.cpp)

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
    Expected: not "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
    But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
    Stack Trace: in |---OMITTED---|/directory_assert_are_not_equal.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
