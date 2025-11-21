# generic_queue

Shows how to use [xtd::collections::generic::queue](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1queue.html) class.

## Sources

* [src/generic_queue.cpp](src/generic_queue.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
one
two
three
four
five

Dequeuing 'one'
Peek at next item to dequeue: two
Dequeuing 'two'

Contents of the first copy:
three
four
five

Contents of the second copy, with duplicates and empty:



three
four
five

queue_copy.contains("four") = true

queue_copy.clear()

queue_copy.count() = 0
```
