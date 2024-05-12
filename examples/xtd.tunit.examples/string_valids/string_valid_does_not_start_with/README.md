# string_valid_does_not_start_with

Shows how to use [xtd::tunit::string_valid::does_not_start_with](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__valid.html#a98101ae986546f99bc3645dbaace74f3) method.

## Sources

[src/string_valid_does_not_start_with.cpp](src/string_valid_does_not_start_with.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that does_not_start_with the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_failed (0 ms total)
    Expected: not string starting with "val"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_valid_does_not_start_with.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
