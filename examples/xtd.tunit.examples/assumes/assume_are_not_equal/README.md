# assume_are_not_equal

Shows how to use [xtd::tunit::assume::are_not_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a18979db548114b94daa0a137c154acb2) method.

## Sources

[src/assume_are_not_equal.cpp](src/assume_are_not_equal.cpp)

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
  ABORTED test.test_case_aborted (0 ms total)
    Test aborted
    Expected: not 24
    But was:  24
    Stack Trace: in |---OMITTED---|/assume_are_not_equal.cpp:13

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
