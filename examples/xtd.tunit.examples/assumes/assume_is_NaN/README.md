# assume_is_NaN

Shows how to use [xtd::tunit::assume::is_NaN](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#ae0feb57a4c084d50894849e18d085788) method.

## Sources

[src/assume_is_NaN.cpp](src/assume_is_NaN.cpp)

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
    Expected: NaN
    But was:  3.14159
    Stack Trace: in |---OMITTED---|/assume_is_NaN.cpp:15

// Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
