# file_assume_are_equal

Shows how to use [xtd::tunit::file_assume::are_equal](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1file__assume.html#ac8d2cb7182091f09fe9cd5375f9edb53) method.

## Sources

* [src/file_assume_are_equal.cpp](src/file_assume_are_equal.cpp)
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
  ABORTED test.test_case_failed (0 ms total)
    Test aborted
    Expected: istream at offset 32 value e
    But was:  a
    Stack Trace: in |---OMITTED---|/file_assume_are_equal.cpp:14

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
