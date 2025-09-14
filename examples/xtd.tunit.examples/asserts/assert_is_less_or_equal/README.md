# assert_is_less_or_equal

Shows how to use [xtd::tunit::assert::is_less_or_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#a542f581b00cd70e620841c44d97f1406) method.

## Sources

* [src/assert_is_less_or_equal.cpp](src/assert_is_less_or_equal.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 3 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case_succeed1 (0 ms total)
  SUCCEED unit_tests::test.test_case_succeed2 (0 ms total)
  FAILED  unit_tests::test.test_case_failed (0 ms total)
    Expected: less than or equal to 12
    But was:  24
    Stack Trace: in |---OMITTED---|/assert_is_less_or_equal.cpp:18

Test results:
  SUCCEED 2 tests.
  FAILED  1 test.
End 3 tests from 1 test case ran. (0 ms total)
```
