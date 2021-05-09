# create_gtest_like_event_listener

Shows how to create your own [xtd::tunit::event_listener](../../../../src/xtd.tunit/include/xtd/event_listener.h) class.

## Sources

[src/create_gtest_like_event_listener.cpp](src/create_gtest_like_event_listener.cpp)

[CMakeLists.txt](CMakeLists.txt)

# Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

# Output

```
[==========] Running 3 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 3 tests from test
[ RUN      ] test.test_case1
[       OK ] test.test_case1 (0 ms)8
[ RUN      ] test.test_case2
[       OK ] test.test_case2 (0 ms)
[ RUN      ] test.test_case3
!---OMITTED---!/create_gtest_like_event_listener.cpp:139: Failure
  Actual: false
Expected: true
Your message...
[  FAILED  ] ManualTest.TestCase3 (0 ms)
[----------] 3 tests from test (0 ms)

[----------] Global test environment tear-down
[==========] 3 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 2 tests.
[  FAILED  ] 1 test, listed below:
[  FAILED  ] test.test_case3

 1 FAILED TEST
  YOU HAVE 1 DISABLED TESTS
```
