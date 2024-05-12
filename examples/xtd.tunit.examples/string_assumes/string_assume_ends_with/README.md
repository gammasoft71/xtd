# string_assume_ends_with

Shows how to use [xtd::tunit::string_assume::ends_with](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1string__assume.html#abf7d1827c174e209a45901592bc76117) method.

## Sources

[src/string_assume_ends_with.cpp](src/string_assume_ends_with.cpp)

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
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  ABORTED test.test_case_aborted (0 ms total)
    Test aborted
    Expected: string ending with "val"
    But was:  "value"
    Stack Trace: in |---OMITTED---|/string_assume_ends_with.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
