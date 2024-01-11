# assert_ignore

Shows how to use [xtd::tunit::assert::ignore](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1base__assert.html#a43955cabe9ead93bb75087f7057b7b47) method.

## Sources

[src/assert_ignore.cpp](src/assert_ignore.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Start 1 test from 1 test case
Run tests:
  IGNORED test.test_case_ignored (0 ms total)
    Test ignored

Test results:
  IGNORED 1 test.
End 1 test from 1 test case ran. (0 ms total)
```
