# Collections

## Overview

xtd mainly uses [std collections](https://en.cppreference.com/w/cpp/container). xtd just implements the [arranged_element_collection](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1layout_1_1arranged__element__collection.html) collections and defines a few specialized containers.

## Sequence containers

Sequence containers implement data structures which can be accessed sequentially.

| Container                                                                     | Definition                              |
| ----------------------------------------------------------------------------- | --------------------------------------- |
| [std::array](https://en.cppreference.com/w/cpp/container/array)               | Represents a static contiguous array.   |
| [std::vector](https://en.cppreference.com/w/cpp/container/vector)             | Represents a sdynamic contiguous array. |
| [std::deque](https://en.cppreference.com/w/cpp/container/deque)               | Represents a sdouble-ended queue.       |
| [std::forward_list](https://en.cppreference.com/w/cpp/container/forward_list) | Represents a ssingly-linked list.       |
| [std::list](https://en.cppreference.com/w/cpp/container/list)                 | Represents a sdoubly-linked list.       |

## Associative containers

Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).

| Container                                                             | Definition                                                                    |
| --------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| [std::set](https://en.cppreference.com/w/cpp/container/set)           | Represents a scollection of unique keys, sorted by keys.                      |
| [std::map](https://en.cppreference.com/w/cpp/container/map)           | Represents a scollection of key-value pairs, sorted by keys, keys are unique. |
| [std::multiset](https://en.cppreference.com/w/cpp/container/multiset) | Represents a scollection of keys, sorted by keys.                             | 
| [std::multimap](https://en.cppreference.com/w/cpp/container/multimap) | Represents a scollection of key-value pairs, sorted by keys.                  |

## Unordered associative containers

Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity).

| Container                                                                                 | Definition                                                                    |
| ----------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| [std::unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set)           | Represents a scollection of unique keys, hashed by keys.                      |
| [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)           | Represents a scollection of key-value pairs, hashed by keys, keys are unique. |
| [std::unordered_multiset](https://en.cppreference.com/w/cpp/container/unordered_multiset) | Represents a scollection of keys, hashed by keys.                             |
| [std::unordered_multimap](https://en.cppreference.com/w/cpp/container/unordered_multimap) | Represents a scollection of key-value pairs, hashed by keys.                  |

## Container adaptors

Container adaptors provide a different interface for sequential containers.

| Container                                                                         | Definition                                                                               |
| --------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------- |
| [std::stack](https://en.cppreference.com/w/cpp/container/stack)                   | Adapts a container to provide stack (LIFO data structure).                               |
| [std::queue](https://en.cppreference.com/w/cpp/container/queue)                   | Adapts a container to provide queue (FIFO data structure).                               |
| [std::priority_queue](https://en.cppreference.com/w/cpp/container/priority_queue) | Adapts a container to provide priority queue.                                            |
| [std::flat_set](https://en.cppreference.com/w/cpp/container/flat_set)             | Adapts a container to provide a collection of unique keys, sorted by keys.               |
| [std::flat_map](https://en.cppreference.com/w/cpp/container/flat_map)             | Adapts two containers to provide a collection of key-value pairs, sorted by unique keys. |
| [std::flat_multiset](https://en.cppreference.com/w/cpp/container/flat_multiset)   | Adapts a container to provide a collection of keys, sorted by keys.                      |
| [std::flat_multimap](https://en.cppreference.com/w/cpp/container/flat_multimap)   | Adapts two containers to provide a collection of key-value pairs, sorted by keys.        |

## Eventing containers

The [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) collection has the particularity to have [events](/docs/documentation/Guides/xtd.core/Events/overview.md) on which we can connect:

* [item_added](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1layout_1_1arranged__element__collection.html#afadce93d0b8a19c5d61f3b417158747c) : occurs when an item is added to the collection.
* [item_updated](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1layout_1_1arranged__element__collection.html#a3ccfbdf5ef99ca06e5c380c2f4de4076) : occurs when an item is updated in the collection.
* [item_removed](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1layout_1_1arranged__element__collection.html#ad37a37d62a7b257ac20274e95a6501f3) : occurs when an item is deleted from the collection.

This [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) Collections is overloaded in various classes such as [control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html), [list_control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1list__control.html), [tab_control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__control.html), [status_bar](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1status__bar.html), [tool_bar](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tool__bar.html), ...

## Specialized containers

## Thread-safe containers

Not yet implemented, but coming soon :

| Container                                          | Definition                                                       |
| -------------------------------------------------- | ---------------------------------------------------------------- |
| **xtd::collections::concurrent::concurrent_bag**   | Represents a thread-safe, unordered collection of objects.       |
| **xtd::collections::concurrent::concurrent_queue** | Represents a thread-safe first in-first out (FIFO) collection.   |
| **xtd::collections::concurrent::concurrent_stack** | RepRepresents a thread-safe last in-first out (LIFO) collection. |

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
