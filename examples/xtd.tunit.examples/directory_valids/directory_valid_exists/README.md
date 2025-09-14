# directory_valid_exists

Shows how to use [xtd::tunit::directory_valid::exists](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1directory__valid.html#a16601aa9bc905b912c48c2fed1c18800) method.

## Sources

* [src/directory_valid_exists.cpp](src/directory_valid_exists.cpp)
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
    Expected: directory exists
    But was:  "unknown folder 1/unknown folder 2/unknown folder 3"
    Stack Trace: in |---OMITTED---|/directory_valid_exists.cpp:14

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
