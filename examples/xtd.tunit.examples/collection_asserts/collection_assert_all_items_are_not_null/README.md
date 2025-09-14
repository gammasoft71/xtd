# collection_assert_all_items_are_not_null

Shows how to use [xtd::tunit::collection_assert::all_items_are_not_null](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assert.html#af705588fd1b6ec68f4f1703c98993021) method.

## Sources

* [src/collection_assert_all_items_are_not_null.cpp](src/collection_assert_all_items_are_not_null.cpp)
* [CMakeLists.txt](CMakeLists.txt)

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
    Expected: all items are not null
    But was:  < 0x7ffeefbfc8d4, 0x7ffeefbfc8d0, 0x0 >
    Stack Trace: in |---OMITTED---|/collection_assert_all_items_are_not_null.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
