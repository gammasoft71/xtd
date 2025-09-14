# assert_are_not_equal

Shows how to use [xtd::tunit::assert::are_not_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html#ace6f054ea16c209831e41bb3ea9b358c) method.

## Sources

* [src/assert_are_not_equal.cpp](src/assert_are_not_equal.cpp)
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
    Expected: not 24
    But was:  24
    Stack Trace: in |---OMITTED---|/assert_are_not_equal.cpp:13

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
