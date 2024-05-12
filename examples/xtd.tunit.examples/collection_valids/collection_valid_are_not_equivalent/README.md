# collection_valid_are_not_equivalent

Shows how to use [xtd::tunit::collection_valid::are_not_equivalent](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__valid.html#ac2637f79665451999e8e54701152a3f3) method.

## Sources

[src/collection_valid_are_not_equivalent.cpp](src/collection_valid_are_not_equivalent.cpp)

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
    Expected: not equivalent < 4, 3, 2, 1 >
    But was:  < 1, 2, 3, 4 >
    Stack Trace: in |---OMITTED---|/collection_valid_are_not_equivalent.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
