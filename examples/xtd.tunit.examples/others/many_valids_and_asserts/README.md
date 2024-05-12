# many_valids_and_asserts

Shows how to use [xtd::tunit::valid](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1valid.html) and [xtd::tunit::assert](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert.html) classes.

## Sources

[src/many_valids_and_asserts.cpp](src/many_valids_and_asserts.cpp)

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
  FAILED  unit_tests::test.test_case1 (0 ms total)
    Expected: string starting with "¡Hola,"
    But was:  "Hello, World!"
    Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:15
  FAILED  unit_tests::test.test_case1 (0 ms total)
    Expected: string ending with " mundo!"
    But was:  "Hello, World!"
    Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:16
  FAILED  unit_tests::test.test_case1 (0 ms total)
    Expected: collection containing a
    But was:  < 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!' >
    Stack Trace: in |---OMITTED---|/many_valids_and_asserts.cpp:17

Test results:
  FAILED  1 test.
End 1 test from 1 test case ran. (0 ms total)
```
