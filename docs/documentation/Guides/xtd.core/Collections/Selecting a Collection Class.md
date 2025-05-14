# Selecting a Collection Class

Be sure to choose your collection class carefully. Using the wrong type can restrict your use of the collection.

> **Important**
> Avoid using the types in the [xtd::collections](https://gammasoft71.github.io/xtd/reference_guides/latest/namespacextd_1_1collections.html) namespace. The [generic](https://en.cppreference.com/w/cpp/container) and [concurrent](#) versions of the collections are recommended because of their greater type safety and other improvements.

Consider the following questions:

* Do you need a sequential list where the element is typically discarded after its value is retrieved?
  * If yes, consider using the [xtd::collection::queue](#) class or the [std::queue<type_t>](https://en.cppreference.com/w/cpp/container/queue) generic class if you need first-in, first-out (FIFO) behavior. Consider using the [xtd::collection::stack](#) class or the [std::stack<type_t>](https://en.cppreference.com/w/cpp/container/stack) generic class if you need last-in, first-out (LIFO) behavior. For safe access from multiple threads, use the concurrent versions, [xtd::collection::concurrent::concurrent_queue<typr_t>](#) and [xtd::collection::concurrent::concurrent_stack<type_t>](#).
  * If not, consider using the other collections.
* Do you need to access the elements in a certain order, such as FIFO, LIFO, or random?
  * The [xtd::collection::queue](#) class, as well as the [std::queue<type_t>](https://en.cppreference.com/w/cpp/container/queue) and [xtd::collection::concurrent::concurrent_queue<typr_t>](#) generic classes all offer FIFO access. For more information, see When to Use a Thread-Safe Collection.
  * The  [xtd::collection::stack](#) class, as well as the [std::stack<type_t>](https://en.cppreference.com/w/cpp/container/stack) and [xtd::collection::concurrent::concurrent_stack<type_t>](#) generic classes all offer LIFO access. For more information, see When to Use a Thread-Safe Collection.
  * The [std::list<type_t>](https://en.cppreference.com/w/cpp/container/list) generic class allows sequential access either from the head to the tail, or from the tail to the head.

# See also
​
* [Guides](/docs/documentation/Guides)
* [Documentation](/docs/documentation)

[//]: # (https://learn.microsoft.com/en-us/dotnet/standard/collections/selecting-a-collection-class)
