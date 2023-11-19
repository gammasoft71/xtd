# Collections

## In this article

* [Overview](#overview)
* [std containers](#std-containers)
  * [Sequence containers](#sequence-containers)
  * [Associative containers](#associative-containers)
  * [Unordered associative containers](#unordered-associative-containers)
  * [Container adaptors](#container-adaptors)
* [xtd containers](#xtd-containers)
  * [Containers with events](#containers-with-events)
  * [Specialized containers](#specialized-containers)
  * [Thread-safe containers](#thread-safe-containers)
* [Overview](#overview)

## Overview

xtd mainly uses [std collections](https://en.cppreference.com/w/cpp/container). 
To complete the std, xtd implements some owner containers.

## std containers

### Sequence containers

Sequence containers implement data structures which can be accessed sequentially.

| Container                                                                     | Definition                              |
| ----------------------------------------------------------------------------- | --------------------------------------- |
| [std::array](https://en.cppreference.com/w/cpp/container/array)               | Represents a static contiguous array.   |
| [std::vector](https://en.cppreference.com/w/cpp/container/vector)             | Represents a sdynamic contiguous array. |
| [std::deque](https://en.cppreference.com/w/cpp/container/deque)               | Represents a sdouble-ended queue.       |
| [std::forward_list](https://en.cppreference.com/w/cpp/container/forward_list) | Represents a ssingly-linked list.       |
| [std::list](https://en.cppreference.com/w/cpp/container/list)                 | Represents a sdoubly-linked list.       |

### Associative containers

Associative containers implement sorted data structures that can be quickly searched (O(log n) complexity).

| Container                                                             | Definition                                                                    |
| --------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| [std::set](https://en.cppreference.com/w/cpp/container/set)           | Represents a scollection of unique keys, sorted by keys.                      |
| [std::map](https://en.cppreference.com/w/cpp/container/map)           | Represents a scollection of key-value pairs, sorted by keys, keys are unique. |
| [std::multiset](https://en.cppreference.com/w/cpp/container/multiset) | Represents a scollection of keys, sorted by keys.                             | 
| [std::multimap](https://en.cppreference.com/w/cpp/container/multimap) | Represents a scollection of key-value pairs, sorted by keys.                  |

### Unordered associative containers

Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (O(1) average, O(n) worst-case complexity).

| Container                                                                                 | Definition                                                                    |
| ----------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| [std::unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set)           | Represents a scollection of unique keys, hashed by keys.                      |
| [std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map)           | Represents a scollection of key-value pairs, hashed by keys, keys are unique. |
| [std::unordered_multiset](https://en.cppreference.com/w/cpp/container/unordered_multiset) | Represents a scollection of keys, hashed by keys.                             |
| [std::unordered_multimap](https://en.cppreference.com/w/cpp/container/unordered_multimap) | Represents a scollection of key-value pairs, hashed by keys.                  |

### Container adaptors

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

## std containers

### Containers with events

| Container                                                                                                                                          | Definition                                                                                                              |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) | Represents a collection with [events](/docs/documentation/Guides/xtd.core/Events/overview.md) to which you can connect. |

> **Remarks**
> The [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) Collections is overloaded in various classes such as [control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1control.html), [list_control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1list__control.html), [tab_control](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tab__control.html), [status_bar](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1status__bar.html), [tool_bar](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1tool__bar.html), ...

### Specialized containers

Specialized and strongly-typed collections.

| Container                                                                                                                                                            | Definition                                                                                                                        |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| [xtd::collections::hash_table](#)                                                                                                                                    | Represents a collection of key/value pairs that are organized based on the hash code of the key.                                  |
| [xtd::collections::vector_list](https://gammasoft71.github.io/xtd/reference_guides/latest/group__collections.html#gaf18249e78122f5f0f0f09003cf6abc5c)                | Represents a collection of std::any.                                                                                              |
| [xtd::collections::specialized::string_map](https://gammasoft71.github.io/xtd/reference_guides/latest/group__collections.html#ga563b341f7aaf8f09a45cf5c52e70bbc8)    | Implements a [std::map](https://en.cppreference.com/w/cpp/container/map) with the key and the value strongly typed to be strings. |
| [xtd::collections::specialized::string_vector](https://gammasoft71.github.io/xtd/reference_guides/latest/group__collections.html#gadc1dbfbb41611242c5aa2e857e574256) | Represents a collection of strings.                                                                                               |

### Thread-safe containers

Thread-safe containers can be used for multithreading.

| Container                                           | Definition                                                                                                    |
| --------------------------------------------------- | ------------------------------------------------------------------------------------------------------------- |
| [xtd::collections::concurrent::concurrent_bag](#)   | Represents a thread-safe, unordered collection of objects.                                                    |
| [xtd::collections::concurrent::concurrent_queue](#) | Represents a thread-safe first in-first out (FIFO) collection.                                                |
| [xtd::collections::concurrent::concurrent_map](#)   | Represents a thread-safe collection of key/value pairs that can be accessed by multiple threads concurrently. |
| [xtd::collections::concurrent::concurrent_stack](#) | RepRepresents a thread-safe last in-first out (LIFO) collection.                                              |

> **Remarks**
> Not yet implemented, but coming soon.


## Choose a collection

In general, you should use generic collections. The following table describes some common collection scenarios and the collection classes you can use for those scenarios. If you're new to generic collections, the following table will help you choose the generic collection that works best for your task:

| I want to…                                               | collection options                                                                                                                             | Non-generic collection options                                                                                                                        | Thread-safe or immutable collection options       |
| ------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------- |
| Store items as key/value pairs for quick look-up by key | [std::map](https://en.cppreference.com/w/cpp/container/map)<br>[std::unordered_map](https://en.cppreference.com/w/cpp/container/unordered_map) | [xtd::collections::hash_table](#)                                                                                                                     | [xtd::collections::concurrent::concurrent_map](#) |
| Access items by index                                   | [std::vector](https://en.cppreference.com/w/cpp/container/vector)<br>[std::array](https://en.cppreference.com/w/cpp/container/array)           | [xtd::collections::vector_list](https://gammasoft71.github.io/xtd/reference_guides/latest/group__collections.html#gaf18249e78122f5f0f0f09003cf6abc5c) | [xtd::collections::concurrent::concurrent_map](#) |

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
