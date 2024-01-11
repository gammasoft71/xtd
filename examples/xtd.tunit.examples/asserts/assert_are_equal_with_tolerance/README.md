# assert_are_equal_with_tolerance

Shows how to use [xtd::tunit::assert::are_equal_with_tolerance](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#a026c2256bbe03ed84b6c118e0184a419) method.

## Sources

[src/assert_are_equal_with_tolerance.cpp](src/assert_are_equal_with_tolerance.cpp)

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
    Expected: 0.6
    But was:  0.6
    Stack Trace: in |---OMITTED---|/assert_are_equal_with_tolerance.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
