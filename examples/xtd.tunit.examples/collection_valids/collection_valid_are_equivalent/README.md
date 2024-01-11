# collection_valid_are_equivalent

Shows how to use [xtd::tunit::collection_valid::are_equivalent](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__valid.html#a19baa1c5befef17048b447234959733e) method.

## Sources

[src/collection_valid_are_equivalent.cpp](src/collection_valid_are_equivalent.cpp)

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
    Expected: equivalent < 1, 2, 3, 5 >
    But was:  < 1, 2, 3, 4 >
    Stack Trace: in |---OMITTED---|/collection_valid_are_equivalent.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
