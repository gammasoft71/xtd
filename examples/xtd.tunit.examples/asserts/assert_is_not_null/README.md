# assert_is_not_null

Shows how to use [xtd::tunit::assert::is_not_null](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#ab75c42c523609e6036cd25cedbb690dd) method.

## Sources

[src/assert_is_not_null.cpp](src/assert_is_not_null.cpp)

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
    Expected: not null
    But was:  null
    Stack Trace: in |---OMITTED---|/assert_is_not_null.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
