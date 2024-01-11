# assert_throws

Shows how to use [xtd::tunit::assert::throws](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#a5ca1a96c7e4d73f154520a916a087a07) method.

## Sources

[src/assert_throws.cpp](src/assert_throws.cpp)

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
    Expected: <std::out_of_range>
    But was:  <nothing>
    Stack Trace: in |---OMITTED---|/assert_throws.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
