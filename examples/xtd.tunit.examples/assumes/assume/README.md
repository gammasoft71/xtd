# assume

Shows how to use [xtd::tunit::assume](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html) class.

## Sources

[src/assume.cpp](src/assume.cpp)

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
    Expected: false
    But was:  true
    Stack Trace: in |---OMITTED---|/assume.cpp:14
  ABORTED test.test_case3 (0 ms total)
    Test aborted
    Expected: No Exception to be thrown
    But was:  <std::range_error>
    Stack Trace: in |---OMITTED---|/assume.cpp:18

Test results:
  SUCCEED 1 test.
  ABORTED 2 tests.
End 3 tests from 1 test case ran. (0 ms total)

```
