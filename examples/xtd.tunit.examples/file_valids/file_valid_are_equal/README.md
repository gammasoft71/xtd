# file_valid_are_equal

Shows how to use [xtd::tunit::file_valid::are_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1file__valid.html#afd1bb97a8f86b14d617c43a56d732ab6) method.

## Sources

[src/file_valid_are_equal.cpp](src/file_valid_are_equal.cpp)

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
    Expected: istream at offset 31 value e
    But was:  a
    Stack Trace: in |---OMITTED---|/file_valid_are_equal.cpp:14

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
