# call_once2

Shows how to use [call_once](https://gammasoft71.github.io/xtd/reference_guides/latest/structxtd_1_1call__once.html) struct.

## Sources

[src/call_once2.cpp](src/call_once2.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
(main) begin
  (thread_proc) call once 1 times
  (thread_proc) running 1 times
  (thread_proc) running 2 times
  (thread_proc) running 3 times
(main) end
```
