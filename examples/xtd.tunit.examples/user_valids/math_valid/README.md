# math_valid

Shows how to create your own [xtd::tunit::valid](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html) class.

## Sources

[src/math_valid.cpp](src/math_valid.cpp)

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
  FAILED  math_test.test_case_failed (0 ms total)
    Expected: greater of 100
    But was:  20
    Stack Trace: in |---OMITTED---|/math_valid.cpp:47

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
