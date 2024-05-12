# string_valid_contains

Shows how to use [xtd::tunit::string_valid::contains](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__valid.html#a0799b37471d8dd62f5db65935bcf15a2) method.

## Sources

[src/string_valid_contains.cpp](src/string_valid_contains.cpp)

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
  FAILED  unit_tests::test.test_case_failed (0 ms total)
    Expected: string containing "zor"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_valid_contains.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
