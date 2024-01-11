# file_assume_exists

Shows how to use [xtd::tunit::file_assume::exists](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1file__assume.html#ad435ec0356abad2e9407c9c426a8498a) method.

## Sources

[src/file_assume_exists.cpp](src/file_assume_exists.cpp)

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
  ABORTED test.test_case_failed (0 ms total)
    Test aborted
    Expected: file exists
    But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T/tmp491024a4.tmp"
    Stack Trace: in |---OMITTED---|/file_assume_exists.cpp:15

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
