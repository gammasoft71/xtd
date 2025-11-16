# generic_linked_list_node

Shows how to use [xtd::collections::generic::generic_linked_list_node](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1generic_1_1linked__list__node.html) class.

## Sources

* [src/generic_linked_list_node.cpp](src/generic_linked_list_node.cpp)
* [CMakeLists.txt](CMakeLists.txt)

## Build and run

Open "Command Prompt" or "Terminal". Navigate to the folder that contains the project and type the following:

```cmake
xtdc run
```

## Output

```
After creating the node ....
   Node is not linked.
   Previous node is null.
   Value of current node:  orange
   Next node is null.

After adding the node to the empty linked_list ....
   Node belongs to a linked list with 1 elements.
   Previous node is null.
   Value of current node:  orange
   Next node is null.

After adding red and yellow ....
   Node belongs to a linked list with 3 elements.
   Value of previous node: red
   Value of current node:  orange
   Value of next node:     yellow

```
