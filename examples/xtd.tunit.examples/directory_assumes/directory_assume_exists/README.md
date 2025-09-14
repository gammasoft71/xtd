# directory_assume_exists

Shows how to use [xtd::tunit::directory_assume::exists](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1directory__assume.html#ad1a19a732791903f424e012018d6c72d) method.

## Sources

* [src/directory_assume_exists.cpp](src/directory_assume_exists.cpp)
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
  ABORTED test.test_case_aborted (0 ms total)
    Test aborted
    Expected: directory exists
    But was:  "unknown folder 1/unknown folder 2/unknown folder 3"
    Stack Trace: in |---OMITTED---|/directory_assume_exists.cpp:14

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
