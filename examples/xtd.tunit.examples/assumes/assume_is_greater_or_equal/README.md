# assume_is_greater_or_equal

Shows how to use [xtd::tunit::assume::is_greater_or_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a3b7e300416362c4661f4d3758d84561b) method.

## Sources

[src/assume_is_greater_or_equal.cpp](src/assume_is_greater_or_equal.cpp)

[CMakeLists.txt](CMakeLists.txt)

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
  ABORTED test.test_case_aborted (0 ms total)
    Expected: greater than or equal to 48
    But was:  24
    Stack Trace: in |---OMITTED---|/assume_is_greater_or_equal.cpp:18

Test results:
  SUCCEED 2 tests.
  ABORTED 1 test.
End 3 tests from 1 test case ran. (0 ms total)
```
