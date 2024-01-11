# assume_is_not_zero

Shows how to use [xtd::tunit::assume::is_not_zero](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a56338a72e52bb2f534be14d95ce1dcda) method.

## Sources

[src/assume_is_not_zero.cpp](src/assume_is_not_zero.cpp)

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
  ABORTED test.test_case_aborted (0 ms total)
    Expected: not zero
    But was:  0
    Stack Trace: in |---OMITTED---|/assume_is_not_zero.cpp:15

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
