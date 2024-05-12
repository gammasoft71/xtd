# directory_assume

Shows how to use [xtd::tunit::directory_assume](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1directory__assume.html) class.

## Sources

[src/directory_assume.cpp](src/directory_assume.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 3 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case1 (0 ms total)
  ABORTED test.test_case2 (0 ms total)
    Test aborted
    Expected: directory exists
    But was:  "unknown root folder/unknown sub folder/unknown xtd example folder"
    Stack Trace: in |---OMITTED---|/directory_assume.cpp:16
  ABORTED test.test_case3 (0 ms total)
    Test aborted
    Expected: "|---OMITTED---|/Music"
    But was:  "|---OMITTED---|/Movies"
    Stack Trace: in |---OMITTED---|/directory_assume.cpp:20

Test results:
  SUCCEED 1 test.
  ABORTED 2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
