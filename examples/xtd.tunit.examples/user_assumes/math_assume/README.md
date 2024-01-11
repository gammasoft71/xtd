# math_assume

Shows how to create your own [xtd::tunit::assume](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html) class.

## Sources

[src/math_assume.cpp](src/math_assume.cpp)

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
  SUCCEED math_test.test_case_success (0 ms total)
  ABORTED math_test.test_case_aborted (0 ms total)
    Test aborted
    Expected: greater of 100
    But was:  20
    Stack Trace: in |---OMITTED---|/math_assume.cpp:47

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
