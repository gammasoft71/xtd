# collection_valid_all_items_are_unique

Shows how to use [xtd::tunit::collection_valid::all_items_are_unique](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__valid.html#a4ab5dbda7248000d856488f784ecba1f) method.

## Sources

[src/collection_valid_all_items_are_unique.cpp](src/collection_valid_all_items_are_unique.cpp)

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
    Expected: all items are unique
    But was:  < 1, 2, 3, 4, 1 >
    Stack Trace: in |---OMITTED---|/collection_valid_all_items_are_unique.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
