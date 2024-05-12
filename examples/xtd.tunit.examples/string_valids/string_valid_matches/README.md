# string_valid_matches

Shows how to use [xtd::tunit::string_valid::matches](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__valid.html#a96767fa89a4c5d96149b6abbd5752a70) method.

## Sources

[src/string_valid_matches.cpp](src/string_valid_matches.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that matches the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_failed (0 ms total)
    Expected: string matching "^item"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_valid_matches.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
