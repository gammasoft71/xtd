# valid_is_not_zero

Shows how to use [xtd::tunit::valid::is_not_zero](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html#a2b6ced238a6f4dfefc171c39f330cb78) method.

## Sources

[src/valid_is_not_zero.cpp](src/valid_is_not_zero.cpp)

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
    Expected: not zero
    But was:  0
    Stack Trace: in |---OMITTED---|/valid_is_not_zero.cpp:15

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
