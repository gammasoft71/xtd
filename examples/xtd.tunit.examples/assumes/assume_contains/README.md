# assume_contains

Shows how to use [xtd::tunit::assume::contains](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#af46db342cef45ea859709a544922585d) method.

## Sources

[src/assume_contains.cpp](src/assume_contains.cpp)

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
  SUCCEED test.test_case_collection_succeed (0 ms total)
  ABORTED test.test_case_collection_aborted (0 ms total)
    Expected: collection containing 4
    But was:  < 0, 1, 2, 3 >
    Stack Trace: in |---OMITTED---|/assume_contains.cpp:14
  SUCCEED test.test_case_string_succeed (0 ms total)
  ABORTED test.test_case_string_aborted (0 ms total)
    Expected: collection containing a
    But was:  < 's', 't', 'r', 'i', 'n', 'g' >
    Stack Trace: in |---OMITTED---|/assume_contains.cpp:22

Test results:
  SUCCEED 2 tests.
  ABORTED 2 tests.
End 4 tests from 1 test case ran. (0 ms total)
```
