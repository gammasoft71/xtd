# assume_is_true

Shows how to use [xtd::tunit::assume::is_true](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a5c48682d12f9aa2e4d1a2f3a8f5d3f37) method.

## Sources

[src/assume_is_true.cpp](src/assume_is_true.cpp)

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
    Expected: true
    But was:  false
    Stack Trace: in |---OMITTED---|/assume_is_true.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
