# assert_is_empty

Shows how to use [xtd::tunit::assert::is_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#a8dcdfb694da51cbb85aa7d5d70542d79) method.

## Sources

* [src/assert_is_empty.cpp](src/assert_is_empty.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 4 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case_collection_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_collection_failed (0 ms total)
    Expected: collection <empty>
    But was:  < 0, 1, 2, 3 >
    Stack Trace: in |---OMITTED---|/assert_is_empty.cpp:13
  SUCCEED unit_tests::test.test_case_string_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_string_failed (0 ms total)
    Expected: collection <empty>
    But was:  < 's', 't', 'r', 'i', 'n', 'g' >
    Stack Trace: in |---OMITTED---|/assert_is_empty.cpp:21

Test results:
  SUCCEED 2 tests.
  FAILED  2 tests.
End 4 tests from 1 test case ran. (0 ms total)
```
