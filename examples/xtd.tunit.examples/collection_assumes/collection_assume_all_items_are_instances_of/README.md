# collection_assume_all_items_are_instances_of

Shows how to use [xtd::tunit::collection_assume::all_items_are_instances_of](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1collection__assume.html#a76fefbb4774d2ada9c0f74fbc9efe1fc) method.

## Sources

[src/collection_assume_all_items_are_instances_of.cpp](src/collection_assume_all_items_are_instances_of.cpp)

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
  SUCCEED unit_tests::test.test_case_succeed (0 ms total)
  ABORTED test.test_case_aborted (0 ms total)
    Test aborted
    Expected: all items instance of <std::basic_ostream<char, std::char_traits<char> >*>
    But was:  < 8-byte object <78-37 1D-8C FF-7F 00-00>, 8-byte object <B8-38 1D-8C FF-7F 00-00>, 8-byte object <30-36 1D-8C FF-7F 00-00> >
    Stack Trace: in |---OMITTED---|/collection_assume_all_items_are_instances_of.cpp:13

Test results:
  SUCCEED 1 test.
  ABORTED 1 test.
End 2 tests from 1 test case ran. (1 ms total)
```
