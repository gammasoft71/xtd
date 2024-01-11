# string_assert_ends_with

Shows how to use [xtd::tunit::string_assert::ends_with](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assert.html#aa48fa8ff8f40e30c289aedcd1941b482) method.

## Sources

[src/string_assert_ends_with.cpp](src/string_assert_ends_with.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that ends_with the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  FAILED  test.test_case_failed (0 ms total)
    Expected: string ending with "val"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_assert_ends_with.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
