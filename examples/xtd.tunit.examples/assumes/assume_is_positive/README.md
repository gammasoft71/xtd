# assume_is_positive

Shows how to use [xtd::tunit::assume::is_positive](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a16309851aaa0b65893dd10500188ecf7) method.

## Sources

[src/assume_is_positive.cpp](src/assume_is_positive.cpp)

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
    Expected: positive
    But was:  -1
    Stack Trace: in |---OMITTED---|/assume_is_positive.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
