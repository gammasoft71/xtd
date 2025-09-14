# directory_valid_are_equal

Shows how to use [xtd::tunit::directory_valid::are_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1directory__valid.html#a1f33cee10e467037525d6a0a0d3db7a9) method.

## Sources

* [src/directory_valid_are_equal.cpp](src/directory_valid_are_equal.cpp)
* [CMakeLists.txt](CMakeLists.txt)

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
    Expected: "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T"
    But was:  "/System"
    Stack Trace: in |---OMITTED---|/directory_valid_are_equal.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
