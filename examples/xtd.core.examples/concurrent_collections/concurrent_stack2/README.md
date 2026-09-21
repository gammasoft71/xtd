# concurrent_stack2

Shows how to use [xtd::collections::concurrent::concurrent_stack](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1concurrent_1_1concurrent__stack.html) class.

## Sources

* [src/concurrent_stack2.cpp](src/concurrent_stack2.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Pushing an array of ints from 0 to 999
Pushing an array of ints from 2000 to 2999
Pushing an array of ints from 3000 to 3999
Pushing an array of ints from 1000 to 1999
Try pop range expected 1000, got 1000.
Try pop range expected 1000, got 1000.
Try pop range expected 1000, got 1000.
Try pop range expected 1000, got 1000.
Expected a range of 3000 to 3999. Got 3000 to 3999
Expected a range of 1000 to 1999. Got 1000 to 1999
Expected a range of 0 to 999. Got 0 to 999
Expected a range of 2000 to 2999. Got 2000 to 2999
```
