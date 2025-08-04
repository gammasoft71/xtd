# Type Design Guidelines

From the c++ perspective, there are only two categories of types-natives types and class types—but for the purpose of a discussion about framework design, we divide types into more logical groups, each with its own specific design rules.

Classes are the general case of reference types. They make up the bulk of types in the majority of frameworks. Classes owe their popularity to the rich set of object-oriented features they support and to their general applicability. Base classes and abstract classes are special logical groups related to extensibility.

Interfaces are types that can be implemented by both reference types and value types. They can thus serve as roots of polymorphic hierarchies of reference types and value types.

Structs are the general case of value types and should be reserved for small, simple types, similar to language primitives.

Enums are a special case of value types used to define short sets of values, such as days of the week, console colors, and so on.

Static classes are types intended to be containers for static members. They are commonly used to provide shortcuts to other operations.

Delegates, exceptions, attributes, arrays, and collections are all special cases of reference types intended for specific uses, and guidelines for their design and usage are discussed elsewhere in this book.

**✔️ DO** ensure that each type is a well-defined set of related members, not just a random collection of unrelated functionality.

# In This Section

* [Choosing Between Class and Struct](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/choosing_between_class_and_struct)
* [Abstract Class Design](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/abstract_class_design)
* [Static Class Design](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/static_class_design)
* [Interface Design](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/interface_design)
* [Struct Design](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/struct_design)
* [Enum Design](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/enum_design)
* [Nested Types](/docs/documentation/Design%20Guidelines/Type%20Design%20Guidelines/nested_types)

# See also

* [Design Guidelines](/docs/documentation/Design%20Guidelines)
* [Documentation](/docs/documentation)
