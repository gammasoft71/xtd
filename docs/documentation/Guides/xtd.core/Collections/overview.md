# Collections

## Overview

xtd mainly uses [std collections](https://en.cppreference.com/w/cpp/container). xtd just implements the [arranged_element_collection](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1layout_1_1arranged__element__collection.html) Collections and defines a few specialized containers.

## Sequence containers

Sequence containers implement data structures which can be accessed sequentially.

| Class                                                                         | Definition               |
| ----------------------------------------------------------------------------- | ------------------------ |
| [std::array](https://en.cppreference.com/w/cpp/container/array)               | static contiguous array  |
| [std::vector](https://en.cppreference.com/w/cpp/container/vector)             | dynamic contiguous array |
| [std::deque](https://en.cppreference.com/w/cpp/container/deque)               | double-ended queue       |
| [std::forward_list](https://en.cppreference.com/w/cpp/container/forward_list) | singly-linked list       |
| [std::list](https://en.cppreference.com/w/cpp/container/list)                 | doubly-linked list       |

## Associative containers

Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).

| Class                                                                 | Definition                                                     |
| --------------------------------------------------------------------- | -------------------------------------------------------------- |
| [std::set](https://en.cppreference.com/w/cpp/container/set)           | collection of unique keys, sorted by keys                      |
| [std::map](https://en.cppreference.com/w/cpp/container/map)           | collection of key-value pairs, sorted by keys, keys are unique |
| [std::multiset](https://en.cppreference.com/w/cpp/container/multiset) | collection of keys, sorted by keys                             | 
| [std::multimap](https://en.cppreference.com/w/cpp/container/multimap) | collection of key-value pairs, sorted by keys                  |

## Unordered associative containers

Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity).

| Class                                                                                     | Definition                                                     |
| ----------------------------------------------------------------------------------------- | -------------------------------------------------------------- |
| [std::unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set)           | collection of unique keys, hashed by keys                      |
| [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)           | collection of key-value pairs, hashed by keys, keys are unique |
| [std::unordered_multiset](https://en.cppreference.com/w/cpp/container/unordered_multiset) | collection of keys, hashed by keys                             |
| [std::unordered_multimap](https://en.cppreference.com/w/cpp/container/unordered_multimap) | collection of key-value pairs, hashed by keys                  |

## Container adaptors

Container adaptors provide a different interface for sequential containers.

| Class                                                                             | Definition                                                                              |
| --------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| [std::stack](https://en.cppreference.com/w/cpp/container/stack)                   | adapts a container to provide stack (LIFO data structure)                               |
| [std::queue](https://en.cppreference.com/w/cpp/container/queue)                   | adapts a container to provide queue (FIFO data structure)                               |
| [std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue) | adapts a container to provide priority queue                                            |
| [std::flat_set](https://en.cppreference.com/w/cpp/container/flat_set)             | adapts a container to provide a collection of unique keys, sorted by keys               |
| [std::flat_map](https://en.cppreference.com/w/cpp/container/flat_map)             | adapts two containers to provide a collection of key-value pairs, sorted by unique keys |
| [std::flat_multiset](https://en.cppreference.com/w/cpp/container/flat_multiset)   | adapts a container to provide a collection of keys, sorted by keys                      |
| [std::flat_multimap](https://en.cppreference.com/w/cpp/container/flat_multimap)   | adapts two containers to provide a collection of key-value pairs, sorted by keys        |

## Eventing containers

The [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) collection has the particularity to have [events](/docs/documentation/Guides/xtd.core/Events/overview.md) on which we can connect:

* item_added : occurs when an item is added to the collection.
* item_updated : occurs when an item is updated in the collection.
* item_removed : occurs when an item is deleted from the collection.

This [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) Collections is overloaded in various classes such as control, list_control, tab_control, status_bar, tool_bar, ...

## Specialized containers

## Thread-safe containers

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
