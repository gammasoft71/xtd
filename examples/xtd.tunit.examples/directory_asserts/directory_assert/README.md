# directory_assert

Shows how to use [xtd::tunit::directory_assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1directory__assert.html) class.

## Sources

[src/directory_assert.cpp](src/directory_assert.cpp)

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
  SUCCEED test.test_case1 (0 ms total)
  FAILED  test.test_case2 (0 ms total)
    Expected: directory exists
    But was:  "unknown root folder/unknown sub folder/unknown xtd example folder"
    Stack Trace: in |---OMITTED---|/directory_assert.cpp:16
  FAILED  test.test_case3 (0 ms total)
    Expected: "|---OMITTED---|/Music"
    But was:  "|---OMITTED---|/Movies"
    Stack Trace: in |---OMITTED---|/directory_assert.cpp:20

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
