# concurrent_stack

Shows how to use [xtd::collections::concurrent::concurrent_stack](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1concurrent_1_1concurrent__stack.html) class.

## Sources

* [src/concurrent_stack.cpp](src/concurrent_stack.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
try_peek() saw 9999 on top of the stack.
Cleared the stack.
Task started on 6
Task started on 7
Task started on 8
Task started on 9
Task started on 10
Task ended on 9
Task ended on 10
Task ended on 6
Task ended on 7
Task ended on 8
```
