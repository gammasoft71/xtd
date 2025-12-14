# assert_that

Shows how to use [xtd::tunit::assert_that](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert__that.html) method.

## Sources

* [src/assert_that.cpp](src/assert_that.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 3 tests from 1 test case
Run tests:
  SUCCEED unit_tests::test.test_case1 [< 1 ms]
  FAILED unit_tests::test.test_case2 [< 1 ms]
    Expected: false
    But was:  true
    Stack Trace: in |---OMITTED---|/assert_that.cpp:10
  FAILED  unit_tests::test.test_case3 [< 1 ms]
    Expected: No Exception to be thrown
    But was:  <std::range_error>
    Stack Trace: in |---OMITTED---|/assert_that.cpp:14

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. [0.0006 seconds]
```
