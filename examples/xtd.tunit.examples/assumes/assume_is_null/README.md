# assume_is_null

Shows how to use [xtd::tunit::assume::is_null](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#aa6bec68f958ef34957406d26146067de) method.

## Sources

[src/assume_is_null.cpp](src/assume_is_null.cpp)

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
    Expected: null
    But was:  not null
    Stack Trace: in |---OMITTED---|/assume_is_null.cpp:15

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
