# Collections

## Overview

xtd mainly uses std containers. xtd just implements the [arranged_element_collection](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1forms_1_1layout_1_1arranged__element__collection.html) Collections and defines a few specialized containers.

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

Coming soon...

## Unordered associative containers

Coming soon...

## Container adaptors

Coming soon...

## Eventing containers

The [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) collection has the particularity to have [events](/docs/documentation/Guides/xtd.core/Events/overview.md) on which we can connect:

* item_added : occurs when an item is added to the collection.
* item_updated : occurs when an item is updated in the collection.
* item_removed : occurs when an item is deleted from the collection.

This [arranged_element_collection](https://github.com/gammasoft71/xtd/blob/master/src/xtd.forms/include/xtd/forms/layout/arranged_element_collection.h) Collections is overloaded in various classes such as control, list_control, tab_control, status_bar, tool_bar, ...
## Specialized containers

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/base-types/type-conversion)
