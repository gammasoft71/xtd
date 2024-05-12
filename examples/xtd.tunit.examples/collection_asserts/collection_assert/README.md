# collection_assert

Shows how to use [xtd::tunit::collection_assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assert.html) class.

## Sources

[src/collection_assert.cpp](src/collection_assert.cpp)

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
    Expected: <empty>
    But was:  < 1, 2, 3 >
    Stack Trace: in |---OMITTED---|/collection_assert.cpp:14
  FAILED  unit_tests::test.test_case3 (0 ms total)
    Expected: <ordered>
    But was:  < 1, 3, 2 >
    Stack Trace: in |---OMITTED---|/collection_assert.cpp:18

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
