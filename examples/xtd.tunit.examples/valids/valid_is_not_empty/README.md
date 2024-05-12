# valid_is_not_empty

Shows how to use [xtd::tunit::valid::is_not_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html#a5873770dc074c8668b060b1ac5c436a2) method.

## Sources

[src/valid_is_not_empty.cpp](src/valid_is_not_empty.cpp)

[CMakeLists.txt](CMakeLists.txt)

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
    Expected: collection not <empty>
    But was:  <empty>
    Stack Trace: in |---OMITTED---|/valid_is_not_empty.cpp:13
  SUCCEED unit_tests::test.test_case_string_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_string_failed (0 ms total)
    Expected: collection not <empty>
    But was:  <empty>
    Stack Trace: in |---OMITTED---|/valid_is_not_empty.cpp:21

Test results:
  SUCCEED 2 tests.
  FAILED  2 tests.
End 4 tests from 1 test case ran. (0 ms total)
```
