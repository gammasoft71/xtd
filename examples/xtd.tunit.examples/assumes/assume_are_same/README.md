# assume_are_same

Shows how to use [xtd::tunit::assume::are_same](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a1628a6dc2392b247c2034c84c03d08df) method.

## Sources

[src/assume_are_same.cpp](src/assume_are_same.cpp)

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
    Expected: same as 24
    But was:  24
    Stack Trace: in |---OMITTED---|/assume_are_same.cpp:14

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
