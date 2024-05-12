# collection_valid_is_empty

Shows how to use [xtd::tunit::collection_valid::is_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__valid.html#a179eeadd8e0002a0ced692583bc96377) method.

## Sources

[src/collection_valid_is_empty.cpp](src/collection_valid_is_empty.cpp)

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
    Expected: <emtpy>
    But was:  < 1, 2, 3, 4 >
    Stack Trace: in |---OMITTED---|/collection_valid_is_empty.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
