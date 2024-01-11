# assert_is_zero

Shows how to use [xtd::tunit::assert::is_zero](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#ac658f32c77d98010fe1d6936c8afabcf) method.

## Sources

[src/assert_is_zero.cpp](src/assert_is_zero.cpp)

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
    Expected: zero
    But was:  42
    Stack Trace: in |---OMITTED---|/assert_is_zero.cpp:16

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
