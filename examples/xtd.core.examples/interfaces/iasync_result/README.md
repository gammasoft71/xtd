# iasync_result

Shows how to use [xtd:: iasync_result](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1iasync__result.html) interface.

## Sources

[src/iasync_result.cpp](src/iasync_result.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Main thread 1 does some work.
Test method begins.
The call executed on thread 3, with return value "My call time was 3000.".
```
