# assume_does_not_throw

Shows how to use [xtd::tunit::assume::does_not_throw](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a37d29a60f5757e6afe290d7c6e6cb7ca) method.

## Sources

[src/assume_does_not_throw.cpp](src/assume_does_not_throw.cpp)

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
  ABORTED test.test_case_aborted (0 ms total)
    Expected: No Exception to be thrown
    But was:  <std::out_of_range>
    Stack Trace: in |---OMITTED---|/assume_does_not_throw.cpp:15

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
