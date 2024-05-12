# string_assume_are_equal_ignoring_case

Shows how to use [xtd::tunit::string_assume::are_equal_ignoring_case](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assume.html#a23d3241ef65211b87f9f67cbd63efc40) method.

## Sources

[src/string_assume_are_equal_ignoring_case.cpp](src/string_assume_are_equal_ignoring_case.cpp)

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
    Expected: "key", ignoring case
    But was:  "VALUE"
    Stack Trace: in |---OMITTED---|/string_assume_are_equal_ignoring_case.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
