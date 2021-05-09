# class_without_insert_stream_operator

Shows how to use [xtd::tunit::assert](../../../../src/xtd.tunit/include/xtd/assert.h) class with a class to test that does not contain insert stream operator.

## Sources

[src/class_without_insert_stream_operator.cpp](src/class_without_insert_stream_operator.cpp)

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
  FAILED  test.test_case_failed (0 ms total)
    Expected: 4-byte object <2A-00 00-00>
    But was:  4-byte object <18-00 00-00>
    Stack Trace: in |---OMITTED---|/class_without_insert_stream_operator.cpp:30

Test results:
  SUCCEED 1 test.
  FAILED  1 test.
End 2 tests from 1 test case ran. (0 ms total)
```
