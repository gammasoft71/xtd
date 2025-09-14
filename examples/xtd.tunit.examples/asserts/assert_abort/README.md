# assert_abort

Shows how to use [xtd::tunit::assert::abort](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1base__assert.html#a12d0a475e319dc4ad8a7f7823eab9cd4) method.

## Sources

* [src/assert_abort.cpp](src/assert_abort.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 1 test from 1 test case
Run tests:
  ABORTED test.test_case_aborted (0 ms total)
    Test aborted

Test results:
  ABORTED 1 test.
End 1 test from 1 test case ran. (0 ms total)
```
