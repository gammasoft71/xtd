# string_assume_does_not_contain

Shows how to use [xtd::tunit::string_assume::does_not_contain](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assume.html#a9c2ac5bdb0a9983d7c32d4cd21f97d0e) method.

## Sources

[src/string_assume_does_not_contain.cpp](src/string_assume_does_not_contain.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that does_not_contain the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  ABORTED test.test_case_aborted (0 ms total)
    Test aborted
    Expected: not string containing "alu"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_assume_does_not_contain.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
