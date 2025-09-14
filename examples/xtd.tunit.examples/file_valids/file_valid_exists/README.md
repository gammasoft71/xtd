# file_valid_exists

Shows how to use [xtd::tunit::file_valid::exists](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1file__valid.html#a59ee89d189f39f33115da632f6045b6b) method.

## Sources

* [src/file_valid_exists.cpp](src/file_valid_exists.cpp)
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
    Expected: file exists
    But was:  "/var/folders/xg/2fvdl7v939g9kbp8xn1dpgg00000gn/T/tmp491024a4.tmp"
    Stack Trace: in |---OMITTED---|/file_valid_exists.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
