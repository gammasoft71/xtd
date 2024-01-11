# collection_assert_are_not_equal

Shows how to use [xtd::tunit::collection_assert::are_not_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assume.html#ac4a06f518139e34519771a3f32c370fa) method.

## Sources

[src/collection_assert_are_not_equal.cpp](src/collection_assert_are_not_equal.cpp)

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
    Expected: not < 4, 3, 2, 1 >
    But was:  < 1, 2, 3, 4 >
    Stack Trace: in |---OMITTED---|/collection_assert_are_not_equal.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
