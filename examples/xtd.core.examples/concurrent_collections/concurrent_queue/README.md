# concurrent_queue

Shows how to use [xtd::collections::concurrent::concurrent_queue](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1concurrent_1_1concurrent__queue.html) class.

## Sources

* [src/concurrent_queue.cpp](src/concurrent_queue.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
After enqueueing
  items.length = 100
  items = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100]
After dequeueing
  items.length = 50
  items = [6, 7, 8, 9, 10, 16, 17, 18, 19, 20, 26, 27, 28, 29, 30, 36, 37, 38, 39, 40, 46, 47, 48, 49, 50, 56, 57, 58, 59, 60, 66, 67, 68, 69, 70, 76, 77, 78, 79, 80, 86, 87, 88, 89, 90, 96, 97, 98, 99, 100]
```
