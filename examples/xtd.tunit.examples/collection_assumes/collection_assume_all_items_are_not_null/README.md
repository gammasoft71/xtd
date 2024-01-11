# collection_assume_all_items_are_not_null

Shows how to use [xtd::tunit::collection_assume::all_items_are_not_null](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assume.html#a9162944acdb21f93e56456c9ebed79f4) method.

## Sources

[src/collection_assume_all_items_are_not_null.cpp](src/collection_assume_all_items_are_not_null.cpp)

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
  ABORTED test.test_case_aborted (0 ms total)
    Test aborted
    Expected: all items are not null
    But was:  < 0x7ffeefbfc8d4, 0x7ffeefbfc8d0, 0x0 >
    Stack Trace: in |---OMITTED---|/collection_assume_all_items_are_not_null.cpp:15

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
