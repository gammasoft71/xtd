# valid

Shows how to use [xtd::tunit::valid](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html) class.

## Sources

* [src/valid.cpp](src/valid.cpp)
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
  SUCCEED unit_tests::test.test_case1 (0 ms total)
  FAILED  unit_tests::test.test_case2 (0 ms total)
    Expected: false
    But was:  true
    Stack Trace: in |---OMITTED---|/valid.cpp:14
  FAILED  unit_tests::test.test_case3 (0 ms total)
    Expected: No Exception to be thrown
    But was:  <std::range_error>
    Stack Trace: in |---OMITTED---|/valid.cpp:18

Test results:
  SUCCEED 1 test.
  FAILED  2 tests.
End 3 tests from 1 test case ran. (0 ms total)
```
