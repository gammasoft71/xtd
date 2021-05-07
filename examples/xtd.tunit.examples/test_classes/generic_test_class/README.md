# generic_test_class

Shows how to use generic [xtd::tunit::test_class](../../../../src/xtd.tunit/include/xtd/test_class.h) class.

## Sources

[src/generic_test_class.cpp](src/generic_test_class.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
Start 5 tests from 5 test cases
Run tests:
  SUCCEED test<bool>.test_max_value (0 ms total)
  SUCCEED test<int>.test_max_value (0 ms total)
  SUCCEED test<long int>.test_max_value (0 ms total)
  SUCCEED test<int8_t>.test_max_value (0 ms total)
  FAILED  test<uint8_t>.test_max_value (0 ms total)
    expect max value for this type is not defined.
    Stack Trace: in |---OMITTED---|/generic_test_class.cpp:39

Test results:
  SUCCEED 4 tests.
  FAILED  1 test.
End 5 tests from 5 test cases ran. (0 ms total)
```
