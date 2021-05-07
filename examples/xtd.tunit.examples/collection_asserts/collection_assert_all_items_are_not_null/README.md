# collection_assert_all_items_are_not_null

Shows how to use [xtd::tunit::collection_assert::all_items_are_not_null](../../../../src/xtd.tunit/include/xtd/collection_assert.h) method.

## Sources

[src/collection_assert_all_items_are_not_null.cpp](src/collection_assert_all_items_are_not_null.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  FAILED  test.test_case_Failed (0 ms total)
    Expected: all items are not null
    But was:  < 0x7ffeefbfc8d4, 0x7ffeefbfc8d0, 0x0 >
    Stack Trace: in |---OMITTED---|/collection_assert_all_items_are_not_null.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
