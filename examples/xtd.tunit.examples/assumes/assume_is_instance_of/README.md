# assert_is_instance_of

Shows how to use [xtd::tunit::assert::is_instance_of](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assume.html#a4a507fca67fdd13672a40d376e9b2250) method.

## Sources

[src/assert_is_instance_of.cpp](src/assert_is_instance_of.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 2 tests from 1 test case
Run tests:
  SUCCEED test.test_case_succeed (0 ms total)
  ABORTED test.test_case_failed (0 ms total)
    Expected: instance of <std::bad_cast>
    But was:  <std::invalid_argument>
    Stack Trace: in |---OMITTED---|/assert_is_instance_of.cpp:16

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
