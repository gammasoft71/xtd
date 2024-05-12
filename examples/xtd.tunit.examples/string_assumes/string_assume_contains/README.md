# string_assume_contains

Shows how to use [xtd::tunit::string_assume::contains](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assume.html#a8f9c13834c29daf12f503b48589c33d9) method.

## Sources

[src/string_assume_contains.cpp](src/string_assume_contains.cpp)

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
    Expected: string containing "zor"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_assume_contains.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
