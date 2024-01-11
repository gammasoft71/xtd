# assume_are_not_same

Shows how to use [xtd::tunit::assume::are_not_same](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a27df29a18fb50ab2793991a06d227276) method.

## Sources

[src/assume_are_not_same.cpp](src/assume_are_not_same.cpp)

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
    Test aborted
    Expected: not same as 24
    But was:  24
    Stack Trace: in |---OMITTED---|/assume_are_not_same.cpp:14

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
