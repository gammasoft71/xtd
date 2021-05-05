# hello_world_tunit

The classic first application "Hello, World!" with [xtd::tunit::console_unit_test](../../../../src/xtd.tunit/include/xtd/tunit/console_unit_test.h) class.

## Sources

[src/hello_world_tunit.cpp](src/hello_world_tunit.cpp)

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
  SUCCEED hello_world_tunit.create_string_from_literal (0 ms total)
  SUCCEED hello_world_tunit.create_string_from_chars (0 ms total)

Test results:
  SUCCEED 2 tests.
End 2 tests from 1 test case ran. (0 ms total)
```

