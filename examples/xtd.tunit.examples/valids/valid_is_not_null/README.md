# valid_is_not_null

Shows how to use [xtd::tunit::valid::is_not_null](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html#af2c20ddce72120011e2a8e2cfae4154a) method.

## Sources

[src/valid_is_not_null.cpp](src/valid_is_not_null.cpp)

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
  FAILED  test.test_case_failed (0 ms total)
    Expected: not null
    But was:  null
    Stack Trace: in |---OMITTED---|/valid_is_not_null.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
