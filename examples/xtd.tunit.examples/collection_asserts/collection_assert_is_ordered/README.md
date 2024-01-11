# collection_assert_is_ordered

Shows how to use [xtd::tunit::collection_assert::is_ordered](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assert.html#a5af8ad7461b20cf4a1b6528377a5be0f) method.

## Sources

[src/collection_assert_is_ordered.cpp](src/collection_assert_is_ordered.cpp)

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
    Expected: <ordered>
    But was:  < 1, 2, 4, 3 >
    Stack Trace: in |---OMITTED---|/collection_assert_is_ordered.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
