# collection_assert_is_empty

Shows how to use [xtd::tunit::collection_assert::is_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assert.html#a9c7837d7a624e3dda086f3eceaf6fd4e) method.

## Sources

[src/collection_assert_is_empty.cpp](src/collection_assert_is_empty.cpp)

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
    Expected: <emtpy>
    But was:  < 1, 2, 3, 4 >
    Stack Trace: in |---OMITTED---|/collection_assert_is_empty.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
