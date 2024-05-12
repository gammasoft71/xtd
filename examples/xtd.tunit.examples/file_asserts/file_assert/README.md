# file_assert

Shows how to use [xtd::tunit::file_assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1file__assert.html) class.

## Sources

[src/file_assert.cpp](src/file_assert.cpp)

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
  FAILED  unit_tests::test.test_case2 (0 ms total)
    Expected: file exists
    But was:  "t35uk5my.8v2"
    Stack Trace: in |---OMITTED---|/file_assert.cpp:18
  FAILED  unit_tests::test.test_case3 (0 ms total)
    Expected: istream at offset 32 value e
    But was:  a
    Stack Trace: in |---OMITTED---|/file_assert.cpp:24

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
