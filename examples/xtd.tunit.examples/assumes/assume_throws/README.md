# assume_throws

Shows how to use [xtd::tunit::assume::throws](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a4511c842b01e454dcbf461066df124e2) method.

## Sources

[src/assume_throws.cpp](src/assume_throws.cpp)

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
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  ABORTED test.test_case_aborted (0 ms total)
    Expected: <std::out_of_range>
    But was:  <nothing>
    Stack Trace: in |---OMITTED---|/assume_throws.cpp:15

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
