# collection_assert_contains

Shows how to use [xtd::tunit::collection_assert::contains](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assert.html#abf1433eff0dea381a6b7a3d90be8f706) method.

## Sources

[src/collection_assert_contains.cpp](src/collection_assert_contains.cpp)

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
  SUCCEED test.test_case_succeed (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: contains < 1, 2, 6 >
    But was:  < 1, 2, 3, 4 >
    Stack Trace: in |---OMITTED---|/collection_assert_contains.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
