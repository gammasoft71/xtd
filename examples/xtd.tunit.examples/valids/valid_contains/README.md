# valid_contains

Shows how to use [xtd::tunit::valid::contains](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html#a3ac34fba7dcf30ee9d2205f361ab1857) method.

## Sources

[src/valid_contains.cpp](src/valid_contains.cpp)

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
    Expected: collection containing 4
    But was:  < 0, 1, 2, 3 >
    Stack Trace: in |---OMITTED---|/valid_contains.cpp:14
  SUCCEED unit_tests::test.test_case_string_succeed (0 ms total)
  FAILED  unit_tests::test.test_case_string_failed (0 ms total)
    Expected: collection containing a
    But was:  < 's', 't', 'r', 'i', 'n', 'g' >
    Stack Trace: in |---OMITTED---|/valid_contains.cpp:22

Test results:
  SUCCEED 2 tests.
  FAILED  2 tests.
End 4 tests from 1 test case ran. (0 ms total)
```
