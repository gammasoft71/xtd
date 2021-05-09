# many_valids_and_asserts

Shows how to use [xtd::tunit::valid](../../../../src/xtd.tunit/include/xtd/valid.h) and [xtd::tunit::assert](../../../../src/xtd.tunit/include/xtd/assert.h) classes.

## Sources

[src/many_valids_and_asserts.cpp](src/many_valids_and_asserts.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

Start 1 test from 1 test case
Run tests:
  FAILED  test.test_case1 (0 ms total)
    Expected: string starting with "¡Hola,"
    But was:  "Hello, World!"
    Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:15
  FAILED  test.test_case1 (0 ms total)
    Expected: string ending with " mundo!"
    But was:  "Hello, World!"
    Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:16
  FAILED  test.test_case1 (0 ms total)
    Expected: collection containing a
    But was:  < 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!' >
    Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:17

Test results:
  FAILED  1 test.
End 1 test from 1 test case ran. (0 ms total)```

```
