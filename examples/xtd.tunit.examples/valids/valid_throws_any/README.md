# valid_throws_any

Shows how to use [xtd::tunit::valid::throws_any](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html#a1efbf499859e744ebeb073ba0c84e642) method.

## Sources

[src/valid_throws_any.cpp](src/valid_throws_any.cpp)

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
    Expected: <exception>
    But was:  <nothing>
    Stack Trace: in |---OMITTED---|/valid_throws_any.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
