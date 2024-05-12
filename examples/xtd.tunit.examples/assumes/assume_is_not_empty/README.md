# assume_is_not_empty

Shows how to use [xtd::tunit::assume::is_not_empty](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#af240b85297b3a31a53707a017d002d0e) method.

## Sources

[src/assume_is_not_empty.cpp](src/assume_is_not_empty.cpp)

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
  ABORTED test.test_case_collection_aborted (0 ms total)
    Expected: collection not <empty>
    But was:  <empty>
    Stack Trace: in |---OMITTED---|/assume_is_not_empty.cpp:13
  SUCCEED unit_tests::test.test_case_string_succeed (0 ms total)
  ABORTED test.test_case_string_aborted (0 ms total)
    Expected: collection not <empty>
    But was:  <empty>
    Stack Trace: in |---OMITTED---|/assume_is_not_empty.cpp:21

Test results:
  SUCCEED 2 tests.
  ABORTED 2 tests.
End 4 tests from 1 test case ran. (0 ms total)
```
