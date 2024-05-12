# string_assume

Shows how to use [xtd::tunit::string_assume](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assume.html) class.

## Sources

[src/string_assume.cpp](src/string_assume.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 3 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case1 (0 ms total)
  ABORTED test.test_case2 (0 ms total)
    Test aborted
    Expected: string containing "item"
    But was:  "A string value"
    Stack Trace: in |---OMITTED---|/string_assume.cpp:17
  ABORTED test.test_case3 (0 ms total)
    Expected: string matching "item$"
    But was:  "A string value"
    Stack Trace: in |---OMITTED---|/string_assume.cpp:22

Test results:
  SUCCEED 1 test.
  ABORTED 2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
