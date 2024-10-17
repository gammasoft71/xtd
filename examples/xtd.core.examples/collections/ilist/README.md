# ilist

Shows how to use [xtd::collections::ilist](https://gammasoft71.github.io/xtd/reference_guides/latest/group__interfaces_gaf2cca35e1002dd44cdfa244b0654d6b4.html#gaf2cca35e1002dd44cdfa244b0654d6b4) interface.

## Sources

[src/ilist.cpp](src/ilist.cpp)

[CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
Populate the List
List has a capacity of 8 and currently has 8 elements.
List contents: one two three four five six seven eight

Remove elements from the list
List has a capacity of 8 and currently has 6 elements.
List contents: one two three four five seven

Add an element to the end of the list
List has a capacity of 8 and currently has 7 elements.
List contents: one two three four five seven nine

Insert an element into the middle of the list
List has a capacity of 8 and currently has 8 elements.
List contents: one two three four number five seven nine

Check for specific elements in the list
List contains "three": true
List contains "ten": false
```
